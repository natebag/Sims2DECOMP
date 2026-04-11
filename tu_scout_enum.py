#!/usr/bin/env python3
"""TUScout: Enumerate and rank all TUs for the decomp project."""

import subprocess
import re
import json

# Get all TUs
result = subprocess.run(['python', 'tools/tu_match.py', '--list'], capture_output=True, text=True)
tus = [line.strip() for line in result.stdout.split('\n') if line.strip() and not line.startswith('541')]

print(f'Total TUs to process: {len(tus)}')

tu_stats = []

# Process all TUs
for i, tu in enumerate(tus):
    if i % 50 == 0:
        print(f'Processing {i}/{len(tus)}: {tu}...')
    
    try:
        result = subprocess.run(['python', 'tools/tu_match.py', '--combine', tu], 
                               capture_output=True, text=True, timeout=60)
        output = result.stdout
        
        # Parse the output
        lines = output.split('\n')
        total = 0
        matched = 0
        mismatch = 0
        no_source = 0
        
        for line in lines:
            if 'functions' in line and 'TU:' in line:
                # Extract total count
                m = re.search(r'(\d+) functions', line)
                if m:
                    total = int(m.group(1))
            elif 'MATCH' in line and 'MISMATCH' not in line:
                matched += 1
            elif 'MISMATCH' in line:
                mismatch += 1
            elif '[no source]' in line:
                no_source += 1
        
        if total > 0:
            pct = (matched / total) * 100
            remaining = total - matched
            tu_stats.append({
                'name': tu,
                'total': total,
                'matched': matched,
                'mismatch': mismatch,
                'no_source': no_source,
                'remaining': remaining,
                'pct': round(pct, 1)
            })
    except Exception as e:
        print(f'Error processing {tu}: {e}')

# Sort by percentage descending
tu_stats.sort(key=lambda x: (-x['pct'], -x['total']))

# Save to file
with open('tu_ranking_full.json', 'w') as f:
    json.dump(tu_stats, f, indent=2)

print(f'\nProcessed {len(tu_stats)} TUs with data')
print('\nTop 20 TUs by completion pct:')
for i, tu in enumerate(tu_stats[:20]):
    print(f"{i+1:2d}. {tu['name']:<25} {tu['matched']:>3}/{tu['total']:<3} ({tu['pct']:>5.1f}pct) - {tu['remaining']} rem")
