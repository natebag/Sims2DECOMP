#!/usr/bin/env python3
"""
Find missing functions not in asm_decomp.

This script:
1. Parses config/symbols.txt to get all function addresses + names
2. Extracts addresses from src/asm_decomp/*.cpp files
3. Extracts addresses from src/matched/agent/*.cpp files
4. Cross-references to find functions that are missing (no asm_decomp, not matched)
5. Reports findings by size categories
"""

import re
import os
from pathlib import Path
from collections import defaultdict

def parse_symbols_file(filepath):
    """Parse symbols.txt to get all function addresses, names, and sizes."""
    functions = []
    pattern = r'(\S+)\s*=\s*\S+:0x([0-9A-Fa-f]+);\s*//\s*type:function\s*size:0x([0-9A-Fa-f]+)'
    
    with open(filepath, 'r') as f:
        for line in f:
            match = re.search(pattern, line)
            if match:
                name = match.group(1)
                addr = int(match.group(2), 16)
                size = int(match.group(3), 16)
                functions.append({
                    'name': name,
                    'addr': addr,
                    'size': size
                })
    return functions

def extract_asm_decomp_addresses(directory):
    """Extract function addresses from asm_decomp .cpp files."""
    addresses = set()
    pattern = r'//\s*0x([0-9A-Fa-f]+)\s*\(\d+\s*bytes\)'
    
    for filepath in Path(directory).glob('*.cpp'):
        with open(filepath, 'r') as f:
            content = f.read()
            for match in re.finditer(pattern, content):
                addr = int(match.group(1), 16)
                addresses.add(addr)
    
    return addresses

def extract_matched_addresses(directory):
    """Extract function addresses from matched .cpp files."""
    addresses = set()
    # Pattern for filenames like match_0x802DF544_EBitArray_ctor.cpp or match_802DF544_...
    pattern = r'match_0x([0-9A-Fa-f]{8})|match_([0-9A-Fa-f]{8})'
    
    for filepath in Path(directory).glob('*.cpp'):
        match = re.search(pattern, filepath.name)
        if match:
            addr_str = match.group(1) if match.group(1) else match.group(2)
            addr = int(addr_str, 16)
            addresses.add(addr)
    
    return addresses

def categorize_by_size(size):
    """Categorize function by size."""
    if size <= 32:
        return 'tiny (<=32B)'
    elif size <= 64:
        return 'small (33-64B)'
    elif size <= 128:
        return 'medium (65-128B)'
    elif size <= 256:
        return 'large (129-256B)'
    else:
        return 'huge (>256B)'

def main():
    print("Finding missing functions...")
    print()
    
    # Parse all functions from symbols.txt
    print("Parsing symbols.txt...")
    all_functions = parse_symbols_file('config/symbols.txt')
    print(f"  Total functions: {len(all_functions)}")
    
    # Extract addresses from asm_decomp
    print("Extracting asm_decomp addresses...")
    asm_decomp_addrs = extract_asm_decomp_addresses('src/asm_decomp')
    print(f"  Functions in asm_decomp: {len(asm_decomp_addrs)}")
    
    # Extract addresses from matched
    print("Extracting matched addresses...")
    matched_addrs = extract_matched_addresses('src/matched')
    print(f"  Functions matched: {len(matched_addrs)}")
    
    # Find missing functions
    print()
    print("Cross-referencing...")
    
    missing_functions = []
    covered_functions = []
    
    for func in all_functions:
        addr = func['addr']
        in_asm_decomp = addr in asm_decomp_addrs
        is_matched = addr in matched_addrs
        
        if in_asm_decomp or is_matched:
            covered_functions.append({
                **func,
                'in_asm_decomp': in_asm_decomp,
                'is_matched': is_matched
            })
        else:
            missing_functions.append(func)
    
    print(f"  Covered (asm_decomp OR matched): {len(covered_functions)}")
    print(f"  Missing (not in asm_decomp AND not matched): {len(missing_functions)}")
    print()
    
    # Categorize missing functions by size
    size_categories = defaultdict(list)
    for func in missing_functions:
        cat = categorize_by_size(func['size'])
        size_categories[cat].append(func)
    
    print("=" * 60)
    print("MISSING FUNCTIONS BY SIZE:")
    print("=" * 60)
    
    for cat in ['tiny (<=32B)', 'small (33-64B)', 'medium (65-128B)', 'large (129-256B)', 'huge (>256B)']:
        funcs = size_categories[cat]
        print(f"\n{cat}: {len(funcs)} functions")
        
        # Show first 10 examples for small and medium categories
        if cat in ['small (33-64B)', 'medium (65-128B)'] and funcs:
            print("  Examples (first 10):")
            for func in sorted(funcs, key=lambda x: x['size'])[:10]:
                print(f"    0x{func['addr']:08X} ({func['size']:4d}B) - {func['name'][:60]}")
    
    # Find patterns in missing function names
    print()
    print("=" * 60)
    print("MISSING FUNCTIONS BY CLASS/SYSTEM (top 20):")
    print("=" * 60)
    
    class_counts = defaultdict(int)
    for func in missing_functions:
        name = func['name']
        # Extract class name (part before :: or first __)
        if '__' in name:
            class_name = name.split('__')[0]
        elif '::' in name:
            class_name = name.split('::')[0]
        else:
            class_name = name.split('_')[0] if '_' in name else name[:20]
        class_counts[class_name] += 1
    
    for class_name, count in sorted(class_counts.items(), key=lambda x: -x[1])[:20]:
        print(f"  {class_name}: {count} functions")
    
    # Summary of low-hanging fruit (small functions)
    print()
    print("=" * 60)
    print("LOW-HANGING FRUIT (<=64 bytes, likely simple):")
    print("=" * 60)
    
    small_missing = [f for f in missing_functions if f['size'] <= 64]
    print(f"Total small missing functions: {len(small_missing)}")
    print()
    print("First 20 smallest:")
    for func in sorted(small_missing, key=lambda x: x['size'])[:20]:
        print(f"  0x{func['addr']:08X} ({func['size']:3d}B) - {func['name'][:70]}")
    
    # Save full list to file
    output_file = 'missing_functions_report.txt'
    with open(output_file, 'w') as f:
        f.write("MISSING FUNCTIONS REPORT\n")
        f.write("=" * 80 + "\n\n")
        f.write(f"Total functions in symbols.txt: {len(all_functions)}\n")
        f.write(f"Functions in asm_decomp: {len(asm_decomp_addrs)}\n")
        f.write(f"Functions matched: {len(matched_addrs)}\n")
        f.write(f"Missing functions: {len(missing_functions)}\n\n")
        
        f.write("ALL MISSING FUNCTIONS (sorted by size):\n")
        f.write("-" * 80 + "\n")
        for func in sorted(missing_functions, key=lambda x: (x['size'], x['addr'])):
            f.write(f"0x{func['addr']:08X}  {func['size']:5d}B  {func['name']}\n")
    
    print()
    print(f"Full report saved to: {output_file}")

if __name__ == '__main__':
    main()
