#!/usr/bin/env python3
import os, random, re, subprocess

BASH = r'F:\coding\Decompiles\Tools\devkitPro\msys2\usr\bin\bash.exe'

def verify(fpath):
    with open(fpath, 'r', errors='ignore') as f:
        content = f.read()
    m = re.search(r'0x([0-9a-fA-F]{8})', content)
    sm = re.search(r'\(\s*(\d+)\s*bytes?\s*\)', content, re.I)
    if not m or not sm:
        return None, None, None, None
    addr = '0x' + m.group(1)
    size = sm.group(1)
    cmd = [BASH, '-lc', f'cd /f/coding/Decompiles/Sims\\ 2 && DEVKITPPC=/f/coding/Decompiles/Tools/devkitPro/devkitPPC ./tools/verify_match.sh \"{fpath}\" {addr} {size}']
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    output = result.stdout + result.stderr
    if 'MATCH!' in output:
        return 'MATCH', addr, size, os.path.basename(fpath)
    elif 'SIZE_MISMATCH' in output or 'MISMATCH' in output:
        return 'MISMATCH', addr, size, os.path.basename(fpath)
    else:
        return 'ERROR', addr, size, os.path.basename(fpath)

files = []
for root, dirs, filenames in os.walk('src/matched'):
    for fname in filenames:
        if fname.endswith('.cpp'):
            fpath = os.path.join(root, fname)
            with open(fpath, 'r', errors='ignore') as f:
                content = f.read()
            if re.search(r'0x[0-9a-fA-F]{8}', content) and re.search(r'\(\s*\d+\s*bytes?\s*\)', content, re.I):
                files.append(fpath)

random.seed()
random.shuffle(files)
count = 0
for fpath in files[:50]:
    if count >= 10:
        break
    status, addr, size, basename = verify(fpath)
    if status:
        count += 1
        print(f'{status}\t{addr}\t{size}\t{basename}')
