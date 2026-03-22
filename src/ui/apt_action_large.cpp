// apt_action_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptActionInterpreter.cpp.obj
// 91 functions, 47184 bytes

#include "types.h"

// ============================================================================
// AptActionInterpreter::loadVariables(AptValue *, AptValue *, EAStringC *) - 0x8026D454 | 620 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__loadVariables(void* self, void* p1, void* p2, void* p3) {
    // Stack: 56 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // ... and 2 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionInterpreter::getObject(AptValue *, AptValue *, EAStringC *) - 0x8026D6C0 | 316 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__getObject(void* self, void* p1, void* p2, void* p3) {
    // Stack: 40 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptActionInterpreter::getContext(AptValue *, AptValue *, EAStringC *, AptValue **, EAStringC &)
    // -> AptValue::findChild(EAStringC *, AptValue *)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionInterpreter::getContext(AptValue *, AptValue *, EAStringC *, AptValue **, EAStringC &) - 0x8026D7FC | 348 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__getContext(void* self, void* p1, void* p2, void* p3, void* p4, void* p5) {
    // Stack: 288 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptActionInterpreter::getContext(AptValue *, AptValue *, EAStringC *, AptValue **, char *)
    // -> EAStringC::InitFromBuffer(char *)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionInterpreter::getContext(AptValue *, AptValue *, EAStringC *, AptValue **, char *) - 0x8026D958 | 520 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__getContext(void* self, void* p1, void* p2, void* p3, void* p4, char* p5) {
    // Stack: 312 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> AptValue::findChild(EAStringC *, AptValue *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> strcpy
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionInterpreter::cbCallMethod_setInterval(AptValue *, int) - 0x8026E048 | 924 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__cbCallMethod_setInterval(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::findChild(EAStringC *, AptValue *)
    // -> AptValue::toFloat(void) const
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// AptActionInterpreter::cbCallMethod_clearInterval(AptValue *, int) - 0x8026E3E4 | 308 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__cbCallMethod_clearInterval(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toInteger(void) const
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// AptActionInterpreter::cbCallMethod_hitTest(AptCIH *, int) - 0x8026E518 | 388 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__cbCallMethod_hitTest(void* self, void* p1, int p2) {
    // Stack: 80 bytes
    // -> AptValue::toFloat(void) const
    // -> AptValue::toInteger(void) const
    // -> AptCIH::getBoundingRect(AptRect *)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// AptActionInterpreter::cbCallMethod_unescape(AptValue *, int) - 0x8026EB48 | 416 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__cbCallMethod_unescape(void* self, void* p1, int p2) {
    // Stack: 24 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> AptValue::toString(EAStringC &) const
    // -> _unEscape(EAStringC &)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// AptActionInterpreter::cbCallMethod_escape(AptValue *, int) - 0x8026ECE8 | 372 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__cbCallMethod_escape(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> AptValue::toString(EAStringC &) const
    // -> _escape(EAStringC &)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// _getNameString(AptCIH *, EAStringC &, NameStringType) - 0x8026F4C0 | 540 bytes
// ============================================================================
// NON_MATCHING
void _getNameString(void* p1, void* p2, void* p3) {
    // Stack: 56 bytes
    // -> sprintf
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> _getNameString(AptCIH *, EAStringC &, NameStringType)
    // -> operator+(char *, EAStringC &)
    // -> EAStringC::operator+=(EAStringC &)
    // ... and 3 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionInterpreter::getName2(AptCIH *, EAStringC &) - 0x8026F6DC | 328 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__getName2(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> _getNameString(AptCIH *, EAStringC &, NameStringType)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionInterpreter::_doCloneSprite(AptCIH *, AptValue *, AptValue *, AptValue *, int, AptValue *) - 0x8026F8DC | 628 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___doCloneSprite(void* self, void* p1, void* p2, void* p3, void* p4, int p5, void* p6) {
    // Stack: 80 bytes
    // -> AptActionInterpreter::valueToObject(AptValue *, AptValue *, AptValue *, AptValue **)
    // -> AptValue::toString(EAStringC &) const
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptDisplayList::placeObject(AptCIH *, int, AptCharacter *, EAStringC *, AptCIH *, int, int, AptCXForm *, AptMatrix *, AptEventActionSet *, float, AptValue *)
    // -> AptDisplayListState::findInst(int, EAStringC *, AptCIH **, AptCIH **)
    // ... and 2 more calls
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Copy/clone
}

// ============================================================================
// AptActionInterpreter::_doEnumerate(AptValue *, AptValue *) - 0x80271BB8 | 760 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___doEnumerate(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> AptNativeHash::GetFirstItem(void)
    // -> strcasecmp
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // ... and 3 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// _concatAsStrings(AptValue *, AptValue *) - 0x80271EB0 | 544 bytes
// ============================================================================
// NON_MATCHING
void _concatAsStrings(void* p1, void* p2) {
    // Stack: 40 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValue::toString(EAStringC &) const
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionInterpreter::runStream(unsigned char *, AptCIH *, int, AptCharacterInst *) - 0x802720D0 | 1008 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__runStream(void* self, char* p1, void* p2, int p3, void* p4) {
    // Stack: 72 bytes
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> AptValueVector::ReleaseValues(void)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// _escape(EAStringC &) - 0x802724C0 | 380 bytes
// ============================================================================
// NON_MATCHING
void _escape(void* p1) {
    // Stack: 48 bytes
    // -> memset
    // -> EAStringC::ReserveSize(unsigned int)
    // -> sprintf
    // -> EAStringC::operator+=(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// _unEscape(EAStringC &) - 0x8027269C | 344 bytes
// ============================================================================
// NON_MATCHING
void _unEscape(void* p1) {
    // Stack: 32 bytes
    // -> EAStringC::ReserveSize(unsigned int)
    // -> _escape2Char(char, char)
    // -> EAStringC::operator+=(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionInterpreter::urlDecode(char *, EAStringC &, EAStringC &) - 0x802727F4 | 324 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__urlDecode(void* self, char* p1, void* p2, void* p3) {
    // Stack: 40 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::Append(char *, unsigned int)
    // -> _unEscape(EAStringC &)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionAdd(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80272BC4 | 688 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionAdd(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toFloat(void) const
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionSubtract(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80272E74 | 688 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionSubtract(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toFloat(void) const
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionMultiply(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80273124 | 688 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionMultiply(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toFloat(void) const
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDivide(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x802733D4 | 496 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDivide(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toFloat(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionEquals(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x802735C4 | 636 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionEquals(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toFloat(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionLessThan(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80273840 | 620 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionLessThan(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toFloat(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionAnd(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80273AAC | 660 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionAnd(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toFloat(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionOr(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80273D40 | 656 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionOr(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toFloat(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionNot(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80273FD0 | 360 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionNot(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> AptValue::toBool(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionStringEquals(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80274138 | 860 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionStringEquals(void* self, void* p1, void* p2) {
    // Stack: 56 bytes
    // -> AptGetSwfVersion(void)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toString(EAStringC &) const
    // -> memcmp
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionStringLength(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80274494 | 456 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionStringLength(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionSubString(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027465C | 864 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionSubString(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptValue::toInteger(void) const
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // ... and 3 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionToInteger(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80274A60 | 404 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionToInteger(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionGetVariable(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80274BF4 | 344 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionGetVariable(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionSetVariable(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80274D4C | 332 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionSetVariable(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // -> AptValueVector::ReleaseValues(void)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionSetTarget2(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80274E98 | 380 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionSetTarget2(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> AptActionInterpreter::getObject(AptValue *, AptValue *, EAStringC *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionStringAdd(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80275014 | 508 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionStringAdd(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::EAStringC(char *)
    // ... and 3 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionGetProperty(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80275210 | 532 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionGetProperty(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptActionInterpreter::valueToObject(AptValue *, AptValue *, AptValue *, AptValue **)
    // -> AptValue::toInteger(void) const
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionSetProperty(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80275424 | 296 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionSetProperty(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptActionInterpreter::valueToObject(AptValue *, AptValue *, AptValue *, AptValue **)
    // -> AptValue::toInteger(void) const
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // Contains loop(s)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionTrace(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80275728 | 592 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionTrace(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptGetSwfVersion(void)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::EAStringC(char *)
    // ... and 7 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionStartDragMovie(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80275978 | 832 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionStartDragMovie(void* self, void* p1, void* p2) {
    // Stack: 64 bytes
    // -> AptActionInterpreter::getContext(AptValue *, AptValue *, EAStringC *, AptValue **, EAStringC &)
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValue::toFloat(void) const
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionRandom(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80275D20 | 400 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionRandom(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> AptRand(void)
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionAsciiToChar(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80275EB8 | 640 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionAsciiToChar(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> AptValue::toInteger(void) const
    // -> EAStringC::EAStringC(unsigned int, unsigned int)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDelete(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80276240 | 548 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDelete(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDelete2(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80276464 | 476 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDelete2(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDefineLocal(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80276640 | 316 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDefineLocal(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> AptScriptFunctionBase::CreateFrameStack(void)
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionCallFunction(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027677C | 576 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionCallFunction(void* self, void* p1, void* p2) {
    // Stack: 56 bytes
    // -> AptValue::toInteger(void) const
    // -> AptArray::get(int)
    // -> AptActionInterpreter::getContext(AptValue *, AptValue *, EAStringC *, AptValue **, EAStringC &)
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> AptActionInterpreter::callFunction(AptValue *, AptValue *, int)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionModulo(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x802769C8 | 504 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionModulo(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toFloat(void) const
    // -> fmodf
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionNewObject(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80276BC0 | 496 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionNewObject(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> AptValue::toInteger(void) const
    // -> AptActionInterpreter::_createObject(AptValue *, AptValue *, EAStringC *, int, bool)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDefineLocal2(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80276DB0 | 372 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDefineLocal2(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> AptNativeHash::Lookup(EAStringC *) const
    // -> AptScriptFunctionBase::CreateFrameStack(void)
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionInitArray(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80276F24 | 428 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionInitArray(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptValue::toInteger(void) const
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptArray::AptArray(void)
    // -> AptArray::set(int, AptValue *)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionInitObject(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x802770D0 | 788 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionInitObject(void* self, void* p1, void* p2) {
    // Stack: 56 bytes
    // -> AptValue::toInteger(void) const
    // -> AptActionInterpreter::_createObject(AptValue *, AptValue *, EAStringC *, int, bool)
    // -> AptValue::toString(EAStringC &) const
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionTypeOf(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x802773E4 | 1016 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionTypeOf(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionTargetPath(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x802777DC | 856 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionTargetPath(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptActionInterpreter::valueToObject(AptValue *, AptValue *, AptValue *, AptValue **)
    // -> AptActionInterpreter::getName(AptCIH *, EAStringC &)
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionToString(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027A738 | 924 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionToString(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptGetSwfVersion(void)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::EAStringC(char *)
    // ... and 4 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionSetMember(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027AFD0 | 872 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionSetMember(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptValue::toInteger(void) const
    // -> AptArray::set(int, AptValue *)
    // -> AptValue::toString(EAStringC &) const
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // -> memcmp
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionIncrement(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027B338 | 604 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionIncrement(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toFloat(void) const
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDecrement(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027B594 | 604 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDecrement(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toFloat(void) const
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionNewMethod(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027C324 | 620 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionNewMethod(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> AptValue::toInteger(void) const
    // -> AptActionInterpreter::_createObject(AptValue *, AptValue *, EAStringC *, int, bool)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionBitAnd(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027C5B8 | 460 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionBitAnd(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionBitOr(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027C784 | 460 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionBitOr(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionBitXor(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027C950 | 460 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionBitXor(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionBitLShift(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027CB1C | 460 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionBitLShift(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionBitRShift(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027CCE8 | 460 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionBitRShift(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptGetSwfVersion(void)
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionGreater(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027D43C | 924 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionGreater(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptGetSwfVersion(void)
    // -> strcmp
    // -> AptValue::toFloat(void) const
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionGetUrl(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027D8C0 | 416 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionGetUrl(void* self, void* p1, void* p2) {
    // Stack: 1072 bytes
    // -> AptActionInterpreter::isFSCommand(char *)
    // -> AptActionInterpreter::doFSCommand(char *, char *)
    // -> strcpy
    // -> strlen
    // -> EAStringC::InitFromBuffer(char *)
    // -> AptLinker::Load(EAStringC &, EAStringC)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionSetTarget(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027DAD8 | 372 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionSetTarget(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> EAStringC::TrimRight(char *)
    // -> AptActionInterpreter::getObject(AptValue *, AptValue *, EAStringC *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionWith(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027DD30 | 276 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionWith(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptActionInterpreter::valueToObject(AptValue *, AptValue *, AptValue *, AptValue **)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPush(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027DE44 | 264 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPush(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptScriptFunctionBase::GetRegisterValue(int)
    // Contains loop(s)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDefineFunction(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027E3D4 | 428 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDefineFunction(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptScriptFunction1::AptScriptFunction1(AptScriptFunctionBase *, AptAction_DefineFunction *, AptCIH *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDefineFunction2(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027E580 | 308 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDefineFunction2(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptScriptFunction2::AptScriptFunction2(AptScriptFunctionBase *, AptAction_DefineFunction2 *, AptCIH *)
    // -> EAStringC::InitFromBuffer(char *)
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionCallFrame(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027E798 | 424 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionCallFrame(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptActionInterpreter::getContext(AptValue *, AptValue *, EAStringC *, AptValue **, EAStringC &)
    // -> AptMovie::labelToFrame(EAStringC *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValue::toInteger(void) const
    // -> AptMovie::runFrameActions(AptCIH *, int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionGotoFrame2(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027E940 | 708 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionGotoFrame2(void* self, void* p1, void* p2) {
    // Stack: 56 bytes
    // -> AptActionInterpreter::getContext(AptValue *, AptValue *, EAStringC *, AptValue **, EAStringC &)
    // -> AptValue::getVtblIndex(void) const
    // -> AptValue::isUndefined(void) const
    // -> AptMovie::labelToFrame(EAStringC *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValue::toInteger(void) const
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushThis(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027EC64 | 324 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushThis(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushGlobal(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027EDA8 | 324 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushGlobal(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushZeroSetVar(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027F690 | 268 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushZeroSetVar(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptActionInterpreter::_FunctionAptActionSetVariable(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushString(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027F79C | 392 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushString(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushStringGetVar(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027FA30 | 284 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushStringGetVar(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptActionInterpreter::getVariable(AptValue *, AptValue *, EAStringC *, int, int, int)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushStringGetMember(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027FB4C | 408 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushStringGetMember(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushStringSetVar(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027FCE4 | 408 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushStringSetVar(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushStringSetMember(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8027FE7C | 408 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushStringSetMember(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDictCallFuncPop(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8028016C | 264 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDictCallFuncPop(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> AptActionInterpreter::_FunctionAptActionCallFunction(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)
    // -> AptValueVector::ReleaseValues(void)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDictCallMethodPop(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80280338 | 264 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionDictCallMethodPop(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> AptActionInterpreter::_FunctionAptActionCallMethod(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)
    // -> AptValueVector::ReleaseValues(void)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushFloat(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80280504 | 296 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushFloat(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushByte(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x8028062C | 268 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushByte(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushWord(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80280738 | 280 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushWord(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionPushDWord(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80280850 | 296 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionPushDWord(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionExtends(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80280A5C | 1004 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionExtends(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::isObjectOfType(AptValue *, AptValue *) - 0x80280E48 | 372 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter__isObjectOfType(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> AptObject::DoesImplementObject(AptValue *) const
    // Contains loop(s)

}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionInstanceOf(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80280FBC | 560 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionInstanceOf(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptActionInterpreter::isObjectOfType(AptValue *, AptValue *)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionCastOp(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x802811EC | 568 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionCastOp(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptActionInterpreter::isObjectOfType(AptValue *, AptValue *)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionImplementsOp(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x80281424 | 932 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionImplementsOp(void* self, void* p1, void* p2) {
    // Stack: 80 bytes
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptArray::AptArray(void)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // ... and 3 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionTry(AptActionInterpreter *, AptActionInterpreter::LocalContextT *) - 0x802817C8 | 844 bytes
// ============================================================================
// NON_MATCHING
void AptActionInterpreter___FunctionAptActionTry(void* self, void* p1, void* p2) {
    // Stack: 40 bytes
    // -> AptActionInterpreter::runStream(unsigned char *, AptCIH *, int, AptCharacterInst *)
    // -> AptScriptFunctionBase::SetRegisterValue(int, AptValue *)
    // -> EAStringC::InitFromBuffer(char *)
    // -> AptScriptFunctionBase::CreateFrameStack(void)
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // -> AptActionInterpreter::setVariable(AptValue *, AptValue *, EAStringC *, AptValue *, int, int, int)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // ActionScript bytecode handler
    // Pop operands from stack
    // Perform operation
    // Push result
}
