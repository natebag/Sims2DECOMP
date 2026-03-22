// apt_misc_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: Apt.cpp.obj
// 13 functions, 6296 bytes

#include "types.h"

// ============================================================================
// AptMemoryAllocationsT::operator+(AptMemoryAllocationsT &) - 0x80268714 | 288 bytes
// ============================================================================
// NON_MATCHING
void AptMemoryAllocationsT__operator(void* self, void* p1) {
    // Stack: 72 bytes
    // Contains loop(s)

}

// ============================================================================
// AptInitialize(AptInitParmsT *, bool) - 0x80268998 | 688 bytes
// ============================================================================
// NON_MATCHING
void AptInitialize(void* p1, int p2) {
    // Stack: 96 bytes
    // -> AptInitializeGC(void)
    // -> StringPool::Initialize(int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValueVector::AptValueVector(int)
    // -> AptValueInitialize(void)
    // -> AptActionInterpreter::initialize(AptInitParmsT &)
    // ... and 4 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Initialize subsystem
    // Sets up global state
}

// ============================================================================
// AptReset(void) - 0x80268C48 | 400 bytes
// ============================================================================
// NON_MATCHING
void AptReset(void) {
    // Stack: 24 bytes
    // -> AptScriptFunctionBase::ShutdownStaticData(void)
    // -> AptAnimationPoolData::PreDestroy(void)
    // -> AptUpdateZombieVector(bool)
    // -> AptLoader::~AptLoader(void)
    // -> AptLinker::~AptLinker(void)
    // -> AptSavedInputCheckpoints::~AptSavedInputCheckpoints(void)
    // ... and 11 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Reset state to defaults
}

// ============================================================================
// AptShutdown(int) - 0x80268DD8 | 352 bytes
// ============================================================================
// NON_MATCHING
void AptShutdown(int p1) {
    // Stack: 16 bytes
    // -> AptMath::ClipStackShutdown(void)
    // -> AptAnimationPoolData::PreDestroy(void)
    // -> AptUpdateZombieVector(bool)
    // -> AptLoader::~AptLoader(void)
    // -> AptLinker::~AptLinker(void)
    // -> AptSavedInputCheckpoints::~AptSavedInputCheckpoints(void)
    // ... and 14 more calls
    // Accesses globals via r13 (SDA)

    // Tear down subsystem
}

// ============================================================================
// _AptGetAnimationAtLevel(int) - 0x80269180 | 352 bytes
// ============================================================================
// NON_MATCHING
void _AptGetAnimationAtLevel(int p1) {
    // Stack: 24 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices, AptValue::CIH_ONLY)
    // -> EAStringC::EAStringC(void)
    // -> AptValue::setGCRoot(unsigned int)
    // -> AptDisplayListState::insert(int, AptCIH *)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Getter
}

// ============================================================================
// _tick(unsigned int) - 0x80269718 | 400 bytes
// ============================================================================
// NON_MATCHING
void _tick(int p1) {
    // Stack: 32 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptAnimationPoolData::tickIntervalTimers(int)
    // -> AptDisplayList::tick(void)
    // -> AptAnimationPoolData::runActions(void)
    // -> AptAnimationPoolData::ProcessInputs(void)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// _AptInternalUpdate(unsigned int) - 0x8026A86C | 492 bytes
// ============================================================================
// NON_MATCHING
void _AptInternalUpdate(int p1) {
    // Stack: 440 bytes
    // -> AptSharedPtrIncRef(AptFile *)
    // -> AptSharedPtrDecRef(AptFile *)
    // -> AptSharedPtrDelete(AptFile *)
    // -> _playbackSavedInputs(unsigned int)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // ... and 5 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// AptSetInternalVariable(char *, char *) - 0x8026ABBC | 416 bytes
// ============================================================================
// NON_MATCHING
void AptSetInternalVariable(char* p1, char* p2) {
    // Stack: 48 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::EAStringC(char *)
    // -> EAStringC::operator=(EAStringC &)
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// AptCallFunction(char *, char *, char *, int,...) - 0x8026AE4C | 1016 bytes
// ============================================================================
// NON_MATCHING
void AptCallFunction(char* p1, char* p2, char* p3, int p4) {
    // Stack: 344 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> _AptGetAnimationAtLevel(int)
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // ... and 9 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCallFunctionOpti(char *, char *, char *, int,...) - 0x8026B244 | 812 bytes
// ============================================================================
// NON_MATCHING
void AptCallFunctionOpti(char* p1, char* p2, char* p3, int p4) {
    // Stack: 336 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> _AptGetAnimationAtLevel(int)
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptScriptFunctionBase::PushStaticData(void)
    // -> AptActionInterpreter::callFunction(AptValue *, AptValue *, int)
    // ... and 2 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptSetInputRoot(char *) - 0x8026B570 | 272 bytes
// ============================================================================
// NON_MATCHING
void AptSetInputRoot(char* p1) {
    // Stack: 24 bytes
    // -> AptAnimationPoolData::setInputMask(AptCIH *)
    // -> EAStringC::InitFromBuffer(char *)
    // -> _AptGetAnimationAtLevel(int)
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// AptUpdateZombieVector(bool) - 0x8026BAB4 | 488 bytes
// ============================================================================
// NON_MATCHING
void AptUpdateZombieVector(int p1) {
    // Stack: 56 bytes
    // -> memmove
    // -> AptSharedPtrDecRef(AptFile *)
    // -> AptSharedPtrDelete(AptFile *)
    // -> AptSharedPtrIncRef(AptFile *)
    // -> AptPartialGarbageCollection(void)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// AptLinker::~AptLinker(void) - 0x8026BF54 | 320 bytes
// ============================================================================
// NON_MATCHING
void AptLinker__dtor_AptLinker(void* self) {
    // Stack: 32 bytes
    // -> AptNonGCAllocSaveSize(unsigned int)
    // -> AptSharedPtrDecRef(AptFile *)
    // -> AptSharedPtrDelete(AptFile *)
    // -> AptNonGCFreeSavedSize(void *)
    // -> AptSharedPtrDecRef(AptLinkerThingy *)
    // -> AptSharedPtrDelete(AptLinkerThingy *)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Release resources
    // AptSharedPtrDelete(AptFile *) called for cleanup
    // AptNonGCFreeSavedSize(void *) called for cleanup
    // AptSharedPtrDelete(AptLinkerThingy *) called for cleanup
    // Destroy members
}
