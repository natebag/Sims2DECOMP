#!/usr/bin/env python3
"""tu_match.py — Translation Unit compiler and matcher for Sims 2 GC decomp.

Compiles matched functions for a given TU with SDA-aware flags (-msdata=eabi)
and reports which functions match the original DOL bytes.

WHY THIS MATTERS:
  - SDA globals: compiling with -msdata=eabi/-G 8 makes the compiler emit
    r13-relative loads (1 instruction) for small globals, matching the original.
    Without this flag, GCC emits lis/addi pairs (2 instructions) → size mismatch.
  - Shared epilogues: SN compiler can share epilogue code between functions in
    the same TU. The --combine mode compiles all functions together to reproduce
    this behavior.

Usage:
    python tools/tu_match.py caslistener          # test one TU (per-function mode)
    python tools/tu_match.py interaction          # test interaction TU
    python tools/tu_match.py --combine caslistener  # true single-TU compilation
    python tools/tu_match.py --list               # list all TUs in map
    python tools/tu_match.py --list-funcs caslistener  # show TU function list
"""

import sys
import os
import re
import struct
import subprocess
import shutil
from pathlib import Path

# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------
MAP_PATH   = "extracted/files/u2_ngc_release_dvd.map"
DOL_PATH   = "extracted/sys/main.dol"
SN_BIN     = "compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin"
SN_CC1PLUS = os.path.join(SN_BIN, "cc1plus.exe")
SN_AS      = os.path.join(SN_BIN, "NgcAs.exe")
DEVKITPPC  = "F:/coding/Decompiles/Tools/devkitPro/devkitPPC"
DEVKIT_AS  = f"{DEVKITPPC}/bin/powerpc-eabi-as.exe"
DEVKIT_LD  = f"{DEVKITPPC}/bin/powerpc-eabi-ld.exe"
DEVKIT_NM  = f"{DEVKITPPC}/bin/powerpc-eabi-nm.exe"
CXXFILT    = f"{DEVKITPPC}/bin/powerpc-eabi-c++filt.exe"
OBJDUMP    = f"{DEVKITPPC}/bin/powerpc-eabi-objdump.exe"
MATCH_DIRS = ["src/matched/agent", "src/matched/trivial"]
BUILD_DIR  = "build/tu_match"

# SN compiler flags — -msdata=eabi + -G 8 are the SDA fix
# -fno-elide-constructors matches the SN ProDG default for struct returns
SN_COMPILE_FLAGS = [
    "-quiet", "-O2", "-fno-elide-constructors",
    "-msdata=eabi", "-G", "8",
]

# ---------------------------------------------------------------------------
# Map parsing
# ---------------------------------------------------------------------------

def _extract_tu_name(line: str):
    """Extract TU name from a map object-file line.
    Handles two formats:
      - Direct obj:  ...\\objname.obj
      - Lib member:  ...\\libname.lib(objname.obj)
    Returns lowercase tu_name string or None.
    """
    # Lib member: lib(objname.obj)  — paren format
    m = re.search(r'\((\w+)\.obj\)', line, re.IGNORECASE)
    if m:
        return m.group(1).lower()
    # Direct obj: \objname.obj  — backslash format
    m = re.search(r'\\(\w+)\.obj', line, re.IGNORECASE)
    if m:
        return m.group(1).lower()
    return None


def _is_obj_line(line: str) -> bool:
    """Return True if line is a map object-file section header."""
    return bool(re.search(r'\\[\w.]+\.obj|\([\w.]+\.obj\)', line, re.IGNORECASE))


def parse_map_for_tu(tu_name: str) -> list:
    """Return sorted list of (addr, size, full_name) for all .text functions in tu_name."""
    tu_name_lower = tu_name.lower()
    results = []
    in_tu = False

    with open(MAP_PATH, "r", errors="replace") as f:
        for line in f:
            # Detect object file lines
            if _is_obj_line(line):
                name = _extract_tu_name(line)
                if name is not None:
                    in_tu = (name == tu_name_lower)
                continue

            if not in_tu:
                continue

            # Symbol lines have align == 0 and a C++ name with parentheses
            m = re.match(r'([0-9a-f]{8})\s+([0-9a-f]{8})\s+0\s+(.*)', line, re.IGNORECASE)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                if size > 0 and '(' in name and 0x80003100 <= addr < 0x80600000:
                    results.append((addr, size, name))

    return sorted(set(results))  # dedup + sort by addr


def list_all_tus() -> list:
    """Return sorted list of all TU names in the map."""
    tus = set()
    with open(MAP_PATH, "r", errors="replace") as f:
        for line in f:
            name = _extract_tu_name(line)
            if name is not None:
                tus.add(name)
    return sorted(tus)


def parse_all_tus() -> dict:
    """Parse map ONCE and return dict: tu_name -> list of (addr, size, name).
    Much faster than calling parse_map_for_tu() N times.
    """
    tus = {}
    current_tu = None

    with open(MAP_PATH, "r", errors="replace") as f:
        for line in f:
            if _is_obj_line(line):
                name = _extract_tu_name(line)
                if name is not None:
                    current_tu = name
                    if current_tu not in tus:
                        tus[current_tu] = []
                continue

            if not current_tu:
                continue

            m = re.match(r'([0-9a-f]{8})\s+([0-9a-f]{8})\s+0\s+(.*)', line, re.IGNORECASE)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                if size > 0 and '(' in name and 0x80003100 <= addr < 0x80600000:
                    tus[current_tu].append((addr, size, name))

    # Dedup + sort each TU
    return {tu: sorted(set(funcs)) for tu, funcs in tus.items() if funcs}


# ---------------------------------------------------------------------------
# Work queue generation
# ---------------------------------------------------------------------------

def generate_work_queue(output_path: str = "docs/tracking/tu_work_queue.txt"):
    """Scan all TUs, find unmatched functions, output prioritized work queue.

    Sorted by TU completion % descending (highest completion first = easiest wins).
    Format: TU_NAME | FUNC_ADDRESS | SIZE | FUNC_NAME | TU_COMPLETION_%
    """
    print("Scanning all TUs for unmatched functions...")
    all_tus = parse_all_tus()

    # Count matched per TU
    rows = []
    tu_stats = []

    for tu_name, funcs in sorted(all_tus.items()):
        total   = len(funcs)
        matched = sum(1 for addr, _, _ in funcs if find_match_file(addr))
        pct     = 100 * matched / total if total else 0
        tu_stats.append((tu_name, matched, total, pct))

        for addr, size, name in funcs:
            if not find_match_file(addr):
                rows.append((tu_name, addr, size, name, pct, matched, total))

    # Sort: highest TU completion % first, then by size (smallest first)
    rows.sort(key=lambda r: (-r[4], r[2]))

    total_funcs   = sum(t for _, _, t, _ in tu_stats)
    total_matched = sum(m for _, m, _, _ in tu_stats)
    total_unmatched = len(rows)

    # Size distribution of unmatched functions
    tier_20   = sum(1 for _, _, sz, _, _, _, _ in rows if sz <= 20)
    tier_100  = sum(1 for _, _, sz, _, _, _, _ in rows if sz <= 100)
    tier_500  = sum(1 for _, _, sz, _, _, _, _ in rows if sz <= 500)
    tier_big  = sum(1 for _, _, sz, _, _, _, _ in rows if sz > 500)

    print(f"  {len(all_tus)} TUs | {total_matched}/{total_funcs} matched "
          f"({100*total_matched//total_funcs if total_funcs else 0}%) | "
          f"{total_unmatched} unmatched")
    print(f"\n  Unmatched size distribution:")
    print(f"    <=20 bytes  (getter/setter tier):  {tier_20:5d}  ({100*tier_20//total_unmatched if total_unmatched else 0}%)")
    print(f"    <=100 bytes (easy grind tier):     {tier_100:5d}  ({100*tier_100//total_unmatched if total_unmatched else 0}%)")
    print(f"    <=500 bytes (medium tier):         {tier_500:5d}  ({100*tier_500//total_unmatched if total_unmatched else 0}%)")
    print(f"    >500 bytes (complex tier):        {tier_big:5d}  ({100*tier_big//total_unmatched if total_unmatched else 0}%)")

    os.makedirs(os.path.dirname(output_path) or ".", exist_ok=True)

    with open(output_path, "w") as f:
        f.write(f"# Sims 2 GC Decomp — TU Work Queue\n")
        f.write(f"# Generated: {__import__('datetime').date.today()}\n")
        f.write(f"# {len(all_tus)} TUs | {total_matched}/{total_funcs} matched "
                f"({100*total_matched//total_funcs if total_funcs else 0}%)\n")
        f.write(f"# Unmatched functions: {total_unmatched}\n")
        f.write(f"#\n")
        f.write(f"# Size distribution (unmatched):\n")
        f.write(f"#   <=20 bytes  (getter/setter tier): {tier_20}\n")
        f.write(f"#   <=100 bytes (easy grind tier):    {tier_100}\n")
        f.write(f"#   <=500 bytes (medium tier):        {tier_500}\n")
        f.write(f"#   >500 bytes  (complex tier):       {tier_big}\n")
        f.write(f"#\n")
        f.write(f"# Sorted by TU completion % DESC (closest-to-done first = easiest wins)\n")
        f.write(f"# TU_NAME | FUNC_ADDRESS | SIZE | FUNC_NAME | TU_COMPLETION_%\n")
        f.write(f"#{'='*90}\n\n")

        current_tu = None
        for tu_name, addr, size, name, pct, matched, total in rows:
            if tu_name != current_tu:
                current_tu = tu_name
                f.write(f"\n# --- {tu_name} [{matched}/{total}, {pct:.1f}%] ---\n")
            f.write(f"{tu_name} | 0x{addr:08X} | {size:5d} | {name} | {pct:.1f}%\n")

    print(f"\n  Written to {output_path}")

    # Print top TUs closest to completion with remaining work
    tu_stats.sort(key=lambda x: (-x[3], x[2]))  # sort by % desc, then total asc
    print(f"\n  Top TUs by completion % (closest to done):")
    shown = 0
    for tu_name, matched, total, pct in tu_stats:
        remaining = total - matched
        if remaining > 0 and shown < 25:
            print(f"    {tu_name:<35} {matched:3d}/{total:3d} ({pct:5.1f}%)  - {remaining} remaining")
            shown += 1


def generate_decomp_matrix(output_path: str = "docs/tracking/decomp-matrix.txt"):
    """Generate a progress matrix showing matched/total for every TU."""
    import datetime
    print("Generating decomp matrix...")
    all_tus = parse_all_tus()

    tu_stats = []
    for tu_name, funcs in sorted(all_tus.items()):
        total   = len(funcs)
        matched = sum(1 for addr, _, _ in funcs if find_match_file(addr))
        pct     = 100 * matched / total if total else 0
        tu_stats.append((tu_name, matched, total, pct))

    total_funcs   = sum(t for _, _, t, _ in tu_stats)
    total_matched = sum(m for _, m, _, _ in tu_stats)
    total_pct     = 100 * total_matched / total_funcs if total_funcs else 0

    # Sort alphabetically for the matrix
    tu_stats.sort(key=lambda x: x[0])

    os.makedirs(os.path.dirname(output_path) or ".", exist_ok=True)

    bar_width = 50
    with open(output_path, "w") as f:
        f.write(f"# Decomp Progress Matrix\n")
        f.write(f"# Generated: {datetime.date.today()}\n")
        f.write(f"# Total: {total_matched} matched / {total_funcs} functions\n")
        f.write(f"# Coverage: {total_pct:.1f}%\n")
        f.write(f"# TUs: {len(tu_stats)}\n\n")
        f.write(f"{'TU Name':<45} {'Matched':>7} {'Total':>5} {'%':>7}  Bar\n")
        f.write("-" * 120 + "\n")

        for tu_name, matched, total, pct in tu_stats:
            filled = int(bar_width * pct / 100)
            bar = "#" * filled + "." * (bar_width - filled)
            f.write(f"{tu_name:<45} {matched:3d}/{total:<3d}   {pct:5.1f}%  [{bar}]\n")

    print(f"  {len(tu_stats)} TUs | {total_matched}/{total_funcs} matched ({total_pct:.1f}%)")
    print(f"  Written to {output_path}")


# ---------------------------------------------------------------------------
# Match file lookup
# ---------------------------------------------------------------------------

def find_match_file(addr: int) -> str:
    """Return path to a matched .cpp for the given address, or empty string."""
    addr_hex = f"{addr:08x}"
    addr_HEX = f"{addr:08X}"
    for d in MATCH_DIRS:
        if not os.path.isdir(d):
            continue
        for fname in os.listdir(d):
            fl = fname.lower()
            if (addr_hex in fl or addr_HEX.lower() in fl) and fname.endswith(".cpp"):
                return os.path.join(d, fname)
    return ""


# ---------------------------------------------------------------------------
# DOL helpers
# ---------------------------------------------------------------------------

def load_dol() -> bytes:
    with open(DOL_PATH, "rb") as f:
        return f.read()


def vaddr_to_offset(dol: bytes, vaddr: int):
    # 7 text sections
    for i in range(7):
        off  = struct.unpack(">I", dol[i*4:i*4+4])[0]
        addr = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
        sz   = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    # 11 data sections
    for i in range(11):
        off  = struct.unpack(">I", dol[0x1C+i*4:0x1C+i*4+4])[0]
        addr = struct.unpack(">I", dol[0x64+i*4:0x64+i*4+4])[0]
        sz   = struct.unpack(">I", dol[0xAC+i*4:0xAC+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    return None


def get_dol_bytes(dol: bytes, addr: int, size: int):
    off = vaddr_to_offset(dol, addr)
    if off is None:
        return None
    return dol[off:off+size]


# ---------------------------------------------------------------------------
# Compilation
# ---------------------------------------------------------------------------

def strip_comments(src: str) -> str:
    """Strip // and /* */ comments (GCC 2.95 old preprocessor quirk workaround)."""
    src = re.sub(r'/\*.*?\*/', '', src, flags=re.DOTALL)
    src = re.sub(r'//[^\n]*', '', src)
    return src


def compile_file(src_path: str, asm_path: str, obj_path: str,
                 force_devkit_as: bool = False) -> tuple:
    """Compile src_path -> asm_path -> obj_path with SN ProDG.
    force_devkit_as=True: always use devkitPPC assembler (required for ld -r merging).
    Returns (success: bool, error_msg: str).
    """
    # Clean comments for GCC 2.95 compat — write to BUILD_DIR, not source dir
    with open(src_path, "r", errors="replace") as f:
        content = f.read()
    clean_name = os.path.basename(src_path).rsplit(".", 1)[0] + "_clean.cpp"
    clean_path = os.path.join(BUILD_DIR, clean_name)
    os.makedirs(BUILD_DIR, exist_ok=True)
    with open(clean_path, "w") as f:
        f.write(strip_comments(content))

    # cc1plus: C++ -> assembly
    cmd = [SN_CC1PLUS, clean_path, "-o", asm_path] + SN_COMPILE_FLAGS
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode != 0:
        return False, (r.stdout + r.stderr).strip()[:200]

    # Assemble
    if force_devkit_as:
        # devkitPPC assembler always (produces standard ELF compatible with ld -r / nm)
        r_as = subprocess.run(
            [DEVKIT_AS, "-mgekko", "-mregnames", asm_path, "-o", obj_path],
            capture_output=True, text=True
        )
        if r_as.returncode != 0:
            return False, (r_as.stdout + r_as.stderr).strip()[:200]
    else:
        # Try SN assembler first (matches SN ProDG output more closely), fall back
        r_as = subprocess.run([SN_AS, asm_path, "-o", obj_path], capture_output=True, text=True)
        if r_as.returncode != 0:
            r_as2 = subprocess.run(
                [DEVKIT_AS, "-mgekko", "-mregnames", asm_path, "-o", obj_path],
                capture_output=True, text=True
            )
            if r_as2.returncode != 0:
                return False, (r_as.stdout + r_as.stderr).strip()[:200]

    return True, ""


# ---------------------------------------------------------------------------
# Object file analysis
# ---------------------------------------------------------------------------

def get_obj_text_bytes(obj_path: str) -> bytes:
    """Extract .text section bytes from compiled .o."""
    r = subprocess.run([OBJDUMP, "-s", "-j", ".text", obj_path],
                       capture_output=True, text=True)
    if r.returncode != 0:
        return b""

    data = []
    in_section = False
    for line in r.stdout.splitlines():
        if "Contents of section .text" in line:
            in_section = True
            continue
        if not in_section:
            continue
        line = line.strip()
        if not line:
            break
        # "OFFSET HHHHHHHH HHHHHHHH HHHHHHHH HHHHHHHH  ascii"
        parts = line.split()
        for p in parts[1:5]:
            if len(p) == 8:
                try:
                    v = int(p, 16)
                    data.extend([(v >> 24) & 0xFF, (v >> 16) & 0xFF, (v >> 8) & 0xFF, v & 0xFF])
                except ValueError:
                    pass
    return bytes(data)


def get_reloc_offsets(obj_path: str) -> set:
    """Return set of byte offsets in .text that are relocation targets."""
    r = subprocess.run([OBJDUMP, "-r", obj_path], capture_output=True, text=True)
    offsets = set()
    for line in r.stdout.splitlines():
        m = re.match(r'^([0-9a-f]+)\s+R_PPC', line, re.IGNORECASE)
        if m:
            off = int(m.group(1), 16)
            # Mask full 4-byte instruction containing the relocation
            base = (off // 4) * 4
            for b in range(4):
                offsets.add(base + b)
    return offsets


def compare_bytes_masked(dol_bytes: bytes, compiled_bytes: bytes, reloc_offsets: set):
    """Compare bytes with relocation masking. Returns (is_match, diff_list)."""
    size = len(dol_bytes)
    if len(compiled_bytes) < size:
        return False, [f"SIZE_MISMATCH: DOL={size}B, compiled={len(compiled_bytes)}B"]

    comp = compiled_bytes[:size]
    seen_instrs = set()
    diffs = []

    for i in range(size):
        if i in reloc_offsets:
            continue
        if comp[i] != dol_bytes[i]:
            instr_off = (i // 4) * 4
            if instr_off not in seen_instrs:
                seen_instrs.add(instr_off)
                dol_w  = dol_bytes[instr_off:instr_off+4].hex()
                comp_w = comp[instr_off:instr_off+4].hex()
                diffs.append(f"    +0x{instr_off:03x}: DOL={dol_w}  compiled={comp_w}")

    return len(diffs) == 0, diffs


# ---------------------------------------------------------------------------
# Per-function mode (default)
# ---------------------------------------------------------------------------

def match_tu_per_function(tu_name: str, verbose: bool = True) -> dict:
    """Compile each matched function individually, compare against DOL."""
    os.makedirs(BUILD_DIR, exist_ok=True)

    funcs = parse_map_for_tu(tu_name)
    if not funcs:
        print(f"ERROR: TU '{tu_name}' not found in map or has no functions.")
        return {}

    dol = load_dol()

    print(f"\n=== TU: {tu_name} — {len(funcs)} functions ===")
    print(f"    Compiler: SN ProDG cc1plus  Flags: {' '.join(SN_COMPILE_FLAGS)}\n")

    counts = {"match": 0, "mismatch": 0, "no_source": 0, "error": 0}
    results = {}

    for addr, size, name in funcs:
        short = name.split("::")[0] if "::" in name else name.split("(")[0]
        label = f"  0x{addr:08X} ({size:4d}B) {name.split('(')[0]}"

        match_file = find_match_file(addr)
        if not match_file:
            counts["no_source"] += 1
            results[addr] = "no_source"
            print(f"{label:<72}  [no source]")
            continue

        basename  = f"{tu_name}_{addr:08X}"
        asm_path  = os.path.join(BUILD_DIR, f"{basename}.s")
        obj_path  = os.path.join(BUILD_DIR, f"{basename}.o")

        ok, err = compile_file(match_file, asm_path, obj_path)
        if not ok:
            counts["error"] += 1
            results[addr] = "error"
            print(f"{label:<72}  [compile error] {err[:60]}")
            continue

        dol_bytes = get_dol_bytes(dol, addr, size)
        if dol_bytes is None:
            print(f"{label:<72}  [dol addr not found]")
            continue

        compiled  = get_obj_text_bytes(obj_path)
        relocs    = get_reloc_offsets(obj_path)
        is_match, diffs = compare_bytes_masked(dol_bytes, compiled, relocs)

        if is_match:
            counts["match"] += 1
            results[addr] = "match"
            print(f"{label:<72}  MATCH")
        else:
            counts["mismatch"] += 1
            results[addr] = "mismatch"
            print(f"{label:<72}  MISMATCH")
            if verbose and diffs:
                for d in diffs[:4]:
                    print(d)

    # Summary
    tested = counts["match"] + counts["mismatch"] + counts["error"]
    total  = len(funcs)
    pct    = 100 * counts["match"] // tested if tested else 0

    print(f"\n--- {tu_name} summary ---")
    print(f"  MATCH:      {counts['match']}")
    print(f"  MISMATCH:   {counts['mismatch']}")
    print(f"  No source:  {counts['no_source']}")
    print(f"  Error:      {counts['error']}")
    print(f"  Match rate: {counts['match']}/{tested} tested ({pct}%)")
    print(f"  Overall:    {counts['match']}/{total} ({100*counts['match']//total if total else 0}%)")

    return results


# ---------------------------------------------------------------------------
# Combined TU mode — compile individually, merge with ld -r, extract per-function
# ---------------------------------------------------------------------------

def nm_symbols(obj_path: str) -> list:
    """Return list of (offset, mangled_name) for .text symbols, sorted by offset."""
    r = subprocess.run([DEVKIT_NM, "-n", "--defined-only", obj_path],
                       capture_output=True, text=True)
    syms = []
    for line in r.stdout.splitlines():
        # Format: "XXXXXXXX T symbol_name"  (T = .text)
        m = re.match(r'^([0-9a-f]{8})\s+[Tt]\s+(\S+)', line, re.IGNORECASE)
        if m:
            syms.append((int(m.group(1), 16), m.group(2)))
    return sorted(syms)


def demangle(mangled_names: list) -> list:
    """Demangle a list of C++ names via c++filt. Returns same-length list."""
    if not mangled_names:
        return []
    r = subprocess.run([CXXFILT], input="\n".join(mangled_names),
                       capture_output=True, text=True)
    if r.returncode != 0:
        return mangled_names
    demangled = r.stdout.strip().split("\n")
    # Pad/truncate to same length
    while len(demangled) < len(mangled_names):
        demangled.append(mangled_names[len(demangled)])
    return demangled[:len(mangled_names)]


def normalize_name(name: str) -> str:
    """Normalize a C++ name for loose matching (strip args, spaces)."""
    # Remove argument list
    name = re.sub(r'\s*\(.*', '', name)
    # Remove spaces
    name = re.sub(r'\s+', '', name)
    return name.lower()


def match_tu_combined(tu_name: str, verbose: bool = True):
    """
    Combined TU mode:
    1. Compile each matched function individually (with SDA flags)
    2. Merge all .o files with ld -r → combined.o
    3. Use nm to extract per-function byte offsets from combined.o
    4. For each function: extract bytes at its offset, compare vs DOL
    5. Report MATCH/MISMATCH per function

    The combined .o means the compiler sees SDA context across the whole TU,
    and shared epilogues (if present) are preserved across function boundaries.
    """
    os.makedirs(BUILD_DIR, exist_ok=True)

    funcs = parse_map_for_tu(tu_name)
    if not funcs:
        print(f"ERROR: TU '{tu_name}' not found in map.")
        return

    dol = load_dol()

    print(f"\n=== TU: {tu_name} [combined] — {len(funcs)} functions ===")
    print(f"    Compiler: SN ProDG cc1plus  Flags: {' '.join(SN_COMPILE_FLAGS)}\n")

    # Step 1: Compile each matched function
    obj_files   = []   # list of (addr, size, name, obj_path)
    no_source   = 0

    for addr, size, name in funcs:
        mf = find_match_file(addr)
        if not mf:
            no_source += 1
            continue
        basename = f"{tu_name}_{addr:08X}"
        asm_path = os.path.join(BUILD_DIR, f"{basename}.s")
        obj_path = os.path.join(BUILD_DIR, f"{basename}.o")
        # force_devkit_as=True so all .o files are standard ELF for ld -r merging
        ok, err  = compile_file(mf, asm_path, obj_path, force_devkit_as=True)
        if ok:
            obj_files.append((addr, size, name, obj_path))
        else:
            label = f"  0x{addr:08X} ({size:4d}B) {name.split('(')[0]}"
            print(f"{label:<72}  [compile error] {err[:60]}")

    if not obj_files:
        print("No functions compiled successfully.")
        return

    # Step 2: Merge with ld -r
    combined_obj = os.path.join(BUILD_DIR, f"{tu_name}_combined.o")
    r_ld = subprocess.run(
        [DEVKIT_LD, "-r", "-o", combined_obj] + [o for _, _, _, o in obj_files],
        capture_output=True, text=True
    )
    if r_ld.returncode != 0:
        print(f"ld -r failed: {r_ld.stderr[:200]}")
        print("Falling back to per-function .o analysis...")
        _match_from_individual_objs(funcs, obj_files, dol, no_source, verbose)
        return

    # Step 3: Build addr → offset map using cumulative .text sizes.
    # ld -r concatenates .text sections in input order, so offsets are deterministic.
    combined_text   = get_obj_text_bytes(combined_obj)
    combined_relocs = get_reloc_offsets(combined_obj)

    cumulative = 0
    addr_to_combined_off = {}
    for addr, size, name, obj_path in obj_files:
        addr_to_combined_off[addr] = cumulative
        cumulative += len(get_obj_text_bytes(obj_path))  # advance by that function's size

    # Step 4: Compare per function
    counts = {"match": 0, "mismatch": 0, "no_source": no_source, "error": 0}

    for addr, size, name in funcs:
        label = f"  0x{addr:08X} ({size:4d}B) {name.split('(')[0]}"

        if not find_match_file(addr):
            print(f"{label:<72}  [no source]")
            continue

        if addr not in addr_to_combined_off:
            counts["error"] += 1
            print(f"{label:<72}  [compile error]")
            continue

        off      = addr_to_combined_off[addr]
        compiled = combined_text[off : off + size]
        relocs   = {r - off for r in combined_relocs if off <= r < off + size}

        dol_bytes = get_dol_bytes(dol, addr, size)
        if dol_bytes is None:
            print(f"{label:<72}  [dol addr not found]")
            continue

        is_match, diffs = compare_bytes_masked(dol_bytes, compiled, relocs)

        if is_match:
            counts["match"] += 1
            print(f"{label:<72}  MATCH")
        else:
            counts["mismatch"] += 1
            print(f"{label:<72}  MISMATCH")
            if verbose and diffs:
                for d in diffs[:4]:
                    print(d)

    total  = len(funcs)
    tested = counts["match"] + counts["mismatch"] + counts["error"]
    pct    = 100 * counts["match"] // tested if tested else 0

    print(f"\n--- {tu_name} [combined] summary ---")
    print(f"  MATCH:      {counts['match']}")
    print(f"  MISMATCH:   {counts['mismatch']}")
    print(f"  No source:  {counts['no_source']}")
    print(f"  Error:      {counts['error']}")
    print(f"  Match rate: {counts['match']}/{tested} tested ({pct}%)")
    print(f"  Overall:    {counts['match']}/{total} ({100*counts['match']//total if total else 0}%)")
    print(f"  Combined .o: {combined_obj}")


def _match_from_individual_objs(funcs, obj_files, dol, no_source, verbose):
    """Fallback: use per-function .o files when ld -r merge fails."""
    addr_to_obj = {a: (s, n, o) for a, s, n, o in obj_files}
    counts = {"match": 0, "mismatch": 0, "no_source": no_source, "error": 0}

    for addr, size, name in funcs:
        label = f"  0x{addr:08X} ({size:4d}B) {name.split('(')[0]}"
        if addr not in addr_to_obj:
            if not find_match_file(addr):
                counts["no_source"] += 1
                print(f"{label:<72}  [no source]")
            else:
                counts["error"] += 1
                print(f"{label:<72}  [compile error]")
            continue

        _, _, obj_path = addr_to_obj[addr]
        dol_bytes  = get_dol_bytes(dol, addr, size)
        if dol_bytes is None:
            print(f"{label:<72}  [dol addr not found]")
            continue

        compiled   = get_obj_text_bytes(obj_path)
        relocs     = get_reloc_offsets(obj_path)
        is_match, diffs = compare_bytes_masked(dol_bytes, compiled, relocs)

        if is_match:
            counts["match"] += 1
            print(f"{label:<72}  MATCH")
        else:
            counts["mismatch"] += 1
            print(f"{label:<72}  MISMATCH")
            if verbose and diffs:
                for d in diffs[:4]:
                    print(d)


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main():
    args = sys.argv[1:]

    if not args or "--help" in args or "-h" in args:
        print(__doc__)
        sys.exit(0)

    if "--list" in args:
        tus = list_all_tus()
        print(f"{len(tus)} TUs in map:")
        for t in tus:
            print(f"  {t}")
        return

    combine_mode = "--combine" in args
    if combine_mode:
        args = [a for a in args if a != "--combine"]

    list_funcs = "--list-funcs" in args
    if list_funcs:
        args = [a for a in args if a != "--list-funcs"]
        if args:
            funcs = parse_map_for_tu(args[0])
            print(f"{len(funcs)} functions in TU '{args[0]}':")
            for addr, size, name in funcs:
                mf = find_match_file(addr)
                flag = "  [matched]" if mf else ""
                print(f"  0x{addr:08X} ({size:4d}B) {name}{flag}")
        return

    decomp_matrix = "--decomp-matrix" in args
    if decomp_matrix:
        args = [a for a in args if a != "--decomp-matrix"]
        output = args[0] if args else "docs/tracking/decomp-matrix.txt"
        generate_decomp_matrix(output)
        return

    work_queue = "--work-queue" in args
    if work_queue:
        output = "docs/tracking/tu_work_queue.txt"
        # Allow custom output path: --work-queue path/to/file.txt
        remaining = [a for a in args if a != "--work-queue"]
        if remaining:
            output = remaining[0]
        generate_work_queue(output)
        return

    if not args:
        print("ERROR: specify a TU name.")
        sys.exit(1)

    tu_name = args[0]

    if combine_mode:
        match_tu_combined(tu_name)
    else:
        match_tu_per_function(tu_name)


if __name__ == "__main__":
    main()
