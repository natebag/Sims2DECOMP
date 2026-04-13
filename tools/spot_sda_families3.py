import os, re, collections, json

agent_dir = 'src/matched/agent/'
vd_dir = 'src/wip/version_diff/'

# Extract function name from filename or header
def extract_func_name(filename, base_dir):
    path = base_dir + filename
    func_pattern = re.compile(r'//\s+0x[0-9A-Fa-f]+\s+(\S+)\s*\(')
    try:
        with open(path, 'r', encoding='utf-8', errors='ignore') as fp:
            first_line = fp.readline().strip()
        m = func_pattern.search(first_line)
        if m:
            return m.group(1)
    except:
        pass
    base = filename.replace('.cpp', '')
    base = re.sub(r'^0x[0-9A-Fa-f]+_', '', base)
    return base

# Extract method name
def extract_method(func_name):
    if '__' in func_name:
        return func_name.split('__')[-1]
    if '::' in func_name:
        return func_name.split('::')[-1]
    parts = func_name.split('_')
    if len(parts) > 1 and not parts[-1].startswith('0x'):
        return parts[-1]
    return func_name

# Extract extern declarations from file
extern_pattern = re.compile(r'extern\s+\w+\s+(\w+)\s*\[')
def extract_externs(path):
    try:
        with open(path, 'r', encoding='utf-8', errors='ignore') as fp:
            content = fp.read()
        return set(extern_pattern.findall(content))
    except:
        return set()

# Scan agent files
agent_files = [f for f in os.listdir(agent_dir) if f.endswith('.cpp')]
agent_externs = collections.defaultdict(list)  # extern_name -> [(func_name, filename)]
agent_methods = collections.defaultdict(list)  # method -> [(func_name, filename, externs)]

for f in agent_files:
    func_name = extract_func_name(f, agent_dir)
    method = extract_method(func_name)
    externs = extract_externs(agent_dir + f)
    if externs:
        agent_methods[method].append((func_name, f, externs))
        for e in externs:
            agent_externs[e].append((func_name, f))

# Scan version_diff files
vd_files = [f for f in os.listdir(vd_dir) if f.endswith('.cpp')]
vd_methods = collections.defaultdict(list)
for f in vd_files:
    func_name = extract_func_name(f, vd_dir)
    method = extract_method(func_name)
    vd_methods[method].append((func_name, f))

# Find method families with SDA externs + unmatched in VD
families = []
for method, agent_list in agent_methods.items():
    vd_list = vd_methods.get(method, [])
    total = len(agent_list) + len(vd_list)
    if len(agent_list) >= 3 and total >= 5:
        # Get common externs across the family
        common_externs = None
        for _, _, externs in agent_list:
            if common_externs is None:
                common_externs = set(externs)
            else:
                common_externs &= externs
        families.append({
            'method': method,
            'matched_count': len(agent_list),
            'unmatched_count': len(vd_list),
            'total_count': total,
            'common_externs': list(common_externs) if common_externs else [],
            'agent_examples': [fn for _, fn, _ in agent_list[:5]],
            'vd_examples': [fn for _, fn in vd_list[:5]],
        })

families.sort(key=lambda x: (-x['unmatched_count'], -x['total_count']))

print(f"SDA method families with 3+ matched and 5+ total members:")
for fam in families[:25]:
    print(f"\n{fam['method']}: {fam['matched_count']} matched, {fam['unmatched_count']} unmatched, total={fam['total_count']}")
    print(f"  Common externs: {fam['common_externs'][:5]}")
    print(f"  Agent examples: {fam['agent_examples'][:3]}")
    print(f"  VD examples: {fam['vd_examples'][:3]}")

# Also report by extern variable clusters
extern_clusters = []
for extern_name, files in agent_externs.items():
    if len(files) >= 5:
        extern_clusters.append({
            'extern_name': extern_name,
            'matched_count': len(files),
            'examples': [fn for _, fn in files[:5]],
        })
extern_clusters.sort(key=lambda x: -x['matched_count'])

print(f"\n\nTop extern variable clusters in agent/:")
for cl in extern_clusters[:20]:
    print(f"  {cl['extern_name']}: {cl['matched_count']} files")
    print(f"    Examples: {cl['examples'][:3]}")

with open('sda_family_report3.json', 'w') as fp:
    json.dump({'method_families': families, 'extern_clusters': extern_clusters}, fp, indent=2)
