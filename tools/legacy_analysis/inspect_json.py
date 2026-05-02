import json

with open('tools/all_24b_targets.json') as f:
    data = json.load(f)

keywords = ['audio', 'sound', 'effect', 'music', 'sfx']
found = 0
for group_name, entries in data['groups'].items():
    for entry in entries:
        name = entry.get('name', '')
        if any(k in name.lower() for k in keywords):
            print(f"{group_name}: {entry['address']} {entry['size']}B {name}")
            found += 1
            if found >= 50:
                break
    if found >= 50:
        break

print(f"\nTotal found: {found}")
