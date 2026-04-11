#!/usr/bin/env python3
"""Bulk dtor52 blast - add headers, apply -fno-schedule-insns and verify."""

import os
import re
import subprocess
import json

WIP_DIR = "src/wip/version_diff"
DVD_MAP = "extracted/files/u2_ngc_release_dvd.map"

# Load DVD map for size lookups
def load_dvd_map():
    addr_to_size = {}
    addr_to_name = {}
    with open(DVD_MAP) as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) >= 3:
                addr = parts[0]
                size = parts[1]
                name = parts[2] if len(parts) > 2 else ""
                addr_to_size[addr] = size
                addr_to_name[addr] = name
    return addr_to_size, addr_to_name

# Find all dtor52 candidates
def find_candidates():
    candidates = []
    for f in os.listdir(WIP_DIR):
        if re.search(r'dtor.*52|52.*dtor|~.*52|_52_', f, re.IGNORECASE):
            filepath = os.path.join(WIP_DIR, f)
            try:
                with open(filepath) as fp:
                    content = fp.read()
                    # Skip if already has FLAGS
                    if '// FLAGS:' in content[:500]:
                        continue
                    # Skip if already has proper header
                    if re.search(r'^//\s*0x[0-9A-Fa-f]+', content[:500], re.MULTILINE):
                        continue
                    candidates.append(f)
            except:
                pass
    return candidates

# Extract address from filename
def parse_addr_from_filename(fname):
    m = re.search(r'0x([0-9A-Fa-f]+)', fname)
    if m:
        return f"0x{m.group(1).upper()}"
    return None

# Process candidates
def process_batch(candidates, addr_to_size, addr_to_name, batch_size=20):
    batch = candidates[:batch_size]
    results = []
    
    for fname in batch:
        filepath = os.path.join(WIP_DIR, fname)
        
        try:
            with open(filepath) as f:
                content = f.read()
            
            # Get address from filename
            addr = parse_addr_from_filename(fname)
            if not addr:
                results.append({"file": fname, "status": "PARSE_ERROR", "reason": "No address in filename"})
                continue
            
            # Get size from DVD map
            size_hex = addr_to_size.get(addr.upper().replace('0X', ''), '')
            if not size_hex:
                results.append({"file": fname, "status": "PARSE_ERROR", "reason": f"Size not found for {addr}"})
                continue
            size = int(size_hex, 16)
            
            # Get function name from DVD map or filename
            func_name = addr_to_name.get(addr.upper().replace('0X', ''), '')
            if not func_name:
                # Extract from filename
                m = re.search(r'match_0x[0-9A-Fa-f]+_(.+?)\.cpp', fname, re.IGNORECASE)
                func_name = m.group(1) if m else "Unknown"
            
            # Create proper header
            header = f"// {addr} {func_name} ({size}b)\n// FLAGS: -fno-schedule-insns\n\n"
            
            # Write updated file
            with open(filepath, 'w') as f:
                f.write(header + content)
            
            # Run verify_match.sh
            result = subprocess.run(
                ["bash", "tools/verify_match.sh", filepath, addr, str(size)],
                capture_output=True, text=True, timeout=30
            )
            
            output = result.stdout + result.stderr
            
            if "MATCH" in output and "MISMATCH" not in output:
                results.append({
                    "file": fname, 
                    "status": "MATCH", 
                    "addr": addr, 
                    "size": size,
                    "func": func_name
                })
            else:
                results.append({
                    "file": fname, 
                    "status": "MISMATCH", 
                    "addr": addr,
                    "size": size,
                    "output": output[:300]
                })
                
        except Exception as e:
            results.append({"file": fname, "status": "ERROR", "reason": str(e)})
    
    return results

# Main
print("Loading DVD map...")
addr_to_size, addr_to_name = load_dvd_map()

print("Finding candidates...")
candidates = find_candidates()
print(f"Found {len(candidates)} candidates needing headers and FLAGS")

print("Processing batch of 20...")
results = process_batch(candidates, addr_to_size, addr_to_name, 20)

# Summary
matches = [r for r in results if r["status"] == "MATCH"]
mismatches = [r for r in results if r["status"] == "MISMATCH"]
errors = [r for r in results if r["status"] in ("ERROR", "PARSE_ERROR")]

print(f"\n=== BATCH RESULTS ===")
print(f"MATCH: {len(matches)}")
print(f"MISMATCH: {len(mismatches)}")
print(f"ERRORS: {len(errors)}")

if matches:
    print("\n=== MATCHES ===")
    for m in matches:
        print(f"  {m['addr']} ({m['size']}b) - {m['func']}")

# Save results
with open("dtor52_results.json", "w") as f:
    json.dump(results, f, indent=2)

print(f"\nResults saved to dtor52_results.json")
print(f"Remaining candidates: {len(candidates) - 20}")
