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
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from paths import REPO_ROOT, GAME_ID, MAP_PATH

MATCH_REGEX = re.compile(r"match_(?:0[xX])?([0-9A-Fa-f]{8})_", re.IGNORECASE)

# A function is classified as "SDK" if its symbol is sourced from a TU under
# the DolphinSDK1.0 library path in the map file. This is more precise than
# a flat address-range check because some non-SDK templates land in SDK
# address neighborhoods due to linker placement.
SDK_PATH_MARKER = re.compile(r"DolphinSDK", re.IGNORECASE)


def collect_matched_addresses(matched_dir: Path) -> set:
    """Scan src/matched/ for `match_<addr>_*.cpp` filenames, return set of ints."""
    addrs = set()
    for cpp in matched_dir.rglob("match_*.cpp"):
        m = MATCH_REGEX.match(cpp.name)
        if m:
            addrs.add(int(m.group(1), 16))
    return addrs


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


def build_measures(functions: list, matched_addrs: set) -> dict:
    """Compute the objdiff Measures block (matches proto3 serde JSON conventions
    used by decomp.dev / dtk-template). uint64 fields are emitted as strings,
    uint32 fields as integers, percent fields as floats.
    """
    total_code = sum(f["size"] for f in functions)
    matched_code = sum(f["size"] for f in functions if f["addr"] in matched_addrs)
    total_functions = len(functions)
    matched_functions = sum(1 for f in functions if f["addr"] in matched_addrs)

    pct_bytes = (matched_code / total_code * 100.0) if total_code else 0.0
    pct_funcs = (matched_functions / total_functions * 100.0) if total_functions else 0.0
    return {
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
        "total_units": total_functions,
        "complete_units": matched_functions,
    }


def build_units(functions: list, matched_addrs: set) -> list:
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
            function_entries.append({
                "name": f["name"],
                "size": str(f["size"]),
                "metadata": {"virtual_address": str(f["addr"])},
                "address": str(f["addr"] - base_addr),
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

    game_funcs = [f for f in functions if not f["sdk"]]
    sdk_funcs = [f for f in functions if f["sdk"]]

    report = {
        "version": 2,
        "measures": build_measures(functions, matched_addrs),
        "units": build_units(functions, matched_addrs),
        "categories": [
            {
                "id": "game",
                "name": "Game code (SN Systems ProDG)",
                "measures": build_measures(game_funcs, matched_addrs),
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
            print(f"  {label}: {m['matched_code_percent']:.2f}% matched "
                  f"({mc:,} / {tc:,} bytes, "
                  f"{m['matched_functions']:,} / {m['total_functions']:,} funcs)")
        print()
        show("Overall", report["measures"])
        show("Game   ", report["categories"][0]["measures"])
        show("SDK    ", report["categories"][1]["measures"])

    return 0


if __name__ == "__main__":
    sys.exit(main())
