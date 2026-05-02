#!/usr/bin/env python3
import re, json
from pathlib import Path
from collections import defaultdict

REPO = Path(r"F:\coding\Decompiles\Sims 2")
MAP_FILE = REPO / "extracted" / "files" / "u2_ngc_release.map"
MATCHED_DIR = REPO / "src" / "matched"
TARGETS = ["ERoom", "ENeighborhood", "EHouse", "GoalUnlock", "Careers", "Skill", "cSimulatorImpl", "ERLevel", "ERModel", "ENgcRenderer"]

def parse_map():
    functions = {}
    with open(MAP_FILE, 'r', encoding='utf-8', errors='replace') as f:
        for line in f:
            m = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+(\d+)\s+(.+)$', line)
            if not m or '::' not in m.group(4):
                continue
            addr, size, name = int(m.group(1), 16), int(m.group(2), 16), m.group(4).strip()
            if any(t in name for t in TARGETS) and 16 <= size <= 64:
                functions[addr] = (name, size)
    return functions

def check_collision(addr):
    for pattern in [f"*{addr:08X}*", f"*{addr:08x}*", f"*{addr:X}*"]:
        if list(MATCHED_DIR.glob(pattern)):
            return True
    return False

functions = parse_map()
print(f"[OK] Found {len(functions)} unmatched in targets (16-64B)")
findings = [{'addr': addr, 'addr_hex': f'0x{addr:08X}', 'size': size, 'name': name}
            for addr, (name, size) in sorted(functions.items()) if not check_collision(addr)]
print(f"[OK] {len(findings)} after collision check")
with open("track_d_findings.json", "w") as f:
    json.dump(findings, f, indent=2)
print(f"[OK] Results saved to track_d_findings.json")
