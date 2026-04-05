#!/usr/bin/env python3
"""
Pattern classifier for 65-128B functions in asm_decomp.

Classifies functions by pattern type to identify which are likely matchable
vs VERSION_DIFF.
"""

import os
import re
import sys
from pathlib import Path
from collections import defaultdict


def extract_functions_from_file(filepath):
    """Extract all 65-128B functions from a asm_decomp file."""
    with open(filepath, 'r') as f:
        content = f.read()
    
    functions = []
    lines = content.split('\n')
    i = 0
    
    while i < len(lines):
        line = lines[i]
        match = re.match(r'// (0x[0-9a-fA-F]+) \(([0-9]+) bytes\)', line)
        if match:
            addr = match.group(1)
            size = int(match.group(2))
            
            # Only process 65-128B functions
            if 65 <= size <= 128:
                # Get function name from next line
                func_name = ''
                if i + 1 < len(lines):
                    func_name_match = re.match(r'// (.+)', lines[i + 1])
                    if func_name_match:
                        func_name = func_name_match.group(1).strip()
                
                # Extract asm body
                asm_body = []
                j = i + 4  # Skip to asm body
                while j < len(lines) and '__builtin_unreachable' not in lines[j]:
                    asm_line = lines[j].strip()
                    if asm_line.startswith('"') and asm_line.endswith('"'):
                        # Extract instruction from "instr\n"
                        instr = asm_line[1:-1].replace('\\n', '').strip()
                        if instr and not instr.startswith('.'):
                            asm_body.append(instr)
                    j += 1
                
                functions.append({
                    'addr': addr,
                    'size': size,
                    'name': func_name,
                    'asm': '\n'.join(asm_body),
                    'file': os.path.basename(filepath),
                })
        i += 1
    
    return functions


def classify_function(func):
    """Classify a single function by its patterns."""
    asm = func['asm'].lower()
    classifications = []
    
    # Check for vtable thunk pattern
    if 'lha r' in asm and 'lwz r' in asm and 'add r' in asm and 'mtlr' in asm and 'blrl' in asm:
        classifications.append('VTABLE_THUNK')
    
    # Check for atomic operations
    if 'lwarx' in asm or 'stwcx' in asm:
        classifications.append('ATOMIC')
    
    # Check for SDA-relative
    if '(r13)' in asm:
        classifications.append('SDA_RELATIVE')
    
    # Check for float operations
    if 'lfs ' in asm or 'stfs ' in asm:
        classifications.append('FLOAT_OPS')
    
    # Check for bit manipulation
    if 'rlwinm' in asm or 'rlwimi' in asm:
        classifications.append('BIT_MANIP')
    
    # Check for constructor pattern
    if 'lis r' in asm and 'stw r' in asm and '0(r3)' in asm:
        # But not if it's a vtable thunk
        if 'VTABLE_THUNK' not in classifications:
            classifications.append('CONSTRUCTOR')
    
    # Check for leaf function
    has_call = 'bl ' in asm or 'blrl' in asm
    has_stack_frame = 'stwu r1' in asm or 'mflr r0' in asm
    if not has_call and not has_stack_frame and 'blr' in asm:
        classifications.append('LEAF')
    
    # Check for simple call (has bl but no vtable/atomic)
    if has_call and 'VTABLE_THUNK' not in classifications and 'ATOMIC' not in classifications:
        classifications.append('SIMPLE_CALL')
    
    # If no specific classification, mark as OTHER
    if not classifications:
        classifications.append('OTHER')
    
    return classifications


def main():
    """Main entry point."""
    asm_decomp_dir = Path('src/asm_decomp')
    
    if not asm_decomp_dir.exists():
        print(f"Error: {asm_decomp_dir} does not exist")
        sys.exit(1)
    
    print("Scanning asm_decomp files for 65-128B functions...")
    print("=" * 70)
    
    all_functions = []
    
    # Process all cpp files in asm_decomp
    for cpp_file in sorted(asm_decomp_dir.glob('*.cpp')):
        functions = extract_functions_from_file(cpp_file)
        all_functions.extend(functions)
        if functions:
            print(f"{cpp_file.name}: {len(functions)} functions (65-128B)")
    
    print("=" * 70)
    print(f"Total 65-128B functions: {len(all_functions)}")
    print()
    
    if not all_functions:
        print("No 65-128B functions found!")
        return
    
    # Classify all functions
    print("Classifying functions...")
    print("=" * 70)
    
    by_pattern = defaultdict(list)
    
    for func in all_functions:
        patterns = classify_function(func)
        func['patterns'] = patterns
        
        for p in patterns:
            by_pattern[p].append(func)
    
    # Print summary by pattern
    print("\n=== CLASSIFICATION SUMMARY ===\n")
    
    pattern_order = ['VTABLE_THUNK', 'ATOMIC', 'SDA_RELATIVE', 'FLOAT_OPS', 
                     'BIT_MANIP', 'LEAF', 'CONSTRUCTOR', 'SIMPLE_CALL', 'OTHER']
    
    for pattern_name in pattern_order:
        funcs = by_pattern.get(pattern_name, [])
        if funcs:
            print(f"\n{pattern_name}: {len(funcs)} functions")
            
            # Show first 5 examples
            for func in funcs[:5]:
                print(f"     {func['addr']} ({func['size']}B): {func['name'][:50]}")
            if len(funcs) > 5:
                print(f"     ... and {len(funcs) - 5} more")
    
    print("\n" + "=" * 70)
    print("SUMMARY:")
    targetable = len(by_pattern.get('LEAF', [])) + len(by_pattern.get('CONSTRUCTOR', []))
    version_diff = (len(by_pattern.get('VTABLE_THUNK', [])) + 
                   len(by_pattern.get('ATOMIC', [])) +
                   len(by_pattern.get('SDA_RELATIVE', [])))
    maybe = (len(by_pattern.get('SIMPLE_CALL', [])) +
            len(by_pattern.get('FLOAT_OPS', [])) +
            len(by_pattern.get('BIT_MANIP', [])) +
            len(by_pattern.get('OTHER', [])))
    
    print(f"  TARGETABLE (LEAF + CONSTRUCTOR):   {targetable}")
    print(f"  VERSION_DIFF (VTABLE + ATOMIC):    {version_diff}")
    print(f"  MAYBE (other patterns):            {maybe}")
    print(f"  TOTAL:                             {len(all_functions)}")
    print("=" * 70)
    
    # Export targetable list
    targetable_file = Path('targetable_functions.txt')
    with open(targetable_file, 'w') as f:
        f.write("# Targetable 65-128B functions (likely matchable with v3.93)\n")
        f.write("# Format: address size file function_name\n\n")
        
        for pattern in ['LEAF', 'CONSTRUCTOR']:
            funcs = by_pattern.get(pattern, [])
            for func in sorted(funcs, key=lambda x: x['size']):
                f.write(f"{func['addr']} {func['size']} {func['file']} {func['name']}\n")
    
    print(f"\nTargetable functions list saved to: {targetable_file}")
    
    # Export VERSION_DIFF list
    version_diff_file = Path('version_diff_functions.txt')
    with open(version_diff_file, 'w') as f:
        f.write("# VERSION_DIFF 65-128B functions (require v1.76 compiler)\n")
        f.write("# Format: address size file function_name patterns\n\n")
        
        for pattern in ['VTABLE_THUNK', 'ATOMIC', 'SDA_RELATIVE']:
            funcs = by_pattern.get(pattern, [])
            for func in sorted(funcs, key=lambda x: x['size']):
                f.write(f"{func['addr']} {func['size']} {func['file']} {func['name']} {','.join(func['patterns'])}\n")
    
    print(f"VERSION_DIFF functions list saved to: {version_diff_file}")


if __name__ == '__main__':
    main()
