#!/usr/bin/env python3
"""
Generate skeleton assembly files with all symbols at correct offsets.

Reads config/symbols.txt and generates one .s file per ELF section that
defines all symbols as global labels at the right offsets, with .space
padding between them. This produces an ELF that dtk can diff against
the original DOL.

symbols.txt uses dtk section names (data2, data3, etc.) which map to
standard ELF section names used in the linker script.

Usage:
    python tools/gen_skeleton.py
"""

import re
from pathlib import Path
from collections import defaultdict

SYMBOLS_FILE = Path("config/symbols.txt")
OUTPUT_DIR = Path("build/skeleton")

# Symbols that exist in compiled source files but whose .init/.text placement
# conflicts with the skeleton. These are excluded from skeleton generation.
# When a symbol is fully in the skeleton (with injected bytes), its source file
# should be excluded from compilation instead — see Makefile ASM_EXCLUDE.
COMPILED_SYMBOLS = set()

# Map dtk section names (from symbols.txt) -> ELF section names (for linker)
DTK_TO_ELF = {
    "init":   "init",
    "text":   "text",
    "data2":  "ctors",     # DOL data[0] = .ctors + .dtors
    "data3":  "rodata",    # DOL data[1]
    "data4":  "data",      # DOL data[2]
    "bss":    "bss",
    "data5":  "sdata",     # DOL data[3]
    "sbss":   "sbss",
    "data6":  "sdata2",    # DOL data[4]
}

# Section base addresses from the original ELF
# Keyed by ELF section name
SECTION_BASES = {
    "init":   0x80003100,
    "text":   0x800034C0,
    "ctors":  0x803CA900,
    "rodata": 0x803CAD20,
    "data":   0x804235E0,
    "bss":    0x8046E1E0,
    "sdata":  0x804FD920,
    "sbss":   0x804FF6C0,
    "sdata2": 0x80500600,
}

# Section end addresses (start of next section or known end)
SECTION_ENDS = {
    "init":   0x800034C0,
    "text":   0x803CA900,
    "ctors":  0x803CAD20,  # .ctors+.dtors combined, ends where .rodata starts
    "rodata": 0x804235E0,
    "data":   0x8046E1E0,
    "bss":    0x804FD920,
    "sdata":  0x804FF6C0,
    "sbss":   0x80500600,
    "sdata2": 0x8050158C,
}

# Section types for assembly directives
SECTION_FLAGS = {
    "init":   '"ax"',
    "text":   '"ax"',
    "ctors":  '"wa"',
    "rodata": '"a"',
    "data":   '"wa"',
    "bss":    '"wa", @nobits',
    "sdata":  '"wa"',
    "sbss":   '"wa", @nobits',
    "sdata2": '"a"',
}


def sanitize_asm_name(name):
    """Make a symbol name safe for GAS assembly.

    The @ prefix is special in GAS (denotes PLT references, etc.).
    | and ^ are also invalid in labels.
    """
    name = name.replace('|', '_OR_')
    name = name.replace('^', '_XOR_')
    if name.startswith('@'):
        name = '_anon_' + name[1:]
    return name


def is_anon_symbol(name):
    """Check if a symbol is an anonymous/internal symbol (@-prefixed)."""
    return name.startswith('@')


def parse_symbols():
    """Parse symbols.txt into a dict of elf_section -> [(offset, name, size, kind)]."""
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

            # Map dtk section name to ELF section name
            elf_section = DTK_TO_ELF.get(dtk_section)
            if elf_section is None:
                print(f"  WARNING: Unknown section '{dtk_section}' for {name}")
                continue

            # Parse size
            size_m = re.search(r'size:0x([0-9A-Fa-f]+)', rest)
            size = int(size_m.group(1), 16) if size_m else 0

            # Parse type
            kind = "function" if "type:function" in rest else "object"

            # Compute offset within section
            base = SECTION_BASES[elf_section]
            offset = addr - base

            sections[elf_section].append((offset, name, size, kind))

    # Sort each section by offset
    for section in sections:
        sections[section].sort(key=lambda x: x[0])

    return sections


def write_section_asm(section, symbols, outdir):
    """Write an assembly file for one section with all symbols."""
    outdir.mkdir(parents=True, exist_ok=True)
    outpath = outdir / f"{section}.s"

    base = SECTION_BASES[section]
    end = SECTION_ENDS[section]
    total_size = end - base
    flags = SECTION_FLAGS[section]
    is_bss = "nobits" in flags

    with open(outpath, 'w') as f:
        f.write(f"# Auto-generated skeleton for .{section}\n")
        f.write(f"# Base: 0x{base:08X}  End: 0x{end:08X}  Size: 0x{total_size:X}\n\n")
        f.write(f"    .section .{section}, {flags}\n\n")

        # Interleave labels and .space in strict offset order.
        # Handles overlapping functions naturally — labels are just
        # placed at the right byte position within the stream.

        by_offset = defaultdict(list)
        for offset, name, size, kind in symbols:
            by_offset[offset].append((name, size, kind))

        offsets_sorted = sorted(by_offset.keys())
        cursor = 0  # Bytes emitted so far

        for i, offset in enumerate(offsets_sorted):
            # Emit space to reach this offset (if cursor hasn't passed it)
            gap = offset - cursor
            if gap > 0:
                f.write(f"    .space 0x{gap:X}\n")
                cursor = offset

            # Emit labels. Skip overlapping symbols where cursor has already
            # passed their offset — GAS can't place them at the right address.
            # (109 overlapping pairs in .text; these get their addresses from
            # the inject step or compiled source instead.)
            if offset >= cursor:
                for name, size, kind in by_offset[offset]:
                    safe_name = sanitize_asm_name(name)
                    anon = is_anon_symbol(name)
                    if not anon:
                        f.write(f"    .global {safe_name}\n")
                    if kind == "function":
                        f.write(f"    .type {safe_name}, @function\n")
                    f.write(f"{safe_name}:\n")
                    if size > 0:
                        f.write(f"    .size {safe_name}, 0x{size:X}\n")

            # Advance cursor to the furthest extent of symbols at this offset.
            # This ensures .space is emitted between sequential non-overlapping
            # symbols. For overlapping symbols (next offset < cursor), the gap
            # check above will skip .space emission.
            for _, size, _ in by_offset[offset]:
                extent = offset + size
                if extent > cursor:
                    cursor = extent

        # Pad to section end
        remaining = total_size - cursor
        if remaining > 0:
            f.write(f"    .space 0x{remaining:X}\n")

    return outpath


def main():
    symbols = parse_symbols()
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    generated = []
    for section in SECTION_BASES:
        syms = symbols.get(section, [])
        path = write_section_asm(section, syms, OUTPUT_DIR)
        generated.append(path)
        print(f"  {section:8s}: {len(syms):5d} symbols -> {path}")

    # Generate overlapping symbol definitions (absolute address assembly)
    overlap_count = write_overlap_symbols(symbols, OUTPUT_DIR)

    print(f"\nGenerated {len(generated)} section files in {OUTPUT_DIR}/")
    print(f"Total symbols: {sum(len(symbols[s]) for s in symbols)}")
    if overlap_count > 0:
        print(f"Overlap symbols: {overlap_count} (in overlaps.s)")


def write_overlap_symbols(symbols, outdir):
    """Generate assembly for overlapping symbols using .set directives.

    Overlapping symbols are internal entry points within larger functions
    (e.g. NotDvdDsi inside DSIExcHandler). The skeleton can't place them
    at the right address because the cursor has already passed their offset.
    Instead, we use .set to define them at absolute addresses.
    """
    overlaps = []

    for section in SECTION_BASES:
        syms = symbols.get(section, [])
        # syms are already sorted by offset
        cursor = 0
        for offset, name, size, kind in syms:
            if offset < cursor:
                # This symbol overlaps with the previous one
                addr = SECTION_BASES[section] + offset
                overlaps.append((name, addr, size, kind))
            # Track furthest extent
            extent = offset + size
            if extent > cursor:
                cursor = extent

    if not overlaps:
        return 0

    # Find the parent symbol for each overlap (the symbol it's inside of).
    # Define overlaps as parent_symbol + offset in linker script, which
    # makes them section-relative (not ABS) so dtk is happy.
    all_syms_by_section = defaultdict(list)
    for section in SECTION_BASES:
        syms = symbols.get(section, [])
        for offset, name, size, kind in syms:
            addr = SECTION_BASES[section] + offset
            all_syms_by_section[section].append((addr, name, size, kind))
        all_syms_by_section[section].sort()

    outpath = outdir / "overlaps.ld"
    with open(outpath, 'w') as f:
        f.write("/* Auto-generated: overlapping symbol definitions */\n")
        f.write("/* Defined relative to parent symbols for section membership. */\n\n")

        for name, addr, size, kind in overlaps:
            # Find which section and parent symbol
            for sec_name, sec_syms in all_syms_by_section.items():
                for i, (sa, sn, ss, sk) in enumerate(sec_syms):
                    if sa <= addr < sa + ss and sn != name:
                        # Found parent symbol — define as parent + offset
                        offset_from_parent = addr - sa
                        safe_name = sanitize_asm_name(name)
                        parent_safe = sanitize_asm_name(sn)
                        f.write(f"{safe_name} = {parent_safe} + 0x{offset_from_parent:X};\n")
                        break
                else:
                    continue
                break
            else:
                # Fallback: absolute definition
                safe_name = sanitize_asm_name(name)
                f.write(f"{safe_name} = 0x{addr:08X};\n")

    return len(overlaps)


if __name__ == "__main__":
    main()
