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
    # Check for per-file flag overrides via // FLAGS: comment
    EXTRA_FLAGS=$(grep '// FLAGS:' "$SRC" 2>/dev/null | head -1 | sed 's|.*// FLAGS: *||')
    if [ -n "$EXTRA_FLAGS" ]; then
        SN_FLAGS="-quiet -O2 $EXTRA_FLAGS -msdata=eabi -G 8"
    else
        SN_FLAGS="-quiet -O2 -fno-elide-constructors -fno-schedule-insns2 -msdata=eabi -G 8"
    fi
    echo "Compiling $SRC with SN Systems ProDG..."
    "$SN_CC1PLUS" "$CLEAN_SRC" -o "$ASM" $SN_FLAGS 2>&1
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

# Step 4: Get relocations with type and target (offset, type, target)
# Format: "offset|type|target" (pipe-separated, one per line)
RELOC_DATA=$($OBJDUMP -r "$OBJ" 2>/dev/null | awk '/^[0-9a-f]+ /{print $1"|"$2"|"$3}')

# Step 4b: Compare with relocation-aware logic
COMPILED_TRIMMED="${COMPILED_BYTES:0:$(($SIZE * 2))}"

PYTHON2="/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"
RESULT=$($PYTHON2 -c "
import sys, re
dol = '$DOL_BYTES'
comp = '$COMPILED_TRIMMED'
reloc_lines = '''$RELOC_DATA'''.strip().split('\n')
if len(dol) != len(comp):
    print('SIZE_MISMATCH')
    print('DOL length: %d, Compiled length: %d' % (len(dol), len(comp)))
    sys.exit(0)

# Parse relocations: list of (offset, type, target_str)
relocs = []
for line in reloc_lines:
    if not line.strip() or '|' not in line: continue
    parts = line.split('|')
    if len(parts) < 3: continue
    off = int(parts[0], 16)
    rtype = parts[1].strip()
    target = parts[2].strip()
    relocs.append((off, rtype, target))

def hex_to_bytes(h):
    return bytes(int(h[i:i+2], 16) for i in range(0, len(h), 2))
def bytes_to_hex(b):
    return ''.join('%02x' % x for x in b)

dol_b = list(hex_to_bytes(dol))
comp_b = list(hex_to_bytes(comp))

# For each relocation, decide:
# 1. LOCAL branch (.text+OFFSET): substitute expected displacement into compiled, then compare bytes normally
# 2. EXTERNAL symbol: mask the relevant bits in BOTH (we cannot resolve)
mask = [False] * len(dol_b)

for off, rtype, target in relocs:
    is_local = target.startswith('.text')
    # PPC ELF relocation offsets:
    #   REL14, REL24, EMB_SDA21: offset = instruction start (4 bytes)
    #   ADDR16_HA, ADDR16_LO:    offset = the 16-bit field (instruction + 2)
    if is_local and rtype in ('R_PPC_REL14', 'R_PPC_REL24'):
        # LOCAL branch: substitute the expected displacement and compare normally
        m = re.match(r'\.text\+0x([0-9a-fA-F]+)', target)
        if not m: continue
        tgt_off = int(m.group(1), 16)
        disp = tgt_off - off  # post-link PC-relative displacement
        instr = (comp_b[off]<<24)|(comp_b[off+1]<<16)|(comp_b[off+2]<<8)|comp_b[off+3]
        if rtype == 'R_PPC_REL14':
            new = (instr & 0xFFFF0003) | (disp & 0xFFFC)
        else:  # R_PPC_REL24
            new = (instr & 0xFC000003) | (disp & 0x03FFFFFC)
        comp_b[off]   = (new>>24) & 0xFF
        comp_b[off+1] = (new>>16) & 0xFF
        comp_b[off+2] = (new>>8) & 0xFF
        comp_b[off+3] = new & 0xFF
    elif rtype in ('R_PPC_ADDR16_HA', 'R_PPC_ADDR16_LO'):
        # External 16-bit immediate field: mask the 2 bytes at the relocation offset
        mask[off]   = True
        mask[off+1] = True
    elif rtype == 'R_PPC_EMB_SDA21':
        # 21-bit SDA load/store: mask the entire 4-byte instruction
        # (lower 21 bits hold the rA/D field which the linker patches)
        # The opcode (top 6 bits) stays the same, but to keep things simple,
        # mask all 4 bytes — false positives on opcode are unlikely.
        mask[off]   = True
        mask[off+1] = True
        mask[off+2] = True
        mask[off+3] = True
    elif rtype == 'R_PPC_REL24':
        # External 24-bit branch (bl <extern>): mask all 4 bytes
        mask[off]   = True
        mask[off+1] = True
        mask[off+2] = True
        mask[off+3] = True
    elif rtype == 'R_PPC_REL14':
        # External 14-bit branch (rare): mask 16-bit displacement field at instr+2
        mask[off+2] = True
        mask[off+3] = True
    else:
        # Unknown relocation type — be safe and mask 4 bytes
        mask[off]   = True
        mask[off+1] = True
        mask[off+2] = True
        mask[off+3] = True

# Apply mask
for i in range(len(dol_b)):
    if mask[i]:
        dol_b[i] = 0xCC
        comp_b[i] = 0xCC

dol_m = bytes_to_hex(bytes(dol_b))
comp_m = bytes_to_hex(bytes(comp_b))

if dol_m == comp_m:
    print('MATCH')
else:
    print('MISMATCH')
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
echo "Relocations:"
echo "$RELOC_DATA" | sed 's/^/  /'
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
