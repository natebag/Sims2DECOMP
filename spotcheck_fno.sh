#!/bin/bash
files=(
  "src/matched/agent/match_0x800347DC_ESim__RefreshSkin.cpp|0x800347DC|48"
  "src/matched/agent/match_0x80094204_MUStatesDisplay_ctor.cpp|0x80094204|52"
  "src/matched/agent/match_0x80161A6C_CasListener__HandleEvent.cpp|0x80161A6C|112"
  "src/matched/agent/match_0x802BC04C_AptValueVector_ctor.cpp|0x802BC04C|28"
  "src/matched/agent/match_0x8012C9D8_cXPersonImpl_GetRouteStackSize.cpp|0x8012C9D8|28"
  "src/matched/agent/match_0x803A48B8_ReconLoadObject_IFFResMap.cpp|0x803A48B8|48"
  "src/matched/agent/match_0x800900A8_ChangeHouseDemolishHouse_ctor.cpp|0x800900A8|56"
  "src/matched/agent/match_0x800EAFC0_cXObjectImpl__EnableSim.cpp|0x800EAFC0|24"
  "src/matched/agent/match_0x803A0254_MoviePlayerEndgameMovieState_dtor.cpp|0x803A0254|52"
  "src/matched/agent/match_0x803A7230_ReconSaveObject_ThumbnailLoader.cpp|0x803A7230|48"
)
passed=0
failed=0
for entry in "${files[@]}"; do
  IFS='|' read -r path addr size <<< "$entry"
  if bash tools/verify_match.sh "$path" "$addr" "$size" > /tmp/verify_out.txt 2>&1; then
    echo "PASS $path"
    passed=$((passed+1))
  else
    echo "FAIL $path"
    tail -n 8 /tmp/verify_out.txt
    failed=$((failed+1))
  fi
done
echo "Results: $passed passed, $failed failed"
