// apt_cih_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptCIH.cpp.obj
// 10 functions, 4796 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// AptCIH::Remove(void) - 0x8028FEC8 | 292 bytes
// ============================================================================
// NON_MATCHING
void AptCIH__Remove(void* self) {
    // Stack: 16 bytes
    // -> AptLinker::CancelLoad(AptCIH *)
    // -> AptCIH::ClearCIH(bool)
    // -> AptActionQueueC::RemoveActionFor(AptCIH *)
    // -> AptAnimationPoolData::removeFromBIL(AptCIH *)
    // -> AptDisplayListState::remove(AptCIH *)
    // Accesses globals via r13 (SDA)

    // Remove element
}

// ============================================================================
// AptCIH::ensureStringAllocated(AptCIH *) - 0x80290824 | 820 bytes
// ============================================================================
// NON_MATCHING
void AptCIH__ensureStringAllocated(void* self, void* p1) {
    // Stack: 136 bytes
    // -> AptCharacterTextInst::UpdateText(AptCIH *)
    // -> AptCIH::setProceduralProperty(AptProceduralProperty, float, bool)
    // Uses floating point

}

// ============================================================================
// AptCIH::deallocAssetStringRecursive(void) - 0x80290B58 | 264 bytes
// ============================================================================
// NON_MATCHING
void AptCIH__deallocAssetStringRecursive(void* self) {
    // Stack: 24 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptDisplayList::deallocAssetStringRecursive(void)

}

// ============================================================================
// AptCIH::_getBoundingRect(AptRenderingContext *, AptRect *) - 0x80291390 | 448 bytes
// ============================================================================
// NON_MATCHING
void AptCIH___getBoundingRect(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptRenderingContext::pushVertexMatrix(void)
    // -> AptRenderingContext::appendVertexMatrix(AptMatrix *)
    // -> AptDisplayList::_getBoundingRect(AptRenderingContext *, AptRect *)
    // -> AptRenderingContext::expandBoundingRect(AptRect *, AptRect *)
    // ... and 2 more calls

}

// ============================================================================
// AptCIH::GetProceduralProperty(AptProceduralProperty) - 0x80291760 | 976 bytes
// ============================================================================
// NON_MATCHING
void* AptCIH__GetProceduralProperty(void* self, void* p1) {
    // Stack: 40 bytes
    // -> AptCIH::getBoundingRect(AptRect *)
    // -> AptCIH::GetVectorLength(AptMatrix *)
    // -> acosf
    // Contains loop(s)
    // Uses floating point

    // Getter
    return 0;
}

// ============================================================================
// AptCIH::jumpToFrame(int) - 0x80292994 | 452 bytes
// ============================================================================
// NON_MATCHING
void AptCIH__jumpToFrame(void* self, int p1) {
    // Stack: 40 bytes
    // -> AptMovie::doFrameControls(AptDisplayList *, AptCIH *, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptPseudoCIH_t::AptPseudoCIH_t(AptControl *, int, int, AptCharacter *)
    // -> AptMovie::DoTemporaryFrameControls(AptPseudoDisplayList *, int)
    // -> AptDisplayList::mergeState(AptPseudoDisplayList *, AptNativeHash *, bool)
    // -> AptPseudoDisplayList::ClearList(void)
    // ... and 4 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCIH::tick(void) - 0x80293128 | 544 bytes
// ============================================================================
// NON_MATCHING
void AptCIH__tick(void* self) {
    // Stack: 24 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptCIH::jumpToFrame(int)
    // -> AptMovie::doFrameControls(AptDisplayList *, AptCIH *, int)
    // -> AptMovie::queueFrameActions(AptCIH *, int)
    // -> AptCIH::HasEvent(int)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCIH::hasRenderData(void) - 0x802935F0 | 348 bytes
// ============================================================================
// NON_MATCHING
void AptCIH__hasRenderData(void* self) {
    // Stack: 24 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptDisplayList::getState(void)
    // -> AptDisplayListState::hasRenderData(void)

    // Render pass
}

// ============================================================================
// AptCIH::GetMovieclipInfo(AptMovieclipInformation *) - 0x8029374C | 364 bytes
// ============================================================================
// NON_MATCHING
void* AptCIH__GetMovieclipInfo(void* self, void* p1) {
    // Stack: 24 bytes
    // -> AptDisplayList::getState(void)
    // -> AptDisplayListState::GetMovieclipInfo(AptMovieclipInformation *)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const

    // Getter
    return 0;
}

// ============================================================================
// AptCIH::AptCIH(AptVirtualFunctionTable_Indices, AptCharacterInst *, AptCIH *) - 0x802939E8 | 288 bytes
// ============================================================================
// NON_MATCHING
void AptCIH__AptCIH(void* self, void* p1, void* p2, void* p3) {
    // Stack: 24 bytes
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices, AptValue::CIH_ONLY)
    // -> EAStringC::EAStringC(void)
    // -> AptValue::setGCRoot(unsigned int)
    // Uses floating point

    // Initialize members
    // Object size >= 0x5C9C
}
