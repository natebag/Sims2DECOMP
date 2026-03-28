// apt_input_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptInput.cpp.obj
// 8 functions, 3892 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// _getButtonScore(AptInputType, int, int, int, int) - 0x8029CA14 | 364 bytes
// ============================================================================
// NON_MATCHING
void _getButtonScore(void* p1, int p2, int p3, int p4, int p5) {
    // Stack: 16 bytes
    // Uses floating point

}

// ============================================================================
// _getBestButton(AptInputType, AptCIH *, AptCIH *) - 0x8029CB80 | 588 bytes
// ============================================================================
// NON_MATCHING
void _getBestButton(void* p1, void* p2, void* p3) {
    // Stack: 96 bytes
    // -> _getCharacterGridPosition(EAStringC &, int *, int *)
    // -> AptNativeHash::GetFirstItem(void)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptAnimationPoolData::isInputMasked(AptCIH *)
    // -> _getButtonScore(AptInputType, int, int, int, int)
    // ... and 1 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptAnimationPoolData::_doButtonActions(AptCIH *, int) - 0x8029CE2C | 472 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData___doButtonActions(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> AptAnimationPoolData::GetActionPool(void)
    // -> AptActionQueueC::AddActionBack(AptActionBlock *, AptCIH *, unsigned int)
    // -> _ActionConditionFlagToActionEventFlags(int)
    // -> AptCIH::getNativeHash(void) const
    // -> AptNativeHash::Lookup(EAStringC *) const
    // -> AptActionQueueC::AddFunctionFront(AptCIH *, AptValue *, int, unsigned int)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptAnimationPoolData::setValidFocusButton(void) - 0x8029D004 | 412 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__setValidFocusButton(void* self) {
    // Stack: 48 bytes
    // -> _getCharacterGridPosition(EAStringC &, int *, int *)
    // -> AptCIH::gotoState(AptCharacterButtonRecordState)
    // -> AptAnimationPoolData::_doButtonActions(AptCIH *, int)
    // Contains loop(s)

}

// ============================================================================
// AptAnimationPoolData::_isPointInButtonHitTestRegion(AptCharacterButton *, AptMatrix *, int, int) - 0x8029D290 | 408 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData___isPointInButtonHitTestRegion(void* self, void* p1, void* p2, int p3, int p4) {
    // Stack: 144 bytes
    // -> _matrix_vecMult(float *, AptMatrix *, float *)
    // -> _pointInTri(float *, float, float)
    // Contains loop(s)
    // Uses floating point

}

// ============================================================================
// AptAnimationPoolData::ProcessInputSet(AptInputType, AptInputState, unsigned int, AptInputController, bool) - 0x8029D428 | 640 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__ProcessInputSet(void* self, void* p1, void* p2, int p3, void* p4, int p5) {
    // Stack: 64 bytes
    // -> AptAnimationPoolData::isInputMasked(AptCIH *)
    // -> AptCIH::queueClipEvents(int, unsigned int, int)
    // -> AptAnimationPoolData::GetActionPool(void)
    // -> AptActionQueueC::AddActionBack(AptActionBlock *, AptCIH *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// AptAnimationPoolData::AddListenerToQueue(AptValue *, int, unsigned int) - 0x8029D838 | 580 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__AddListenerToQueue(void* self, void* p1, int p2, int p3) {
    // Stack: 56 bytes
    // -> AptCIH::HasEvent(int)
    // -> AptValue::findChild(EAStringC *, AptValue *)
    // -> AptCIH::decZombieCount(void)
    // -> AptAnimationPoolData::GetActionPool(void)
    // -> AptActionQueueC::AddFunctionBack(AptCIH *, AptValue *, int, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Add element
}

// ============================================================================
// AptAnimationPoolData::HandleAutoNav(AptCIH *, AptInputType, AptInputState) - 0x8029DFA4 | 428 bytes
// ============================================================================
// NON_MATCHING
void AptAnimationPoolData__HandleAutoNav(void* self, void* p1, void* p2, void* p3) {
    // Stack: 32 bytes
    // -> AptAnimationPoolData::setValidFocusButton(void)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> _getBestButton(AptInputType, AptCIH *, AptCIH *)
    // -> AptCIH::gotoState(AptCharacterButtonRecordState)
    // -> AptAnimationPoolData::_doButtonActions(AptCIH *, int)

    // Process/handle event
}
