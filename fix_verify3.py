with open('tools/verify_match.sh', 'r') as f:
    lines = f.readlines()

# Find the line with COMPILED_BYTES and insert PYTHON before it
for i, line in enumerate(lines):
    if 'COMPILED_BYTES=$($OBJDUMP -s -j .text' in line:
        # Insert PYTHON definition before the Step 2 comment
        j = i - 2
        while j >= 0 and 'Step 2' not in lines[j]:
            j -= 1
        if j >= 0:
            lines.insert(j, 'PYTHON="/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"\n')
            break

# Remove duplicate PYTHON definition later in the file
for i in range(len(lines)-1, -1, -1):
    if 'PYTHON="/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"' in lines[i]:
        # Check if there's another one before it
        for j in range(i-1, -1, -1):
            if 'PYTHON="/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"' in lines[j]:
                # Remove the later one
                del lines[i]
                break
        break

with open('tools/verify_match.sh', 'w') as f:
    f.writelines(lines)

print('Fixed')
