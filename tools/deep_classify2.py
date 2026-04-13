import json
import re
import subprocess
from pathlib import Path

with open('wall_classification.json') as f:
    data = json.load(f)

UNKNOWN = data['UNKNOWN']
NO_ADDRESS = data['NO_ADDRESS']

def run_verify(filepath, addr, size):
    try:
        result = subprocess.run(
            ['bash', 'tools/verify_match.sh', str(filepath), addr, str(size)],
            capture_output=True, text=True, timeout=30
        )
        return result.stdout + result.stderr
    except Exception as e:
        return str(e)

def classify_from_diff(combined):
    combined_lower = combined.lower()
    
    if "match!" in combined_lower:
        return "MATCH"
    
    if "dol length" in combined_lower and "compiled length" in combined_lower:
        return "SIZE_MISMATCH"
    
    # Look for branch structure patterns in mismatch offsets
    if any(x in combined_lower for x in ["beqlr", "bnelr", "blelr", "bgtlr"]):
        return "BRANCH_STRUCTURE"
    
    # Check for store ordering: same instructions but different offset values in stw
    # Pattern: stw rN, X(rM) vs stw rN, Y(rM) with same opcode
    mismatch_lines = [l for l in combined.splitlines() if "MISMATCH" in l or "offset" in l.lower()]
    if mismatch_lines:
        # If all mismatches are in immediate fields of stores, it's store order
        store_mismatch = False
        other_mismatch = False
        for line in combined.splitlines():
            if line.strip().startswith("offset"):
                # Extract the instruction bytes
                parts = line.split()
                if len(parts) >= 4:
                    dol_bytes = parts[2]
                    comp_bytes = parts[4]
                    # If only the immediate (last 2 bytes) differs, and it's a store
                    if len(dol_bytes) == 8 and len(comp_bytes) == 8:
                        if dol_bytes[:4] == comp_bytes[:4] and dol_bytes[:2] in ['90', '91', '92', '93', '94', '95', '96', '97', '98', '99', '9a', '9b', '9c', '9d', '9e', '9f']:
                            store_mismatch = True
                        elif dol_bytes[:4] != comp_bytes[:4]:
                            other_mismatch = True
        if store_mismatch and not other_mismatch:
            return "STORE_ORDER"
    
    if "mr " in combined_lower:
        return "REGISTER_ALLOCATION"
    
    if any(x in combined for x in ["f0", "f13", "fmadd", "fmuls", "fadds"]):
        return "FP_ALTERNATION"
    
    if "stwu" in combined_lower:
        return "FRAME_SIZE"
    
    if "sda21" in combined_lower or "r13" in combined_lower:
        return "SDA_R13"
    
    if "vtable" in combined_lower:
        return "VTABLE_SCHEDULING"
    
    return "UNKNOWN"

print("=== Reclassifying ALL UNKNOWN files ===")
new_counts = {}
examples = {}

for item in UNKNOWN:
    addr = item['addr']
    size = item['size']
    filepath = Path('src/wip/version_diff') / item['file']
    if not addr or not size:
        continue
    
    combined = run_verify(filepath, addr, size)
    wall = classify_from_diff(combined)
    
    new_counts[wall] = new_counts.get(wall, 0) + 1
    if wall not in examples:
        examples[wall] = []
    examples[wall].append((item['file'], addr, size))

for wall, count in sorted(new_counts.items(), key=lambda x: -x[1]):
    print(f"\n{wall}: {count}")
    for ex in examples[wall][:5]:
        print(f"  - {ex[0]} @ {ex[1]} ({ex[2]}b)")

# Update JSON with reclassified data
for wall, items in examples.items():
    if wall == "UNKNOWN":
        continue
    # Remove from UNKNOWN and add to proper category
    data['UNKNOWN'] = [x for x in data['UNKNOWN'] if x['file'] not in {i[0] for i in items}]
    for fname, addr, size in items:
        data[wall].append({"file": fname, "addr": addr, "size": size})

# Reclassify NO_ADDRESS based on content
print("\n=== Reclassifying NO_ADDRESS files by content ===")
no_addr_counts = {}
for item in NO_ADDRESS:
    filepath = Path('src/wip/version_diff') / item['file']
    try:
        text = filepath.read_text(errors='ignore').lower()
    except:
        continue
    
    wall = "NO_ADDRESS"
    if 'compilation error' in text or 'does not compile' in text:
        wall = "COMPILATION_ERROR"
    elif 'r13' in text or 'sda' in text:
        wall = "SDA_R13"
    elif 'vtable' in text:
        wall = "VTABLE_SCHEDULING"
    elif 'schedule' in text or 'store order' in text:
        wall = "STORE_ORDER"
    elif 'branch' in text or 'beqlr' in text:
        wall = "BRANCH_STRUCTURE"
    elif 'size mismatch' in text:
        wall = "SIZE_MISMATCH"
    elif 'init_hardware' in item['file'].lower() or 'operator_lt' in item['file'].lower() or 'wcscmp' in item['file'].lower():
        wall = "SDK_OR_STDLIB"
    
    if wall not in data:
        data[wall] = []
    if wall != "NO_ADDRESS":
        data['NO_ADDRESS'] = [x for x in data['NO_ADDRESS'] if x['file'] != item['file']]
        data[wall].append(item)
    
    no_addr_counts[wall] = no_addr_counts.get(wall, 0) + 1

print("NO_ADDRESS reclassification:")
for wall, count in sorted(no_addr_counts.items(), key=lambda x: -x[1]):
    print(f"  {wall}: {count}")

with open('wall_classification.json', 'w') as f:
    json.dump(data, f, indent=2)

print("\n=== FINAL COUNTS ===")
total = sum(len(v) for v in data.values())
for cat in ['SIZE_MISMATCH', 'REGISTER_ALLOCATION', 'BRANCH_STRUCTURE', 'FP_ALTERNATION', 
            'FRAME_SIZE', 'STORE_ORDER', 'COMPILATION_ERROR', 'SDA_R13', 'VTABLE_SCHEDULING',
            'CTOR_EPILOGUE', 'SDK_OR_STDLIB', 'UNKNOWN', 'NO_ADDRESS', 'OTHER']:
    if cat in data and data[cat]:
        count = len(data[cat])
        pct = count / total * 100
        print(f"{cat}: {count} ({pct:.1f}%)")
print(f"TOTAL: {total}")
