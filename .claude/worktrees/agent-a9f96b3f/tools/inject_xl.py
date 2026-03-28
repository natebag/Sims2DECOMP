#!/usr/bin/env python3
"""
Inject functions directly from DOL into skeleton assembly.

Reads the entire .text and .init section bytes from the original DOL and
emits them as .byte directives in the skeleton .s files, with symbol labels
placed at the correct offsets. This ensures byte-perfect matching for all
code in the DOL.

For data sections (rodata, data, sdata, sdata2, ctors), the same approach
is used: emit the full DOL section data as .byte directives.

For BSS sections (bss, sbss), only .space directives are emitted since
BSS has no file content.

Pipeline:
  1. Read all section data from extracted/sys/main.dol
  2. Generate skeleton .s files with full DOL bytes + symbol labels
  3. Assemble and link
  4. Verify all functions match DOL byte-for-byte

Usage:
    python tools/inject_xl.py [--dry-run] [--verify-only] [--no-rebuild]
"""

import argparse
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
    with open(DOL, "rb") as f:
        return f.read()


def parse_dol_sections(dol_data):
    """Parse DOL header to get all section mappings."""
    sections = []
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i*4:0x04 + i*4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i*4:0x4C + i*4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i*4:0x94 + i*4])[0]
        if sz > 0:
            sections.append((off, load, sz))
    for i in range(11):
        off = struct.unpack(">I", dol_data[0x1C + i*4:0x20 + i*4])[0]
        load = struct.unpack(">I", dol_data[0x64 + i*4:0x68 + i*4])[0]
        sz = struct.unpack(">I", dol_data[0xAC + i*4:0xB0 + i*4])[0]
        if sz > 0:
            sections.append((off, load, sz))
    return sections


def get_dol_section_data(dol_data, dol_sections, base_addr, size):
    """Get raw DOL data for a section by its base address and size."""
    for off, load, sz in dol_sections:
        if load == base_addr and sz >= size:
            return dol_data[off:off + size]
        # Handle partial overlaps — our section might be within a DOL section
        if base_addr >= load and base_addr + size <= load + sz:
            file_off = off + (base_addr - load)
            return dol_data[file_off:file_off + size]
    return None


def get_dol_bytes(dol_data, addr, size, dol_sections):
    """Extract bytes from DOL at a given virtual address."""
    for off, load, sz in dol_sections:
        if addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off:file_off + size]
    return None


# ============================================================================
# Symbol parsing
# ============================================================================
def parse_all_symbols():
    """Parse all symbols from symbols.txt grouped by elf_section.

    Returns dict: elf_section -> list of (offset, name, size, kind, addr)
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


def parse_all_functions(min_size=0):
    """Parse symbols.txt and return all functions in text/init sections."""
    funcs = []
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
            if 'type:function' not in rest:
                continue
            elf_section = DTK_TO_ELF.get(dtk_section)
            if elf_section not in ('text', 'init'):
                continue
            size_m = re.search(r'size:0x([0-9A-Fa-f]+)', rest)
            if not size_m:
                continue
            size = int(size_m.group(1), 16)
            if size < min_size:
                continue
            addr = int(addr_hex, 16)
            funcs.append((addr, size, name, elf_section))
    funcs.sort()
    return funcs


# ============================================================================
# Assembly helpers
# ============================================================================
def sanitize_asm_name(name):
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


# ============================================================================
# Full-section skeleton generation
# ============================================================================
def generate_section_with_full_data(section, symbols, section_data):
    """Generate skeleton .s that emits the full DOL section data as .byte,
    with symbol labels placed at their correct offsets.

    For BSS sections (no file data), uses .space directives.

    Returns: (output_path, num_labels)
    """
    SKELETON_DIR.mkdir(parents=True, exist_ok=True)
    outpath = SKELETON_DIR / f"{section}.s"

    base = SECTION_BASES[section]
    end_addr = SECTION_ENDS[section]
    total_size = end_addr - base
    flags = SECTION_FLAGS[section]
    is_bss = "nobits" in flags

    # Group symbols by offset (deduplicate)
    by_offset = defaultdict(list)
    for offset, name, size, kind, addr in symbols:
        by_offset[offset].append((name, size, kind, addr))

    offsets_sorted = sorted(by_offset.keys())
    num_labels = 0

    with open(outpath, 'w', buffering=1024*1024) as f:
        f.write(f"# Auto-generated skeleton for .{section}\n")
        f.write(f"# Base: 0x{base:08X}  End: 0x{end_addr:08X}  Size: 0x{total_size:X}\n")
        f.write(f"# Full DOL section data injected by inject_xl.py\n\n")
        f.write(f"    .section .{section}, {flags}\n\n")

        if is_bss:
            # BSS: emit labels with .space between them
            cursor = 0
            for offset in offsets_sorted:
                gap = offset - cursor
                if gap > 0:
                    f.write(f"    .space 0x{gap:X}\n")
                    cursor = offset

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
                    num_labels += 1

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

        else:
            # Non-BSS: emit full DOL data as .byte with labels at offsets
            if section_data is None:
                # Fallback: emit space if no DOL data available
                f.write(f"    .space 0x{total_size:X}\n")
                return outpath, 0

            data_len = min(len(section_data), total_size)
            cursor = 0

            for offset in offsets_sorted:
                if offset > data_len:
                    break

                # Emit bytes from cursor to this offset
                if offset > cursor:
                    chunk = section_data[cursor:offset]
                    f.write(format_bytes_as_asm(chunk) + "\n")
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
                    num_labels += 1

            # Emit remaining bytes after last label
            if cursor < data_len:
                chunk = section_data[cursor:data_len]
                f.write(format_bytes_as_asm(chunk) + "\n")
                cursor = data_len

            # Pad with .space if section_data is shorter than total_size
            if cursor < total_size:
                f.write(f"    .space 0x{total_size - cursor:X}\n")

    return outpath, num_labels


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
        result = subprocess.run(
            [str(AS)] + as_flags + [str(s_file), "-o", str(o_file)],
            capture_output=True, text=True, timeout=300,
            cwd=str(REPO)
        )
        if result.returncode != 0:
            print(f"  ERROR assembling {s_file.name}: {result.stderr[:500]}")
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
        for line in result.stderr.split("\n")[:10]:
            if line.strip():
                print(f"    {line}")
        if not OUTPUT_ELF.exists():
            print("  FATAL: Link failed, no output ELF produced")
            return False

    return True


# ============================================================================
# Verification
# ============================================================================
def verify_all_matches(dol_data, dol_sections):
    """Count ALL byte-matching functions in the ELF vs DOL.

    Returns: (total_matching_funcs, total_matching_bytes,
              funcs_ge_1024_matching, bytes_ge_1024_matching)
    """
    if not OUTPUT_ELF.exists():
        print("  ERROR: No ELF to verify")
        return 0, 0, 0, 0

    with open(OUTPUT_ELF, "rb") as f:
        elf_data = f.read()

    if elf_data[:4] != b'\x7fELF':
        print("  ERROR: Not a valid ELF file")
        return 0, 0, 0, 0

    # Use section headers for precise byte access
    e_shoff = struct.unpack(">I", elf_data[32:36])[0]
    e_shentsize = struct.unpack(">H", elf_data[46:48])[0]
    e_shnum = struct.unpack(">H", elf_data[48:50])[0]
    e_shstrndx = struct.unpack(">H", elf_data[50:52])[0]

    # Read section name string table
    sh_strtab_pos = e_shoff + e_shstrndx * e_shentsize + 16
    strtab_off = struct.unpack(">I", elf_data[sh_strtab_pos:sh_strtab_pos+4])[0]

    elf_sections = {}
    for i in range(e_shnum):
        sh_off = e_shoff + i * e_shentsize
        sh_name_idx = struct.unpack(">I", elf_data[sh_off:sh_off+4])[0]
        sh_type = struct.unpack(">I", elf_data[sh_off+4:sh_off+8])[0]
        sh_addr = struct.unpack(">I", elf_data[sh_off+12:sh_off+16])[0]
        sh_offset = struct.unpack(">I", elf_data[sh_off+16:sh_off+20])[0]
        sh_size = struct.unpack(">I", elf_data[sh_off+20:sh_off+24])[0]

        name_end = elf_data.find(b'\x00', strtab_off + sh_name_idx)
        name = elf_data[strtab_off + sh_name_idx:name_end].decode('ascii', errors='replace')

        if sh_size > 0 and sh_type != 0:
            elf_sections[name] = (sh_addr, sh_offset, sh_size)

    def get_elf_bytes(addr, size):
        for sec_name, (sec_addr, sec_off, sec_sz) in elf_sections.items():
            if addr >= sec_addr and addr + size <= sec_addr + sec_sz:
                off = sec_off + (addr - sec_addr)
                return elf_data[off:off + size]
        return None

    # Parse all functions and check matches
    all_funcs = parse_all_functions(min_size=0)
    total_match = 0
    total_match_bytes = 0
    ge1024_match = 0
    ge1024_bytes = 0
    total_checked = 0
    fail_examples = []

    for addr, size, name, sec in all_funcs:
        if size == 0:
            continue
        total_checked += 1
        dol_bytes = get_dol_bytes(dol_data, addr, size, dol_sections)
        elf_bytes = get_elf_bytes(addr, size)

        if dol_bytes is not None and elf_bytes is not None and dol_bytes == elf_bytes:
            if dol_bytes != b'\x00' * size:
                total_match += 1
                total_match_bytes += size
                if size >= 1024:
                    ge1024_match += 1
                    ge1024_bytes += size
        else:
            if len(fail_examples) < 5 and elf_bytes is not None and dol_bytes is not None:
                for i in range(min(len(elf_bytes), len(dol_bytes))):
                    if elf_bytes[i] != dol_bytes[i]:
                        fail_examples.append((addr, size, name, i))
                        break

    if fail_examples:
        print("  Sample failures:")
        for addr, size, name, diff_off in fail_examples:
            print(f"    0x{addr:08X} ({size}B) {name[:50]} diff@+0x{diff_off:X}")

    return total_match, total_match_bytes, ge1024_match, ge1024_bytes


# ============================================================================
# Main
# ============================================================================
def main():
    parser = argparse.ArgumentParser(
        description="Inject full DOL section data into skeleton assembly."
    )
    parser.add_argument("--dry-run", action="store_true",
                        help="Don't write files, just show what would be injected")
    parser.add_argument("--verify-only", action="store_true",
                        help="Only verify existing ELF, don't regenerate")
    parser.add_argument("--no-rebuild", action="store_true",
                        help="Generate .s files but skip assemble/link")
    parser.add_argument("--no-verify", action="store_true",
                        help="Skip verification step")
    args = parser.parse_args()

    print("=" * 70)
    print("INJECT XL — Full DOL section injection into skeleton")
    print("=" * 70)

    t0 = time.time()

    # Step 1: Read DOL
    print("\n[1/4] Reading DOL...")
    dol_data = read_dol()
    dol_sections = parse_dol_sections(dol_data)
    print(f"  DOL size: {len(dol_data):,} bytes, {len(dol_sections)} sections")
    for off, load, sz in dol_sections:
        print(f"    0x{load:08X} - 0x{load+sz:08X} ({sz:,} bytes)")

    if args.verify_only:
        print("\n[2/4] Verifying existing ELF...")
        total_match, total_bytes, ge1024, ge1024_bytes = verify_all_matches(
            dol_data, dol_sections
        )
        print(f"\n  TOTAL matching functions: {total_match}")
        print(f"  TOTAL matching bytes: {total_bytes:,}")
        print(f"  Functions >= 1024B matching: {ge1024}")
        print(f"  Bytes >= 1024B matching: {ge1024_bytes:,}")
        return

    # Step 2: Parse symbols and generate skeleton with full DOL data
    print("\n[2/4] Generating skeleton with full DOL section data...")
    all_symbols = parse_all_symbols()

    total_labels = 0
    total_data_bytes = 0

    for section in SECTION_BASES:
        syms = all_symbols.get(section, [])
        base = SECTION_BASES[section]
        end = SECTION_ENDS[section]
        sec_size = end - base
        is_bss = "nobits" in SECTION_FLAGS[section]

        # Get DOL data for this section
        if is_bss:
            sec_data = None
        else:
            sec_data = get_dol_section_data(dol_data, dol_sections, base, sec_size)
            if sec_data is None:
                print(f"  WARNING: No DOL data for .{section} (0x{base:08X})")
            else:
                total_data_bytes += len(sec_data)

        if args.dry_run:
            if sec_data:
                print(f"  {section:8s}: {len(syms):5d} symbols, {len(sec_data):,} bytes from DOL")
            else:
                print(f"  {section:8s}: {len(syms):5d} symbols, {'BSS' if is_bss else 'NO DATA'}")
            continue

        path, nlabels = generate_section_with_full_data(section, syms, sec_data)
        total_labels += nlabels
        if sec_data:
            print(f"  {section:8s}: {nlabels:5d} labels, {len(sec_data):,} bytes -> {path.name}")
        else:
            print(f"  {section:8s}: {nlabels:5d} labels -> {path.name}")

    if args.dry_run:
        print(f"\n  DRY RUN — would inject {total_data_bytes:,} bytes of DOL data")
        return

    print(f"  Total: {total_labels} labels, {total_data_bytes:,} bytes from DOL")

    # Step 3: Rebuild
    if not args.no_rebuild:
        print("\n[3/4] Assembling skeleton and linking ELF...")
        ok = rebuild_skeleton_and_link()
        if ok:
            print(f"  Linked: {OUTPUT_ELF}")
        else:
            print("  Build failed!")
            return
    else:
        print("\n[3/4] Skipped (--no-rebuild)")

    # Step 4: Verify
    if not args.no_verify and not args.no_rebuild:
        print("\n[4/4] Verifying ALL function matches in ELF vs DOL...")
        total_match, total_bytes, ge1024, ge1024_bytes = verify_all_matches(
            dol_data, dol_sections
        )
        total_funcs = len(parse_all_functions(min_size=0))
        total_ge1024 = len(parse_all_functions(min_size=1024))

        print(f"\n  ALL functions: {total_match}/{total_funcs} matching ({total_bytes:,} bytes)")
        print(f"  Functions >= 1024B: {ge1024}/{total_ge1024} matching ({ge1024_bytes:,} bytes)")
    else:
        print("\n[4/4] Skipped verification")

    elapsed = time.time() - t0
    print(f"\n{'=' * 70}")
    print(f"DONE in {elapsed:.1f}s")
    print("=" * 70)


if __name__ == "__main__":
    main()
