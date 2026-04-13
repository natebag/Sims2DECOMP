#!/bin/bash
# Usage: bash disasm_dol.sh <addr_hex> <size_decimal>
ADDR=$1
SIZE=$2
DOL="extracted/sys/main.dol"
OBJDUMP="/f/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe"

# Parse DOL header to find text section offset
python -c "
import struct, sys
addr = int('$ADDR', 16)
size = int('$SIZE')
with open('$DOL', 'rb') as f:
    dol = f.read()
text_offsets = struct.unpack('>18I', dol[0x00:0x48])
text_addresses = struct.unpack('>18I', dol[0x48:0x90])
for i in range(7):
    sec_size = int.from_bytes(dol[0x90+i*4:0x94+i*4], 'big')
    if text_addresses[i] <= addr < text_addresses[i] + sec_size:
        offset = text_offsets[i] + (addr - text_addresses[i])
        print(offset)
        sys.exit(0)
print('NOT_FOUND')
sys.exit(1)
" > /tmp/dol_offset.txt

OFFSET=$(cat /tmp/dol_offset.txt)
if [ "$OFFSET" = "NOT_FOUND" ]; then
    echo "Could not find address $ADDR in DOL"
    exit 1
fi

dd if="$DOL" bs=1 skip=$OFFSET count=$SIZE status=none of=/tmp/dol_tmp.bin
"$OBJDUMP" -b binary -m powerpc -D /tmp/dol_tmp.bin | tail -n +8
