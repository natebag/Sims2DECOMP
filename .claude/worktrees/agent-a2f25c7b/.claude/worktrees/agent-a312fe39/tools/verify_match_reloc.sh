#!/bin/bash
# verify_match_reloc.sh — Verify with relocation-aware comparison
# Usage: ./tools/verify_match_reloc.sh <source.cpp> <address_hex> <size_decimal>

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
MAP="extracted/files/u2_ngc_release_dvd.map"

SN_BIN="compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin"
SN_CC1PLUS="$SN_BIN/cc1plus.exe"
SN_AS="$SN_BIN/NgcAs.exe"

mkdir -p build/verify
BASENAME="$(basename "$SRC" .cpp)"
OBJ="build/verify/${BASENAME}.o"
ASM="build/verify/${BASENAME}.s"

# Step 1: Compile
if [ -f "$SN_CC1PLUS" ]; then
    CLEAN_SRC="build/verify/${BASENAME}_clean.cpp"
    sed 's|//.*||; s|/\*.*\*/||' "$SRC" > "$CLEAN_SRC"
    echo "Compiling with SN Systems ProDG..."
    "$SN_CC1PLUS" "$CLEAN_SRC" -o "$ASM" -quiet -O2 2>&1
    "$SN_AS" "$ASM" -o "$OBJ" 2>&1 || \
        "$DEVKITPPC/bin/powerpc-eabi-as" -mgekko -mregnames "$ASM" -o "$OBJ" 2>&1
else
    CXX="$DEVKITPPC/bin/powerpc-eabi-g++"
    CXXFLAGS="-mcpu=750 -meabi -mhard-float -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-exceptions -fno-rtti -fno-builtin -fshort-wchar -fpermissive -Wno-unused -Wno-return-type"
    echo "Compiling with devkitPPC GCC..."
    $CXX $CXXFLAGS -c "$SRC" -o "$OBJ" 2>&1
fi

# Step 2: Extract .text hex and relocations, then apply them
COMPILED_BYTES=$($OBJDUMP -s -j .text "$OBJ" 2>/dev/null | awk '/Contents of section .text/{found=1;next} found{print}' | awk '{for(i=2;i<=5;i++) printf "%s", $i; printf "\n"}' | tr -d ' \n')

RELOCS=$($OBJDUMP -r "$OBJ" 2>/dev/null | grep -E '^[0-9a-f]' || true)

# Step 3: Use Python to apply relocations and compare
PYTHON="/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"

RESULT=$($PYTHON << 'PYEOF'
import struct, sys, os

compiled_hex = os.environ.get('COMPILED_HEX', '')
reloc_text = os.environ.get('RELOC_TEXT', '')
func_addr = int(os.environ.get('FUNC_ADDR', '0'), 0)
func_size = int(os.environ.get('FUNC_SIZE', '0'))
dol_path = os.environ.get('DOL_PATH', '')
map_path = os.environ.get('MAP_PATH', '')

obj_bytes = bytearray.fromhex(compiled_hex)[:func_size]

# Parse relocations
relocs = []
for line in reloc_text.strip().split('\n'):
    line = line.strip()
    if not line:
        continue
    parts = line.split()
    if len(parts) >= 3:
        try:
            offset = int(parts[0], 16)
            rtype = parts[1]
            value_str = parts[2]
            if '+' in value_str:
                sym, addend_str = value_str.rsplit('+', 1)
                addend = int(addend_str, 16)
            else:
                sym = value_str
                addend = 0
            relocs.append((offset, rtype, sym, addend))
        except:
            pass

# Build symbol map
sym_map = {}
with open(map_path, 'r', errors='replace') as f:
    for line in f:
        parts = line.strip().split()
        if len(parts) >= 4:
            try:
                a = int(parts[0], 16)
                name = ' '.join(parts[3:])
                sym_map[name] = a
            except:
                pass

# Apply relocations
for offset, rtype, sym, addend in relocs:
    if offset >= func_size:
        continue
    if sym == '.text':
        target_addr = func_addr + addend
    elif sym in sym_map:
        target_addr = sym_map[sym]
    else:
        print(f'WARNING: Unknown symbol: {sym}')
        continue

    instr_addr = func_addr + offset
    if rtype == 'R_PPC_REL14':
        displacement = target_addr - instr_addr
        old = struct.unpack('>I', obj_bytes[offset:offset+4])[0]
        old_masked = old & 0xFFFF0003
        new_val = old_masked | (displacement & 0x0000FFFC)
        struct.pack_into('>I', obj_bytes, offset, new_val)
    elif rtype == 'R_PPC_REL24':
        displacement = target_addr - instr_addr
        old = struct.unpack('>I', obj_bytes[offset:offset+4])[0]
        old_masked = old & 0xFC000003
        new_val = old_masked | (displacement & 0x03FFFFFC)
        struct.pack_into('>I', obj_bytes, offset, new_val)

compiled_final = obj_bytes[:func_size].hex()

# DOL bytes
with open(dol_path, 'rb') as f:
    dol = f.read()
dol_hex = ''
for i in range(7):
    off = struct.unpack('>I', dol[i*4:i*4+4])[0]
    addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
    sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
    if addr <= func_addr < addr + sz:
        foff = off + (func_addr - addr)
        dol_raw = dol[foff:foff+func_size]
        dol_hex = ''.join(f'{b:02x}' for b in dol_raw)
        break

print(f'DOL:      {dol_hex}')
print(f'Compiled: {compiled_final}')
if dol_hex == compiled_final:
    print('MATCH!')
else:
    diffs = []
    for i in range(0, min(len(dol_hex), len(compiled_final)), 8):
        d = dol_hex[i:i+8]
        c = compiled_final[i:i+8]
        if d != c:
            diffs.append(f'  offset 0x{i//2:02X}: DOL={d} compiled={c}')
    print('MISMATCH')
    for d in diffs:
        print(d)
PYEOF
)

echo "$RESULT"
echo "$RESULT" | grep -q "MATCH!" && exit 0 || exit 1
