import json, subprocess, sys, re, collections

def get_mnemonics(addr):
    try:
        result = subprocess.run([sys.executable, 'tools/disasm_func.py', addr], capture_output=True, text=True)
        lines = result.stdout.split('\n')
        mnems = []
        for line in lines:
            if not line.strip() or line.startswith('//') or line.startswith('Symbol references'):
                continue
            parts = line.split('\t')
            if len(parts) >= 3:
                mnem = parts[2].strip().split()[0] if parts[2].strip().split() else ''
                mnems.append(mnem)
        return tuple(mnems)
    except Exception:
        return ()

# Load all targets
all_groups = {}
for jsonfile in ['tools/all_24b_targets.json', 'tools/all_40_64b_targets.json', 'tools/all_64_128b_targets.json']:
    with open(jsonfile) as f:
        data = json.load(f)
    for group_name, funcs in data['groups'].items():
        if group_name not in all_groups:
            all_groups[group_name] = []
        for func in funcs:
            func['source'] = jsonfile
        all_groups[group_name].extend(funcs)

# For each group with 5+ remaining unmatched, cluster by mnemonic sequence
print("Scanning for template sub-families...\n")

for group_name, funcs in sorted(all_groups.items(), key=lambda x: -len(x[1])):
    if len(funcs) < 5:
        continue
    
    # Get mnemonics for all functions
    seq_to_funcs = collections.defaultdict(list)
    for func in funcs:
        mnems = get_mnemonics(func['addr'])
        if mnems:
            seq_to_funcs[mnems].append(func)
    
    # Report clusters of 3+ with identical mnemonic sequences
    for seq, cluster in sorted(seq_to_funcs.items(), key=lambda x: -len(x[1])):
        if len(cluster) >= 3:
            print(f"FAMILY: {group_name} --- {len(cluster)} functions with identical {len(seq)}-insn layout")
            for func in cluster:
                print(f"  {func['addr']} {func['symbol']}")
            print()
