// AptMisc.cpp - APT misc functions (Math, Rand, String, GC, Movie, Input)
// Source: libaptz.a(AptMath.cpp.obj, AptRand.cpp.obj, AptString.cpp.obj,
//         AptGC.cpp.obj, AptMovie.cpp.obj, AptInput.cpp.obj)
// Small functions (<=64 bytes) decompiled from the Sims 2 GameCube ELF
//
// Original compiler: SN Systems ProDG for GameCube
// Decomp compiler: devkitPPC GCC -mcpu=750 -O2

#include "ui/apt_misc.h"

// ============================================================================
// External function declarations
// ============================================================================
extern "C" {
    void* AptNonGCAllocSaveSize(unsigned int size);
    void AptNonGCFreeSavedSize(void* ptr);
}

// External allocator (SDA-relative at r13 - 23020)
extern void* gpAptAllocator;  // DOGMA_PoolManager*
extern void* DOGMA_PoolManager_Allocate(void* mgr, unsigned int size);
extern void DOGMA_PoolManager_Deallocate(void* mgr, void* ptr, unsigned int size);

// External functions for string operations
extern void EAStringC_assign(EAStringC* dst, EAStringC* src);           // EAStringC::operator=(EAStringC&)
extern void EAStringC_cat_str(EAStringC* dst, EAStringC* src);          // EAStringC::operator+=(EAStringC&)
extern void EAStringC_cat_cstr(EAStringC* dst, char* src);              // EAStringC::operator+=(char*)
extern void EAStringC_InitFromBuffer(EAStringC* str, char* buf);        // EAStringC::InitFromBuffer

// External functions for movie
extern void* AptNativeHash_Lookup(void* hash, EAStringC* key);          // AptNativeHash::Lookup
extern int AptValue_toInteger(void* val);                                // AptValue::toInteger

// SDA-relative globals
extern AptValue* gpObjectPrototype;       // r13 - 22936 (for sMethod_lastIndexOf)

// AptMath clip stack globals (SDA-relative)
// s_clipStackIndex at r13 - 27242 (offset from r13)
extern u16 s_clipStackIndex;

// ============================================================================
// AptGC::Initialize (0x8029c650, 4 bytes) NON_MATCHING
// No-op (blr). GC initialization is apparently empty.
// ============================================================================
void AptGC::Initialize() {
}

// ============================================================================
// AptMath::ClipStackPushUnit (0x802a2684, 44 bytes) NON_MATCHING
// Increments s_clipStackIndex (u16 SDA-relative at r13-27242), then calls
// ClipStackMakeUnit to initialize the new stack entry to identity.
// SN: stwu/mflr/stw/lhz r9,off(r13)/addi r9,1/sth r9,off(r13)/bl ClipStackMakeUnit/lwz/mtlr/addi/blr
// ============================================================================
void AptMath::ClipStackPushUnit() {
    s_clipStackIndex++;
    ClipStackMakeUnit();
}

// ============================================================================
// AptAnimationPoolData::GetActionPool (0x802a9880 / 0x8029e268, 8 bytes) NON_MATCHING
// Returns m_actionPool at offset 0x98. lwz r3,152(r3); blr
// Two copies exist (Movie and Input translation units).
// ============================================================================
void* AptAnimationPoolData::GetActionPool() {
    return *(void**)((char*)this + 0x98);
}

// ============================================================================
// AptAnimationPoolData::validateBIL (0x8029e1f0, 8 bytes) NON_MATCHING
// Always returns 1 (true). li r3,1; blr
// ============================================================================
int AptAnimationPoolData::validateBIL() {
    return 1;
}

// ============================================================================
// AptMovie::labelToFrame (0x802a9848, 56 bytes) NON_MATCHING
// Looks up a label string in m_labelHash (offset 0x08) via AptNativeHash::Lookup.
// If found, converts the result to integer via AptValue::toInteger.
// If not found, returns -1.
// SN: stwu/mflr/stw/lwz r3,8(r3)/bl Lookup/mr. r0,r3/li r3,-1/beq ret/
//     mr r3,r0/bl toInteger/ret: lwz/mtlr/addi/blr
// ============================================================================
int AptMovie::labelToFrame(EAStringC* label) {
    void* result = AptNativeHash_Lookup(m_labelHash, label);
    if (result == 0) {
        return -1;
    }
    return AptValue_toInteger(result);
}

// ============================================================================
// AptString::sMethod_lastIndexOf (0x802ad0d4, 8 bytes) NON_MATCHING
// Returns gpObjectPrototype (SDA-relative at r13 - 22936).
// This is a stub that returns a global value.
// SN: lwz r3,-22936(r13); blr. GCC cannot match SDA-relative access.
// ============================================================================
AptValue* AptString::sMethod_lastIndexOf(AptValue* thisObj, int argc) {
    return gpObjectPrototype;
}

// ============================================================================
// AptValueGC::IsGarbageCollected (0x802aec34, 8 bytes) NON_MATCHING
// Returns true (1). Duplicate from AptString.cpp.obj.
// li r3,1; blr
// ============================================================================
// (defined in apt_value.cpp - duplicate TU copy)

// ============================================================================
// AptValueNoGC::IsGarbageCollected (0x802aec3c, 8 bytes) NON_MATCHING
// Returns false (0). Duplicate from AptString.cpp.obj.
// li r3,0; blr
// ============================================================================
// (defined in apt_value.cpp - duplicate TU copy)

// ============================================================================
// AptValueNoGC::RegisterReferences (0x802aec44, 4 bytes) NON_MATCHING
// No-op (blr). Duplicate from AptString.cpp.obj.
// ============================================================================
// (defined in apt_value.cpp - duplicate TU copy)

// ============================================================================
// AptString::cpy(EAStringC*) (0x802aec48, 36 bytes) NON_MATCHING
// Calls EAStringC::operator= on the internal string at this+0x0C.
// SN: stwu/mflr/stw/addi r3,r3,12/bl operator=/lwz/mtlr/addi/blr
// ============================================================================
void AptString::cpy(EAStringC* src) {
    EAStringC_assign(&m_string, src);
}

// ============================================================================
// AptString::cat(EAStringC*) (0x802aecb4, 36 bytes) NON_MATCHING
// Calls EAStringC::operator+=(EAStringC&) on the internal string at this+0x0C.
// SN: stwu/mflr/stw/addi r3,r3,12/bl operator+=/lwz/mtlr/addi/blr
// ============================================================================
void AptString::cat(EAStringC* src) {
    EAStringC_cat_str(&m_string, src);
}

// ============================================================================
// AptString::cat(char*) (0x802aecd8, 36 bytes) NON_MATCHING
// Calls EAStringC::operator+=(char*) on the internal string at this+0x0C.
// SN: stwu/mflr/stw/addi r3,r3,12/bl operator+= char/lwz/mtlr/addi/blr
// ============================================================================
void AptString::cat(char* src) {
    EAStringC_cat_cstr(&m_string, src);
}

// ============================================================================
// AptString::GetInternalString (0x802aecfc, 8 bytes) NON_MATCHING
// Returns pointer to internal EAStringC at this+0x0C.
// addi r3,r3,12; blr
// ============================================================================
EAStringC* AptString::GetInternalString() {
    return &m_string;
}

// ============================================================================
// AptString::SetNext (0x802aed04, 8 bytes) NON_MATCHING
// Sets linked list next pointer at this+0x10.
// stw r4,16(r3); blr
// ============================================================================
void AptString::SetNext(AptString* next) {
    m_next = next;
}

// ============================================================================
// AptString::GetNext (0x802aed0c, 8 bytes) NON_MATCHING
// Returns linked list next pointer from this+0x10.
// lwz r3,16(r3); blr
// ============================================================================
AptString* AptString::GetNext() const {
    return m_next;
}

// ============================================================================
// AptString::operator new (0x802aed14, 40 bytes) NON_MATCHING
// Allocates via DOGMA_PoolManager::Allocate using gpAptAllocator.
// SN: stwu/mflr/stw/mr r4,r3/lwz r3,-23020(r13)/bl Allocate/lwz/mtlr/addi/blr
// ============================================================================
void* AptString::operator new(unsigned int size) {
    return DOGMA_PoolManager_Allocate(gpAptAllocator, size);
}

// ============================================================================
// AptString::operator delete (0x802aed3c, 48 bytes) NON_MATCHING
// Deallocates via DOGMA_PoolManager::Deallocate using gpAptAllocator.
// SN: stwu/mflr/stw/mr r0,r3/mr r5,r4/lwz r3,-23020(r13)/mr r4,r0/bl Deallocate/lwz/mtlr/addi/blr
// ============================================================================
void AptString::operator delete(void* ptr, unsigned int size) {
    DOGMA_PoolManager_Deallocate(gpAptAllocator, ptr, size);
}

// ============================================================================
// AptString::operator new[] (0x802aed6c, 32 bytes) NON_MATCHING
// Calls AptNonGCAllocSaveSize for array allocation.
// SN: stwu/mflr/stw/bl AptNonGCAllocSaveSize/lwz/mtlr/addi/blr
// ============================================================================
void* AptString::operator new[](unsigned int size) {
    return AptNonGCAllocSaveSize(size);
}

// ============================================================================
// AptString::operator delete[] (0x802aed8c, 32 bytes) NON_MATCHING
// Calls AptNonGCFreeSavedSize for array deallocation.
// SN: stwu/mflr/stw/bl AptNonGCFreeSavedSize/lwz/mtlr/addi/blr
// ============================================================================
void AptString::operator delete[](void* ptr) {
    AptNonGCFreeSavedSize(ptr);
}

// ============================================================================
// AptSeedRand (0x802ab148, 64 bytes) NON_MATCHING
// Seeds the Mersenne Twister PRNG state array (624 u32s).
// Sets mt[0] = seed | 1, then mt[i] = mt[i-1] * 69069 for i=1..623.
// Also clears the reload index to 0.
//
// SN codegen: lis r9,hi(mt)/li r0,0/ori r3,r3,1/li r11,623/
//   stw r3,lo(mt)(r9)/mtctr r11/stw r0,idx(r13)/addi r9,r9,lo(mt)/
//   lis r0,hi(69069)/addi r9,4/ori r0,r0,lo(69069)/
//   loop: mullw r3,r3,r0/stw r3,0(r9)/addi r9,4/bdnz loop/blr
//
// The constant 69069 = 0x00010DCD.
// GCC will likely produce different register allocation and loop structure.
// ============================================================================

// ============================================================================
// Free list heads for pooled value types (SDA-relative globals)
// AptBoolean free list: r13 - 26916 (0x6924)
// AptFloat free list: r13 - 26912 (0x6920)
// AptInteger free list: r13 - 26908 (0x691C)
// ============================================================================
extern AptBoolean* s_booleanFreeList;   // SDA-relative
extern AptFloat* s_floatFreeList;       // SDA-relative
extern AptInteger* s_integerFreeList;   // SDA-relative

// ============================================================================
// AptBoolean - boolean value type with free list pooling
// Source: libaptz.a(AptBoolean.cpp.obj)
// ============================================================================

// 0x802bb8b4 (16 bytes) NON_MATCHING - SN uses SDA-relative r13 access
// Pushes this onto the boolean free list. Sets m_value (offset 0x0C) to old head.
void AptBoolean::DeleteThis() {
    m_value = (u32)s_booleanFreeList;
    s_booleanFreeList = this;
}

// 0x802bb8c4 (16 bytes) NON_MATCHING - identical to DeleteThis
void AptBoolean::ForceDelete() {
    m_value = (u32)s_booleanFreeList;
    s_booleanFreeList = this;
}

// 0x802bbac8 (16 bytes) NON_MATCHING - identical to DeleteThis/ForceDelete
void AptBoolean::Destroy() {
    m_value = (u32)s_booleanFreeList;
    s_booleanFreeList = this;
}

// 0x802bbad8 (8 bytes) NON_MATCHING
// Returns m_value from offset 0x0C. lwz r3,12(r3); blr
u32 AptBoolean::GetBool() const {
    return m_value;
}

// 0x802bb934 (40 bytes) NON_MATCHING - SN uses SDA r13-relative for gpAptAllocator
void* AptBoolean::operator new(unsigned int size) {
    return DOGMA_PoolManager_Allocate(gpAptAllocator, size);
}

// 0x802bb95c (48 bytes) NON_MATCHING
void AptBoolean::operator delete(void* ptr, unsigned int size) {
    DOGMA_PoolManager_Deallocate(gpAptAllocator, ptr, size);
}

// 0x802bb98c (32 bytes) NON_MATCHING
void* AptBoolean::operator new[](unsigned int size) {
    return AptNonGCAllocSaveSize(size);
}

// 0x802bb9ac (32 bytes) NON_MATCHING
void AptBoolean::operator delete[](void* ptr) {
    AptNonGCFreeSavedSize(ptr);
}

// ============================================================================
// AptFloat - float value type with free list pooling
// Source: libaptz.a(AptFloat.cpp.obj)
// ============================================================================

// 0x802bbb64 (16 bytes) NON_MATCHING - SN uses SDA-relative r13 access
void AptFloat::DeleteThis() {
    *(u32*)&m_value = (u32)s_floatFreeList;
    s_floatFreeList = this;
}

// 0x802bbb74 (16 bytes) NON_MATCHING
void AptFloat::ForceDelete() {
    *(u32*)&m_value = (u32)s_floatFreeList;
    s_floatFreeList = this;
}

// 0x802bbd84 (16 bytes) NON_MATCHING
void AptFloat::Destroy() {
    *(u32*)&m_value = (u32)s_floatFreeList;
    s_floatFreeList = this;
}

// 0x802bbd94 (8 bytes) NON_MATCHING
// Returns float from offset 0x0C. lfs f1,12(r3); blr
float AptFloat::GetFloat() const {
    return m_value;
}

// 0x802bbbe4 (40 bytes) NON_MATCHING
void* AptFloat::operator new(unsigned int size) {
    return DOGMA_PoolManager_Allocate(gpAptAllocator, size);
}

// 0x802bbc0c (48 bytes) NON_MATCHING
void AptFloat::operator delete(void* ptr, unsigned int size) {
    DOGMA_PoolManager_Deallocate(gpAptAllocator, ptr, size);
}

// 0x802bbc3c (32 bytes) NON_MATCHING
void* AptFloat::operator new[](unsigned int size) {
    return AptNonGCAllocSaveSize(size);
}

// 0x802bbc5c (32 bytes) NON_MATCHING
void AptFloat::operator delete[](void* ptr) {
    AptNonGCFreeSavedSize(ptr);
}

// ============================================================================
// AptInteger - integer value type with free list pooling
// Source: libaptz.a(AptInteger.cpp.obj)
// ============================================================================

// 0x802bbe20 (16 bytes) NON_MATCHING - SN uses SDA-relative r13 access
void AptInteger::DeleteThis() {
    m_value = (int)s_integerFreeList;
    s_integerFreeList = this;
}

// 0x802bbe30 (16 bytes) NON_MATCHING
void AptInteger::ForceDelete() {
    m_value = (int)s_integerFreeList;
    s_integerFreeList = this;
}

// 0x802bc034 (16 bytes) NON_MATCHING
void AptInteger::Destroy() {
    m_value = (int)s_integerFreeList;
    s_integerFreeList = this;
}

// 0x802bc044 (8 bytes) NON_MATCHING
// Returns m_value from offset 0x0C. lwz r3,12(r3); blr
int AptInteger::GetInt() const {
    return m_value;
}

// 0x802bbea0 (40 bytes) NON_MATCHING
void* AptInteger::operator new(unsigned int size) {
    return DOGMA_PoolManager_Allocate(gpAptAllocator, size);
}

// 0x802bbec8 (48 bytes) NON_MATCHING
void AptInteger::operator delete(void* ptr, unsigned int size) {
    DOGMA_PoolManager_Deallocate(gpAptAllocator, ptr, size);
}

// 0x802bbef8 (32 bytes) NON_MATCHING
void* AptInteger::operator new[](unsigned int size) {
    return AptNonGCAllocSaveSize(size);
}

// 0x802bbf18 (32 bytes) NON_MATCHING
void AptInteger::operator delete[](void* ptr) {
    AptNonGCFreeSavedSize(ptr);
}

// ============================================================================
// AptRand - Mersenne Twister PRNG
// Source: libaptz.a(AptRand.cpp.obj)
// ============================================================================

// Mersenne Twister state - 624 u32s + index counter
// Located in BSS at 0x804ac1c0 (absolute address from disassembly)
// s_mtIndex is SDA-relative (r13 - 27100)
extern u32 s_mt[MT_N];
extern u32 s_mtIndex;

// 0x802ab148 (64 bytes) NON_MATCHING
// SN uses lis/ori for 69069 constant and ctr-based loop (li r11,623/mtctr/bdnz).
// GCC may use different loop structure and constant loading.
void AptSeedRand(u32 seed) {
    seed |= 1;
    s_mt[0] = seed;
    s_mtIndex = 0;
    for (int i = 1; i < MT_N; i++) {
        seed = seed * 69069;
        s_mt[i] = seed;
    }
}
