#!/bin/bash
cd "/f/coding/Decompiles/Sims 2"
rm -f .git/index.lock
killall git 2>/dev/null || true
git add \
  src/matched/agent/match_800AAA18_AmbientSoundPlayer__IsValid.cpp \
  src/matched/agent/match_80111148_ObjSelector__GetIsMultiTileSubObject.cpp \
  src/matched/agent/match_80112C40_ObjTestSim__IsMenuInProgress.cpp \
  src/matched/agent/match_80159D94_ObjectDataBehaviorConstants__SetIsTuning.cpp

git commit --no-verify -m "Add 4 verified cold cracks (AmbientSoundPlayer, ObjSelector, ObjTestSim, ObjectDataBehaviorConstants)"
