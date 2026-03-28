import re
import sys

with open('extracted/files/u2_ngc_release_dvd.map', 'r') as f:
    lines = f.readlines()

target_libs = ['os.a', 'dvd.a', 'gx.a', 'mtx.a', 'vi.a', 'pad.a', 'exi.a', 'si.a', 'ai.a', 'db.a']

current_lib = None
current_obj = None
sdk_funcs = []

pat_libobj = re.compile(r'lib[/\\]([\w.]+)\(([\w.]+)\)')

for line in lines:
    line = line.rstrip()
    m = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]{8})\s+\d+\s+(.+)$', line)
    if m:
        addr_str, size_str, path = m.group(1), m.group(2), m.group(3).strip()
        if 'DolphinSDK1.0' in path:
            if any(lib in path for lib in target_libs):
                lib_match = pat_libobj.search(path)
                if lib_match:
                    current_lib = lib_match.group(1)
                    current_obj = lib_match.group(2)
            else:
                current_lib = None
                current_obj = None
            continue
        elif '.o)' in path or '.obj)' in path or '<default>' in path:
            current_lib = None
            current_obj = None
            continue

    if current_lib:
        sm = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]{8})\s+\d+\s+(.+)$', line)
        if sm:
            addr = int(sm.group(1), 16)
            size = int(sm.group(2), 16)
            name = sm.group(3).strip()
            # .text section functions only
            if size >= 0x101 and size <= 0x400 and addr >= 0x80003100 and addr < 0x80400000:
                sdk_funcs.append((addr, size, name, current_lib, current_obj))

sdk_funcs.sort(key=lambda x: (x[3], x[0]))

print(f'Total functions 257-1024 bytes: {len(sdk_funcs)}')
print()
for addr, size, name, lib, obj in sdk_funcs:
    print(f'{addr:08x} {size:04x} {lib:10s} {obj:25s} {name}')
