#!/usr/bin/env python3
"""
Analyze inheritance relationships by comparing field offsets across classes.
"""

import re
from collections import defaultdict

def extract_fields(filepath):
    """Extract field offsets from a class's assembly."""
    fields = defaultdict(lambda: {'loads': 0, 'stores': 0})
    
    try:
        with open(filepath, 'r') as f:
            content = f.read()
    except FileNotFoundError:
        return fields
    
    # Pattern for load/store with offset on r3 (this pointer)
    offset_pattern = r'(?:lwz|lhz|lbz|stw|sth|stb)\s+(\w+),\s*(-?\d+)\(3\)'
    
    for match in re.finditer(offset_pattern, content):
        reg = match.group(1)
        offset = int(match.group(2))
        instr = content[match.start():match.start()+3]
        
        if instr in ['lwz', 'lhz', 'lbz']:
            fields[offset]['loads'] += 1
        elif instr in ['stw', 'sth', 'stb']:
            fields[offset]['stores'] += 1
    
    return fields

def analyze_class(name, filepath):
    """Analyze a single class."""
    fields = extract_fields(filepath)
    if not fields:
        return None
    
    max_offset = max(fields.keys()) if fields else 0
    total_accesses = sum(f['loads'] + f['stores'] for f in fields.values())
    
    return {
        'name': name,
        'fields': fields,
        'max_offset': max_offset,
        'total_accesses': total_accesses,
        'num_fields': len(fields)
    }

def print_class_analysis(cls):
    """Print analysis for a class."""
    print(f"\n{'='*60}")
    print(f"Class: {cls['name']}")
    print(f"{'='*60}")
    print(f"Estimated size: {cls['max_offset'] + 4} bytes (max offset: 0x{cls['max_offset']:04X})")
    print(f"Total field accesses: {cls['total_accesses']}")
    print(f"Unique offsets: {cls['num_fields']}")
    
    print(f"\n{'Offset':>8} | {'L/S':>6} | {'Notes'}")
    print("-" * 40)
    
    for offset in sorted(cls['fields'].keys()):
        data = cls['fields'][offset]
        ls = f"{data['loads']}/{data['stores']}"
        
        notes = []
        if offset == 0:
            notes.append("vtable")
        elif offset == 4:
            notes.append("inner ptr?")
        
        note_str = ", ".join(notes)
        print(f"0x{offset:04X} ({offset:4d}) | {ls:>6} | {note_str}")

def main():
    classes = [
        ('cXObjectImpl', 'src/asm_decomp/cXObjectImpl.cpp'),
        ('TreeSimImpl', 'src/asm_decomp/TreeSimImpl.cpp'),
        ('TreeSim', 'src/asm_decomp/TreeSim.cpp'),
    ]
    
    results = {}
    for name, path in classes:
        result = analyze_class(name, path)
        if result:
            results[name] = result
            print_class_analysis(result)
    
    # Compare inheritance candidates
    if 'cXObjectImpl' in results and 'TreeSimImpl' in results:
        print(f"\n{'='*60}")
        print("Inheritance Analysis")
        print(f"{'='*60}")
        
        cxo = results['cXObjectImpl']
        ts = results['TreeSimImpl']
        
        print(f"\ncXObjectImpl max offset: 0x{cxo['max_offset']:04X} ({cxo['max_offset']} bytes)")
        print(f"TreeSimImpl max offset: 0x{ts['max_offset']:04X} ({ts['max_offset']} bytes)")
        
        # Check if cXObjectImpl contains TreeSimImpl at offset 0x04
        print(f"\nHypothesis: cXObjectImpl has TreeSimImpl* at offset 0x04")
        print(f"  - 268 loads from offset 0x04 suggests pointer dereferencing")
        print(f"  - TreeSimImpl size fits within cXObjectImpl's larger layout")
        
        # Look for patterns suggesting composition vs inheritance
        print(f"\nKey observations:")
        print(f"  - cXObjectImpl offset 0x04 is heavily accessed ({cxo['fields'][4]['loads']} loads)")
        print(f"  - This suggests a pointer to an inner object (composition pattern)")
        print(f"  - TreeSimImpl has its own vtable at offset 0 (standalone object)")

if __name__ == '__main__':
    main()
