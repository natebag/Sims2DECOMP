// apt_display_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptDisplayList.cpp.obj
// 14 functions, 7384 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// AptDisplayListState::findInst(int, EAStringC *, AptCIH **, AptCIH **) - 0x80299340 | 272 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayListState__findInst(void* self, int p1, void* p2, void* p3, void* p4) {
    // Stack: 40 bytes
    // -> memcmp
    // Contains loop(s)

}

// ============================================================================
// AptDisplayListState::insert(int, AptVirtualFunctionTable_Indices, AptCharacterInst *, AptCIH *, AptCIH *) - 0x80299600 | 288 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayListState__insert(void* self, int p1, void* p2, void* p3, void* p4, void* p5) {
    // Stack: 40 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices, AptValue::CIH_ONLY)
    // -> EAStringC::EAStringC(void)
    // -> AptValue::setGCRoot(unsigned int)
    // -> AptDisplayListState::insert(AptCIH *, AptCIH *)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDisplayListState::insert(int, AptVirtualFunctionTable_Indices, AptCharacterInst *) - 0x80299720 | 316 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayListState__insert(void* self, int p1, void* p2, void* p3) {
    // Stack: 48 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices, AptValue::CIH_ONLY)
    // -> EAStringC::EAStringC(void)
    // -> AptValue::setGCRoot(unsigned int)
    // -> AptDisplayListState::findInst(int, EAStringC *, AptCIH **, AptCIH **)
    // -> AptDisplayListState::insert(AptCIH *, AptCIH *)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// _convertToCXForm(AptCXForm *, AptnCXForm *) - 0x8029A1A4 | 320 bytes
// ============================================================================
// NON_MATCHING
void _convertToCXForm(void* p1, void* p2) {
    // Stack: 24 bytes
    // Uses floating point

}

// ============================================================================
// AptDisplayList::_addToSetCaches(AptCIH *, int) - 0x8029A3A8 | 776 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayList___addToSetCaches(void* self, void* p1, int p2) {
    // Stack: 24 bytes
    // -> AptCIH::queueClipEvents(int, unsigned int, int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// AptDisplayList::placeObject(AptCIH *, int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptCXForm *, AptMatrix *, AptEventActionSet *, float, AptValue *) - 0x8029A6B0 | 816 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayList__placeObject(void* self, void* p1, int p2, void* p3, void* p4, void* p5, int p6, int p7, void* p8, void* p9, void* p10, float p11, void* p12) {
    // Stack: 64 bytes
    // -> AptDisplayList::instantiateCharacter(int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptCIH **, int *)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptDisplayList::_addToSetCaches(AptCIH *, int)
    // -> AptNativeHash::GetFirstItem(void)
    // -> memcmp
    // ... and 3 more calls
    // Contains loop(s)
    // Uses floating point

}

// ============================================================================
// AptDisplayList::placeObject(AptControlPlaceObject2 *, AptCIH *) - 0x8029A9E0 | 724 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayList__placeObject_CPO2(void* self, void* p1, void* p2) {
    // Stack: 80 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptDisplayListState::findInst(int, EAStringC *, AptCIH **, AptCIH **)
    // -> AptDisplayList::placeObjectNCXForm(AptCIH *, int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptnCXForm *, AptMatrix *, AptEventActionSet *, float)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDisplayList::placeObject(AptPseudoCIH_t *, AptCIH *) - 0x8029ACB4 | 356 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayList__placeObject_Pseudo(void* self, void* p1, void* p2) {
    // Stack: 56 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptDisplayList::placeObjectNCXForm(AptCIH *, int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptnCXForm *, AptMatrix *, AptEventActionSet *, float)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// _drawCharacterInstOpti(AptRenderingContext *, AptCIH *, AptMaskRenderOperation) - 0x8029B0D4 | 892 bytes
// ============================================================================
// NON_MATCHING
void _drawCharacterInstOpti(void* p1, void* p2, void* p3) {
    // Stack: 176 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptCIH::ensureStringAllocated(AptCIH *)
    // -> AptCIH::render(AptRenderingContext *, AptMath::ClipTransform_t *, AptMaskRenderOperation)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDisplayList::render(AptRenderingContext *, AptMaskRenderOperation) - 0x8029B4A4 | 628 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayList__render(void* self, void* p1, void* p2) {
    // Stack: 168 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDisplayList::clear(bool) - 0x8029B89C | 260 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayList__clear(void* self, int p1) {
    // Stack: 40 bytes
    // -> AptDisplayList::removeObject(AptCIH *)
    // -> AptCIH::ClearCIH(bool)
    // -> AptValueVector::ReleaseValues(void)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDisplayList::mergeState(AptPseudoDisplayList *, AptNativeHash *, bool) - 0x8029BBE0 | 952 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayList__mergeState(void* self, void* p1, void* p2, int p3) {
    // Stack: 40 bytes
    // -> AptDisplayList::AddToDisplayList(AptNativeHash *, AptPseudoCIH_t *, AptCIH *)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> _convertToCXForm(AptCXForm *, AptnCXForm *)
    // -> AptDisplayList::ReplaceDisplyListItem(AptNativeHash *, AptCIH *, AptPseudoCIH_t *, AptCIH *)
    // -> AptDisplayList::RemoveFromDisplayList(AptNativeHash *, AptCIH *)
    // Contains loop(s)

}

// ============================================================================
// AptDisplayList::validate(AptCIH *) - 0x8029BF98 | 404 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayList__validate(void* self, void* p1) {
    // Stack: 32 bytes
    // -> AptNativeHash::GetFirstItem(void)
    // -> memcmp
    // -> AptNativeHash::GetNextItem(AptHashItem *)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptDisplayList::validate(AptCIH *)
    // Contains loop(s)

}

// ============================================================================
// AptDisplayListState::AptDisplayListState(void) - 0x8029C1D0 | 380 bytes
// ============================================================================
// NON_MATCHING
void AptDisplayListState__AptDisplayListState(void* self) {
    // Stack: 32 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices, AptValue::CIH_ONLY)
    // -> EAStringC::EAStringC(void)
    // -> AptValue::setGCRoot(unsigned int)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Initialize members
    // Object size >= 0x769C
}
