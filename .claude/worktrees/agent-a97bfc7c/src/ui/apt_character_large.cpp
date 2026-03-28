// apt_character_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptCharacter.cpp.obj
// 18 functions, 10676 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// TextMembersIndex::in_word_set(char *, unsigned int) - 0x80287F68 | 296 bytes
// ============================================================================
// NON_MATCHING
void TextMembersIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 272 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// AptCharacterSpriteInstBase::AptCharacterSpriteInstBase(void) - 0x802881B8 | 320 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterSpriteInstBase__AptCharacterSpriteInstBase(void* self) {
    // Stack: 24 bytes
    // -> AptDisplayList::AptDisplayList(void)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptNativeHash::AptNativeHash(int)
    // -> AptNativeHash::Lookup(EAStringC *) const
    // Accesses globals via r13 (SDA)

    // Initialize members
    // Object size >= 0x6974
}

// ============================================================================
// AptCharacterTextInst::SetText(AptCIH *) - 0x802883AC | 852 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterTextInst__SetText(void* self, void* p1) {
    // Stack: 40 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // ... and 5 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// AptCharacterTextInst::UpdateText(AptCIH *) - 0x80288700 | 636 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterTextInst__UpdateText(void* self, void* p1) {
    // Stack: 48 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValue::toString(EAStringC &) const
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// AptCharacterTextInst::~AptCharacterTextInst(void) - 0x80288A38 | 352 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterTextInst__dtor_AptCharacterTextInst(void* self) {
    // Stack: 24 bytes
    // -> EAStringC::~EAStringC(void)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptNativeHash::~AptNativeHash(void)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Release resources
    // Destroy members
}

// ============================================================================
// AptCharacterInst::_gotoAndX(AptValue *, int, int) - 0x80288B98 | 292 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst___gotoAndX(void* self, void* p1, int p2, int p3) {
    // Stack: 24 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptMovie::labelToFrame(EAStringC *)
    // -> AptValue::toInteger(void) const
    // -> AptCIH::jumpToFrame(int)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_attachMovie(AptValue *, int) - 0x802893E0 | 720 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_attachMovie(void* self, void* p1, int p2) {
    // Stack: 88 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> strcasecmp
    // -> AptValue::toInteger(void) const
    // -> AptDisplayList::placeObject(AptCIH *, int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptCXForm *, AptMatrix *, AptEventActionSet *, float, AptValue *)
    // -> AptAnimationPoolData::_tickNewInsts(void)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_loadMovie(AptValue *, int) - 0x802896B0 | 488 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_loadMovie(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::Delete(int, int)
    // -> AptActionInterpreter::getName(AptCIH *, EAStringC &)
    // -> AptLinker::Load(EAStringC &, EAStringC)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_createTextField(AptValue *, int) - 0x80289B00 | 820 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_createTextField(void* self, void* p1, int p2) {
    // Stack: 128 bytes
    // -> AptValue::toInteger(void) const
    // -> AptValue::toFloat(void) const
    // -> AptValue::toString(EAStringC &) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptDisplayList::placeObject(AptCIH *, int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptCXForm *, AptMatrix *, AptEventActionSet *, float, AptValue *)
    // -> AptValue::getVtblIndex(void) const
    // ... and 3 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_swapDepths(AptValue *, int) - 0x80289F18 | 812 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_swapDepths(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> AptDisplayListState::findInst(int, EAStringC *, AptCIH **, AptCIH **)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValue::toInteger(void) const
    // -> AptDisplayListState::remove(AptCIH *)
    // -> AptDisplayListState::insert(int, AptCIH *)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_getBounds(AptValue *, int) - 0x8028A318 | 916 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_getBounds(void* self, void* p1, int p2) {
    // Stack: 56 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> AptCIH::getBoundingRect(AptRect *)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_startDrag(AptValue *, int) - 0x8028A6AC | 516 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_startDrag(void* self, void* p1, int p2) {
    // Stack: 24 bytes
    // -> AptValue::toInteger(void) const
    // -> AptValue::toFloat(void) const
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_hitTest(AptValue *, int) - 0x8028A8B0 | 844 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_hitTest(void* self, void* p1, int p2) {
    // Stack: 96 bytes
    // -> AptCIH::getBoundingRect(AptRect *)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toFloat(void) const
    // -> AptValue::toInteger(void) const
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_createEmptyMovieClip(AptValue *, int) - 0x8028ABFC | 440 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_createEmptyMovieClip(void* self, void* p1, int p2) {
    // Stack: 56 bytes
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::toString(EAStringC &) const
    // -> AptDisplayList::placeObject(AptCIH *, int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptCXForm *, AptMatrix *, AptEventActionSet *, float, AptValue *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_getBytesTotal(AptValue *, int) - 0x8028B040 | 556 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_getBytesTotal(void* self, void* p1, int p2) {
    // Stack: 64 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> EAStringC::operator+=(EAStringC &)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_getBytesLoaded(AptValue *, int) - 0x8028B26C | 480 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_getBytesLoaded(void* self, void* p1, int p2) {
    // Stack: 64 bytes
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> EAStringC::operator+=(EAStringC &)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Load/parse data
}

// ============================================================================
// AptCharacterInst::sMethod_setTextFormat(AptValue *, int) - 0x8028EA8C | 712 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_setTextFormat(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> EAStringC::EAStringC(char *)
    // -> TextFormat::copyTextFormatObj(TextFormat *)
    // -> EAStringC::operator!=(char *) const
    // -> EAStringC::operator=(EAStringC &)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptCharacterInst::sMethod_localToGlobal(AptValue *, int) - 0x8028F73C | 624 bytes
// ============================================================================
// NON_MATCHING
void AptCharacterInst__sMethod_localToGlobal(void* self, void* p1, int p2) {
    // Stack: 72 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> AptNativeHash::Lookup(EAStringC *) const
    // -> AptRenderingContext::multMatrix(AptMatrix *, AptMatrix *, AptMatrix *)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // ... and 1 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}
