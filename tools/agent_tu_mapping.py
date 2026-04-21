#!/usr/bin/env python3
"""
Agent TU Mapping Tool
Maps files in src/matched/agent/ to their proper TUs by cross-referencing addresses.
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
            # Match patterns like // 0x80012345 or // 0X80012345
            addr_match = re.search(r'0[xX]([0-9a-fA-F]{8})', first_line)
            if addr_match:
                return int(addr_match.group(1), 16)
    except Exception as e:
        pass
    return None

def parse_map_for_addresses(map_path):
    """Parse DVD map to get address -> TU mapping."""
    addr_to_tu = {}  # address -> tu_name
    current_tu = None
    
    with open(map_path, 'r', encoding='utf-8', errors='ignore') as f:
        for line in f:
            line = line.strip()
            
            # Look for .obj paths which indicate TU boundaries
            obj_match = re.search(r'u2_ngc_release_dvd[\\/]([^\\]+)\.obj', line, re.IGNORECASE)
            if obj_match:
                current_tu = obj_match.group(1).lower()
                continue
            
            # Skip non-function lines
            if not current_tu:
                continue
                
            # Parse function entries (Address Size Align ... Symbol)
            parts = line.split()
            if len(parts) >= 4 and parts[0].startswith('8') and len(parts[0]) == 8:
                try:
                    addr = int(parts[0], 16)
                    addr_to_tu[addr] = current_tu
                except:
                    pass
    
    return addr_to_tu

def map_agent_files(agent_dir, addr_to_tu):
    """Map agent directory files to TUs."""
    tu_files = defaultdict(list)  # tu -> list of (filename, addr)
    unmapped = []
    
    agent_path = Path(agent_dir)
    if not agent_path.exists():
        return tu_files, unmapped
    
    for file_path in agent_path.glob('*.cpp'):
        addr = extract_addr_from_file(file_path)
        
        if addr is None:
            unmapped.append((file_path.name, 'no_address'))
        elif addr in addr_to_tu:
            tu = addr_to_tu[addr]
            tu_files[tu].append((file_path.name, addr))
        else:
            unmapped.append((file_path.name, f'0x{addr:08X}'))
    
    return tu_files, unmapped

def main():
    agent_dir = 'src/matched/agent'
    map_file = 'extracted/files/u2_ngc_release_dvd.map'
    
    print("=" * 70)
    print("AGENT TO TU MAPPING")
    print("=" * 70)
    print()
    
    # Parse map file
    print("Parsing DVD map file...")
    addr_to_tu = parse_map_for_addresses(map_file)
    print(f"Found {len(addr_to_tu)} function addresses in map file")
    print()
    
    # Map agent files
    print(f"Scanning {agent_dir}...")
    tu_files, unmapped = map_agent_files(agent_dir, addr_to_tu)
    
    total_mapped = sum(len(files) for files in tu_files.values())
    total_unmapped = len(unmapped)
    total_files = total_mapped + total_unmapped
    
    print(f"Total files in agent/: {total_files}")
    print(f"Successfully mapped: {total_mapped}")
    print(f"Unmapped: {total_unmapped}")
    print()
    
    # Sort TUs by file count (descending)
    sorted_tus = sorted(tu_files.items(), key=lambda x: len(x[1]), reverse=True)
    
    # Print top TUs
    print("=" * 70)
    print("TOP TUs BY AGENT FILE COUNT")
    print("=" * 70)
    print()
    print(f"{'Rank':<5} {'TU Name':<35} {'File Count':<12}")
    print("-" * 55)
    
    for i, (tu, files) in enumerate(sorted_tus[:50], 1):
        print(f"{i:<5} {tu:<35} {len(files):<12}")
    
    if len(sorted_tus) > 50:
        print(f"... and {len(sorted_tus) - 50} more TUs")
    
    # Print summary by file count buckets
    print()
    print("=" * 70)
    print("SUMMARY BY FILE COUNT")
    print("=" * 70)
    print()
    
    buckets = {
        '100+': 0,
        '50-99': 0,
        '20-49': 0,
        '10-19': 0,
        '5-9': 0,
        '2-4': 0,
        '1': 0
    }
    
    for tu, files in sorted_tus:
        count = len(files)
        if count >= 100:
            buckets['100+'] += 1
        elif count >= 50:
            buckets['50-99'] += 1
        elif count >= 20:
            buckets['20-49'] += 1
        elif count >= 10:
            buckets['10-19'] += 1
        elif count >= 5:
            buckets['5-9'] += 1
        elif count >= 2:
            buckets['2-4'] += 1
        else:
            buckets['1'] += 1
    
    for bucket, count in buckets.items():
        if count > 0:
            print(f"  {bucket} files: {count} TUs")
    
    # Unmapped sample
    if unmapped:
        print()
        print("=" * 70)
        print(f"UNMAPPED FILES (sample of 20)")
        print("=" * 70)
        print()
        for filename, reason in unmapped[:20]:
            print(f"  {filename}: {reason}")
        if len(unmapped) > 20:
            print(f"  ... and {len(unmapped) - 20} more")
    
    print()
    print("=" * 70)
    print("COMPLETE TU LIST (alphabetical)")
    print("=" * 70)
    print()
    
    for tu in sorted(tu_files.keys()):
        print(f"{tu}: {len(tu_files[tu])} files")

if __name__ == '__main__':
    main()
