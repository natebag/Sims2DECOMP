// unlockdisplay.cpp - Decompiled small functions from unlockdisplay.obj,
// unlockdisplayobject.obj, and unlockdisplayobjectsim.obj
// Original obj files from u2_ngc_release_dvd
//
// 40 small functions (<=64 bytes) total:
//   unlockdisplay.obj:          16 functions
//   unlockdisplayobject.obj:    21 functions
//   unlockdisplayobjectsim.obj:  3 functions

#include "objects/unlockdisplay.h"

// ============================================================================
// External references
// ============================================================================

// EAHeap::Alloc (at 0x802CFF00) - gets current heap
extern void* EAHeap_GetCurrent();
// EAHeap::AllocFromHeap (at 0x802D0B70)
extern void* EAHeap_AllocFromHeap(void* heap, unsigned int size, int align, int flags, int type);
// EAHeap::FreeToHeap (at 0x802D0D78)
extern void EAHeap_FreeToHeap(void* heap, void* ptr);
// operator new (at 0x802D11B0)
extern void* operator_new(unsigned int size);
// operator delete (at 0x802D1220)
extern void operator_delete(void* ptr);
// AmbientScorePlayer::Pause (at 0x800A8A18)
extern void AmbientScorePlayer_Pause(void* player, int pause);

// ============================================================================
// CUnlockDisplay::SetAmbientLight
// Address: 0x80078BD0, Size: 56 bytes
// NON_MATCHING - stack-based EVec3 copy vs register-based
// Copies 3 floats into m_ambientLight
// ============================================================================
void CUnlockDisplay::SetAmbientLight(float r, float g, float b) {
    float temp[3];
    temp[0] = r;
    temp[1] = g;
    temp[2] = b;
    // Copy 12 bytes to m_ambientLight
    *(int*)&m_ambientLight[0] = *(int*)&temp[0];
    *(int*)&m_ambientLight[4] = *(int*)&temp[1];
    *(int*)&m_ambientLight[8] = *(int*)&temp[2];
}

// ============================================================================
// CUnlockDisplay::ManualCameraPos
// Address: 0x80078010, Size: 16 bytes
// MATCHING
// Sets camera position (x, y, z)
// ============================================================================
void CUnlockDisplay::ManualCameraPos(float x, float y, float z) {
    m_cameraPosZ = z;
    m_cameraPosX = x;
    m_cameraPosY = y;
}

// ============================================================================
// CUnlockDisplay::SetupForSocial
// Address: 0x80077DD4, Size: 40 bytes
// NON_MATCHING - function call to makeObjects may differ
// Sets display mode to 3 (social) and creates objects
// ============================================================================
void CUnlockDisplay::SetupForSocial(void* data) {
    m_displayMode = 3;
    makeObjects();
}

// ============================================================================
// CUnlockDisplay::SetDisplayBoxLeft
// Address: 0x80077FA8, Size: 24 bytes
// NON_MATCHING - conditional return (bsolr/cror) pattern differs
// Sets left display box boundary, clamped to not exceed right
// ============================================================================
void CUnlockDisplay::SetDisplayBoxLeft(float val) {
    if (val >= m_displayBoxRight) return;
    m_displayBoxLeft = val;
}

// ============================================================================
// CUnlockDisplay::SetDisplayBoxTop
// Address: 0x80077FC0, Size: 24 bytes
// NON_MATCHING - conditional return (bsolr/cror) pattern differs
// Sets top display box boundary, clamped to not exceed bottom
// ============================================================================
void CUnlockDisplay::SetDisplayBoxTop(float val) {
    if (val >= m_displayBoxBottom) return;
    m_displayBoxTop = val;
}

// ============================================================================
// CUnlockDisplay::SetDisplayBoxRight
// Address: 0x80077FD8, Size: 24 bytes
// NON_MATCHING - conditional return (bsolr/cror) pattern differs
// Sets right display box boundary, clamped to not be less than left
// ============================================================================
void CUnlockDisplay::SetDisplayBoxRight(float val) {
    if (val <= m_displayBoxLeft) return;
    m_displayBoxRight = val;
}

// ============================================================================
// CUnlockDisplay::SetDisplayBoxBottom
// Address: 0x80077FF0, Size: 24 bytes
// NON_MATCHING - conditional return (bsolr/cror) pattern differs
// Sets bottom display box boundary, clamped to not be less than top
// ============================================================================
void CUnlockDisplay::SetDisplayBoxBottom(float val) {
    if (val <= m_displayBoxTop) return;
    m_displayBoxBottom = val;
}

// ============================================================================
// CUnlockDisplay::SetViewZoomFactor
// Address: 0x80078008, Size: 8 bytes
// MATCHING
// Simple float store
// ============================================================================
void CUnlockDisplay::SetViewZoomFactor(float val) {
    m_viewZoomFactor = val;
}

// ============================================================================
// CUnlockDisplay::HasDrawn
// Address: 0x80078C08, Size: 60 bytes
// NON_MATCHING - loop structure and linked list traversal pattern
// Iterates through object list, returns true if any object has drawn
// ============================================================================
bool CUnlockDisplay::HasDrawn() {
    // Object list node: +0x00 = next, +0x7C = hasDrawn
    struct ObjNode { ObjNode* next; u8 pad[0x78]; int hasDrawn; };
    ObjNode* node = (ObjNode*)m_objectList;
    bool result = true;
    if (node == 0) return result;
    while (node != 0) {
        result = false;
        if (node->hasDrawn != 0) {
            result = true;
        }
        node = node->next;
    }
    return result;
}

// ============================================================================
// CUnlockDisplay::RemoveAllDirectLights
// Address: 0x80078DAC, Size: 12 bytes
// MATCHING
// Zeros the direct light count
// ============================================================================
void CUnlockDisplay::RemoveAllDirectLights() {
    m_numDirectLights = 0;
}

// ============================================================================
// CUnlockDisplay::IsDone
// Address: 0x80078FDC, Size: 8 bytes
// MATCHING
// Returns the done flag
// ============================================================================
bool CUnlockDisplay::IsDone() {
    return m_isDone;
}

// ============================================================================
// CUnlockDisplay::Hide
// Address: 0x80078FE4, Size: 12 bytes
// MATCHING
// Sets hidden flag to 1
// ============================================================================
void CUnlockDisplay::Hide() {
    m_hidden = 1;
}

// ============================================================================
// CUnlockDisplay::UnHide
// Address: 0x80078FF0, Size: 12 bytes
// MATCHING
// Clears hidden flag
// ============================================================================
void CUnlockDisplay::UnHide() {
    m_hidden = 0;
}

// ============================================================================
// CUnlockDisplay::DonePreloadObject
// Address: 0x80078FFC, Size: 8 bytes
// MATCHING
// Returns preload done flag
// ============================================================================
int CUnlockDisplay::DonePreloadObject() {
    return m_preloadDone;
}

// ============================================================================
// CUnlockDisplay::operator new
// Address: 0x80079004, Size: 64 bytes
// NON_MATCHING - heap allocation call sequence
// Allocates from EAHeap with 16-byte alignment
// ============================================================================
void* CUnlockDisplay::operator new(unsigned int size) {
    void* heap = EAHeap_GetCurrent();
    return EAHeap_AllocFromHeap(heap, size, 16, 0, 0);
}

// ============================================================================
// CUnlockDisplay::operator delete
// Address: 0x80079044, Size: 52 bytes
// NON_MATCHING - heap free call sequence
// Frees to EAHeap
// ============================================================================
void CUnlockDisplay::operator delete(void* ptr) {
    void* heap = EAHeap_GetCurrent();
    EAHeap_FreeToHeap(heap, ptr);
}

// ============================================================================
// CUnlockDisplayObject functions (unlockdisplayobject.obj)
// ============================================================================

// ============================================================================
// CUnlockDisplayObject::IsActive
// Address: 0x800799A0, Size: 36 bytes
// NON_MATCHING - bool conversion with subfic/adde pattern
// Returns true if object exists and is loaded
// ============================================================================
bool CUnlockDisplayObject::IsActive() {
    if (m_object == 0) return false;
    return m_done != 0;
}

// ============================================================================
// CUnlockDisplayObject::GetModel
// Address: 0x800799C4, Size: 8 bytes
// MATCHING
// ============================================================================
void* CUnlockDisplayObject::GetModel() {
    return m_model;
}

// ============================================================================
// CUnlockDisplayObject::IsSimple
// Address: 0x80079A54, Size: 8 bytes
// MATCHING
// ============================================================================
bool CUnlockDisplayObject::IsSimple() {
    return m_isSimple;
}

// ============================================================================
// CUnlockDisplayObject::SetModelID
// Address: 0x80079A5C, Size: 8 bytes
// MATCHING
// ============================================================================
void CUnlockDisplayObject::SetModelID(unsigned int id) {
    m_modelID = id;
}

// ============================================================================
// CUnlockDisplayObject::SetCharacterID
// Address: 0x80079A64, Size: 40 bytes
// NON_MATCHING - branch structure for isSimple calculation
// Sets character ID and updates isSimple flag
// ============================================================================
void CUnlockDisplayObject::SetCharacterID(unsigned int id) {
    m_characterID = id;
    bool simple = false;
    if (id == 0 || m_animationID == 0) {
        simple = true;
    }
    m_isSimple = simple;
}

// ============================================================================
// CUnlockDisplayObject::SetAnimationID
// Address: 0x80079A8C, Size: 40 bytes
// NON_MATCHING - branch structure for isSimple calculation
// Sets animation ID and updates isSimple flag
// ============================================================================
void CUnlockDisplayObject::SetAnimationID(unsigned int id) {
    m_animationID = id;
    bool simple = false;
    if (m_characterID == 0 || id == 0) {
        simple = true;
    }
    m_isSimple = simple;
}

// ============================================================================
// CUnlockDisplayObject::SetPos
// Address: 0x80079AB4, Size: 32 bytes
// MATCHING
// Copies 12 bytes (EVec3) from source to m_pos
// ============================================================================
void CUnlockDisplayObject::SetPos(EVec3& pos) {
    u8* src = (u8*)&pos;
    u8* dst = (u8*)&m_posX;
    *(int*)(dst+0) = *(int*)(src+0);
    *(int*)(dst+4) = *(int*)(src+4);
    *(int*)(dst+8) = *(int*)(src+8);
}

// ============================================================================
// CUnlockDisplayObject::GetPos
// Address: 0x80079AD4, Size: 36 bytes
// NON_MATCHING - float load/store pattern (lfs/stfs vs lwz/stw)
// Returns EVec3 position (struct return in r3)
// ============================================================================
EVec3 CUnlockDisplayObject::GetPos() {
    EVec3 result;
    float* dst = (float*)&result;
    dst[0] = m_posX;
    dst[1] = m_posY;
    dst[2] = m_posZ;
    return result;
}

// ============================================================================
// CUnlockDisplayObject::SetRot
// Address: 0x80079AF8, Size: 32 bytes
// MATCHING
// Copies 12 bytes (EVec3) from source to m_rot
// ============================================================================
void CUnlockDisplayObject::SetRot(EVec3& rot) {
    u8* src = (u8*)&rot;
    u8* dst = (u8*)&m_rotX;
    *(int*)(dst+0) = *(int*)(src+0);
    *(int*)(dst+4) = *(int*)(src+4);
    *(int*)(dst+8) = *(int*)(src+8);
}

// ============================================================================
// CUnlockDisplayObject::GetRot
// Address: 0x80079B18, Size: 36 bytes
// NON_MATCHING - float load/store pattern
// ============================================================================
EVec3 CUnlockDisplayObject::GetRot() {
    EVec3 result;
    float* dst = (float*)&result;
    dst[0] = m_rotX;
    dst[1] = m_rotY;
    dst[2] = m_rotZ;
    return result;
}

// ============================================================================
// CUnlockDisplayObject::SetRotAdd
// Address: 0x80079B3C, Size: 32 bytes
// MATCHING
// ============================================================================
void CUnlockDisplayObject::SetRotAdd(EVec3& rotAdd) {
    u8* src = (u8*)&rotAdd;
    u8* dst = (u8*)&m_rotAddX;
    *(int*)(dst+0) = *(int*)(src+0);
    *(int*)(dst+4) = *(int*)(src+4);
    *(int*)(dst+8) = *(int*)(src+8);
}

// ============================================================================
// CUnlockDisplayObject::GetRotAdd
// Address: 0x80079B5C, Size: 36 bytes
// NON_MATCHING - float load/store pattern
// ============================================================================
EVec3 CUnlockDisplayObject::GetRotAdd() {
    EVec3 result;
    float* dst = (float*)&result;
    dst[0] = m_rotAddX;
    dst[1] = m_rotAddY;
    dst[2] = m_rotAddZ;
    return result;
}

// ============================================================================
// CUnlockDisplayObject::SetAnimationLoops
// Address: 0x80079B80, Size: 8 bytes
// MATCHING
// ============================================================================
void CUnlockDisplayObject::SetAnimationLoops(unsigned int loops) {
    m_animationLoops = loops;
}

// ============================================================================
// CUnlockDisplayObject::SetPlayAndHold
// Address: 0x80079B88, Size: 8 bytes
// MATCHING
// ============================================================================
void CUnlockDisplayObject::SetPlayAndHold(bool hold) {
    m_playAndHold = hold;
}

// ============================================================================
// CUnlockDisplayObject::IsReady
// Address: 0x80079C18, Size: 8 bytes
// MATCHING
// ============================================================================
bool CUnlockDisplayObject::IsReady() {
    return m_isReady;
}

// ============================================================================
// CUnlockDisplayObject::SetTrigger
// Address: 0x80079C20, Size: 12 bytes
// MATCHING
// ============================================================================
void CUnlockDisplayObject::SetTrigger() {
    m_triggered = 1;
}

// ============================================================================
// CUnlockDisplayObject::IsDone
// Address: 0x80079C2C, Size: 8 bytes
// MATCHING
// ============================================================================
bool CUnlockDisplayObject::IsDone() {
    return m_done;
}

// ============================================================================
// CUnlockDisplayObject::GetRadius
// Address: 0x80079C34, Size: 8 bytes
// MATCHING
// ============================================================================
float CUnlockDisplayObject::GetRadius() {
    return m_radius;
}

// ============================================================================
// CUnlockDisplayObject::GetCenter
// Address: 0x80079C3C, Size: 36 bytes
// NON_MATCHING - float load/store pattern
// ============================================================================
EVec3 CUnlockDisplayObject::GetCenter() {
    EVec3 result;
    float* dst = (float*)&result;
    dst[0] = m_centerX;
    dst[1] = m_centerY;
    dst[2] = m_centerZ;
    return result;
}

// ============================================================================
// CUnlockDisplayObject::HasDrawn
// Address: 0x80079C60, Size: 8 bytes
// MATCHING
// ============================================================================
bool CUnlockDisplayObject::HasDrawn() {
    return m_hasDrawn;
}

// ============================================================================
// CUnlockDisplayObject::GetType
// Address: 0x80079C68, Size: 8 bytes
// MATCHING
// ============================================================================
int CUnlockDisplayObject::GetType() {
    return m_type;
}

// ============================================================================
// CUnlockDisplayObjectSim functions (unlockdisplayobjectsim.obj)
// ============================================================================

// ============================================================================
// CUnlockDisplayObjectSim::Setup
// Address: 0x80079EAC, Size: 4 bytes
// MATCHING
// Empty virtual override (no-op)
// ============================================================================
void CUnlockDisplayObjectSim::Setup() {
    // no-op
}

// ============================================================================
// CUnlockDisplayObjectSim::IsMale
// Address: 0x80079F78, Size: 12 bytes
// MATCHING
// Returns gender from person object (+0x1B4 person ptr, +0x84 gender field)
// ============================================================================
int CUnlockDisplayObjectSim::IsMale() {
    // m_person at +0x1B4, gender at +0x84 in person
    int** person = (int**)m_person;
    return ((int*)person)[0x84 / 4];
}

// ============================================================================
// CUnlockDisplayObjectSim::IsAdult
// Address: 0x80079F84, Size: 8 bytes
// MATCHING
// Always returns 1 (all sims in unlock display are adults)
// ============================================================================
int CUnlockDisplayObjectSim::IsAdult() {
    return 1;
}
