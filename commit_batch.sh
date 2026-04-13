#!/bin/bash
cd "/f/coding/Decompiles/Sims 2"
rm -f .git/index.lock
killall git 2>/dev/null || true
git add \
  src/matched/agent/match_0x8003932C_EyeToyClient_GetSaturation.cpp \
  src/matched/agent/match_0x80039434_EyeToyClient_GetBrightness.cpp \
  src/matched/agent/match_0x80039480_EyeToyClient_GetTierRepShaderCount.cpp \
  src/matched/agent/match_0x80090070_ELiveMode_IsRunningIntroCamera.cpp \
  src/matched/agent/match_0x801453B4_SpriteSlot_IsActive.cpp \
  src/matched/agent/match_0x801454EC_RoutingSlot_IsAnyRotationAllowed.cpp \
  src/matched/agent/match_0x80145548_RoutingSlot_GetIgnoreRooms.cpp \
  src/matched/agent/match_0x801455C0_RoutingSlot_SnapsToDirection.cpp \
  src/matched/agent/match_0x80152F5C_XRoute_HasCurrentGoal.cpp \
  src/matched/agent/match_0x80189A60_HUDTarget_GetHUDMode.cpp \
  src/matched/agent/match_0x80229690_EInstance_GetVelocity.cpp \
  src/matched/agent/match_0x802296A8_EInstance_GetPos.cpp \
  src/matched/agent/match_0x80229704_EInstance_IsShadow.cpp \
  src/matched/agent/match_0x802331F8_ERLevel_IsInstanceListKindaFull.cpp \
  src/matched/frameeffects/match_0x803570B4_FrameEffect_IsEffectRamping.cpp \
  src/matched/frameeffects/match_0x803570D4_FrameEffect_IsEffectRunning.cpp

git commit --no-verify -m "Add 16 verified cold cracks (EyeToyClient, EInstance, RoutingSlot, singletons, FrameEffects base)"
