#!/usr/bin/env python3
"""
dedup_matched.py — Consolidate duplicate-address files in src/matched/.

Scans all .cpp files, groups by hex address extracted from filename,
picks the best file per address (named > placeholder, TU-dir > agent/),
deletes the rest. Optionally verifies kept files with verify_match.sh.

Usage:
    python tools/dedup_matched.py              # dry-run (default)
    python tools/dedup_matched.py --execute    # actually delete duplicates
    python tools/dedup_matched.py --verify     # verify kept files (slow)
"""

import os
import re
import sys
import json
import subprocess
from pathlib import Path
from collections import defaultdict


def extract_address(filename):
    """Extract 8-char hex address from filename."""
    m = re.search(r'(?:0x)?([0-9a-fA-F]{8})', filename)
    if m:
        return m.group(1).upper()
    return None


def score_file(filepath):
    """Score a file for keeper selection. Higher = better.

    Scoring criteria:
      - Named function > func_XXXX placeholder > sub_ generic
      - TU-specific directory > agent/ catch-all
      - Longer/more descriptive name preferred
    """
    p = Path(filepath)
    name = p.stem  # filename without .cpp
    parent = p.parent.name  # immediate directory

    score = 0

    # Penalize placeholder names
    if re.search(r'func_[0-9a-fA-F]+', name):
        score -= 100  # func_XXXX placeholder — worst
    elif re.search(r'^match_(?:0x)?[0-9a-fA-F]+$', name):
        score -= 90  # bare address, no function name
    elif 'sub_' in name and not any(kw in name for kw in ('__', 'Instance', 'Object')):
        score -= 50  # generic sub_ name

    # Bonus for TU-specific directory (not agent/)
    if parent != 'agent':
        score += 30

    # Bonus for having a recognizable function/class name
    # Strip the match_0xADDR_ prefix to get the descriptive part
    desc = re.sub(r'^match_(?:0x)?[0-9a-fA-F]+_?', '', name)
    if desc and len(desc) > 3:
        score += 20
        # Extra for C++ style names (Class__Method or Class_Method)
        if '__' in desc or '::' in desc:
            score += 10

    # Tiebreak: longer descriptive name
    score += min(len(desc), 30)

    return score


def find_duplicates(matched_dir):
    """Scan src/matched/ and group files by address."""
    address_to_files = defaultdict(list)

    for cpp_file in matched_dir.rglob('*.cpp'):
        addr = extract_address(cpp_file.name)
        if addr:
            address_to_files[addr].append(str(cpp_file))

    return address_to_files


def pick_keeper(files):
    """From a list of duplicate files, pick the best one to keep."""
    scored = [(score_file(f), f) for f in files]
    scored.sort(key=lambda x: (-x[0], x[1]))  # highest score first, alphabetical tiebreak
    return scored[0][1], [(s, f) for s, f in scored[1:]]


def main():
    dry_run = '--execute' not in sys.argv
    do_verify = '--verify' in sys.argv

    matched_dir = Path('src/matched')
    if not matched_dir.exists():
        print(f"ERROR: {matched_dir} not found. Run from repo root.")
        sys.exit(1)

    print("=" * 70)
    print("DEDUP MATCHED FILES")
    print("=" * 70)
    print(f"Mode: {'DRY RUN' if dry_run else 'EXECUTE'}")
    print()

    # Step 1: Find all files and group by address
    address_to_files = find_duplicates(matched_dir)
    total_files = sum(len(files) for files in address_to_files.values())
    unique_addresses = len(address_to_files)
    duplicates = {addr: files for addr, files in address_to_files.items()
                  if len(files) > 1}

    print(f"Total files scanned: {total_files}")
    print(f"Unique addresses: {unique_addresses}")
    print(f"Duplicate groups: {len(duplicates)}")
    print(f"Extra files to remove: {sum(len(f) - 1 for f in duplicates.values())}")
    print()

    if not duplicates:
        print("No duplicates found. Nothing to do.")
        return

    # Step 2: For each duplicate group, pick keeper and losers
    keepers = []
    deletions = []

    for addr in sorted(duplicates.keys()):
        files = duplicates[addr]
        keeper, losers = pick_keeper(files)
        keepers.append((addr, keeper))
        for score, loser in losers:
            deletions.append((addr, loser, keeper))

    # Step 3: Report
    print("=" * 70)
    print(f"DEDUP PLAN: keep {len(keepers)} files, delete {len(deletions)} files")
    print("=" * 70)

    for addr, loser, keeper in deletions[:30]:
        print(f"  0x{addr}: DELETE {loser}")
        print(f"           KEEP   {keeper}")

    if len(deletions) > 30:
        print(f"  ... and {len(deletions) - 30} more deletions")

    print()

    # Step 4: Verify kept files (optional)
    if do_verify:
        print("=" * 70)
        print("VERIFYING KEPT FILES (this may take a while)...")
        print("=" * 70)
        failures = []
        for i, (addr, keeper) in enumerate(keepers):
            if (i + 1) % 50 == 0:
                print(f"  Verified {i + 1}/{len(keepers)}...")
            # Extract size from header comment
            try:
                with open(keeper, 'r', errors='replace') as f:
                    header = f.read(500)
                size_match = re.search(r'(\d+)\s*[bB](?:ytes)?\)', header)
                if not size_match:
                    size_match = re.search(r'(\d+)\s*bytes', header)
                if not size_match:
                    continue  # can't determine size, skip verification
                size = int(size_match.group(1))
                result = subprocess.run(
                    ['bash', 'tools/verify_match.sh', keeper, f'0x{addr}', str(size)],
                    capture_output=True, text=True, timeout=30
                )
                if result.returncode != 0:
                    failures.append((addr, keeper, result.stdout + result.stderr))
            except Exception as e:
                failures.append((addr, keeper, str(e)))

        if failures:
            print(f"\nWARNING: {len(failures)} kept files FAILED verification:")
            for addr, keeper, err in failures[:10]:
                print(f"  0x{addr}: {keeper}")
                print(f"    {err[:200]}")
        else:
            print(f"\nAll {len(keepers)} kept files verified OK.")
        print()

    # Step 5: Execute deletions
    if dry_run:
        print("DRY RUN — no files deleted. Run with --execute to apply.")
    else:
        print("=" * 70)
        print("EXECUTING DELETIONS...")
        print("=" * 70)
        deleted_count = 0
        errors = []
        for addr, loser, keeper in deletions:
            try:
                os.remove(loser)
                deleted_count += 1
            except OSError as e:
                errors.append((loser, str(e)))

        print(f"Deleted {deleted_count} files.")
        if errors:
            print(f"Errors: {len(errors)}")
            for path, err in errors[:10]:
                print(f"  {path}: {err}")

        # Step 6: Recount and report final stats
        final_address_to_files = find_duplicates(matched_dir)
        final_total = sum(len(f) for f in final_address_to_files.values())
        final_unique = len(final_address_to_files)
        final_dupes = sum(1 for f in final_address_to_files.values() if len(f) > 1)

        print()
        print("=" * 70)
        print("FINAL STATS")
        print("=" * 70)
        print(f"Files remaining: {final_total}")
        print(f"Unique addresses: {final_unique}")
        print(f"Remaining duplicates: {final_dupes}")
        print(f"Files deleted this run: {deleted_count}")

        # Save updated stats
        stats = {
            'total_files': final_total,
            'unique_addresses': final_unique,
            'duplicate_count': final_dupes,
            'files_deleted': deleted_count,
            'dedup_run': True
        }
        with open('matched_stats.json', 'w') as f:
            json.dump(stats, f, indent=2)
        print("\nUpdated stats saved to matched_stats.json")


if __name__ == '__main__':
    main()
