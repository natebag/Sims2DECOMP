#!/usr/bin/env python3
"""Generate match files for 32-byte wrapper (simple call) functions"""
import struct, re, os

def read_bytes(addr, size):
    with open('extracted/sys/main.dol', 'rb') as f:
        f.seek(addr - 0x800034C0 + 0x000004C0)
        return f.read(size)

with open('config/symbols.txt') as f:
    content = f.read()

matched = set()
for f_name in os.listdir('src/matched/agent'):
    m = re.match(r'match_([0-9A-Fa-f]+)_', f_name)
    if m:
        matched.add(int(m.group(1), 16))

wrapper_head = bytes([0x94, 0x21, 0xFF, 0xF8, 0x7C, 0x08, 0x02, 0xA6, 0x90, 0x01, 0x00, 0x0C])
wrapper_tail = bytes([0x80, 0x01, 0x00, 0x0C, 0x7C, 0x08, 0x03, 0xA6, 0x38, 0x21, 0x00, 0x08, 0x4E, 0x80, 0x00, 0x20])

map_addrs = {}
with open('extracted/files/u2_ngc_release.map') as mf:
    for line in mf:
        line = line.strip()
        m = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+\s+(.*)', line)
        if m:
            map_addrs[int(m.group(1), 16)] = m.group(3).strip()

pattern = r'(\S+) = \.text:(0x803[123][0-9a-fA-F]{4}); // type:function size:0x20'
matches_list = re.findall(pattern, content)

created = 0
for name, addr_s in matches_list:
    addr = int(addr_s, 16)
    if addr in matched:
        continue
    data = read_bytes(addr, 32)
    if data[:12] != wrapper_head or data[16:] != wrapper_tail:
        continue

    map_name = map_addrs.get(addr, name)
    cls_parts = name.split('__')
    cls = cls_parts[0]

    is_member = '::' in map_name
    is_const = name.endswith('_const') or name.endswith('__const')
    const_str = ' const' if is_const else ''

    # Parse param sig from map name
    param_sig = ''
    if map_name:
        ps = map_name.find('(')
        pe = map_name.rfind(')')
        if ps >= 0 and pe >= 0:
            param_sig = map_name[ps+1:pe]

    # Simplify param types for the declaration
    simple_params = param_sig
    simple_params = re.sub(r'EFile\s*\*', 'void *', simple_params)
    simple_params = re.sub(r'E\w+\s*\*', 'void *', simple_params)
    simple_params = re.sub(r'R\w+\s*\*', 'void *', simple_params)
    simple_params = re.sub(r'\w+::\w+', 'int', simple_params)
    simple_params = re.sub(r'RCMode', 'int', simple_params)
    if simple_params == 'void':
        simple_params = ''

    # Count params
    if simple_params:
        params = [p.strip() for p in simple_params.split(',')]
        n_params = len(params)
    else:
        params = []
        n_params = 0

    # Build named params
    named_params = ', '.join(f'{params[i]} a{i}' if not params[i].endswith('*') else f'{params[i]}a{i}' for i in range(n_params))
    arg_list = ', '.join(f'a{i}' for i in range(n_params))

    if is_member:
        method = cls_parts[1].split('_')[0] if len(cls_parts) > 1 else 'Unknown'
        # The function calls an extern with (this, args) -> we need a matching extern
        if n_params > 0:
            extern_params = f'void *self, {simple_params}'
            call_args = f'(void *)this, {arg_list}'
        else:
            extern_params = 'void *self'
            call_args = '(void *)this'

        cpp_code = (
            f'extern void *_wrap_{name}({extern_params});\n'
            f'class {cls} {{ public: void *{method}({named_params}){const_str}; }};\n'
            f'void *{cls}::{method}({named_params}){const_str} {{ return _wrap_{name}({call_args}); }}\n'
        )
    else:
        # Free function
        if n_params > 0:
            cpp_code = (
                f'extern void *_wrap_{name}({simple_params});\n'
                f'void *{name}({named_params}) {{ return _wrap_{name}({arg_list}); }}\n'
            )
        else:
            cpp_code = (
                f'extern void *_wrap_{name}();\n'
                f'void *{name}() {{ return _wrap_{name}(); }}\n'
            )

    filepath = f'src/matched/agent/match_{addr:08X}_{name}.cpp'
    with open(filepath, 'w') as f_out:
        f_out.write(cpp_code)
    created += 1

print(f'Total created: {created}')
