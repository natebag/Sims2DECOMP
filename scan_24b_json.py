import json

with open('tools/all_24b_targets.json') as f:
    data = json.load(f)

keywords = ['audio', 'sound', 'effect', 'music', 'sfx']
for entry in data:
    name = entry.get('name', '')
    if any(k in name.lower() for k in keywords):
        print(f"{entry['address']} {entry['size']}B {name}")
