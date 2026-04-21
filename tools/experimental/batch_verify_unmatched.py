import subprocess, os, re

BASH = r'F:\coding\Decompiles\Tools\devkitPro\msys2\usr\bin\bash.exe'

def get_size(addr):
    try:
        result = subprocess.run([os.sys.executable, 'tools/disasm_func.py', addr], capture_output=True, text=True)
        lines = result.stdout.split('\n')
        size_line = [l for l in lines if 'Size:' in l]
        if size_line:
            m = re.search(r'Size:\s+(\d+)\s+bytes', size_line[0])
            return int(m.group(1)) if m else None
    except Exception:
        pass
    return None

# Get all version_diff files
vd_files = sorted([f for f in os.listdir('src/wip/version_diff') if f.endswith('.cpp')])

# Find matched addresses
matched = set()
for root, dirs, files in os.walk('src/matched'):
    for f in files:
        if f.endswith('.cpp'):
            m = re.search(r'0x([0-9A-Fa-f]{8})', f)
            if m:
                matched.add(m.group(1).lower())

# Find unmatched
unmatched = []
for f in vd_files:
    m = re.search(r'0x([0-9A-Fa-f]{8})', f)
    if m and m.group(1).lower() not in matched:
        unmatched.append((f, '0x' + m.group(1).upper()))

print('Unmatched version_diff files: ' + str(len(unmatched)))

# Test first 20
matches = []
errors = []

for fpath, addr in unmatched[:20]:
    size = get_size(addr)
    if size is None or size == 0:
        print('SKIP ' + addr + ' (no size)')
        continue
    full_path = 'src/wip/version_diff/' + fpath
    result = subprocess.run([BASH, 'tools/verify_match.sh', full_path, addr, str(size)], capture_output=True, text=True)
    output = result.stdout + result.stderr
    if 'MATCH!' in output:
        print('MATCH: ' + addr + ' (' + str(size) + 'B) — ' + fpath)
        matches.append((full_path, addr, size, fpath))
    elif 'NEAR_MATCH' in output or 'MISMATCH' in output or 'SIZE_MISMATCH' in output:
        print('NEAR/MISMATCH: ' + addr + ' (' + str(size) + 'B)')
    else:
        print('NO_MATCH/ERROR: ' + addr + ' (' + str(size) + 'B)')
        errors.append((addr, size, output[-300:]))

print('\n=== SUMMARY ===')
print('Matches: ' + str(len(matches)))
for full_path, addr, size, fname in matches:
    print('  ' + addr + ' (' + str(size) + 'B) ' + fname)
