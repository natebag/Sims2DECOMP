// apt_movie_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptMovie.cpp.obj
// 4 functions, 2688 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// AptMovie::resolve(unsigned char *, AptConstFile *, int *) - 0x802A8C44 | 900 bytes
// ============================================================================
// NON_MATCHING
void AptMovie__resolve(void* self, char* p1, void* p2, int p3) {
    // Stack: 64 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptNativeHash::AptNativeHash(int)
    // -> AptActionInterpreter::resolveStream(unsigned char *, unsigned char *, AptConstFile *, int *)
    // -> EAStringC::InitFromBuffer(char *)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptMovie::unresolve(unsigned char *, int *) - 0x802A8FC8 | 700 bytes
// ============================================================================
// NON_MATCHING
void AptMovie__unresolve(void* self, char* p1, int p2) {
    // Stack: 48 bytes
    // -> AptActionInterpreter::unresolveStream(unsigned char *, unsigned char *, int *)
    // -> AptNativeHash::DestroyGCPointers(void)
    // -> AptNativeHash::~AptNativeHash(void)
    // Contains loop(s)

}

// ============================================================================
// AptMovie::DoTemporaryFrameControls(AptPseudoDisplayList *, int) - 0x802A9284 | 552 bytes
// ============================================================================
// NON_MATCHING
void AptMovie__DoTemporaryFrameControls(void* self, void* p1, int p2) {
    // Stack: 56 bytes
    // -> AptPseudoDisplayList::FindInst(int, AptPseudoCIH_t **, AptPseudoCIH_t **)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptPseudoCIH_t::AptPseudoCIH_t(AptControl *, int, int, AptCharacter *)
    // -> AptPseudoDisplayList::Insert(AptPseudoCIH_t *)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptMovie::doFrameControls(AptDisplayList *, AptCIH *, int) - 0x802A94AC | 536 bytes
// ============================================================================
// NON_MATCHING
void AptMovie__doFrameControls(void* self, void* p1, void* p2, int p3) {
    // Stack: 64 bytes
    // -> AptActionInterpreter::PrepareForExecution(AptActionSetup *)
    // -> AptCIH::getRootAnimation(void)
    // -> AptActionInterpreter::runStream(unsigned char *, AptCIH *, int, AptCharacterInst *)
    // -> AptActionInterpreter::CleanupAfterExecution(void *, AptActionSetup *)
    // -> AptCharacterAnimation::ExecuteInitActions(AptCIH *, int)
    // -> AptDisplayList::placeObject(AptControlPlaceObject2 *, AptCIH *)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}
