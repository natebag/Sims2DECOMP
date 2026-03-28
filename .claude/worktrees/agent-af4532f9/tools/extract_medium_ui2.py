import re

BS = chr(92)  # backslash

with open('extracted/files/u2_ngc_release_dvd.map', 'r', errors='replace') as f:
    lines = f.readlines()

target_names = ['wrapper.obj', 'targets_s2c.obj', 'targets_tsc3.obj',
               'AptValue.cpp.obj', 'AptCharacter.cpp.obj', 'AptActionInterpreter.cpp.obj',
               'AptDisplayList.cpp.obj', 'uibase.obj', 'uicore.obj', 'uidraw.obj',
               'dlgwrapper.obj', 'mustates.obj']

results = {t: [] for t in target_names}
current_obj = None

def extract_obj_name(path):
    """Extract the .obj filename from a path, handling libfoo.a(Bar.obj) format."""
    # Handle library archive format: libfoo.a(Bar.cpp.obj)
    m = re.search(r'\(([^)]+\.obj)\)', path)
    if m:
        return m.group(1)
    # Regular path
    fname = path.replace(BS, '/').split('/')[-1]
    return fname

for line in lines:
    stripped = line.rstrip()
    if not stripped:
        continue

    m = re.match(r'([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+(\d+)\s+(.*)', stripped)
    if not m:
        current_obj = None
        continue

    addr_str = m.group(1)
    size_str = m.group(2)
    rest = m.group(4).strip()

    try:
        size = int(size_str, 16)
    except:
        continue

    # Is this an obj file line?
    if '.obj' in rest and (BS in rest or '/' in rest or '.a(' in rest):
        fname = extract_obj_name(rest)
        matched = None
        for t in target_names:
            if fname == t:
                matched = t
                break
        if matched:
            current_obj = matched
        else:
            current_obj = None
        continue

    # Symbol line
    if current_obj and size > 0 and rest:
        if 'virtual table' in rest or 'wordlist' in rest or 'lookup.' in rest:
            continue
        if 65 <= size <= 256:
            entry = (addr_str, size, rest)
            if entry not in results[current_obj]:
                results[current_obj].append(entry)

for obj in target_names:
    funcs = results[obj]
    if funcs:
        text_funcs = [(a, s, n) for a, s, n in funcs if a.startswith('80') and int(a, 16) < 0x803d0000]
        template_funcs = [(a, s, n) for a, s, n in funcs if a.startswith('80') and int(a, 16) >= 0x803d0000]
        print(f'=== {obj}: {len(text_funcs)} code + {len(template_funcs)} template ===')
        for addr, size, name in text_funcs:
            print(f'  CODE 0x{addr} [{size:3d}] {name}')
        for addr, size, name in template_funcs:
            print(f'  TMPL 0x{addr} [{size:3d}] {name}')
        print()

total = sum(len(v) for v in results.values())
print(f'Total medium functions: {total}')
