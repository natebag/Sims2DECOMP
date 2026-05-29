#!/usr/bin/env python3
"""
TU Completion Ranking Tool
Ranks TUs by completion percentage, counting both TU-directory files and agent/ files.
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
    except Exception:
        pass
    return None

def parse_map_for_tu_counts(map_path):
    """Parse DVD map to get total function count per TU."""
    tu_total_funcs = defaultdict(int)
    current_tu = None
    
    with open(map_path, 'r', encoding='utf-8', errors='ignore') as f:
        for line in f:
            line = line.strip()
            
            obj_match = re.search(r'u2_ngc_release_dvd[\\/]([^\\]+)\.obj', line, re.IGNORECASE)
            if obj_match:
                current_tu = obj_match.group(1).lower()
                continue
            
            if not current_tu:
                continue
                
            parts = line.split()
            if len(parts) >= 4 and parts[0].startswith('8') and len(parts[0]) == 8:
                try:
                    int(parts[0], 16)
                    tu_total_funcs[current_tu] += 1
                except:
                    pass
    
    return tu_total_funcs

def count_tu_dir_files(matched_dir):
    """Count matched files per TU directory."""
    tu_dir_counts = {}
    matched_path = Path(matched_dir)
    
    for subdir in matched_path.iterdir():
        if subdir.is_dir() and subdir.name != 'agent':
            cpp_files = list(subdir.glob('*.cpp'))
            tu_dir_counts[subdir.name.lower()] = len(cpp_files)
    
    return tu_dir_counts

def map_agent_files(agent_dir, addr_to_tu):
    """Map agent directory files to TUs."""
    tu_agent_counts = defaultdict(int)
    
    agent_path = Path(agent_dir)
    if not agent_path.exists():
        return tu_agent_counts
    
    for file_path in agent_path.glob('*.cpp'):
        addr = extract_addr_from_file(file_path)
        if addr and addr in addr_to_tu:
            tu = addr_to_tu[addr]
            tu_agent_counts[tu] += 1
    
    return tu_agent_counts

def parse_map_for_addresses(map_path):
    """Parse DVD map to get address -> TU mapping."""
    addr_to_tu = {}
    current_tu = None
    
    with open(map_path, 'r', encoding='utf-8', errors='ignore') as f:
        for line in f:
            line = line.strip()
            obj_match = re.search(r'u2_ngc_release_dvd[\\/]([^\\]+)\.obj', line, re.IGNORECASE)
            if obj_match:
                current_tu = obj_match.group(1).lower()
                continue
            
            if not current_tu:
                continue
                
            parts = line.split()
            if len(parts) >= 4 and parts[0].startswith('8') and len(parts[0]) == 8:
                try:
                    addr = int(parts[0], 16)
                    addr_to_tu[addr] = current_tu
                except:
                    pass
    
    return addr_to_tu

def main():
    matched_dir = 'src/matched'
    agent_dir = 'src/matched/agent'
    map_file = 'extracted/files/u2_ngc_release_dvd.map'
    
    # Parse map
    addr_to_tu = parse_map_for_addresses(map_file)
    tu_total_funcs = parse_map_for_tu_counts(map_file)
    
    # Count TU dir files
    tu_dir_counts = count_tu_dir_files(matched_dir)
    
    # Count agent files mapped to TUs
    tu_agent_counts = map_agent_files(agent_dir, addr_to_tu)
    
    # Combine all TUs
    all_tus = set(tu_total_funcs.keys()) | set(tu_dir_counts.keys()) | set(tu_agent_counts.keys())
    
    rankings = []
    for tu in all_tus:
        total = tu_total_funcs.get(tu, 0)
        dir_count = tu_dir_counts.get(tu, 0)
        agent_count = tu_agent_counts.get(tu, 0)
        matched = dir_count + agent_count
        
        if total > 0:
            pct = (matched / total) * 100
        else:
            pct = 0.0
        
        remaining = total - matched
        rankings.append({
            'tu': tu,
            'total': total,
            'matched': matched,
            'dir_count': dir_count,
            'agent_count': agent_count,
            'remaining': remaining,
            'pct': pct
        })
    
    # Sort by completion percentage descending, then by total functions ascending
    rankings.sort(key=lambda x: (-x['pct'], x['total']))
    
    print("=" * 80)
    print("TU COMPLETION RANKING (post-dedup)")
    print("=" * 80)
    print()
    print(f"{'Rank':<5} {'TU Name':<30} {'Matched':<8} {'Total':<8} {'%':<8} {'Remaining':<10} {'Agent':<8}")
    print("-" * 80)
    
    near_complete = []
    for i, r in enumerate(rankings[:50], 1):
        print(f"{i:<5} {r['tu']:<30} {r['matched']:<8} {r['total']:<8} {r['pct']:.1f}%{'':<3} {r['remaining']:<10} {r['agent_count']:<8}")
        if r['pct'] >= 80 and r['remaining'] > 0:
            near_complete.append(r)
    
    print()
    print("=" * 80)
    print(f"NEAR-COMPLETE TUs (>=80% matched, >0 remaining): {len(near_complete)}")
    print("=" * 80)
    print()
    
    for i, r in enumerate(near_complete[:20], 1):
        print(f"{i}. {r['tu']} — {r['matched']}/{r['total']} matched ({r['pct']:.1f}%) — {r['remaining']} remaining")
    
    # Write full report to file for posting
    with open('build/reports/tu_ranking_full.json', 'w') as f:
        import json
        json.dump(rankings, f, indent=2)

if __name__ == '__main__':
    main()
