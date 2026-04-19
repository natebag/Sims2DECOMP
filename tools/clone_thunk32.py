#!/usr/bin/env python3
"""Generate 32B thunk match files from thunk->target pairs."""
import struct, re, os, subprocess, sys, glob

DOL_PATH = 'extracted/sys/main.dol'
MAP_PATH = 'extracted/files/u2_ngc_release_dvd.map'

with open(DOL_PATH, 'rb') as f:
    d = f.read()
text_off = struct.unpack('>7I', d[0x00:0x1C])
text_addr = struct.unpack('>7I', d[0x48:0x64])
text_size = struct.unpack('>7I', d[0x90:0xAC])

def va_to_off(va):
    for i in range(7):
        if text_size[i] and text_addr[i] <= va < text_addr[i] + text_size[i]:
            return text_off[i] + (va - text_addr[i])
    return None

# Parse map
name_for = {}
size_for = {}
with open(MAP_PATH) as f:
    for line in f:
        m = re.match(r'^([0-9a-f]{8}) ([0-9a-f]+) +0 +(.+)$', line)
        if m:
            a = int(m.group(1), 16)
            name_for[a] = m.group(3).strip()
            size_for[a] = int(m.group(2), 16)

# Find 32B thunks
thunk_sig = bytes.fromhex('9421fff87c0802a69001000c')
thunk_epilog = bytes.fromhex('8001000c7c0803a6382100084e800020')

existing = set()
for p in glob.glob('src/matched/agent/match_*.cpp'):
    m = re.match(r'match_0?x?([0-9A-Fa-f]{8})_', os.path.basename(p))
    if m: existing.add(int(m.group(1), 16))

thunks = []
for addr, name in name_for.items():
    if size_for.get(addr) != 32: continue
    if addr in existing: continue
    off = va_to_off(addr)
    if off is None: continue
    body = d[off:off+32]
    if body[:12] != thunk_sig: continue
    if body[16:32] != thunk_epilog: continue
    bl = struct.unpack('>I', body[12:16])[0]
    if (bl >> 26) != 18 or (bl & 1) != 1: continue
    off_s = bl & 0x03fffffc
    if off_s & 0x02000000: off_s -= 0x04000000
    target = addr + 12 + off_s
    if target not in name_for: continue
    thunks.append((addr, name, target, name_for[target]))

print(f'Found {len(thunks)} 32B thunks to generate')

def parse_name(fullname):
    """Parse C::M(args) → (class_or_None, method, arg_str, is_const)"""
    is_const = fullname.endswith(' const')
    if is_const: fullname = fullname[:-6]
    paren = fullname.find('(')
    if paren < 0: return None, fullname, '', is_const
    pre = fullname[:paren]
    args = fullname[paren:]
    if '::' in pre:
        cls, meth = pre.rsplit('::', 1)
        return cls, meth, args, is_const
    return None, pre, args, is_const

def sanitize_slug(s):
    return re.sub(r'[^A-Za-z0-9_]', '_', s)[:80]

def parse_args(args):
    """Parse '(type1, type2)' → ['type1', 'type2'] balancing angle brackets."""
    s = args[1:-1].strip()
    if s in ('', 'void'): return []
    depth = 0
    parts = []
    cur = []
    for ch in s:
        if ch == '<' or ch == '(': depth += 1
        elif ch == '>' or ch == ')': depth -= 1
        if ch == ',' and depth == 0:
            parts.append(''.join(cur).strip())
            cur = []
        else:
            cur.append(ch)
    if cur: parts.append(''.join(cur).strip())
    return parts

def typed_param_list(argtypes):
    """['int', 'char*'] → '(int a0, char* a1)'; [] → '(void)'"""
    if not argtypes: return '(void)'
    return '(' + ', '.join(f'{t} a{i}' for i, t in enumerate(argtypes)) + ')'

def call_arg_list(argtypes):
    """['int', 'char*'] → 'a0, a1'; [] → ''"""
    return ', '.join(f'a{i}' for i in range(len(argtypes)))

OUT_DIR = 'src/matched/agent'
verify = 'tools/verify_match.sh'

written = []
failed = []
for addr, name, tgt, tname in thunks:
    src_cls, src_meth, src_args, src_const = parse_name(name)
    tgt_cls, tgt_meth, tgt_args, tgt_const = parse_name(tname)
    # slugify for filename
    base_slug = sanitize_slug(f'{src_cls}_{src_meth}' if src_cls else src_meth)
    fname = f'match_0x{addr:08X}_{base_slug}.cpp'
    fpath = os.path.join(OUT_DIR, fname)
    if os.path.exists(fpath):
        continue

    src_argtypes = parse_args(src_args)
    tgt_argtypes = parse_args(tgt_args)
    # Only handle when arity matches
    if len(src_argtypes) != len(tgt_argtypes):
        os.remove(fpath) if os.path.exists(fpath) else None
        continue
    src_param = typed_param_list(src_argtypes)
    tgt_param = typed_param_list(tgt_argtypes)
    pass_args = call_arg_list(src_argtypes)
    const_s = ' const' if src_const else ''
    const_t = ' const' if tgt_const else ''

    lines = [
        f'// 0x{addr:08X} (32B) {name}',
        f'// Thunk to {tname}',
        '',
    ]
    if src_cls and tgt_cls:
        if src_cls == tgt_cls:
            lines.append(f'class {src_cls} {{')
            lines.append('public:')
            lines.append(f'    void {src_meth}{src_param}{const_s};')
            if tgt_meth != src_meth:
                lines.append(f'    void {tgt_meth}{tgt_param}{const_t};')
            lines.append('};')
            lines.append('')
            lines.append(f'void {src_cls}::{src_meth}{src_param}{const_s} {{')
            lines.append(f'    {tgt_meth}({pass_args});')
            lines.append('}')
        else:
            lines.append(f'class {tgt_cls} {{')
            lines.append('public:')
            lines.append(f'    static void {tgt_meth}{tgt_param}{const_t};')
            lines.append('};')
            lines.append('')
            lines.append(f'class {src_cls} {{')
            lines.append('public:')
            lines.append(f'    void {src_meth}{src_param}{const_s};')
            lines.append('};')
            lines.append('')
            lines.append(f'void {src_cls}::{src_meth}{src_param}{const_s} {{')
            lines.append(f'    {tgt_cls}::{tgt_meth}({pass_args});')
            lines.append('}')
    else:
        lines.append(f'extern void {tgt_meth}{tgt_param};')
        lines.append('')
        lines.append(f'void {src_meth}{src_param} {{')
        lines.append(f'    {tgt_meth}({pass_args});')
        lines.append('}')

    src = '\n'.join(lines) + '\n'
    with open(fpath, 'w') as f:
        f.write(src)

    # Verify
    r = subprocess.run(f'bash {verify} {fpath} 0x{addr:08X} 32',
                       capture_output=True, text=True, shell=True)
    out = r.stdout + r.stderr
    if 'MATCH!' in out and 'MISMATCH' not in out:
        written.append(fpath)
        print(f'OK  0x{addr:08X} {name[:50]}')
    else:
        failed.append((fpath, name, out[-200:]))
        os.remove(fpath)
        print(f'FAIL 0x{addr:08X} {name[:50]}')

print(f'\nSuccess: {len(written)}, Failed: {len(failed)}')
