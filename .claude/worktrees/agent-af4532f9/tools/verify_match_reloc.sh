#!/bin/bash
# verify_match_reloc.sh — Verify with relocation masking
# Like verify_match.sh but masks out branch (bl/b) targets that need linker resolution
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

SN_BIN="compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin"
SN_CC1PLUS="$SN_BIN/cc1plus.exe"
SN_AS="$SN_BIN/NgcAs.exe"

mkdir -p build/verify
BASENAME="$(basename "$SRC" .cpp)"
OBJ="build/verify/${BASENAME}.o"
ASM="build/verify/${BASENAME}.s"

if [ -f "$SN_CC1PLUS" ]; then
    CLEAN_SRC="build/verify/${BASENAME}_clean.cpp"
    sed 's|//.*||; s|/\*.*\*/||' "$SRC" > "$CLEAN_SRC"
    echo "Compiling $SRC with SN Systems ProDG..."
    "$SN_CC1PLUS" "$CLEAN_SRC" -o "$ASM" -quiet -O2 2>&1
    if [ $? -ne 0 ]; then
        echo "COMPILE FAILED"
        exit 1
    fi
    "$SN_AS" "$ASM" -o "$OBJ" 2>&1
    if [ $? -ne 0 ]; then
        "$DEVKITPPC/bin/powerpc-eabi-as" -mgekko -mregnames "$ASM" -o "$OBJ" 2>&1
        if [ $? -ne 0 ]; then
            echo "ASSEMBLE FAILED"
            exit 1
        fi
    fi
else
    echo "Compiling $SRC with devkitPPC GCC..."
    CXX="$DEVKITPPC/bin/powerpc-eabi-g++"
    CXXFLAGS="-mcpu=750 -meabi -mhard-float -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-exceptions -fno-rtti -fno-builtin -fshort-wchar -fpermissive -Wno-unused -Wno-return-type"
    $CXX $CXXFLAGS -c "$SRC" -o "$OBJ" 2>&1
    if [ $? -ne 0 ]; then
        echo "COMPILE FAILED"
        exit 1
    fi
fi

echo "Extracting compiled bytes..."
COMPILED_BYTES=$($OBJDUMP -s -j .text "$OBJ" 2>/dev/null | awk '/Contents of section .text/{found=1;next} found{print}' | awk '{for(i=2;i<=5;i++) printf "%s", $i; printf "\n"}' | tr -d ' \n')

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

COMPILED_TRIMMED="${COMPILED_BYTES:0:$(($SIZE * 2))}"

# Get relocation offsets from the object file
RELOC_OFFSETS=$($OBJDUMP -r "$OBJ" 2>/dev/null | grep "R_PPC_REL24\|R_PPC_REL14\|R_PPC_ADDR16\|R_PPC_ADDR32\|R_PPC_ADDR16_HA\|R_PPC_ADDR16_LO" | awk '{print $1}' | tr -d ':')

# Mask out relocation sites in both DOL and compiled bytes
MASKED_DOL="$DOL_BYTES"
MASKED_COMP="$COMPILED_TRIMMED"

for OFF in $RELOC_OFFSETS; do
    # Convert hex offset to char position in hex string (each byte = 2 chars)
    OFF_DEC=$((16#$OFF))
    CHAR_POS=$(($OFF_DEC * 2))

    # Get the opcode byte to determine mask width
    OPCODE_HEX="${MASKED_DOL:$CHAR_POS:2}"
    OPCODE_DEC=$((16#$OPCODE_HEX))
    OPCODE_BITS=$(($OPCODE_DEC >> 2))

    # For branch instructions (opcode 18 = b/bl), mask the 26-bit offset (keep top 6 bits)
    # For conditional branch (opcode 16 = bc/bcl), mask the 14-bit displacement (keep top 16 bits)
    # For other relocations, mask the lower 16 bits
    if [ "$OPCODE_BITS" -eq 18 ] 2>/dev/null; then
        # b/bl instruction - mask lower 26 bits (keep top 6 bits of first byte)
        FIRST="${MASKED_DOL:$CHAR_POS:2}"
        FIRST_VAL=$((16#$FIRST))
        MASKED_FIRST=$(printf "%02x" $(($FIRST_VAL & 0xFC)))
        MASKED_DOL="${MASKED_DOL:0:$CHAR_POS}${MASKED_FIRST}000000${MASKED_DOL:$(($CHAR_POS + 8))}"

        FIRST="${MASKED_COMP:$CHAR_POS:2}"
        FIRST_VAL=$((16#$FIRST))
        MASKED_FIRST=$(printf "%02x" $(($FIRST_VAL & 0xFC)))
        MASKED_COMP="${MASKED_COMP:0:$CHAR_POS}${MASKED_FIRST}000000${MASKED_COMP:$(($CHAR_POS + 8))}"
    elif [ "$OPCODE_BITS" -eq 16 ] 2>/dev/null; then
        # bc/bcl instruction - mask lower 16 bits (14-bit displacement + AA + LK)
        # Keep first 2 bytes (opcode + BO + BI), mask last 2 bytes
        MASKED_DOL="${MASKED_DOL:0:$(($CHAR_POS + 4))}0000${MASKED_DOL:$(($CHAR_POS + 8))}"
        MASKED_COMP="${MASKED_COMP:0:$(($CHAR_POS + 4))}0000${MASKED_COMP:$(($CHAR_POS + 8))}"
    else
        # 16-bit relocation - mask 2 bytes
        MASKED_DOL="${MASKED_DOL:0:$(($CHAR_POS + 4))}0000${MASKED_DOL:$(($CHAR_POS + 8))}"
        MASKED_COMP="${MASKED_COMP:0:$(($CHAR_POS + 4))}0000${MASKED_COMP:$(($CHAR_POS + 8))}"
    fi
done

echo ""
echo "DOL bytes:      $DOL_BYTES"
echo "Compiled bytes: $COMPILED_TRIMMED"
if [ -n "$RELOC_OFFSETS" ]; then
    echo "Masked DOL:     $MASKED_DOL"
    echo "Masked Comp:    $MASKED_COMP"
    echo "Relocations at: $RELOC_OFFSETS"
fi
echo ""

if [ "$MASKED_DOL" = "$MASKED_COMP" ]; then
    echo "MATCH! Function at $ADDR ($SIZE bytes) matches (with relocations masked)."
    exit 0
else
    echo "MISMATCH at $ADDR ($SIZE bytes)"
    echo ""
    echo "Compiled disassembly:"
    $OBJDUMP -d "$OBJ"
    echo ""
    echo "Relocations:"
    $OBJDUMP -r "$OBJ"
    exit 1
fi
