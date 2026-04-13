#!/usr/bin/env python3
"""
TU Completion Ranking Tool v3
Ranks Translation Units by completion percentage for Phase 3 targeting.
Handles agent/ catch-all directory properly.
"""

import os
import re
from collections import defaultdict
from pathlib import Path

def extract_addr_from_file(filepath):
    """Extract address from match file header."""
    try:
        with open(filepath, 'r') as f:
            first_line = f.readline().strip()
            # Match patterns like // 0x80012345 or // 0X80012345
            addr_match = re.search(r'0[xX]([0-9a-fA-F]{8})', first_line)
            if addr_match:
                return int(addr_match.group(1), 16)
    except:
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
            if len(parts) >= 7 and parts[0].startswith('8') and len(parts[0]) == 8:
                try:
                    addr = int(parts[0], 16)
                    addr_to_tu[addr] = current_tu
                except:
                    pass
    
    return addr_to_tu

def count_matched_by_tu(matched_dir, addr_to_tu):
    """Count matched files per TU using address mapping."""
    tu_counts = defaultdict(int)
    unmatched = 0
    
    for root, dirs, files in os.walk(matched_dir):
        for file in files:
            if not file.endswith('.cpp'):
                continue
            
            filepath = os.path.join(root, file)
            addr = extract_addr_from_file(filepath)
            
            if addr and addr in addr_to_tu:
                tu = addr_to_tu[addr]
                tu_counts[tu] += 1
            else:
                unmatched += 1
    
    return tu_counts, unmatched

def count_total_per_tu(addr_to_tu):
    """Count total functions per TU from map."""
    tu_totals = defaultdict(int)
    for addr, tu in addr_to_tu.items():
        tu_totals[tu] += 1
    return tu_totals

def main():
    matched_dir = 'src/matched'
    map_file = 'extracted/files/u2_ngc_release_dvd.map'
    
    print("=" * 70)
    print("TU COMPLETION RANKING (post-dedup)")
    print("=" * 70)
    print()
    
    # Parse map file
    print("Parsing DVD map file for address -> TU mapping...")
    addr_to_tu = parse_map_for_addresses(map_file)
    print(f"Found {len(addr_to_tu)} function addresses in map file")
    print()
    
    # Count total functions per TU
    tu_totals = count_total_per_tu(addr_to_tu)
    print(f"Found {len(tu_totals)} unique TUs in map file")
    print()
    
    # Count matched files per TU
    print("Counting matched files per TU...")
    tu_matched, unmatched = count_matched_by_tu(matched_dir, addr_to_tu)
    print(f"Matched files mapped to TUs: {sum(tu_matched.values())}")
    print(f"Unmatched files (no address or no TU mapping): {unmatched}")
    print()
    
    # Calculate completion
    results = []
    for tu, total in tu_totals.items():
        matched = tu_matched.get(tu, 0)
        completion = (matched / total * 100) if total > 0 else 0
        remaining = total - matched
        
        results.append({
            'tu': tu,
            'matched': matched,
            'total': total,
            'completion': completion,
            'remaining': remaining
        })
    
    # Sort: first by remaining functions (ascending), then by completion (descending), then by total (ascending)
    results.sort(key=lambda x: (x['remaining'], -x['completion'], x['total']))
    
    # Print header
    print(f"{'Rank':<5} {'TU Name':<35} {'Matched':<8} {'Total':<8} {'%':<6} {'Remaining':<10}")
    print("-" * 75)
    
    # Print top 40
    near_complete = []
    for i, r in enumerate(results[:40], 1):
        marker = ""
        if r['remaining'] == 0:
            marker = " [DONE]"
        elif r['remaining'] <= 3:
            marker = " [NEAR]"
            near_complete.append(r)
        
        print(f"{i:<5} {r['tu']:<35} {r['matched']:<8} {r['total']:<8} {r['completion']:<5.1f}{marker}")
    
    print()
    print("=" * 70)
    print("NEAR-COMPLETE TUs (1-3 functions remaining)")
    print("=" * 70)
    print()
    
    if near_complete:
        print(f"{'TU Name':<35} {'Matched':<8} {'Total':<8} {'Remaining':<10}")
        print("-" * 65)
        for r in sorted(near_complete, key=lambda x: x['remaining']):
            print(f"{r['tu']:<35} {r['matched']:<8} {r['total']:<8} {r['remaining']:<10}")
    else:
        print("No TUs found with 1-3 functions remaining.")
    
    # Print 100% complete TUs
    complete = [r for r in results if r['remaining'] == 0 and r['total'] > 0]
    print()
    print("=" * 70)
    print(f"100% COMPLETE TUs ({len(complete)} TUs)")
    print("=" * 70)
    print()
    
    if complete:
        print(f"{'TU Name':<35} {'Matched':<8} {'Total':<8}")
        print("-" * 55)
        for r in sorted(complete, key=lambda x: -x['total'])[:20]:
            print(f"{r['tu']:<35} {r['matched']:<8} {r['total']:<8}")
        if len(complete) > 20:
            print(f"... and {len(complete) - 20} more")
    
    # Print high completion TUs (90%+ but not 100%)
    high_completion = [r for r in results if 90 <= r['completion'] < 100 and r['total'] > 0]
    print()
    print("=" * 70)
    print(f"HIGH COMPLETION TUs (90-99%, {len(high_completion)} TUs)")
    print("=" * 70)
    print()
    
    if high_completion:
        print(f"{'TU Name':<35} {'Matched':<8} {'Total':<8} {'%':<6} {'Remaining':<10}")
        print("-" * 65)
        for r in sorted(high_completion, key=lambda x: -x['completion'])[:15]:
            print(f"{r['tu']:<35} {r['matched']:<8} {r['total']:<8} {r['completion']:<5.1f} {r['remaining']:<10}")
    
    print()
    print("=" * 70)
    print("SUMMARY")
    print("=" * 70)
    print(f"Total TUs: {len(results)}")
    print(f"TUs with 100% completion: {len(complete)}")
    print(f"TUs with 90-99% completion: {len(high_completion)}")
    print(f"TUs with 1-3 remaining: {len(near_complete)}")
    print(f"Total matched functions: {sum(r['matched'] for r in results)}")
    print(f"Total functions in map: {sum(r['total'] for r in results)}")
    print(f"Overall completion: {sum(r['matched'] for r in results) / sum(r['total'] for r in results) * 100:.2f}%")

if __name__ == '__main__':
    main()
