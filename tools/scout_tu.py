#!/usr/bin/env python
import struct
import sys

dol = open('extracted/sys/main.dol', 'rb').read()

def get_bytes(addr, size):
    for i in range(7):
        off = struct.unpack('>I', dol[i*4:i*4+4])[0]
        base = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
        if base <= addr < base + sz:
            return dol[off + (addr - base):off + (addr - base) + size]
    return None

tus = ['person', 'eroom', 'e_rlevel', 'ifloor', 'e_istaticmodel', 'gzsndsys']

for tu in tus:
    print(f'\n=== {tu} (all sizes) ===')
    counts = {'small': 0, 'medium': 0, 'large': 0}
    examples = []
    
    with open('build/reports/missing_functions_report.txt', 'r') as f:
        for line in f:
            if tu.replace('_', '') in line.lower() or tu in line.lower():
                parts = line.split()
                if len(parts) >= 3:
                    try:
                        addr = int(parts[0], 16)
                        size = int(parts[1].replace('B', ''))
                        data = get_bytes(addr, size)
                        if data:
                            has_stwu = any(struct.unpack('>I', data[i:i+4])[0] >> 26 == 0x11 for i in range(0, len(data), 4))
                            has_bl = any(struct.unpack('>I', data[i:i+4])[0] >> 26 == 0x12 for i in range(0, len(data), 4))
                            
                            if size <= 40:
                                counts['small'] += 1
                            elif size <= 100:
                                counts['medium'] += 1
                                if has_stwu and has_bl and len(examples) < 3:
                                    examples.append((addr, size, parts[2]))
                            else:
                                counts['large'] += 1
                    except:
                        pass
    
    print(f'  Small: {counts["small"]}, Medium: {counts["medium"]}, Large: {counts["large"]}')
    for ex in examples:
        print(f'  0x{ex[0]:08X} {ex[1]}B {ex[2]} (stwu+bl)')
