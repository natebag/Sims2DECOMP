#!/bin/bash
cd "/f/coding/Decompiles/Sims 2"
SRC="src/wip/version_diff/match_0x80119428_cTrackCacheHandle_GetTrackObject.cpp"
BASENAME="match_0x80119428_cTrackCacheHandle_GetTrackObject"
OUTDIR="/tmp/verify_test"
mkdir -p "$OUTDIR"

CLEAN_SRC="$OUTDIR/${BASENAME}_clean.cpp"
sed 's|//.*||; s|/\*.*\*/||' "$SRC" > "$CLEAN_SRC"

SN_CC1PLUS="compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/cc1plus.exe"
SN_AS="compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin/NgcAs.exe"
OBJDUMP="/f/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump"

ASM="$OUTDIR/${BASENAME}.s"
OBJ="$OUTDIR/${BASENAME}.o"

"$SN_CC1PLUS" "$CLEAN_SRC" -o "$ASM" -quiet -O2 -fno-elide-constructors -msdata=eabi -G 8
"$SN_AS" "$ASM" -o "$OBJ"

echo "=== objdump raw ==="
"$OBJDUMP" -s -j .text "$OBJ"

echo "=== extracted bytes ==="
BYTES=$("$OBJDUMP" -s -j .text "$OBJ" 2>/dev/null | awk '/Contents of section .text/{found=1;next} found{print}' | awk '{for(i=2;i<=5;i++) printf "%s", $i; printf "\n"}' | tr -d ' \n')
echo "[$BYTES]"
echo "length=${#BYTES}"
