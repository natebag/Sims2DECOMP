// awarenessmanager_stubs.cpp - Stub implementations for Awarenessmanager
// Auto-generated from symbols.json - 49 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x80019160 | 96 bytes
AwarenessManager::AwarenessManager(void) { }

// 0x800191C0 | 232 bytes
void AwarenessManager::Init(SAnimator2 *, EAnimController *) { }

// 0x80019360 | 84 bytes
AwarenessManager::~AwarenessManager(void) { }

// 0x800193B4 | 204 bytes
void AwarenessManager::AwarenessCheck(unsigned int) { }

// 0x80019480 | 68 bytes
void AwarenessManager::handleAwarenessAnimations(unsigned int) { }

// 0x800194C4 | 8 bytes
void AwarenessManager::SetIsRaining(bool) { }

// 0x800194CC | 124 bytes
void AwarenessManager::AwarenessAutoRunCheck(float) { }

// 0x80019548 | 40 bytes
void AwarenessManager::SetPlayerControl(bool) { }

// 0x80019570 | 312 bytes
void AwarenessManager::GetFirstNodeRotation(float, float) { }

// 0x800196A8 | 192 bytes
void AwarenessManager::GetSecondNodeRotation(float) { }

// 0x80019768 | 516 bytes
void AwarenessManager::AwarenessAnimateHeadLeadsMotion(unsigned int, EACTrack *, EMat4 &, ERCharacter *, EACNodeState *) { }

// 0x8001996C | 516 bytes
void AwarenessManager::AwarenessAnimateTorsoLeadsMotion(unsigned int, EACTrack *, EMat4 &, ERCharacter *, EACNodeState *) { }

// 0x80019B70 | 224 bytes
void AwarenessManager::SetAwarenessTargetAngle(cXObject *) { }

// 0x80019C50 | 352 bytes
void AwarenessManager::handlePassiveInfluenceAnimation(unsigned int) { }

// 0x80019DB0 | 104 bytes
void AwarenessManager::handleMemoryAwarenessAnimation(unsigned int) { }

// 0x80019E18 | 176 bytes
void AwarenessManager::handleAwarenessTurningAnimation(void) { }

// 0x80019EC8 | 68 bytes
void AwarenessManager::SetAwareOfObject(cXObject *) { }

// 0x80019F0C | 52 bytes
void AwarenessManager::SetAwareOfObjectKilled(cXObject *) { }

// 0x80019F40 | 72 bytes
void AwarenessManager::ClearAwareOfObject(cXObject *) { }

// 0x80019F88 | 356 bytes
void AwarenessManager::IsTimeToCheckMemoryAwareness(unsigned int) { }

// 0x8001A0EC | 456 bytes
void AwarenessManager::CanSeePlayer(void) { }

// 0x8001A2B4 | 316 bytes
void AwarenessManager::GetActiveMemoryCategory(cXObject *, int &, int &) { }

// 0x8001A3F0 | 392 bytes
void AwarenessManager::StarMemoryAwarenessSprite(void) { }

// 0x8001A578 | 100 bytes
void AwarenessManager::SetPendingMemoryAwarenessAnim(int, int) { }

// 0x8001A5DC | 480 bytes
void AwarenessManager::StartMemoryAwarenessAnimation(int, int) { }

// 0x8001A7BC | 388 bytes
void AwarenessManager::SetMemoryAwarenessActionToTry(cXObject *) { }

// 0x8001A940 | 716 bytes
void AwarenessManager::MemoryAwarenessClearAction(void) { }

// 0x8001AC0C | 416 bytes
void AwarenessManager::UpdateAwarenessAngle(unsigned int) { }

// 0x8001ADAC | 332 bytes
void AwarenessManager::MemoryAwarenessCheck(unsigned int) { }

// 0x8001AEF8 | 252 bytes
void AwarenessManager::StopPassiveInfluenceAnimation(void) { }

// 0x8001AFF4 | 332 bytes
void AwarenessManager::StartPassiveInfluenceAnimation(AnimRef *) { }

// 0x8001B140 | 96 bytes
void AwarenessManager::RainAwarenessCheck(void) { }

// 0x8001B1A0 | 968 bytes
void AwarenessManager::PassiveInfluenceAwarenessCheck(unsigned int) { }

// 0x8001B568 | 40 bytes
void AwarenessManager::GetPlayerObject(int) { }

// 0x8001B590 | 440 bytes
void AwarenessManager::GetDeltaAngleToTargetObject(cXObject *) { }

// 0x8001D660 | 8 bytes
void AwarenessManager::GetAwarenessAction(void) { }

// 0x8001D668 | 8 bytes
void AwarenessManager::GetAwareOfObject(void) { }

// 0x8001D670 | 12 bytes
void AwarenessManager::IsMemoryAwarenessAnimPending(void) { }

// 0x8001D67C | 12 bytes
void AwarenessManager::IsAutoCarryActive(void) { }

// 0x8001D688 | 8 bytes
void AwarenessManager::SetTimeMultiplier(float) { }

// 0x8001D690 | 8 bytes
void AwarenessManager::SetPauseMultiplier(float) { }

// 0x8001D698 | 8 bytes
void AwarenessManager::GetStateFlags(void) { }

// 0x8001D6B8 | 240 bytes
void AwarenessManager::ShouldAwarenessBeActive(unsigned int) { }

// 0x8001D7A8 | 104 bytes
void AwarenessManager::IsMemoryAwarenessAnimDone(void) { }

// 0x8001D810 | 188 bytes
void AwarenessManager::getPassiveInfluenceSkillID(signed char, AnimRef *&) { }

// 0x8001D8CC | 356 bytes
void AwarenessManager::getAwarenessSkillID(int, int, AnimRef *&) { }

// 0x8001DA30 | 360 bytes
void AwarenessManager::shouldAutoCarry(void) { }

// 0x8001DB98 | 828 bytes
void AwarenessManager::startAutoCarry(void) { }

// 0x8001DED4 | 372 bytes
void AwarenessManager::endAutoCarry(void) { }
