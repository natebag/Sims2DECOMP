import json, re, os

with open('build/reports/matched_stats.json') as f:
    data = json.load(f)

dupes = data.get('duplicates', {})

def find_addr(f):
    with open(f) as fh:
        lines = fh.readlines()[:5]
    for line in lines:
        m = re.search(r'0x([0-9A-Fa-f]+)', line)
        if m:
            return m.group(1).upper()
    return None

def find_size(f):
    with open(f) as fh:
        lines = fh.readlines()[:5]
    for line in lines:
        m = re.search(r'\((\d+)\s*[Bb]ytes?\)', line)
        if m:
            return m.group(1)
        m = re.search(r'\((\d+)B\)', line)
        if m:
            return m.group(1)
        m = re.search(r'-\s*(\d+)\s*[Bb]ytes?', line)
        if m:
            return m.group(1)
    return None

for addr, files in sorted(dupes.items(), key=lambda x: int(x[0], 16)):
    print(f'=== {addr} ===')
    for f in files:
        faddr = find_addr(f)
        fsize = find_size(f)
        exists = os.path.exists(f)
        status = 'OK' if faddr == addr else ('NO_ADDR' if faddr is None else 'WRONG_ADDR')
        print(f'  {status} size={fsize} exists={exists}: {f}')
