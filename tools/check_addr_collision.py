#!/usr/bin/env python3
"""check_addr_collision.py — QA-RULE #3 address collision detector.

Usage: python tools/check_addr_collision.py <file1.cpp> [file2.cpp ...]
Exit:  0 = all clean, 1 = at least one collision

Scans committed files plus staged additions in src/matched/** and src/wip/**
once into an address index, then checks each argument's address against it.
Untracked working-tree files are intentionally ignored: they may be another
worker's transient WIP and are not part of the commit being checked.

Handles both prefix styles (match_0xADDR_, match_ADDR_) and both hex
cases (case-insensitive via int parse).

Output: one line per collision on stdout:
    DUPE <file> 0xADDR <existing-path1> <existing-path2> ...
"""
import sys
import os
import re
import subprocess

ADDR_RE = re.compile(r'^match_0?x?([0-9A-Fa-f]{6,8})_')

def addr_of(path):
    m = ADDR_RE.match(os.path.basename(path))
    if not m:
        return None
    return int(m.group(1), 16)

def build_index():
    index = {}
    result = subprocess.run(
        ['git', 'ls-files', '--cached', '--', 'src/matched', 'src/wip'],
        check=True,
        capture_output=True,
        text=True,
    )
    for p in result.stdout.splitlines():
        if not p.endswith('.cpp') or not os.path.basename(p).startswith('match_'):
            continue
        a = addr_of(p)
        if a is None:
            continue
        pn = p.replace('\\', '/')
        index.setdefault(a, []).append(pn)
    return index

def main(argv):
    if len(argv) < 2:
        print('usage: check_addr_collision.py <file.cpp> [...]', file=sys.stderr)
        return 2

    index = build_index()
    collisions = 0

    for f in argv[1:]:
        a = addr_of(f)
        if a is None:
            print(f'SKIP {f} (no address in filename)', file=sys.stderr)
            continue
        paths = [p for p in index.get(a, []) if p != f.replace('\\', '/')]
        if paths:
            collisions += 1
            print(f'DUPE {f} 0x{a:08X} ' + ' '.join(paths))

    return 1 if collisions > 0 else 0

if __name__ == '__main__':
    sys.exit(main(sys.argv))
