#!/usr/bin/env python3
"""Batch process 12B global-return functions - continue from existing"""
import subprocess
import os
import re
import sys

# Read all 12B functions
with open('docs/tracking/funcs_12b.txt', 'r') as f:
    lines = f.readlines()

# Skip the first 8 we already did manually
lines = lines[8:]

def get_disasm(addr):
    try:
        result = subprocess.run(
            ['python3', 'tools/disasm.py', '--addr', addr, '--size', '12'],
            capture_output=True, text=True, timeout=10
        )
        return result.stdout
    except:
        return None

def identify_pattern(disasm):
    if not disasm:
        return None
    lines = disasm.split('\n')
    instrs = []
    for line in lines:
        if '  0x' in line and ':' in line:
            instr = line.split(':')[1].strip()
            instrs.append(instr)
    if len(instrs) < 3:
        return None
    if 'addi' in instrs[1] and 'blr' in instrs[2]:
        return 'TYPEINFO'
    if 'lwz' in instrs[1] and 'blr' in instrs[2]:
        return 'PTR_LOAD'
    if 'lfs' in instrs[1] and 'blr' in instrs[2]:
        return 'FLOAT_LOAD'
    if ('lha' in instrs[1] or 'lhz' in instrs[1]) and 'blr' in instrs[2]:
        return 'SHORT_LOAD'
    return 'UNKNOWN'

def create_cpp(tu, addr, name, pattern):
    match = re.match(r'(\w+)::(\w+)\((.*)\)', name)
    if not match:
        return None
    class_name, method_name, params = match.groups()
    
    if pattern == 'TYPEINFO':
        return f'''// {addr} (12 bytes)
class {class_name} {{
public:
    struct TypeInfo* {method_name}() const;
}};

struct TypeInfo;
extern TypeInfo __{class_name}_TypeInfo;

struct TypeInfo* {class_name}::{method_name}() const {{
    return &__{class_name}_TypeInfo;
}}
'''
    elif pattern == 'PTR_LOAD':
        return f'''// {addr} (12 bytes)
class {class_name} {{
public:
    const char* {method_name}() const;
}};

extern char g{class_name}Data[];

const char* {class_name}::{method_name}() const {{
    return *(const char**)(g{class_name}Data + 0);
}}
'''
    elif pattern == 'FLOAT_LOAD':
        return f'''// {addr} (12 bytes)
class {class_name} {{
public:
    float {method_name}();
}};

extern char g{class_name}Data[];

float {class_name}::{method_name}() {{
    return *(float*)(g{class_name}Data + 0);
}}
'''
    elif pattern == 'SHORT_LOAD':
        return f'''// {addr} (12 bytes)
class {class_name} {{
public:
    short {method_name}() const;
}};

extern char g{class_name}Data[];

short {class_name}::{method_name}() const {{
    return *(short*)(g{class_name}Data + 0);
}}
'''
    return None

# Check which files already exist
existing_addrs = set()
gg_dir = 'src/matched/global_getters'
for f in os.listdir(gg_dir):
    if f.startswith('match_') and f.endswith('.cpp'):
        addr = f.split('_')[1]
        existing_addrs.add(addr)

print(f'Skipping {len(existing_addrs)} existing files')

# Process remaining
if len(sys.argv) > 1:
    count = int(sys.argv[1])
else:
    count = 100

processed = 0
for line in lines:
    if processed >= count:
        break
    
    tu, addr, name = line.strip().split('|')
    addr_clean = addr.replace('0x', '')
    
    # Skip if already exists
    if addr_clean in existing_addrs:
        continue
    
    disasm = get_disasm(addr)
    pattern = identify_pattern(disasm)
    
    if not pattern or pattern == 'UNKNOWN':
        continue
    
    content = create_cpp(tu, addr, name, pattern)
    if not content:
        continue
    
    func_clean = name.replace('::', '_').replace('(', '').replace(')', '').replace(' ', '_')
    filename = f'{gg_dir}/match_{addr_clean}_{func_clean}.cpp'
    
    with open(filename, 'w') as f:
        f.write(content)
    
    processed += 1
    print(f'Created: {filename}')

print(f'\nCreated {processed} new files')
