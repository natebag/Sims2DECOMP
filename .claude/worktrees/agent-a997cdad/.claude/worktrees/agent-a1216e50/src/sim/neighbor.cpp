// neighbor.cpp - Decompiled small functions from neighbor.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\neighbor.obj
//
// 20 small functions (<=64 bytes) decompiled from neighbor.obj
//
// Matching status (devkitPPC GCC vs original SN Systems compiler):
//   MATCHING:     8 functions
//   NON_MATCHING: 12 functions
//
// Common NON_MATCHING causes:
//   - GCC uses bctr for tail calls, SN uses blrl with stack frame
//   - GCC rearranges prologue (saves to stack slot vs using r31)
//   - GCC uses different registers (r9/r10 vs r0)
//   - SDA-relative addressing for globals
//   - 'this' unused in original static-like member functions

#include "sim/neighbor.h"
#include "types.h"

// ============================================================================
// External functions
// ============================================================================
extern void Interests_Init(void* interests);               // at 0x800c88c0
extern void Neighbor_RecalculateRelationshipCounts(Neighbor* n); // at 0x800c9ba8

// Persistent data fields table (at 0x8048627c)
extern PersistentDataField sPersistentFields[];

// Aspiration score constants in .sdata2
extern float sAspScoreAdd;
extern float sAspScoreDiv;
extern float sAspScoreMul;
extern float sAspScoreSetDiv;
extern float sAspScoreSetMul;
extern float sAspScoreSetSub;

// ============================================================================
// Neighbor::GetRelations
// Address: 0x800c90b4, Size: 8 bytes
// MATCHING
// ============================================================================
RelationList* Neighbor::GetRelations() const {
    return m_relations;
}

// ============================================================================
// Neighbor::GetPersistentDataFieldsByIndex
// Address: 0x800c9780, Size: 20 bytes
// MATCHING
// ============================================================================
PersistentDataField* Neighbor::GetPersistentDataFieldsByIndex(int index) {
    return &sPersistentFields[index];
}

// ============================================================================
// Neighbor::GetLatestPersDataVersion
// Address: 0x800c9794, Size: 8 bytes
// MATCHING
// ============================================================================
int Neighbor::GetLatestPersDataVersion() {
    return 8;
}

// ============================================================================
// Neighbor::GetGUID
// Address: 0x800c9a8c, Size: 8 bytes
// MATCHING
// ============================================================================
int Neighbor::GetGUID() {
    return m_guid;
}

// ============================================================================
// Neighbor::SetGUID
// Address: 0x800c9a94, Size: 8 bytes
// MATCHING
// ============================================================================
void Neighbor::SetGUID(int guid) {
    m_guid = guid;
}

// ============================================================================
// Neighbor::GetFriendCount
// Address: 0x800ca208, Size: 60 bytes
// NON_MATCHING - GCC reorders: checks dirty flag first, falls through to
// fast path without creating stack frame. SN always creates full frame.
// ============================================================================
short Neighbor::GetFriendCount() {
    if (m_dirtyFlag != 0) {
        RecalculateRelationshipCounts();
    }
    return m_friendCount;
}

// ============================================================================
// Neighbor::GetEnemyCount
// Address: 0x800ca244, Size: 60 bytes
// NON_MATCHING - same frame setup issue as GetFriendCount
// ============================================================================
short Neighbor::GetEnemyCount() {
    if (m_dirtyFlag != 0) {
        RecalculateRelationshipCounts();
    }
    return m_enemyCount;
}

// ============================================================================
// Neighbor::GetReputationValue
// Address: 0x800ca280, Size: 60 bytes
// NON_MATCHING - same frame setup issue as GetFriendCount
// ============================================================================
short Neighbor::GetReputationValue() {
    if (m_dirtyFlag != 0) {
        RecalculateRelationshipCounts();
    }
    return m_reputationValue;
}

// ============================================================================
// Neighbor::GetRelationship
// Address: 0x800ca348, Size: 64 bytes
// NON_MATCHING - GCC reorders null check branches
// ============================================================================
int Neighbor::GetRelationship(Neighbor* other, int* outValue) {
    if (other == 0) {
        if (outValue != 0) {
            *outValue = 0;
        }
        return 0;
    }
    short guid = *(short*)((char*)other + 4);
    return GetRelationshipByGUID(guid);
}

// ============================================================================
// Neighbor::RemoveAllRelationships
// Address: 0x800ca4d0, Size: 56 bytes
// NON_MATCHING - GCC uses bctr tail call, SN uses blrl with stack frame
// Dispatches through relations vtable at offset +0x38/+0x3C
// ============================================================================
void Neighbor::RemoveAllRelationships() {
    RelationList* rels = m_relations;
    int* vtbl = *(int**)rels;
    short offset = *(short*)((char*)vtbl + 56);
    void (*fn)(void*) = (void (*)(void*))*(int*)((char*)vtbl + 60);
    fn((char*)rels + offset);
}

// ============================================================================
// Neighbor::GetAspirationScore
// Address: 0x800ca924, Size: 44 bytes
// NON_MATCHING - GCC loads constants in different order
// Logic: return ((raw + add) / div) * mul
// ============================================================================
float Neighbor::GetAspirationScore() {
    float raw = m_aspirationScore;
    return ((raw + sAspScoreAdd) / sAspScoreDiv) * sAspScoreMul;
}

// ============================================================================
// Neighbor::SetAspirationScore
// Address: 0x800ca950, Size: 40 bytes
// MATCHING
// Logic: store = (score / div) * mul - sub
// ============================================================================
void Neighbor::SetAspirationScore(float score) {
    m_aspirationScore = (score / sAspScoreSetDiv) * sAspScoreSetMul - sAspScoreSetSub;
}

// ============================================================================
// Neighbor::ResetInterests
// Address: 0x800ca978, Size: 36 bytes
// NON_MATCHING - GCC uses b tail call, SN uses bl with stack frame
// ============================================================================
void Neighbor::ResetInterests() {
    Interests_Init(&m_interests);
}

// ============================================================================
// Neighbor::GetSlotRange
// Address: 0x800cb490, Size: 44 bytes
// NON_MATCHING - original doesn't use 'this' pointer (effectively static)
// SN: r3=isPlayer2, r4=outStart, r5=outEnd
// GCC: r3=this, r4=isPlayer2, r5=outStart, r6=outEnd
// ============================================================================
void Neighbor::GetSlotRange(bool isPlayer2, unsigned int& outStart, unsigned int& outEnd) {
    if (isPlayer2) {
        outStart = 4;
        outEnd = 7;
    } else {
        outStart = 0;
        outEnd = 4;
    }
}

// ============================================================================
// Neighbor::GetBookmarkRange
// Address: 0x800cb4bc, Size: 44 bytes
// NON_MATCHING - same 'this' unused issue as GetSlotRange
// ============================================================================
void Neighbor::GetBookmarkRange(bool isPlayer2, unsigned int& outStart, unsigned int& outEnd) {
    if (isPlayer2) {
        outStart = 13;
        outEnd = 20;
    } else {
        outStart = 0;
        outEnd = 13;
    }
}

// ============================================================================
// global constructors keyed to Interests::sInterestMap
// Address: 0x800cc678, Size: 44 bytes
// NON_MATCHING - static init pattern
// ============================================================================

// ============================================================================
// global destructors keyed to Interests::sInterestMap
// Address: 0x800cc6a4, Size: 44 bytes
// NON_MATCHING - static destruct pattern
// ============================================================================

// ============================================================================
// ObjSelector::GetSimDescription
// Address: 0x803a5208, Size: 8 bytes
// MATCHING
// ============================================================================
void* ObjSelector::GetSimDescription() const {
    return *(void**)((char*)this + 0x8C);
}

// ============================================================================
// WantFear::Tree::GetNodeById
// Address: 0x803a5210, Size: 16 bytes
// MATCHING
// ============================================================================
void* WantFear::Tree::GetNodeById(short id) const {
    char* nodes = *(char**)((char*)this + 0x28);
    return nodes + ((unsigned int)id << 5);
}
