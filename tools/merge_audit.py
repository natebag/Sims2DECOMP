#!/usr/bin/env python3
"""
Merge audit chunk results and produce summary + cleanup actions.
Usage: python merge_audit.py /tmp/audit_chunks/chunk_*.txt
"""
import sys
import os
from collections import Counter, defaultdict
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")

# Collect all results
results = []
for fpath in sys.argv[1:]:
    with open(fpath, 'r') as f:
        for line in f:
            parts = line.strip().split('\t')
            if len(parts) >= 2:
                results.append(parts)

# Deduplicate by filepath
seen = {}
for parts in results:
    filepath = parts[1]
    if filepath not in seen:
        seen[filepath] = parts

results = list(seen.values())

# Categorize
categories = Counter()
failures = defaultdict(list)
for parts in results:
    status = parts[0]
    filepath = parts[1]
    categories[status] += 1
    if status != "PASS":
        detail = parts[4] if len(parts) > 4 else ""
        failures[status].append((filepath, detail))

total = len(results)
print(f"=== FULL AUDIT RESULTS ===")
print(f"Total files audited: {total}")
print()
for status in ["PASS", "MISMATCH", "SIZE_MISMATCH", "COMPILE_FAIL", "SKIP", "OTHER", "TIMEOUT", "REJECTED"]:
    count = categories.get(status, 0)
    if count > 0:
        pct = 100 * count / total if total > 0 else 0
        print(f"  {status:20s}: {count:6d} ({pct:5.1f}%)")

pass_count = categories.get("PASS", 0)
total_funcs = 20508
print()
print(f"=== VERIFIED PROGRESS ===")
print(f"  Verified PASS:      {pass_count}")
print(f"  Total functions:    {total_funcs}")
print(f"  True decomp %:     {100*pass_count/total_funcs:.1f}%")
print(f"  Previous reported:  9,192 files (44.8%)")
print(f"  Delta:              {pass_count - 9192} files ({100*pass_count/total_funcs - 44.8:+.1f}pp)")

# Write full results
output_path = REPO / "tools" / "full_audit_results_v2.txt"
with open(output_path, 'w') as f:
    for parts in sorted(results, key=lambda p: (p[0], p[1])):
        f.write('\t'.join(parts) + '\n')
print(f"\nFull results written to: {output_path}")

# Write cleanup actions
cleanup_path = REPO / "tools" / "cleanup_actions.txt"
with open(cleanup_path, 'w') as f:
    for parts in sorted(results, key=lambda p: p[1]):
        status = parts[0]
        filepath = parts[1]
        if status in ("MISMATCH", "SIZE_MISMATCH"):
            f.write(f"RELOCATE\t{filepath}\treason: {status}\n")
        elif status == "COMPILE_FAIL":
            f.write(f"RELOCATE\t{filepath}\treason: COMPILE_FAIL\n")
        elif status == "OTHER":
            detail = parts[4] if len(parts) > 4 else "unknown"
            f.write(f"RELOCATE\t{filepath}\treason: OTHER — {detail}\n")
        elif status == "REJECTED":
            f.write(f"DELETE\t{filepath}\treason: REJECTED — fake match\n")

cleanup_count = sum(1 for s in categories if s in ("MISMATCH", "SIZE_MISMATCH", "COMPILE_FAIL", "OTHER", "REJECTED") for _ in range(categories[s]))
print(f"Cleanup actions written to: {cleanup_path}")
print(f"  Files to relocate/delete: {cleanup_count}")

# Write failure details
details_path = REPO / "tools" / "audit_failure_details.txt"
with open(details_path, 'w') as f:
    for status in ["MISMATCH", "SIZE_MISMATCH", "COMPILE_FAIL", "OTHER", "TIMEOUT", "REJECTED"]:
        items = failures.get(status, [])
        if items:
            f.write(f"\n=== {status} ({len(items)} files) ===\n")
            for filepath, detail in sorted(items):
                f.write(f"  {filepath}")
                if detail:
                    f.write(f"  — {detail}")
                f.write("\n")
print(f"Failure details written to: {details_path}")

# Subdirectory breakdown
print(f"\n=== BY DIRECTORY ===")
dir_stats = defaultdict(Counter)
for parts in results:
    status = parts[0]
    filepath = parts[1]
    # Get second-level dir
    p = Path(filepath)
    if len(p.parts) >= 3:
        subdir = str(Path(*p.parts[:3]))
    else:
        subdir = str(p.parent)
    dir_stats[subdir][status] += 1

for subdir in sorted(dir_stats.keys()):
    stats = dir_stats[subdir]
    total_d = sum(stats.values())
    pass_d = stats.get("PASS", 0)
    print(f"  {subdir:40s}: {total_d:5d} total, {pass_d:5d} PASS ({100*pass_d/total_d:.1f}%)")
