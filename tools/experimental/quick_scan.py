import json, subprocess, sys, collections

def get_mnems(addr):
    try:
        result = subprocess.run([sys.executable, 'tools/disasm_func.py', addr], capture_output=True, text=True)
        mnems = []
        for line in result.stdout.split('\n'):
            if not line.strip() or line.startswith('//') or line.startswith('Symbol references'):
                continue
            parts = line.split('\t')
            if len(parts) >= 3:
                mnems.append(parts[2].strip().split()[0] if parts[2].strip().split() else '')
        return tuple(mnems)
    except:
        return ()

for jsonfile in ['tools/all_40_64b_targets.json', 'tools/all_64_128b_targets.json']:
    with open(jsonfile) as f:
        data = json.load(f)
    for group_name in ['ESimsCam', 'cSimulatorImpl', 'NeighborhoodImpl', 'EyeToyClient']:
        if group_name not in data['groups']:
            continue
        funcs = data['groups'][group_name]
        seq_to_funcs = collections.defaultdict(list)
        for func in funcs:
            mnems = get_mnems(func['addr'])
            if mnems:
                seq_to_funcs[mnems].append(func)
        for seq, cluster in sorted(seq_to_funcs.items(), key=lambda x: -len(x[1])):
            if len(cluster) >= 2:
                print(group_name + ': ' + str(len(cluster)) + ' functions, ' + str(len(seq)) + ' insns')
                for func in cluster:
                    print('  ' + func['addr'] + ' ' + func['symbol'])
                print()
