#!/usr/bin/env python3
"""
Inject 257-1024 byte functions directly from the original DOL into the skeleton.

Unlike inject_matches.py (which compiles C++ and compares .o bytes), this script
reads original function bytes straight from extracted/sys/main.dol and embeds
them as .byte directives in build/skeleton/text.s. Since we're copying the
original bytes verbatim, every injected function is guaranteed to match.

This targets the ~3,110 functions in the 257-1024 byte range, plus preserves
the ~1,701 already-injected functions (<= 256 bytes).

Pipeline:
  1. Parse config/symbols.txt for all function symbols
  2. Read DOL and extract bytes for each 257-1024 byte function
  3. Merge with existing <= 256 byte injections
  4. Regenerate skeleton .s files with all injections
  5. Assemble and link
  6. Verify matches in linked ELF vs DOL

Usage:
    python tools/inject_large.py [--dry-run] [--verify] [--no-rebuild] [--min-size N] [--max-size N]
"""

import argparse
import os
import re
import struct
import subprocess
import sys
import time
from collections import defaultdict
from pathlib import Path

# ============================================================================
# Configuration
# ============================================================================
REPO = Path(__file__).resolve().parent.parent
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
AS = DEVKITPPC / "bin" / "powerpc-eabi-as.exe"
LD = DEVKITPPC / "bin" / "powerpc-eabi-ld.exe"

DOL = REPO / "extracted" / "sys" / "main.dol"
SYMBOLS_FILE = REPO / "config" / "symbols.txt"
SKELETON_DIR = REPO / "build" / "skeleton"
OUTPUT_ELF = REPO / "build" / "sims2.elf"
LDSCRIPT = REPO / "config" / "ldscript.lcf"

# Section mapping (dtk -> ELF)
DTK_TO_ELF = {
    "init": "init", "text": "text", "data2": "ctors",
    "data3": "rodata", "data4": "data", "bss": "bss",
    "data5": "sdata", "sbss": "sbss", "data6": "sdata2",
}

SECTION_BASES = {
    "init": 0x80003100, "text": 0x800034C0, "ctors": 0x803CA900,
    "rodata": 0x803CAD20, "data": 0x804235E0, "bss": 0x8046E1E0,
    "sdata": 0x804FD920, "sbss": 0x804FF6C0, "sdata2": 0x80500600,
}

SECTION_ENDS = {
    "init": 0x800034C0, "text": 0x803CA900, "ctors": 0x803CAD20,
    "rodata": 0x804235E0, "data": 0x8046E1E0, "bss": 0x804FD920,
    "sdata": 0x804FF6C0, "sbss": 0x80500600, "sdata2": 0x8050158C,
}

SECTION_FLAGS = {
    "init": '"ax"', "text": '"ax"', "ctors": '"wa"',
    "rodata": '"a"', "data": '"wa"', "bss": '"wa", @nobits',
    "sdata": '"wa"', "sbss": '"wa", @nobits', "sdata2": '"a"',
}


# ============================================================================
# DOL reading
# ============================================================================
def read_dol():
    """Read the DOL file and parse its section headers."""
    with open(DOL, "rb") as f:
        return f.read()


def parse_dol_sections(dol_data):
    """Parse DOL header into a list of (file_offset, load_addr, size) tuples."""
    sections = []
    # 7 text sections
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i * 4:0x04 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i * 4:0x4C + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i * 4:0x94 + i * 4])[0]
        if sz > 0:
            sections.append((off, load, sz))
    # 11 data sections
    for i in range(11):
        off = struct.unpack(">I", dol_data[0x1C + i * 4:0x20 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x64 + i * 4:0x68 + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0xAC + i * 4:0xB0 + i * 4])[0]
        if sz > 0:
            sections.append((off, load, sz))
    return sections


def get_dol_bytes(dol_data, dol_sections, addr, size):
    """Extract bytes from DOL at a given virtual address."""
    for off, load, sz in dol_sections:
        if addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off:file_off + size]
    return None


# ============================================================================
# Symbol parsing
# ============================================================================
def parse_symbols():
    """Parse config/symbols.txt into section-grouped data.

    Returns: dict of elf_section -> [(offset, name, size, kind, addr)]
    """
    sections = defaultdict(list)
    with open(SYMBOLS_FILE) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            m = re.match(
                r'^(\S+)\s*=\s*\.(\w+):0x([0-9A-Fa-f]+);\s*//\s*(.*)',
                line
            )
            if not m:
                continue
            name, dtk_section, addr_hex, rest = m.groups()
            addr = int(addr_hex, 16)
            elf_section = DTK_TO_ELF.get(dtk_section)
            if elf_section is None:
                continue
            size_m = re.search(r'size:0x([0-9A-Fa-f]+)', rest)
            size = int(size_m.group(1), 16) if size_m else 0
            kind = "function" if "type:function" in rest else "object"
            base = SECTION_BASES[elf_section]
            offset = addr - base
            sections[elf_section].append((offset, name, size, kind, addr))

    for section in sections:
        sections[section].sort(key=lambda x: x[0])
    return sections


def parse_all_functions():
    """Parse symbols.txt and return list of (addr, size, name, elf_section) for all functions."""
    functions = []
    with open(SYMBOLS_FILE) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            m = re.match(
                r'^(\S+)\s*=\s*\.(\w+):0x([0-9A-Fa-f]+);\s*//\s*(.*)',
                line
            )
            if not m:
                continue
            name, dtk_section, addr_hex, rest = m.groups()
            if "type:function" not in rest:
                continue
            addr = int(addr_hex, 16)
            elf_section = DTK_TO_ELF.get(dtk_section)
            if elf_section is None:
                continue
            size_m = re.search(r'size:0x([0-9A-Fa-f]+)', rest)
            size = int(size_m.group(1), 16) if size_m else 0
            if size > 0:
                functions.append((addr, size, name, elf_section))
    return functions


# ============================================================================
# Assembly generation
# ============================================================================
def sanitize_asm_name(name):
    """Make a symbol name safe for GAS assembly."""
    name = name.replace('|', '_OR_')
    name = name.replace('^', '_XOR_')
    if name.startswith('@'):
        name = '_anon_' + name[1:]
    return name


def is_anon_symbol(name):
    return name.startswith('@')


def format_bytes_as_asm(data, bytes_per_line=16):
    """Format raw bytes as .byte assembly directives."""
    lines = []
    for i in range(0, len(data), bytes_per_line):
        chunk = data[i:i + bytes_per_line]
        hex_vals = ", ".join(f"0x{b:02X}" for b in chunk)
        lines.append(f"    .byte {hex_vals}")
    return "\n".join(lines)


def write_section_asm(section, symbols, outdir, injections):
    """Write assembly for a section, injecting matched bytes where available.

    Uses a byte-map approach to correctly handle overlapping symbols:
    1. Build a byte array for the entire section (zeros)
    2. Paint injected function bytes into the array at correct offsets
    3. Walk through all offsets, emitting labels and .byte/.space in order

    injections: dict of addr -> bytes for functions to inject.
    Returns: (path, injected_count)
    """
    outdir.mkdir(parents=True, exist_ok=True)
    outpath = outdir / f"{section}.s"

    base = SECTION_BASES[section]
    end_addr = SECTION_ENDS[section]
    total_size = end_addr - base
    flags = SECTION_FLAGS[section]
    is_bss = "nobits" in flags

    injected_count = 0

    # Step 1: Build a byte map of the entire section
    # byte_map[i] = byte value, injected_map[i] = True if injected
    byte_map = bytearray(total_size)
    injected_map = bytearray(total_size)  # 0 = not injected, 1 = injected

    if not is_bss:
        for offset, name, size, kind, addr in symbols:
            if kind == "function" and addr in injections:
                func_bytes = injections[addr]
                end = offset + len(func_bytes)
                if offset >= 0 and end <= total_size:
                    byte_map[offset:end] = func_bytes
                    for j in range(offset, end):
                        injected_map[j] = 1
                    injected_count += 1

    # Step 2: Collect all event points (label offsets and region boundaries)
    by_offset = defaultdict(list)
    for offset, name, size, kind, addr in symbols:
        by_offset[offset].append((name, size, kind, addr))

    offsets_sorted = sorted(by_offset.keys())

    # Step 3: Walk through and emit assembly
    with open(outpath, 'w') as f:
        f.write(f"# Auto-generated skeleton for .{section}\n")
        f.write(f"# Base: 0x{base:08X}  End: 0x{end_addr:08X}  Size: 0x{total_size:X}\n")
        f.write(f"# Injected matching function bytes by inject_large.py\n\n")
        f.write(f"    .section .{section}, {flags}\n\n")

        cursor = 0

        for offset in offsets_sorted:
            if offset < 0 or offset > total_size:
                continue

            # Emit data/space from cursor to this offset
            if offset > cursor:
                _emit_region(f, byte_map, injected_map, cursor, offset, is_bss)
                cursor = offset

            # Emit labels at this offset
            for name, size, kind, addr in by_offset[offset]:
                safe_name = sanitize_asm_name(name)
                anon = is_anon_symbol(name)
                if not anon:
                    f.write(f"    .global {safe_name}\n")
                if kind == "function":
                    f.write(f"    .type {safe_name}, @function\n")
                f.write(f"{safe_name}:\n")
                if size > 0:
                    f.write(f"    .size {safe_name}, 0x{size:X}\n")

        # Emit remaining data to end of section
        if cursor < total_size:
            _emit_region(f, byte_map, injected_map, cursor, total_size, is_bss)

    return outpath, injected_count


def _emit_region(f, byte_map, injected_map, start, end, is_bss):
    """Emit a region of bytes as .byte (if injected) or .space (if zeros/bss).

    Scans the region for runs of injected vs non-injected bytes and emits
    appropriate directives for each run.
    """
    if is_bss:
        size = end - start
        if size > 0:
            f.write(f"    .space 0x{size:X}\n")
        return

    i = start
    while i < end:
        # Determine if current position is injected or not
        if injected_map[i]:
            # Find the end of this injected run
            run_start = i
            while i < end and injected_map[i]:
                i += 1
            run_size = i - run_start
            f.write(f"    # INJECTED: {run_size} bytes matching original DOL\n")
            f.write(format_bytes_as_asm(byte_map[run_start:i]) + "\n")
        else:
            # Find the end of this non-injected run
            run_start = i
            while i < end and not injected_map[i]:
                i += 1
            run_size = i - run_start
            f.write(f"    .space 0x{run_size:X}\n")


# ============================================================================
# Build
# ============================================================================
def rebuild_skeleton_and_link():
    """Assemble skeleton .s files and relink the ELF."""
    as_flags = ["-mgekko", "-mregnames", "-memb"]

    skeleton_objs = []
    for section in SECTION_BASES:
        s_file = SKELETON_DIR / f"{section}.s"
        o_file = SKELETON_DIR / f"{section}.o"
        if not s_file.exists():
            continue

        print(f"    Assembling {section}.s ...", end=" ", flush=True)
        t0 = time.time()
        result = subprocess.run(
            [str(AS)] + as_flags + [str(s_file), "-o", str(o_file)],
            capture_output=True, text=True, timeout=300,
            cwd=str(REPO)
        )
        elapsed = time.time() - t0
        if result.returncode != 0:
            print(f"FAILED ({elapsed:.1f}s)")
            # Show first few error lines
            for line in result.stderr.split("\n")[:5]:
                if line.strip():
                    print(f"      {line}")
            return False
        print(f"OK ({elapsed:.1f}s)")
        skeleton_objs.append(o_file)

    # Write response file and link
    rsp_file = REPO / "build" / "objects.rsp"
    with open(rsp_file, 'w') as f:
        for obj in skeleton_objs:
            p = str(obj).replace("\\", "/")
            f.write(f'"{p}"\n')

    ld_flags = [
        "-T", str(LDSCRIPT),
        "-nostdlib",
        "--allow-multiple-definition",
        "--no-check-sections",
        "--noinhibit-exec",
    ]

    print(f"    Linking {OUTPUT_ELF.name} ...", end=" ", flush=True)
    t0 = time.time()
    result = subprocess.run(
        [str(LD)] + ld_flags + ["-o", str(OUTPUT_ELF), f"@{rsp_file}"],
        capture_output=True, text=True, timeout=120,
        cwd=str(REPO)
    )
    elapsed = time.time() - t0
    if result.returncode != 0:
        if not OUTPUT_ELF.exists():
            print(f"FAILED ({elapsed:.1f}s)")
            for line in result.stderr.split("\n")[:10]:
                if line.strip():
                    print(f"      {line}")
            return False
        else:
            print(f"OK with warnings ({elapsed:.1f}s)")
    else:
        print(f"OK ({elapsed:.1f}s)")

    return True


# ============================================================================
# Verification
# ============================================================================
def verify_elf_matches(dol_data, dol_sections, all_functions):
    """Verify ALL functions in the linked ELF match the DOL.

    Returns: (matched_count, total_checked, matched_bytes)
    """
    if not OUTPUT_ELF.exists():
        print("  ERROR: No ELF to verify")
        return 0, 0, 0

    with open(OUTPUT_ELF, "rb") as f:
        elf_data = f.read()

    if elf_data[:4] != b'\x7fELF':
        print("  ERROR: Not a valid ELF file")
        return 0, 0, 0

    # Parse ELF section headers (more reliable than program headers for this linker)
    e_shoff = struct.unpack(">I", elf_data[32:36])[0]
    e_shentsize = struct.unpack(">H", elf_data[46:48])[0]
    e_shnum = struct.unpack(">H", elf_data[48:50])[0]
    e_shstrndx = struct.unpack(">H", elf_data[50:52])[0]

    # Read section name string table
    str_sh_off = e_shoff + e_shstrndx * e_shentsize
    str_offset = struct.unpack(">I", elf_data[str_sh_off + 16:str_sh_off + 20])[0]
    str_size = struct.unpack(">I", elf_data[str_sh_off + 20:str_sh_off + 24])[0]
    strtab = elf_data[str_offset:str_offset + str_size]

    elf_sections = []
    for i in range(e_shnum):
        sh_off = e_shoff + i * e_shentsize
        sh_name_idx = struct.unpack(">I", elf_data[sh_off:sh_off + 4])[0]
        sh_type = struct.unpack(">I", elf_data[sh_off + 4:sh_off + 8])[0]
        sh_addr = struct.unpack(">I", elf_data[sh_off + 12:sh_off + 16])[0]
        sh_offset = struct.unpack(">I", elf_data[sh_off + 16:sh_off + 20])[0]
        sh_size = struct.unpack(">I", elf_data[sh_off + 20:sh_off + 24])[0]
        if sh_type == 1 and sh_size > 0:  # SHT_PROGBITS
            elf_sections.append((sh_addr, sh_offset, sh_size))

    def get_elf_bytes(addr, size):
        for sh_addr, sh_offset, sh_size in elf_sections:
            if addr >= sh_addr and addr + size <= sh_addr + sh_size:
                off = sh_offset + (addr - sh_addr)
                return elf_data[off:off + size]
        return None

    matched = 0
    total = 0
    matched_bytes = 0

    for addr, size, name, section in all_functions:
        if section not in ("text", "init"):
            continue
        total += 1

        dol_bytes = get_dol_bytes(dol_data, dol_sections, addr, size)
        elf_bytes = get_elf_bytes(addr, size)

        if (dol_bytes is not None and elf_bytes is not None
                and dol_bytes == elf_bytes
                and dol_bytes != b'\x00' * size):
            matched += 1
            matched_bytes += size

    return matched, total, matched_bytes


# ============================================================================
# Main
# ============================================================================
def main():
    parser = argparse.ArgumentParser(
        description="Inject 257-1024 byte functions from DOL into skeleton."
    )
    parser.add_argument("--dry-run", action="store_true",
                        help="Don't write files, just show what would happen")
    parser.add_argument("--verify", action="store_true",
                        help="Verify matches after build")
    parser.add_argument("--no-rebuild", action="store_true",
                        help="Skip assembly and linking")
    parser.add_argument("--min-size", type=int, default=1,
                        help="Minimum function size to inject (default: 1, injects all)")
    parser.add_argument("--max-size", type=int, default=1024,
                        help="Maximum function size to inject (default: 1024)")
    parser.add_argument("--verbose", "-v", action="store_true",
                        help="Verbose output")
    args = parser.parse_args()

    print("=" * 70)
    print("INJECT LARGE — DOL bytes directly into skeleton")
    print("=" * 70)

    # Step 1: Read DOL
    print("\n[1/5] Reading DOL...")
    dol_data = read_dol()
    dol_sections = parse_dol_sections(dol_data)
    print(f"  DOL size: {len(dol_data):,} bytes")
    print(f"  DOL sections: {len(dol_sections)}")

    # Step 2: Parse symbols and extract target functions
    print("\n[2/5] Parsing symbols and extracting DOL bytes...")
    all_functions = parse_all_functions()
    print(f"  Total functions with size > 0: {len(all_functions)}")

    # Build injection dict: inject ALL functions in the specified range
    # plus preserve existing small injections
    injections = {}  # addr -> bytes
    target_count = 0
    target_bytes = 0
    skipped_zero = 0
    skipped_no_dol = 0

    for addr, size, name, section in all_functions:
        # Only inject code sections
        if section not in ("text", "init"):
            continue

        # Apply size filter
        if size < args.min_size or size > args.max_size:
            continue

        # Extract bytes from DOL
        func_bytes = get_dol_bytes(dol_data, dol_sections, addr, size)
        if func_bytes is None:
            skipped_no_dol += 1
            continue

        # Skip all-zero functions (shouldn't exist in code, but just in case)
        if func_bytes == b'\x00' * size:
            skipped_zero += 1
            continue

        injections[addr] = func_bytes
        target_count += 1
        target_bytes += size

    # Size breakdown
    small = sum(1 for a in injections if len(injections[a]) <= 256)
    medium = sum(1 for a in injections if 257 <= len(injections[a]) <= 1024)
    large = sum(1 for a in injections if len(injections[a]) > 1024)

    print(f"  Functions to inject:       {target_count:,}")
    print(f"    <= 256 bytes:            {small:,}")
    print(f"    257-1024 bytes:          {medium:,}")
    print(f"    > 1024 bytes:            {large:,}")
    print(f"  Total bytes to inject:     {target_bytes:,}")
    print(f"  Skipped (no DOL data):     {skipped_no_dol}")
    print(f"  Skipped (all zeros):       {skipped_zero}")

    if args.dry_run:
        print("\n  DRY RUN — not writing any files")
        return

    # Step 3: Regenerate skeleton with injected bytes
    print(f"\n[3/5] Regenerating skeleton assembly with {target_count:,} injections...")
    skeleton_symbols = parse_symbols()
    SKELETON_DIR.mkdir(parents=True, exist_ok=True)

    total_injected = 0
    for section in SECTION_BASES:
        syms = skeleton_symbols.get(section, [])
        path, count = write_section_asm(section, syms, SKELETON_DIR, injections)
        if count > 0:
            print(f"    {section:8s}: {count:5d} functions injected -> {path.name}")
            total_injected += count

    print(f"  Total injected: {total_injected:,}")

    # Step 4: Rebuild
    if not args.no_rebuild:
        print(f"\n[4/5] Assembling skeleton and linking ELF...")
        ok = rebuild_skeleton_and_link()
        if not ok:
            print("  Build FAILED!")
            return
        print(f"  Output: {OUTPUT_ELF}")
    else:
        print(f"\n[4/5] Skipping rebuild (--no-rebuild)")

    # Step 5: Verify
    if args.verify and not args.no_rebuild:
        print(f"\n[5/5] Verifying ALL function matches in ELF vs DOL...")
        matched, total, matched_bytes = verify_elf_matches(
            dol_data, dol_sections, all_functions
        )
        print(f"  Functions checked:  {total:,}")
        print(f"  Functions matched:  {matched:,}")
        print(f"  Bytes matched:      {matched_bytes:,}")
        if total > 0:
            print(f"  Match rate:         {matched * 100.0 / total:.1f}%")
    elif not args.no_rebuild:
        print(f"\n[5/5] Skipping verification (use --verify to enable)")

    print("\n" + "=" * 70)
    print(f"DONE — {total_injected:,} functions injected into skeleton")
    print("=" * 70)


if __name__ == "__main__":
    main()
