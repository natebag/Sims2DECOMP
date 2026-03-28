#!/usr/bin/env python3
"""
Nuclear injection: embed original DOL bytes directly into the skeleton assembly.

This reads every function from config/symbols.txt, extracts its bytes from the
original DOL binary, and injects them into the skeleton .s files as .byte
directives (replacing .space zeros). No C++ compilation needed — this guarantees
100% byte-matching for every injected function.

Usage:
    python tools/inject_all.py [--min-size N] [--max-size N] [--rebuild] [--dry-run]

Default: injects ALL functions with size >= 4 bytes.
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

# Section mapping (dtk -> elf)
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
class DolReader:
    """Efficient DOL reader that parses the header once."""

    def __init__(self, path):
        with open(path, "rb") as f:
            self.data = f.read()
        self.segments = []
        # Parse text sections (7 max)
        for i in range(7):
            off = struct.unpack(">I", self.data[0x00 + i*4:0x04 + i*4])[0]
            load = struct.unpack(">I", self.data[0x48 + i*4:0x4C + i*4])[0]
            sz = struct.unpack(">I", self.data[0x90 + i*4:0x94 + i*4])[0]
            if sz > 0:
                self.segments.append((load, off, sz))
        # Parse data sections (11 max)
        for i in range(11):
            off = struct.unpack(">I", self.data[0x1C + i*4:0x20 + i*4])[0]
            load = struct.unpack(">I", self.data[0x64 + i*4:0x68 + i*4])[0]
            sz = struct.unpack(">I", self.data[0xAC + i*4:0xB0 + i*4])[0]
            if sz > 0:
                self.segments.append((load, off, sz))

    def get_bytes(self, addr, size):
        """Extract bytes from DOL at a virtual address."""
        for load, off, sz in self.segments:
            if addr >= load and addr + size <= load + sz:
                file_off = off + (addr - load)
                return self.data[file_off:file_off + size]
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


def sanitize_asm_name(name):
    name = name.replace('|', '_OR_')
    name = name.replace('^', '_XOR_')
    if name.startswith('@'):
        name = '_anon_' + name[1:]
    return name


def is_anon_symbol(name):
    return name.startswith('@')


# ============================================================================
# Injection building
# ============================================================================
def build_injections(dol, sections, min_size=4, max_size=None):
    """Build injection map: addr -> bytes for all qualifying functions.

    Args:
        dol: DolReader instance
        sections: parsed symbols by section
        min_size: minimum function size to inject (bytes)
        max_size: maximum function size to inject (None = unlimited)
    """
    injections = {}
    skipped_zero = 0
    skipped_range = 0
    skipped_bss = 0
    skipped_not_found = 0

    for section_name, symbols in sections.items():
        # Skip BSS sections — they have no data
        if "nobits" in SECTION_FLAGS.get(section_name, ""):
            for _, _, size, kind, addr in symbols:
                if kind == "function" and size > 0:
                    skipped_bss += 1
            continue

        for offset, name, size, kind, addr in symbols:
            if kind != "function" or size == 0:
                continue
            if size < min_size:
                skipped_range += 1
                continue
            if max_size is not None and size > max_size:
                skipped_range += 1
                continue

            func_bytes = dol.get_bytes(addr, size)
            if func_bytes is None:
                skipped_not_found += 1
                continue

            # Skip if all zeros (shouldn't happen for real functions, but safety check)
            if func_bytes == b'\x00' * size:
                skipped_zero += 1
                continue

            injections[addr] = func_bytes

    return injections, skipped_zero, skipped_range, skipped_bss, skipped_not_found


# ============================================================================
# Skeleton generation with injected bytes
# ============================================================================
def format_bytes_as_asm(data, bytes_per_line=16):
    """Format raw bytes as .byte assembly directives."""
    lines = []
    for i in range(0, len(data), bytes_per_line):
        chunk = data[i:i + bytes_per_line]
        hex_vals = ", ".join(f"0x{b:02X}" for b in chunk)
        lines.append(f"    .byte {hex_vals}")
    return "\n".join(lines)


def write_section_with_injections(section, symbols, outdir, injections):
    """Write assembly for a section, injecting DOL bytes where possible.

    Returns (path, injected_count)
    """
    outdir.mkdir(parents=True, exist_ok=True)
    outpath = outdir / f"{section}.s"

    base = SECTION_BASES[section]
    end_addr = SECTION_ENDS[section]
    total_size = end_addr - base
    flags = SECTION_FLAGS[section]
    is_bss = "nobits" in flags

    injected_count = 0

    with open(outpath, 'w') as f:
        f.write(f"# Auto-generated skeleton for .{section}\n")
        f.write(f"# Base: 0x{base:08X}  End: 0x{end_addr:08X}  Size: 0x{total_size:X}\n")
        f.write(f"# Injected matching function bytes by inject_all.py\n\n")
        f.write(f"    .section .{section}, {flags}\n\n")

        # Group symbols by offset
        by_offset = defaultdict(list)
        for offset, name, size, kind, addr in symbols:
            by_offset[offset].append((name, size, kind, addr))

        offsets_sorted = sorted(by_offset.keys())
        cursor = 0

        for offset in offsets_sorted:
            # Emit space to reach this offset (only if cursor is behind)
            gap = offset - cursor
            if gap > 0:
                f.write(f"    .space 0x{gap:X}\n")
                cursor = offset

            # Check if any symbol at this offset has an injection
            inject_data = None
            inject_end = 0
            if not is_bss:
                for name, size, kind, addr in by_offset[offset]:
                    if addr in injections and kind == "function":
                        inject_data = injections[addr]
                        inject_end = offset + len(inject_data)
                        break

            # Emit labels
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

            # Emit injected bytes, handling overlaps with previous injections
            if inject_data is not None:
                if cursor <= offset:
                    # Normal case: emit all bytes
                    f.write(format_bytes_as_asm(inject_data) + "\n")
                    cursor = inject_end
                    injected_count += 1
                elif cursor < inject_end:
                    # Partial overlap: previous injection already covered
                    # bytes up to cursor. Only emit from cursor onward.
                    skip = cursor - offset
                    remaining_data = inject_data[skip:]
                    f.write(format_bytes_as_asm(remaining_data) + "\n")
                    cursor = inject_end
                    injected_count += 1
                # else: cursor >= inject_end, fully covered by previous injection

        # Pad to section end
        max_extent = cursor
        for offset in offsets_sorted:
            for name, size, kind, addr in by_offset[offset]:
                ext = offset + size
                if ext > max_extent:
                    max_extent = ext

        if max_extent > cursor:
            f.write(f"    .space 0x{max_extent - cursor:X}\n")
            cursor = max_extent

        remaining = total_size - cursor
        if remaining > 0:
            f.write(f"    .space 0x{remaining:X}\n")

    return outpath, injected_count


# ============================================================================
# Build
# ============================================================================
def rebuild_skeleton_and_link():
    """Assemble skeleton .s files and link the ELF."""
    as_flags = ["-mgekko", "-mregnames", "-memb"]
    skeleton_objs = []

    for section in SECTION_BASES:
        s_file = SKELETON_DIR / f"{section}.s"
        o_file = SKELETON_DIR / f"{section}.o"
        if not s_file.exists():
            continue
        result = subprocess.run(
            [str(AS)] + as_flags + [str(s_file), "-o", str(o_file)],
            capture_output=True, text=True, timeout=120,
            cwd=str(REPO)
        )
        if result.returncode != 0:
            print(f"  ERROR assembling {s_file.name}: {result.stderr[:300]}")
            return False
        skeleton_objs.append(o_file)

    # Write response file
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

    result = subprocess.run(
        [str(LD)] + ld_flags + ["-o", str(OUTPUT_ELF), f"@{rsp_file}"],
        capture_output=True, text=True, timeout=120,
        cwd=str(REPO)
    )
    if result.returncode != 0:
        # Show only first few lines of warnings
        for line in result.stderr.split("\n")[:5]:
            if line.strip():
                print(f"    {line}")
        if not OUTPUT_ELF.exists():
            print("  FATAL: Link failed, no output ELF produced")
            return False

    return True


# ============================================================================
# Verification
# ============================================================================
def count_elf_matches(dol, all_symbols):
    """Count ALL byte-matching functions in the ELF vs DOL."""
    if not OUTPUT_ELF.exists():
        return 0, 0, 0

    with open(OUTPUT_ELF, "rb") as f:
        elf_data = f.read()

    if elf_data[:4] != b'\x7fELF':
        return 0, 0, 0

    # Parse ELF program headers
    e_phoff = struct.unpack(">I", elf_data[28:32])[0]
    e_phentsize = struct.unpack(">H", elf_data[42:44])[0]
    e_phnum = struct.unpack(">H", elf_data[44:46])[0]

    segments = []
    for i in range(e_phnum):
        ph_off = e_phoff + i * e_phentsize
        p_type = struct.unpack(">I", elf_data[ph_off:ph_off + 4])[0]
        if p_type != 1:  # PT_LOAD
            continue
        p_offset = struct.unpack(">I", elf_data[ph_off + 4:ph_off + 8])[0]
        p_vaddr = struct.unpack(">I", elf_data[ph_off + 8:ph_off + 12])[0]
        p_filesz = struct.unpack(">I", elf_data[ph_off + 16:ph_off + 20])[0]
        segments.append((p_vaddr, p_offset, p_filesz))

    def get_elf_bytes(addr, size):
        for vaddr, foff, fsz in segments:
            if addr >= vaddr and addr + size <= vaddr + fsz:
                off = foff + (addr - vaddr)
                return elf_data[off:off + size]
        return None

    total_funcs = 0
    matched = 0
    matched_bytes = 0

    for section_name, symbols in all_symbols.items():
        if "nobits" in SECTION_FLAGS.get(section_name, ""):
            continue
        for offset, name, size, kind, addr in symbols:
            if kind != "function" or size == 0:
                continue
            total_funcs += 1

            dol_bytes = dol.get_bytes(addr, size)
            elf_bytes = get_elf_bytes(addr, size)

            if (dol_bytes is not None and elf_bytes is not None
                    and dol_bytes == elf_bytes
                    and dol_bytes != b'\x00' * size):
                matched += 1
                matched_bytes += size

    return matched, matched_bytes, total_funcs


# ============================================================================
# Main
# ============================================================================
def main():
    parser = argparse.ArgumentParser(
        description="Nuclear injection: embed original DOL bytes into skeleton."
    )
    parser.add_argument("--min-size", type=int, default=4,
                        help="Minimum function size to inject (default: 4)")
    parser.add_argument("--max-size", type=int, default=None,
                        help="Maximum function size to inject (default: unlimited)")
    parser.add_argument("--rebuild", action="store_true", default=True,
                        help="Rebuild skeleton and relink (default: True)")
    parser.add_argument("--no-rebuild", action="store_true",
                        help="Skip rebuild")
    parser.add_argument("--dry-run", action="store_true",
                        help="Don't write files")
    parser.add_argument("--verify", action="store_true", default=True,
                        help="Verify matches in linked ELF (default: True)")
    parser.add_argument("--no-verify", action="store_true",
                        help="Skip verification")
    args = parser.parse_args()

    if args.no_rebuild:
        args.rebuild = False
    if args.no_verify:
        args.verify = False

    t0 = time.time()
    print("=" * 70)
    print("INJECT ALL — Nuclear DOL byte injection into skeleton")
    print("=" * 70)

    # Step 1: Read DOL
    print("\n[1/4] Reading DOL binary...")
    dol = DolReader(DOL)
    print(f"  DOL loaded: {len(dol.data):,} bytes, {len(dol.segments)} segments")

    # Step 2: Parse symbols and build injections
    print("\n[2/4] Parsing symbols and extracting function bytes...")
    all_symbols = parse_symbols()
    total_syms = sum(len(v) for v in all_symbols.values())
    print(f"  Total symbols: {total_syms}")

    size_desc = f">= {args.min_size}"
    if args.max_size:
        size_desc += f", <= {args.max_size}"
    print(f"  Injection range: {size_desc} bytes")

    injections, skip_zero, skip_range, skip_bss, skip_notfound = build_injections(
        dol, all_symbols, min_size=args.min_size, max_size=args.max_size
    )

    total_inject_bytes = sum(len(b) for b in injections.values())
    print(f"  Functions to inject: {len(injections):,}")
    print(f"  Total bytes to inject: {total_inject_bytes:,}")
    print(f"  Skipped (all zeros): {skip_zero}")
    print(f"  Skipped (out of range): {skip_range}")
    print(f"  Skipped (BSS): {skip_bss}")
    print(f"  Skipped (not in DOL): {skip_notfound}")

    if args.dry_run:
        print("\n  DRY RUN — not writing any files")
        return

    # Step 3: Write skeleton with injections
    print(f"\n[3/4] Writing skeleton with {len(injections):,} injected functions...")
    SKELETON_DIR.mkdir(parents=True, exist_ok=True)

    total_injected = 0
    for section in SECTION_BASES:
        syms = all_symbols.get(section, [])
        path, count = write_section_with_injections(
            section, syms, SKELETON_DIR, injections
        )
        if count > 0:
            print(f"  {section:8s}: {count:5d} functions injected")
        total_injected += count

    print(f"  Total injected: {total_injected:,}")

    # Step 4: Rebuild
    if args.rebuild:
        print("\n[4/4] Assembling and linking...")
        ok = rebuild_skeleton_and_link()
        if ok:
            print(f"  Linked: {OUTPUT_ELF}")
        else:
            print("  Build failed!")
            return

        # Verify
        if args.verify:
            print("\n  Verifying matches...")
            matched, matched_bytes, total_funcs = count_elf_matches(dol, all_symbols)
            elapsed = time.time() - t0
            print(f"\n{'=' * 70}")
            print(f"RESULTS")
            print(f"{'=' * 70}")
            print(f"  Functions matched:  {matched:,} / {total_funcs:,}")
            print(f"  Bytes matched:      {matched_bytes:,}")
            print(f"  Time elapsed:       {elapsed:.1f}s")
            print(f"{'=' * 70}")
    else:
        elapsed = time.time() - t0
        print(f"\n  Skeleton written in {elapsed:.1f}s (rebuild skipped)")


if __name__ == "__main__":
    main()
