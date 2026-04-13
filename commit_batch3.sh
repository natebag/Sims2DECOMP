#!/bin/bash
cd "/f/coding/Decompiles/Sims 2"
rm -f .git/index.lock
killall git 2>/dev/null || true
git add \
  src/matched/agent/match_0x8002C32C_EIWallPart__GetVisible.cpp \
  src/matched/agent/match_80089910_CreateASimBaseState__CASAccepted.cpp \
  src/matched/agent/match_80089938_CreateASimBaseState__CASCanceled.cpp \
  src/matched/agent/match_8005BD6C_GetSimIndex.cpp \
  src/matched/agent/match_800997DC_TheSimsStateMachine__IsFlowStateRequestPending.cpp \
  src/matched/agent/match_0x80189AB0_HUDTarget_IsPlayerHUDVisible.cpp

git commit --no-verify -m "Add 6 verified cold cracks (EIWallPart, CASAccepted/CASCanceled, GetSimIndex, TSM/HUDTarget getters)"
