#!/bin/bash
# verify_match_reloc.sh - Verify match with relocation masking
# Like verify_match.sh but masks bl/b instruction targets before comparing
set -e

SRC="$1"
ADDR="$2"
SIZE="$3"

if [ -z "$SRC" ] || [ -z "$ADDR" ] || [ -z "$SIZE" ]; then
    echo "Usage: $0 <source.cpp> <hex_address> <size>"
    exit 1
fi

export PATH="/f/coding/Decompiles/Tools/devkitPro/msys2/usr/bin:$PATH"
DEVKITPPC="/f/coding/Decompiles/Tools/devkitPro/devkitPPC"
OBJDUMP="$DEVKITPPC/bin/powerpc-eabi-objdump"
DOL="extracted/sys/main.dol"
SN_BIN="compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin"
SN_CC1PLUS="$SN_BIN/cc1plus.exe"
SN_AS="$SN_BIN/NgcAs.exe"

mkdir -p build/verify
BASENAME="$(basename "$SRC" .cpp)"
OBJ="build/verify/${BASENAME}.o"
ASM="build/verify/${BASENAME}.s"

# Compile
if [ -f "$SN_CC1PLUS" ]; then
    CLEAN_SRC="build/verify/${BASENAME}_clean.cpp"
    sed 's|//.*||; s|/\*.*\*/||' "$SRC" > "$CLEAN_SRC"
    "$SN_CC1PLUS" "$CLEAN_SRC" -o "$ASM" -quiet -O2 2>&1
    if [ $? -ne 0 ]; then echo "COMPILE FAILED"; exit 1; fi
    "$SN_AS" "$ASM" -o "$OBJ" 2>&1 || "$DEVKITPPC/bin/powerpc-eabi-as" -mgekko -mregnames "$ASM" -o "$OBJ" 2>&1
    if [ $? -ne 0 ]; then echo "ASSEMBLE FAILED"; exit 1; fi
else
    echo "SN compiler not found"; exit 1
fi

# Extract compiled bytes
COMPILED_BYTES=$($OBJDUMP -s -j .text "$OBJ" 2>/dev/null | awk '/Contents of section .text/{found=1;next} found{print}' | awk '{for(i=2;i<=5;i++) printf "%s", $i; printf "\n"}' | tr -d ' \n')

# Compare with relocation masking
PYTHON="/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"
$PYTHON -c "
import struct
with open('$DOL', 'rb') as f:
    dol = f.read()
vaddr = $ADDR
for i in range(7):
    off = struct.unpack('>I', dol[i*4:i*4+4])[0]
    addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
    sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
    if addr <= vaddr < addr + sz:
        foff = off + (vaddr - addr)
        dol_raw = dol[foff:foff+$SIZE]
        break

comp_hex = '$COMPILED_BYTES'[:$SIZE*2]
comp_raw = bytes.fromhex(comp_hex)

def mask(raw):
    m = bytearray(raw)
    for i in range(0, len(m)-3, 4):
        w = struct.unpack('>I', m[i:i+4])[0]
        op = (w >> 26) & 0x3F
        if op == 18:
            lk = w & 1
            masked_w = (op << 26) | lk
            struct.pack_into('>I', m, i, masked_w)
    return bytes(m)

dol_m = mask(dol_raw)
comp_m = mask(comp_raw)

if dol_m == comp_m:
    print('MATCH (reloc-masked)! Function at $ADDR ($SIZE bytes) matches.')
    exit(0)
else:
    print('MISMATCH at $ADDR ($SIZE bytes)')
    print(f'DOL:  {dol_raw.hex()}')
    print(f'Comp: {comp_raw.hex()}')
    for i in range(min(len(dol_m), len(comp_m))):
        if dol_m[i] != comp_m[i]:
            print(f'  Diff at byte {i} (0x{i:X}): DOL={dol_m[i]:02X} Comp={comp_m[i]:02X}')
    exit(1)
"
