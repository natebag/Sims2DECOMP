#!/usr/bin/env python3
"""
TU Completion Ranking Tool v2
Ranks Translation Units by completion percentage for Phase 3 targeting.
Uses DVD map file to estimate total function counts per TU.
"""

import os
import re
from collections import defaultdict
from pathlib import Path

def parse_map_for_tus(map_path):
    """Parse DVD map to get TU sizes (function counts)."""
    tu_info = {}  # tu_name -> {'total_bytes': int, 'function_count': int}
    current_tu = None
    
    with open(map_path, 'r', encoding='utf-8', errors='ignore') as f:
        for line in f:
            line = line.strip()
            
            # Look for .obj paths which indicate TU boundaries
            obj_match = re.search(r'u2_ngc_release_dvd[\\/]([^\\]+)\.obj', line, re.IGNORECASE)
            if obj_match:
                current_tu = obj_match.group(1).lower()
                if current_tu not in tu_info:
                    tu_info[current_tu] = {'total_bytes': 0, 'function_count': 0}
                continue
            
            # Skip non-function lines
            if not current_tu:
                continue
                
            # Parse function entries (Address Size Align ... Symbol)
            parts = line.split()
            if len(parts) >= 7 and parts[0].startswith('8') and len(parts[0]) == 8:
                try:
                    size = int(parts[1], 16)
                    if size > 0 and size < 0x10000:  # Sanity check
                        tu_info[current_tu]['total_bytes'] += size
                        tu_info[current_tu]['function_count'] += 1
                except:
                    pass
    
    return tu_info

def count_matched_per_tu(matched_dir):
    """Count matched files per TU directory."""
    tu_counts = {}
    
    for tu_dir in os.listdir(matched_dir):
        tu_path = os.path.join(matched_dir, tu_dir)
        if os.path.isdir(tu_path):
            cpp_files = list(Path(tu_path).glob('*.cpp'))
            tu_counts[tu_dir.lower()] = len(cpp_files)
    
    return tu_counts

def normalize_tu_name(name):
    """Normalize TU name for comparison."""
    name = name.lower().replace('_', '').replace('-', '')
    return name

def find_tu_matches(map_tus, matched_tus):
    """Match map TUs to matched directory TUs."""
    results = []
    
    for map_tu, info in map_tus.items():
        matched_count = 0
        
        # Try exact match
        if map_tu in matched_tus:
            matched_count = matched_tus[map_tu]
        else:
            # Try normalized match
            norm_map = normalize_tu_name(map_tu)
            for matched_tu, count in matched_tus.items():
                if normalize_tu_name(matched_tu) == norm_map:
                    matched_count = count
                    break
        
        total_funcs = info['function_count']
        if total_funcs > 0:
            completion = (matched_count / total_funcs) * 100
        else:
            completion = 0
        
        remaining = total_funcs - matched_count
        
        results.append({
            'tu': map_tu,
            'matched': matched_count,
            'total': total_funcs,
            'completion': completion,
            'remaining': remaining,
            'bytes': info['total_bytes']
        })
    
    return results

def main():
    matched_dir = 'src/matched'
    map_file = 'extracted/files/u2_ngc_release_dvd.map'
    
    print("=" * 70)
    print("TU COMPLETION RANKING (post-dedup)")
    print("=" * 70)
    print()
    
    # Parse map file for TU info
    print("Parsing DVD map file...")
    map_tus = parse_map_for_tus(map_file)
    print(f"Found {len(map_tus)} TUs in map file")
    print()
    
    # Count matched files
    print("Counting matched files...")
    matched_tus = count_matched_per_tu(matched_dir)
    print(f"Found {len(matched_tus)} TU directories")
    print()
    
    # Calculate completion
    results = find_tu_matches(map_tus, matched_tus)
    
    # Filter out TUs with 0 functions or unrealistic counts
    results = [r for r in results if r['total'] > 0 and r['total'] < 1000]
    
    # Sort: first by remaining functions (ascending), then by completion (descending), then by total (ascending)
    results.sort(key=lambda x: (x['remaining'], -x['completion'], x['total']))
    
    # Print header
    print(f"{'Rank':<5} {'TU Name':<30} {'Matched':<8} {'Total':<8} {'%':<6} {'Remaining':<10}")
    print("-" * 70)
    
    # Print top 30
    near_complete = []
    for i, r in enumerate(results[:30], 1):
        print(f"{i:<5} {r['tu']:<30} {r['matched']:<8} {r['total']:<8} {r['completion']:<5.1f} {r['remaining']:<10}")
        if r['remaining'] <= 3 and r['remaining'] > 0:
            near_complete.append(r)
    
    print()
    print("=" * 70)
    print("NEAR-COMPLETE TUs (1-3 functions remaining)")
    print("=" * 70)
    print()
    
    if near_complete:
        print(f"{'TU Name':<30} {'Matched':<8} {'Total':<8} {'Remaining':<10}")
        print("-" * 60)
        for r in near_complete:
            print(f"{r['tu']:<30} {r['matched']:<8} {r['total']:<8} {r['remaining']:<10}")
    else:
        print("No TUs found with exactly 1-3 functions remaining.")
    
    # Print high completion TUs (90%+)
    high_completion = [r for r in results if r['completion'] >= 90 and r['remaining'] > 0]
    print()
    print("=" * 70)
    print(f"HIGH COMPLETION TUs (90%+, {len(high_completion)} TUs)")
    print("=" * 70)
    print()
    
    if high_completion:
        print(f"{'TU Name':<30} {'Matched':<8} {'Total':<8} {'%':<6} {'Remaining':<10}")
        print("-" * 60)
        for r in high_completion[:20]:
            print(f"{r['tu']:<30} {r['matched']:<8} {r['total']:<8} {r['completion']:<5.1f} {r['remaining']:<10}")
    
    print()
    print("=" * 70)
    print("SUMMARY")
    print("=" * 70)
    print(f"Total TUs analyzed: {len(results)}")
    print(f"TUs with 100% completion: {len([r for r in results if r['remaining'] == 0])}")
    print(f"TUs with 90-99% completion: {len([r for r in results if r['completion'] >= 90 and r['remaining'] > 0])}")
    print(f"TUs with 1-3 remaining: {len(near_complete)}")
    print(f"Total matched functions: {sum(r['matched'] for r in results)}")
    print(f"Total functions in map: {sum(r['total'] for r in results)}")
    print(f"Overall completion: {sum(r['matched'] for r in results) / sum(r['total'] for r in results) * 100:.1f}%")

if __name__ == '__main__':
    main()
