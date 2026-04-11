import json
import sys

with open('tools/symbols.json', 'r') as f:
    data = json.load(f)

search_term = sys.argv[1] if len(sys.argv) > 1 else ''

for sym in data.get('symbols', []):
    name = sym.get('name', '')
    if search_term in name:
        print(f"{sym.get('address')}: {name} (size: {sym.get('size', 'unknown')})")
