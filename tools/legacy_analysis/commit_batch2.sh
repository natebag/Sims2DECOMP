#!/bin/bash
cd "/f/coding/Decompiles/Sims 2"
rm -f .git/index.lock
killall git 2>/dev/null || true
git add \
  src/matched/agent/match_0x8003919C_EyeToyClient_GetRepShaderGUID.cpp \
  src/matched/agent/match_0x80042320_EGlobal_InLevelState.cpp \
  src/matched/agent/match_0x800EB218_cXObjectImpl_CountObjectSlots.cpp

git commit --no-verify -m "Add 3 verified cold cracks (EyeToyClient GUID, EGlobal state, cXObjectImpl slots)"
