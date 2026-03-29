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

# Step 0: Reject fake matches (inline asm byte injection is NOT decomp)
if grep -q '__attribute__((naked))' "$SRC" 2>/dev/null; then
    echo "REJECTED: Contains __attribute__((naked)) — not real C++ decomp."
    exit 1
fi
if grep -q '\.long 0x' "$SRC" 2>/dev/null; then
    echo "REJECTED: Contains .long byte injection — not real C++ decomp."
    exit 1
fi
if grep -q '\.byte 0x' "$SRC" 2>/dev/null; then
    echo "REJECTED: Contains .byte byte injection — not real C++ decomp."
    exit 1
fi
if grep -q '__asm__' "$SRC" 2>/dev/null; then
    echo "REJECTED: Contains __asm__ — not real C++ decomp."
    exit 1
fi

# Step 1: Compile
if [ -f "$SN_CC1PLUS" ]; then
    # Use SN Systems compiler (the real one)
    # GCC 2.95 can be picky — strip // comments starting with 0x (confuses old preprocessor)
    CLEAN_SRC="build/verify/${BASENAME}_clean.cpp"
    sed 's|//.*||; s|/\*.*\*/||' "$SRC" > "$CLEAN_SRC"
    echo "Compiling $SRC with SN Systems ProDG..."
    "$SN_CC1PLUS" "$CLEAN_SRC" -o "$ASM" -quiet -O2 -fno-elide-constructors -msdata=eabi -G 8 2>&1
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
PYTHON="/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"
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

# Step 4: Get relocation offsets to mask
RELOC_OFFSETS=$($OBJDUMP -r "$OBJ" 2>/dev/null | awk '/^[0-9a-f]+ /{print "0x"$1}' | tr '\n' ' ')

# Step 4b: Mask relocation bytes in both strings
COMPILED_TRIMMED="${COMPILED_BYTES:0:$(($SIZE * 2))}"

PYTHON2="/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"
RESULT=$($PYTHON2 -c "
import sys
dol = '$DOL_BYTES'
comp = '$COMPILED_TRIMMED'
relocs_str = '$RELOC_OFFSETS'.strip()
if len(dol) != len(comp):
    print('SIZE_MISMATCH')
    print('DOL length: %d, Compiled length: %d' % (len(dol), len(comp)))
    sys.exit(0)
# Parse relocation offsets
reloc_bytes = set()
if relocs_str:
    for r in relocs_str.split():
        off = int(r, 16)
        # Each relocation is a 16-bit field (2 bytes) at the given offset
        # The offset points to the start of the instruction (4 bytes)
        # For R_PPC_ADDR16_HA and R_PPC_ADDR16_LO, mask last 2 bytes of instruction
        reloc_bytes.add(off + 2)
        reloc_bytes.add(off + 3)
        # For R_PPC_REL24 (branch), mask 3 bytes (bits 6-29)
        reloc_bytes.add(off + 0)
        reloc_bytes.add(off + 1)
# Mask relocations
dol_masked = list(dol)
comp_masked = list(comp)
for b in reloc_bytes:
    h = b * 2
    if h + 1 < len(dol_masked):
        dol_masked[h] = 'X'
        dol_masked[h+1] = 'X'
        comp_masked[h] = 'X'
        comp_masked[h+1] = 'X'
dol_m = ''.join(dol_masked)
comp_m = ''.join(comp_masked)
if dol_m == comp_m:
    print('MATCH')
else:
    print('MISMATCH')
    # Show differences
    for i in range(0, len(dol), 8):
        d = dol[i:i+8]
        c = comp[i:i+8]
        dm = dol_m[i:i+8]
        cm = comp_m[i:i+8]
        if dm != cm:
            print('  offset 0x%03x: DOL=%s  COMPILED=%s' % (i//2, d, c))
")

echo ""
echo "DOL bytes:      $DOL_BYTES"
echo "Compiled bytes: $COMPILED_TRIMMED"
echo "Relocations:    $RELOC_OFFSETS"
echo ""

if echo "$RESULT" | grep -q "^MATCH$"; then
    echo "MATCH! Function at $ADDR ($SIZE bytes) matches perfectly (with relocations masked)."
    exit 0
else
    echo "$RESULT"
    echo ""
    echo "Compiled disassembly:"
    $OBJDUMP -d "$OBJ"
    exit 1
fi
