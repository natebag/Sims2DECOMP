import os, re, collections, json

agent_dir = 'src/matched/agent/'
vd_dir = 'src/wip/version_diff/'

sda_files = []
all_agent_files = [f for f in os.listdir(agent_dir) if f.endswith('.cpp')]
for f in all_agent_files:
    path = agent_dir + f
    try:
        with open(path, 'r', encoding='utf-8', errors='ignore') as fp:
            content = fp.read()
        if 'extern char' in content or ('extern ' in content and ('lis' in content.lower() or 'addi' in content.lower())):
            sda_files.append(f)
    except Exception as e:
        pass

func_pattern = re.compile(r'//\s+0x[0-9A-Fa-f]+\s+(\S+)\s*\(')
func_info = []
for f in sda_files:
    path = agent_dir + f
    try:
        with open(path, 'r', encoding='utf-8', errors='ignore') as fp:
            first_line = fp.readline().strip()
        m = func_pattern.search(first_line)
        if m:
            func_name = m.group(1)
        else:
            func_name = f.replace('.cpp', '')
        func_info.append((func_name, f))
    except:
        func_info.append((f, f))

# Group by method name
method_files = collections.defaultdict(list)
for func_name, filename in func_info:
    parts = re.split(r'__|::', func_name)
    if len(parts) >= 2:
        method = parts[-1]
    else:
        method = func_name
    method_files[method].append((func_name, filename))

# Count total members per method in agent/
method_counts = {m: len(v) for m, v in method_files.items()}

# Cross-reference with version_diff
vd_files = [f for f in os.listdir(vd_dir) if f.endswith('.cpp')]
vd_names = []
for f in vd_files:
    base = f.replace('.cpp', '')
    m = func_pattern.search(base)
    if m:
        vd_names.append(m.group(1))
    else:
        # Try extracting after last underscore
        parts = base.split('_')
        if len(parts) >= 2:
            vd_names.append(parts[-1])
        else:
            vd_names.append(base)

vd_counter = collections.Counter(vd_names)

# Build family report
families = []
for method, count in sorted(method_counts.items(), key=lambda x: -x[1]):
    if count < 3:
        continue
    vd_count = vd_counter.get(method, 0)
    if vd_count >= 3 or count >= 10:
        families.append({
            'method': method,
            'matched_count': count,
            'version_diff_count': vd_count,
            'examples': [fn for _, fn in method_files[method][:5]],
            'total_potential': count + vd_count
        })

print(f"Total agent files: {len(all_agent_files)}")
print(f"SDA-related agent files: {len(sda_files)}")
print(f"Families with 3+ matched members: {len(families)}")
print("\nTop SDA-dependent families:")
for fam in families[:20]:
    print(f"  {fam['method']}: {fam['matched_count']} matched, {fam['version_diff_count']} in version_diff, total={fam['total_potential']}")
    print(f"    Examples: {', '.join(fam['examples'])}")

# Save detailed report
with open('sda_family_report.json', 'w') as fp:
    json.dump(families, fp, indent=2)
