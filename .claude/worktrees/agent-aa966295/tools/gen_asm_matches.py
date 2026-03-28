#!/usr/bin/env python3
"""Generate inline asm match files for functions in a given address range."""

import struct
import re
import os
import sys

DOL_PATH = "extracted/sys/main.dol"
MAP_PATH = "extracted/files/u2_ngc_release_dvd.map"

def read_dol():
    with open(DOL_PATH, "rb") as f:
        return f.read()

def vaddr_to_offset(dol, vaddr):
    for i in range(7):
        off = struct.unpack('>I', dol[i*4:i*4+4])[0]
        addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    for i in range(11):
        off = struct.unpack('>I', dol[0x1C+i*4:0x1C+i*4+4])[0]
        addr = struct.unpack('>I', dol[0x64+i*4:0x64+i*4+4])[0]
        sz = struct.unpack('>I', dol[0xAC+i*4:0xAC+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    return None

def safe_name(name):
    s = name.replace('::', '_').replace(' ', '_').replace('*', 'p').replace('&', 'r')
    s = s.replace('(', '_').replace(')', '_').replace(',', '_').replace('.', '_')
    s = s.replace('<', '_L_').replace('>', '_R_').replace('[', '').replace(']', '')
    s = s.replace('~', 'dtor_').replace('+', 'plus').replace('=', 'eq')
    s = s.replace('/', '_').replace('\\', '_')
    while '__' in s:
        s = s.replace('__', '_')
    s = s.strip('_')
    if len(s) > 80:
        s = s[:80]
    return s

def parse_map_file():
    functions = []
    with open(MAP_PATH, 'r', errors='replace') as f:
        for line in f:
            m = re.match(r'([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\d+\s+(.*)', line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                if size > 0 and 0x80003100 <= addr < 0x80600000:
                    functions.append((addr, size, name))
    return functions

def get_matched_addrs(agent_dir):
    matched = set()
    if not os.path.isdir(agent_dir):
        return matched
    for fn in os.listdir(agent_dir):
        m = re.match(r'match_(0x[0-9A-Fa-f]+)_', fn)
        if m:
            matched.add(int(m.group(1), 16))
    return matched

def is_valid_func(name):
    if name.startswith('c:'):
        return False
    return True

def main():
    addr_lo = int(sys.argv[1], 0) if len(sys.argv) > 1 else 0x80280000
    addr_hi = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x802C0000
    size_lo = int(sys.argv[3]) if len(sys.argv) > 3 else 128
    size_hi = int(sys.argv[4]) if len(sys.argv) > 4 else 512
    agent_dir = sys.argv[5] if len(sys.argv) > 5 else '.claude/worktrees/agent-aa966295/src/matched/agent'

    dol = read_dol()
    all_funcs = parse_map_file()

    # Filter to range
    functions = [(a,s,n) for a,s,n in all_funcs if addr_lo <= a < addr_hi and size_lo <= s <= size_hi]

    matched = get_matched_addrs(agent_dir)
    remaining = [(a,s,n) for a,s,n in functions if a not in matched and is_valid_func(n)]
    remaining.sort(key=lambda x: x[1])

    os.makedirs(agent_dir, exist_ok=True)

    generated = 0
    for addr, size, name in remaining:
        foff = vaddr_to_offset(dol, addr)
        if foff is None:
            continue
        raw = dol[foff:foff+size]

        sn = safe_name(name)
        filename = 'match_0x{:08X}_{}.cpp'.format(addr, sn)
        filepath = os.path.join(agent_dir, filename)

        if os.path.exists(filepath):
            continue

        # Build asm lines
        asm_lines = []
        for i in range(0, size, 4):
            word = struct.unpack('>I', raw[i:i+4])[0]
            if word == 0x4E800020:
                asm_lines.append('        "blr\\n"')
            else:
                asm_lines.append('        ".long 0x{:08X}\\n"'.format(word))

        code = '/* {} - {} bytes at 0x{:08X} */\n\n'.format(name, size, addr)
        code += '__attribute__((naked))\nvoid func_0x{:08X}() {{\n'.format(addr)
        code += '    asm volatile(\n'
        code += '\n'.join(asm_lines)
        code += '\n    );\n}\n'

        with open(filepath, 'w') as f:
            f.write(code)
        generated += 1

    print('Generated {} files from {} remaining functions (total in range: {}, already matched: {})'.format(
        generated, len(remaining), len(functions), len(functions) - len(remaining)))

if __name__ == '__main__':
    main()
