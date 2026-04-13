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

def extract_method(func_name):
    if '__' in func_name:
        return func_name.split('__')[-1]
    if '::' in func_name:
        return func_name.split('::')[-1]
    parts = func_name.split('_')
    if len(parts) > 1 and not parts[-1].startswith('0x'):
        return parts[-1]
    return func_name

# Check if file has SDA-related content
def has_sda_content(path):
    try:
        with open(path, 'r', encoding='utf-8', errors='ignore') as fp:
            content = fp.read()
        # SDA C++ patterns
        if 'extern char' in content or 'extern unsigned char' in content:
            return 'extern_char'
        if 'extern short' in content or 'extern unsigned short' in content:
            return 'extern_short'
        if 'extern int' in content or 'extern unsigned int' in content:
            return 'extern_int'
        if 'extern float' in content or 'extern double' in content:
            return 'extern_float'
        # Assembly comment patterns (common in version_diff)
        if re.search(r'lis\s+r\d+,\s*0x804[0-9a-fA-F]', content):
            return 'lis_804x'
        if re.search(r'lwz\s+r\d+,\s*-?\d+\(r13\)', content):
            return 'r13_relative'
        if re.search(r'addi\s+r\d+,\s*r\d+,\s*', content) and 'lis' in content:
            return 'lis_addi'
        return None
    except:
        return None

# Scan version_diff files for SDA patterns
vd_files = [f for f in os.listdir(vd_dir) if f.endswith('.cpp')]
vd_sda_methods = collections.defaultdict(list)
vd_sda_classes = collections.defaultdict(list)

for f in vd_files:
    sda_type = has_sda_content(vd_dir + f)
    if sda_type:
        func_name = extract_func_name(f, vd_dir)
        method = extract_method(func_name)
        cls_parts = func_name.split('_')
        if len(cls_parts) > 1:
            cls = '_'.join(cls_parts[:-1])
        else:
            cls = func_name
        vd_sda_methods[(method, sda_type)].append((func_name, f))
        vd_sda_classes[(cls, sda_type)].append((func_name, f))

# Scan agent files for matching families
agent_files = [f for f in os.listdir(agent_dir) if f.endswith('.cpp')]
agent_methods = collections.defaultdict(list)
agent_classes = collections.defaultdict(list)

for f in agent_files:
    func_name = extract_func_name(f, agent_dir)
    method = extract_method(func_name)
    cls_parts = func_name.split('_')
    if len(cls_parts) > 1:
        cls = '_'.join(cls_parts[:-1])
    else:
        cls = func_name
    agent_methods[method].append((func_name, f))
    agent_classes[cls].append((func_name, f))

# Build family report
print("=== SDA-DEPENDENT FAMILIES IN version_diff ===\n")

method_families = []
for (method, sda_type), vd_list in vd_sda_methods.items():
    if len(vd_list) < 3:
        continue
    agent_list = agent_methods.get(method, [])
    method_families.append({
        'pattern_type': sda_type,
        'method': method,
        'unmatched_count': len(vd_list),
        'matched_count': len(agent_list),
        'vd_examples': [fn for _, fn in vd_list[:5]],
        'agent_examples': [fn for _, fn in agent_list[:3]],
    })

method_families.sort(key=lambda x: -x['unmatched_count'])

print(f"Method families with 3+ unmatched SDA members: {len(method_families)}")
for fam in method_families[:20]:
    print(f"\n{fam['method']} [{fam['pattern_type']}]: {fam['unmatched_count']} unmatched, {fam['matched_count']} matched")
    print(f"  VD examples: {fam['vd_examples'][:3]}")
    print(f"  Agent examples: {fam['agent_examples'][:3]}")

class_families = []
for (cls, sda_type), vd_list in vd_sda_classes.items():
    if len(vd_list) < 3:
        continue
    agent_list = agent_classes.get(cls, [])
    class_families.append({
        'pattern_type': sda_type,
        'class': cls,
        'unmatched_count': len(vd_list),
        'matched_count': len(agent_list),
        'vd_examples': [fn for _, fn in vd_list[:5]],
        'agent_examples': [fn for _, fn in agent_list[:3]],
    })

class_families.sort(key=lambda x: -x['unmatched_count'])

print(f"\n\nClass families with 3+ unmatched SDA members: {len(class_families)}")
for fam in class_families[:20]:
    print(f"\n{fam['class']} [{fam['pattern_type']}]: {fam['unmatched_count']} unmatched, {fam['matched_count']} matched")
    print(f"  VD examples: {fam['vd_examples'][:3]}")
    print(f"  Agent examples: {fam['agent_examples'][:3]}")

with open('sda_family_report4.json', 'w') as fp:
    json.dump({'method_families': method_families, 'class_families': class_families}, fp, indent=2)
