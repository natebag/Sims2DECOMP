import re

keywords = ['audio', 'sound', 'effect', 'music', 'sfx']

with open('config/symbols.txt') as f:
    for line in f:
        if not any(k in line.lower() for k in keywords):
            continue
        m = re.search(r'size:0x([0-9a-fA-F]+)', line)
        if not m:
            continue
        size = int(m.group(1), 16)
        if 24 <= size <= 32:
            addr = re.search(r'0x([0-9a-fA-F]{8})', line)
            name = line.split('=')[0].strip()
            if addr and name:
                print(f"{addr.group(0)} {size}B {name}")
