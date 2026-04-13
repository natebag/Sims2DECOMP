#!/usr/bin/env python3
"""Bulk dtor52 blast - apply -fno-schedule-insns and verify."""

import os
import re
import subprocess
import json

WIP_DIR = "src/wip/version_diff"
MATCHED_DIR = "src/matched"

# Find all dtor52 candidates
candidates = []
for f in os.listdir(WIP_DIR):
    if re.search(r'dtor.*52|52.*dtor|~.*52|_52_', f, re.IGNORECASE):
        # Check if already has FLAGS
        filepath = os.path.join(WIP_DIR, f)
        try:
            with open(filepath) as fp:
                lines = fp.read().split('\n')[:3]
                has_flags = any('FLAGS:' in line for line in lines)
                if not has_flags:
                    candidates.append(f)
        except:
            pass

print(f"Found {len(candidates)} dtor52 candidates without FLAGS")

# Process first batch of 20
batch = candidates[:20]
results = []

for fname in batch:
    filepath = os.path.join(WIP_DIR, fname)
    
    # Parse header for address and size
    try:
        with open(filepath) as f:
            lines = f.readlines()
        header = lines[0] if lines else ""
        
        # Extract address and size from header like "// 0x80012345 FuncName (52b)"
        m = re.search(r'0x([0-9A-Fa-f]+).*?(\d+)\s*[bB]', header)
        if not m:
            results.append({"file": fname, "status": "PARSE_ERROR", "reason": "Could not parse header"})
            continue
            
        addr = f"0x{m.group(1).upper()}"
        size = m.group(2)
        
        # Add FLAGS line as line 2
        new_lines = [lines[0]]
        if not lines[0].endswith('\n'):
            new_lines[0] += '\n'
        new_lines.append("// FLAGS: -fno-schedule-insns\n")
        new_lines.extend(lines[1:])
        
        with open(filepath, 'w') as f:
            f.writelines(new_lines)
        
        # Run verify_match.sh
        result = subprocess.run(
            ["bash", "tools/verify_match.sh", filepath, addr, size],
            capture_output=True, text=True, timeout=30
        )
        
        output = result.stdout + result.stderr
        
        if "MATCH" in output and "MISMATCH" not in output:
            # Success! Determine TU from filename
            tu_match = re.search(r'([A-Za-z][A-Za-z0-9]*)_', fname)
            tu = tu_match.group(1).lower() if tu_match else "agent"
            
            results.append({
                "file": fname, 
                "status": "MATCH", 
                "addr": addr, 
                "size": size,
                "tu": tu
            })
        else:
            # Failed - leave FLAGS in place as signal
            results.append({
                "file": fname, 
                "status": "MISMATCH", 
                "addr": addr,
                "output": output[:200]
            })
            
    except Exception as e:
        results.append({"file": fname, "status": "ERROR", "reason": str(e)})

# Summary
matches = [r for r in results if r["status"] == "MATCH"]
mismatches = [r for r in results if r["status"] == "MISMATCH"]
errors = [r for r in results if r["status"] in ("ERROR", "PARSE_ERROR")]

print(f"\n=== BATCH RESULTS ===")
print(f"MATCH: {len(matches)}")
print(f"MISMATCH: {len(mismatches)}")
print(f"ERRORS: {len(errors)}")

if matches:
    print("\n=== MATCHES (ready to move) ===")
    for m in matches:
        print(f"  {m['addr']} {m['file']} -> {m['tu']}")

# Save results
with open("dtor52_batch_results.json", "w") as f:
    json.dump(results, f, indent=2)

print(f"\nResults saved to dtor52_batch_results.json")
