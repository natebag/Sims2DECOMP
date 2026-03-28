#!/usr/bin/env python3
"""
Sims 2 GameCube — SN Systems Map → decomp-toolkit Converter

Converts an SN Systems ProDG linker map file into decomp-toolkit's
symbols.txt and splits.txt formats.

Usage:
    python sn_map_to_dtk.py <map_file> <out_dir> [--stats]
"""

import re
import argparse
from pathlib import Path
from collections import defaultdict


# Sections that contain code
CODE_SECTIONS = {'.init', '.text'}
# Sections that contain read-only data
RODATA_SECTIONS = {'.rodata', '.ctors', '.dtors', '.sdata2', '.sbss2'}
# Sections that contain read-write data
DATA_SECTIONS = {'.data', '.sdata'}
# Sections that contain uninitialized data
BSS_SECTIONS = {'.bss', '.sbss'}
# Sections to skip (debug, metadata)
SKIP_SECTIONS = {
    '.comment', '.stab', '.stabstr', '.debug', '.line',
    '.debug_srcinfo', '.debug_sfnames', '.debug_aranges',
    '.debug_pubnames', '.debug_info', '.debug_abbrev',
    '.debug_line', '.debug_frame', '.debug_str', '.debug_loc',
    '.debug_macinfo', '.debug_weaknames', '.debug_funcnames',
    '.debug_typenames', '.debug_varnames',
    '.got2', '.fixup', '.got', '.got.plt', '.plt',
}

# Sections in link order for splits.txt header
SECTION_ORDER = [
    '.init', '.text', '.ctors', '.dtors', '.rodata',
    '.data', '.bss', '.sdata', '.sbss', '.sdata2', '.sbss2',
]

# Map SN Systems section names to dtk's auto-detected DOL section names.
# dtk names data sections .data2-.data6 since it can't identify SN Systems sections.
# Mapping derived from DOL section addresses:
#   D0 (0x803CA900) = .ctors+.dtors -> dtk .data2
#   D1 (0x803CAD20) = .rodata       -> dtk .data3
#   D2 (0x804235E0) = .data         -> dtk .data4
#   D3 (0x804FD920) = .sdata        -> dtk .data5
#   D4 (0x80500600) = .sdata2       -> dtk .data6
DTK_SECTION_MAP = {
    '.init':   '.init',
    '.text':   '.text',
    '.ctors':  '.data2',
    '.dtors':  '.data2',
    '.rodata': '.data3',
    '.data':   '.data4',
    '.bss':    '.bss',
    '.sdata':  '.data5',
    '.sbss':   '.sbss',
    '.sdata2': '.data6',
    '.sbss2':  '.sbss2',
}

# dtk section order (matching splits.txt header)
DTK_SECTION_ORDER = [
    '.init', '.text', '.data2', '.data3', '.data4',
    '.bss', '.data5', '.sbss', '.data6',
]


def get_section_type(name):
    if name in CODE_SECTIONS:
        return 'code'
    if name in RODATA_SECTIONS:
        return 'rodata'
    if name in DATA_SECTIONS:
        return 'data'
    if name in BSS_SECTIONS:
        return 'bss'
    return None


def parse_sn_map(map_path):
    """Parse SN Systems linker map into structured data."""
    symbols = []          # (address, size, name, section, obj_file)
    obj_files = []        # (address, size, obj_path, section)
    sections_info = {}    # section_name -> (address, size, align)

    with open(map_path, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    current_section = None
    current_obj = None

    # Pattern captures: addr, size, align, whitespace-before-name, name
    # The whitespace length determines the hierarchy level:
    #   1 space  = level 0 (section header)
    #   9 spaces = level 1 (input section)
    #  17 spaces = level 2 (object file)
    #  25 spaces = level 3 (symbol name)
    line_pattern = re.compile(
        r'^([0-9a-fA-F]{8}) ([0-9a-fA-F]{8})\s+(\d+)(\s+)(\S.*)'
    )

    for line in lines:
        line = line.rstrip()
        if not line or line.startswith('=') or line == 'UNDEFINED':
            continue

        # Skip undefined symbol lines (heavily indented, no hex prefix)
        if line.startswith('                                                '):
            continue

        match = line_pattern.match(line)
        if not match:
            continue

        addr = int(match.group(1), 16)
        size = int(match.group(2), 16)
        # Align values in SN Systems maps are hex (e.g., 10=16, 20=32)
        align = int(match.group(3), 16)
        indent_spaces = len(match.group(4))
        name = match.group(5).strip()

        # Classify by indentation level
        level = (indent_spaces - 1) // 8  # 0=section, 1=input, 2=obj, 3=symbol

        if level == 0:
            # Section header
            sec_name = name.split()[0]
            if sec_name not in SKIP_SECTIONS:
                current_section = sec_name
                if sec_name not in sections_info:
                    sections_info[sec_name] = (addr, size, align)
            else:
                current_section = None
            current_obj = None

        elif level == 1:
            # Input section marker or <default> -- skip
            current_obj = None

        elif level == 2 and current_section:
            # Object file path
            current_obj = name
            if addr > 0 and size > 0:
                obj_files.append((addr, size, name, current_section))

        elif level >= 3 and current_section:
            # Symbol name
            if addr > 0:
                symbols.append((addr, size, name, current_section, current_obj))

    return symbols, obj_files, sections_info


def normalize_obj_name(obj_path):
    """Convert an object file path to a short source file name for splits.txt."""
    # e.g., "c:\BuildAgent\...\appmain.obj" -> "appmain"
    # e.g., "C:\Program Files\SN Systems\ngc\lib\libsn.a(crt0.o)" -> "libsn/crt0"
    # e.g., "lib.a(D:\Dolphin\src\Foo.o)" -> "libname/Foo"

    name = obj_path.replace('\\', '/')

    # Handle archive members: lib.a(member.o)
    archive_match = re.search(r'([^/]+)\.a\(([^)]+)\)', name)
    if archive_match:
        lib = archive_match.group(1)
        member = archive_match.group(2).replace('\\', '/')
        # Extract just the filename from the member path (may contain drive letters)
        member_basename = member.split('/')[-1]
        # Remove .o/.obj extension
        member_basename = re.sub(r'\.(o|obj)$', '', member_basename)
        return f'{lib}/{member_basename}'

    # Handle regular object files
    basename = name.split('/')[-1]
    basename = re.sub(r'\.(o|obj)$', '', basename)
    return basename


def sanitize_symbol_name(name):
    """Convert a demangled C++ symbol name to a valid dtk identifier.

    dtk's symbols.txt parser cannot handle spaces, parentheses, angle brackets,
    or other special characters in symbol names. We sanitize by replacing them
    with underscores while keeping names readable and unique.
    """
    # Handle {anonymous} namespace
    name = name.replace('{anonymous}', '_anonymous_')

    # Replace C++ operators before general replacement
    name = name.replace('operator==', 'op_eq_eq')
    name = name.replace('operator!=', 'op_neq')
    name = name.replace('operator<=', 'op_lte')
    name = name.replace('operator>=', 'op_gte')
    name = name.replace('operator<<', 'op_shl')
    name = name.replace('operator>>', 'op_shr')
    name = name.replace('operator+=', 'op_add_eq')
    name = name.replace('operator-=', 'op_sub_eq')
    name = name.replace('operator*=', 'op_mul_eq')
    name = name.replace('operator/=', 'op_div_eq')
    name = name.replace('operator[]', 'op_index')
    name = name.replace('operator()', 'op_call')
    name = name.replace('operator->', 'op_arrow')
    name = name.replace('operator new', 'op_new')
    name = name.replace('operator delete', 'op_delete')
    name = name.replace('operator=', 'op_assign')
    name = name.replace('operator+', 'op_add')
    name = name.replace('operator-', 'op_sub')
    name = name.replace('operator*', 'op_mul')
    name = name.replace('operator/', 'op_div')
    name = name.replace('operator<', 'op_lt')
    name = name.replace('operator>', 'op_gt')
    name = name.replace('operator!', 'op_not')

    # Replace C++ scope and type modifiers
    name = name.replace('::', '__')
    name = name.replace(' &', '_ref')
    name = name.replace(' *', '_ptr')
    name = name.replace('*', 'p')
    name = name.replace('&', 'r')
    name = name.replace('<', '_L_')
    name = name.replace('>', '_R_')
    name = name.replace(',', '_')
    name = name.replace('(', '_')
    name = name.replace(')', '_')
    name = name.replace(' ', '_')
    name = name.replace('...', 'varargs')
    name = name.replace('.', '_')
    name = name.replace('~', 'dtor_')
    name = name.replace('=', '_eq_')
    name = name.replace('+', '_plus_')
    name = name.replace('-', '_minus_')
    name = name.replace('/', '_div_')
    name = name.replace('[', '_')
    name = name.replace(']', '_')
    name = name.replace(';', '_')
    name = name.replace('"', '_')
    name = name.replace("'", '_')

    # Collapse runs of 3+ underscores down to 2 (keep __ for C++ scope)
    name = re.sub(r'_{3,}', '__', name)

    # Remove trailing underscores
    name = name.rstrip('_')

    return name


def determine_symbol_type(name, section, size):
    """Determine if a symbol is a function or object."""
    if section in CODE_SECTIONS:
        return 'function'
    return 'object'


def determine_data_type(section, size):
    """Guess data type from section and size for symbols.txt."""
    if section in CODE_SECTIONS:
        return None
    if size == 1:
        return 'byte'
    if size == 2:
        return '2byte'
    if size == 4:
        return '4byte'
    if size == 8:
        return '8byte'
    return None


def write_symbols_txt(symbols, sections_info, out_path, name_map_path=None):
    """Write symbols in dtk symbols.txt format."""
    count = 0
    used_names = {}  # sanitized_name -> count (for dedup)
    name_mapping = []  # (sanitized, original, addr) for mapping file

    with open(out_path, 'w', encoding='utf-8') as f:
        f.write(f'// Sims 2 GameCube - symbols extracted from SN Systems map\n')
        f.write(f'// Total: {len(symbols)} symbols\n\n')

        for addr, size, name, section, obj_file in symbols:
            if addr == 0 or section not in sections_info:
                continue

            # Map SN section name to dtk section name
            dtk_section = DTK_SECTION_MAP.get(section)
            if not dtk_section:
                continue

            sym_type = determine_symbol_type(name, section, size)

            # Sanitize name for dtk
            safe_name = sanitize_symbol_name(name)
            if not safe_name:
                safe_name = f'sym_{addr:08X}'

            # Deduplicate
            if safe_name in used_names:
                used_names[safe_name] += 1
                safe_name = f'{safe_name}_{used_names[safe_name]}'
            else:
                used_names[safe_name] = 0

            # Build attributes
            attrs = [f'type:{sym_type}']
            if size > 0:
                attrs.append(f'size:0x{size:X}')
            attrs.append('scope:global')

            data_type = determine_data_type(section, size)
            if data_type:
                attrs.append(f'data:{data_type}')

            attr_str = ' '.join(attrs)
            f.write(f'{safe_name} = {dtk_section}:0x{addr:08X}; // {attr_str}\n')
            name_mapping.append((safe_name, name, addr))
            count += 1

    # Write name mapping file (sanitized -> original demangled name)
    if name_map_path:
        with open(name_map_path, 'w', encoding='utf-8') as f:
            f.write('// Symbol name mapping: sanitized_name -> original demangled name\n')
            f.write('// Use this to recover original C++ names from dtk identifiers\n\n')
            for safe, orig, addr in name_mapping:
                if safe != orig:
                    f.write(f'0x{addr:08X}  {safe}  =  {orig}\n')

    return count


def write_splits_txt(obj_files, sections_info, out_path):
    """Write file splits in dtk splits.txt format using dtk section names."""
    # Build a mapping of obj_name -> {dtk_section -> [(start, end)]}
    obj_sections = defaultdict(lambda: defaultdict(list))

    for addr, size, obj_path, section in obj_files:
        if addr == 0 or size == 0:
            continue
        dtk_section = DTK_SECTION_MAP.get(section)
        if not dtk_section:
            continue
        obj_name = normalize_obj_name(obj_path)
        end = addr + size
        obj_sections[obj_name][dtk_section].append((addr, end))

    with open(out_path, 'w', encoding='utf-8') as f:
        f.write('// Sims 2 GameCube - splits from SN Systems map\n\n')

        # Write section headers using dtk's auto-detected names and types
        f.write('Sections:\n')
        dtk_sections_meta = {
            '.init':  ('code', 4),
            '.text':  ('code', 4),
            '.data2': ('data', 4),
            '.data3': ('data', 4),
            '.data4': ('data', 4),
            '.bss':   ('bss', 4),
            '.data5': ('data', 16),
            '.sbss':  ('bss', 4),
            '.data6': ('data', 32),
        }
        for sec_name in DTK_SECTION_ORDER:
            if sec_name in dtk_sections_meta:
                sec_type, align = dtk_sections_meta[sec_name]
                f.write(f'\t{sec_name:<12s} type:{sec_type} align:{align}\n')
        f.write('\n')

        # Write splits per object file, ordered by first address
        sorted_objs = sorted(
            obj_sections.items(),
            key=lambda x: min(
                min(spans, key=lambda s: s[0])[0]
                for spans in x[1].values()
            )
        )

        for obj_name, sec_spans in sorted_objs:
            f.write(f'{obj_name}:\n')
            for sec_name in DTK_SECTION_ORDER:
                if sec_name in sec_spans:
                    spans = sorted(sec_spans[sec_name])
                    for start, end in spans:
                        f.write(f'\t{sec_name:<12s} start:0x{start:08X} end:0x{end:08X}\n')
            f.write('\n')

    return len(sorted_objs)


def print_stats(symbols, obj_files, sections_info):
    """Print summary statistics."""
    print(f"\n{'='*60}")
    print(f"  SN Systems Map -> dtk Converter")
    print(f"{'='*60}")
    print(f"  Total symbols:    {len(symbols):,}")
    print(f"  Object files:     {len(obj_files):,}")
    print(f"  Sections:         {len(sections_info)}")

    # Count by section
    sec_counts = defaultdict(int)
    for _, _, _, section, _ in symbols:
        sec_counts[section] += 1

    print(f"\n  Symbols per section:")
    for sec_name in SECTION_ORDER:
        if sec_name in sec_counts:
            print(f"    {sec_name:<12s}  {sec_counts[sec_name]:,}")

    # Function count
    funcs = [s for s in symbols if s[3] in CODE_SECTIONS and s[0] > 0]
    total_code = sum(s[1] for s in funcs)
    print(f"\n  Functions:        {len(funcs):,}")
    print(f"  Total code bytes: {total_code:,} ({total_code/1024/1024:.2f} MB)")

    print(f"\n  Sections:")
    for sec_name in SECTION_ORDER:
        if sec_name in sections_info:
            addr, size, align = sections_info[sec_name]
            print(f"    {sec_name:<12s}  0x{addr:08X}  size: 0x{size:X} ({size:,} bytes)  align: {align}")

    print()


def main():
    parser = argparse.ArgumentParser(
        description='Convert SN Systems map to decomp-toolkit format'
    )
    parser.add_argument('map_file', help='Path to SN Systems .map file')
    parser.add_argument('out_dir', help='Output directory for symbols.txt and splits.txt')
    parser.add_argument('--stats', '-s', action='store_true', help='Print statistics')
    args = parser.parse_args()

    out_dir = Path(args.out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    print(f"Parsing {args.map_file}...")
    symbols, obj_files, sections_info = parse_sn_map(args.map_file)

    if args.stats:
        print_stats(symbols, obj_files, sections_info)

    sym_path = out_dir / 'symbols.txt'
    name_map_path = out_dir / 'symbol_names.txt'
    sym_count = write_symbols_txt(symbols, sections_info, sym_path, name_map_path)
    print(f"Wrote {sym_count:,} symbols to {sym_path}")
    print(f"Wrote name mapping to {name_map_path}")

    split_path = out_dir / 'splits.txt'
    split_count = write_splits_txt(obj_files, sections_info, split_path)
    print(f"Wrote {split_count:,} object file splits to {split_path}")


if __name__ == '__main__':
    main()
