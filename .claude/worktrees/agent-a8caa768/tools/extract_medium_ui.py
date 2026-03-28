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

for line in lines:
    stripped = line.rstrip()
    if not stripped:
        continue

    # Try to match: addr size align name_or_path
    m = re.match(r'([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+(\d+)\s+(.*)', stripped)
    if not m:
        current_obj = None
        continue

    addr_str = m.group(1)
    size_str = m.group(2)
    align = m.group(3)
    rest = m.group(4).strip()

    try:
        size = int(size_str, 16)
    except:
        continue

    # Is this an obj file line?
    if '.obj' in rest and (BS in rest or '/' in rest):
        fname = rest.replace(BS, '/').split('/')[-1]
        fname = fname.rstrip(')')
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
        if 65 <= size <= 256:
            entry = (addr_str, size, rest)
            if entry not in results[current_obj]:
                results[current_obj].append(entry)

for obj in target_names:
    funcs = results[obj]
    if funcs:
        print(f'=== {obj} ({len(funcs)} medium functions) ===')
        for addr, size, name in funcs:
            print(f'  0x{addr} [{size:3d}] {name}')
        print()

total = sum(len(v) for v in results.values())
print(f'Total medium functions: {total}')
