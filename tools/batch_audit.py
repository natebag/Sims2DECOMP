#!/usr/bin/env python3
"""
Batch audit of src/matched/ — processes a chunk of files via verify_match.sh.
Usage: python batch_audit.py <file_list> <output_file> [--start N] [--count N]
"""
import re
import subprocess
import sys
import struct
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
BASH = r"C:\Program Files\Git\bin\bash.exe"
DVD_MAP = REPO / "extracted" / "files" / "u2_ngc_release_dvd.map"

# Parse args
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("file_list", help="File with list of .cpp paths to audit")
parser.add_argument("output_file", help="Output results file")
parser.add_argument("--start", type=int, default=0, help="Start line (0-indexed)")
parser.add_argument("--count", type=int, default=0, help="Number of files (0=all)")
args = parser.parse_args()

# Load DVD map for size fallback
ADDR_TO_SIZE = {}
_map_re = re.compile(r'^([0-9a-f]{8})\s+([0-9a-f]{8})\s+0\s')
with open(DVD_MAP, 'r') as f:
    for line in f:
        m = _map_re.match(line)
        if m:
            ADDR_TO_SIZE[int(m.group(1), 16)] = int(m.group(2), 16)
print(f'Loaded {len(ADDR_TO_SIZE)} symbols from DVD map', flush=True)

# Load file list
with open(args.file_list, 'r') as f:
    all_files = [line.strip() for line in f if line.strip()]

# Slice
start = args.start
end = start + args.count if args.count > 0 else len(all_files)
files = all_files[start:end]
print(f'Processing files {start} to {end-1} ({len(files)} files)', flush=True)

# Size extraction patterns
SIZE_PATTERNS = [
    re.compile(r'\(\s*(\d+)\s*[Bb](?:ytes?)?\s*\)'),
    re.compile(r'\(\s*(\d+)\s*\)'),  # just (NNN) near addr
    re.compile(r'[Ss]ize\s*[:=]\s*(\d+)'),
    re.compile(r'\b(\d+)\s+bytes?\b'),
]

stats = {"PASS": 0, "MISMATCH": 0, "COMPILE_FAIL": 0, "SIZE_MISMATCH": 0, "SKIP": 0, "TIMEOUT": 0, "REJECTED": 0, "OTHER": 0}

with open(args.output_file, 'w') as out:
    for i, filepath in enumerate(files):
        filepath = filepath.strip()
        fname = Path(filepath).name

        # Extract address from filename (handles both match_0xADDR and match_ADDR)
        addr_m = re.search(r'match_(?:0x)?([0-9A-Fa-f]{8})', fname)
        if not addr_m:
            out.write(f"SKIP\t{filepath}\tno_address_in_filename\n")
            out.flush()
            stats["SKIP"] += 1
            continue

        addr_hex = addr_m.group(1).upper()
        addr_int = int(addr_hex, 16)

        # Read first 10 lines to find size
        try:
            p = Path(REPO / filepath)
            content = p.read_text(errors='ignore')[:2000]  # first 2KB
        except Exception as e:
            out.write(f"SKIP\t{filepath}\tcant_read: {e}\n")
            out.flush()
            stats["SKIP"] += 1
            continue

        size = None
        for pat in SIZE_PATTERNS:
            m = pat.search(content[:500])
            if m:
                s = int(m.group(1))
                if 4 <= s <= 100000:  # sanity check
                    size = s
                    break

        if size is None:
            size = ADDR_TO_SIZE.get(addr_int)

        if size is None:
            out.write(f"SKIP\t{filepath}\tno_size_found\n")
            out.flush()
            stats["SKIP"] += 1
            continue

        # Run verify_match.sh
        rel = filepath.replace('\\', '/')
        try:
            result = subprocess.run(
                [BASH, 'tools/verify_match.sh', rel, f'0x{addr_hex}', str(size)],
                capture_output=True, text=True, timeout=120, cwd=str(REPO)
            )
            stdout = result.stdout
            stderr = result.stderr

            if 'MATCH!' in stdout:
                status = "PASS"
            elif 'REJECTED' in stdout:
                status = "REJECTED"
            elif 'COMPILE FAILED' in stdout or 'COMPILE FAILED' in stderr:
                status = "COMPILE_FAIL"
            elif 'ASSEMBLE FAILED' in stdout:
                status = "COMPILE_FAIL"
            elif 'SIZE_MISMATCH' in stdout:
                status = "SIZE_MISMATCH"
            elif 'MISMATCH' in stdout:
                status = "MISMATCH"
            elif result.returncode != 0:
                # Get last useful line
                detail = (stdout + stderr).strip().split('\n')[-1][:100]
                status = "OTHER"
                out.write(f"OTHER\t{filepath}\t0x{addr_hex}\t{size}\t{detail}\n")
                out.flush()
                stats["OTHER"] += 1
                if (i + 1) % 50 == 0:
                    total = i + 1
                    print(f'  [{total}/{len(files)}] P={stats["PASS"]} M={stats["MISMATCH"]} CF={stats["COMPILE_FAIL"]} SM={stats["SIZE_MISMATCH"]} S={stats["SKIP"]} R={stats["REJECTED"]} O={stats["OTHER"]}', flush=True)
                continue
            else:
                status = "OTHER"
                detail = stdout.strip().split('\n')[-1][:100]
                out.write(f"OTHER\t{filepath}\t0x{addr_hex}\t{size}\t{detail}\n")
                out.flush()
                stats["OTHER"] += 1
                if (i + 1) % 50 == 0:
                    total = i + 1
                    print(f'  [{total}/{len(files)}] P={stats["PASS"]} M={stats["MISMATCH"]} CF={stats["COMPILE_FAIL"]} SM={stats["SIZE_MISMATCH"]} S={stats["SKIP"]} R={stats["REJECTED"]} O={stats["OTHER"]}', flush=True)
                continue

            out.write(f"{status}\t{filepath}\t0x{addr_hex}\t{size}\n")
            out.flush()
            stats[status] += 1

        except subprocess.TimeoutExpired:
            out.write(f"TIMEOUT\t{filepath}\t0x{addr_hex}\t{size}\n")
            out.flush()
            stats["TIMEOUT"] += 1
        except Exception as e:
            out.write(f"OTHER\t{filepath}\t0x{addr_hex}\t{size}\t{str(e)[:100]}\n")
            out.flush()
            stats["OTHER"] += 1

        if (i + 1) % 50 == 0:
            total = i + 1
            print(f'  [{total}/{len(files)}] P={stats["PASS"]} M={stats["MISMATCH"]} CF={stats["COMPILE_FAIL"]} SM={stats["SIZE_MISMATCH"]} S={stats["SKIP"]} R={stats["REJECTED"]} O={stats["OTHER"]}', flush=True)

    # Final summary
    print(f'\n=== CHUNK COMPLETE ===', flush=True)
    for k, v in stats.items():
        print(f'  {k}: {v}', flush=True)
    print(f'  Total: {sum(stats.values())}', flush=True)
