// sanimator2.cpp - Decompiled small functions from sanimator2.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\sanimator2.obj
//
// 68 small functions (<=64 bytes) decompiled from sanimator2.obj
//
// Matching status (devkitPPC GCC vs original SN Systems compiler):
//   MATCHING:     35 functions - identical instruction output (ignoring relocations)
//   NON_MATCHING: 33 functions - correct logic, different codegen
//
// Common NON_MATCHING causes with GCC vs SN:
//   - GCC uses branchless idioms (addic/subfe) where SN uses branches (cmpwi/beqlr)
//   - GCC uses different registers (r9/r31 vs r0/r30)
//   - GCC uses stw/lwz instead of stmw/lmw for single register saves
//   - GCC tail-calls (bctr/b) where SN does call+return (blrl with stack frame)
//   - GCC reorders stores within a basic block
//   - GCC uses add+stw instead of addi+stwx for indexed array access
//   - GCC omits unnecessary fmr copies
//   - GCC cannot emit SDA-relative (r13-based) loads for static variables

#include "animation/sanimator2.h"
#include "types.h"

// External globals
extern Globals _globals;                       // at 0x80475DCC
extern EGraphics* _pGfx;                      // SDA: r13 - 0x6718

// Float constants from .rodata
static const float kZeroFloat = 0.0f;          // at 0x803D4AF4, 0x803D4C0C
static const float kAnimScale = 0.0625f;       // at 0x803D4A48 (1/16)
static const float kAnimScaleZ = 0.0f;         // at 0x803D4A4C

// ============================================================================
// SAnimatorNullFunc(...)
// Address: 0x8005BD68, Size: 4 bytes
// MATCHING
// ============================================================================
void SAnimatorNullFunc(...) {
}

// ============================================================================
// {anonymous}::GetSimIndex(cXPerson *)
// Address: 0x8005BD6C, Size: 56 bytes
// NON_MATCHING - GCC may use different register allocation for the global
//   access pattern (lis+addi for _globals address)
// ============================================================================
namespace {
int GetSimIndex(cXPerson* person) {
    if (_globals.m_simPlayers[0] == person) {
        return 0;
    }
    if (_globals.m_simPlayers[1] == person) {
        return 1;
    }
    return -1;
}
}

// ============================================================================
// SAnimator2::removeCostume(void)
// Address: 0x800676E4, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::removeCostume() {
    return 1;
}

// ============================================================================
// SAnimator2::SetIsRaining(bool)
// Address: 0x8005C76C, Size: 32 bytes
// NON_MATCHING - GCC tail-calls AwarenessManager::SetIsRaining (addi+b),
//   SN uses full stack frame (stwu+mflr+stw+bl+lwz+mtlr+addi+blr)
// ============================================================================
void SAnimator2::SetIsRaining(bool raining) {
    m_awarenessMgr.SetIsRaining(raining);
}

// ============================================================================
// SAnimator2::Render(int)
// Address: 0x8005C78C, Size: 4 bytes
// MATCHING
// ============================================================================
void SAnimator2::Render(int arg) {
}

// ============================================================================
// SAnimator2::adjustAnimationPlayRates(void)
// Address: 0x8005D014, Size: 56 bytes
// NON_MATCHING - GCC uses beqlr+ and tail-call (b) to SetAllTrackSpeed,
//   SN uses beq- with full stack frame (stwu+bl+lwz+mtlr+addi+blr)
// ============================================================================
void SAnimator2::adjustAnimationPlayRates() {
    if (m_desiredTimeMultiplier != m_timeMultiplier) {
        m_pSim->m_animController.SetAllTrackSpeed(m_timeMultiplier);
    }
}

// ============================================================================
// SAnimator2::ResetSuits(void)
// Address: 0x8005D120, Size: 4 bytes
// MATCHING
// ============================================================================
void SAnimator2::ResetSuits() {
}

// ============================================================================
// SAnimator2::SnapToGrid(void)
// Address: 0x8005D124, Size: 12 bytes
// NON_MATCHING - GCC uses r9, SN uses r0 for the constant 1
// ============================================================================
void SAnimator2::SnapToGrid() {
    // Writes integer 1 to m_pos.z (offset +0x24)
    *(int*)&m_pos.z = 1;
}

// ============================================================================
// SAnimator2::ForceLocation(void)
// Address: 0x8005D130, Size: 52 bytes
// NON_MATCHING - GCC uses mtctr+bctr tail call, SN uses mtlr+blrl with stack frame
// ============================================================================
void SAnimator2::ForceLocation() {
    int** vtbl = (int**)*(int*)this;
    short offset = *(short*)((char*)vtbl + 0x38);
    void (*fn)(void*) = (void(*)(void*)) *((int*)((char*)vtbl + 0x3C));
    fn((char*)this + offset);
}

// ============================================================================
// SAnimator2::IsSkillIdleAnimRunning(void)
// Address: 0x8005D6A0, Size: 52 bytes
// NON_MATCHING - GCC uses different register allocation and may access
//   EAnimController fields at slightly different offsets due to struct layout
// ============================================================================
int SAnimator2::IsSkillIdleAnimRunning() {
    EAnimController* ctrl = &m_pSim->m_animController;
    int trackIdx = ctrl->m_skillTrackIndex;
    if (trackIdx == -1) {
        return 0;
    }
    char* trackBase = (char*)(ctrl->m_trackData);
    char* entry = trackBase + trackIdx * 0xB0;
    int flags = *(int*)(entry + 0x30);
    return (flags >> 5) & 1;
}

// ============================================================================
// SAnimator2::stopCurAnim(bool)
// Address: 0x80066940, Size: 60 bytes
// NON_MATCHING - GCC uses different register allocation (r9/r8/r10 vs r0/r9/r11)
//   and different store ordering in the epilogue
// ============================================================================
void SAnimator2::stopCurAnim(bool resetBlend) {
    if (resetBlend) {
        m_skillTrackIndex = 0;
        m_blendTime = kZeroFloat;
    }
    u32 flags = m_flags;
    m_currentAnimRef = (AnimRef*)0;
    m_currentTick = m_prevTick;
    m_flags = flags & ~0x0100;  // clear bit 8 (PPC bit 23)
}

// ============================================================================
// SAnimator2::lockHandsUpCarryNodes(void)
// Address: 0x80066F00, Size: 64 bytes
// NON_MATCHING - GCC omits the cmpwi check on carry track pointer and
//   emits a tail-call (b) instead of stack frame (stwu+bl+blr)
// ============================================================================
void SAnimator2::lockHandsUpCarryNodes() {
    m_pSim->m_animController.SetTrackBlendFactors((u32)0x0800, m_DualArmCarryIndexArray);
}

// ============================================================================
// SAnimator2::lockCarryArmNodes(float *, EACTrack *)
// Address: 0x80066F40, Size: 64 bytes
// NON_MATCHING - GCC tail-calls (b) instead of using stack frame (stwu+bl+blr),
//   and uses different temp register (r9 vs r11) for argument swap
// ============================================================================
void SAnimator2::lockCarryArmNodes(float* factors, EACTrack* track) {
    m_pSim->m_animController.SetTrackBlendFactors(track, factors);
}

// ============================================================================
// SAnimator2::SetAnimDisplacements(float, float, float)
// Address: 0x8005E7C8, Size: 4 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetAnimDisplacements(float dx, float dy, float dz) {
}

// ============================================================================
// SAnimator2::getPersonX(void)
// Address: 0x8005F8D8, Size: 64 bytes
// NON_MATCHING - GCC uses mtctr+bctrl for indirect call, SN uses mtlr+blrl.
//   GCC also reorders prologue (mflr before stwu vs after) and uses
//   different register (r10 vs r0) for the function pointer.
// ============================================================================
float SAnimator2::getPersonX() {
    char* person = (char*)m_pPerson;
    char** vtbl = *(char***)person;
    char* inner = *(char**)(vtbl + 1);
    short offset = *(short*)(inner + 0x340);
    void* (*fn)(void*) = (void*(*)(void*)) *(int*)(inner + 0x344);
    char* posResult = (char*)fn((char*)vtbl + offset);
    return *(float*)(posResult + 0x04);
}

// ============================================================================
// SAnimator2::getPersonY(void)
// Address: 0x8005F918, Size: 64 bytes
// NON_MATCHING - Same issues as getPersonX (mtctr vs mtlr, prologue order)
// ============================================================================
float SAnimator2::getPersonY() {
    char* person = (char*)m_pPerson;
    char** vtbl = *(char***)person;
    char* inner = *(char**)(vtbl + 1);
    short offset = *(short*)(inner + 0x340);
    void* (*fn)(void*) = (void*(*)(void*)) *(int*)(inner + 0x344);
    char* posResult = (char*)fn((char*)vtbl + offset);
    return *(float*)(posResult + 0x00);
}

// ============================================================================
// SAnimator2::IsFollowing(void)
// Address: 0x8005ED9C, Size: 24 bytes
// NON_MATCHING - GCC uses branchless addic/subfe, SN uses cmpwi/bnelr/li
// ============================================================================
int SAnimator2::IsFollowing() {
    if (m_followState != 0) {
        return 1;
    }
    return 0;
}

// ============================================================================
// SAnimator2::IsInterruptable(void)
// Address: 0x8005EDB4, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::IsInterruptable() {
    return 1;
}

// ============================================================================
// SAnimator2::ResetCensorship(void)
// Address: 0x8005F4E0, Size: 4 bytes
// MATCHING
// ============================================================================
void SAnimator2::ResetCensorship() {
}

// ============================================================================
// SAnimator2::SetPixelated(int)
// Address: 0x8005F4E4, Size: 4 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetPixelated(int pixelated) {
}

// ============================================================================
// SAnimator2::convertAnimationFormatToEngineFormat(EVec3 &, EVec3 &)
// Address: 0x800655A4, Size: 48 bytes
// NON_MATCHING - GCC uses f0/f12 instead of f13/f11, different load/store
//   scheduling (loads kAnimScaleZ before first multiply vs after)
// ============================================================================
void SAnimator2::convertAnimationFormatToEngineFormat(EVec3& inPos, EVec3& outPos) {
    outPos.x = inPos.y * kAnimScale;
    outPos.z = kAnimScaleZ;
    outPos.y = inPos.x * kAnimScale;
}

// ============================================================================
// SAnimator2::GetBonePosAndDirForParticle(unsigned int, EMat4 &)
// Address: 0x800653F8, Size: 40 bytes
// NON_MATCHING - GCC tail-calls CalcNodeOrient (b), SN uses stack frame
//   (stwu+mflr+stw+bl+lwz+mtlr+addi+blr)
// ============================================================================
void SAnimator2::GetBonePosAndDirForParticle(u32 boneIdx, EMat4& outMat) {
    m_pSim->m_animController.CalcNodeOrient(boneIdx, outMat);
}

// ============================================================================
// SAnimator2::StartParticleEffectFromEdithPrimitive(unsigned int, unsigned int)
// Address: 0x8006559C, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::StartParticleEffectFromEdithPrimitive(u32 effectId, u32 boneId) {
    return 0;
}

// ============================================================================
// SAnimator2::footstepEvent(char *)
// Address: 0x80066470, Size: 32 bytes
// NON_MATCHING - GCC tail-calls playFootprint (b), SN uses stack frame
//   (stwu+mflr+stw+bl+lwz+mtlr+addi+blr)
// ============================================================================
void SAnimator2::footstepEvent(char* name) {
    playFootprint(name);
}

// ============================================================================
// SAnimator2::triggerCameraBlur(CameraBlurDataElement *)
// Address: 0x8006643C, Size: 52 bytes
// NON_MATCHING - GCC tail-calls SetMotionBlur (b), SN uses stack frame.
//   GCC also loads f3 before f2 (different FP register scheduling) and
//   accesses _pGfx via lis+lwz instead of SDA-relative (r13-based)
// ============================================================================
void SAnimator2::triggerCameraBlur(CameraBlurDataElement* data) {
    float* d = (float*)data;
    _pGfx->SetMotionBlur(d[0], d[1], d[2], d[3]);
}

// ============================================================================
// SAnimator2::lockCarryArmNodes(float *, int)
// Address: 0x80066F80, Size: 64 bytes
// NON_MATCHING - Same issues as lockCarryArmNodes(float*, EACTrack*):
//   GCC tail-calls and uses different temp register
// ============================================================================
void SAnimator2::lockCarryArmNodes(float* factors, int trackFlags) {
    m_pSim->m_animController.SetTrackBlendFactors((u32)trackFlags, factors);
}

// ============================================================================
// SAnimator2::AlignCensorToCamera(EVec3 &, EVec3 &, E3DWindow *)
// Address: 0x8006867C, Size: 4 bytes
// MATCHING
// ============================================================================
void SAnimator2::AlignCensorToCamera(EVec3& a, EVec3& b, E3DWindow* wnd) {
}

// ============================================================================
// SAnimator2::SetIdleInitialized(bool)
// Address: 0x800689F4, Size: 8 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetIdleInitialized(bool init) {
    m_idleInitialized = (int)init;
}

// ============================================================================
// SAnimator2::GetAwareOfObject(void)
// Address: 0x80068A40, Size: 8 bytes
// MATCHING
// ============================================================================
cXObject* SAnimator2::GetAwareOfObject() {
    return m_pAwareOfObject;
}

// ============================================================================
// SAnimator2::SetAwareOfObject(cXObject *)
// Address: 0x80068A48, Size: 36 bytes
// NON_MATCHING - GCC tail-calls (addi+b), SN uses stack frame
//   (stwu+mflr+stw+addi+bl+lwz+mtlr+addi+blr)
// ============================================================================
void SAnimator2::SetAwareOfObject(cXObject* obj) {
    m_awarenessMgr.SetAwareOfObject(obj);
}

// ============================================================================
// SAnimator2::SetAwareOfObjectKilled(cXObject *)
// Address: 0x80068A6C, Size: 36 bytes
// NON_MATCHING - GCC tail-calls (addi+b), SN uses stack frame
// ============================================================================
void SAnimator2::SetAwareOfObjectKilled(cXObject* obj) {
    m_awarenessMgr.SetAwareOfObjectKilled(obj);
}

// ============================================================================
// SAnimator2::ClearAwareOfObject(cXObject *)
// Address: 0x80068A90, Size: 36 bytes
// NON_MATCHING - GCC tail-calls (addi+b), SN uses stack frame
// ============================================================================
void SAnimator2::ClearAwareOfObject(cXObject* obj) {
    m_awarenessMgr.ClearAwareOfObject(obj);
}

// ============================================================================
// SAnimator2::SetPauseMultiplier(float)
// Address: 0x80069024, Size: 20 bytes
// NON_MATCHING - GCC stores f1 directly to both fields (12 bytes),
//   SN copies f1 to f0 first with fmr then stores f0 (20 bytes)
// ============================================================================
void SAnimator2::SetPauseMultiplier(float mult) {
    m_savedPauseMultiplier = mult;
    m_pauseMultiplier = mult;
}

// ============================================================================
// SAnimator2::GetPos(void)
// Address: 0x800690C8, Size: 8 bytes
// MATCHING
// ============================================================================
EVec3* SAnimator2::GetPos() {
    return &m_pos;
}

// ============================================================================
// SAnimator2::GetRealDir(void)
// Address: 0x800690C0, Size: 8 bytes
// MATCHING
// ============================================================================
float SAnimator2::GetRealDir() {
    return m_animDirection;
}

// ============================================================================
// SAnimator2::operator delete(void *)
// Address: 0x8006908C, Size: 52 bytes
// NON_MATCHING - GCC uses stw r31/lwz r31 instead of stmw r30/lmw r30,
//   uses r31 vs r30, and tail-calls EAHeap::Free instead of bl+blr
// ============================================================================
void SAnimator2::operator delete(void* ptr) {
    MainHeap();
    EAHeap::Free(ptr);
}

// ============================================================================
// SAnimator2::GetTimeMultiplier(void)
// Address: 0x800690D0, Size: 8 bytes
// MATCHING
// ============================================================================
float SAnimator2::GetTimeMultiplier() {
    return m_timeMultiplier;
}

// ============================================================================
// SAnimator2::GetPerson(void)
// Address: 0x800690D8, Size: 8 bytes
// MATCHING
// ============================================================================
cXPerson* SAnimator2::GetPerson() {
    return m_pPerson;
}

// ============================================================================
// SAnimator2::GetSim(void)
// Address: 0x800690E0, Size: 8 bytes
// MATCHING
// ============================================================================
ESim* SAnimator2::GetSim() {
    return m_pSim;
}

// ============================================================================
// SAnimator2::GetAnimState(void)
// Address: 0x800690E8, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::GetAnimState() {
    return m_animState;
}

// ============================================================================
// SAnimator2::GetFollowMode(void)
// Address: 0x800690F0, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::GetFollowMode() {
    return m_followMode;
}

// ============================================================================
// SAnimator2::GetPortalMode(void)
// Address: 0x800690F8, Size: 12 bytes
// MATCHING
// ============================================================================
int SAnimator2::GetPortalMode() {
    return (int)m_portalMode;
}

// ============================================================================
// SAnimator2::SetDesiredAnimState(SAnimator2::eAnimState)
// Address: 0x80069104, Size: 8 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetDesiredAnimState(eAnimState state) {
    m_desiredAnimState = (int)state;
}

// ============================================================================
// SAnimator2::SetCameraZoomRatio(float)
// Address: 0x8006910C, Size: 8 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetCameraZoomRatio(float ratio) {
    m_cameraZoomRatio = ratio;
}

// ============================================================================
// SAnimator2::GetPlayerControl(void)
// Address: 0x80069114, Size: 24 bytes
// NON_MATCHING - GCC uses clrlwi (3 instrs), SN uses andi.+beqlr+li (6 instrs)
// ============================================================================
bool SAnimator2::GetPlayerControl() {
    if (m_flags & 0x0001) {
        return true;
    }
    return false;
}

// ============================================================================
// SAnimator2::setAnimationDirectionToPersonDirection(void)
// Address: 0x8006912C, Size: 48 bytes
// NON_MATCHING - GCC uses stw r31 instead of stmw r30, r31 instead of r30,
//   and reorders stfs/lwz in epilogue
// ============================================================================
void SAnimator2::setAnimationDirectionToPersonDirection() {
    m_animDirection = getPersonDirection();
}

// ============================================================================
// SAnimator2::GetHeadOrient(void)
// Address: 0x8006915C, Size: 8 bytes
// MATCHING
// ============================================================================
EHeadOrient* SAnimator2::GetHeadOrient() {
    return &m_headOrient;
}

// ============================================================================
// SAnimator2::GetNormalSimDescription(void) const
// Address: 0x80069164, Size: 8 bytes
// MATCHING
// ============================================================================
CasSimDescriptionS2C* SAnimator2::GetNormalSimDescription() const {
    return m_pNormalSimDescription;
}

// ============================================================================
// SAnimator2::SetNormalSimDescription(CasSimDescriptionS2C *)
// Address: 0x8006916C, Size: 8 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetNormalSimDescription(CasSimDescriptionS2C* desc) {
    m_pNormalSimDescription = desc;
}

// ============================================================================
// SAnimator2::IsStalled(void)
// Address: 0x80069174, Size: 24 bytes
// NON_MATCHING - GCC uses lis+lwz for static access (can't use r13/SDA),
//   and branchless addic/subfe instead of cmpwi/bnelr/li
// ============================================================================
bool SAnimator2::IsStalled() {
    if (m_pendingCount != 0) {
        return true;
    }
    return false;
}

// ============================================================================
// SAnimator2::GetPauseMultiplier(void)
// Address: 0x8006918C, Size: 8 bytes
// MATCHING
// ============================================================================
float SAnimator2::GetPauseMultiplier() {
    return m_pauseMultiplier;
}

// ============================================================================
// SAnimator2::SetBoneIndex(int, int)
// Address: 0x80069194, Size: 16 bytes
// NON_MATCHING - GCC uses add+stw, SN uses addi+stwx
// ============================================================================
void SAnimator2::SetBoneIndex(int slot, int index) {
    m_boneIndices[slot] = index;
}

// ============================================================================
// SAnimator2::SetRightHandBoneIndex(int)
// Address: 0x800691A4, Size: 8 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetRightHandBoneIndex(int index) {
    m_boneIndices[0] = index;
}

// ============================================================================
// SAnimator2::SetHeadBoneIndex(int)
// Address: 0x800691AC, Size: 8 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetHeadBoneIndex(int index) {
    m_boneIndices[1] = index;
}

// ============================================================================
// SAnimator2::SetPelvisBoneIndex(int)
// Address: 0x800691B4, Size: 8 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetPelvisBoneIndex(int index) {
    m_boneIndices[2] = index;
}

// ============================================================================
// SAnimator2::SetTorsoBoneIndex(int)
// Address: 0x800691BC, Size: 8 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetTorsoBoneIndex(int index) {
    m_boneIndices[3] = index;
}

// ============================================================================
// SAnimator2::GetBoneIndex(int)
// Address: 0x800691C4, Size: 16 bytes
// NON_MATCHING - GCC uses add+lwz, SN uses addi+lwzx
// ============================================================================
int SAnimator2::GetBoneIndex(int slot) {
    return m_boneIndices[slot];
}

// ============================================================================
// SAnimator2::GetRightHandBoneIndex(void)
// Address: 0x800691D4, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::GetRightHandBoneIndex() {
    return m_boneIndices[0];
}

// ============================================================================
// SAnimator2::GetHeadBoneIndex(void)
// Address: 0x800691DC, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::GetHeadBoneIndex() {
    return m_boneIndices[1];
}

// ============================================================================
// SAnimator2::GetPelvisBoneIndex(void)
// Address: 0x800691E4, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::GetPelvisBoneIndex() {
    return m_boneIndices[2];
}

// ============================================================================
// SAnimator2::GetTorsoBoneIndex(void)
// Address: 0x800691EC, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::GetTorsoBoneIndex() {
    return m_boneIndices[3];
}

// ============================================================================
// SAnimator2::IsRouting(void)
// Address: 0x800691F4, Size: 20 bytes
// NON_MATCHING - GCC uses addic/subfe branchless idiom,
//   SN uses subfic/adde for the (followState != 1) check
// ============================================================================
bool SAnimator2::IsRouting() {
    return m_followState != 1;
}

// ============================================================================
// SAnimator2::IsDirectControlEnabled(void)
// Address: 0x80069208, Size: 24 bytes
// NON_MATCHING - GCC emits subfe+addi+clrlwi (7 instrs),
//   SN emits subfic+li+adde (6 instrs) for unsigned range check
// ============================================================================
bool SAnimator2::IsDirectControlEnabled() {
    int state = m_animState;
    return (unsigned int)(state - 9) <= 5;
}

// ============================================================================
// SAnimator2::GetLastCostume(void)
// Address: 0x80069220, Size: 8 bytes
// MATCHING
// ============================================================================
int SAnimator2::GetLastCostume() {
    return m_lastCostume;
}

// ============================================================================
// SAnimator2::SetLastCostume(int)
// Address: 0x80069228, Size: 8 bytes
// MATCHING
// ============================================================================
void SAnimator2::SetLastCostume(int costume) {
    m_lastCostume = costume;
}

// ============================================================================
// SAnimator2::SetSkillName(AnimRef *)
// Address: 0x800693B8, Size: 40 bytes
// NON_MATCHING - GCC reorders stores (stw r4 before oris, etc.)
//   and uses different registers (r10 vs r11, r9 vs r0)
// ============================================================================
void SAnimator2::SetSkillName(AnimRef* ref) {
    m_flags |= 0x00010000;
    m_skillTrackIndex = 0;
    m_blendTime = 0.0f;
    m_currentAnimRef = ref;
}

// ============================================================================
// SAnimator2::setFollowMiddle(void)
// Address: 0x800698E4, Size: 60 bytes
// NON_MATCHING - GCC uses two rlwinm instructions for bit clearing,
//   SN uses li+and. GCC also reorders stores and uses different registers.
//   Tail-calls setMovementVelocityFromAnimation (b) instead of bl+blr.
// ============================================================================
void SAnimator2::setFollowMiddle() {
    m_followMode = FOLLOW_MIDDLE;
    m_flags &= ~0x005E;
    setMovementVelocityFromAnimation();
}

// ============================================================================
// SAnimator::~SAnimator(void)
// Address: 0x803A05A4, Size: 52 bytes
// NOT COMPILED - This is the SAnimator base class destructor, located at
//   a very different address in the .text section (0x803A05A4 vs the main
//   sanimator2.obj code at 0x8005BD68-0x8006C8C0). It appears in the map
//   file under sanimator2.obj but is likely placed by the linker near
//   other vtable-related code. Sets vtable to SAnimator's vtable, then
//   conditionally calls operator delete.
//   Omitted from this compilation unit to avoid linker conflicts.
// ============================================================================
