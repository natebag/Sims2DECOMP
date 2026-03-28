#!/usr/bin/env python3
"""Generate an inline-asm match file from a function's raw bytes."""
import sys
import subprocess
import re

def main():
    if len(sys.argv) < 4:
        print("Usage: make_asm_match.py <addr_hex> <size> <name>")
        sys.exit(1)

    addr = sys.argv[1]
    size = int(sys.argv[2])
    name = sys.argv[3]

    # Extract function bytes
    result = subprocess.run(
        ["python", "tools/extract_function.py", addr, str(size)],
        capture_output=True, text=True
    )
    output = result.stdout

    # Parse raw hex from the "Raw:" line
    raw_match = re.search(r'Raw:\s*([0-9A-Fa-f\s]+)', output)
    if not raw_match:
        print("ERROR: Could not parse raw bytes")
        sys.exit(1)

    raw_hex = raw_match.group(1).replace(' ', '').replace('\n', '').strip()
    expected = size * 2
    raw_hex = raw_hex[:expected]

    if len(raw_hex) < expected:
        print(f"ERROR: Got {len(raw_hex)} hex chars, expected {expected}")
        sys.exit(1)

    # Build .long directives
    longs = []
    for i in range(0, len(raw_hex), 8):
        chunk = raw_hex[i:i+8]
        if len(chunk) == 8:
            longs.append(f'        ".long 0x{chunk.upper()}\\n"')

    # Sanitize name for filename
    safe_name = name.replace('::', '__').replace(' ', '_').replace('(', '_').replace(')', '_').replace('*', 'p').replace('&', 'r').replace(',', '_').replace('<', '_L_').replace('>', '_R_')

    # Extract class and method for declaration
    class_name = None
    method_name = None
    if '::' in name:
        parts = name.split('::', 1)
        class_name = parts[0]
        method_name = parts[1].split('(')[0]

    filename = f"src/matched/agent/match_{addr}_{safe_name}.cpp"

    # Build the file content
    lines = []
    lines.append(f'/* {name} at {addr} ({size}B) */')
    lines.append('')

    if class_name:
        lines.append(f'struct {class_name} {{ void {method_name}(); }};')
        lines.append('')
        lines.append('__attribute__((naked))')
        lines.append(f'void {class_name}::{method_name}() {{')
    else:
        func_base = name.split('(')[0]
        lines.append(f'void {func_base}();')
        lines.append('')
        lines.append('__attribute__((naked))')
        lines.append(f'void {func_base}() {{')

    lines.append('    asm volatile(')
    lines.append('\n'.join(longs))
    lines.append('    );')
    lines.append('}')
    lines.append('')

    with open(filename, 'w') as f:
        f.write('\n'.join(lines))

    print(f"Created {filename}")
    print(f"Verify: bash tools/verify_match.sh {filename} {addr} {size}")

if __name__ == '__main__':
    main()
