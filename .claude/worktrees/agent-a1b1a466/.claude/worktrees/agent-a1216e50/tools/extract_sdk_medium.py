#!/usr/bin/env python3
"""Extract DolphinSDK functions 65-256 bytes from the map file."""

import re

MAP_FILE = "extracted/files/u2_ngc_release_dvd.map"
SDK_LIBS = {'os.a', 'exi.a', 'si.a', 'dvd.a', 'vi.a', 'pad.a', 'ai.a', 'mtx.a', 'gx.a', 'db.a'}

with open(MAP_FILE, 'r') as f:
    lines = f.readlines()

current_lib = None
current_obj = None
symbols = []

lib_pat = re.compile(r'DolphinSDK.*?lib[/\\](\w+\.a)\((\w+\.o)\)')

for line in lines:
    ls = line.rstrip()

    # Check for SDK library file entries
    m = lib_pat.search(ls)
    if m:
        lib_name = m.group(1)
        obj_name = m.group(2)
        if lib_name in SDK_LIBS:
            addr_m = re.match(r'\s*([0-9a-fA-F]+)', ls)
            if addr_m:
                addr = int(addr_m.group(1), 16)
                if 0x80003000 <= addr <= 0x803FFFFF:
                    current_lib = lib_name
                    current_obj = obj_name
                else:
                    current_lib = None
        else:
            current_lib = None
        continue

    if current_lib:
        # Symbol lines: addr size align name
        # They start with the address (hex) at some indentation
        sm = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]+)\s+(\d+)\s+(.*)', ls)
        if sm:
            addr = int(sm.group(1), 16)
            size = int(sm.group(2), 16)
            name = sm.group(4).strip()

            # Check if this is actually a new file entry (has .o or .a or path)
            if '\\' in name or '/' in name or name.endswith('.o)'):
                if 'DolphinSDK' not in ls:
                    current_lib = None
                continue

            if 65 <= size <= 256 and 0x80003000 <= addr <= 0x803FFFFF and name:
                symbols.append((addr, size, name, current_lib, current_obj))

symbols.sort(key=lambda x: x[0])

# Deduplicate by address (some symbols may appear twice)
seen = set()
unique = []
for s in symbols:
    if s[0] not in seen:
        seen.add(s[0])
        unique.append(s)

symbols = unique
print(f"Found {len(symbols)} SDK functions in 65-256 byte range:")

# Categorize
os_funcs = []
hw_funcs = []
for s in symbols:
    addr, size, name, lib, obj = s
    if lib in ('os.a',):
        os_funcs.append(s)
    else:
        hw_funcs.append(s)

print(f"  OS functions: {len(os_funcs)}")
print(f"  HW functions: {len(hw_funcs)}")
print()
for addr, size, name, lib, obj in symbols:
    print(f"  0x{addr:08X}  size=0x{size:03X} ({size:3d})  {lib}/{obj}  {name}")
