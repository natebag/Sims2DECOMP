#!/usr/bin/env python3
"""Batch process 12B global-return functions"""
import subprocess
import os
import re
import sys

# Read all 12B functions
with open('docs/tracking/funcs_12b.txt', 'r') as f:
    lines = f.readlines()

# Skip the first 8 we already did  
lines = lines[8:]

def get_disasm(addr):
    """Get disassembly for a 12B function"""
    try:
        result = subprocess.run(
            ['python3', 'tools/disasm.py', '--addr', addr, '--size', '12'],
            capture_output=True, text=True, timeout=10
        )
        return result.stdout
    except:
        return None

def identify_pattern(disasm):
    """Identify the instruction pattern"""
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
    
    # Check for lis + addi + blr (return address)
    if 'addi' in instrs[1] and 'blr' in instrs[2]:
        return 'TYPEINFO'
    
    # Check for lis + lwz + blr (return pointer value)
    if 'lwz' in instrs[1] and 'blr' in instrs[2]:
        return 'PTR_LOAD'
    
    # Check for lis + lfs + blr (return float)
    if 'lfs' in instrs[1] and 'blr' in instrs[2]:
        return 'FLOAT_LOAD'
    
    # Check for lis + lha/lhz + blr (return short)
    if ('lha' in instrs[1] or 'lhz' in instrs[1]) and 'blr' in instrs[2]:
        return 'SHORT_LOAD'
    
    return 'UNKNOWN'

def create_cpp(tu, addr, name, pattern):
    """Generate C++ code based on pattern"""
    match = re.match(r'(\w+)::(\w+)\((.*)\)', name)
    if not match:
        return None
    
    class_name, method_name, params = match.groups()
    
    if pattern == 'TYPEINFO':
        content = f'''// {addr} (12 bytes)
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
        content = f'''// {addr} (12 bytes)
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
        content = f'''// {addr} (12 bytes)
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
        content = f'''// {addr} (12 bytes)
class {class_name} {{
public:
    short {method_name}() const;
}};

extern char g{class_name}Data[];

short {class_name}::{method_name}() const {{
    return *(short*)(g{class_name}Data + 0);
}}
'''
    else:
        return None
    
    return content

def verify_match(filepath, addr):
    """Run verify_match.sh and check result"""
    try:
        result = subprocess.run(
            ['bash', 'tools/verify_match.sh', filepath, addr, '12'],
            capture_output=True, text=True, timeout=30
        )
        return 'MATCH!' in result.stdout
    except:
        return False

# Main batch processing
if len(sys.argv) > 1:
    count = int(sys.argv[1])
else:
    count = 50  # Default batch size

batch = lines[:count]
print(f'Processing {len(batch)} functions...')

matched = 0
failed = 0

for line in batch:
    tu, addr, name = line.strip().split('|')
    
    # Get disassembly and identify pattern
    disasm = get_disasm(addr)
    pattern = identify_pattern(disasm)
    
    if not pattern or pattern == 'UNKNOWN':
        print(f'SKIP: {name} - unknown pattern')
        failed += 1
        continue
    
    # Generate C++ file
    content = create_cpp(tu, addr, name, pattern)
    if not content:
        print(f'SKIP: {name} - could not generate code')
        failed += 1
        continue
    
    # Write file
    addr_clean = addr.replace('0x', '')
    func_clean = name.replace('::', '_').replace('(', '').replace(')', '').replace(' ', '_')
    filename = f'src/matched/global_getters/match_{addr_clean}_{func_clean}.cpp'
    
    with open(filename, 'w') as f:
        f.write(content)
    
    # Verify match
    if verify_match(filename, addr):
        print(f'MATCH: {name}')
        matched += 1
    else:
        print(f'FAIL: {name}')
        failed += 1

print(f'\nBatch complete: {matched} matched, {failed} failed')
