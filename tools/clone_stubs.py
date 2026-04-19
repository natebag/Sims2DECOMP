#!/usr/bin/env python3
"""Generate stub match files for small common DOL patterns."""
import struct, re, os, subprocess, glob, sys

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

existing = set()
# GLOB RECURSIVELY across all matched/ + wip/ dirs — QA-RULE #3
# Accept both 0x-prefix and no-prefix styles, any hex case, 6-8 digits
for root in ('src/matched/**/match_*.cpp', 'src/wip/**/match_*.cpp'):
    for p in glob.glob(root, recursive=True):
        m = re.match(r'match_0?x?([0-9A-Fa-f]{6,8})_', os.path.basename(p))
        if m: existing.add(int(m.group(1), 16))
print(f'[clone_stubs] already_matched index: {len(existing)} addrs across src/matched + src/wip')

funcs = []
with open(MAP_PATH) as f:
    for line in f:
        m = re.match(r'^([0-9a-f]{8}) ([0-9a-f]+) +0 +(.+)$', line)
        if m:
            a = int(m.group(1), 16)
            s = int(m.group(2), 16)
            n = m.group(3).strip()
            funcs.append((a, s, n))

def parse_name(fullname):
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

def sanitize(s):
    return re.sub(r'[^A-Za-z0-9_]', '_', s)[:80]

def parse_args(args):
    s = args[1:-1].strip()
    if s in ('', 'void'): return []
    depth = 0; parts = []; cur = []
    for ch in s:
        if ch in '<(': depth += 1
        elif ch in '>)': depth -= 1
        if ch == ',' and depth == 0:
            parts.append(''.join(cur).strip()); cur = []
        else: cur.append(ch)
    if cur: parts.append(''.join(cur).strip())
    return parts

def typed_params(argtypes):
    if not argtypes: return '(void)'
    return '(' + ', '.join(f'{t} a{i}' for i, t in enumerate(argtypes)) + ')'

def ret_type_for(name):
    """Guess return type from name heuristics."""
    n = name.lower()
    if n.startswith('is') or n.startswith('has') or n.startswith('can') or n.startswith('will'):
        return 'bool'
    if 'count' in n or 'num' in n or 'size' in n or 'index' in n or 'id' in n:
        return 'int'
    if 'volume' in n or 'rate' in n or 'distance' in n or 'speed' in n or 'time' in n or 'radius' in n:
        return 'float'
    return 'int'

def verify(fpath, addr, sz):
    r = subprocess.run(f'bash tools/verify_match.sh {fpath} 0x{addr:08X} {sz}',
                       capture_output=True, text=True, shell=True)
    out = r.stdout + r.stderr
    return 'MATCH!' in out and 'MISMATCH' not in out

def gen_return_const(addr, name, sz, const_val):
    """Generate a stub that returns a constant (0 or 1)."""
    cls, meth, args, is_const = parse_name(name)
    argtypes = parse_args(args)
    param = typed_params(argtypes)
    const_s = ' const' if is_const else ''
    rt = ret_type_for(meth)
    slug = sanitize(f'{cls}_{meth}' if cls else meth)
    fname = f'match_0x{addr:08X}_{slug}.cpp'
    fpath = os.path.join('src/matched/agent', fname)
    if os.path.exists(fpath): return None

    lines = [f'// 0x{addr:08X} ({sz}B) {name}',
             f'// return {const_val} stub.', '']
    if cls:
        lines.append(f'class {cls} {{')
        lines.append('public:')
        lines.append(f'    {rt} {meth}{param}{const_s};')
        lines.append('};')
        lines.append('')
        lines.append(f'{rt} {cls}::{meth}{param}{const_s} {{')
        lines.append(f'    return {const_val};')
        lines.append('}')
    else:
        lines.append(f'{rt} {meth}{param} {{')
        lines.append(f'    return {const_val};')
        lines.append('}')

    with open(fpath, 'w') as f:
        f.write('\n'.join(lines) + '\n')

    if verify(fpath, addr, sz):
        return fpath
    else:
        # try alternate: void, int, bool
        for alt_rt in ['int', 'bool', 'unsigned int', 'void*']:
            if alt_rt == rt: continue
            lines2 = list(lines)
            for i, l in enumerate(lines2):
                lines2[i] = l.replace(f'    {rt} {meth}', f'    {alt_rt} {meth}', 1).replace(f'{rt} {cls}::{meth}' if cls else f'{rt} {meth}', f'{alt_rt} {cls}::{meth}' if cls else f'{alt_rt} {meth}', 1) if (f'{rt} {meth}' in l or (cls and f'{rt} {cls}::{meth}' in l)) else l
            with open(fpath, 'w') as f:
                f.write('\n'.join(lines2) + '\n')
            if verify(fpath, addr, sz):
                return fpath
        os.remove(fpath)
        return None

def gen_getter(addr, name, sz, offset, field_kind='int'):
    """Generate a getter that returns this->field at offset.
    field_kind: 'int' (lwz), 'float' (lfs), 'short' (lha), 'ushort' (lhz)"""
    cls, meth, args, is_const = parse_name(name)
    argtypes = parse_args(args)
    param = typed_params(argtypes)
    const_s = ' const' if is_const else ''

    if field_kind == 'float':
        field_t = 'float'; rt = 'float'
    elif field_kind == 'short':
        field_t = 'short'; rt = 'int'
    elif field_kind == 'ushort':
        field_t = 'unsigned short'; rt = 'int'
    else:
        field_t = 'int'; rt = ret_type_for(meth)
        if rt not in ('int', 'unsigned int', 'bool', 'void*'):
            rt = 'int'

    slug = sanitize(f'{cls}_{meth}' if cls else meth)
    fname = f'match_0x{addr:08X}_{slug}.cpp'
    fpath = os.path.join('src/matched/agent', fname)
    if os.path.exists(fpath): return None

    if not cls: return None
    lines = [f'// 0x{addr:08X} ({sz}B) {name}',
             f'// Getter for {field_t} field at offset 0x{offset:X}.', '']
    lines.append(f'class {cls} {{')
    lines.append('public:')
    if offset > 0:
        lines.append(f'    char pad_000[0x{offset:X}];')
    lines.append(f'    {field_t} m_field_{offset:X};')
    lines.append(f'    {rt} {meth}{param}{const_s};')
    lines.append('};')
    lines.append('')
    lines.append(f'{rt} {cls}::{meth}{param}{const_s} {{')
    lines.append(f'    return m_field_{offset:X};')
    lines.append('}')

    with open(fpath, 'w') as f:
        f.write('\n'.join(lines) + '\n')

    if verify(fpath, addr, sz):
        return fpath
    else:
        os.remove(fpath)
        return None

def gen_setter(addr, name, sz, offset):
    """Generate a setter: this->field = arg (stw r4, offset(r3))."""
    cls, meth, args, is_const = parse_name(name)
    argtypes = parse_args(args)
    # must have >=1 arg
    if len(argtypes) < 1: return None
    param = typed_params(argtypes)
    const_s = ' const' if is_const else ''
    slug = sanitize(f'{cls}_{meth}' if cls else meth)
    fname = f'match_0x{addr:08X}_{slug}.cpp'
    fpath = os.path.join('src/matched/agent', fname)
    if os.path.exists(fpath): return None
    if not cls: return None

    lines = [f'// 0x{addr:08X} ({sz}B) {name}',
             f'// Setter for field at offset 0x{offset:X}.', '']
    lines.append(f'class {cls} {{')
    lines.append('public:')
    if offset > 0:
        lines.append(f'    char pad_000[0x{offset:X}];')
    lines.append(f'    int m_field_{offset:X};')
    lines.append(f'    void {meth}{param}{const_s};')
    lines.append('};')
    lines.append('')
    lines.append(f'void {cls}::{meth}{param}{const_s} {{')
    lines.append(f'    m_field_{offset:X} = (int)a0;')
    lines.append('}')

    with open(fpath, 'w') as f:
        f.write('\n'.join(lines) + '\n')

    if verify(fpath, addr, sz):
        return fpath
    else:
        os.remove(fpath)
        return None

def gen_getter_lwz(addr, name, sz, offset):
    return gen_getter(addr, name, sz, offset, 'int')

def scan_pattern(pattern_hex, sz):
    """Find all unmatched funcs with body == pattern_hex."""
    target = bytes.fromhex(pattern_hex)
    out = []
    for a, s, n in funcs:
        if s != sz: continue
        if a in existing: continue
        off = va_to_off(a)
        if off is None: continue
        if d[off:off+sz] == target:
            out.append((a, n))
    return out

# Patterns to run
PATTERNS = [
    # (name, hex, size, handler_type, arg)
    ('return 0',      '386000004e800020', 8,  'const',  0),
    ('return 1',      '386000014e800020', 8,  'const',  1),
    ('return 2',      '386000024e800020', 8,  'const',  2),
    ('return 4',      '386000044e800020', 8,  'const',  4),
    ('return 5',      '386000054e800020', 8,  'const',  5),
    ('lwz 0(r3)',     '806300004e800020', 8,  'getter', 0x00),
    ('lwz 4(r3)',     '806300044e800020', 8,  'getter', 0x04),
    ('lwz 8(r3)',     '806300084e800020', 8,  'getter', 0x08),
    ('lwz 0xc(r3)',   '8063000c4e800020', 8,  'getter', 0x0c),
    ('lwz 0x10(r3)',  '806300104e800020', 8,  'getter', 0x10),
    ('lwz 0x14(r3)',  '806300144e800020', 8,  'getter', 0x14),
    ('lwz 0x18(r3)',  '806300184e800020', 8,  'getter', 0x18),
    ('lwz 0x1c(r3)',  '8063001c4e800020', 8,  'getter', 0x1c),
    ('lwz 0x20(r3)',  '806300204e800020', 8,  'getter', 0x20),
    ('lwz 0x24(r3)',  '806300244e800020', 8,  'getter', 0x24),
    ('lwz 0x28(r3)',  '806300284e800020', 8,  'getter', 0x28),
    ('lwz 0x30(r3)',  '806300304e800020', 8,  'getter', 0x30),
    ('lwz 0x34(r3)',  '806300344e800020', 8,  'getter', 0x34),
    ('lwz 0x548(r3)', '806305484e800020', 8,  'getter', 0x548),
    ('lfs 0x30(r3)',  'c02300304e800020', 8,  'getter_f', 0x30),
    ('lfs 0x2c(r3)',  'c023002c4e800020', 8,  'getter_f', 0x2c),
    ('lha 4(r3)',     'a86300044e800020', 8,  'getter_s', 0x04),
    ('lha 6(r3)',     'a86300064e800020', 8,  'getter_s', 0x06),
    ('lha 8(r3)',     'a86300084e800020', 8,  'getter_s', 0x08),
    ('lha 0x34(r3)',  'a86300344e800020', 8,  'getter_s', 0x34),
    ('stw 0(r3)',     '908300004e800020', 8,  'setter', 0x00),
    ('stw 0x30(r3)',  '908300304e800020', 8,  'setter', 0x30),
    ('stw 0x34(r3)',  '908300344e800020', 8,  'setter', 0x34),
    ('stw 0x10(r3)',  '908300104e800020', 8,  'setter', 0x10),
]

total_ok = 0; total_fail = 0
for pname, hex_pat, sz, htype, harg in PATTERNS:
    hits = scan_pattern(hex_pat, sz)
    ok = 0; fail = 0
    for addr, name in hits:
        if htype == 'const':
            r = gen_return_const(addr, name, sz, harg)
        elif htype == 'getter':
            r = gen_getter_lwz(addr, name, sz, harg)
        else:
            r = None
        if r: ok += 1
        else: fail += 1
    print(f'{pname:20s}: {ok}/{len(hits)} OK  ({fail} failed)')
    total_ok += ok; total_fail += fail

print(f'\nTOTAL: {total_ok} OK, {total_fail} FAIL')
