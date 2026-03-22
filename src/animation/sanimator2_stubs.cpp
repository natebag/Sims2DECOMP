// sanimator2_stubs.cpp - Stub implementations for Sanimator2
// Auto-generated from symbols.json - 158 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x800A04FC | 732 bytes
SAnimator2::SAnimator2(void) { }

// 0x800A07D8 | 512 bytes
SAnimator2::~SAnimator2(void) { }

// 0x800A09D8 | 532 bytes
void SAnimator2::Initialize(cXPerson *) { }

// 0x800A0BEC | 384 bytes
void SAnimator2::InitStaticAnimationElements(void) { }

// 0x800A0D90 | 236 bytes
void SAnimator2::TryChangeSuit(void) { }

// 0x800A0E7C | 108 bytes
void SAnimator2::checkParticleCleanup(void) { }

// 0x800A0EE8 | 912 bytes
void SAnimator2::updateFreeMoveState(void) { }

// 0x800A1278 | 84 bytes
void SAnimator2::updateMovementState(void) { }

// 0x800A12CC | 1024 bytes
void SAnimator2::Update(void) { }

// 0x800A16CC | 1220 bytes
void SAnimator2::updateDiagnosticDisplay(void) { }

// 0x800A1B90 | 352 bytes
void SAnimator2::drawDiagnosticDisplay(ERC *) { }

// 0x800A1E40 | 664 bytes
void SAnimator2::resolveSkillForPrimitive(StackElem *, IdleAnimateParam *, AnimRef *&) { }

// 0x800A23A8 | 292 bytes
void SAnimator2::loadSkillAnim(AnimRef *) { }

// 0x800A2500 | 920 bytes
void SAnimator2::TryIdleAnimate(StackElem *, IdleAnimateParam *) { }

// 0x800A2898 | 452 bytes
void SAnimator2::SelectAlgorithmicIdle(AnimRef *&) { }

// 0x800A2A5C | 3652 bytes
void SAnimator2::TryAnimate(StackElem *, AnimateNewParam *) { }

// 0x800A38A4 | 808 bytes
void SAnimator2::BeginFollow(float) { }

// 0x800A3BCC | 480 bytes
void SAnimator2::FollowOneStep(void) { }

// 0x800A3DAC | 296 bytes
void SAnimator2::EndFollow(void) { }

// 0x800A3EF4 | 120 bytes
void SAnimator2::DequeueAnimEvent(int *) { }

// 0x800A3F6C | 1944 bytes
void SAnimator2::ReconStream(ReconBuffer *, int) { }

// 0x800A470C | 96 bytes
void SAnimator2::getCorrectId(PropRef *) { }

// 0x800A476C | 208 bytes
void SAnimator2::Dress(PropRef *) { }

// 0x800A483C | 392 bytes
void SAnimator2::AddProp(unsigned int, bool) { }

// 0x800A49C4 | 136 bytes
void SAnimator2::RemoveProp(unsigned int) { }

// 0x800A4A4C | 156 bytes
void SAnimator2::PreloadDress(PropRef *) { }

// 0x800A4AE8 | 172 bytes
void SAnimator2::Undress(PropRef *) { }

// 0x800A4C14 | 652 bytes
void SAnimator2::endFollowDone(void) { }

// 0x800A4EA0 | 128 bytes
void SAnimator2::followStandToTurnUpdate(float &, float &, float) { }

// 0x800A4F20 | 592 bytes
void SAnimator2::followSidestepUpdate(float &, float &, float) { }

// 0x800A5170 | 252 bytes
void SAnimator2::followMiddleUpdate(float &, float &, float) { }

// 0x800A526C | 100 bytes
void SAnimator2::followMoveToTurnUpdate(float &, float &, float) { }

// 0x800A52D0 | 100 bytes
void SAnimator2::followDoneUpdate(float &, float &, float) { }

// 0x800A5334 | 352 bytes
void SAnimator2::endMoveAnimation(void) { }

// 0x800A5494 | 488 bytes
void SAnimator2::UpdatePortalMode(void) { }

// 0x800A567C | 1076 bytes
void SAnimator2::moveAnimation(void) { }

// 0x800A5AB0 | 680 bytes
void SAnimator2::awarenessMove(void) { }

// 0x800A5D58 | 120 bytes
void SAnimator2::GetTurnRate(void) { }

// 0x800A5DD0 | 348 bytes
void SAnimator2::rotateAnimation(float, float, float) { }

// 0x800A5F2C | 412 bytes
void SAnimator2::sidestepAlongNode(float &) { }

// 0x800A60C8 | 192 bytes
void SAnimator2::advanceAlongNode(float &) { }

// 0x800A6188 | 336 bytes
void SAnimator2::getUseSpeed(float, float, float, float) { }

// 0x800A62D8 | 140 bytes
void SAnimator2::EnableWalkFade(unsigned int &, float, float, float) { }

// 0x800A6364 | 708 bytes
void SAnimator2::moveTowardsDestination(float &, EVec2 &) { }

// 0x800A6628 | 1352 bytes
void SAnimator2::updateRenderAnimation(void) { }

// 0x800A6B70 | 1172 bytes
void SAnimator2::updateParticles(void) { }

// 0x800A704C | 620 bytes
void SAnimator2::handleMoodAnimations(void) { }

// 0x800A72B8 | 864 bytes
void SAnimator2::playFootprint(char *) { }

// 0x800A7618 | 224 bytes
void SAnimator2::getFootSound(char *) { }

// 0x800A76F8 | 1748 bytes
void SAnimator2::handleSidestepAnimation(void) { }

// 0x800A7DCC | 1568 bytes
void SAnimator2::handleWalkRunAnimation(void) { }

// 0x800A83EC | 636 bytes
void SAnimator2::CheckCollision(EVec2 &, EVec2 &) { }

// 0x800A8668 | 2660 bytes
void SAnimator2::handleFreeMoveWalkRunAnimation(void) { }

// 0x800A90CC | 508 bytes
void SAnimator2::handleRunStopAnimation(void) { }

// 0x800A92C8 | 184 bytes
void SAnimator2::SetNextStateFromCompletedTurn(void) { }

// 0x800A9380 | 832 bytes
void SAnimator2::selectRandomIdle(void) { }

// 0x800A96C0 | 1340 bytes
void SAnimator2::handleSkillIdleAnimation(void) { }

// 0x800A9BFC | 3232 bytes
void SAnimator2::handleIdleAnimation(void) { }

// 0x800AA89C | 344 bytes
void SAnimator2::handleImpatientIdleAnimation(void) { }

// 0x800AA9F4 | 144 bytes
void SAnimator2::clearImpatientIdleAnimation(void) { }

// 0x800AAA84 | 240 bytes
void SAnimator2::LoadSMOptionalMotionAnims(void) { }

// 0x800AAB74 | 240 bytes
void SAnimator2::LoadDCOptionalMotionAnims(void) { }

// 0x800AAC64 | 264 bytes
void SAnimator2::LoadOptionalIdleAnim(void) { }

// 0x800AAD6C | 196 bytes
void SAnimator2::UnloadPendingLongIdleAnim(void) { }

// 0x800AAE30 | 292 bytes
void SAnimator2::UnloadOptionalIdleAnim(void) { }

// 0x800AAF54 | 236 bytes
void SAnimator2::UnloadDCOptionalMotionAnims(void) { }

// 0x800AB040 | 236 bytes
void SAnimator2::UnloadSMOptionalMotionAnims(void) { }

// 0x800AB12C | 108 bytes
void SAnimator2::CheckOptionalMotionAnimStatusOnStateChange(SAnimator2::eAnimState) { }

// 0x800AB198 | 1264 bytes
void SAnimator2::handleTurnAnimation(void) { }

// 0x800AB688 | 880 bytes
void SAnimator2::positionCharacter(EMat4 *) { }

// 0x800ABA20 | 272 bytes
void SAnimator2::AttachParticleEffect(unsigned int, unsigned int, int) { }

// 0x800ABB30 | 240 bytes
void SAnimator2::DetachParticleEffect(unsigned int, unsigned int, int) { }

// 0x800ABCCC | 148 bytes
void SAnimator2::GetEngineFormatPos(void) { }

// 0x800ABD60 | 924 bytes
void SAnimator2::processEvents(AnimRef &, int, int, bool, bool) { }

// 0x800AC0FC | 1208 bytes
void SAnimator2::eventHandler(EAnimNote &, int) { }

// 0x800AC5B4 | 684 bytes
void SAnimator2::PreloadEvents(AnimRef *) { }

// 0x800AC860 | 116 bytes
void SAnimator2::PreloadBoneParticleEvent(REffectsAttachment *) { }

// 0x800AC8D4 | 408 bytes
void SAnimator2::_handleParticleEvent(REffectsAttachment *) { }

// 0x800ACA6C | 1068 bytes
void SAnimator2::procBoneParticleEvt(AnimParticleData *, bool) { }

// 0x800ACE98 | 476 bytes
void SAnimator2::cleanupParticlesDelayed(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle *> *> *) { }

// 0x800AD074 | 484 bytes
void SAnimator2::cleanupParticlesImmediate(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle *> *> *) { }

// 0x800AD258 | 920 bytes
void SAnimator2::cleanupParticles(TRedBlackTree<unsigned int, TRedBlackTree<unsigned int, EBoneParticle *> *> *) { }

// 0x800AD5F0 | 84 bytes
void SAnimator2::playRumble(char *) { }

// 0x800AD7F4 | 84 bytes
void SAnimator2::triggerCameraBloom(char *) { }

// 0x800AD9C0 | 1084 bytes
void SAnimator2::startSkill(AnimRef *, bool, unsigned int) { }

// 0x800ADDFC | 336 bytes
void SAnimator2::isAnimationDone(void) { }

// 0x800ADF88 | 164 bytes
void SAnimator2::setPersonDirection(float) { }

// 0x800AE02C | 1364 bytes
void SAnimator2::updateCarryAnimation(void) { }

// 0x800AE834 | 312 bytes
void SAnimator2::updateRenderModels(void) { }

// 0x800AE96C | 224 bytes
void SAnimator2::setJobModel(void) { }

// 0x800AEA4C | 200 bytes
void SAnimator2::wearNormal(void) { }

// 0x800AEB14 | 452 bytes
void SAnimator2::setNewModel(char *, bool, bool) { }

// 0x800AECD8 | 420 bytes
void SAnimator2::RestoreNonCostumeRelatedSimDescriptionItems(CasSimDescriptionS2C *, CasSimDescriptionS2C *, bool) { }

// 0x800AEE7C | 380 bytes
void SAnimator2::GetCostumeName(SAnimator::OutfitS2C) { }

// 0x800AF000 | 108 bytes
void SAnimator2::GetCarryHandPosAndDir(EVec3 &, EVec3 &, EMat4 &) { }

// 0x800AF06C | 188 bytes
void SAnimator2::GetBonePos(SAnimator::BoneIdx, EVec3 &) { }

// 0x800AF128 | 108 bytes
void SAnimator2::PropsHaveAlpha(void) { }

// 0x800AF194 | 476 bytes
void SAnimator2::DrawProps(ERC *, bool, EShader *) { }

// 0x800AF370 | 212 bytes
void SAnimator2::DrawPropsShadow(ERC *) { }

// 0x800AF444 | 152 bytes
void SAnimator2::removeAllProps(void) { }

// 0x800AF4DC | 248 bytes
void SAnimator2::updateCensor(void) { }

// 0x800AF5D4 | 2608 bytes
void SAnimator2::DrawCensor(ERC *) { }

// 0x800B0008 | 156 bytes
void SAnimator2::addAnimationName(char *) { }

// 0x800B00A4 | 348 bytes
void SAnimator2::drawLastAnimationNames(ERC *) { }

// 0x800B0200 | 1168 bytes
void SAnimator2::GetFootSound(CTilePt &, char *) { }

// 0x800B0698 | 68 bytes
void SAnimator2::UpdateAnimationValidity(void) { }

// 0x800B0750 | 216 bytes
void SAnimator2::setAwarenessFollowStart(float) { }

// 0x800B0828 | 580 bytes
void SAnimator2::shouldUseLowMotiveIdle(void) { }

// 0x800B0A6C | 252 bytes
void SAnimator2::shouldUseLowMotiveWalk(void) { }

// 0x800B0B68 | 240 bytes
void SAnimator2::IsSimulatorControlled(void) { }

// 0x800B0C58 | 104 bytes
void SAnimator2::SetPlayerControl(bool) { }

// 0x800B3B1C | 84 bytes
void* SAnimator2::operator new(unsigned int) { }

// 0x800B3D14 | 180 bytes
void SAnimator2::getPersonDirection(void) { }

// 0x800B4124 | 112 bytes
void SAnimator2::EndAutoRun(void) { }

// 0x800B4194 | 100 bytes
void SAnimator2::getIndexOfPropID(unsigned int) { }

// 0x800B4220 | 144 bytes
void SAnimator2::SetDesiredFacing(float) { }

// 0x800B42B0 | 92 bytes
void SAnimator2::addSkillAnimationName(char *, AnimRef *) { }

// 0x800B430C | 116 bytes
void SAnimator2::clearSuspendedCarry(void) { }

// 0x800B4380 | 76 bytes
void SAnimator2::SetIdleAnimPlaybackParameters(EACTrack *) { }

// 0x800B43CC | 140 bytes
void SAnimator2::determineFirstFollowMode(TileList *) { }

// 0x800B4458 | 324 bytes
void SAnimator2::determineWalkRunStyle(float) { }

// 0x800B459C | 428 bytes
void SAnimator2::StartDefaultIdle(void) { }

// 0x800B4748 | 88 bytes
void SAnimator2::DetachMonitoredTrack(void) { }

// 0x800B47A0 | 68 bytes
void SAnimator2::updateDesiredAndDeltaDir(float &, float &) { }

// 0x800B47E4 | 116 bytes
void SAnimator2::setFirstFollowMode(SAnimator2::eFollowMode) { }

// 0x800B4894 | 124 bytes
void SAnimator2::setFollowEnd(void) { }

// 0x800B4910 | 128 bytes
void SAnimator2::setFollowDone(void) { }

// 0x800B4990 | 120 bytes
void SAnimator2::defaultVelocity(int) { }

// 0x800B4A08 | 80 bytes
void SAnimator2::getAnimDuration(ERAnim *) { }

// 0x800B4A58 | 808 bytes
void SAnimator2::setSideStepSpeedFromAnimation(AnimRef *) { }

// 0x800B4D80 | 824 bytes
void SAnimator2::setMovementVelocityFromAnimation(void) { }

// 0x800B50B8 | 488 bytes
void SAnimator2::setRotationRateFromShuffleDir(int, float) { }

// 0x800B52A0 | 520 bytes
void SAnimator2::initShuffleRotation(float) { }

// 0x800B54A8 | 88 bytes
void SAnimator2::getIsLeftFootUp(void) { }

// 0x800B5500 | 144 bytes
void SAnimator2::getShuffleDirFromDeltaDir(float) { }

// 0x800B5590 | 116 bytes
void SAnimator2::getDeltaDirFromDesiredDir(float) { }

// 0x800B5604 | 404 bytes
void SAnimator2::getDesiredDir(void) { }

// 0x800B5798 | 176 bytes
void SAnimator2::GetMovementVelocityFromStyle(SAnimator2::eWalkRunStyle) { }

// 0x800B5848 | 852 bytes
void SAnimator2::setAnimationState(void) { }

// 0x800B5B9C | 612 bytes
void SAnimator2::getTurnSkillID(AnimRef *&, int) { }

// 0x800B5E00 | 232 bytes
void SAnimator2::getSidestepSkillIDs(AnimRef *&, AnimRef *&, float) { }

// 0x800B5EE8 | 424 bytes
void SAnimator2::getWalkRunSkillID(AnimRef *&) { }

// 0x800B6090 | 156 bytes
void SAnimator2::UpdateNPCAutoRunState(void) { }

// 0x800B612C | 1580 bytes
void SAnimator2::UpdateNPCAutoRun(void) { }

// 0x800B6758 | 92 bytes
void SAnimator2::getSidestepIntensity(void) { }

// 0x800B67B4 | 1724 bytes
void SAnimator2::initSidestep(void) { }

// 0x800B6E70 | 900 bytes
void SAnimator2::initWalkRun(void) { }

// 0x800B71F4 | 352 bytes
void SAnimator2::initWalkRunFadeOut(void) { }

// 0x800B7354 | 848 bytes
void SAnimator2::selectIdleOverlay(void) { }

// 0x800B76A4 | 88 bytes
void SAnimator2::stopIdleOverlay(void) { }

// 0x800B76FC | 84 bytes
void SAnimator2::skillIsIdle(void) { }

// 0x800B7750 | 180 bytes
void SAnimator2::ShouldEndSkillTrack(void) { }

// 0x800B7804 | 552 bytes
void SAnimator2::startCarry(void) { }

// 0x800B7A2C | 376 bytes
void SAnimator2::stopCarry(void) { }

// 0x800B7BA4 | 468 bytes
void SAnimator2::setAwarenessFollowEnd(void) { }

// 0x800B7D78 | 120 bytes
void SAnimator2::setAwarenessFollowMiddle(void) { }

// 0x800B7DF0 | 432 bytes
void SAnimator2::exitAwarenessFollow(void) { }

// 0x800B7FA0 | 112 bytes
void SAnimator2::StartAutoRun(float) { }
