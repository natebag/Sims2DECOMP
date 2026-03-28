#!/usr/bin/env python3
"""
Sims 2 GameCube — Symbol Map Parser

Parses u2_ngc_release.map and u2_ngc_debug.map into structured data.
Outputs JSON with all symbols, addresses, sizes, source files, and sections.

Usage:
    python map_parser.py <map_file> [--output symbols.json] [--stats]
"""

import re
import json
import argparse
from pathlib import Path
from collections import defaultdict


def parse_map_file(map_path: str) -> dict:
    """Parse a CodeWarrior/SN Systems map file into structured data."""
    symbols = []
    sections = []
    source_files = set()
    current_section = None

    with open(map_path, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    # Patterns
    # Symbol line: "80003100 00000368     1                 path/to/file.a(source.cpp.obj)"
    symbol_pattern = re.compile(
        r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+(\d+)\s+(.+)$'
    )
    # Section line: "800034c0 00942954    10 .text"
    section_pattern = re.compile(
        r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+(\d+)\s+(\.\w+)\s*$'
    )
    # Function name line: "80003804 000006a4     0                         FunctionName(...)"
    func_pattern = re.compile(
        r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+(\d+)\s+(\S.+)$'
    )
    # Source file in path
    source_pattern = re.compile(r'([^(]+\.(?:cpp|c))')
    # Object file with full path
    obj_path_pattern = re.compile(r'((?:[A-Za-z]:\\|/).+?\.(?:obj|o|a\(.+?\)))')

    # Undefined symbols section
    undefined_pattern = re.compile(r'^\s+(\S+\.\S+)\s*$')

    in_undefined = False
    undefined_symbols = []

    for line in lines:
        line = line.rstrip()

        # Track sections
        if line.strip() == 'UNDEFINED':
            in_undefined = True
            continue

        if in_undefined:
            if line.strip() == '' or line.startswith('='):
                if line.startswith('='):
                    in_undefined = False
                continue
            match = undefined_pattern.match(line)
            if match:
                undefined_symbols.append(match.group(1).strip())
                continue

        # Section headers
        sec_match = section_pattern.match(line)
        if sec_match:
            addr = int(sec_match.group(1), 16)
            size = int(sec_match.group(2), 16)
            align = int(sec_match.group(3))
            name = sec_match.group(4)
            current_section = name
            sections.append({
                'name': name,
                'address': f'0x{addr:08X}',
                'size': size,
                'align': align
            })
            continue

        # Symbol/function entries
        sym_match = symbol_pattern.match(line)
        if sym_match:
            addr = int(sym_match.group(1), 16)
            size = int(sym_match.group(2), 16)
            align = int(sym_match.group(3))
            rest = sym_match.group(4).strip()

            # Determine if this is a source file reference or a function name
            source_file = None
            symbol_name = None

            if rest.startswith('c:\\') or rest.startswith('C:\\') or rest.startswith('/'):
                # This is a source file / object reference
                source_file = rest
                src_match = source_pattern.search(rest)
                if src_match:
                    source_files.add(src_match.group(1))
            else:
                # This is a function/symbol name
                symbol_name = rest

            entry = {
                'address': f'0x{addr:08X}',
                'address_int': addr,
                'size': size,
                'align': align,
                'section': current_section,
            }

            if source_file:
                entry['source_file'] = source_file
                entry['type'] = 'object'
            if symbol_name:
                entry['name'] = symbol_name
                entry['type'] = 'function'

            symbols.append(entry)

    # Extract unique source files
    cpp_files = sorted(source_files)

    return {
        'total_symbols': len(symbols),
        'total_functions': sum(1 for s in symbols if s.get('type') == 'function'),
        'total_objects': sum(1 for s in symbols if s.get('type') == 'object'),
        'total_undefined': len(undefined_symbols),
        'sections': sections,
        'source_files': cpp_files,
        'undefined_symbols': undefined_symbols,
        'symbols': symbols,
    }


def print_stats(data: dict):
    """Print summary statistics."""
    print(f"\n{'='*60}")
    print(f"  Sims 2 GameCube — Symbol Map Analysis")
    print(f"{'='*60}")
    print(f"  Total entries:      {data['total_symbols']:,}")
    print(f"  Functions:          {data['total_functions']:,}")
    print(f"  Object files:       {data['total_objects']:,}")
    print(f"  Undefined symbols:  {data['total_undefined']:,}")
    print(f"  Source files:       {len(data['source_files'])}")
    print(f"{'='*60}")

    # Section breakdown
    print(f"\n  Sections:")
    for sec in data['sections']:
        print(f"    {sec['name']:12s}  {sec['address']}  size: {sec['size']:,} bytes")

    # Size distribution of functions
    functions = [s for s in data['symbols'] if s.get('type') == 'function' and s['size'] > 0]
    if functions:
        sizes = [f['size'] for f in functions]
        total_bytes = sum(sizes)
        print(f"\n  Function size stats:")
        print(f"    Total code bytes:  {total_bytes:,}")
        print(f"    Smallest:          {min(sizes):,} bytes")
        print(f"    Largest:           {max(sizes):,} bytes")
        print(f"    Average:           {total_bytes // len(sizes):,} bytes")
        print(f"    Median:            {sorted(sizes)[len(sizes)//2]:,} bytes")

    # Source files
    if data['source_files']:
        print(f"\n  Known source files ({len(data['source_files'])}):")
        for sf in data['source_files']:
            print(f"    {sf}")

    print()


def main():
    parser = argparse.ArgumentParser(description='Parse Sims 2 GC symbol map files')
    parser.add_argument('map_file', help='Path to .map file')
    parser.add_argument('--output', '-o', help='Output JSON file', default=None)
    parser.add_argument('--stats', '-s', action='store_true', help='Print statistics')
    args = parser.parse_args()

    data = parse_map_file(args.map_file)

    if args.stats:
        print_stats(data)

    if args.output:
        # Don't include address_int in output (it's for internal sorting)
        output_data = {k: v for k, v in data.items()}
        for sym in output_data['symbols']:
            sym.pop('address_int', None)

        with open(args.output, 'w') as f:
            json.dump(output_data, f, indent=2)
        print(f"Wrote {args.output}")
    elif not args.stats:
        # Default: print stats
        print_stats(data)


if __name__ == '__main__':
    main()
