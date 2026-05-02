import re, os
from collections import defaultdict

with open("extracted/files/u2_ngc_release_dvd.map") as f:
    lines = f.readlines()

matched = set()
for root, dirs, files in os.walk("src/matched"):
    for f in files:
        if f.endswith(".cpp"):
            m = re.search(r"0x([0-9A-Fa-f]{8})", f)
            if m:
                matched.add(int(m.group(1), 16))

families = defaultdict(list)
for line in lines:
    m = re.match(r"([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\d+\s+(.*)", line)
    if not m:
        continue
    addr = int(m.group(1), 16)
    size = int(m.group(2), 16)
    name = m.group(3).strip()
    if size < 40 or size > 64:
        continue
    if addr >= 0x80240000 and addr < 0x803A0000:
        continue
    if addr in matched:
        continue
    if ".obj)" in name or ".lib(" in name:
        continue
    cm = re.match(r"([^:]+)::(.*)", name)
    if cm:
        cls = cm.group(1)
        families[cls].append((addr, size, name))

for cls, funcs in sorted(families.items(), key=lambda x: -len(x[1])):
    if len(funcs) >= 5:
        print(f"[{cls}] -- {len(funcs)} functions")
        for addr, size, name in funcs[:10]:
            print(f"  0x{addr:08x}  {name} ({size}B)")
        if len(funcs) > 10:
            print(f"  ... and {len(funcs)-10} more")
        print()
