#!/usr/bin/env python3
"""
Count byte-identical function matches between our build ELF and original DOL.
"""

import os
import re
import struct
import subprocess
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
OBJCOPY = DEVKITPPC / "bin" / "powerpc-eabi-objcopy.exe"
OBJDUMP = DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe"

ORIGINAL_DOL = REPO / "extracted" / "sys" / "main.dol"
OUR_ELF = REPO / "build" / "sims2.elf"
SYMBOLS_FILE = REPO / "config" / "symbols.txt"


def read_dol_sections(dol_path):
    """Read all sections from DOL file. Returns dict of addr -> bytes."""
    with open(dol_path, 'rb') as f:
        data = f.read()

    sections = {}

    # 7 text sections
    for i in range(7):
        off = struct.unpack('>I', data[0x00+i*4:0x04+i*4])[0]
        addr = struct.unpack('>I', data[0x48+i*4:0x4C+i*4])[0]
        size = struct.unpack('>I', data[0x90+i*4:0x94+i*4])[0]
        if size > 0:
            section_data = data[off:off+size]
            sections[addr] = section_data

    # 11 data sections
    for i in range(11):
        off = struct.unpack('>I', data[0x1C+i*4:0x20+i*4])[0]
        addr = struct.unpack('>I', data[0x64+i*4:0x68+i*4])[0]
        size = struct.unpack('>I', data[0xAC+i*4:0xB0+i*4])[0]
        if size > 0:
            section_data = data[off:off+size]
            sections[addr] = section_data

    return sections


def get_dol_bytes(sections, addr, size):
    """Get bytes at given address from DOL sections."""
    for sec_addr, sec_data in sections.items():
        sec_end = sec_addr + len(sec_data)
        if addr >= sec_addr and addr + size <= sec_end:
            off = addr - sec_addr
            return sec_data[off:off+size]
    return None


def read_elf_text(elf_path):
    """Extract .text section from our ELF."""
    tmp = REPO / "build" / "tmp_text.bin"
    subprocess.run([
        str(OBJCOPY), "-O", "binary", "-j", ".text",
        str(elf_path), str(tmp)
    ], check=True, cwd=str(REPO))

    with open(tmp, 'rb') as f:
        data = f.read()

    # Get .text load address from objdump -h
    result = subprocess.run([
        str(OBJDUMP), "-h", str(elf_path)
    ], capture_output=True, text=True, cwd=str(REPO))

    text_addr = None
    for line in result.stdout.split('\n'):
        parts = line.split()
        if len(parts) >= 4 and parts[1] == '.text':
            text_addr = int(parts[3], 16)
            break

    os.unlink(tmp)
    return text_addr, data


def parse_symbols():
    """Parse symbols.txt for .text function addresses and sizes."""
    functions = []
    with open(SYMBOLS_FILE, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            # Format: name = .section:0xADDR; // type:function size:0xSIZE scope:...
            m = re.match(r'(\S+)\s*=\s*\.(\w+):0x([0-9A-Fa-f]+);\s*//\s*type:(\w+)\s+size:0x([0-9A-Fa-f]+)', line)
            if m:
                name = m.group(1)
                section = m.group(2)
                addr = int(m.group(3), 16)
                typ = m.group(4)
                size = int(m.group(5), 16)
                if section == 'text' and typ == 'function' and size > 0:
                    functions.append((addr, size, name))
    return functions


def get_active_function_addrs():
    """
    Scan all matched source files and extract addresses of active (not #if 0'd) functions.
    Returns set of (addr, expected_size).
    """
    matched_dir = REPO / "src" / "matched"
    active = set()

    for fname in sorted(os.listdir(matched_dir)):
        if not fname.endswith('.cpp'):
            continue

        with open(matched_dir / fname, 'r') as f:
            content = f.read()

        # Track #if 0 nesting
        in_if0 = 0
        lines = content.split('\n')
        pending_addr = None

        for line in lines:
            s = line.strip()

            if s == '#if 0':
                in_if0 += 1
                pending_addr = None
                continue
            elif s == '#endif' and in_if0 > 0:
                in_if0 -= 1
                continue

            if in_if0 > 0:
                continue

            # Check for address comment
            m = re.match(r'// 0x([0-9A-Fa-f]+)\s+\((\d+) bytes\)', s)
            if m:
                pending_addr = (int(m.group(1), 16), int(m.group(2)))
                continue

            # Check if this is a function definition line
            if '::' in s and '{' in s and '}' in s and not s.startswith('//') and not s.startswith('#'):
                if pending_addr:
                    active.add(pending_addr)
                pending_addr = None
            elif 'template class' in s:
                # Template instantiation lines
                pending_addr = None
            elif s and not s.startswith('//') and not s.startswith('#'):
                pending_addr = None

    # Also check other src/ directories
    for root, dirs, files in os.walk(REPO / "src"):
        if 'matched' in root:
            continue
        for fname in files:
            if not fname.endswith('.cpp') and not fname.endswith('.c'):
                continue
            fpath = os.path.join(root, fname)
            with open(fpath, 'r') as f:
                content = f.read()
            for m in re.finditer(r'// 0x([0-9A-Fa-f]+)\s+\((\d+) bytes\)', content):
                addr = int(m.group(1), 16)
                size = int(m.group(2))
                active.add((addr, size))

    return active


def main():
    print("Reading original DOL...")
    dol_sections = read_dol_sections(ORIGINAL_DOL)
    total_dol = sum(len(d) for d in dol_sections.values())
    print(f"  DOL: {len(dol_sections)} sections, {total_dol} bytes total")

    print("Reading our ELF...")
    our_addr, our_data = read_elf_text(OUR_ELF)
    print(f"  ELF .text: 0x{our_addr:08X}, {len(our_data)} bytes")

    print("Parsing symbols...")
    all_funcs = parse_symbols()
    print(f"  {len(all_funcs)} text functions total")

    print("Scanning active matched functions...")
    active_addrs = get_active_function_addrs()
    print(f"  {len(active_addrs)} active function addresses")

    # Build lookup
    active_set = {addr for addr, size in active_addrs}

    # Compare all functions (not just active ones - skeleton might have stubs)
    total_match = 0
    total_mismatch = 0
    total_match_bytes = 0
    matches = []
    mismatches = []

    for addr, size, name in all_funcs:
        orig_bytes = get_dol_bytes(dol_sections, addr, size)
        if orig_bytes is None:
            continue

        our_off = addr - our_addr
        if our_off < 0 or our_off + size > len(our_data):
            continue

        our_bytes = our_data[our_off:our_off + size]

        if orig_bytes == our_bytes:
            total_match += 1
            total_match_bytes += size
            if addr in active_set:
                matches.append((addr, size, name))
        else:
            if addr in active_set:
                total_mismatch += 1
                mismatches.append((addr, size, name))

    print(f"\n{'='*60}")
    print(f"BYTE MATCH RESULTS")
    print(f"{'='*60}")
    print(f"Total functions in DOL .text:  {len(all_funcs)}")
    print(f"Total byte-identical:          {total_match}")
    print(f"Total matched bytes:           {total_match_bytes}")
    print(f"")
    print(f"Active matched functions:      {len(active_addrs)}")
    print(f"  Of those, byte-identical:    {len(matches)}")
    print(f"  Of those, mismatched:        {total_mismatch}")

    if matches:
        print(f"\nSample byte-identical matches (first 30):")
        for addr, size, name in matches[:30]:
            print(f"  0x{addr:08X} ({size:4d} bytes) {name}")

    if mismatches:
        print(f"\nMismatched functions (first 20):")
        for addr, size, name in mismatches[:20]:
            print(f"  0x{addr:08X} ({size:4d} bytes) {name}")


if __name__ == '__main__':
    main()
