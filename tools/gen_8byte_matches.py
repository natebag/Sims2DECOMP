#!/usr/bin/env python3
"""Generate match files for 8-byte getter/setter functions in range 0x80310000-0x80340000"""
import struct, re, os

def addr_to_file_offset(addr):
    return addr - 0x800034C0 + 0x000004C0

def read_bytes(addr, size):
    with open('extracted/sys/main.dol', 'rb') as f:
        f.seek(addr_to_file_offset(addr))
        return f.read(size)

# Parse symbols.txt for 8-byte functions in range
with open('config/symbols.txt') as f:
    content = f.read()

pattern = r'(\S+) = \.text:(0x803[123][0-9a-fA-F]{4}); // type:function size:0x8'
matches_list = re.findall(pattern, content)

# Already matched
matched = set()
for f_name in os.listdir('src/matched/agent'):
    m = re.match(r'match_([0-9A-Fa-f]+)_', f_name)
    if m:
        matched.add(int(m.group(1), 16))

# Map file for original names
map_addrs = {}
with open('extracted/files/u2_ngc_release.map') as f:
    for line in f:
        line = line.strip()
        m = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+\s+(.*)', line)
        if m:
            addr_val = int(m.group(1), 16)
            map_addrs[addr_val] = m.group(3).strip()

created = 0

for name, addr_s in matches_list:
    addr = int(addr_s, 16)
    if addr in matched:
        continue
    if addr < 0x80310000 or addr >= 0x80340000:
        continue
    data = read_bytes(addr, 8)
    w0, w1 = struct.unpack('>II', data)
    if w1 != 0x4E800020:
        continue

    op0 = (w0 >> 26) & 0x3F
    rt = (w0 >> 21) & 0x1F
    ra = (w0 >> 16) & 0x1F
    rb = (w0 >> 11) & 0x1F
    d = w0 & 0xFFFF
    if d & 0x8000:
        d -= 0x10000

    map_name = map_addrs.get(addr, '')
    cls_parts = name.split('__')
    cls = cls_parts[0]
    method_with_params = '__'.join(cls_parts[1:]) if len(cls_parts) > 1 else 'Unknown'
    method = cls_parts[1].split('_')[0] if len(cls_parts) > 1 else 'Unknown'

    cpp_code = None

    # Pattern 1: lwz r3, offset(r3) / blr -> member getter returning int/ptr
    if op0 == 32 and ra == 3 and rt == 3:
        is_const = name.endswith('_const') or name.endswith('__const')
        const_str = ' const' if is_const else ''
        cpp_code = (
            f'class {cls} {{ char pad[{d}]; int m_val; public: int {method}(){const_str}; }};\n'
            f'int {cls}::{method}(){const_str} {{ return m_val; }}\n'
        )

    # Pattern 2: lbz r3, offset(r3) / blr -> member getter returning unsigned char
    elif op0 == 34 and ra == 3 and rt == 3:
        cpp_code = (
            f'class {cls} {{ char pad[{d}]; unsigned char m_val; public: unsigned char {method}(); }};\n'
            f'unsigned char {cls}::{method}() {{ return m_val; }}\n'
        )

    # Pattern 3: lha r3, offset(r3) / blr -> member getter returning signed short
    elif op0 == 42 and ra == 3 and rt == 3:
        cpp_code = (
            f'class {cls} {{ char pad[{d}]; short m_val; public: short {method}(); }};\n'
            f'short {cls}::{method}() {{ return m_val; }}\n'
        )

    # Pattern 4: lhz r3, offset(r3) / blr -> member getter returning unsigned short
    elif op0 == 40 and ra == 3 and rt == 3:
        cpp_code = (
            f'class {cls} {{ char pad[{d}]; unsigned short m_val; public: unsigned short {method}(); }};\n'
            f'unsigned short {cls}::{method}() {{ return m_val; }}\n'
        )

    # Pattern 5: lfs f1, offset(r3) / blr -> member getter returning float
    elif op0 == 48 and ra == 3 and rt == 1:
        is_const = name.endswith('_const') or name.endswith('__const')
        const_str = ' const' if is_const else ''
        cpp_code = (
            f'class {cls} {{ char pad[{d}]; float m_val; public: float {method}(){const_str}; }};\n'
            f'float {cls}::{method}(){const_str} {{ return m_val; }}\n'
        )

    # Pattern 6: li r3, val / blr -> return constant
    elif op0 == 14 and ra == 0 and rt == 3:
        val = d
        # Determine parameters from the symbol name
        # Parse map_name for proper signature
        param_sig = ''
        if map_name:
            paren_start = map_name.find('(')
            paren_end = map_name.rfind(')')
            if paren_start >= 0 and paren_end >= 0:
                param_sig = map_name[paren_start+1:paren_end]

        if param_sig == 'void' or param_sig == '':
            param_decl = ''
        elif param_sig == 'EResource *':
            param_decl = 'EResource *'
        elif param_sig == 'int':
            param_decl = 'int'
        elif param_sig == 'EVoice *':
            param_decl = 'void *'
        elif param_sig == 'unsigned char':
            param_decl = 'unsigned char'
        else:
            # Generic - just use the raw params
            # Replace pointer types with void *
            param_decl = re.sub(r'\w[\w:]*\s*\*', 'void *', param_sig)

        is_const = map_name.endswith(' const') if map_name else (name.endswith('_const') or name.endswith('__const'))
        const_str = ' const' if is_const else ''

        # Forward declare if needed
        fwd = ''
        if 'EResource *' in param_decl:
            fwd = 'class EResource;\n'
        if 'EMC_Operation' in param_sig:
            # Complex signature, generate carefully
            param_decl = re.sub(r'EMC_Operation\s*\*', 'void *', param_decl)
            param_decl = re.sub(r'EMC_Operation\s*&', 'int &', param_decl)

        cpp_code = (
            f'{fwd}'
            f'class {cls} {{ public: int {method}({param_decl}){const_str}; }};\n'
            f'int {cls}::{method}({param_decl}){const_str} {{ return {val}; }}\n'
        )

    # Pattern 7: stw r4, offset(r3) / blr -> member setter (int/ptr param)
    elif op0 == 36 and ra == 3 and rt == 4:
        # Determine param type
        param_type = 'int'
        if 'bool' in name.lower():
            param_type = 'bool'
        elif 'unsigned_int' in name:
            param_type = 'unsigned int'
        elif 'MovieId' in name:
            param_type = 'unsigned int'

        member_type = 'int' if param_type == 'bool' else param_type

        cpp_code = (
            f'class {cls} {{ char pad[{d}]; {member_type} m_val; public: void {method}({param_type}); }};\n'
            f'void {cls}::{method}({param_type} val) {{ m_val = val; }}\n'
        )

    # Pattern 8: stfs f1, offset(r3) / blr -> member setter (float param)
    elif op0 == 52 and ra == 3 and rt == 1:
        cpp_code = (
            f'class {cls} {{ char pad[{d}]; float m_val; public: void {method}(float); }};\n'
            f'void {cls}::{method}(float val) {{ m_val = val; }}\n'
        )

    # Pattern 9: addi r3, r3, offset / blr -> return pointer to member
    elif op0 == 14 and ra == 3 and rt == 3:
        is_const = name.endswith('_const') or name.endswith('__const')
        const_str = ' const' if is_const else ''
        cpp_code = (
            f'struct Embedded {{ int x; }};\n'
            f'class {cls} {{ char pad[{d}]; Embedded m_val; public: Embedded *{method}(){const_str}; }};\n'
            f'Embedded *{cls}::{method}(){const_str} {{ return &m_val; }}\n'
        )

    # Pattern 10: stb r3, offset(r13) / blr -> static setter via SDA (skip)
    # Pattern 11: lwz r3, offset(r13) / blr -> static getter via SDA (skip)
    elif ra == 13:
        continue

    # Pattern 12: sth r3, offset(r13) / blr -> static setter via SDA (skip)
    elif op0 == 44 and ra == 13:
        continue

    if cpp_code is None:
        print(f'SKIP: {addr:08X} {name} (unhandled pattern op={op0} rt={rt} ra={ra})')
        continue

    safe_name = name
    filepath = f'src/matched/agent/match_{addr:08X}_{safe_name}.cpp'

    with open(filepath, 'w') as f_out:
        f_out.write(cpp_code)

    created += 1
    print(f'Created: match_{addr:08X}_{safe_name}.cpp')

print(f'\nTotal created: {created}')
