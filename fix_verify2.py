with open('tools/verify_match.sh', 'r') as f:
    content = f.read()

old = '| python3 -c "'
new = '| "$PYTHON" -c "'

if old in content:
    content = content.replace(old, new)
    with open('tools/verify_match.sh', 'w') as f:
        f.write(content)
    print('Updated to use $PYTHON')
else:
    print('Pattern not found')
