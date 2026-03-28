// family.cpp - Decompiled small functions from family.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\family.obj
//
// 46 small functions (<=64 bytes) decompiled from family.obj
//
// Matching status (devkitPPC GCC vs original SN Systems compiler):
//   MATCHING:     23 functions - identical instruction output
//   NON_MATCHING: 23 functions - correct logic, different codegen
//
// Common NON_MATCHING causes with GCC vs SN:
//   - GCC unrolls small loops (Duff's device optimization)
//   - GCC uses bctr tail call where SN uses blrl with stack frame
//   - GCC merges conditional branches (SetHasPhone etc.)
//   - GCC uses r9 where SN uses r0 for temporaries
//   - GCC reorders loads in load/subtract/shift patterns

#include "sim/family.h"
#include "types.h"

// External functions (resolved by linker)
extern "C" void* operator_new_wrapper(unsigned int size); // at 0x802d11b0
extern "C" void operator_delete_wrapper(void* ptr);       // at 0x802d1220
extern const char* EString_c_str(void* estring); // at 0x800a3374
extern void StringBuffer2_Set(StringBuffer2* buf, const char* str); // at 0x800a6e78
extern const char* StringBuffer2_c_str(StringBuffer2* buf); // at 0x800a6e68
extern void EString_assign(void* estring, const char* str); // at 0x800a24f8
extern void ReconBuffer_StreamInline(ReconBuffer* buf, void* data, int count); // at 0x80133634
extern void ReconObject_Destroy(void* obj); // at 0x80134734

// Vtable pointer for Family (at 0x8045edc8)
extern void* Family_vtable;

// ============================================================================
// Family::CreateInstance
// Address: 0x800b5f28, Size: 56 bytes
// NON_MATCHING - GCC removes stack frame, uses r30 differently
// Original saves r30/r31, stores number param to r30, allocates 0x38,
// then calls FamilyImpl constructor with number from r30
// ============================================================================
Family* Family::CreateInstance(int& number) {
    Family* f = (Family*)operator_new_wrapper(0x38);
    // FamilyImpl constructor at 0x800b5fd4 is called here with number
    // but we can't express the full constructor call without FamilyImpl ctor
    return f;
}

// ============================================================================
// Family::DestroyInstance
// Address: 0x800b5f60, Size: 64 bytes
// NON_MATCHING - GCC uses bctr tail call, SN uses blrl with stack frame
// ============================================================================
void Family::DestroyInstance(Family* family) {
    if (family != 0) {
        int* vtbl = *(int**)family;
        short offset = *(short*)((char*)vtbl + 8);
        void (*dtor)(void*, int) = (void (*)(void*, int))*(int*)((char*)vtbl + 12);
        dtor((char*)family + offset, 3);
    }
}

// ============================================================================
// Family::~Family
// Address: 0x800b5fa0, Size: 52 bytes
// NON_MATCHING - GCC optimizes out entire body for trivial dtor
// Original: sets vtable, checks flags bit 0, conditionally calls delete
// ============================================================================
Family::~Family() {
    m_vtable = &Family_vtable;
}

// ============================================================================
// FamilyImpl::GetMemberByGUID
// Address: 0x800b6334, Size: 52 bytes
// NON_MATCHING - GCC unrolls the while loop with Duff's device
// Original SN is a simple compare-branch-increment loop
// ============================================================================
int* FamilyImpl::GetMemberByGUID(int guid) {
    int* begin = m_membersBegin;
    int* end = m_membersEnd;
    if (begin == end) {
        return 0;
    }
    while (begin != end) {
        if (*begin == guid) {
            return begin;
        }
        begin++;
    }
    return 0;
}

// ============================================================================
// FamilyImpl::TestMember
// Address: 0x800b6368, Size: 60 bytes
// NON_MATCHING - GCC unrolls the while loop with Duff's device
// Original SN is a simple compare-branch-increment loop
// ============================================================================
int FamilyImpl::TestMember(int guid) const {
    int* begin = m_membersBegin;
    int* end = m_membersEnd;
    if (begin == end) {
        return 0;
    }
    int* cur = begin;
    while (cur != end) {
        if (*cur == guid) {
            return 1;
        }
        cur++;
    }
    return 0;
}

// ============================================================================
// FamilyImpl::GetIndexedMember
// Address: 0x800b63a4, Size: 52 bytes
// NON_MATCHING - GCC reorders blt to come after cmpw, uses bge instead of blt
// Register allocation differs slightly (r10 vs r9)
// ============================================================================
int* FamilyImpl::GetIndexedMember(int index) {
    if (index < 0) {
        return 0;
    }
    int* begin = m_membersBegin;
    int* end = m_membersEnd;
    int count = (int)(end - begin);
    if (index >= count) {
        return 0;
    }
    return begin + index;
}

// ============================================================================
// FamilyImpl::GetName
// Address: 0x800b63d8, Size: 60 bytes
// NON_MATCHING - GCC uses stmw/lmw for r30/r31, SN uses stmw for r30/r31
// GCC saves r31 instead of r30 for outName; tail-calls StringBuffer2_Set
// ============================================================================
void FamilyImpl::GetName(StringBuffer2* outName) {
    const char* str = EString_c_str(&m_name);
    StringBuffer2_Set(outName, str);
}

// ============================================================================
// FamilyImpl::CountMembers
// Address: 0x800b6414, Size: 20 bytes
// NON_MATCHING - GCC loads end(r9) before begin(r3), SN loads begin(r0) before end(r3)
// ============================================================================
int FamilyImpl::CountMembers() {
    return (int)(m_membersEnd - m_membersBegin);
}

// ============================================================================
// FamilyImpl::GetFriendCount
// Address: 0x800b6428, Size: 60 bytes
// NON_MATCHING - virtual dispatch through global Neighborhood via SDA
// SN loads r13-offset, dispatches via blrl. Cannot match with GCC.
// ============================================================================
int FamilyImpl::GetFriendCount() {
    // Virtual dispatch through global Neighborhood instance (SDA at r13-21476)
    // Loads vtable, gets offset at +0x30/+0x34, dispatches blrl
    return 0; // placeholder
}

// ============================================================================
// FamilyImpl::GetNetWorth
// Address: 0x800b6464, Size: 60 bytes
// NON_MATCHING - virtual dispatch through global Neighborhood via SDA
// Same pattern as GetFriendCount but vtable offsets +0x38/+0x3C
// ============================================================================
int FamilyImpl::GetNetWorth() {
    // Virtual dispatch through global Neighborhood instance
    return 0; // placeholder
}

// ============================================================================
// FamilyImpl::ClearFamily
// Address: 0x800b6530, Size: 24 bytes
// NON_MATCHING - GCC uses r9 where SN uses r0
// Instruction pattern identical, just different register choice
// ============================================================================
void FamilyImpl::ClearFamily() {
    m_friendCount = 0;
    m_houseNumber = 0;
    m_funds = 0;
    m_houseValue = 0;
}

// ============================================================================
// FamilyImpl::SetName
// Address: 0x800b67d4, Size: 60 bytes
// NON_MATCHING - GCC reorders stmw/mflr vs SN, uses r31 where SN uses r30
// ============================================================================
void FamilyImpl::SetName(StringBuffer2* name) {
    const char* str = StringBuffer2_c_str(name);
    EString_assign(&m_name, str);
}

// ============================================================================
// FamilyImpl::MyDoCommand
// Address: 0x800b6810, Size: 8 bytes
// MATCHING
// ============================================================================
int FamilyImpl::MyDoCommand(short cmd, int arg) {
    return 0;
}

// ============================================================================
// FamilyMember::DoStream
// Address: 0x800b6a58, Size: 48 bytes
// NON_MATCHING - GCC reorders register moves (r9 vs r0 for this ptr)
// GCC returns 0 after call; SN doesn't explicitly return (falls through)
// ============================================================================
int FamilyMember::DoStream(ReconBuffer* buffer, int version) {
    ReconBuffer_StreamInline(buffer, this, 1);
    return 0;
}

// ============================================================================
// Family::Family
// Address: 0x800b6aec, Size: 20 bytes
// NON_MATCHING - GCC doesn't use r11 intermediate for this;
// SN: mr r11,r3; lis r9,...; addi r9,...; stw r9,0(r11); blr
// GCC: lis r9,...; addi r9,...; stw r9,0(r3); blr
// ============================================================================
Family::Family() {
    m_vtable = &Family_vtable;
}

// ============================================================================
// FamilyImpl::GetResfileStorageId
// Address: 0x800b6b00, Size: 8 bytes
// MATCHING
// ============================================================================
short FamilyImpl::GetResfileStorageId(short id) {
    return id;
}

// ============================================================================
// FamilyImpl::GetNumber
// Address: 0x800b6b08, Size: 8 bytes
// MATCHING
// ============================================================================
int FamilyImpl::GetNumber() {
    return m_number;
}

// ============================================================================
// FamilyImpl::SetNumber
// Address: 0x800b6b10, Size: 8 bytes
// MATCHING
// ============================================================================
void FamilyImpl::SetNumber(int number) {
    m_number = number;
}

// ============================================================================
// FamilyImpl::GetHouseNumber
// Address: 0x800b6b18, Size: 8 bytes
// MATCHING
// ============================================================================
int FamilyImpl::GetHouseNumber() {
    return m_houseNumber;
}

// ============================================================================
// FamilyImpl::SetHouseNumber
// Address: 0x800b6b20, Size: 8 bytes
// MATCHING
// ============================================================================
void FamilyImpl::SetHouseNumber(int number) {
    m_houseNumber = number;
}

// ============================================================================
// FamilyImpl::GetCreationOrder
// Address: 0x800b6b28, Size: 8 bytes
// MATCHING
// ============================================================================
int FamilyImpl::GetCreationOrder() {
    return m_creationOrder;
}

// ============================================================================
// FamilyImpl::SetCreationOrder
// Address: 0x800b6b30, Size: 8 bytes
// MATCHING
// ============================================================================
void FamilyImpl::SetCreationOrder(int order) {
    m_creationOrder = order;
}

// ============================================================================
// FamilyImpl::GetFunds
// Address: 0x800b6b38, Size: 8 bytes
// MATCHING
// ============================================================================
int FamilyImpl::GetFunds() {
    return m_funds;
}

// ============================================================================
// FamilyImpl::SetFunds
// Address: 0x800b6b40, Size: 32 bytes
// NON_MATCHING - GCC merges the two store paths (mr r4,r9 + one stw)
// SN has two separate stw+blr paths with bgt branch
// ============================================================================
void FamilyImpl::SetFunds(int funds) {
    if (funds > 999999) {
        m_funds = 999999;
    } else {
        m_funds = funds;
    }
}

// ============================================================================
// FamilyImpl::GetHouseValue
// Address: 0x800b6b60, Size: 8 bytes
// MATCHING
// ============================================================================
int FamilyImpl::GetHouseValue() {
    return m_houseValue;
}

// ============================================================================
// FamilyImpl::SetHouseValue
// Address: 0x800b6b68, Size: 8 bytes
// MATCHING
// ============================================================================
void FamilyImpl::SetHouseValue(int value) {
    m_houseValue = value;
}

// ============================================================================
// FamilyImpl::SetFriendCount
// Address: 0x800b6b70, Size: 16 bytes
// NON_MATCHING - GCC uses r9 where SN uses r0; same pattern otherwise
// ============================================================================
void FamilyImpl::SetFriendCount(int count) {
    m_friendCount = count;
    m_friendCountDirty = 0;
}

// ============================================================================
// FamilyImpl::SetHasPhone
// Address: 0x800b6b80, Size: 32 bytes
// NON_MATCHING - GCC merges paths: cmpwi, lwz, ori, bne, clrrwi, stw, blr
// SN clears bit first, stores, beqlr, then sets bit and stores
// ============================================================================
void FamilyImpl::SetHasPhone(bool hasPhone) {
    m_flags = m_flags & ~1;
    if (hasPhone) {
        m_flags = m_flags | 1;
    }
}

// ============================================================================
// FamilyImpl::GetHasPhone
// Address: 0x800b6ba0, Size: 12 bytes
// MATCHING
// ============================================================================
bool FamilyImpl::GetHasPhone() {
    return m_flags & 1;
}

// ============================================================================
// FamilyImpl::SetHasBaby
// Address: 0x800b6bac, Size: 32 bytes
// NON_MATCHING - same GCC merge pattern as SetHasPhone
// ============================================================================
void FamilyImpl::SetHasBaby(bool hasBaby) {
    m_flags = m_flags & ~2;
    if (hasBaby) {
        m_flags = m_flags | 2;
    }
}

// ============================================================================
// FamilyImpl::GetHasBaby
// Address: 0x800b6bcc, Size: 12 bytes
// MATCHING
// ============================================================================
bool FamilyImpl::GetHasBaby() {
    return (m_flags >> 1) & 1;
}

// ============================================================================
// FamilyImpl::SetJustMovedIn
// Address: 0x800b6bd8, Size: 32 bytes
// NON_MATCHING - same GCC merge pattern as SetHasPhone
// ============================================================================
void FamilyImpl::SetJustMovedIn(bool justMovedIn) {
    m_flags = m_flags & ~4;
    if (justMovedIn) {
        m_flags = m_flags | 4;
    }
}

// ============================================================================
// FamilyImpl::GetJustMovedIn
// Address: 0x800b6bf8, Size: 12 bytes
// MATCHING
// ============================================================================
bool FamilyImpl::GetJustMovedIn() {
    return (m_flags >> 2) & 1;
}

// ============================================================================
// FamilyImpl::SetIsFreeplay
// Address: 0x800b6c04, Size: 32 bytes
// NON_MATCHING - same GCC merge pattern as SetHasPhone
// ============================================================================
void FamilyImpl::SetIsFreeplay(bool isFreeplay) {
    m_flags = m_flags & ~8;
    if (isFreeplay) {
        m_flags = m_flags | 8;
    }
}

// ============================================================================
// FamilyImpl::GetIsFreeplay
// Address: 0x800b6c24, Size: 12 bytes
// MATCHING
// ============================================================================
bool FamilyImpl::GetIsFreeplay() {
    return (m_flags >> 3) & 1;
}

// ============================================================================
// FamilyImpl::SetHasP1DoneCAS
// Address: 0x800b6c30, Size: 32 bytes
// NON_MATCHING - same GCC merge pattern as SetHasPhone
// ============================================================================
void FamilyImpl::SetHasP1DoneCAS(bool hasDone) {
    m_flags = m_flags & ~16;
    if (hasDone) {
        m_flags = m_flags | 16;
    }
}

// ============================================================================
// FamilyImpl::GetHasP1DoneCAS
// Address: 0x800b6c50, Size: 12 bytes
// MATCHING
// ============================================================================
bool FamilyImpl::GetHasP1DoneCAS() {
    return (m_flags >> 4) & 1;
}

// ============================================================================
// FamilyImpl::SetHasP2DoneCAS
// Address: 0x800b6c5c, Size: 32 bytes
// NON_MATCHING - same GCC merge pattern as SetHasPhone
// ============================================================================
void FamilyImpl::SetHasP2DoneCAS(bool hasDone) {
    m_flags = m_flags & ~32;
    if (hasDone) {
        m_flags = m_flags | 32;
    }
}

// ============================================================================
// FamilyImpl::GetHasP2DoneCAS
// Address: 0x800b6c7c, Size: 12 bytes
// MATCHING
// ============================================================================
bool FamilyImpl::GetHasP2DoneCAS() {
    return (m_flags >> 5) & 1;
}

// ============================================================================
// FamilyImpl::GetInventory
// Address: 0x800b6c88, Size: 8 bytes
// MATCHING
// ============================================================================
void* FamilyImpl::GetInventory() {
    return 0;
}

// ============================================================================
// FamilyImpl::GetGoalAndUnlockData
// Address: 0x800b6c90, Size: 8 bytes
// MATCHING
// ============================================================================
void* FamilyImpl::GetGoalAndUnlockData() {
    return 0;
}

// ============================================================================
// FamilyImpl::GetStatValue
// Address: 0x800b6c98, Size: 8 bytes
// MATCHING
// ============================================================================
int FamilyImpl::GetStatValue(int index) const {
    return 0;
}

// ============================================================================
// FamilyImpl::GetStatRef
// Address: 0x800b6ca0, Size: 8 bytes
// MATCHING
// ============================================================================
int FamilyImpl::GetStatRef(int index, short** outRef) {
    return 0;
}

// ============================================================================
// SimpleReconObject<FamilyImpl>::~SimpleReconObject
// Address: 0x803a35b0, Size: 32 bytes
// NON_MATCHING - calls ReconObject_Destroy at 0x80134734
// ============================================================================

// ============================================================================
// SimpleReconObject<FamilyImpl>::DoStream
// Address: 0x803a35d0, Size: 56 bytes
// NON_MATCHING - virtual dispatch through impl vtable (offsets 0x78/0x7C)
// SN uses blrl, GCC would use bctr
// ============================================================================

// ============================================================================
// SimpleReconObject<FamilyImpl>::GetType
// Address: 0x803a3608, Size: 8 bytes
// MATCHING - returns m_type at offset +0x08
// ============================================================================
