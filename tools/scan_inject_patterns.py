#!/usr/bin/env python3
"""Scan inject stubs and classify by matchable pattern."""
import os, re, glob, sys

agent_dir = "src/matched/agent"
files = sorted(glob.glob(f"{agent_dir}/match_*.cpp"))

def parse_inject(content):
    m = re.search(r'ASMPROC_inject_before:\s*before="([^"]+)"\s+lines="([^"]+)"', content)
    if not m:
        return None, None
    return m.group(1), m.group(2)

def get_size(content):
    m = re.search(r'0x[0-9a-fA-F]+ \w[^\n]+\((\d+)B\)', content)
    if m:
        return int(m.group(1))
    return 0

patterns = {
    'zero_two_globals': [],
    'zero_two_struct_fields': [],
    'set_single_global_0': [],
    'set_single_global_1': [],
    'set_two_fn_ptr_globals': [],
    'sda_short_exchange': [],
    'lbzx_extsb_getter': [],
    'same_var_two_loads': [],
    'three_zeros': [],
    'other_linear': [],
}

inject_total = 0
for f in files:
    with open(f) as fh:
        content = fh.read()
    before, lines = parse_inject(content)
    if lines is None:
        continue
    inject_total += 1
    insns = [x.strip() for x in re.split(r'[;]+', lines.replace('\\n', ';')) if x.strip()]
    if not insns:
        continue
    # Only want simple linear stubs: ≤8 instructions, no bl_ calls, no labels
    joined_raw = ' '.join(insns)
    if len(insns) > 8:
        continue
    if re.search(r'bl _s', joined_raw):
        continue
    if re.search(r'\d+:', joined_raw):  # label markers
        continue
    size = get_size(content)
    fname = os.path.basename(f)
    addr_m = re.search(r'match_(0x[0-9a-fA-F]+)_', fname)
    addr = addr_m.group(1) if addr_m else '?'
    joined = ' '.join(insns)

    if re.search(r'li 0,0.{0,30}stw 0,.*\(13\).{0,30}stw 0,.*\(13\)', joined):
        patterns['zero_two_globals'].append((addr, fname, insns))
    elif re.search(r'li 0,0.{0,30}stw 0,.*\(3\).{0,30}stw 0,.*\(3\)', joined):
        patterns['zero_two_struct_fields'].append((addr, fname, insns))
    elif re.match(r'^li 0,0 stw 0,\S+\(13\)$', joined):
        patterns['set_single_global_0'].append((addr, fname, insns))
    elif re.search(r'li 0,1 stw 0,.*\(13\)', joined) and joined.count('stw') == 1:
        patterns['set_single_global_1'].append((addr, fname, insns))
    elif re.search(r'stw 3,\S+\(13\) stw 4,\S+\(13\)', joined) and 'li' not in joined:
        patterns['set_two_fn_ptr_globals'].append((addr, fname, insns))
    elif re.search(r'lhz 0,\S+\(13\).*sth.*mr 3,0', joined):
        patterns['sda_short_exchange'].append((addr, fname, insns))
    elif re.search(r'addi.*lbzx.*extsb', joined):
        patterns['lbzx_extsb_getter'].append((addr, fname, insns))
    elif re.search(r'lwz 0,\S+ stw 0,\S+ lwz 0,\S+ stw 0,\S+', joined):
        patterns['same_var_two_loads'].append((addr, fname, insns))
    elif joined.count('stw 0,') >= 3 and 'li 0,0' in joined:
        patterns['three_zeros'].append((addr, fname, insns))
    else:
        patterns['other_linear'].append((addr, fname, insns, before, size))

print(f"Total inject stubs: {inject_total}")
print()
for pname, items in patterns.items():
    print(f"  {pname}: {len(items)}")

print()
for pname in ['zero_two_globals','set_single_global_1','set_single_global_0',
              'set_two_fn_ptr_globals','sda_short_exchange','lbzx_extsb_getter',
              'same_var_two_loads','zero_two_struct_fields','three_zeros','other_linear']:
    items = patterns[pname]
    if not items:
        continue
    print(f"=== {pname.upper()} ({len(items)} total) ===")
    for item in items:
        if len(item) == 5:
            addr, fname, insns, before, size = item
            print(f"  {addr} ({size}B,before={before}): {' | '.join(insns)}")
        else:
            addr, fname, insns = item
            print(f"  {addr}: {' | '.join(insns)}")
    print()
