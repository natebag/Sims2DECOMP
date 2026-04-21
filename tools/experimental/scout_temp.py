import json

priority_keywords = ['ehouse', 'neighborhood', 'csimulator', 'esim', 'cas', 'bbi', 'behavior', 'interaction', 'xroute', 'route']

for jsonfile in ['tools/all_24b_targets.json', 'tools/all_40_64b_targets.json', 'tools/all_64_128b_targets.json']:
    with open(jsonfile) as f:
        data = json.load(f)
    print(f'=== {jsonfile} ===')
    for group_name, funcs in data['groups'].items():
        lower = group_name.lower()
        if any(x in lower for x in priority_keywords):
            if len(funcs) >= 3:
                print(f'{group_name}: {len(funcs)} functions')
                for func in funcs[:3]:
                    print(f'  {func["addr"]} {func["symbol"]}')
    print()
