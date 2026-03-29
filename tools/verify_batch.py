#!/usr/bin/env python3
import subprocess
import os

dir = 'src/matched/global_getters'
files = [f for f in os.listdir(dir) if f.endswith('.cpp') and 'void' in f]

print(f'Checking {len(files)} files...')

matched = 0
for f in files:
    # Extract address from filename
    addr = '0x' + f.split('_')[1]
    filepath = os.path.join(dir, f)
    
    result = subprocess.run(
        ['bash', 'tools/verify_match.sh', filepath, addr, '12'],
        capture_output=True, text=True, timeout=30
    )
    
    if 'MATCH!' in result.stdout:
        matched += 1

print(f'\nTotal: {matched}/{len(files)} matched')
