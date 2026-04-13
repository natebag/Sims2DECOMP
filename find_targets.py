import os
import re

# Parse map file
map_path = 'extracted/files/u2_ngc_release_dvd.map'
pattern = re.compile(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+\s+(.*)$')

audio_eff_funcs = []
with open(map_path, 'r') as f:
    for line in f:
        m = pattern.match(line)
        if m:
            addr, size, name = m.groups()
            size_val = int(size, 16)
            addr_val = int(addr, 16)
            if size_val in (24, 32):
                name = name.strip()
                if any(k in name.lower() for k in ['sound', 'audio', 'effect', 'frame']):
                    # skip SDK range
                    if 0x80240000 <= addr_val <= 0x80390000:
                        continue
                    audio_eff_funcs.append((addr_val, size_val, name))

# Check which are already matched
matched_addrs = set()
for root, dirs, files in os.walk('src/matched'):
    for f in files:
        m = re.search(r'0x([0-9a-fA-F]{8})', f)
        if m:
            matched_addrs.add(int(m.group(1), 16))

unmatched = [(a, s, n) for a, s, n in audio_eff_funcs if a not in matched_addrs]

print(f"Total Audio/Effect/Frame 24-32B functions: {len(audio_eff_funcs)}")
print(f"Already matched: {len(audio_eff_funcs) - len(unmatched)}")
print(f"Unmatched: {len(unmatched)}")
print()
for a, s, n in unmatched:
    print(f"0x{a:08X}  {s}B  {n}")
