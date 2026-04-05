#!/usr/bin/env python3
"""
count_new_matches.py - Count new match files and report duplicates.

This script:
1. Uses git status -s to find untracked match files
2. Extracts addresses from filenames
3. Deduplicates by address
4. Reports: unique new matches, duplicates to delete

Usage:
    python tools/count_new_matches.py
"""

import subprocess
import re
from collections import defaultdict

def get_git_status():
    """Get untracked files from git status."""
    result = subprocess.run(
        ['git', 'status', '-s'],
        capture_output=True,
        text=True,
        cwd='.'
    )
    return result.stdout

def extract_match_files(status_output):
    """Extract match file paths from git status output."""
    match_files = []
    for line in status_output.strip().split('\n'):
        if not line:
            continue
        # Git status -s format: XY filename
        # For untracked files: ?? filename
        if line.startswith('??'):
            filename = line[3:].strip()
            if 'match_' in filename and filename.endswith('.cpp'):
                match_files.append(filename)
    return match_files

def extract_address(filename):
    """Extract hex address from match filename."""
    # Pattern: match_0xXXXXXXXX_* or match_XXXXXXXX_*
    patterns = [
        r'match_0x([0-9A-Fa-f]{8})_',
        r'match_([0-9A-Fa-f]{8})_'
    ]
    for pattern in patterns:
        match = re.search(pattern, filename)
        if match:
            return match.group(1).upper()
    return None

def analyze_matches(match_files):
    """Analyze match files for duplicates."""
    address_to_files = defaultdict(list)
    
    for filepath in match_files:
        addr = extract_address(filepath)
        if addr:
            address_to_files[addr].append(filepath)
    
    return address_to_files

def main():
    print("=" * 60)
    print("NEW MATCH FILE ANALYSIS")
    print("=" * 60)
    print()
    
    # Get git status
    status_output = get_git_status()
    match_files = extract_match_files(status_output)
    
    if not match_files:
        print("No new untracked match files found.")
        return
    
    print(f"Found {len(match_files)} untracked match files:")
    for f in match_files[:10]:
        print(f"  {f}")
    if len(match_files) > 10:
        print(f"  ... and {len(match_files) - 10} more")
    print()
    
    # Analyze for duplicates
    address_to_files = analyze_matches(match_files)
    
    unique_count = 0
    duplicate_count = 0
    duplicates = []
    
    for addr, files in address_to_files.items():
        if len(files) == 1:
            unique_count += 1
        else:
            duplicate_count += len(files) - 1
            # Keep the first one, mark rest as duplicates
            duplicates.extend(files[1:])
    
    print("-" * 60)
    print("SUMMARY:")
    print("-" * 60)
    print(f"Unique new matches: {unique_count}")
    print(f"Duplicate files to delete: {duplicate_count}")
    print(f"Total files: {len(match_files)}")
    print()
    
    if duplicates:
        print("-" * 60)
        print("DUPLICATE FILES (recommend deleting these):")
        print("-" * 60)
        for dup in duplicates[:20]:
            print(f"  rm '{dup}'")
        if len(duplicates) > 20:
            print(f"  ... and {len(duplicates) - 20} more")
        print()
    
    # Show addresses with multiple files
    print("-" * 60)
    print("ADDRESSES WITH MULTIPLE FILES:")
    print("-" * 60)
    for addr, files in sorted(address_to_files.items()):
        if len(files) > 1:
            print(f"\n0x{addr}: {len(files)} files")
            for f in files:
                print(f"  - {f}")

if __name__ == '__main__':
    main()
