import json, re, subprocess, sys

with open('matched_stats.json') as f:
    data = json.load(f)

dupes = data.get('duplicates', {})

def verify(f):
    with open(f) as fh:
        line = fh.readline()
    m = re.search(r'0x([0-9A-Fa-f]+)', line)
    if not m:
        return None, 'no addr'
    addr = '0x' + m.group(1)
    m = re.search(r'\((\d+)\s*[Bb]ytes?\)', line)
    if not m:
        m = re.search(r'\((\d+)B\)', line)
    if not m:
        m = re.search(r'-\s*(\d+)\s*[Bb]ytes?', line)
    if not m:
        return None, 'no size'
    size = m.group(1)
    result = subprocess.run(['bash', 'tools/verify_match.sh', f, addr, size], capture_output=True, text=True, timeout=60)
    return result.returncode == 0, result.stdout.strip().split('\n')[-1]

for addr, files in sorted(dupes.items(), key=lambda x: int(x[0], 16)):
    print(f'=== {addr} ===')
    for f in files:
        ok, tail = verify(f)
        status = 'MATCH' if ok else ('FAIL' if ok is False else f'ERR:{tail}')
        print(f'  {status}: {f}')
    sys.stdout.flush()
