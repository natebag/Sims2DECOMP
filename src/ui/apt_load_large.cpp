// apt_load_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptLoad.cpp.obj
// 6 functions, 2424 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// AptLoader::Invalidate(AptFile *) - 0x8029E474 | 260 bytes
// ============================================================================
// NON_MATCHING
void AptLoader__Invalidate(void* self, void* p1) {
    // Stack: 40 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptLoader::Load(EAStringC &) - 0x8029E69C | 324 bytes
// ============================================================================
// NON_MATCHING
void AptLoader__Load(void* self, void* p1) {
    // Stack: 48 bytes
    // -> AptLoader::findFile(EAStringC &)
    // -> AptSharedPtrIncRef(AptFile *)
    // -> AptSharedPtrDecRef(AptFile *)
    // -> AptSharedPtrDelete(AptFile *)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> EAStringC::EAStringC(EAStringC &)
    // Accesses globals via r13 (SDA)

    // Load/parse data
}

// ============================================================================
// AptLoader::AllImportsAvailable(AptSharedPtr<AptFile>) - 0x8029E7E0 | 288 bytes
// ============================================================================
// NON_MATCHING
void AptLoader__AllImportsAvailable(void* self, void* p1) {
    // Stack: 48 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> AptLoader::IsLoaded(EAStringC &)
    // -> AptSharedPtrDecRef(AptFile *)
    // -> AptSharedPtrDelete(AptFile *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptLoader::Update(void) - 0x8029E900 | 404 bytes
// ============================================================================
// NON_MATCHING
void AptLoader__Update(void* self) {
    // Stack: 56 bytes
    // -> AptSharedPtrIncRef(AptFile *)
    // -> AptLoader::AllImportsAvailable(AptSharedPtr<AptFile>)
    // -> AptCharacterAnimation::Link(AptCharacter *, void *)
    // -> AptLoader::notify(AptSharedPtr<AptFile>)
    // -> AptSharedPtrDecRef(AptFile *)
    // -> AptSharedPtrDelete(AptFile *)
    // Contains loop(s)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// AptLoader::CancelPreloadedAnimation(EAStringC &) - 0x8029EB60 | 788 bytes
// ============================================================================
// NON_MATCHING
int AptLoader__CancelPreloadedAnimation(void* self, void* p1) {
    // Stack: 88 bytes
    // -> AptLoader::findFile(EAStringC &)
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptSharedPtrIncRef(AptFile *)
    // -> AptFile::GetMainCharacter(void) const
    // -> EAStringC::EAStringC(char *)
    // ... and 5 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    return 0;
}

// ============================================================================
// AptLinker::CancelLoad(AptCIH *) - 0x802A0E80 | 360 bytes
// ============================================================================
// NON_MATCHING
int AptLinker__CancelLoad(void* self, void* p1) {
    // Stack: 48 bytes
    // -> AptSharedPtrDecRef(AptLinkerThingy *)
    // -> AptSharedPtrDelete(AptLinkerThingy *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Load/parse data
}
