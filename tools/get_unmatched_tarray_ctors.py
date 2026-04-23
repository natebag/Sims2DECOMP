import json

with open('tools/all_40_64b_targets.json') as f:
    data = json.load(f)

for cls, funcs in data.get('groups', {}).items():
    if 'TArray' in cls:
        for t in funcs:
            if not t.get('matched', False) and '::TArray(void)' in t['symbol']:
                print(f"{t['addr']}  {t['symbol']}")
