// eanimcontroller_stubs.cpp - Stub implementations for Eanimcontroller
// Auto-generated from symbols.json - 82 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x80486070 | 224 bytes
EAnimController::EAnimController(void) { }

// 0x80486150 | 96 bytes
EAnimController::~EAnimController(void) { }

// 0x804861B0 | 272 bytes
void EAnimController::Deallocate(void) { }

// 0x804862C0 | 212 bytes
void EAnimController::DeallocateNodes(void) { }

// 0x80486394 | 1068 bytes
void EAnimController::Init(unsigned int, eAnimatedObjectType, unsigned int) { }

// 0x8048682C | 320 bytes
void EAnimController::IsTrackValid(eTrackFlags) { }

// 0x80486AD8 | 332 bytes
void EAnimController::ResumeTrack(eTrackFlags) { }

// 0x80486C24 | 148 bytes
void EAnimController::CalcOrientMatrix(EVec3 &, EVec3 &, EVec3 &, EMat4 &) { }

// 0x80486CB8 | 1144 bytes
void EAnimController::Update(EVec3 *, EVec3 *, EVec3) { }

// 0x80487130 | 392 bytes
void EAnimController::ProcessEvents(TNodeList<EACEventRange *> &, bool) { }

// 0x804872B8 | 108 bytes
void EAnimController::AddEventRange(TNodeList<EACEventRange *> &, EACTrack *, float, float) { }

// 0x80487324 | 2488 bytes
void EAnimController::UpdateTrack(EACTrack *, EVec3 &, EVec3 &, TNodeList<EACEventRange *> &) { }

// 0x80487CDC | 152 bytes
void EAnimController::GetSlavePos(EACTrack *, EACTrack *) { }

// 0x80487DA4 | 464 bytes
void EAnimController::GetAnimTrans(eTrackFlags, EVec3 &) { }

// 0x80487F74 | 696 bytes
void EAnimController::GetAnimTranslate(eTrackFlags, EVec3 &, EVec3 &) { }

// 0x8048822C | 420 bytes
void EAnimController::GetAnimTime(eTrackFlags) { }

// 0x804883D0 | 100 bytes
void EAnimController::GetAnimVelocity(eTrackFlags, EVec3 &) { }

// 0x80488434 | 164 bytes
void EAnimController::GetFirstRelevantTrack(void) { }

// 0x804884F0 | 184 bytes
void EAnimController::AnimateTrack(EACTrack *, EACNodeState *, EMat4 *) { }

// 0x804885A8 | 1100 bytes
void EAnimController::Compute(EMat4 &, int) { }

// 0x804889F4 | 180 bytes
void EAnimController::AllocMatrices(void) { }

// 0x80488AA8 | 176 bytes
void EAnimController::ComputeInverse(EMat4 &, int) { }

// 0x80488B98 | 312 bytes
void EAnimController::PostMultNodeAndDescendents(int, EMat4 &) { }

// 0x80488CD0 | 312 bytes
void EAnimController::PreMultNodeAndDescendents(int, EMat4 &) { }

// 0x80488E08 | 348 bytes
void EAnimController::CalcTightBoundBox(EMat4 &, EBound3 &, bool *) { }

// 0x80488F64 | 68 bytes
void EAnimController::FixAccumulationForRootNode(EACTrack *, EACNodeState &) { }

// 0x80488FA8 | 772 bytes
void EAnimController::AnimateSpecial(ERAnim *, float, EACTrackStreams *, EACNodeState *, EAnimNodeDataPos *, EACNodeState &) { }

// 0x804892AC | 824 bytes
void EAnimController::BlendNodeArrays(EACTrack *, EACNodeState *, EACNodeState *) { }

// 0x804895E4 | 1176 bytes
void EAnimController::Animate(EACTrack *, EACNodeState *) { }

// 0x80489A7C | 400 bytes
void EAnimController::Blend(float, EACNodeState &, EACNodeState &) { }

// 0x80489C0C | 508 bytes
void EAnimController::Layer(float, EACNodeState &, EACNodeState &) { }

// 0x80489E3C | 1624 bytes
void EAnimController::ComputeMatrices(EMat4 &) { }

// 0x8048A494 | 1040 bytes
void EAnimController::CalcMatrix(EMat4 &, ECharacterNode &, EACNodeState &, EMat4 &) { }

// 0x8048A8A4 | 96 bytes
void EAnimController::StopAllTracks(void) { }

// 0x8048A904 | 352 bytes
void EAnimController::DeactivateTrack(EACTrack *) { }

// 0x8048AA64 | 796 bytes
void EAnimController::CreateStreams(EACTrack *) { }

// 0x8048AD80 | 236 bytes
void EAnimController::DestroyStreams(EACTrack *) { }

// 0x8048AE6C | 328 bytes
void EAnimController::StopTrack(eTrackFlags) { }

// 0x8048AFB4 | 680 bytes
void EAnimController::TransferTrack(eTrackFlags, eTrackFlags) { }

// 0x8048B25C | 360 bytes
void EAnimController::GetTrackAnimId(eTrackFlags) { }

// 0x8048B3C4 | 1044 bytes
void EAnimController::SetStaticBlendTrackAnim(eTrackFlags, unsigned int, float, int, float, EACTrack *) { }

// 0x8048B7D8 | 2444 bytes
void EAnimController::SetTrackAnim(eTrackFlags, unsigned int, int, float, EACTrack **) { }

// 0x8048C1B8 | 360 bytes
void EAnimController::GetTrackAnimName(eTrackFlags) { }

// 0x8048C320 | 408 bytes
void EAnimController::SetTrackIntensity(eTrackFlags, float) { }

// 0x8048C564 | 128 bytes
void EAnimController::SetAllTrackIntensities(float) { }

// 0x8048C5E4 | 348 bytes
void EAnimController::GetTrackBlendTarget(eTrackFlags) { }

// 0x8048C740 | 336 bytes
void EAnimController::GetTrackIntensity(eTrackFlags) { }

// 0x8048C890 | 336 bytes
void EAnimController::GetTrackSpeed(eTrackFlags) { }

// 0x8048C9E0 | 272 bytes
void EAnimController::BlendAllOutgoingTracks(float, float, bool) { }

// 0x8048CAF0 | 96 bytes
void EAnimController::SetTrackBlend(EACTrack *, float) { }

// 0x8048CC98 | 108 bytes
void EAnimController::SetTrackBlendSmooth(EACTrack *, float, float, float) { }

// 0x8048CFB4 | 184 bytes
void EAnimController::SetTrackBlendHermite(EACTrack *, float, float, float, float) { }

// 0x8048D1C8 | 524 bytes
void EAnimController::BlendTrackIntensity(EACTrack *) { }

// 0x8048D3D4 | 156 bytes
void EAnimController::SetTrackPhaseLock(EACTrack *, EACTrack *, float) { }

// 0x8048D470 | 536 bytes
void EAnimController::SetProceduralTrack(eTrackFlags, void (*)(unsigned int, EACTrack *, ERCharacter *, EVec3 &, EVec3 &), void (*)(unsigned int, EACTrack *, EMat4 &, ERCharacter *, EACNodeState *), unsigned int) { }

// 0x8048D688 | 428 bytes
void EAnimController::RestartTrack(eTrackFlags) { }

// 0x8048D834 | 384 bytes
void EAnimController::SetTrackPhase(eTrackFlags, float) { }

// 0x8048D9B4 | 468 bytes
void EAnimController::SetTrackFrame(eTrackFlags, float, bool) { }

// 0x8048DCE8 | 360 bytes
void EAnimController::GetTrackFrameCount(eTrackFlags) { }

// 0x8048DE50 | 336 bytes
void EAnimController::GetTrackFrame(eTrackFlags) { }

// 0x8048DFA0 | 396 bytes
void EAnimController::GetTrackPos(eTrackFlags) { }

// 0x8048E12C | 104 bytes
void EAnimController::SetTrackPos(EACTrack *, float, bool) { }

// 0x8048E2DC | 344 bytes
void EAnimController::IsTrackAnimComplete(eTrackFlags) { }

// 0x8048E434 | 328 bytes
void EAnimController::ClearTrackAnimComplete(eTrackFlags) { }

// 0x8048E57C | 316 bytes
void EAnimController::GetTrackAnimDef(eTrackFlags) { }

// 0x8048E6B8 | 68 bytes
void EAnimController::SetTrackSpeed(EACTrack *, float) { }

// 0x8048E844 | 104 bytes
void EAnimController::SetAllTrackSpeed(float) { }

// 0x8048E8AC | 148 bytes
void EAnimController::VisibilityTest(EMat4 &) { }

// 0x8048E940 | 820 bytes
void EAnimController::CalcVisibilitySphere(EMat4 &, EBoundSphere &) { }

// 0x8048EC74 | 180 bytes
void EAnimController::GetAnimRootNodeTrans(EACTrack *) { }

// 0x8048ED28 | 116 bytes
void EAnimController::Draw(ERC *, ERModel *, EMat4 &) { }

// 0x8048ED9C | 308 bytes
void EAnimController::CalcNodePos(int) { }

// 0x8048EED0 | 284 bytes
void EAnimController::CalcNodeMatrix(int, EMat4 &) { }

// 0x8048EFEC | 136 bytes
void EAnimController::GetNodeMatrix(int) { }

// 0x8048F074 | 348 bytes
void EAnimController::CalcNodeOrientWithoutLocalRot(int, EMat4 &) { }

// 0x8048F1D0 | 468 bytes
void EAnimController::CalcNodeOrient(int, EMat4 &) { }

// 0x8048F3A4 | 92 bytes
void EAnimController::SetNodeIgnoreAnimatedVisibility(int, bool) { }

// 0x8048F400 | 92 bytes
void EAnimController::SetNodeVisible(int, bool) { }

// 0x8048F45C | 276 bytes
void EAnimController::SetTrackActive(EACTrack *, bool) { }

// 0x8048F570 | 208 bytes
void EAnimController::Enable(bool, EMat4 &) { }

// 0x8048F640 | 80 bytes
void EAnimController::CalcBillinearCoeff(float, float, float, float &, float &, float &, float &) { }

// 0x804905DC | 144 bytes
void EAnimController::GetNonMainTrackFlagFromIndex(int) { }
