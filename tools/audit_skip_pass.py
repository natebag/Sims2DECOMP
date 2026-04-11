#!/usr/bin/env python3
"""
Secondary audit for SKIP files — infers size from function name pattern and verifies.
"""
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
BASH = r"C:\Program Files\Git\bin\bash.exe"

# Size inference rules based on function name patterns
# 8-byte: single instruction + blr
SIZE_8_PATTERNS = [
    r'li_return_',     # li r3, N; blr
    r'ReturnConst_',   # li r3, N; blr
    r'mr_return',      # mr r3, rX; blr
    r'getter_0x',      # lwz r3, 0xN(r3); blr
    r'Setter_0x',      # stw rX, 0xN(r3); blr
    r'stfs_0x',        # stfs fX, 0xN(r3); blr
    r'hgetter_0x',     # lhz r3, 0xN(r3); blr
    r'addi_0x',        # addi r3, r3, N; blr
    r'Rb_global_M_increment',  # likely 8 bytes
]
# 12-byte: two instructions + blr
SIZE_12_PATTERNS = [
    r'lis_return_',    # lis r3, hi; ori r3, r3, lo; blr
]

def infer_size(basename):
    for pat in SIZE_12_PATTERNS:
        if re.search(pat, basename):
            return 12
    for pat in SIZE_8_PATTERNS:
        if re.search(pat, basename):
            return 8
    return None

# Load file list
skip_file = sys.argv[1]
output_file = sys.argv[2]

with open(skip_file, 'r') as f:
    files = [line.strip() for line in f if line.strip()]

stats = {"PASS": 0, "MISMATCH": 0, "SIZE_MISMATCH": 0, "SKIP": 0, "OTHER": 0}

with open(output_file, 'w') as out:
    for i, filepath in enumerate(files):
        basename = Path(filepath).stem

        # Extract address
        addr_m = re.search(r'(?:0x)?([0-9A-Fa-f]{8})', basename)
        if not addr_m:
            out.write(f"SKIP\t{filepath}\tno_address\n")
            out.flush()
            stats["SKIP"] += 1
            continue

        addr_hex = addr_m.group(1).upper()

        # Infer size
        # Strip address prefix to get function name part
        func_name = re.sub(r'^match_(?:0x)?[0-9A-Fa-f]{8}_', '', basename)
        size = infer_size(func_name)

        if size is None:
            out.write(f"SKIP\t{filepath}\tcant_infer_size: {func_name}\n")
            out.flush()
            stats["SKIP"] += 1
            continue

        # Run verify_match.sh
        rel = filepath.replace('\\', '/')
        try:
            result = subprocess.run(
                [BASH, 'tools/verify_match.sh', rel, f'0x{addr_hex}', str(size)],
                capture_output=True, text=True, timeout=60, cwd=str(REPO)
            )
            stdout = result.stdout

            if 'MATCH!' in stdout:
                status = "PASS"
            elif 'SIZE_MISMATCH' in stdout:
                status = "SIZE_MISMATCH"
            elif 'MISMATCH' in stdout:
                status = "MISMATCH"
            else:
                status = "OTHER"

            out.write(f"{status}\t{filepath}\t0x{addr_hex}\t{size}\n")
            out.flush()
            stats[status] += 1
        except Exception as e:
            out.write(f"OTHER\t{filepath}\t0x{addr_hex}\t{size}\t{str(e)[:80]}\n")
            out.flush()
            stats["OTHER"] += 1

        if (i + 1) % 50 == 0:
            print(f'  [{i+1}/{len(files)}] {dict(stats)}', flush=True)

print(f'\n=== SKIP RE-AUDIT COMPLETE ===', flush=True)
for k, v in stats.items():
    if v > 0:
        print(f'  {k}: {v}', flush=True)
print(f'  Total: {sum(stats.values())}', flush=True)
