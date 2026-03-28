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

        for offset in offsets_sorted:
            # Emit space to reach this offset
            gap = offset - cursor
            if gap > 0:
                f.write(f"    .space 0x{gap:X}\n")
                cursor = offset

            # Emit labels (only if we're at or before this offset)
            if cursor <= offset:
                for name, size, kind in by_offset[offset]:
                    safe_name = sanitize_asm_name(name)
                    anon = is_anon_symbol(name)
                    if not anon:
                        f.write(f"    .global {safe_name}\n")
                    if kind == "function":
                        f.write(f"    .type {safe_name}, @function\n")
                    f.write(f"{safe_name}:\n")
                    if kind == "function" and size > 0:
                        f.write(f"    .size {safe_name}, 0x{size:X}\n")
                    elif kind == "object" and size > 0:
                        f.write(f"    .size {safe_name}, 0x{size:X}\n")

            # Track the furthest extent any symbol reaches
            for _, size, _ in by_offset[offset]:
                end = offset + size
                if end > cursor:
                    pass  # Don't advance cursor yet — next label may be within

        # After all labels, advance cursor to furthest extent
        max_extent = cursor
        for offset in offsets_sorted:
            for _, size, _ in by_offset[offset]:
                end = offset + size
                if end > max_extent:
                    max_extent = end

        if max_extent > cursor:
            f.write(f"    .space 0x{max_extent - cursor:X}\n")
            cursor = max_extent

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

    print(f"\nGenerated {len(generated)} section files in {OUTPUT_DIR}/")
    print(f"Total symbols: {sum(len(symbols[s]) for s in symbols)}")


if __name__ == "__main__":
    main()
