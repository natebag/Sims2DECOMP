#!/usr/bin/env python3
"""
Audit src/matched/ for files that don't actually pass verify_match.sh.
Identifies false positives that slipped through historical verification.
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
BASH = r"C:\Program Files\Git\bin\bash.exe"
MATCHED_DIR = REPO / "src" / "matched"
DVD_MAP = REPO / "extracted" / "files" / "u2_ngc_release_dvd.map"

# Parse DVD map for addr → size lookup
ADDR_TO_SIZE = {}
_map_re = re.compile(r'^([0-9a-f]{8})\s+([0-9a-f]{8})\s+0\s')
with open(DVD_MAP, 'r') as f:
    for line in f:
        m = _map_re.match(line)
        if m:
            ADDR_TO_SIZE[int(m.group(1), 16)] = int(m.group(2), 16)
print(f'Loaded {len(ADDR_TO_SIZE)} symbols from DVD map for size lookup', flush=True)

# Sample random files from agent dir
import random
random.seed(42)
all_files = sorted(MATCHED_DIR.rglob('match_0x*.cpp'))
# Skip cbmt_blast (already verified)
all_files = [f for f in all_files if 'cbmt_blast' not in f.parts]

sample_size = int(sys.argv[1]) if len(sys.argv) > 1 else 100
sample = random.sample(all_files, min(sample_size, len(all_files)))

print(f'Auditing {len(sample)} random files from {len(all_files)} total in src/matched/', flush=True)

fails = []
ok = 0
errors = 0

for i, f in enumerate(sample):
    name = f.name
    m = re.search(r'0x([0-9A-Fa-f]{8})', name)
    if not m:
        continue
    addr = m.group(1).upper()
    content = f.read_text(errors='ignore')
    # Try size-comment formats first:
    sm = (
        re.search(r'\(\s*(\d+)\s*[Bb](?:ytes?)?\s*\)', content) or
        re.search(r'[Ss]ize\s*[:=]\s*(\d+)', content) or
        re.search(r'\b(\d+)\s+bytes?\b', content)
    )
    if sm:
        size = int(sm.group(1))
    else:
        # Fall back to DVD map lookup by address
        size = ADDR_TO_SIZE.get(int(addr, 16))
        if size is None:
            continue

    rel = str(f.relative_to(REPO)).replace('\\', '/')
    try:
        result = subprocess.run(
            [BASH, 'tools/verify_match.sh', rel, f'0x{addr}', str(size)],
            capture_output=True, text=True, timeout=60, cwd=str(REPO)
        )
        if 'MATCH!' in result.stdout:
            ok += 1
        else:
            fails.append((name, result.stdout[-150:].strip()))
    except subprocess.TimeoutExpired:
        errors += 1
        fails.append((name, 'TIMEOUT'))
    except Exception as e:
        errors += 1
        fails.append((name, str(e)))

    if (i + 1) % 10 == 0:
        print(f'  [{i+1}/{len(sample)}] {ok} ok, {len(fails)} fail', flush=True)

print(f'\n=== RESULTS ===', flush=True)
print(f'  Total: {len(sample)}', flush=True)
print(f'  OK (verified MATCH!): {ok}', flush=True)
print(f'  FAIL (not matching): {len(fails) - errors}', flush=True)
print(f'  Errors: {errors}', flush=True)
print(f'  Fail rate: {100*len(fails)/len(sample):.1f}%', flush=True)

if fails:
    print(f'\n=== FIRST 10 FAILURES ===', flush=True)
    for name, out in fails[:10]:
        print(f'  {name}', flush=True)
