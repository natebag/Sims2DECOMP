import json
with open('wall_classification.json') as f:
    data = json.load(f)

for cat in ['UNKNOWN', 'NO_ADDRESS']:
    print(f"\n=== {cat} ({len(data[cat])} files) ===")
    for item in data[cat][:15]:
        size_str = f"{item['size']}b" if item['size'] else "?"
        print(f"  {item['file']} @ {item['addr']} ({size_str})")
