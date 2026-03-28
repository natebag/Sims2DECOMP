#!/usr/bin/env python3
"""extract_abs.py - Extract function disassembly using absolute paths."""
import struct
import sys
import os

DOL_PATH = "F:/coding/Decompiles/Sims 2/extracted/sys/main.dol"
MAP_PATH = "F:/coding/Decompiles/Sims 2/extracted/files/u2_ngc_release_dvd.map"

# Import the decoder from extract_function
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)) + "/..")
from tools.extract_function import decode_ppc

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

def extract_and_disassemble(dol, vaddr, size):
    foff = vaddr_to_offset(dol, vaddr)
    if foff is None:
        print(f"ERROR: Could not find offset for {vaddr:#x}")
        return
    raw = dol[foff:foff+size]
    print(f"Function at {vaddr:#010x}, {size} bytes:")
    print(f"Raw bytes: {raw.hex()}")
    print("Disassembly:")
    for i in range(0, len(raw), 4):
        if i + 4 > len(raw):
            break
        word = struct.unpack(">I", raw[i:i+4])[0]
        addr = vaddr + i
        asm = decode_ppc(word, addr)
        hex_str = " ".join(f"{b:02X}" for b in raw[i:i+4])
        print(f"  {addr:08X}:  {hex_str}    {asm}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python extract_abs.py <hex_address> <size>")
        sys.exit(1)
    addr = int(sys.argv[1], 16)
    size = int(sys.argv[2])
    dol = read_dol()
    extract_and_disassemble(dol, addr, size)
