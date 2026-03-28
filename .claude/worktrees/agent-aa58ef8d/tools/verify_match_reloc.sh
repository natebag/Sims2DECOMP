#!/bin/bash
# verify_match_reloc.sh — Verify matching with relocation-aware comparison
# Masks bl/b instruction targets since .o files have unresolved relocations
#
# Usage: ./tools/verify_match_reloc.sh <source.cpp> <address_hex> <size_decimal>

set -e

SRC="$1"
ADDR="$2"
SIZE="$3"

if [ -z "$SRC" ] || [ -z "$ADDR" ] || [ -z "$SIZE" ]; then
    echo "Usage: $0 <source.cpp> <hex_address> <size>"
    exit 1
fi

# Setup toolchain
export PATH="/f/coding/Decompiles/Tools/devkitPro/msys2/usr/bin:$PATH"
DEVKITPPC="/f/coding/Decompiles/Tools/devkitPro/devkitPPC"
OBJDUMP="$DEVKITPPC/bin/powerpc-eabi-objdump"
DOL="extracted/sys/main.dol"

# SN Systems compiler
SN_BIN="compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin"
SN_CC1PLUS="$SN_BIN/cc1plus.exe"

# Output paths
mkdir -p build/verify
BASENAME="$(basename "$SRC" .cpp)"
OBJ="build/verify/${BASENAME}.o"
ASM="build/verify/${BASENAME}.s"

# Step 1: Compile with SN
if [ -f "$SN_CC1PLUS" ]; then
    CLEAN_SRC="build/verify/${BASENAME}_clean.cpp"
    sed 's|//.*||; s|/\*.*\*/||' "$SRC" > "$CLEAN_SRC"
    "$SN_CC1PLUS" "$CLEAN_SRC" -o "$ASM" -quiet -O2 2>&1
    if [ $? -ne 0 ]; then
        echo "COMPILE FAILED"
        exit 1
    fi
    "$SN_BIN/NgcAs.exe" "$ASM" -o "$OBJ" 2>&1 || \
    "$DEVKITPPC/bin/powerpc-eabi-as" -mgekko -mregnames "$ASM" -o "$OBJ" 2>&1
    if [ $? -ne 0 ]; then
        echo "ASSEMBLE FAILED"
        exit 1
    fi
else
    echo "SN compiler not found!"
    exit 1
fi

# Step 2: Extract compiled bytes
COMPILED_BYTES=$($OBJDUMP -s -j .text "$OBJ" 2>/dev/null | awk '/Contents of section .text/{found=1;next} found{print}' | awk '{for(i=2;i<=5;i++) printf "%s", $i; printf "\n"}' | tr -d ' \n')

# Step 3: Extract DOL bytes + relocation-aware compare
PYTHON="/c/Users/SCICO/AppData/Local/Python/bin/python.exe"
$PYTHON -c "
import struct

with open('$DOL', 'rb') as f:
    dol = f.read()

vaddr = $ADDR
size = $SIZE
foff = None
for i in range(7):
    off = struct.unpack('>I', dol[i*4:i*4+4])[0]
    addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
    sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
    if addr <= vaddr < addr + sz:
        foff = off + (vaddr - addr)
        break

if foff is None:
    print('ERROR: Cannot find address in DOL')
    exit(1)

dol_raw = dol[foff:foff+size]
comp_hex = '$COMPILED_BYTES'
comp_raw = bytes.fromhex(comp_hex[:size*2])

if len(comp_raw) < size:
    print(f'ERROR: Compiled output too small ({len(comp_raw)} < {size})')
    exit(1)

dol_hex = dol_raw.hex()
comp_hex_trimmed = comp_raw.hex()

print(f'DOL bytes:      {dol_hex}')
print(f'Compiled bytes: {comp_hex_trimmed}')
print()

mismatches = 0
lis_pending = {}  # reg -> True, for registers loaded by lis awaiting lo-half
for i in range(0, size, 4):
    d = struct.unpack('>I', dol_raw[i:i+4])[0]
    c = struct.unpack('>I', comp_raw[i:i+4])[0]
    opcode = (d >> 26) & 0x3F
    # Mask unconditional branch instructions (opcode 18 = b/bl) - relocation targets
    if opcode == 18:
        d_masked = d & 0xFC000003
        c_masked = c & 0xFC000003
        if d_masked != c_masked:
            print(f'  MISMATCH at +0x{i:02x}: branch type {d:08x} vs {c:08x}')
            mismatches += 1
        continue
    # Mask lis (addis rd, 0, imm) - high address load relocation
    if opcode == 15 and ((d >> 16) & 0x1F) == 0:
        rd = (d >> 21) & 0x1F
        d_masked = d & 0xFFE00000
        c_masked = c & 0xFFE00000
        if d_masked != c_masked:
            print(f'  MISMATCH at +0x{i:02x}: lis reg differs {d:08x} vs {c:08x}')
            mismatches += 1
        lis_pending[rd] = True
        continue
    # Mask addi/ori that completes a lis+addi pair
    if opcode in (14, 24):  # addi or ori
        ra = (d >> 16) & 0x1F
        if ra in lis_pending:
            d_masked = d & 0xFFE00000
            c_masked = c & 0xFFE00000
            if d_masked != c_masked:
                print(f'  MISMATCH at +0x{i:02x}: lo-addr reg differs {d:08x} vs {c:08x}')
                mismatches += 1
            del lis_pending[ra]
            continue
    # Mask lwz/lhz/lfs etc with pending lis base register
    if opcode in (32, 34, 40, 36, 44, 38, 48, 52):
        ra = (d >> 16) & 0x1F
        if ra in lis_pending:
            d_masked = d & 0xFFFF0000
            c_masked = c & 0xFFFF0000
            if d_masked != c_masked:
                print(f'  MISMATCH at +0x{i:02x}: load offset reg differs {d:08x} vs {c:08x}')
                mismatches += 1
            del lis_pending[ra]
            continue
    # Do NOT mask conditional branches - they must match exactly
    if d != c:
        print(f'  MISMATCH at +0x{i:02x}: {d:08x} vs {c:08x}')
        mismatches += 1

if mismatches == 0:
    print('MATCH! (relocation-aware)')
    exit(0)
else:
    print(f'MISMATCH ({mismatches} instruction(s) differ)')
    import subprocess
    subprocess.run(['$OBJDUMP', '-d', '$OBJ'])
    exit(1)
"
