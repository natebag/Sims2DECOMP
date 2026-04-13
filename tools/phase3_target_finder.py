#!/usr/bin/env python3
"""
Phase 3 Target Finder
Identifies exact missing functions for near-complete TUs.
"""

import os
import re
from collections import defaultdict
from pathlib import Path

def extract_addr_from_file(filepath):
    """Extract address from match file header."""
    try:
        with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
            first_line = f.readline().strip()
            addr_match = re.search(r'0[xX]([0-9a-fA-F]{8})', first_line)
            if addr_match:
                return int(addr_match.group(1), 16)
    except:
        pass
    return None

def get_matched_addresses(tu_dir):
    """Get set of matched addresses for a TU."""
    matched = set()
    tu_path = Path(tu_dir)
    if not tu_path.exists():
        return matched
    
    for file_path in tu_path.glob('*.cpp'):
        addr = extract_addr_from_file(file_path)
        if addr:
            matched.add(addr)
    return matched

def get_map_functions_for_tu(map_path, tu_name):
    """Get all functions for a TU from the DVD map."""
    functions = []  # list of (addr, size, name)
    current_tu = None
    
    with open(map_path, 'r', encoding='utf-8', errors='ignore') as f:
        for line in f:
            line = line.strip()
            
            # Check for TU boundary
            obj_match = re.search(r'u2_ngc_release_dvd[\\/]([^\\]+)\.obj', line, re.IGNORECASE)
            if obj_match:
                current_tu = obj_match.group(1).lower()
                continue
            
            if current_tu != tu_name:
                continue
            
            # Parse function entry
            parts = line.split()
            if len(parts) >= 7 and parts[0].startswith('8') and len(parts[0]) == 8:
                try:
                    addr = int(parts[0], 16)
                    size = int(parts[1], 16)
                    # Symbol name is the last part
                    name = parts[-1] if len(parts) > 6 else "unknown"
                    functions.append((addr, size, name))
                except:
                    pass
    
    return functions

def analyze_tu(tu_name, matched_dir, map_path):
    """Analyze a TU and find missing functions."""
    tu_dir = os.path.join(matched_dir, tu_name)
    matched_addrs = get_matched_addresses(tu_dir)
    map_funcs = get_map_functions_for_tu(map_path, tu_name)
    
    missing = []
    for addr, size, name in map_funcs:
        if addr not in matched_addrs:
            missing.append((addr, size, name))
    
    return {
        'tu': tu_name,
        'matched_count': len(matched_addrs),
        'total_count': len(map_funcs),
        'matched_addrs': matched_addrs,
        'missing': missing
    }

def main():
    matched_dir = 'src/matched'
    map_file = 'extracted/files/u2_ngc_release_dvd.map'
    
    # Top 6 near-complete TUs
    target_tus = [
        'treetab',
        'isiminstance', 
        'behaviortree',
        'e_ipointamblight',
        'e_ispotlight',
        'plumbbob'
    ]
    
    print("=" * 80)
    print("PHASE 3 TARGETS - MISSING FUNCTIONS ANALYSIS")
    print("=" * 80)
    print()
    
    all_targets = []
    
    for tu_name in target_tus:
        result = analyze_tu(tu_name, matched_dir, map_file)
        
        print(f"TU: {tu_name}")
        print(f"  Matched: {result['matched_count']}/{result['total_count']}")
        print(f"  Completion: {result['matched_count']/result['total_count']*100:.1f}%")
        print(f"  Missing: {len(result['missing'])} function(s)")
        print()
        
        if result['missing']:
            print("  MISSING FUNCTIONS:")
            for addr, size, name in result['missing']:
                print(f"    0x{addr:08X}  {size:4d}B  {name}")
                all_targets.append({
                    'tu': tu_name,
                    'addr': addr,
                    'size': size,
                    'name': name
                })
        print()
        print("-" * 60)
        print()
    
    # Print summary for easy copy-paste
    print()
    print("=" * 80)
    print("SUMMARY - MISSING FUNCTIONS FOR PHASE 3")
    print("=" * 80)
    print()
    
    for target in all_targets:
        print(f"{target['tu']:<20} 0x{target['addr']:08X}  {target['size']:4d}B  {target['name']}")

if __name__ == '__main__':
    main()
