#!/usr/bin/env python3
"""Disassemble a function using powerpc-eabi-objdump for accurate output."""

import struct
import subprocess
import sys
import os
import re
import tempfile

DOL_PATH = "extracted/sys/main.dol"
MAP_PATH = "extracted/files/u2_ngc_release_dvd.map"
OBJDUMP = "/f/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe"

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

def parse_map():
    funcs = {}
    with open(MAP_PATH, 'r', errors='replace') as f:
        for line in f:
            m = re.match(r'([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\d+\s+(.*)', line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                funcs[addr] = (size, name)
    return funcs

def main():
    addr = int(sys.argv[1], 0)
    size = int(sys.argv[2]) if len(sys.argv) > 2 else None

    dol = read_dol()
    funcs = parse_map()

    if size is None and addr in funcs:
        size = funcs[addr][0]
    if size is None:
        print("Size not found")
        sys.exit(1)

    name = funcs.get(addr, (0, "unknown"))[1]
    print(f"// {name}")
    print(f"// Address: 0x{addr:08X} | Size: {size} bytes")

    foff = vaddr_to_offset(dol, addr)
    if foff is None:
        print("Address not found in DOL")
        sys.exit(1)

    raw = dol[foff:foff+size]

    # Write to temp file and use objdump
    with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as tmp:
        tmp.write(raw)
        tmp_path = tmp.name

    try:
        result = subprocess.run(
            [OBJDUMP, "-D", "-m", "powerpc", "-EB", "-b", "binary",
             f"--adjust-vma=0x{addr:08X}", tmp_path],
            capture_output=True, text=True, timeout=10
        )
        # Filter to just disassembly lines
        in_disasm = False
        for line in result.stdout.split('\n'):
            if '<.data>:' in line:
                in_disasm = True
                continue
            if in_disasm and line.strip():
                print(line)
    finally:
        os.unlink(tmp_path)

    # Also print symbol references for bl targets
    print("\n// Symbol references:")
    for i in range(0, size, 4):
        word = struct.unpack('>I', raw[i:i+4])[0]
        opcode = (word >> 26) & 0x3F
        if opcode == 18:  # b/bl
            li = word & 0x03FFFFFC
            if li >= 0x02000000:
                li -= 0x04000000
            target = addr + i + li
            aa = (word >> 1) & 1
            lk = word & 1
            if aa:
                target = li
            tname = funcs.get(target, (0, f"0x{target:08X}"))[1]
            op = "bl" if lk else "b"
            print(f"//   0x{addr+i:08X}: {op} -> {tname}")

if __name__ == '__main__':
    main()
