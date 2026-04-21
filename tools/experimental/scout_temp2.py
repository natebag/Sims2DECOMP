import json, os, subprocess, re

# Load target data
target_groups = {}
for jsonfile in ['tools/all_24b_targets.json', 'tools/all_40_64b_targets.json', 'tools/all_64_128b_targets.json']:
    with open(jsonfile) as f:
        data = json.load(f)
    for group_name, funcs in data['groups'].items():
        if group_name not in target_groups:
            target_groups[group_name] = []
        for func in funcs:
            func['source'] = jsonfile
        target_groups[group_name].extend(funcs)

# Find groups with 5+ unmatched functions
large_groups = {k: v for k, v in target_groups.items() if len(v) >= 5}

# Check matched counts for each group
for group_name, funcs in sorted(large_groups.items(), key=lambda x: -len(x[1])):
    # Count how many are already matched
    matched = 0
    for func in funcs:
        addr = func['addr'].replace('0x', '')
        # Check src/matched for this address
        for root, dirs, files in os.walk('src/matched'):
            for f in files:
                if addr.lower() in f.lower():
                    matched += 1
                    break
            else:
                continue
            break
    
    if matched < len(funcs) and len(funcs) - matched >= 5:
        print(f"{group_name}: {len(funcs)} total, {matched} matched, {len(funcs)-matched} remaining")
        for func in funcs[:5]:
            print(f"  {func['addr']} {func['symbol']} ({func['source']})")
        if len(funcs) > 5:
            print(f"  ... and {len(funcs)-5} more")
