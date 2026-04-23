#!/usr/bin/env python3
"""Bulk re-verify old MISMATCH files from full_audit_results_v2.txt."""
import subprocess, os, sys
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
BASH = r"F:\coding\Decompiles\Tools\devkitPro\msys2\usr\bin\bash.exe"

def main():
    audit_file = REPO / "tools" / "full_audit_results_v2.txt"
    out_file = REPO / "tools" / "reverify_mismatch_results.txt"
    
    # Collect existing MISMATCH entries
    tasks = []
    with open(audit_file) as f:
        for line in f:
            if not line.startswith("MISMATCH\t"):
                continue
            parts = line.strip().split("\t")
            if len(parts) < 4:
                continue
            fpath, addr, size = parts[1], parts[2], parts[3]
            full = REPO / fpath
            if full.exists():
                tasks.append((str(full), addr, size))
    
    print(f"Re-verifying {len(tasks)} MISMATCH files...")
    matches = []
    still_mismatch = []
    errors = []
    
    with open(out_file, "w") as out:
        out.write(f"# Bulk re-verify of {len(tasks)} MISMATCH files\n")
        for i, (fpath, addr, size) in enumerate(tasks, 1):
            cmd = [
                BASH, "-lc",
                f'cd /f/coding/Decompiles/Sims\\ 2 && DEVKITPPC=/f/coding/Decompiles/Tools/devkitPro/devkitPPC ./tools/verify_match.sh "{fpath}" {addr} {size}'
            ]
            try:
                result = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
            except subprocess.TimeoutExpired:
                errors.append((fpath, addr, "TIMEOUT"))
                out.write(f"TIMEOUT\t{fpath}\t{addr}\t{size}\n")
                out.flush()
                print(f"[{i}/{len(tasks)}] TIMEOUT {addr}")
                continue
            
            output = result.stdout + result.stderr
            if "MATCH!" in output:
                matches.append((fpath, addr, size))
                out.write(f"MATCH\t{fpath}\t{addr}\t{size}\n")
                print(f"[{i}/{len(tasks)}] MATCH {addr}")
            elif "SIZE_MISMATCH" in output:
                still_mismatch.append((fpath, addr, size, "SIZE_MISMATCH"))
                out.write(f"SIZE_MISMATCH\t{fpath}\t{addr}\t{size}\n")
                print(f"[{i}/{len(tasks)}] SIZE_MISMATCH {addr}")
            elif "MISMATCH" in output or "NO MATCH" in output:
                still_mismatch.append((fpath, addr, size, "MISMATCH"))
                out.write(f"MISMATCH\t{fpath}\t{addr}\t{size}\n")
                print(f"[{i}/{len(tasks)}] MISMATCH {addr}")
            else:
                errors.append((fpath, addr, output[-300:]))
                out.write(f"ERROR\t{fpath}\t{addr}\t{size}\t{output[-200:].replace(chr(10), ' ')}\n")
                print(f"[{i}/{len(tasks)}] ERROR {addr}")
            out.flush()
        
        out.write(f"\n# SUMMARY\n")
        out.write(f"# Total: {len(tasks)}\n")
        out.write(f"# MATCH: {len(matches)}\n")
        out.write(f"# STILL_MISMATCH: {len(still_mismatch)}\n")
        out.write(f"# ERRORS: {len(errors)}\n")
    
    print(f"\n=== DONE ===")
    print(f"MATCH: {len(matches)}")
    print(f"STILL_MISMATCH: {len(still_mismatch)}")
    print(f"ERRORS: {len(errors)}")
    print(f"Results written to {out_file}")

if __name__ == "__main__":
    main()
