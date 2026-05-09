#!/usr/bin/env python3
"""
Count matched functions across all src/matched/ directories.
Removes duplicates and provides accurate statistics.
"""

import os
import re
import json
from pathlib import Path
from collections import defaultdict

def extract_address(filename):
    """Extract hex address from filename."""
    # Match patterns like match_0x8003061C or match_8003061C
    match = re.search(r'match_(?:0x)?([0-9a-fA-F]{8})', filename)
    if match:
        return match.group(1).upper()
    return None

def count_matched_functions():
    """Count all matched functions and report duplicates."""
    matched_dir = Path('src/matched')
    
    # Track all files by address
    address_to_files = defaultdict(list)
    
    # Find all .cpp files in src/matched/
    for cpp_file in matched_dir.rglob('*.cpp'):
        addr = extract_address(cpp_file.name)
        if addr:
            address_to_files[addr].append(str(cpp_file))
    
    # Calculate statistics
    total_files = sum(len(files) for files in address_to_files.values())
    unique_addresses = len(address_to_files)
    duplicates = {addr: files for addr, files in address_to_files.items() if len(files) > 1}
    
    # Report
    print("=" * 70)
    print("MATCHED FUNCTIONS COUNT REPORT")
    print("=" * 70)
    print(f"\nTotal files: {total_files}")
    print(f"Unique addresses: {unique_addresses}")
    print(f"Duplicates: {len(duplicates)}")
    print(f"Duplicate files: {sum(len(f) - 1 for f in duplicates.values())}")
    
    if duplicates:
        print("\n" + "=" * 70)
        print("DUPLICATE ADDRESSES (need cleanup):")
        print("=" * 70)
        for addr, files in sorted(duplicates.items()):
            print(f"\n{addr}: {len(files)} files")
            for f in files:
                print(f"  - {f}")
    
    return {
        'total_files': total_files,
        'unique_addresses': unique_addresses,
        'duplicate_count': len(duplicates),
        'duplicates': duplicates
    }

if __name__ == '__main__':
    stats = count_matched_functions()
    
    # Save to JSON for other tools
    with open('matched_stats.json', 'w') as f:
        json.dump(stats, f, indent=2)
    print("\n\nStats saved to matched_stats.json")
