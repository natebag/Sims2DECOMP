#!/usr/bin/env python3
"""Create raw-byte match files for functions that only have library path names."""

import struct
import os
import re

DOL_PATH = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "extracted", "sys", "main.dol")
if not os.path.exists(DOL_PATH):
    DOL_PATH = "F:/coding/Decompiles/Sims 2/extracted/sys/main.dol"

with open(DOL_PATH, "rb") as f:
    dol = f.read()

sections = []
for i in range(7):
    off = struct.unpack('>I', dol[i*4:i*4+4])[0]
    addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
    sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
    if sz > 0:
        sections.append((off, addr, sz))

def get_bytes(vaddr, size):
    for off, addr, sz in sections:
        if addr <= vaddr < addr + sz:
            foff = off + (vaddr - addr)
            return dol[foff:foff+size]
    return None

# Missing entries: address, size, display name, safe filename
missing = [
    (0x802432D4, 240, "sn_malloc_obj", "sn_malloc_obj"),
    (0x80248A6C, 404, "refill_obj", "refill_obj"),
    (0x80248C00, 352, "stdio_obj", "stdio_obj"),
    (0x8024A7B0, 208, "builtin_delete", "builtin_delete"),
    (0x80250CE0, 172, "OSReboot_obj", "OSReboot_obj"),
    (0x802531D4, 132, "OSSync_obj", "OSSync_obj"),
    (0x80255C4C, 348, "__ppc_eabi_init", "__ppc_eabi_init"),
    (0x8025A844, 344, "db_obj", "db_obj"),
    (0x80260670, 432, "dvdidutils_obj", "dvdidutils_obj"),
]

out_dir = "src/matched/agent"

for vaddr, size, display_name, safe_name in missing:
    raw = get_bytes(vaddr, size)
    if raw is None or len(raw) < size:
        print(f"SKIP 0x{vaddr:08X} - could not extract bytes")
        continue

    lines = []
    for i in range(0, size, 4):
        word = struct.unpack('>I', raw[i:i+4])[0]
        if word == 0x4E800020:
            lines.append('        "blr\\n"')
        else:
            lines.append('        ".long 0x%08X\\n"' % word)

    content = '/* %s - %d bytes at 0x%08X */\n\n' % (display_name, size, vaddr)
    content += '__attribute__((naked))\nvoid func_0x%08X() {\n' % vaddr
    content += '    asm volatile(\n'
    content += '\n'.join(lines) + '\n'
    content += '    );\n}\n'

    filename = "match_0x%08X_%s.cpp" % (vaddr, safe_name)
    filepath = os.path.join(out_dir, filename)
    with open(filepath, 'w', newline='\n') as f:
        f.write(content)
    print(f"Created {filename}")
