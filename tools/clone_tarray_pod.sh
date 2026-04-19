#!/bin/bash
# Clone TArray POD Destruct/Construct match across 26 identical instances

set -e
cd "F:/coding/Decompiles/Sims 2"

# address:shortname pairs
cat <<'EOF' | while IFS=: read addr slug; do
8039C420:TArray_int_Construct
8039C634:TArray_EVec3_Destruct
8039C7D0:TArray_EVec3_Construct
8039CB54:TArray_ENDummyPoint_Destruct
8039CB84:TArray_ENDummyPoint_Construct
8039CD98:TArray_ENCameraPoint_Destruct
8039CDC8:TArray_ENCameraPoint_Construct
8039F658:TArray_EILightPtr_Destruct
8039F774:TArray_EILightPtr_Construct
803C18AC:TArray_EFileSystem_FileCreator_Destruct
803C24B0:TArray_int_DefaultAlloc_Destruct
803C259C:TArray_int_DefaultAlloc_Construct
803C2F5C:TArray_ucharPtr_Destruct
803C305C:TArray_ucharPtr_Construct
803C38E8:TArray_ESMSStrip_Destruct
803C3D74:TArray_uint_Destruct
803C3DA4:TArray_uint_Construct
803C4340:TArray_SimsLightInfo_Destruct
803C517C:TArray_SimsLightInfo_Construct
803C7BC4:TArray_EFontPagePtr_Destruct
803C7F0C:TArray_EFontPagePtr_Construct
803C9098:TArray_float_ERAnim_Destruct
803C9184:TArray_EAnimEvent_Destruct
803C9424:TArray_float_ERAnim_Construct
803C958C:TArray_EAnimEvent_Construct
803CA044:TArray_SndEvtHitPatch_Destruct
EOF
  file="src/matched/agent/match_0x${addr}_${slug}.cpp"
  fnname="Destruct_POD_${addr}"
  cat > "$file" <<EOT
// FLAGS: -fno-schedule-insns
// 0x${addr} (28B) TArray POD template clone: ${slug}
// Empty-body decrement loop. Identical bytes to 0x8039C3F0 anchor.

void ${fnname}(int*, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do { } while (i--);
}
EOT
  # verify
  if bash tools/verify_match.sh "$file" "0x${addr}" 28 2>&1 | tail -1 | grep -q MATCH; then
    echo "OK 0x${addr} ${slug}"
  else
    echo "FAIL 0x${addr} ${slug}"
    rm -f "$file"
  fi
done
