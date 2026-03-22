// apt_action.cpp - AptActionInterpreter small functions
// From libaptz.a(AptActionInterpreter.cpp.obj)

#include "ui/apt_action.h"
#include "ui/apt_types.h"

// External references
extern AptValue* gpUndefinedValue;
extern "C" int strcmp(const char*, const char*);

// ============================================================================
// AptActionInterpreter::unresolveStream
// NON_MATCHING - GCC emits tail call, SN Systems emits full bl wrapper
// Calls _parseStream with constFile=NULL (r5=0), forwarding offset as r6
// ============================================================================
// NON_MATCHING
void AptActionInterpreter::unresolveStream(u8* stream, u8* end, int* offset) {
    _parseStream(stream, end, (AptConstFile*)0, offset);
}

// ============================================================================
// AptActionInterpreter::resolveStream
// NON_MATCHING - GCC emits tail call, SN Systems emits full bl wrapper
// Direct wrapper for _parseStream
// ============================================================================
// NON_MATCHING
void AptActionInterpreter::resolveStream(u8* stream, u8* end, AptConstFile* constFile, int* offset) {
    _parseStream(stream, end, constFile, offset);
}

// ============================================================================
// AptActionInterpreter::cbCallMethod_ASSetPropFlags
// NON_MATCHING - GCC uses absolute addressing, SN Systems uses SDA-relative (r13)
// Returns gpUndefinedValue (stub - feature not implemented)
// ============================================================================
// NON_MATCHING
AptValue* AptActionInterpreter::cbCallMethod_ASSetPropFlags(AptValue* thisObj, int argc) {
    return gpUndefinedValue;
}

// ============================================================================
// AptActionInterpreter::PrepareForExecution(char*)
// NON_MATCHING - GCC emits tail call, SN Systems emits full bl wrapper
// Calls AptScriptFunctionBase::PushStaticData (ignoring name param)
// ============================================================================
// NON_MATCHING
void AptActionInterpreter::PrepareForExecution(char* name) {
    AptScriptFunctionBase::PushStaticData();
}

// ============================================================================
// AptActionInterpreter::PrepareForExecution(AptActionSetup*)
// NON_MATCHING - GCC emits tail call, SN Systems emits full bl wrapper
// Calls AptScriptFunctionBase::PushStaticData (ignoring setup param)
// ============================================================================
// NON_MATCHING
void AptActionInterpreter::PrepareForExecution(AptActionSetup* setup) {
    AptScriptFunctionBase::PushStaticData();
}

// ============================================================================
// Stub action handlers (no-op, just blr) - ALL MATCHING
// ============================================================================
void AptActionInterpreter::_FunctionAptActionEnd(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionToggleQuality(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionStopSounds(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionStringLessThan(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionMBLength(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionCharToAscii(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionMBSubString(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionMBCharToAscii(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionMBAsciiToChar(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionBitURShift(AptActionInterpreter* interp, int* ctx) {
}

void AptActionInterpreter::_FunctionAptActionWaitForFrame(AptActionInterpreter* interp, int* ctx) {
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionReturn
// NON_MATCHING - register allocation differs (GCC uses r9, SN uses r0)
// Sets ctx->m_returnFlag = 1
// ============================================================================
// NON_MATCHING
void AptActionInterpreter::_FunctionAptActionReturn(AptActionInterpreter* interp, int* ctx) {
    ctx->m_returnFlag = 1;
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionEnumerate
// NON_MATCHING - GCC emits tail call, SN Systems emits full bl wrapper
// Loads scope+stack from ctx, calls _doEnumerate
// ============================================================================
// NON_MATCHING
void AptActionInterpreter::_FunctionAptActionEnumerate(AptActionInterpreter* interp, int* ctx) {
    interp->_doEnumerate((AptValue*)ctx->m_scope, (AptValue*)ctx->m_stack);
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionEnumerate2
// NON_MATCHING - GCC emits tail call, SN Systems emits full bl wrapper
// Same as Enumerate - loads scope+stack from ctx, calls _doEnumerate
// ============================================================================
// NON_MATCHING
void AptActionInterpreter::_FunctionAptActionEnumerate2(AptActionInterpreter* interp, int* ctx) {
    interp->_doEnumerate((AptValue*)ctx->m_scope, (AptValue*)ctx->m_stack);
}

// ============================================================================
// AptActionInterpreter::_FunctionAptActionDefineDictionary
// NON_MATCHING - register allocation differs
// Reads dictionary count+size from aligned stream position
// ============================================================================
// NON_MATCHING
void AptActionInterpreter::_FunctionAptActionDefineDictionary(AptActionInterpreter* interp, int* ctx) {
    u8* ptr = (u8*)((((u32)ctx->m_streamPos) + 3) & ~3);
    ctx->m_streamPos = (u32)(ptr + 8);
    interp->m_dictCount = *(u32*)(ptr);
    interp->m_dictSize = *(u32*)(ptr + 4);
}

// ============================================================================
// AptValueGC::IsGarbageCollected - MATCHING
// Returns true (1)
// ============================================================================
bool AptValueGC::IsGarbageCollected() const {
    return true;
}

// ============================================================================
// AptValueNoGC::IsGarbageCollected - MATCHING
// Returns false (0)
// ============================================================================
bool AptValueNoGC::IsGarbageCollected() const {
    return false;
}

// ============================================================================
// AptValueNoGC::RegisterReferences - MATCHING
// No-op
// ============================================================================
void AptValueNoGC::RegisterReferences() const {
}

// ============================================================================
// EAStringC inline copies
// These functions appear as inline copies in many .obj files in the map.
// Canonical definitions are in apt_value.cpp. Listed here for reference:
//
// EAStringC::IsEmpty() const - NON_MATCHING (SN uses xor+subfic+adde)
// EAStringC::EAStringC() - NON_MATCHING (register allocation differs)
// EAStringC::EAStringC(EAStringC&) - NON_MATCHING (register allocation)
// EAStringC::EAStringC(char*) - NON_MATCHING (SN uses stmw/lmw wrapper)
// EAStringC::operator==(char*) const - NON_MATCHING (SN uses subfic+adde)
// EAStringC::operator!=(char*) const - NON_MATCHING (SN uses subfic+adde+xori)
// EAStringC::Equal(char*) const - NON_MATCHING (same as operator==)
//
// See apt_value.cpp for implementations.
// ============================================================================
