#!/usr/bin/env python3
"""T+270 tick script for TUScout."""
import subprocess, re, sys
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
SIZE_RE = re.compile(r'\((\d+)\s+B\)')

result = subprocess.run(
    ['git', 'ls-files', '--cached', '--', 'src/matched/'],
    capture_output=True, text=True, cwd=str(REPO)
)
all_files = [f.strip() for f in result.stdout.splitlines() if f.strip().endswith('.cpp')]

inject_files = []
for fpath_str in all_files:
    fpath = REPO / fpath_str
    try:
        with open(fpath, 'r', encoding='utf-8', errors='ignore') as fh:
            first = fh.readline()
            chunk = fh.read(4096)
        if 'ASMPROC_inject_before' in (first + chunk):
            inject_files.append((fpath_str, first))
    except Exception:
        pass

b30_50 = 0
b51_80 = 0
unread = 0
focus_dirs = ['aptactioninterpreter', 'eanimcontroller', 'sanimator2', 'agent']
focus_inj = {d: 0 for d in focus_dirs}
focus_tot = {d: 0 for d in focus_dirs}

for fpath_str, first_line in inject_files:
    m = SIZE_RE.search(first_line)
    if not m:
        unread += 1
        continue
    sz = int(m.group(1))
    if 30 <= sz <= 50:
        b30_50 += 1
    elif 51 <= sz <= 80:
        b51_80 += 1
    norm = fpath_str.replace('\\', '/')
    for d in focus_dirs:
        if ('/' + d + '/') in norm:
            focus_inj[d] += 1
            break

for fpath_str in all_files:
    norm = fpath_str.replace('\\', '/')
    for d in focus_dirs:
        if ('/' + d + '/') in norm:
            focus_tot[d] += 1
            break

total_tracked = len(all_files)
inject_pool = len(inject_files)
real_count = total_tracked - inject_pool
ratio = 100.0 * real_count / total_tracked if total_tracked else 0

print("=== T+270 TICK ===")
print("Total tracked   : %d" % total_tracked)
print("Inject pool     : %d  (T+240 baseline: 9274, delta=%+d)" % (inject_pool, inject_pool - 9274))
print("Real C++        : %d" % real_count)
print("Semantic ratio  : %.2f%%  (T+240: 55.78%%)" % ratio)
print()
print("Band counts (30-50B and 51-80B explicit non-overlapping):")
print("  30-50B inject : %d  (T+240 baseline: 292, delta=%+d)" % (b30_50, b30_50 - 292))
print("  51-80B inject : %d  (T+240 baseline: 616, delta=%+d)" % (b51_80, b51_80 - 616))
print("  Unreadable    : %d" % unread)
print()
print("Focus lanes (all-size inject / total):")
print("%-25s %6s %6s %7s" % ("Dir", "Total", "Inject", "%Real"))
print("-" * 50)
for d in focus_dirs:
    tot = focus_tot[d]
    inj = focus_inj[d]
    real = tot - inj
    pct = 100.0 * real / tot if tot else 0
    prev_inj = {'aptactioninterpreter': 127, 'eanimcontroller': 80, 'sanimator2': 127, 'agent': 0}.get(d, 0)
    delta = inj - prev_inj
    print("%-25s %6d %6d %6.1f%%  inject_delta=%+d" % (d, tot, inj, pct, delta))
