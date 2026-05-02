#!/usr/bin/env python3
"""
Track D Scout: Extract unmatched functions for ERoom, Goals, Careers, etc.
Target sizes: 16-64B (focus on MI-vcall wrappers, state machines, getters).
"""

import re
import json
import struct
import subprocess
from pathlib import Path
from collections import defaultdict

REPO = Path(r"F:\coding\Decompiles\Sims 2")
MAP_FILE = REPO / "extracted" / "files" / "u2_ngc_release.map"
DOL_FILE = REPO / "extracted" / "sys" / "main.dol"
MATCHED_DIR = REPO / "src" / "matched"

# Target classes/namespaces
TARGETS = [
    "ERoom", "ENeighborhood", "EHouse",
    "GoalUnlock", "Careers", "Skill",
    "cSimulatorImpl",
    "ERLevel", "ERModel", "ENgcRenderer",
]

def parse_map():
    """Parse release map for function names and addresses."""
    functions = {}  # addr -> (name, size)
    
    with open(MAP_FILE, 'r', encoding='utf-8', errors='replace') as f:
        for line in f:
            # Symbol format: "80003100 00000368     1                 FunctionName(...)"
            m = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+(\d+)\s+(.+)$', line)
            if not m:
                continue
            
            addr_str = m.group(1)
            size_str = m.group(2)
            name = m.group(4).strip()
            
            # Skip non-function entries
            if not name or name.startswith('c:\\') or '::' not in name:
                continue
            
            addr = int(addr_str, 16)
            size = int(size_str, 16)
            
            # Filter to target classes
            if not any(target in name for target in TARGETS):
                continue
            
            # Size range: 16-64B (focus on MI-vcall, state changes, getters)
            if 16 <= size <= 64:
                functions[addr] = (name, size)
    
    return functions

def check_collision(addr):
    """Check if this address already has a matched file."""
    addr_hex_upper = f"{addr:08X}"
    addr_hex_lower = f"{addr:08x}"
    addr_hex_nopfx = f"{addr:X}"
    
    # Search case-insensitive in filenames
    for pattern in [f"*{addr_hex_upper}*", f"*{addr_hex_lower}*", f"*{addr_hex_nopfx}*"]:
        results = list(MATCHED_DIR.glob(pattern))
        if results:
            return True
    
    return False

def main():
    print("🔍 Track D Scout: Scanning ERoom/Goals/Careers/cSimulator/ERLevel/Model/Renderer...")
    print()
    
    functions = parse_map()
    print(f"Found {len(functions)} unmatched functions in target classes (16-64B)")
    
    # Group by size for easy batch targeting
    by_size = defaultdict(list)
    for addr, (name, size) in sorted(functions.items()):
        by_size[size].append((addr, name))
    
    # Filter out collisions
    findings = []
    collision_count = 0
    
    for size in sorted(by_size.keys()):
        for addr, name in by_size[size]:
            if check_collision(addr):
                collision_count += 1
                continue
            
            findings.append({
                'addr': addr,
                'addr_hex': f'0x{addr:08X}',
                'size': size,
                'name': name,
            })
    
    print(f"After collision check: {len(findings)} candidates (skipped {collision_count})")
    print()
    
    # Group by size and class for posting
    by_size_and_class = defaultdict(lambda: defaultdict(list))
    for f in findings:
        class_name = next((t for t in TARGETS if t in f['name']), "Other")
        by_size_and_class[f['size']][class_name].append(f)
    
    # Print summary by size
    print("=== Summary by Size ===")
    for size in sorted(by_size_and_class.keys()):
        total = sum(len(v) for v in by_size_and_class[size].values())
        print(f"  {size:2d}B: {total:3d} functions")
        for class_name in sorted(by_size_and_class[size].keys()):
            count = len(by_size_and_class[size][class_name])
            print(f"      {class_name:20s}: {count:2d}")
    
    print()
    
    # Output for posting to info board (batches of 15-20)
    batch_num = 1
    batch = []
    
    for size in sorted(by_size_and_class.keys()):
        for class_name in sorted(by_size_and_class[size].keys()):
            for f in by_size_and_class[size][class_name]:
                batch.append(f)
                
                if len(batch) >= 20:
                    print(f"\n=== Batch {batch_num} ({len(batch)} functions) ===")
                    for item in batch:
                        print(f"  {item['addr_hex']}  {item['size']:2d}B  {item['name']}")
                    batch_num += 1
                    batch = []
    
    # Final batch
    if batch:
        print(f"\n=== Batch {batch_num} ({len(batch)} functions) ===")
        for item in batch:
            print(f"  {item['addr_hex']}  {item['size']:2d}B  {item['name']}")
    
    # Save full results for workers
    with open("track_d_findings.json", "w") as f:
        json.dump(findings, f, indent=2)
    print(f"\n✓ Full results saved to track_d_findings.json ({len(findings)} candidates)")

if __name__ == "__main__":
    main()
