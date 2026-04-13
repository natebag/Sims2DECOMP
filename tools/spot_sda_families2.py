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
    # Fallback: parse filename
    base = filename.replace('.cpp', '')
    # Remove 0xADDR_ prefix
    base = re.sub(r'^0x[0-9A-Fa-f]+_', '', base)
    return base

# Extract class name from function name
def extract_class(func_name):
    if '__' in func_name:
        return func_name.split('__')[0]
    if '::' in func_name:
        return func_name.split('::')[0]
    parts = func_name.split('_')
    if len(parts) > 1 and not parts[-1].startswith('0x'):
        # Class is everything except last method part
        return '_'.join(parts[:-1])
    return func_name

# Extract method name from function name
def extract_method(func_name):
    if '__' in func_name:
        return func_name.split('__')[-1]
    if '::' in func_name:
        return func_name.split('::')[-1]
    parts = func_name.split('_')
    if len(parts) > 1 and not parts[-1].startswith('0x'):
        return parts[-1]
    return func_name

# Check if file has SDA patterns
def has_sda_patterns(path):
    try:
        with open(path, 'r', encoding='utf-8', errors='ignore') as fp:
            content = fp.read()
        # SDA indicators
        indicators = [
            'extern char',
            'extern unsigned char',
            'extern short',
            'extern unsigned short',
            'extern int',
            'extern unsigned int',
            'extern float',
            'extern double',
            'extern void',
        ]
        for ind in indicators:
            if ind in content:
                return True
    except:
        pass
    return False

# Scan agent files
agent_files = [f for f in os.listdir(agent_dir) if f.endswith('.cpp')]
agent_sda = set()
agent_methods = collections.defaultdict(list)  # method -> [(func_name, filename)]
agent_classes = collections.defaultdict(list)  # class -> [(func_name, filename)]

for f in agent_files:
    func_name = extract_func_name(f, agent_dir)
    method = extract_method(func_name)
    cls = extract_class(func_name)
    agent_methods[method].append((func_name, f))
    agent_classes[cls].append((func_name, f))
    if has_sda_patterns(agent_dir + f):
        agent_sda.add(method)
        agent_sda.add(cls)

# Scan version_diff files
vd_files = [f for f in os.listdir(vd_dir) if f.endswith('.cpp')]
vd_methods = collections.defaultdict(list)
vd_classes = collections.defaultdict(list)

for f in vd_files:
    func_name = extract_func_name(f, vd_dir)
    method = extract_method(func_name)
    cls = extract_class(func_name)
    vd_methods[method].append((func_name, f))
    vd_classes[cls].append((func_name, f))

print(f"Agent files: {len(agent_files)}")
print(f"Agent SDA methods/classes: {len(agent_sda)}")
print(f"VD files: {len(vd_files)}")

# Find method families where agent has SDA + multiple members + VD has unmatched
method_families = []
for method, agent_list in agent_methods.items():
    if method not in agent_sda:
        continue
    vd_list = vd_methods.get(method, [])
    total = len(agent_list) + len(vd_list)
    if total >= 5 and len(vd_list) >= 1:
        method_families.append({
            'type': 'method',
            'name': method,
            'matched': len(agent_list),
            'unmatched': len(vd_list),
            'total': total,
            'agent_examples': [fn for _, fn in agent_list[:3]],
            'vd_examples': [fn for _, fn in vd_list[:3]],
        })

# Find class families where agent has SDA + multiple members + VD has unmatched
class_families = []
for cls, agent_list in agent_classes.items():
    if cls not in agent_sda:
        continue
    vd_list = vd_classes.get(cls, [])
    total = len(agent_list) + len(vd_list)
    if total >= 5 and len(vd_list) >= 1:
        class_families.append({
            'type': 'class',
            'name': cls,
            'matched': len(agent_list),
            'unmatched': len(vd_list),
            'total': total,
            'agent_examples': [fn for _, fn in agent_list[:3]],
            'vd_examples': [fn for _, fn in vd_list[:3]],
        })

# Sort by unmatched count desc, then total desc
method_families.sort(key=lambda x: (-x['unmatched'], -x['total']))
class_families.sort(key=lambda x: (-x['unmatched'], -x['total']))

print(f"\nMethod families with SDA + unmatched in VD: {len(method_families)}")
for fam in method_families[:15]:
    print(f"  {fam['name']}: {fam['matched']} matched, {fam['unmatched']} unmatched, total={fam['total']}")

print(f"\nClass families with SDA + unmatched in VD: {len(class_families)}")
for fam in class_families[:15]:
    print(f"  {fam['name']}: {fam['matched']} matched, {fam['unmatched']} unmatched, total={fam['total']}")

# Save report
report = {
    'method_families': method_families,
    'class_families': class_families,
}
with open('sda_family_report2.json', 'w') as fp:
    json.dump(report, fp, indent=2)
