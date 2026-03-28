#!/usr/bin/env python3
"""extract_function.py — Extract PPC disassembly from the DOL for a function.

Usage:
    python tools/extract_function.py <address_hex> <size>
    python tools/extract_function.py --name "ESimsApp::GetStartLot"
    python tools/extract_function.py --batch-trivial          # list all 8-byte functions
    python tools/extract_function.py --batch-small             # list all 8-32 byte functions

Output: function address, size, raw bytes, PPC disassembly (human-readable).
This output can be fed directly to an AI agent for matching.
"""

import struct
import sys
import os
import re

DOL_PATH = "extracted/sys/main.dol"
# IMPORTANT: The DVD map matches the DOL. The release map is a different build.
MAP_PATH = "extracted/files/u2_ngc_release_dvd.map"

# PPC instruction decoder (subset — covers common instructions)
def decode_ppc(word, addr):
    """Decode a 32-bit PPC instruction to human-readable assembly."""
    opcode = (word >> 26) & 0x3F

    # Common instructions
    if word == 0x4E800020:
        return "blr"
    if word == 0x4E800021:
        return "blrl"

    # li (addi rD, 0, imm)
    if opcode == 14:  # addi
        rd = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        imm = word & 0xFFFF
        if imm >= 0x8000:
            imm -= 0x10000
        if ra == 0:
            return f"li r{rd}, {imm}"
        return f"addi r{rd}, r{ra}, {imm}"

    if opcode == 15:  # addis
        rd = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        imm = word & 0xFFFF
        if imm >= 0x8000:
            imm -= 0x10000
        if ra == 0:
            return f"lis r{rd}, {imm}"
        return f"addis r{rd}, r{ra}, {imm}"

    if opcode == 32:  # lwz
        rd = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        d = word & 0xFFFF
        if d >= 0x8000:
            d -= 0x10000
        return f"lwz r{rd}, {d}(r{ra})"

    if opcode == 36:  # stw
        rs = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        d = word & 0xFFFF
        if d >= 0x8000:
            d -= 0x10000
        return f"stw r{rs}, {d}(r{ra})"

    if opcode == 40:  # lhz
        rd = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        d = word & 0xFFFF
        if d >= 0x8000:
            d -= 0x10000
        return f"lhz r{rd}, {d}(r{ra})"

    if opcode == 44:  # sth
        rs = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        d = word & 0xFFFF
        if d >= 0x8000:
            d -= 0x10000
        return f"sth r{rs}, {d}(r{ra})"

    if opcode == 34:  # lbz
        rd = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        d = word & 0xFFFF
        if d >= 0x8000:
            d -= 0x10000
        return f"lbz r{rd}, {d}(r{ra})"

    if opcode == 38:  # stb
        rs = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        d = word & 0xFFFF
        if d >= 0x8000:
            d -= 0x10000
        return f"stb r{rs}, {d}(r{ra})"

    if opcode == 48:  # lfs
        rd = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        d = word & 0xFFFF
        if d >= 0x8000:
            d -= 0x10000
        return f"lfs f{rd}, {d}(r{ra})"

    if opcode == 52:  # stfs
        rs = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        d = word & 0xFFFF
        if d >= 0x8000:
            d -= 0x10000
        return f"stfs f{rs}, {d}(r{ra})"

    if opcode == 31:  # extended opcode
        xo = (word >> 1) & 0x3FF
        rd = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        rb = (word >> 11) & 0x1F
        if xo == 467:  # mtspr
            spr = ((word >> 16) & 0x1F) | (((word >> 11) & 0x1F) << 5)
            if spr == 8:
                return f"mtlr r{rd}"
            if spr == 9:
                return f"mtctr r{rd}"
            return f"mtspr {spr}, r{rd}"
        if xo == 339:  # mfspr
            spr = ((word >> 16) & 0x1F) | (((word >> 11) & 0x1F) << 5)
            if spr == 8:
                return f"mflr r{rd}"
            if spr == 9:
                return f"mfctr r{rd}"
            return f"mfspr r{rd}, {spr}"
        if xo == 444:  # or (mr)
            if ra == rb:
                return f"mr r{ra}, r{rd}"
            return f"or r{ra}, r{rd}, r{rb}"

    if opcode == 18:  # b/bl
        li = word & 0x03FFFFFC
        if li >= 0x02000000:
            li -= 0x04000000
        target = addr + li
        aa = (word >> 1) & 1
        lk = word & 1
        if aa:
            target = li
        op = "bl" if lk else "b"
        return f"{op} 0x{target:08X}"

    # stwu
    if opcode == 37:
        rs = (word >> 21) & 0x1F
        ra = (word >> 16) & 0x1F
        d = word & 0xFFFF
        if d >= 0x8000:
            d -= 0x10000
        return f"stwu r{rs}, {d}(r{ra})"

    # Fallback
    return f".long 0x{word:08X}"


def read_dol():
    with open(DOL_PATH, "rb") as f:
        return f.read()

def vaddr_to_offset(dol, vaddr):
    for i in range(7):
        off = struct.unpack(">I", dol[i*4:i*4+4])[0]
        addr = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    for i in range(11):
        off = struct.unpack(">I", dol[0x1C+i*4:0x1C+i*4+4])[0]
        addr = struct.unpack(">I", dol[0x64+i*4:0x64+i*4+4])[0]
        sz = struct.unpack(">I", dol[0xAC+i*4:0xAC+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    return None

def extract_function(dol, vaddr, size):
    foff = vaddr_to_offset(dol, vaddr)
    if foff is None:
        return None
    return dol[foff:foff+size]

def disassemble(raw_bytes, base_addr):
    lines = []
    for i in range(0, len(raw_bytes), 4):
        if i + 4 > len(raw_bytes):
            break
        word = struct.unpack(">I", raw_bytes[i:i+4])[0]
        addr = base_addr + i
        asm = decode_ppc(word, addr)
        hex_str = " ".join(f"{b:02X}" for b in raw_bytes[i:i+4])
        lines.append(f"  {addr:08X}:  {hex_str}    {asm}")
    return "\n".join(lines)

def parse_map_file():
    """Parse the release map file for function symbols."""
    functions = []
    if not os.path.exists(MAP_PATH):
        return functions

    with open(MAP_PATH, "r", errors="replace") as f:
        for line in f:
            # Map format: "80004670 00000008     0                         ESimsApp::GetStartLot(void)"
            m = re.match(r'([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\d+\s+(.*)', line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                if size > 0 and 0x80003100 <= addr < 0x80600000:
                    functions.append((addr, size, name))

    return functions

def main():
    dol = read_dol()

    if "--batch-trivial" in sys.argv:
        funcs = parse_map_file()
        trivial = [(a, s, n) for a, s, n in funcs if s == 8]
        print(f"Found {len(trivial)} 8-byte functions:")
        for addr, size, name in sorted(trivial):
            raw = extract_function(dol, addr, size)
            if raw:
                hex_str = " ".join(f"{b:02X}" for b in raw)
                print(f"  0x{addr:08X}  {hex_str}  {name}")
        return

    if "--batch-small" in sys.argv:
        funcs = parse_map_file()
        small = [(a, s, n) for a, s, n in funcs if 8 <= s <= 32]
        print(f"Found {len(small)} functions 8-32 bytes:")
        for addr, size, name in sorted(small)[:100]:
            print(f"  0x{addr:08X} ({size:3d}B) {name}")
        print(f"  ... and {len(small)-100} more" if len(small) > 100 else "")
        return

    if "--name" in sys.argv:
        idx = sys.argv.index("--name")
        search = sys.argv[idx + 1]
        funcs = parse_map_file()
        matches = [(a, s, n) for a, s, n in funcs if search.lower() in n.lower()]
        if not matches:
            print(f"No function matching '{search}' found in map file")
            sys.exit(1)
        for addr, size, name in matches[:5]:
            raw = extract_function(dol, addr, size)
            if raw:
                print(f"// {name}")
                print(f"// Address: 0x{addr:08X} | Size: {size} bytes")
                print(f"// Raw: {' '.join(f'{b:02X}' for b in raw)}")
                print(f"//")
                print(f"// Disassembly:")
                print(disassemble(raw, addr))
                print()
        return

    # Direct address + size
    if len(sys.argv) >= 3:
        addr = int(sys.argv[1], 0)
        size = int(sys.argv[2])

        # Try to find name in map
        funcs = parse_map_file()
        name = "unknown"
        for a, s, n in funcs:
            if a == addr:
                name = n
                break

        raw = extract_function(dol, addr, size)
        if raw is None:
            print(f"Address 0x{addr:08X} not found in DOL")
            sys.exit(1)

        print(f"// {name}")
        print(f"// Address: 0x{addr:08X} | Size: {size} bytes")
        print(f"// Raw: {' '.join(f'{b:02X}' for b in raw)}")
        print(f"//")
        print(f"// Disassembly:")
        print(disassemble(raw, addr))
    else:
        print("Usage:")
        print("  python tools/extract_function.py 0xADDRESS SIZE")
        print("  python tools/extract_function.py --name 'FunctionName'")
        print("  python tools/extract_function.py --batch-trivial")
        print("  python tools/extract_function.py --batch-small")

if __name__ == "__main__":
    main()
