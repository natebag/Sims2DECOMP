import json
import re
import subprocess
from pathlib import Path

with open('build/reports/wall_classification.json') as f:
    data = json.load(f)

UNKNOWN = data['UNKNOWN']
NO_ADDRESS = data['NO_ADDRESS']

# Try to get sizes for NO_ADDRESS files from the map
map_sizes = {}
map_path = Path('extracted/files/u2_ngc_release.map')
if map_path.exists():
    for line in map_path.read_text(errors='ignore').splitlines():
        m = re.search(r'(0x[0-9A-Fa-f]{8})\s+\S+\s+(\d+)', line)
        if m:
            addr = m.group(1).lower()
            map_sizes[addr] = int(m.group(2))

print("=== Reclassifying UNKNOWN files ===")
new_counts = {}
examples = {}

for item in UNKNOWN[:30]:
    addr = item['addr']
    size = item['size']
    filepath = Path('src/wip/version_diff') / item['file']
    if not addr or not size:
        continue
    
    try:
        result = subprocess.run(
            ['bash', 'tools/verify_match.sh', str(filepath), addr, str(size)],
            capture_output=True, text=True, timeout=30
        )
    except Exception as e:
        continue
    
    combined = result.stdout + result.stderr
    
    # Classify from actual diff
    wall = "UNKNOWN"
    if "DOL length" in combined and "Compiled length" in combined:
        wall = "SIZE_MISMATCH"
    elif "beqlr" in combined.lower() or "bnelr" in combined.lower():
        wall = "BRANCH_STRUCTURE"
    elif "f0" in combined or "f13" in combined:
        wall = "FP_ALTERNATION"
    elif "stwu" in combined.lower() and "r1" in combined.lower():
        wall = "FRAME_SIZE"
    elif "mr " in combined.lower():
        wall = "REGISTER_ALLOCATION"
    elif "sda21" in combined.lower() or "r13" in combined.lower():
        wall = "SDA_R13"
    elif "vtable" in combined.lower():
        wall = "VTABLE_SCHEDULING"
    
    new_counts[wall] = new_counts.get(wall, 0) + 1
    if wall not in examples:
        examples[wall] = []
    examples[wall].append((item['file'], addr, size))

print("Sample reclassification results (30 files):")
for wall, count in sorted(new_counts.items(), key=lambda x: -x[1]):
    print(f"  {wall}: {count}")
    for ex in examples[wall][:3]:
        print(f"    - {ex[0]} @ {ex[1]} ({ex[2]}b)")

print("\n=== NO_ADDRESS size lookups ===")
found = 0
for item in NO_ADDRESS[:20]:
    addr = item['addr']
    if addr and addr.lower() in map_sizes:
        print(f"  {item['file']} @ {addr} -> {map_sizes[addr.lower()]}b")
        found += 1
    else:
        print(f"  {item['file']} @ {addr} -> NOT FOUND")

print(f"\nFound sizes for {found}/20 NO_ADDRESS files")
