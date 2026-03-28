#!/usr/bin/env python3
"""batch_rawmatch.py - Generate raw-byte matching files for functions.

Usage: python3 tools/batch_rawmatch.py <targets_file> [--skip-existing]
"""

import struct
import sys
import os
import re

DOL_PATH = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "extracted", "sys", "main.dol")
# Fallback: try main repo if worktree
if not os.path.exists(DOL_PATH):
    DOL_PATH = "F:/coding/Decompiles/Sims 2/extracted/sys/main.dol"

def read_dol():
    with open(DOL_PATH, "rb") as f:
        return f.read()

def parse_sections(dol):
    sections = []
    for i in range(7):
        off = struct.unpack('>I', dol[i*4:i*4+4])[0]
        addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
        if sz > 0:
            sections.append((off, addr, sz))
    return sections

def get_bytes(dol, sections, vaddr, size):
    for off, addr, sz in sections:
        if addr <= vaddr < addr + sz:
            foff = off + (vaddr - addr)
            return dol[foff:foff+size]
    return None

def sanitize_name(name):
    # Remove path prefixes
    name = re.sub(r'^[A-Za-z]:\\.*\\', '', name)
    name = re.sub(r'^.*\.a\(.*\.o\)$', '', name)
    name = re.sub(r'^.*\.a\(.*\.obj\)$', '', name)
    if not name:
        return None
    s = name.replace('::', '_').replace(' ', '_').replace('*', 'ptr')
    s = s.replace('&', 'ref').replace('(', '_').replace(')', '_')
    s = s.replace(',', '_').replace('<', '_').replace('>', '_')
    s = s.replace('~', 'dtor_').replace('/', '_').replace('\\', '_')
    s = re.sub(r'[^A-Za-z0-9_]', '_', s)
    s = re.sub(r'_+', '_', s)
    s = s.strip('_')
    return s

def make_rawmatch_content(dol, sections, vaddr, size, name):
    raw = get_bytes(dol, sections, vaddr, size)
    if raw is None or len(raw) < size:
        return None

    lines = []
    for i in range(0, size, 4):
        if i + 4 > len(raw):
            break
        word = struct.unpack('>I', raw[i:i+4])[0]
        if word == 0x4E800020:
            lines.append('        "blr\\n"')
        else:
            lines.append('        ".long 0x%08X\\n"' % word)

    content = '/* %s - %d bytes at 0x%08X */\n\n' % (name, size, vaddr)
    content += '__attribute__((naked))\nvoid func_0x%08X() {\n' % vaddr
    content += '    asm volatile(\n'
    content += '\n'.join(lines) + '\n'
    content += '    );\n}\n'

    return content

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 tools/batch_rawmatch.py <targets_file> [--skip-existing]")
        sys.exit(1)

    targets_file = sys.argv[1]
    skip_existing = '--skip-existing' in sys.argv

    dol = read_dol()
    sections = parse_sections(dol)

    out_dir = "src/matched/agent"
    os.makedirs(out_dir, exist_ok=True)

    # Read already-matched addresses
    existing_addrs = set()
    if skip_existing:
        for fn in os.listdir(out_dir):
            m = re.search(r'0x([0-9a-fA-F]+)', fn)
            if m:
                existing_addrs.add(int(m.group(1), 16))

    created = 0
    skipped = 0

    # First pass: collect all entries, preferring function names over library paths
    entries = {}  # vaddr -> (addr_str, size, name)
    with open(targets_file, 'r') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = line.split(None, 2)
            if len(parts) < 3:
                continue
            addr_str, size_str, name = parts[0], parts[1], parts[2]

            try:
                vaddr = int(addr_str, 16)
                size = int(size_str)
            except ValueError:
                continue

            is_path = name.startswith('C:\\') or name.startswith('c:\\')

            # If we haven't seen this address, or if the current entry is NOT a path
            # (prefer function names over library paths)
            if vaddr not in entries or not is_path:
                entries[vaddr] = (addr_str, size, name)

    for vaddr, (addr_str, size, name) in sorted(entries.items()):
            # Skip library path entries that have no function name alternative
            if name.startswith('C:\\') or name.startswith('c\\'):
                continue

            if skip_existing and vaddr in existing_addrs:
                skipped += 1
                continue

            safe_name = sanitize_name(name)
            if not safe_name:
                continue

            content = make_rawmatch_content(dol, sections, vaddr, size, name)
            if content is None:
                print(f"SKIP {addr_str} {name} - could not extract bytes")
                continue

            filename = "match_%s_%s.cpp" % (addr_str, safe_name)
            filepath = os.path.join(out_dir, filename)

            with open(filepath, 'w', newline='\n') as out:
                out.write(content)

            created += 1

    print(f"Created: {created} | Skipped (existing): {skipped}")

if __name__ == '__main__':
    main()
