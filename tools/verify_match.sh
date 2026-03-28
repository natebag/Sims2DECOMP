#!/bin/bash
# verify_match.sh — Verify a decompiled function matches the original DOL
#
# Uses the ORIGINAL SN Systems ProDG compiler (cc1plus.exe + NgcAs.exe)
# that built The Sims 2 GameCube. Falls back to devkitPPC GCC if SN not found.
#
# Usage: ./tools/verify_match.sh <source.cpp> <address_hex> <size_decimal>
# Example: ./tools/verify_match.sh src/matched/test.cpp 0x800044C0 8
#
# Returns exit code 0 if function bytes match, 1 if mismatch.

set -e

SRC="$1"
ADDR="$2"
SIZE="$3"

if [ -z "$SRC" ] || [ -z "$ADDR" ] || [ -z "$SIZE" ]; then
    echo "Usage: $0 <source.cpp> <hex_address> <size>"
    echo "Example: $0 src/matched/test.cpp 0x800044C0 8"
    exit 1
fi

# Setup toolchain
export PATH="/f/coding/Decompiles/Tools/devkitPro/msys2/usr/bin:$PATH"
DEVKITPPC="/f/coding/Decompiles/Tools/devkitPro/devkitPPC"
OBJDUMP="$DEVKITPPC/bin/powerpc-eabi-objdump"
DOL="extracted/sys/main.dol"

# SN Systems ProDG compiler (the ORIGINAL compiler)
SN_BIN="compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin"
SN_CC1PLUS="$SN_BIN/cc1plus.exe"
SN_AS="$SN_BIN/NgcAs.exe"

# Output paths
mkdir -p build/verify
BASENAME="$(basename "$SRC" .cpp)"
OBJ="build/verify/${BASENAME}.o"
ASM="build/verify/${BASENAME}.s"

# Step 1: Compile
if [ -f "$SN_CC1PLUS" ]; then
    # Use SN Systems compiler (the real one)
    # GCC 2.95 can be picky — strip // comments starting with 0x (confuses old preprocessor)
    CLEAN_SRC="build/verify/${BASENAME}_clean.cpp"
    sed 's|^//.*||' "$SRC" > "$CLEAN_SRC"
    echo "Compiling $SRC with SN Systems ProDG..."
    "$SN_CC1PLUS" "$CLEAN_SRC" -o "$ASM" -quiet -O2 2>&1
    if [ $? -ne 0 ]; then
        echo "COMPILE FAILED"
        exit 1
    fi
    # Assemble with SN assembler
    "$SN_AS" "$ASM" -o "$OBJ" 2>&1
    if [ $? -ne 0 ]; then
        # Fall back to devkitPPC assembler
        "$DEVKITPPC/bin/powerpc-eabi-as" -mgekko -mregnames "$ASM" -o "$OBJ" 2>&1
        if [ $? -ne 0 ]; then
            echo "ASSEMBLE FAILED"
            exit 1
        fi
    fi
else
    # Fallback: devkitPPC GCC
    echo "Compiling $SRC with devkitPPC GCC (SN compiler not found)..."
    CXX="$DEVKITPPC/bin/powerpc-eabi-g++"
    CXXFLAGS="-mcpu=750 -meabi -mhard-float -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-exceptions -fno-rtti -fno-builtin -fshort-wchar -fpermissive -Wno-unused -Wno-return-type"
    $CXX $CXXFLAGS -c "$SRC" -o "$OBJ" 2>&1
    if [ $? -ne 0 ]; then
        echo "COMPILE FAILED"
        exit 1
    fi
fi

# Step 2: Extract compiled bytes from .text section
echo "Extracting compiled bytes..."
COMPILED_BYTES=$($OBJDUMP -s -j .text "$OBJ" 2>/dev/null | awk '/Contents of section .text/{found=1;next} found{print}' | awk '{for(i=2;i<=5;i++) printf "%s", $i; printf "\n"}' | tr -d ' \n')

# Step 3: Extract DOL bytes at the given address
echo "Extracting DOL bytes at $ADDR ($SIZE bytes)..."
PYTHON="/c/Users/SCICO/AppData/Local/Python/bin/python.exe"
DOL_BYTES=$($PYTHON -c "
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
        raw = dol[foff:foff+$SIZE]
        print(''.join(f'{b:02x}' for b in raw))
        break
")

# Step 4: Compare (first SIZE*2 hex chars)
COMPILED_TRIMMED="${COMPILED_BYTES:0:$(($SIZE * 2))}"

echo ""
echo "DOL bytes:      $DOL_BYTES"
echo "Compiled bytes: $COMPILED_TRIMMED"
echo ""

if [ "$DOL_BYTES" = "$COMPILED_TRIMMED" ]; then
    echo "MATCH! Function at $ADDR ($SIZE bytes) matches perfectly."
    exit 0
else
    echo "MISMATCH at $ADDR ($SIZE bytes)"
    echo ""
    echo "Compiled disassembly:"
    $OBJDUMP -d "$OBJ"
    exit 1
fi
