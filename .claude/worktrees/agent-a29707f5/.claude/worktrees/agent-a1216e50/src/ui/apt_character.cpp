// AptCharacter.cpp - APT character/sprite instance functions
// Source: libaptz.a(AptCharacter.cpp.obj)
// Small functions (<=64 bytes) decompiled from the Sims 2 GameCube ELF
//
// Original compiler: SN Systems ProDG for GameCube
// Decomp compiler: devkitPPC GCC -mcpu=750 -O2

#include "ui/apt_character.h"
#include "ui/apt_display.h"

// ============================================================================
// External function declarations
// ============================================================================
extern "C" {
    int strcmp(const char* s1, const char* s2);
    void* AptNonGCAllocSaveSize(unsigned int size);
    void AptNonGCFreeSavedSize(void* ptr);
}

// External allocator (SDA-relative at r13 - 23020)
extern void* gpAptAllocator;  // DOGMA_PoolManager*

// External functions
extern void AptDisplayList_PreDestroy(AptDisplayList* dl);
extern void AptNativeHash_DestroyGCPointers(void* hash);

// ============================================================================
// EAStringC functions (duplicated in this translation unit)
// ============================================================================

// 0x8028fc78 (32 bytes) NON_MATCHING
// SN uses lis/addi/stw/lhz/addi/sth pattern with r11 scratch.
// GCC may differ in register allocation.
// Original: stores &EAStringC_s_EmptyInternalData into m_pData, increments refCount.
// EAStringC::EAStringC(void) - see apt_value.cpp for canonical version

// 0x8028fc5c (28 bytes) NON_MATCHING
// Compares m_pData to &EAStringC_s_EmptyInternalData using xor/subfic/adde idiom.
// GCC uses cntlzw/srwi instead of subfic/adde.
// EAStringC::IsEmpty(void) const - see apt_value.cpp for canonical version

// ============================================================================
// AptCharacterInst::PreDestroy (0x8028fae4, 4 bytes) NON_MATCHING
// No-op - just returns (blr).
// SN and GCC both generate identical blr for empty virtual override.
// ============================================================================
void AptCharacterInst::PreDestroy() {
}

// ============================================================================
// AptValueGC::IsGarbageCollected (0x8028f9ac, 8 bytes) NON_MATCHING
// Returns true (li r3,1; blr).
// Duplicate of the one in AptValue.cpp.obj - this copy is in AptCharacter.cpp.obj.
// ============================================================================
// (Already defined in apt_value.cpp, this is a duplicate TU copy)

// ============================================================================
// AptCharacterInst::DestroyGCPointers (0x8028fb44, 64 bytes) NON_MATCHING
// If m_nativeHash (offset 0x0C) is non-null, calls AptNativeHash::DestroyGCPointers.
// Sets m_gcFlag (offset 0x10) to 1.
// SN uses r31 for this, GCC may differ.
// ============================================================================
void AptCharacterInst::DestroyGCPointers() {
    // m_pad0C is at offset 0x0C, treated as AptNativeHash*
    void* hash = (void*)m_pad0C;
    if (hash != 0) {
        AptNativeHash_DestroyGCPointers(hash);
    }
    m_pad10 = 1;
}

// ============================================================================
// AptCharacterInst::sMethod_gotoAndStop (0x80289398, 36 bytes) NON_MATCHING
// Calls _gotoAndX with playFlag=0.
// SN: stwu/mflr/stw/li r5,0/bl/lwz/mtlr/addi/blr
// ============================================================================
AptValue* AptCharacterInst::sMethod_gotoAndStop(AptValue* thisObj, int argc) {
    return ((AptCharacterInst*)thisObj)->_gotoAndX(thisObj, argc, 0);
}

// ============================================================================
// AptCharacterInst::sMethod_gotoAndPlay (0x802893bc, 36 bytes) NON_MATCHING
// Calls _gotoAndX with playFlag=1.
// ============================================================================
AptValue* AptCharacterInst::sMethod_gotoAndPlay(AptValue* thisObj, int argc) {
    return ((AptCharacterInst*)thisObj)->_gotoAndX(thisObj, argc, 1);
}

// ============================================================================
// AptCharacterSpriteInstBase::PreDestroy (0x80288388, 36 bytes) NON_MATCHING
// Calls AptDisplayList::PreDestroy on the embedded display list at this+0x24.
// SN: stwu/mflr/stw/addi r3,r3,36/bl PreDestroy/lwz/mtlr/addi/blr
// ============================================================================
void AptCharacterSpriteInstBase::PreDestroy() {
    ((AptDisplayList*)((char*)this + 0x24))->PreDestroy();
}

// ============================================================================
// AptCharacterSpriteInstBase::SetClipAction (0x8028fb84, 24 bytes) NON_MATCHING
// Reads m_clipActionFlags at offset 0x1C, extracts bits 8-31 (srawi r0,8),
// ORs in the action bits, then packs back (rlwimi r0,r9,8,0,23).
// SN uses srawi+or+rlwimi; GCC may produce different bit manipulation.
// ============================================================================
void AptCharacterSpriteInstBase::SetClipAction(int action) {
    u32* flagsPtr = (u32*)((char*)this + 0x1C);
    u32 flags = *flagsPtr;
    int existing = (int)flags >> 8;
    existing |= action;
    *flagsPtr = (flags & 0xFF) | ((u32)existing << 8);
}

// ============================================================================
// AptCharacterSpriteInstBase::RemoveClipAction (0x8028fb9c, 24 bytes) NON_MATCHING
// Reads bits 8-31 of m_clipActionFlags, ANDs out the action bits (andc), packs back.
// SN: lwz/srawi/andc/rlwimi/stw/blr
// ============================================================================
void AptCharacterSpriteInstBase::RemoveClipAction(int action) {
    u32* flagsPtr = (u32*)((char*)this + 0x1C);
    u32 flags = *flagsPtr;
    int existing = (int)flags >> 8;
    existing &= ~action;
    *flagsPtr = (flags & 0xFF) | ((u32)existing << 8);
}

// ============================================================================
// AptCharacterSpriteInstBase::HasClipAction (0x8028fbb4, 16 bytes) NON_MATCHING
// Reads bits 8-31 of m_clipActionFlags, ANDs with action mask.
// SN: lwz/srawi/and/blr
// ============================================================================
int AptCharacterSpriteInstBase::HasClipAction(int action) {
    u32 flags = *(u32*)((char*)this + 0x1C);
    return ((int)flags >> 8) & action;
}

// ============================================================================
// AptCharacterTextInst::operator new (0x8028fbc4, 40 bytes) NON_MATCHING
// Allocates via DOGMA_PoolManager::Allocate using gpAptAllocator (SDA r13-relative).
// SN: stwu/mflr/stw/mr r4,r3/lwz r3,-23020(r13)/bl Allocate/lwz/mtlr/addi/blr
// ============================================================================
void* AptCharacterTextInst::operator new(unsigned int size) {
    extern void* DOGMA_PoolManager_Allocate(void* mgr, unsigned int size);
    return DOGMA_PoolManager_Allocate(gpAptAllocator, size);
}

// ============================================================================
// AptCharacterTextInst::operator delete (0x8028fbec, 48 bytes) NON_MATCHING
// Deallocates via DOGMA_PoolManager::Deallocate using gpAptAllocator.
// SN: stwu/mflr/stw/mr r0,r3/mr r5,r4/lwz r3,-23020(r13)/mr r4,r0/bl/lwz/mtlr/addi/blr
// ============================================================================
void AptCharacterTextInst::operator delete(void* ptr, unsigned int size) {
    extern void DOGMA_PoolManager_Deallocate(void* mgr, void* ptr, unsigned int size);
    DOGMA_PoolManager_Deallocate(gpAptAllocator, ptr, size);
}

// ============================================================================
// AptCharacterTextInst::operator new[] (0x8028fc1c, 32 bytes) NON_MATCHING
// Calls AptNonGCAllocSaveSize for array allocation.
// SN: stwu/mflr/stw/bl AptNonGCAllocSaveSize/lwz/mtlr/addi/blr
// ============================================================================
void* AptCharacterTextInst::operator new[](unsigned int size) {
    return AptNonGCAllocSaveSize(size);
}

// ============================================================================
// AptCharacterTextInst::operator delete[] (0x8028fc3c, 32 bytes) NON_MATCHING
// Calls AptNonGCFreeSavedSize for array deallocation.
// SN: stwu/mflr/stw/bl AptNonGCFreeSavedSize/lwz/mtlr/addi/blr
// ============================================================================
void AptCharacterTextInst::operator delete[](void* ptr) {
    AptNonGCFreeSavedSize(ptr);
}
