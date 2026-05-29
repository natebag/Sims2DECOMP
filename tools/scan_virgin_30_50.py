#!/usr/bin/env python3
"""Find virgin 30-50B inject stubs in agent/ (no canonical counterpart anywhere)."""
import os, re, glob, subprocess

agent_dir = "src/matched/agent"

# Build set of all addresses in non-agent canonical dirs
canonical_addrs = set()
for f in glob.glob("src/matched/**/*.cpp", recursive=True):
    if '/agent/' in f.replace('\\', '/'):
        continue
    m = re.search(r'match_(?:0x)?([0-9a-fA-F]{8})_', os.path.basename(f))
    if m:
        canonical_addrs.add(m.group(1).upper())

# Scan agent stubs
results = []
for f in sorted(glob.glob(f"{agent_dir}/match_*.cpp")):
    with open(f) as fh:
        content = fh.read()

    # Must be inject
    if 'ASMPROC_inject_before' not in content:
        continue

    # Get size
    m = re.search(r'\((\d+)\s*B\)', content)
    if not m:
        continue
    size = int(m.group(1))
    if size < 30 or size > 50:
        continue

    # Get address
    fname = os.path.basename(f)
    addr_m = re.search(r'match_(?:0x)?([0-9a-fA-F]{8})_', fname)
    if not addr_m:
        continue
    addr = addr_m.group(1).upper()

    # Must be virgin (no canonical match anywhere)
    if addr in canonical_addrs:
        continue

    # Get inject lines
    inject_m = re.search(r'lines="([^"]+)"', content)
    inject = inject_m.group(1) if inject_m else ''

    # Count bl_ subcalls
    bl_count = len(re.findall(r'bl _s', content))

    # Get function name from comment
    name_m = re.search(r'0x[0-9a-fA-F]+ ([\w:~<>]+)', content)
    name = name_m.group(1) if name_m else fname[40:80]

    results.append((size, addr, name, bl_count, inject[:120]))

results.sort(key=lambda x: (x[3], x[0]))  # sort by bl_count then size

print(f"Virgin 30-50B inject stubs: {len(results)} total")
print()
print("NO-BL (simplest):")
for size, addr, name, bl, inject in results:
    if bl == 0:
        print(f"  {addr} ({size}B) {name}")
        print(f"    {inject}")

print()
print("ONE-BL:")
for size, addr, name, bl, inject in results:
    if bl == 1:
        print(f"  {addr} ({size}B) {name}")

print()
total_no_bl = sum(1 for r in results if r[3] == 0)
total_one_bl = sum(1 for r in results if r[3] == 1)
total_two_bl = sum(1 for r in results if r[3] == 2)
total_many_bl = sum(1 for r in results if r[3] > 2)
print(f"Summary: 0bl={total_no_bl}, 1bl={total_one_bl}, 2bl={total_two_bl}, >2bl={total_many_bl}")
