import json
import os

# Load matched addresses from filenames
matched_addrs = set()
for root, dirs, files in os.walk('src/matched'):
    for f in files:
        if f.endswith('.cpp'):
            # extract addr from filename like match_0x801B070C_FAMTarget...
            import re
            m = re.search(r'0x([0-9a-fA-F]{8})', f)
            if m:
                matched_addrs.add(m.group(1).lower())
            else:
                m = re.search(r'([0-9a-fA-F]{8})', f)
                if m:
                    matched_addrs.add(m.group(1).lower())

with open('tools/all_64_128b_targets.json') as f:
    data = json.load(f)

for group_name, entries in data['groups'].items():
    if group_name not in ['FAMTarget', 'HUDTarget', 'E2ETarget']:
        continue
    unmatched = []
    for entry in entries:
        addr = entry['addr'].lower().replace('0x', '')
        if addr not in matched_addrs:
            unmatched.append((entry['addr'], entry['symbol']))
    print(f"\n[{group_name}] — {len(unmatched)} unmatched")
    for addr, sym in unmatched:
        print(f"  {addr}  {sym}")
