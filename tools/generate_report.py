#!/usr/bin/env python3
"""Generate a dtk-template-compatible build/G4ZE69/report.json.

Bypasses the full ninja+SN-ProDG build pipeline that the standard dtk-template
configure.py implements. Instead, computes byte-level progress directly from:
- the symbol map (extracted/files/u2_ngc_release_dvd.map) for total function sizes
- src/matched/ corpus for matched function set
- known SDK address range (0x80240000-0x80390000) for the unmatchable category

Output schema matches what `dtk progress` / decomp.dev consume. See
encounter/dtk-template's tools/project.py calculate_progress() for the
reference reader.

Usage:
    python tools/generate_report.py
    python tools/generate_report.py --version G4ZE69 --output build/G4ZE69/report.json
"""

import argparse
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from paths import REPO_ROOT, GAME_ID, MAP_PATH

MATCH_REGEX = re.compile(r"match_(?:0[xX])?([0-9A-Fa-f]{8})_", re.IGNORECASE)

# Data sections we track for byte-match progress. PROGBITS only — BSS sections
# are zero-init at runtime, so there's no "match" work (just correct sizing).
DATA_SECTIONS = (".ctors", ".dtors", ".rodata", ".data", ".sdata", ".sdata2")

# Match quality classification — see GitHub issue #2.
#
# A "match" in this project can mean three very different things:
#   - CLEAN:    hand-written C++ that compiles to byte-matching output. Runs
#               cross-platform (PC port viable).
#   - MUTATOR:  hand-written C++ + ASMPROC compiler-output mutators (gpr_relabel,
#               swap_adj, replace_insn, etc.) nudging GCC's specific output. C++
#               body runs cross-platform; mutators only affect emission.
#   - INJECTED: ASMPROC_inject_before pragma copies raw DOL bytes into the .o.
#               Equivalent to #pragma GLOBAL_ASM. C++ shell is a no-op. Does NOT
#               run cross-platform.
#
# matched_code_percent (regression-gate metric) counts all three.
# matched_code_percent_semantic (PC-port-meaningful metric) counts CLEAN + MUTATOR.
# matched_code_percent_clean (purest hand-written metric) counts CLEAN only.
INJECT_BEFORE_RE = re.compile(rb"ASMPROC_inject_before|#\s*pragma\s+ASMPROC\s+inject_before")
MUTATOR_RE = re.compile(
    rb"ASMPROC_(?:gpr_relabel|region_gpr_relabel|swap_adj|swap_operands|"
    rb"replace_insn|hoist_fcmpu|self_return_blr|this_alias|force_alias_base|"
    rb"force_sda21_destination_reg|dummy_write|virt_return_passthrough)"
)


def classify_match_file(file_path: Path) -> str:
    """Classify a single matched .cpp file as 'clean', 'mutator', or 'injected'.

    See module-level docstring for definitions. Falls back to 'clean' on read
    errors to avoid double-counting genuinely empty / minimal files as injected.
    """
    try:
        with open(file_path, "rb") as f:
            content = f.read()
    except OSError:
        return "clean"
    if INJECT_BEFORE_RE.search(content):
        return "injected"
    if MUTATOR_RE.search(content):
        return "mutator"
    return "clean"

ORIG_ELF = REPO_ROOT / "extracted" / "files" / "u2_ngc_release_dvd.elf"
BUILT_ELF = REPO_ROOT / "build" / "sims2.elf"

# ELF32 constants
SHT_PROGBITS = 1

# A function is classified as "SDK" if its symbol is sourced from a TU under
# the DolphinSDK1.0 library path in the map file. This is more precise than
# a flat address-range check because some non-SDK templates land in SDK
# address neighborhoods due to linker placement.
SDK_PATH_MARKER = re.compile(r"DolphinSDK", re.IGNORECASE)


def collect_matched_addresses(matched_dir: Path) -> dict:
    """Return {addr: classification} for all matched functions in src/matched/.

    Classification is one of {"clean", "mutator", "injected"} per
    classify_match_file. The dict's keys behave like the legacy set for
    `addr in matched_addrs` membership tests, so existing callers stay valid.

    Extended Option 2 patch: uses `git ls-files --cached -- src/matched/` instead
    of filesystem rglob. This means only files tracked by git (committed or
    explicitly staged) are counted. Untracked on-disk WIP files left by other
    fleet workers NEVER contaminate floor readings.

    Pre-commit hook correctness: the worker's newly-staged match file is already
    in the index when the hook runs, so it IS counted. Workers whose files are
    merely on-disk-but-unstaged are NOT counted.

    Falls back to the wip-guarded rglob if git is unavailable (CI without git,
    fresh checkout edge cases, etc.).
    """
    classifications: dict[int, str] = {}
    try:
        result = subprocess.run(
            ["git", "ls-files", "--cached", "--", "src/matched/"],
            cwd=str(REPO_ROOT),
            capture_output=True,
            text=True,
            check=True,
        )
        for line in result.stdout.splitlines():
            p = Path(line)
            # Skip wip paths (version_diff/, etc.)
            if "wip" in p.parts:
                continue
            m = MATCH_REGEX.match(p.name)
            if m:
                addr = int(m.group(1), 16)
                classifications[addr] = classify_match_file(REPO_ROOT / p)
        return classifications
    except (subprocess.CalledProcessError, FileNotFoundError):
        # git unavailable — fall back to wip-guarded rglob
        for cpp in matched_dir.rglob("match_*.cpp"):
            if "wip" in cpp.parts:
                continue
            m = MATCH_REGEX.match(cpp.name)
            if m:
                classifications[int(m.group(1), 16)] = classify_match_file(cpp)
        return classifications


_OBJ_NAME_RE = re.compile(r"([^\\/]+\.obj|[^\\/]+\.a\([^)]+\))$", re.IGNORECASE)


def _short_obj_name(raw: str) -> str:
    """Reduce a full obj/lib path to a compact unit name.

    Examples:
      c:\\...\\u2_ngc_release_dvd\\animeventhandlersupport.obj -> "animeventhandlersupport"
      C:\\Program Files\\SN Systems\\ngc\\lib\\libsn.a(crt0.o) -> "libsn.a(crt0.o)"
      c:\\...\\DolphinSDK1.0\\HW2\\lib\\os.a(OS.o)              -> "os.a(OS.o)"
    """
    m = _OBJ_NAME_RE.search(raw)
    if m:
        name = m.group(1)
        if name.lower().endswith(".obj"):
            return name[:-4]
        return name
    return raw.strip().split("\\")[-1].split("/")[-1] or "unknown"


def parse_text_functions(map_path: Path) -> list:
    """Return list of {addr, size, name, sdk, obj} dicts for .text symbols with
    size > 0. Tracks the running source-file/object reference so each function
    can be tagged with its containing TU (for unit grouping) plus an SDK flag.
    """
    line_re = re.compile(r"^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+(\d+)\s+(.+)$")
    section_re = re.compile(r"^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+(\d+)\s+(\.\w+)\s*$")

    functions = []
    current_section = None
    current_obj_is_sdk = False
    current_obj_name = "unknown"
    src_prefixes = ("c:" + chr(92), "C:" + chr(92), "/")

    with open(map_path, encoding="utf-8", errors="replace") as f:
        for line in f:
            line = line.rstrip()

            sec = section_re.match(line)
            if sec:
                current_section = sec.group(4)
                continue

            m = line_re.match(line)
            if not m:
                continue
            addr = int(m.group(1), 16)
            size = int(m.group(2), 16)
            rest = m.group(4).strip()

            if rest.startswith(src_prefixes):
                # source-file / object reference — update running TU + SDK flag
                current_obj_is_sdk = bool(SDK_PATH_MARKER.search(rest))
                current_obj_name = _short_obj_name(rest)
                continue

            if current_section != ".text":
                continue
            if size == 0:
                continue

            functions.append(
                {
                    "addr": addr,
                    "size": size,
                    "name": rest,
                    "sdk": current_obj_is_sdk,
                    "obj": current_obj_name,
                }
            )

    return functions


def read_elf_progbits_sections(elf_path: Path) -> dict:
    """Read PROGBITS data sections from a 32-bit big-endian PowerPC ELF.

    Returns {section_name: (vaddr, bytes)} for sections in DATA_SECTIONS.
    Pure-Python — no pyelftools dependency. Sections we don't care about
    (.text, .init, .bss family, .shstrtab) are skipped.
    """
    if not elf_path.exists():
        return {}

    with open(elf_path, "rb") as f:
        data = f.read()

    # ELF header (52 bytes for ELF32). Fields we need:
    #   0x20 e_shoff   (4) section header offset
    #   0x2E e_shentsize (2)
    #   0x30 e_shnum   (2)
    #   0x32 e_shstrndx (2)
    e_shoff = struct.unpack(">I", data[0x20:0x24])[0]
    e_shentsize = struct.unpack(">H", data[0x2E:0x30])[0]
    e_shnum = struct.unpack(">H", data[0x30:0x32])[0]
    e_shstrndx = struct.unpack(">H", data[0x32:0x34])[0]

    # Section header (40 bytes for ELF32, BE):
    #   sh_name(4), sh_type(4), sh_flags(4), sh_addr(4), sh_offset(4),
    #   sh_size(4), sh_link(4), sh_info(4), sh_addralign(4), sh_entsize(4)
    def shdr(idx: int) -> tuple:
        off = e_shoff + idx * e_shentsize
        return struct.unpack(">10I", data[off:off + 40])

    # Resolve string table for section names
    _, _, _, _, str_off, str_size, *_ = shdr(e_shstrndx)
    strtab = data[str_off:str_off + str_size]

    def name_at(name_off: int) -> str:
        end = strtab.find(b"\x00", name_off)
        return strtab[name_off:end].decode("ascii", errors="replace")

    sections = {}
    for i in range(e_shnum):
        sh_name, sh_type, _flags, sh_addr, sh_offset, sh_size, *_ = shdr(i)
        if sh_type != SHT_PROGBITS:
            continue
        name = name_at(sh_name)
        if name not in DATA_SECTIONS:
            continue
        sections[name] = (sh_addr, data[sh_offset:sh_offset + sh_size])

    return sections


def compute_data_metrics(orig_elf: Path, built_elf: Path) -> dict:
    """Compare data sections between original (authority) and built ELFs.

    Returns dict with total/matched bytes + per-section breakdown.

    Strategy: byte-by-byte equality per section using the ORIGINAL section
    as the size authority. If built ELF is missing or a section is missing
    from the build, it counts as 0 matched for that section but still
    contributes its size to total_data (so the denominator stays honest).
    """
    orig = read_elf_progbits_sections(orig_elf)
    built = read_elf_progbits_sections(built_elf) if built_elf.exists() else {}

    total = 0
    matched = 0
    per_section = {}

    for name in DATA_SECTIONS:
        orig_entry = orig.get(name)
        if orig_entry is None:
            continue
        _orig_addr, orig_bytes = orig_entry
        sec_total = len(orig_bytes)
        total += sec_total

        sec_matched = 0
        built_entry = built.get(name)
        if built_entry is not None:
            _built_addr, built_bytes = built_entry
            # Compare up to min length; unmatched bytes beyond build's size = 0
            cmp_len = min(len(orig_bytes), len(built_bytes))
            for j in range(cmp_len):
                if orig_bytes[j] == built_bytes[j]:
                    sec_matched += 1
        matched += sec_matched
        per_section[name] = {"total": sec_total, "matched": sec_matched}

    return {"total": total, "matched": matched, "per_section": per_section}


def build_measures(functions: list, matched_addrs: dict,
                   data_metrics: dict | None = None) -> dict:
    """Compute the objdiff Measures block (matches proto3 serde JSON conventions
    used by decomp.dev / dtk-template). uint64 fields are emitted as strings,
    uint32 fields as integers, percent fields as floats.

    Adds three honesty-tier metrics on top of the baseline byte-match floor
    (see GitHub issue #2):
      - matched_code_percent (baseline)  — byte-match regression gate. Counts
        all matches including ASMPROC_inject_before byte injections.
      - matched_code_percent_semantic    — PC-port-meaningful. Counts hand-written
        C++ (with or without ASMPROC mutators). Excludes inject_before.
      - matched_code_percent_clean       — purest. Counts only hand-written C++
        with NO ASMPROC directives at all.
    """
    total_code = sum(f["size"] for f in functions)
    total_functions = len(functions)

    matched_code = 0
    matched_functions = 0
    semantic_code = 0
    semantic_functions = 0
    clean_code = 0
    clean_functions = 0
    injected_code = 0
    injected_functions = 0
    mutator_code = 0
    mutator_functions = 0

    for f in functions:
        if f["addr"] not in matched_addrs:
            continue
        classification = matched_addrs[f["addr"]]
        matched_code += f["size"]
        matched_functions += 1
        if classification == "clean":
            clean_code += f["size"]
            clean_functions += 1
            semantic_code += f["size"]
            semantic_functions += 1
        elif classification == "mutator":
            mutator_code += f["size"]
            mutator_functions += 1
            semantic_code += f["size"]
            semantic_functions += 1
        else:  # injected
            injected_code += f["size"]
            injected_functions += 1

    pct_bytes = (matched_code / total_code * 100.0) if total_code else 0.0
    pct_funcs = (matched_functions / total_functions * 100.0) if total_functions else 0.0
    pct_semantic = (semantic_code / total_code * 100.0) if total_code else 0.0
    pct_semantic_funcs = (semantic_functions / total_functions * 100.0) if total_functions else 0.0
    pct_clean = (clean_code / total_code * 100.0) if total_code else 0.0
    pct_clean_funcs = (clean_functions / total_functions * 100.0) if total_functions else 0.0

    # Data metrics — empty dict means we couldn't measure (no original ELF).
    # In that case fall back to zeros (matches pre-data-tracking behavior).
    total_data = (data_metrics or {}).get("total", 0)
    matched_data = (data_metrics or {}).get("matched", 0)
    pct_data = (matched_data / total_data * 100.0) if total_data else 0.0

    return {
        "fuzzy_match_percent": round(pct_bytes, 6),
        "total_code": str(total_code),
        "matched_code": str(matched_code),
        "matched_code_percent": round(pct_bytes, 6),
        # Honesty-tier additions (GitHub issue #2)
        "matched_code_semantic": str(semantic_code),
        "matched_code_percent_semantic": round(pct_semantic, 6),
        "matched_code_clean": str(clean_code),
        "matched_code_percent_clean": round(pct_clean, 6),
        "matched_code_mutator": str(mutator_code),
        "matched_code_injected": str(injected_code),
        "matched_functions_semantic": semantic_functions,
        "matched_functions_percent_semantic": round(pct_semantic_funcs, 6),
        "matched_functions_clean": clean_functions,
        "matched_functions_percent_clean": round(pct_clean_funcs, 6),
        "matched_functions_mutator": mutator_functions,
        "matched_functions_injected": injected_functions,
        # End honesty-tier additions
        "total_data": str(total_data),
        "matched_data": str(matched_data),
        "matched_data_percent": round(pct_data, 6),
        "total_functions": total_functions,
        "matched_functions": matched_functions,
        "matched_functions_percent": round(pct_funcs, 6),
        "complete_code": str(matched_code),
        "complete_code_percent": round(pct_bytes, 6),
        "complete_data": str(matched_data),
        "complete_data_percent": round(pct_data, 6),
        "total_units": total_functions,
        "complete_units": matched_functions,
    }


def build_units(functions: list, matched_addrs: dict) -> list:
    """Group functions by their containing TU/object and emit one Unit per group.

    Each Unit has:
      - name: short obj/lib name (e.g. "animeventhandlersupport" or "os.a(OS.o)")
      - measures: aggregated stats for this TU
      - sections: a single .text section with virtual_address + size
      - functions: list of contained functions (name, size, address-within-section)

    This is what powers the treemap visualization on decomp.dev.
    """
    by_obj = {}
    for fn in functions:
        by_obj.setdefault(fn["obj"], []).append(fn)

    units = []
    for obj_name, fns in by_obj.items():
        fns_sorted = sorted(fns, key=lambda f: f["addr"])
        base_addr = fns_sorted[0]["addr"]
        # Section size spans from first function start to end of last function
        end_addr = fns_sorted[-1]["addr"] + fns_sorted[-1]["size"]
        section_size = end_addr - base_addr

        total_code = sum(f["size"] for f in fns_sorted)
        matched_code = sum(f["size"] for f in fns_sorted if f["addr"] in matched_addrs)
        total_functions = len(fns_sorted)
        matched_functions = sum(1 for f in fns_sorted if f["addr"] in matched_addrs)
        pct_bytes = (matched_code / total_code * 100.0) if total_code else 0.0
        pct_funcs = (matched_functions / total_functions * 100.0) if total_functions else 0.0

        function_entries = []
        for f in fns_sorted:
            # Per-function match flag — decomp.dev's treemap colors each
            # inner square by this value. Without it, every function
            # defaults to 0% (grey) even when the unit overall reads 100%.
            classification = matched_addrs.get(f["addr"])
            is_matched = classification is not None
            fn_pct = 100.0 if is_matched else 0.0
            function_entries.append({
                "name": f["name"],
                "size": str(f["size"]),
                "metadata": {
                    "virtual_address": str(f["addr"]),
                    "complete": is_matched,
                    # Honesty-tier per-function classification (issue #2).
                    # "clean", "mutator", "injected", or null for unmatched.
                    "match_quality": classification,
                },
                "address": str(f["addr"] - base_addr),
                "fuzzy_match_percent": fn_pct,
            })

        units.append({
            "name": obj_name,
            "measures": {
                "fuzzy_match_percent": round(pct_bytes, 6),
                "total_code": str(total_code),
                "matched_code": str(matched_code),
                "matched_code_percent": round(pct_bytes, 6),
                "total_data": "0",
                "matched_data": "0",
                "matched_data_percent": 0.0,
                "total_functions": total_functions,
                "matched_functions": matched_functions,
                "matched_functions_percent": round(pct_funcs, 6),
                "complete_code": str(matched_code),
                "complete_code_percent": round(pct_bytes, 6),
                "complete_data": "0",
                "complete_data_percent": 0.0,
                "total_units": 1,
                "complete_units": 1 if matched_functions == total_functions else 0,
            },
            "sections": [{
                "name": ".text",
                "size": str(section_size),
                "fuzzy_match_percent": round(pct_bytes, 6),
                "metadata": {"virtual_address": str(base_addr)},
            }],
            "functions": function_entries,
            "metadata": {
                "complete": matched_functions == total_functions,
                "progress_categories": ["sdk" if fns_sorted[0]["sdk"] else "game"],
            },
        })

    return units


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--version", default=GAME_ID, help="Game ID (default: %(default)s)")
    parser.add_argument(
        "--output",
        type=Path,
        default=None,
        help="Output path (default: build/<VERSION>/report.json)",
    )
    parser.add_argument(
        "--print-summary",
        action="store_true",
        help="Print human-readable summary after generation",
    )
    args = parser.parse_args()

    out_path = args.output or (REPO_ROOT / "build" / args.version / "report.json")
    out_path.parent.mkdir(parents=True, exist_ok=True)

    matched_addrs = collect_matched_addresses(REPO_ROOT / "src" / "matched")
    functions = parse_text_functions(MAP_PATH)

    # Measure data sections (.ctors/.dtors/.rodata/.data/.sdata/.sdata2) against
    # the authoritative ELF. Computed once, threaded into all measures blocks so
    # the global total is consistent (decomp.dev reads the top-level measures).
    data_metrics = compute_data_metrics(ORIG_ELF, BUILT_ELF)

    game_funcs = [f for f in functions if not f["sdk"]]
    sdk_funcs = [f for f in functions if f["sdk"]]

    report = {
        "version": 2,
        "measures": build_measures(functions, matched_addrs, data_metrics),
        "units": build_units(functions, matched_addrs),
        "categories": [
            {
                "id": "game",
                "name": "Game code (SN Systems ProDG)",
                # Game category gets the data metrics — data sections are
                # almost entirely game-originated (not SDK).
                "measures": build_measures(game_funcs, matched_addrs, data_metrics),
            },
            {
                "id": "sdk",
                "name": "DolphinSDK (Metrowerks, unmatchable)",
                "measures": build_measures(sdk_funcs, matched_addrs),
            },
        ],
    }

    with open(out_path, "w", encoding="utf-8") as f:
        json.dump(report, f, indent=2)

    print(f"Wrote {out_path}")

    if args.print_summary:
        def show(label: str, m: dict) -> None:
            mc = int(m["matched_code"])
            tc = int(m["total_code"])
            sc = int(m.get("matched_code_semantic", 0))
            cc = int(m.get("matched_code_clean", 0))
            inj = int(m.get("matched_code_injected", 0))
            mut = int(m.get("matched_code_mutator", 0))
            print(f"  {label}: byte-floor {m['matched_code_percent']:.2f}% "
                  f"({mc:,} / {tc:,} bytes, "
                  f"{m['matched_functions']:,} / {m['total_functions']:,} funcs)")
            print(f"    semantic (real C++, PC-port-viable): "
                  f"{m.get('matched_code_percent_semantic', 0):.2f}% "
                  f"({sc:,} bytes — {cc:,} clean + {mut:,} mutator)")
            print(f"    clean (no ASMPROC at all): "
                  f"{m.get('matched_code_percent_clean', 0):.2f}% ({cc:,} bytes)")
            print(f"    injected (raw DOL bytes, NOT runnable on PC): "
                  f"{inj:,} bytes")
        print()
        show("Overall", report["measures"])
        show("Game   ", report["categories"][0]["measures"])
        show("SDK    ", report["categories"][1]["measures"])

    return 0


if __name__ == "__main__":
    sys.exit(main())
