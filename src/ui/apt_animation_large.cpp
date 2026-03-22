// apt_animation_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptAnimation.cpp.obj
// 13 functions, 7160 bytes

#include "types.h"

// ============================================================================
// AptCharacterAnimation::Link(AptCharacter *, void *) - 0x80283024 | 720 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterAnimation__Link(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// AptAnimationPoolData::AptAnimationPoolData(AptInitParmsT &) - 0x802832F4 | 548 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__AptAnimationPoolData(void* self, void* p1) {
    // Stack: 40 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> memset
    // -> AptDisplayList::AptDisplayList(void)
    // -> AptNonGCAllocSaveSize(unsigned int)
    // -> AptActionQueueC::ClearActions(void)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Initialize members
    // Object size >= 0x59EC
}

// ============================================================================
// AptAnimationPoolData::~AptAnimationPoolData(void) - 0x80283518 | 688 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__dtor_AptAnimationPoolData(void* self) {
    // Stack: 48 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptIntervalTimer::cleanParams(void)
    // -> AptNonGCFreeSavedSize(void *)
    // -> AptActionQueueC::operator delete(void *, unsigned int)
    // -> AptDisplayList::~AptDisplayList(void)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Release resources
    // AptNonGCFreeSavedSize(void *) called for cleanup
    // AptActionQueueC::operator delete(void *, unsigned int) called for cleanup
    // Destroy members
}

// ============================================================================
// AptAnimationPoolData::PreDestroy(void) - 0x802837C8 | 704 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__PreDestroy(void* self) {
    // Stack: 56 bytes
    // -> AptAnimationPoolData::clearBIL(void)
    // -> AptDisplayList::PreDestroy(void)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Tear down subsystem
}

// ============================================================================
// AptAnimationPoolData::tickIntervalTimers(int) - 0x80283AC8 | 932 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__tickIntervalTimers(void* self, int p1) {
    // Stack: 120 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptActionInterpreter::PrepareForExecution(AptActionSetup *)
    // -> AptActionInterpreter::callFunction(AptValue *, AptValue *, int)
    // -> AptActionInterpreter::CleanupAfterExecution(void *, AptActionSetup *)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptAnimationPoolData::_tickNewInsts(void) - 0x80283E6C | 308 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData___tickNewInsts(void* self) {
    // Stack: 32 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptCIH::gotoState(AptCharacterButtonRecordState)
    // -> AptCIH::tick(void)
    // Contains loop(s)

}

// ============================================================================
// AptAnimationPoolData::runActions(void) - 0x80283FA0 | 800 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__runActions(void* self) {
    // Stack: 72 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptActionInterpreter::PrepareForExecution(AptActionSetup *)
    // -> AptCIH::getRootAnimation(void)
    // -> AptActionInterpreter::runStream(unsigned char *, AptCIH *, int, AptCharacterInst *)
    // -> AptActionInterpreter::CleanupAfterExecution(void *, AptActionSetup *)
    // ... and 4 more calls
    // Contains loop(s)

}

// ============================================================================
// AptAnimationPoolData::removeTimerFunctions(AptCIH *) - 0x80284410 | 396 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__removeTimerFunctions(void* self, void* p1) {
    // Stack: 48 bytes
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterAnimation::ExecuteInitActions(AptCIH *, int) - 0x80284880 | 288 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterAnimation__ExecuteInitActions(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> AptCharacterAnimation::IsImport(int)
    // -> AptCharacterAnimation::GetIDFromImportFile(int)
    // -> AptCharacterAnimation::ExecuteInitAction(AptCIH *, int)
    // Contains loop(s)

    // Initialize subsystem
}

// ============================================================================
// AptCharacterAnimation::ExecuteInitAction(AptCIH *, int) - 0x802849A0 | 276 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterAnimation__ExecuteInitAction(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> AptCharacterAnimation::ExportClassDefinitionAssets(AptCIH *)
    // -> AptActionInterpreter::PrepareForExecution(AptActionSetup *)
    // -> AptCIH::getRootAnimation(void)
    // -> AptActionInterpreter::runStream(unsigned char *, AptCIH *, int, AptCharacterInst *)
    // -> AptActionInterpreter::CleanupAfterExecution(void *, AptActionSetup *)
    // Contains loop(s)

    // Initialize subsystem
}

// ============================================================================
// AptCharacterAnimation::ExportClassDefinitionAssets(AptCIH *) - 0x80284AB4 | 376 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterAnimation__ExportClassDefinitionAssets(void* self, void* p1) {
    // Stack: 56 bytes
    // -> strstr
    // -> AptActionInterpreter::PrepareForExecution(AptActionSetup *)
    // -> AptCIH::getRootAnimation(void)
    // -> AptActionInterpreter::runStream(unsigned char *, AptCIH *, int, AptCharacterInst *)
    // -> AptActionInterpreter::CleanupAfterExecution(void *, AptActionSetup *)
    // Contains loop(s)

}

// ============================================================================
// AptAnimationPoolData::RegisterReferences(void) - 0x80284C2C | 684 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__RegisterReferences(void* self) {
    // Stack: 40 bytes
    // -> AptDisplayListState::RegisterReferences(AptValue *) const
    // -> AptActionQueueC::RegisterReferences(void)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionQueueC::RemoveActionFor(AptCIH *) - 0x80285340 | 440 bytes
// ============================================================================
// NON_MATCHING
void AptActionQueueC__RemoveActionFor(void* self, void* p1) {
    // Stack: 32 bytes
    // -> memmove
    // -> AptActionQueueC::IncrementDequeLocation(AptActionQueueC::AptActionPool *)
    // Contains loop(s)

    // Remove element
}
