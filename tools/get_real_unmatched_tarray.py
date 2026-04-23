import json, os, re

with open('tools/all_40_64b_targets.json') as f:
    data = json.load(f)

matched_files = set()
for root, dirs, files in os.walk('src/matched'):
    for f in files:
        if f.endswith('.cpp'):
            m = re.search(r'[0-9a-fA-F]{8}', f)
            if m:
                matched_files.add(m.group(0).lower())

for cls, funcs in data.get('groups', {}).items():
    if 'TArray' in cls:
        for t in funcs:
            addr = t['addr'].replace('0x', '').lower()
            if addr not in matched_files:
                print(f"{t['addr']}  {t['symbol']}")
