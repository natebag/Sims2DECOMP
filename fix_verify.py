import re

with open('tools/verify_match.sh', 'r') as f:
    content = f.read()

old = """# Step 2: Extract compiled bytes from .text section
echo "Extracting compiled bytes..."
COMPILED_BYTES=$($OBJDUMP -s -j .text "$OBJ" 2>/dev/null | awk '/Contents of section .text/{found=1;next} found{print}' | awk '{for(i=2;i<=5;i++) printf "%s", $i; printf "\\n"}' | tr -d ' \\n')"""

new = """# Step 2: Extract compiled bytes from .text section
echo "Extracting compiled bytes..."
COMPILED_BYTES=$($OBJDUMP -s -j .text "$OBJ" 2>/dev/null | python3 -c "
import sys, re
for line in sys.stdin:
    line = line.strip()
    if not line or line.startswith('Contents'): continue
    parts = line.split()
    hex_words = []
    for p in parts[1:]:
        if re.fullmatch(r'[0-9a-f]{8}', p):
            hex_words.append(p)
        else:
            break
    print(''.join(hex_words), end='')
")"""

if old in content:
    content = content.replace(old, new)
    with open('tools/verify_match.sh', 'w') as f:
        f.write(content)
    print('Fixed verify_match.sh')
else:
    print('Pattern not found, trying alternative...')
    # Try with different newline handling
    import sys
    sys.exit(1)
