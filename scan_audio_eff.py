import os
import re

version_diff = 'src/wip/version_diff'
pattern = re.compile(r'match_(0x[0-9A-Fa-f]{8})_(.*)\.cpp')

results = []
for f in os.listdir(version_diff):
    m = pattern.match(f)
    if not m:
        continue
    addr, name = m.groups()
    if any(k in name.lower() for k in ['sound', 'audio', 'effect', 'frame']):
        path = os.path.join(version_diff, f)
        size = '?'
        with open(path, 'r') as fp:
            for line in fp:
                sz = re.search(r'Size:\s*(\d+)', line)
                if sz:
                    size = sz.group(1)
                    break
        try:
            szn = int(size)
        except:
            szn = 9999
        results.append((szn, addr, name, size))

results.sort()
for sz, addr, name, size in results:
    print(f"{size:>4}B {addr} {name}")
