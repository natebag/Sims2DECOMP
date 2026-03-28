// AptCharacterInstButton.cpp - APT button character instance
// Source: libaptz.a(AptCharacterInstButton.cpp.obj)
// 7 small functions (<=64 bytes) decompiled
//
// All NON_MATCHING due to SN Systems vs GCC codegen differences.

#include "ui/apt_character_button.h"
#include "ui/apt_types.h"

// External functions
extern void AptDisplayList_PreDestroy(void* displayList);  // AptDisplayList::PreDestroy at 0x8029b9a0
extern void AptNativeHash_DestroyGCPointers_ext(void* hash);  // AptNativeHash::DestroyGCPointers at 0x802a99d0

// External globals
extern DOGMA_PoolManager* gpNonGCPoolManager;

// ============================================================================
// AptCharacterButtonInst::PreDestroy (0x802c4a88, 36 bytes) NON_MATCHING
// Original:
//   stwu r1,-8(r1) / mflr r0 / stw r0,12(r1)
//   addi r3,r3,28    ; this + 0x1C = embedded AptDisplayList
//   bl AptDisplayList::PreDestroy
//   epilogue
// Delegates to the embedded AptDisplayList at offset 0x1C.
// ============================================================================
void AptCharacterButtonInst::PreDestroy() {
    AptDisplayList_PreDestroy((u8*)this + 0x1C);
}

// ============================================================================
// AptCharacterInst::DestroyGCPointers (0x802c4aac, 64 bytes) NON_MATCHING
// Original:
//   stwu r1,-16(r1) / mflr r0 / stw r31,12(r1) / stw r0,20(r1)
//   mr r31,r3
//   lwz r3,12(r31)       ; load m_nativeHash at offset 0x0C
//   cmpwi r3,0
//   beq skip
//   bl AptNativeHash::DestroyGCPointers
// skip:
//   li r0,1
//   stw r0,16(r31)       ; set m_gcFlag at offset 0x10 to 1
//   epilogue
// ============================================================================
void AptCharacterInst::DestroyGCPointers() {
    void* hash = *(void**)((u8*)this + 0x0C);
    if (hash != 0) {
        AptNativeHash_DestroyGCPointers_ext(hash);
    }
    *(u32*)((u8*)this + 0x10) = 1;
}

// ============================================================================
// AptCharacterButtonInst::operator new (0x802c4bcc, 40 bytes) NON_MATCHING
// Original:
//   mr r4,r3 / lwz r3,-23020(r13) (gpNonGCPoolManager)
//   bl DOGMA_PoolManager::Allocate
// ============================================================================
void* AptCharacterButtonInst::operator new(unsigned int size) {
    return gpNonGCPoolManager->Allocate(size);
}

// ============================================================================
// AptCharacterButtonInst::operator delete (0x802c4bf4, 48 bytes) NON_MATCHING
// Original:
//   mr r0,r3 / mr r5,r4
//   lwz r3,-23020(r13) (gpNonGCPoolManager) / mr r4,r0
//   bl DOGMA_PoolManager::Deallocate
// ============================================================================
void AptCharacterButtonInst::operator delete(void* ptr, unsigned int size) {
    gpNonGCPoolManager->Deallocate(ptr, size);
}

// ============================================================================
// AptCharacterButtonInst::operator new[] (0x802c4c24, 32 bytes) NON_MATCHING
// Original:
//   bl AptNonGCAllocSaveSize
// Delegates to global non-GC allocator with saved size.
// ============================================================================
extern void* AptNonGCAllocSaveSize(unsigned int size);

void* AptCharacterButtonInst::operator new[](unsigned int size) {
    return AptNonGCAllocSaveSize(size);
}

// ============================================================================
// AptCharacterButtonInst::operator delete[] (0x802c4c44, 32 bytes) NON_MATCHING
// Original:
//   bl AptNonGCFreeSavedSize
// Delegates to global non-GC free with saved size.
// ============================================================================
extern void AptNonGCFreeSavedSize(void* ptr);

void AptCharacterButtonInst::operator delete[](void* ptr) {
    AptNonGCFreeSavedSize(ptr);
}

// ============================================================================
// AptCharacterInst::PreDestroy (0x802c4c64, 4 bytes) MATCHING
// Original: blr (empty function)
// ============================================================================
void AptCharacterInst::PreDestroy() {
    // Empty - no-op
}
