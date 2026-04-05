#!/usr/bin/env python3
"""Scan asm_decomp functions for v3.93-compatible vtable dispatch pattern.

The v3.93 SN ProDG compiler uses this vtable dispatch register pattern:
  lwz r11, offset(rX)   - load inner/impl pointer into r11
  lwz r9, offset(r11)   - load vtable from inner
  lwz r0, offset(r9)    - load function pointer into r0
  lha r3, offset(r9)    - load vbase offset into r3
  add r3, r11, r3       - compute adjusted this
  mtlr r0               - prepare indirect call
  blrl                   - call

Functions using lwz r3 for inner (instead of r11) are v1.76 pattern and won't match.
"""

import struct
import re
import os
import glob
import subprocess

DOL_PATH = "extracted/sys/main.dol"

def load_dol():
    with open(DOL_PATH, "rb") as f:
        return f.read()

def dol_read(dol, vaddr, size):
    for i in range(7):
        off = struct.unpack(">I", dol[i*4:i*4+4])[0]
        addr = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            foff = off + (vaddr - addr)
            return dol[foff:foff+size]
    return None

def check_pattern(raw_bytes):
    """Check if function uses v3.93 vtable dispatch pattern.

    Returns:
      'v393_vtable' - uses lwz r11 for inner (matchable)
      'v176_vtable' - uses lwz r3 for inner (VERSION_DIFF)
      'no_vtable'   - no vtable dispatch detected (may still match)
      'leaf'        - leaf function (no prologue/epilogue)
    """
    if len(raw_bytes) < 16:
        return 'too_small'

    # Check if leaf function (no stwu prologue)
    first_word = struct.unpack(">I", raw_bytes[0:4])[0]
    if first_word >> 16 != 0x9421:  # stwu r1, -X(r1)
        return 'leaf'

    # Scan for vtable dispatch patterns in the first ~40 bytes
    # Look for lwz rX, offset(rY) patterns
    for i in range(0, min(len(raw_bytes) - 4, 60), 4):
        word = struct.unpack(">I", raw_bytes[i:i+4])[0]
        opcode = (word >> 26) & 0x3F

        if opcode == 32:  # lwz
            rd = (word >> 21) & 0x1F
            ra = (word >> 16) & 0x1F
            d = word & 0xFFFF
            if d > 0x7FFF:
                d -= 0x10000

            # Check for lwz r11, 4(rX) - v3.93 inner load pattern
            if rd == 11 and d == 4 and ra in (3, 30, 31):
                return 'v393_vtable'

            # Check for lwz r11, other_offset(rX) - also v3.93
            if rd == 11 and ra in (3, 30, 31) and d >= 0 and d < 0x100:
                return 'v393_vtable'

            # Check for lwz r3, 4(rX) - v1.76 inner load
            if rd == 3 and d == 4 and ra in (30, 31):
                return 'v176_vtable'

    return 'no_vtable'

def find_already_matched(addr_hex):
    """Check if address is already matched."""
    addr_str = addr_hex[2:].upper()  # Remove 0x prefix
    addr_str_lower = addr_str.lower()
    results = glob.glob(f"src/matched/**/*{addr_str}*", recursive=True)
    results += glob.glob(f"src/matched/**/*{addr_str_lower}*", recursive=True)
    return len(results) > 0

def main():
    dol = load_dol()

    # Find all 65-128B functions across asm_decomp
    functions = []
    for filepath in glob.glob("src/asm_decomp/*.cpp"):
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            prev_line = ""
            for line in f:
                m = re.match(r"^// (0x[0-9a-fA-F]+) \((\d+) bytes\)", line)
                if m:
                    addr = int(m.group(1), 16)
                    size = int(m.group(2))
                    if 65 <= size <= 128:
                        basename = os.path.basename(filepath).replace(".cpp", "")
                        functions.append((addr, size, basename))
                prev_line = line

    print(f"Total 65-128B functions: {len(functions)}")

    # Classify each function
    v393_funcs = []
    no_vtable_funcs = []
    leaf_funcs = []
    v176_count = 0
    already_matched = 0

    for addr, size, source in functions:
        addr_hex = f"0x{addr:08X}"

        if find_already_matched(addr_hex):
            already_matched += 1
            continue

        raw = dol_read(dol, addr, min(size, 64))
        if raw is None:
            continue

        pattern = check_pattern(raw)

        if pattern == 'v393_vtable':
            v393_funcs.append((addr, size, source))
        elif pattern == 'v176_vtable':
            v176_count += 1
        elif pattern == 'no_vtable':
            no_vtable_funcs.append((addr, size, source))
        elif pattern == 'leaf':
            leaf_funcs.append((addr, size, source))

    print(f"Already matched: {already_matched}")
    print(f"v3.93 vtable (MATCHABLE): {len(v393_funcs)}")
    print(f"v1.76 vtable (VERSION_DIFF): {v176_count}")
    print(f"No vtable dispatch: {len(no_vtable_funcs)}")
    print(f"Leaf functions: {len(leaf_funcs)}")

    print(f"\n=== TOP v3.93 VTABLE CANDIDATES (first 50) ===")
    # Sort by size (smaller = easier)
    v393_funcs.sort(key=lambda x: x[1])
    for addr, size, source in v393_funcs[:50]:
        print(f"  0x{addr:08X}  {size:3d}B  {source}")

    print(f"\n=== LEAF FUNCTIONS (first 20) ===")
    leaf_funcs.sort(key=lambda x: x[1])
    for addr, size, source in leaf_funcs[:20]:
        print(f"  0x{addr:08X}  {size:3d}B  {source}")

if __name__ == "__main__":
    main()
