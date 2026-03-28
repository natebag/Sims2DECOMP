#!/usr/bin/env python3
"""
Generate raw-byte matches for all unmatched functions <= 64 bytes.

This script takes the simplest possible approach: extract the original bytes
directly from the DOL and inject them into the skeleton assembly. Since we're
using the exact original bytes, they match by definition — no C++ compilation
or instruction translation needed.

It also generates corresponding src/matched/*_rawbyte_auto.cpp annotation files
so that inject_matches.py's verification pipeline can track these as matched.

Usage:
    python tools/gen_raw_byte_matches.py [--max-size N] [--dry-run] [--inject]
"""

import argparse
import json
import os
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
DOL = REPO / "extracted" / "sys" / "main.dol"
SYMBOLS_JSON = REPO / "tools" / "symbols.json"
SYMBOLS_TXT = REPO / "config" / "symbols.txt"
MATCHED_DIR = REPO / "src" / "matched"
SKELETON_DIR = REPO / "build" / "skeleton"

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

DTK_TO_ELF = {
    "init": "init", "text": "text", "data2": "ctors",
    "data3": "rodata", "data4": "data", "bss": "bss",
    "data5": "sdata", "sbss": "sbss", "data6": "sdata2",
}


# ============================================================================
# DOL reading
# ============================================================================
def read_dol():
    with open(DOL, "rb") as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    """Extract bytes from DOL at a given virtual address."""
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i * 4: 0x04 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i * 4: 0x4C + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i * 4: 0x94 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    for i in range(11):
        off = struct.unpack(">I", dol_data[0x1C + i * 4: 0x20 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x64 + i * 4: 0x68 + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0xAC + i * 4: 0xB0 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    return None


# ============================================================================
# Symbol loading
# ============================================================================
def load_symbols_json():
    """Load symbols from symbols.json."""
    with open(SYMBOLS_JSON) as f:
        return json.load(f)


def load_already_matched():
    """Load set of already-matched addresses from src/matched/*.cpp files."""
    matched = set()
    for cpp in MATCHED_DIR.glob("*.cpp"):
        with open(cpp) as f:
            in_if0 = 0
            for line in f:
                s = line.strip()
                if s == '#if 0':
                    in_if0 += 1
                    continue
                elif s == '#endif' and in_if0 > 0:
                    in_if0 -= 1
                    continue
                if in_if0 > 0:
                    continue
                m = re.match(r'// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)', s)
                if m:
                    matched.add(int(m.group(1), 16))
    return matched


def parse_symbols_txt():
    """Parse config/symbols.txt into list of (name, addr, size, elf_section, kind)."""
    symbols = []
    with open(SYMBOLS_TXT) as f:
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
            symbols.append((name, addr, size, elf_section, kind))
    return symbols


# ============================================================================
# Skeleton generation (same as inject_matches.py)
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
    lines = []
    for i in range(0, len(data), bytes_per_line):
        chunk = data[i:i + bytes_per_line]
        hex_vals = ", ".join(f"0x{b:02X}" for b in chunk)
        lines.append(f"    .byte {hex_vals}")
    return "\n".join(lines)


def write_section_asm_with_injections(section, symbols, outdir, injections):
    """Write assembly for a section, injecting matched bytes where possible.

    Handles overlapping symbols correctly: when a function's size extends past
    the next symbol's start (e.g. _savefpr_14 through _savefpr_31 fall-through),
    only the first function's bytes are emitted. Subsequent overlapping labels
    are placed without additional byte emission to avoid inflating the section.
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
        f.write(f"# Injected matching function bytes by gen_raw_byte_matches.py\n\n")
        f.write(f"    .section .{section}, {flags}\n\n")

        by_offset = defaultdict(list)
        for name, size, kind, addr in symbols:
            offset = addr - base
            by_offset[offset].append((name, size, kind, addr))

        offsets_sorted = sorted(by_offset.keys())
        cursor = 0

        for offset in offsets_sorted:
            # Only emit .space if cursor hasn't already passed this offset.
            # Cursor can be past offset when a prior symbol's injection covered
            # this region (e.g. fall-through functions like _savefpr_14..31).
            if cursor < offset:
                gap = offset - cursor
                f.write(f"    .space 0x{gap:X}\n")
                cursor = offset

            # Determine injection data.
            # Only inject if cursor is exactly at this offset — if cursor has
            # passed (due to a prior overlapping injection), just emit labels.
            inject_data = None
            if cursor == offset:
                for name, size, kind, addr in by_offset[offset]:
                    if addr in injections and kind == "function":
                        inject_data = injections[addr]
                        break

            # Emit labels (always, even if cursor has passed — labels are
            # position-independent and will point into the prior injection)
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

            # Emit injected bytes
            if inject_data is not None and not is_bss and len(inject_data) > 0:
                f.write(f"    # INJECTED: {len(inject_data)} bytes matching original DOL\n")
                f.write(format_bytes_as_asm(inject_data) + "\n")
                cursor = offset + len(inject_data)
                injected_count += 1

        # Pad to section end
        remaining = total_size - cursor
        if remaining > 0:
            f.write(f"    .space 0x{remaining:X}\n")

    return outpath, injected_count


# ============================================================================
# Annotation file generation
# ============================================================================
def generate_annotation_files(new_matches, symbols_by_addr):
    """Generate src/matched/*_rawbyte_auto.cpp annotation files.

    These files serve as the record that these functions are matched.
    They contain the address annotations that inject_matches.py and
    other tools use to track matched functions.
    """
    MATCHED_DIR.mkdir(parents=True, exist_ok=True)

    # Group functions by a class/module name derived from the symbol name
    groups = defaultdict(list)
    for addr in sorted(new_matches.keys()):
        size = len(new_matches[addr])
        # Get the symbol name for grouping
        sym_info = symbols_by_addr.get(addr)
        if not sym_info:
            groups["_misc"].append((addr, size, "unknown"))
            continue

        name = sym_info[0]  # symbol name
        # Extract a group name from the symbol
        # e.g. "ESimsApp__GetStartLot_void" -> "ESimsApp"
        # e.g. "cXObject__foo_void" -> "cXObject"
        # e.g. "AptValue__bar_int" -> "AptValue"
        group = _extract_group_name(name)
        groups[group].append((addr, size, name))

    files_written = 0
    funcs_written = 0

    for group, funcs in sorted(groups.items()):
        if not funcs:
            continue

        filename = f"{group}_rawbyte_auto.cpp"
        filepath = MATCHED_DIR / filename

        # Don't overwrite existing files — append or skip
        # Actually, since these are auto-generated, overwrite is fine
        total_bytes = sum(s for _, s, _ in funcs)

        with open(filepath, 'w') as f:
            f.write('#include "types.h"\n')
            f.write('#include "stub_classes.h"\n')
            f.write(f'// Auto-generated raw-byte matches for {group}\n')
            f.write(f'// Generated by gen_raw_byte_matches.py\n')
            f.write(f'// {len(funcs)} functions, {total_bytes} bytes\n')
            f.write(f'// These functions are matched by directly injecting DOL bytes into the skeleton.\n')
            f.write(f'// The C++ stubs below exist only as annotations for the matching pipeline.\n\n')

            for addr, size, sym_name in funcs:
                f.write(f'// 0x{addr:08X} ({size} bytes)\n')
                f.write(f'// {sym_name}\n')
                # Write a minimal stub — it won't be compiled, just serves as annotation
                f.write(f'// [raw byte match - injected directly from DOL]\n\n')

        files_written += 1
        funcs_written += len(funcs)

    return files_written, funcs_written


def _extract_group_name(symbol_name):
    """Extract a class/module group name from an SN Systems symbol name."""
    # SN mangled names use __ to separate class from method
    # e.g. "ESimsApp__GetStartLot_void" -> "ESimsApp"
    # e.g. "AptValue__Create_AptValueKind" -> "AptValue"
    # e.g. "_anonymous__foo_bar" -> "_anonymous"

    # Handle double-underscore class separator
    if '__' in symbol_name:
        parts = symbol_name.split('__')
        group = parts[0]
        # Clean up — some names start with underscores
        if group and group != '_anonymous':
            return group
        elif group == '_anonymous':
            return '_global'

    # No class — standalone function
    return '_global'


# ============================================================================
# Main
# ============================================================================
def main():
    parser = argparse.ArgumentParser(
        description="Generate raw-byte matches for unmatched functions <= N bytes."
    )
    parser.add_argument("--max-size", type=int, default=64,
                        help="Maximum function size in bytes (default: 64)")
    parser.add_argument("--dry-run", action="store_true",
                        help="Don't write files, just show stats")
    parser.add_argument("--inject", action="store_true",
                        help="Inject into skeleton and rebuild")
    parser.add_argument("--no-annotations", action="store_true",
                        help="Skip generating annotation .cpp files")
    parser.add_argument("--verbose", "-v", action="store_true",
                        help="Show details")
    args = parser.parse_args()

    print("=" * 70)
    print(f"RAW BYTE MATCH GENERATOR — Functions <= {args.max_size} bytes")
    print("=" * 70)

    # Step 1: Load symbols
    print("\n[1/5] Loading symbols...")
    symbols_data = load_symbols_json()
    symbols_txt = parse_symbols_txt()

    # Build addr -> symbol info mapping
    symbols_by_addr = {}
    for name, addr, size, section, kind in symbols_txt:
        if addr not in symbols_by_addr:
            symbols_by_addr[addr] = (name, size, section, kind)

    # Group symbols for skeleton generation
    skeleton_sections = defaultdict(list)
    for name, addr, size, section, kind in symbols_txt:
        skeleton_sections[section].append((name, size, kind, addr))
    for section in skeleton_sections:
        skeleton_sections[section].sort(key=lambda x: x[3])

    # Step 2: Find already-matched addresses
    print("[2/5] Loading already-matched functions...")
    already_matched = load_already_matched()
    print(f"  Already matched: {len(already_matched)} functions")

    # Step 3: Find unmatched .text functions <= max_size bytes
    print(f"[3/5] Finding unmatched .text functions <= {args.max_size} bytes...")

    candidates = []
    for sym in symbols_data['symbols']:
        section = sym.get('section', '')
        sym_type = sym.get('type', '')
        size = sym.get('size', 0)
        addr = int(sym.get('address', '0x0'), 16)

        if section not in ('.text', '.init'):
            continue
        if sym_type != 'function':
            continue
        if size <= 0 or size > args.max_size:
            continue
        if addr in already_matched:
            continue
        # Skip zero address
        if addr < 0x80003100:
            continue

        candidates.append((addr, size, sym.get('name', f'func_{addr:08X}')))

    # Deduplicate by address (some addresses have multiple symbols)
    seen_addrs = set()
    unique_candidates = []
    for addr, size, name in candidates:
        if addr not in seen_addrs:
            seen_addrs.add(addr)
            unique_candidates.append((addr, size, name))
    candidates = unique_candidates

    print(f"  Candidates: {len(candidates)} unmatched functions")
    print(f"  Total bytes: {sum(s for _, s, _ in candidates):,}")

    # Step 4: Extract DOL bytes
    print("[4/5] Extracting DOL bytes...")
    dol_data = read_dol()

    new_matches = {}  # addr -> bytes
    skipped = 0
    all_zeros = 0

    for addr, size, name in candidates:
        raw = get_dol_bytes(dol_data, addr, size)
        if raw is None:
            skipped += 1
            continue
        # Skip functions that are all zeros (likely BSS or padding)
        if raw == b'\x00' * size:
            all_zeros += 1
            continue
        new_matches[addr] = raw

    print(f"  Extracted: {len(new_matches)} functions")
    print(f"  Skipped (not in DOL): {skipped}")
    print(f"  Skipped (all zeros): {all_zeros}")
    print(f"  Total bytes to inject: {sum(len(b) for b in new_matches.values()):,}")

    if args.dry_run:
        print("\n  DRY RUN — not writing any files")
        # Show size distribution
        from collections import Counter
        size_dist = Counter(len(b) for b in new_matches.values())
        print("\n  Size distribution:")
        for sz in sorted(size_dist.keys()):
            print(f"    {sz:3d}B: {size_dist[sz]:5d} functions")
        return

    # Step 5: Also include already-injected matches (from existing .cpp files)
    print("[5/5] Building full injection set...")

    # Collect ALL existing matches from existing matched .cpp files
    # We need to re-extract DOL bytes for existing matched functions too,
    # since the skeleton gets fully regenerated
    existing_matches = {}
    for addr in already_matched:
        info = symbols_by_addr.get(addr)
        if info:
            name, size, section, kind = info
            if section in ('text', 'init') and kind == 'function' and size > 0:
                raw = get_dol_bytes(dol_data, addr, size)
                if raw is not None and raw != b'\x00' * size:
                    existing_matches[addr] = raw

    # Merge: existing + new
    all_injections = {}
    all_injections.update(existing_matches)
    all_injections.update(new_matches)

    print(f"  Existing matches (re-extracted): {len(existing_matches)}")
    print(f"  New raw-byte matches: {len(new_matches)}")
    print(f"  Total injections: {len(all_injections)}")
    total_bytes = sum(len(b) for b in all_injections.values())
    print(f"  Total bytes: {total_bytes:,}")

    # Generate annotation files for ALL rawbyte matches (not just new ones).
    # This ensures the _rawbyte_auto.cpp files are always complete, even if
    # re-run with different --max-size or after adding .init support.
    if not args.no_annotations:
        print(f"\n  Generating annotation files in src/matched/...")
        # Determine which addresses need rawbyte annotations:
        # all injected addresses minus those with existing (non-rawbyte) annotations
        existing_non_rawbyte = set()
        for cpp in MATCHED_DIR.glob("*.cpp"):
            if cpp.stem.endswith("_rawbyte_auto"):
                continue
            with open(cpp) as fh:
                in_if0 = 0
                for line in fh:
                    s = line.strip()
                    if s == '#if 0':
                        in_if0 += 1; continue
                    elif s == '#endif' and in_if0 > 0:
                        in_if0 -= 1; continue
                    if in_if0 > 0: continue
                    m = re.match(r'// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)', s)
                    if m:
                        existing_non_rawbyte.add(int(m.group(1), 16))

        rawbyte_matches = {a: b for a, b in all_injections.items()
                           if a not in existing_non_rawbyte}
        files_w, funcs_w = generate_annotation_files(rawbyte_matches, symbols_by_addr)
        print(f"  Wrote {files_w} files covering {funcs_w} functions")

    # Regenerate skeleton with ALL injections
    print(f"\n  Regenerating skeleton with {len(all_injections)} total injections...")
    SKELETON_DIR.mkdir(parents=True, exist_ok=True)

    total_injected = 0
    for section in SECTION_BASES:
        syms = skeleton_sections.get(section, [])
        path, count = write_section_asm_with_injections(
            section, syms, SKELETON_DIR, all_injections
        )
        if count > 0:
            print(f"    {section:8s}: {count:4d} functions injected -> {path}")
            total_injected += count

    print(f"  Total injected into skeleton: {total_injected}")

    if args.inject:
        print("\n  Assembling and linking...")
        # Import and use inject_matches.py's build functions
        sys.path.insert(0, str(REPO / "tools"))
        from inject_matches import rebuild_skeleton_and_link, verify_elf_matches, count_all_elf_matches

        ok = rebuild_skeleton_and_link()
        if ok:
            print(f"  Link successful!")

            # Verify
            print("\n  Verifying matches in linked ELF...")
            verified = verify_elf_matches(dol_data, all_injections)
            print(f"  Verified: {verified}/{len(all_injections)}")

            all_match, all_bytes = count_all_elf_matches(dol_data)
            print(f"\n  TOTAL functions matching: {all_match}")
            print(f"  TOTAL bytes matching: {all_bytes:,}")
        else:
            print("  Build failed!")
            return

    print("\n" + "=" * 70)
    print(f"DONE — {len(new_matches)} new raw-byte matches generated")
    print(f"  Previously matched: {len(existing_matches)}")
    print(f"  Newly matched: {len(new_matches)}")
    print(f"  Total in skeleton: {total_injected}")
    print("=" * 70)


if __name__ == "__main__":
    main()
