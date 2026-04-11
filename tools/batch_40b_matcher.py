#!/usr/bin/env python3
"""Batch matcher for 40B wrapper functions with bl calls.
Extracts, classifies by opcode skeleton, and attempts matching."""

import subprocess
import sys
import os
import struct

PYTHON = "/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"
BASE_DIR = "/f/coding/Decompiles/Sims 2"
MATCHED_DIR = f"{BASE_DIR}/src/matched/agent"
VD_DIR = f"{BASE_DIR}/src/wip/version_diff"

def extract_bytes(addr_hex, size):
    """Extract raw bytes from DOL."""
    result = subprocess.run(
        [PYTHON, f"{BASE_DIR}/tools/extract_function.py", addr_hex, str(size)],
        capture_output=True, text=True, cwd=BASE_DIR
    )
    for line in result.stdout.split('\n'):
        if line.startswith('// Raw:'):
            hex_str = line.replace('// Raw:', '').strip()
            return bytes.fromhex(hex_str.replace(' ', ''))
    return None

def get_opcode_skeleton(raw_bytes):
    """Extract primary opcode from each instruction, ignoring operands."""
    skeleton = []
    for i in range(0, len(raw_bytes), 4):
        word = struct.unpack('>I', raw_bytes[i:i+4])[0]
        primary = (word >> 26) & 0x3F  # bits 0-5
        secondary = (word >> 1) & 0x3FF if primary in (31, 19) else 0  # extended opcode
        skeleton.append((primary, secondary))
    return tuple(skeleton)

def classify_40b(raw_bytes):
    """Classify a 40B function by its pattern."""
    if len(raw_bytes) != 40:
        return "unknown"

    # 10 instructions for 40B
    instrs = []
    for i in range(0, 40, 4):
        word = struct.unpack('>I', raw_bytes[i:i+4])[0]
        instrs.append(word)

    # Check for SDA access (lwz from r13 = 0x806Dxxxx pattern, or addi r3,r13)
    has_sda = False
    for w in instrs:
        if (w & 0xFFFF0000) == 0x806D0000:  # lwz r3, off(r13)
            has_sda = True
        if (w & 0xFFFF0000) == 0x386D0000:  # addi r3, r13, off
            has_sda = True
        if (w & 0xFFFF0000) == 0x808D0000:  # lwz r4, off(r13)
            has_sda = True

    # Check for lis (non-SDA global)
    has_lis = False
    for w in instrs:
        if (w >> 16) & 0xFFE0 == 0x3D20:  # lis rN
            has_lis = True

    # Check for li (load immediate)
    li_count = 0
    for w in instrs:
        if (w >> 16) & 0xFFE0 == 0x3800 or (w >> 16) & 0xFFE0 == 0x38A0 or \
           (w >> 16) & 0xFFE0 == 0x38C0 or (w >> 16) & 0xFFE0 == 0x3880:
            li_count += 1

    # Check for field access from r3 (this pointer)
    has_field_access = False
    for w in instrs:
        # lwz rN, off(r3)
        if (w & 0xFC1F0000) == 0x80030000 and (w >> 16) & 0x1F != 1:
            has_field_access = True
        # addi r3, r3, off
        if (w & 0xFFFF0000) == 0x38630000:
            has_field_access = True

    if has_sda and not has_lis:
        return "sda_call"
    elif has_field_access and not has_lis:
        return "field_call"
    elif li_count >= 1 and not has_lis and not has_sda:
        return "const_call"
    elif has_lis:
        return "global_call"
    else:
        return "other"

def main():
    # Read unmatched 40B bl functions
    with open("C:/Users/SCICO/AppData/Local/Temp/unmatched_40b_bl.txt") as f:
        lines = f.readlines()

    patterns = {}
    for line in lines:
        parts = line.strip().split()
        if len(parts) < 3:
            continue
        addr = parts[1]  # 0xXXXXXXXX
        name = parts[2]

        raw = extract_bytes(addr, 40)
        if raw is None:
            continue

        ptype = classify_40b(raw)
        if ptype not in patterns:
            patterns[ptype] = []
        patterns[ptype].append((addr, name, raw))

    # Report
    for ptype, funcs in sorted(patterns.items(), key=lambda x: -len(x[1])):
        print(f"\n=== {ptype} ({len(funcs)} functions) ===")
        for addr, name, raw in funcs[:5]:
            print(f"  {addr} {name}")
        if len(funcs) > 5:
            print(f"  ... and {len(funcs) - 5} more")

if __name__ == "__main__":
    main()
