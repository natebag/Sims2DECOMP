import json
import os
import re

# Load matched addresses from src/matched/
matched_addrs = set()
for root, dirs, files in os.walk('src/matched'):
    for f in files:
        if f.endswith('.cpp'):
            path = os.path.join(root, f)
            with open(path) as fp:
                content = fp.read()
                for m in re.finditer(r'0x[0-9a-fA-F]{8}', content):
                    matched_addrs.add(m.group(0).lower())

with open('tools/all_40_64b_targets.json') as f:
    data = json.load(f)

matched = []
unmatched = []
for group_name, entries in data['groups'].items():
    for entry in entries:
        addr = entry['addr'].lower()
        sym = entry['symbol']
        if any(t in sym for t in ['R2LTarget', 'H2DTarget', 'E2ETarget']):
            if addr in matched_addrs:
                matched.append((addr, sym))
            else:
                unmatched.append((addr, sym))

print(f"Matched: {len(matched)}")
print(f"Unmatched: {len(unmatched)}")
for addr, sym in unmatched:
    print(f"  {addr}  {sym}")
