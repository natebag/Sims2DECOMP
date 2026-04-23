import re, os

with open("extracted/files/u2_ngc_release_dvd.map") as f:
    lines = f.readlines()

apt_symbols = []
for line in lines:
    m = re.match(r"([0-9a-f]{8})\s+([0-9a-f]{8})", line)
    if not m:
        continue
    addr = m.group(1)
    size = int(m.group(2), 16)
    if 4 <= size <= 48:
        if "Apt" in line and "virtual table" not in line and "c:\\BuildAgent" not in line:
            apt_symbols.append((addr, size, line.strip()))

matched_addrs = set()
for root, dirs, files in os.walk("src/matched"):
    for f in files:
        if f.endswith(".cpp"):
            m = re.search(r"([0-9a-fA-F]{8})", f)
            if m:
                matched_addrs.add(m.group(1).lower())

unmatched = []
for addr, size, line in apt_symbols:
    if addr.lower() not in matched_addrs:
        unmatched.append((addr, size, line))

print(f"Unmatched Apt* 4-48B: {len(unmatched)}")
for addr, size, line in sorted(unmatched, key=lambda x: x[1]):
    print(f"{addr} {size:3d}B {line}")
