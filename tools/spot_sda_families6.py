import os, re, collections, json

agent_dir = 'src/matched/agent/'
all_matched_dir = 'src/matched/'
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
    base = re.sub(r'^match_0x[0-9A-Fa-f]+_', '', base)
    base = re.sub(r'^match_[0-9A-Fa-f]+_', '', base)
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

def extract_class(func_name):
    if '__' in func_name:
        return func_name.split('__')[0]
    if '::' in func_name:
        return func_name.split('::')[0]
    parts = func_name.split('_')
    if len(parts) > 1 and not parts[-1].startswith('0x'):
        return '_'.join(parts[:-1])
    return func_name

# Check if file has actual SDA extern declarations
def has_sda_externs(path):
    try:
        with open(path, 'r', encoding='utf-8', errors='ignore') as fp:
            content = fp.read()
        # SDA global patterns (NOT function declarations)
        # extern char gName[];
        # extern unsigned short gName[];
        # extern int gName[];
        # extern float gName[];
        # extern ETypeInfo gName;
        # extern TypeName gName[];
        patterns = [
            r'extern\s+char\s+\w+\s*\[',
            r'extern\s+unsigned\s+char\s+\w+\s*\[',
            r'extern\s+short\s+\w+\s*\[',
            r'extern\s+unsigned\s+short\s+\w+\s*\[',
            r'extern\s+int\s+\w+\s*\[',
            r'extern\s+unsigned\s+int\s+\w+\s*\[',
            r'extern\s+float\s+\w+\s*\[',
            r'extern\s+double\s+\w+\s*\[',
            r'extern\s+\w+\s+\w+_TypeInfo\b',
            r'extern\s+\w+\s+\w+_TypeName\b',
            r'extern\s+\w+\s+\w+_ParentTypeInfo\b',
            r'extern\s+char\s+g_\w+\b',
            r'extern\s+float\s+g_\w+\b',
            r'extern\s+int\s+g_\w+\b',
        ]
        for pat in patterns:
            if re.search(pat, content):
                return True
        return False
    except:
        return False

# Scan all matched files for SDA extern patterns
matched_sda_methods = collections.defaultdict(list)
matched_sda_classes = collections.defaultdict(list)

for root, dirs, files in os.walk(all_matched_dir):
    for f in files:
        if not f.endswith('.cpp'):
            continue
        path = os.path.join(root, f)
        if not has_sda_externs(path):
            continue
        func_name = extract_func_name(f, root + '/')
        method = extract_method(func_name)
        cls = extract_class(func_name)
        matched_sda_methods[method].append((func_name, f, path))
        matched_sda_classes[cls].append((func_name, f, path))

# Scan version_diff files
vd_methods = collections.defaultdict(list)
vd_classes = collections.defaultdict(list)

for f in os.listdir(vd_dir):
    if not f.endswith('.cpp'):
        continue
    func_name = extract_func_name(f, vd_dir)
    method = extract_method(func_name)
    cls = extract_class(func_name)
    vd_methods[method].append((func_name, f))
    vd_classes[cls].append((func_name, f))

print(f"Matched files with SDA externs: {sum(len(v) for v in matched_sda_methods.values())}")
print(f"Unique SDA methods: {len(matched_sda_methods)}")
print(f"Unique SDA classes: {len(matched_sda_classes)}")

# Build reports
method_families = []
for method, matched_list in matched_sda_methods.items():
    vd_list = vd_methods.get(method, [])
    if len(matched_list) < 2:
        continue
    if len(vd_list) < 1:
        continue
    method_families.append({
        'method': method,
        'matched_count': len(matched_list),
        'unmatched_count': len(vd_list),
        'total_count': len(matched_list) + len(vd_list),
        'matched_examples': [fn for _, fn, _ in matched_list[:5]],
        'vd_examples': [fn for _, fn in vd_list[:5]],
    })

method_families.sort(key=lambda x: (-x['unmatched_count'], -x['total_count']))
print(f"\n=== SDA-DEPENDENT METHOD FAMILIES ===")
print(f"Found {len(method_families)} method families with 2+ matched and 1+ unmatched")
for fam in method_families[:20]:
    print(f"\n{fam['method']}: {fam['matched_count']} matched, {fam['unmatched_count']} unmatched, total={fam['total_count']}")
    print(f"  Matched: {fam['matched_examples'][:3]}")
    print(f"  VD: {fam['vd_examples'][:3]}")

class_families = []
for cls, matched_list in matched_sda_classes.items():
    vd_list = vd_classes.get(cls, [])
    if len(matched_list) < 2:
        continue
    if len(vd_list) < 1:
        continue
    class_families.append({
        'class': cls,
        'matched_count': len(matched_list),
        'unmatched_count': len(vd_list),
        'total_count': len(matched_list) + len(vd_list),
        'matched_examples': [fn for _, fn, _ in matched_list[:5]],
        'vd_examples': [fn for _, fn in vd_list[:5]],
    })

class_families.sort(key=lambda x: (-x['unmatched_count'], -x['total_count']))
print(f"\n=== SDA-DEPENDENT CLASS FAMILIES ===")
print(f"Found {len(class_families)} class families with 2+ matched and 1+ unmatched")
for fam in class_families[:25]:
    print(f"\n{fam['class']}: {fam['matched_count']} matched, {fam['unmatched_count']} unmatched, total={fam['total_count']}")
    print(f"  Matched: {fam['matched_examples'][:3]}")
    print(f"  VD: {fam['vd_examples'][:3]}")

# Save report
with open('build/reports/sda_family_report6.json', 'w') as fp:
    json.dump({'method_families': method_families, 'class_families': class_families}, fp, indent=2)
