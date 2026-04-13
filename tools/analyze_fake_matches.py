#!/usr/bin/env python3
"""Analyze fake_matches pool for rework inventory"""
import os
import re

fake_matches_dir = 'src/wip/fake_matches'
files = [f for f in os.listdir(fake_matches_dir) if f.endswith('.cpp')]

candidates = []

for filename in files:
    filepath = os.path.join(fake_matches_dir, filename)
    with open(filepath, 'r') as f:
        content = f.read()
    
    # Extract address
    addr_match = re.search(r'0x([0-9A-Fa-f]{8})', content)
    addr = addr_match.group(0) if addr_match else 'unknown'
    
    # Extract size
    size_match = re.search(r'\((\d+) bytes?\)', content)
    size = int(size_match.group(1)) if size_match else 0
    
    # Extract function name from filename
    func_name = filename.replace('_ctor_auto.cpp', '').replace('_ctor_rework.cpp', '').replace('_skeleton.cpp', '')
    
    # Categorize
    if size <= 28:
        cat = 'vtable_only'
        difficulty = 'EASIEST'
    elif size <= 40:
        cat = 'vtable_zero'
        difficulty = 'EASY'
    elif size <= 60:
        cat = 'vtable_fields'
        difficulty = 'MEDIUM'
    else:
        cat = 'complex'
        difficulty = 'HARD'
    
    candidates.append({
        'file': filename,
        'func': func_name,
        'addr': addr,
        'size': size,
        'cat': cat,
        'difficulty': difficulty
    })

# Sort by size (smallest first)
candidates.sort(key=lambda x: x['size'])

print('=== TOP 15 EASIEST CANDIDATES ===')
print()
for i, c in enumerate(candidates[:15]):
    print(f"{i+1}. {c['file']}")
    print(f"   Function: {c['func']}")
    print(f"   Address: {c['addr']}")
    print(f"   Size: {c['size']}B")
    print(f"   Category: {c['cat']} ({c['difficulty']})")
    print()

# Category summary
print('=== CATEGORY SUMMARY ===')
counts = {'vtable_only': 0, 'vtable_zero': 0, 'vtable_fields': 0, 'complex': 0}
for c in candidates:
    counts[c['cat']] += 1

print(f"vtable_only (<=28B):  {counts['vtable_only']:3d} files")
print(f"vtable_zero (<=40B):  {counts['vtable_zero']:3d} files")
print(f"vtable_fields (<=60B): {counts['vtable_fields']:3d} files")
print(f"complex (>60B):       {counts['complex']:3d} files")
print(f"Total: {len(candidates)} files")
