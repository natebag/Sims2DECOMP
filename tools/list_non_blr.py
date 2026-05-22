"""List all unmatched functions that don't end with blr."""
import struct, re, glob

DOL_PATH = 'extracted/sys/main.dol'
DOL_TEXT_START = 0x80003100
DOL_FILE_OFFSET = 0x100
BLR = 0x4E800020
BACKSLASH = chr(92)

with open(DOL_PATH, 'rb') as f:
    raw = f.read()

already_matched = set()
for fn in glob.glob('src/matched/**/*.cpp', recursive=True):
    m = re.search(r'match_(0[xX])?([0-9A-Fa-f]{8})_', fn)
    if m:
        already_matched.add(int(m.group(2), 16))

syms = {}
with open('extracted/files/u2_ngc_release_dvd.map') as f:
    for line in f:
        parts = line.split()
        if len(parts) >= 4:
            try:
                addr = int(parts[0], 16)
                size = int(parts[1], 16)
                name = parts[3]
                if BACKSLASH in name or '/' in name: continue
                if size == 0 or name.startswith('.') or name.startswith('<'): continue
                if addr not in syms: syms[addr] = (size, name)
            except: pass

with open('extracted/files/u2_ngc_release.map', errors='replace') as f:
    for line in f:
        parts = line.split()
        if len(parts) >= 4:
            try:
                addr = int(parts[0], 16)
                size = int(parts[1], 16)
                name = parts[3]
                if BACKSLASH in name or '/' in name: continue
                if '.obj' in name or name.startswith('.') or name.startswith('<'): continue
                if size == 0: continue
                if addr not in syms: syms[addr] = (size, name)
            except: pass

non_blr = []
for addr, (size, name) in sorted(syms.items()):
    if addr in already_matched: continue
    if size == 0 or size % 4 != 0: continue
    off = (addr - DOL_TEXT_START) + DOL_FILE_OFFSET
    if off < 0 or off + size > len(raw): continue
    words = struct.unpack('>{}I'.format(size // 4), raw[off:off+size])
    if words[-1] == BLR: continue
    last_w = words[-1]
    op = (last_w >> 26) & 0x3F
    lk = last_w & 1
    # classify last instruction
    if op == 18 and lk == 0:
        li = (last_w >> 2) & 0xFFFFFF
        if li >= 0x800000: li -= 0x1000000
        target = addr + (size - 4) + li * 4
        within = (addr <= target < addr + size)
        kind = 'b-intra' if within else 'b-extern'
    elif op == 19 and ((last_w >> 1) & 0x3FF) == 528 and lk == 0:
        kind = 'bctr'
    else:
        kind = f'op{op}'
    non_blr.append((addr, size, name, last_w, kind))

print(f'Non-BLR unmatched: {len(non_blr)}')
for addr, size, name, last_w, kind in non_blr:
    print(f'  0x{addr:08X} {size:4d}B {kind:<12} 0x{last_w:08X}  {name[:60]}')
