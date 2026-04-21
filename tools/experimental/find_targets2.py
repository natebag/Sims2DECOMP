import json
with open('tools/all_40_64b_targets.json') as f:
    data = json.load(f)
addrs = ['801AE1E4', '801DCD88', '801DCDB4', '801DCE00']
for group_name, items in data['groups'].items():
    for item in items:
        addr = item['address'].replace('0x', '').upper()
        if addr in addrs:
            print(f"{item['address']} {item['size']} {item['name']}")
