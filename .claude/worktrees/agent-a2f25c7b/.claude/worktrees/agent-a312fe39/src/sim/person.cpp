// person.cpp - Decompiled small functions from person.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\person.obj
//
// 83 small functions (<=64 bytes) decompiled from person.obj
//
// Matching status (devkitPPC GCC vs original SN Systems compiler):
//   MATCHING:     48 functions - identical instruction output
//   NON_MATCHING: 35 functions - correct logic, different codegen
//
// Common NON_MATCHING causes with GCC vs SN:
//   - GCC uses branchless idioms (addic/subfe) where SN uses branches
//   - GCC uses different CR fields (cr0 vs cr7) for comparisons
//   - GCC uses different magic constants for integer division
//   - GCC tail-calls (bctr) where SN does call+return (blrl)
//   - GCC reorders prologue/epilogue instructions
//   - GCC unrolls small loops
//   - GCC uses different addressing modes (add+disp vs lfsx)

#include "sim/person.h"
#include "types.h"

// External global: autonomy constants client (SDA-relative at r13 - 24120)
extern AutonomyConstantsClient sTheAutonomyClient;

// External float constant for IsSleeping comparison
extern float sSleepThreshold; // at 0x803ECE28 in .sdata2

// ============================================================================
// GetAutonomyConstantsClient
// Address: 0x8011A9E0, Size: 8 bytes
// MATCHING
// ============================================================================
AutonomyConstantsClient* GetAutonomyConstantsClient() {
    return &sTheAutonomyClient;
}

// ============================================================================
// cXPersonImpl::ReconType
// Address: 0x8012503C, Size: 12 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::ReconType() {
    return 0x50455253; // 'PERS'
}

// ============================================================================
// cXPersonImpl::GetMotive
// Address: 0x801253A4, Size: 16 bytes
// NON_MATCHING - GCC uses add+lfs, SN uses addi+lfsx
// ============================================================================
float cXPersonImpl::GetMotive(int index) {
    return m_motives[index];
}

// ============================================================================
// cXPersonImpl::GetMotiveRef
// Address: 0x801253B4, Size: 16 bytes
// NON_MATCHING - GCC adds offset/4 before shift, SN shifts before adding offset
// ============================================================================
float* cXPersonImpl::GetMotiveRef(int index) {
    return &m_motives[index];
}

// ============================================================================
// cXPersonImpl::GetOldMotiveRef
// Address: 0x801253C4, Size: 16 bytes
// NON_MATCHING - same issue as GetMotiveRef
// ============================================================================
float* cXPersonImpl::GetOldMotiveRef(int index) {
    return &m_oldMotives[index];
}

// ============================================================================
// cXPersonImpl::SetMotive
// Address: 0x801253D4, Size: 16 bytes
// NON_MATCHING - GCC uses add+stfs, SN uses addi+stfsx
// ============================================================================
void cXPersonImpl::SetMotive(int index, float value) {
    m_motives[index] = value;
}

// ============================================================================
// cXPersonImpl::IsIdle
// Address: 0x80125AD0, Size: 12 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsIdle() {
    return ((int)m_currentAction) ^ 1;
}

// ============================================================================
// cXPersonImpl::DebugDumpHappyScape
// Address: 0x801264C4, Size: 4 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::DebugDumpHappyScape() {
}

// ============================================================================
// IsPermittedToRunCheckTreeForAds
// Address: 0x801270E0, Size: 52 bytes
// NON_MATCHING - GCC uses xoris+cmpwi for GUID compare, SN uses lis+ori+cmpw
//                GCC optimizes two adType compares into branchless rlwinm+xori
// ============================================================================
int IsPermittedToRunCheckTreeForAds(int guid, int adType) {
    if (guid == (int)0xC867A344) {
        if (adType == 2) {
            return 1;
        }
        if (adType == 10) {
            return 1;
        }
    }
    return 0;
}

// ============================================================================
// operator<(ScoredInteraction &, ScoredInteraction &)
// Address: 0x8012811C, Size: 24 bytes
// NON_MATCHING - GCC uses cr0, SN uses cr7; different register allocation
// ============================================================================
bool operator<(ScoredInteraction& a, ScoredInteraction& b) {
    return a.m_score < b.m_score;
}

// ============================================================================
// cXPersonImpl::IsSelected
// Address: 0x8012953C, Size: 16 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsSelected() {
    int* base = (int*)m_vtable;
    int flags = *(int*)((char*)base + 0x84);
    return (flags >> 1) & 1;
}

// ============================================================================
// cXPersonImpl::IsSleeping
// Address: 0x8012B1B8, Size: 28 bytes
// NON_MATCHING - GCC uses cr0 and rlwinm bit 2, SN uses cr7 and rlwinm bit 3
// ============================================================================
int cXPersonImpl::IsSleeping() {
    return m_motives[11] > sSleepThreshold;
}

// ============================================================================
// cXPersonImpl::InvalidateRoutes
// Address: 0x8012B5A0, Size: 52 bytes
// NON_MATCHING - GCC unrolls the loop with Duff's device optimization
// Original SN is a simple do-while with beq loop
// ============================================================================
void cXPersonImpl::InvalidateRoutes() {
    XRoute* begin = m_routeStackBegin;
    XRoute* end = m_routeStackEnd;
    if (begin == end) return;
    XRoute* cur = begin;
    do {
        cur->m_valid = 0;
        cur = (XRoute*)((char*)cur + 0xA4);
    } while (cur != end);
}

// ============================================================================
// cXPersonImpl::StartRecording
// Address: 0x8012B5D4, Size: 4 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::StartRecording(int a, int b) {
}

// ============================================================================
// cXPersonImpl::StopRecording
// Address: 0x8012B5D8, Size: 4 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::StopRecording() {
}

// ============================================================================
// cXPersonImpl::ClearRecording
// Address: 0x8012B5DC, Size: 4 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::ClearRecording() {
}

// ============================================================================
// cXPersonImpl::TickRecording
// Address: 0x8012B5E0, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::TickRecording() {
    return 0;
}

// ============================================================================
// cXPersonImpl::LogEvent
// Address: 0x8012B5E8, Size: 4 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::LogEvent(char* a, char* b, char* c) {
}

// ============================================================================
// cXPersonImpl::Track
// Address: 0x8012B5EC, Size: 4 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::Track() {
}

// ============================================================================
// cXPersonImpl::GetJobSuitTex
// Address: 0x8012B5F0, Size: 4 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::GetJobSuitTex(StringBuffer& a, StringBuffer& b, StringBuffer& c) {
}

// ============================================================================
// cXPersonImpl::SetFirstPlayerInSocialMode
// Address: 0x8012B82C, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetFirstPlayerInSocialMode(bool mode) {
    m_firstPlayerInSocialMode = (int)mode;
}

// ============================================================================
// cXPersonImpl::SetWaitingForSocialMode
// Address: 0x8012B8C4, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetWaitingForSocialMode(bool mode) {
    m_waitingForSocialMode = (int)mode;
}

// ============================================================================
// cXPersonImpl::CastToPersonImpl
// Address: 0x8012C6DC, Size: 4 bytes
// MATCHING
// ============================================================================
cXPersonImpl* cXPersonImpl::CastToPersonImpl() {
    return this;
}

// ============================================================================
// cXPersonImpl::GetPersonImplementation
// Address: 0x8012C6E0, Size: 4 bytes
// MATCHING
// ============================================================================
cXPersonImpl* cXPersonImpl::GetPersonImplementation() {
    return this;
}

// ============================================================================
// cXPerson::CastToPerson
// Address: 0x8012C694, Size: 4 bytes
// MATCHING
// ============================================================================
cXPerson* cXPerson::CastToPerson() {
    return this;
}

// ============================================================================
// cXPersonImpl::GetPersonData
// Address: 0x8012C758, Size: 16 bytes
// NON_MATCHING - GCC uses add+lha(8), SN uses addi(8)+lhax
// ============================================================================
short cXPersonImpl::GetPersonData(int index) const {
    return m_personData[index];
}

// ============================================================================
// cXPersonImpl::SetPersonData
// Address: 0x8012C768, Size: 16 bytes
// NON_MATCHING - GCC uses add+sth(8), SN uses addi(8)+sthx
// ============================================================================
void cXPersonImpl::SetPersonData(int index, short value) {
    m_personData[index] = value;
}

// ============================================================================
// cXPersonImpl::GetPersonDataArray
// Address: 0x8012C778, Size: 8 bytes
// MATCHING
// ============================================================================
short* cXPersonImpl::GetPersonDataArray() {
    return m_personData;
}

// ============================================================================
// cXPersonImpl::GetIdleState
// Address: 0x8012C780, Size: 8 bytes
// MATCHING
// ============================================================================
short cXPersonImpl::GetIdleState() {
    return m_personData[0];
}

// ============================================================================
// cXPersonImpl::GetDestList
// Address: 0x8012C7E4, Size: 8 bytes
// MATCHING
// ============================================================================
void* cXPersonImpl::GetDestList() {
    return m_destList;
}

// ============================================================================
// cXPersonImpl::GetSAnimator
// Address: 0x8012C7EC, Size: 8 bytes
// MATCHING
// ============================================================================
void* cXPersonImpl::GetSAnimator() const {
    return m_pSAnimator;
}

// ============================================================================
// cXPersonImpl::GetCurrentRoom
// Address: 0x8012C7F4, Size: 8 bytes
// MATCHING
// ============================================================================
u16 cXPersonImpl::GetCurrentRoom() const {
    return m_currentRoom;
}

// ============================================================================
// cXPersonImpl::SetIdleLoopCount
// Address: 0x8012C7DC, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetIdleLoopCount(short count) {
    m_idleLoopCount = count;
}

// ============================================================================
// cXPersonImpl::GetSimDescription
// Address: 0x8012C8C0, Size: 16 bytes
// MATCHING
// ============================================================================
void* cXPersonImpl::GetSimDescription() {
    char* base = (char*)m_vtable;
    char* obj = *(char**)(base + 0x8C);
    return *(void**)(obj + 0x8C);
}

// ============================================================================
// cXPersonImpl::GetServiceNPC
// Address: 0x8012C8D0, Size: 16 bytes
// MATCHING
// ============================================================================
void* cXPersonImpl::GetServiceNPC() {
    char* base = (char*)m_vtable;
    char* obj = *(char**)(base + 0x8C);
    return *(void**)(obj + 0x90);
}

// ============================================================================
// cXPersonImpl::IsVisitor
// Address: 0x8012C8A8, Size: 24 bytes
// NON_MATCHING - GCC uses branchless addic/subfe, SN uses branches
// ============================================================================
int cXPersonImpl::IsVisitor() {
    if (m_visitorStatus != 0) {
        return 1;
    }
    return 0;
}

// ============================================================================
// cXPersonImpl::IsInvisible
// Address: 0x8012C8E0, Size: 12 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsInvisible() {
    return m_visibilityFlags & 1;
}

// ============================================================================
// cXPersonImpl::IsGreen
// Address: 0x8012C8EC, Size: 12 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsGreen() {
    return (m_visibilityFlags >> 1) & 1;
}

// ============================================================================
// cXPersonImpl::IsGhost
// Address: 0x8012C8F8, Size: 12 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsGhost() {
    return (m_visibilityFlags >> 2) & 1;
}

// ============================================================================
// cXPersonImpl::IsAlien
// Address: 0x8012C904, Size: 12 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsAlien() {
    return (m_visibilityFlags >> 3) & 1;
}

// ============================================================================
// cXPersonImpl::IsInMotiveFailure
// Address: 0x8012C910, Size: 12 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsInMotiveFailure() {
    return (m_visibilityFlags >> 4) & 1;
}

// ============================================================================
// cXPersonImpl::NeedsWantFearShuffle
// Address: 0x8012C91C, Size: 12 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::NeedsWantFearShuffle() {
    return (m_visibilityFlags >> 5) & 1;
}

// ============================================================================
// cXPersonImpl::SetInvisible
// Address: 0x8012C928, Size: 40 bytes
// NON_MATCHING - GCC merges both paths, SN has two separate branches with early ret
// ============================================================================
void cXPersonImpl::SetInvisible(bool invisible) {
    if (invisible) {
        m_visibilityFlags = m_visibilityFlags | 0x0001;
    } else {
        m_visibilityFlags = m_visibilityFlags & ~0x0001;
    }
}

// ============================================================================
// cXPersonImpl::SetIsAlien
// Address: 0x8012C950, Size: 40 bytes
// NON_MATCHING - GCC merges both paths, SN has two separate branches with early ret
// ============================================================================
void cXPersonImpl::SetIsAlien(bool alien) {
    if (alien) {
        m_visibilityFlags = m_visibilityFlags | 0x0008;
    } else {
        m_visibilityFlags = m_visibilityFlags & ~0x0008;
    }
}

// ============================================================================
// cXPersonImpl::GetVisibility
// Address: 0x8012C978, Size: 8 bytes
// MATCHING
// ============================================================================
short cXPersonImpl::GetVisibility() {
    return (short)m_visibilityFlags;
}

// ============================================================================
// cXPersonImpl::GetMotives
// Address: 0x8012C980, Size: 8 bytes
// MATCHING
// ============================================================================
float* cXPersonImpl::GetMotives() {
    return m_motives;
}

// ============================================================================
// cXPersonImpl::GetMotiveEffects
// Address: 0x8012C988, Size: 8 bytes
// MATCHING
// ============================================================================
void* cXPersonImpl::GetMotiveEffects() {
    return m_pMotiveEffects;
}

// ============================================================================
// cXPersonImpl::GetRecording
// Address: 0x8012C990, Size: 8 bytes
// MATCHING
// ============================================================================
void* cXPersonImpl::GetRecording() {
    return m_pRecording;
}

// ============================================================================
// cXPersonImpl::GetRecordDuration
// Address: 0x8012C998, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::GetRecordDuration() {
    return m_recordDuration;
}

// ============================================================================
// cXPersonImpl::SetRecordDuration
// Address: 0x8012C9A0, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetRecordDuration(int duration) {
    m_recordDuration = duration;
}

// ============================================================================
// cXPersonImpl::GetRecordMaxDuration
// Address: 0x8012C9A8, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::GetRecordMaxDuration() {
    return m_recordMaxDuration;
}

// ============================================================================
// cXPersonImpl::SetRecordMaxDuration
// Address: 0x8012C9B0, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetRecordMaxDuration(int duration) {
    m_recordMaxDuration = duration;
}

// ============================================================================
// cXPersonImpl::GetRecordStartTicks
// Address: 0x8012C9B8, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::GetRecordStartTicks() {
    return m_recordStartTicks;
}

// ============================================================================
// cXPersonImpl::GetRecordCurTicks
// Address: 0x8012C9C0, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::GetRecordCurTicks() {
    return m_recordCurTicks;
}

// ============================================================================
// cXPersonImpl::GetRecordTicksElapsed
// Address: 0x8012C9C8, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::GetRecordTicksElapsed() {
    return m_recordTicksElapsed;
}

// ============================================================================
// cXPersonImpl::GetRecordSkill
// Address: 0x8012C9D0, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::GetRecordSkill() {
    return m_recordSkill;
}

// ============================================================================
// cXPersonImpl::SetChangingOutfitMode
// Address: 0x8012C9F8, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetChangingOutfitMode(bool mode) {
    m_changingOutfitMode = (int)mode;
}

// ============================================================================
// cXPersonImpl::GetLastMotiveUpdateTick
// Address: 0x8012CA00, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::GetLastMotiveUpdateTick() {
    return m_lastMotiveUpdateTick;
}

// ============================================================================
// cXPersonImpl::SetLastMotiveUpdateTick
// Address: 0x8012CA08, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetLastMotiveUpdateTick(int tick) {
    m_lastMotiveUpdateTick = tick;
}

// ============================================================================
// cXPersonImpl::IgnoringObject
// Address: 0x8012CA10, Size: 8 bytes
// MATCHING
// ============================================================================
cXObject* cXPersonImpl::IgnoringObject() {
    return m_pIgnoringObject;
}

// ============================================================================
// cXPersonImpl::SetIgnoringObject
// Address: 0x8012CA18, Size: 8 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::SetIgnoringObject(cXObject* obj) {
    m_pIgnoringObject = obj;
}

// ============================================================================
// cXPersonImpl::ClearIgnoringObject
// Address: 0x8012CA20, Size: 12 bytes
// MATCHING
// ============================================================================
void cXPersonImpl::ClearIgnoringObject() {
    m_pIgnoringObject = (cXObject*)0;
}

// ============================================================================
// cXPersonImpl::IsInSocialMode
// Address: 0x8012CA2C, Size: 24 bytes
// NON_MATCHING - GCC uses branchless addic/subfe, SN uses branches
// ============================================================================
int cXPersonImpl::IsInSocialMode() {
    if (m_socialModeState != 0) {
        return 1;
    }
    return 0;
}

// ============================================================================
// cXPersonImpl::IsFirstPlayerInSocialMode
// Address: 0x8012CA4C, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsFirstPlayerInSocialMode() {
    return m_firstPlayerInSocialMode;
}

// ============================================================================
// cXPersonImpl::IsSecondPlayerInSocialMode
// Address: 0x8012CA44, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsSecondPlayerInSocialMode() {
    return m_secondPlayerInSocialMode;
}

// ============================================================================
// cXPersonImpl::IsWaitingForSocialMode
// Address: 0x8012CA54, Size: 8 bytes
// MATCHING
// ============================================================================
int cXPersonImpl::IsWaitingForSocialMode() {
    return m_waitingForSocialMode;
}

// ============================================================================
// cXPersonImpl::GetPendingAction
// Address: 0x8012C714, Size: 24 bytes
// NON_MATCHING - GCC uses branchless addic/subfe, SN uses branches
// ============================================================================
int cXPersonImpl::GetPendingAction() const {
    if (m_currentAction == 0) {
        return 0;
    }
    return 1;
}

// ============================================================================
// cXPerson::setPersonImpl
// Address: 0x8012C684, Size: 16 bytes
// MATCHING
// ============================================================================
void cXPerson::setPersonImpl(cXPersonImpl* impl) {
    int* base = *(int**)this;
    int* inner = *(int**)base;
    *(cXPersonImpl**)((char*)inner + 0x04) = impl;
}

// ============================================================================
// cXPersonImpl::GetRouteStackSize
// Address: 0x8012C9D8, Size: 32 bytes
// NON_MATCHING - GCC uses different magic constant (mulhw) for division by 164
// Original SN uses mullw with 0xC18F9C19 then srawi 2
// ============================================================================
int cXPersonImpl::GetRouteStackSize() {
    return ((char*)m_routeStackEnd - (char*)m_routeStackBegin) / (int)0xA4;
}

// ============================================================================
// cXPersonImpl::EORDrawStickFigure
// Address: 0x8011AD64, Size: 56 bytes
// NON_MATCHING - GCC uses bctr tail call, SN uses blrl with stack frame
// ============================================================================
void cXPersonImpl::EORDrawStickFigure(int arg) {
    void* sAnimator = m_pSAnimator;
    int* vtbl = *(int**)sAnimator;
    short offset = *(short*)((char*)vtbl + 0x18);
    void (*fn)(void*) = (void (*)(void*)) *(int*)((char*)vtbl + 0x1C);
    fn((char*)sAnimator + offset);
}

// ============================================================================
// cXPersonImpl::IsModelLoaded
// Address: 0x8012B754, Size: 48 bytes
// NON_MATCHING - GCC uses branchless addic/subfe for non-null check
// ============================================================================
int cXPersonImpl::IsModelLoaded() {
    void* p1 = m_pSubObject;
    void* p2 = *(void**)p1;
    void* p3 = *(void**)p2;
    void* p4 = *(void**)((char*)p3 + 0x14);
    if (p4 == 0) {
        return 0;
    }
    int val = *(int*)((char*)p4 + 0x638);
    if (val != 0) {
        return 1;
    }
    return 0;
}

// ============================================================================
// cXPersonImpl::GetCurrentRoute
// Address: 0x80123704, Size: 56 bytes
// NON_MATCHING - GCC uses different magic constant for division by 164
// ============================================================================
XRoute* cXPersonImpl::GetCurrentRoute() {
    char* begin = (char*)m_routeStackBegin;
    char* end = (char*)m_routeStackEnd;
    int count = (int)(end - begin) / (int)0xA4;
    if (count == 0) {
        return (XRoute*)0;
    }
    return (XRoute*)(begin + (count - 1) * 0xA4);
}

// ============================================================================
// cXPersonImpl::SetCurrentActionText
// Address: 0x8012B804, Size: 40 bytes
// NON_MATCHING - GCC tail-calls SetActionText, SN uses bl with stack frame
// ============================================================================
void cXPersonImpl::SetCurrentActionText(BString2& text) {
    m_actionQueue.SetActionText(text, 0);
}

// ============================================================================
// cXPersonImpl::CountActions
// Address: 0x8012C6E4, Size: 48 bytes
// NON_MATCHING - GCC uses addme for subtract, different register scheduling
// ============================================================================
int cXPersonImpl::CountActions(bool includeIdle) {
    int count = m_actionQueue.m_end - m_actionQueue.m_begin;
    if (includeIdle != 0) {
        return count;
    }
    if (m_currentAction == 0) {
        return count;
    }
    return count - 1;
}

// ============================================================================
// cXPersonImpl::GetCurrentInteractionNC
// Address: 0x8012C72C, Size: 44 bytes
// NON_MATCHING - GCC emits addi for action queue offset in different order
// ============================================================================
Interaction* cXPersonImpl::GetCurrentInteractionNC() {
    unsigned int idx = (unsigned int)m_actionQueue.m_begin;
    unsigned int slot = idx % 10;
    return (Interaction*)((char*)&m_actionQueue + slot * 68);
}

// ============================================================================
// ActionQueue::Enqueue
// Address: 0x8011A6E4, Size: 48 bytes
// NON_MATCHING - GCC doesn't save r3 to r9 before the call
// ============================================================================
void ActionQueue::Enqueue(Interaction& action) {
    Insert(action, (unsigned int)(m_end - m_begin));
}

// ============================================================================
// cXPersonImpl::IsRouting
// Address: 0x8012C878, Size: 48 bytes
// NON_MATCHING - GCC inlines GetCurrentRoute, SN calls it as a function
// ============================================================================
int cXPersonImpl::IsRouting() {
    XRoute* route = GetCurrentRoute();
    if (route != 0) {
        return 1;
    }
    return 0;
}

// ============================================================================
// cXPersonImpl::SetAwareOfObject
// Address: 0x8012CAA8, Size: 56 bytes
// NON_MATCHING - GCC uses bctr tail call, SN uses blrl with stack frame
// ============================================================================
void cXPersonImpl::SetAwareOfObject(cXObject* obj) {
    void* sAnimator = m_pSAnimator;
    int* vtbl = *(int**)sAnimator;
    short offset = *(short*)((char*)vtbl + 0x120);
    void (*fn)(void*, cXObject*) = (void (*)(void*, cXObject*)) *(int*)((char*)vtbl + 0x124);
    fn((char*)sAnimator + offset, obj);
}

// ============================================================================
// cXPersonImpl::SetAwareOfObjectKilled
// Address: 0x8012CAE0, Size: 56 bytes
// NON_MATCHING - GCC uses bctr tail call, SN uses blrl with stack frame
// ============================================================================
void cXPersonImpl::SetAwareOfObjectKilled(cXObject* obj) {
    void* sAnimator = m_pSAnimator;
    int* vtbl = *(int**)sAnimator;
    short offset = *(short*)((char*)vtbl + 0x128);
    void (*fn)(void*, cXObject*) = (void (*)(void*, cXObject*)) *(int*)((char*)vtbl + 0x12C);
    fn((char*)sAnimator + offset, obj);
}

// ============================================================================
// cXPersonImpl::ClearAwareOfObject
// Address: 0x8012CB18, Size: 56 bytes
// NON_MATCHING - GCC uses bctr tail call, SN uses blrl with stack frame
// ============================================================================
void cXPersonImpl::ClearAwareOfObject(cXObject* obj) {
    void* sAnimator = m_pSAnimator;
    int* vtbl = *(int**)sAnimator;
    short offset = *(short*)((char*)vtbl + 0x130);
    void (*fn)(void*, cXObject*) = (void (*)(void*, cXObject*)) *(int*)((char*)vtbl + 0x134);
    fn((char*)sAnimator + offset, obj);
}

// ============================================================================
// cXPersonImpl::IsFemale
// Address: 0x8012B528, Size: 60 bytes
// NON_MATCHING - GCC reorders prologue (mflr before stwu vs after)
// ============================================================================
int cXPersonImpl::IsFemale() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x200);
    void* thunkThis = (char*)subObj + offset;
    int (*fn)(void*) = (int (*)(void*)) *(int*)((char*)vtbl + 0x204);
    int isMale = fn(thunkThis);
    return isMale ^ 1;
}

// ============================================================================
// cXPersonImpl::IsAdult
// Address: 0x8012B564, Size: 60 bytes
// NON_MATCHING - GCC reorders prologue (mflr before stwu vs after)
// ============================================================================
int cXPersonImpl::IsAdult() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x150);
    void* thunkThis = (char*)subObj + offset;
    int (*fn)(void*) = (int (*)(void*)) *(int*)((char*)vtbl + 0x154);
    fn(thunkThis);
    return 1;
}

// ============================================================================
// cXPersonImpl::GetNeighborID
// Address: 0x8012C7FC, Size: 60 bytes
// NON_MATCHING - GCC uses bctr tail call, SN uses blrl with stack frame
// ============================================================================
short cXPersonImpl::GetNeighborID() const {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x138);
    void* thunkThis = (char*)subObj + offset;
    short (*fn)(void*, int) = (short (*)(void*, int)) *(int*)((char*)vtbl + 0x13C);
    return fn(thunkThis, 31);
}

// ============================================================================
// cXPersonImpl::SetNeighborID
// Address: 0x8012C838, Size: 64 bytes
// NON_MATCHING - GCC uses bctr tail call, SN uses blrl with stack frame
// ============================================================================
void cXPersonImpl::SetNeighborID(short id) {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x140);
    void* thunkThis = (char*)subObj + offset;
    void (*fn)(void*, int, short) = (void (*)(void*, int, short)) *(int*)((char*)vtbl + 0x144);
    fn(thunkThis, 31, id);
}

// ============================================================================
// _List_global<bool>::_Transfer
// Address: 0x803AB0B4, Size: 60 bytes
// NON_MATCHING - GCC reorders loads/stores slightly
// ============================================================================
template <>
void _List_global<bool>::_Transfer(_List_node_base* pos, _List_node_base* first, _List_node_base* last) {
    if (pos == last) return;

    last->m_prev->m_next = pos;
    first->m_prev->m_next = last;
    pos->m_prev->m_next = first;

    _List_node_base* tmp = pos->m_prev;
    pos->m_prev = last->m_prev;
    last->m_prev = first->m_prev;
    first->m_prev = tmp;
}
