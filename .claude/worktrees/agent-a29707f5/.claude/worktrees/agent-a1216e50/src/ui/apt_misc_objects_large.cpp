// apt_misc_objects_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptMiscObjects.cpp.obj
// 22 functions, 8944 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// KeyMembersIndex::in_word_set(char *, unsigned int) - 0x802A275C | 356 bytes
// ============================================================================
// NON_MATCHING
void KeyMembersIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 272 bytes
    // -> memcmp
    // Contains loop(s)

}

// ============================================================================
// MathMembersIndex::in_word_set(char *, unsigned int) - 0x802A28C0 | 416 bytes
// ============================================================================
// NON_MATCHING
void MathMembersIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 280 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// LoadVarsMembersIndex::in_word_set(char *, unsigned int) - 0x802A2A60 | 264 bytes
// ============================================================================
// NON_MATCHING
void LoadVarsMembersIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 272 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// AptMathObj::sMethod_atan2(AptValue *, int) - 0x802A3E98 | 272 bytes
// ============================================================================
// NON_MATCHING
void AptMathObj__sMethod_atan2(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toFloat(void) const
    // -> atan2f
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptMathObj::sMethod_round(AptValue *, int) - 0x802A3FA8 | 280 bytes
// ============================================================================
// NON_MATCHING
void AptMathObj__sMethod_round(void* self, void* p1, int p2) {
    // Stack: 24 bytes
    // -> AptValue::toFloat(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptMathObj::sMethod_min(AptValue *, int) - 0x802A40C0 | 292 bytes
// ============================================================================
// NON_MATCHING
void AptMathObj__sMethod_min(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toFloat(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptMathObj::sMethod_max(AptValue *, int) - 0x802A41E4 | 292 bytes
// ============================================================================
// NON_MATCHING
void AptMathObj__sMethod_max(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toFloat(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptMathObj::sMethod_abs(AptValue *, int) - 0x802A4308 | 416 bytes
// ============================================================================
// NON_MATCHING
void AptMathObj__sMethod_abs(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toFloat(void) const
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptMathObj::sMethod_pow(AptValue *, int) - 0x802A4B1C | 272 bytes
// ============================================================================
// NON_MATCHING
void AptMathObj__sMethod_pow(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toFloat(void) const
    // -> powf
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptKey::CleanNativeFunctions(void) - 0x802A4EEC | 540 bytes
// ============================================================================
// NON_MATCHING
void AptKey__CleanNativeFunctions(void* self) {
    // Stack: 8 bytes
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptKey::sMethod_isDown(AptValue *, int) - 0x802A5940 | 408 bytes
// ============================================================================
// NON_MATCHING
void AptKey__sMethod_isDown(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> AptValue::toInteger(void) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptKey::sMethod_getAscii(AptValue *, int) - 0x802A5C8C | 276 bytes
// ============================================================================
// NON_MATCHING
void AptKey__sMethod_getAscii(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptKey::sMethod_addListener(AptValue *, int) - 0x802A5E5C | 352 bytes
// ============================================================================
// NON_MATCHING
void AptKey__sMethod_addListener(void* self, void* p1, int p2) {
    // Stack: 8 bytes
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptKey::sMethod_removeListener(AptValue *, int) - 0x802A5FBC | 632 bytes
// ============================================================================
// NON_MATCHING
void AptKey__sMethod_removeListener(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptLoadVars::CleanNativeFunctions(void) - 0x802A6E20 | 412 bytes
// ============================================================================
// NON_MATCHING
void AptLoadVars__CleanNativeFunctions(void* self) {
    // Stack: 8 bytes
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptLoadVars::sMethod_load(AptValue *, int) - 0x802A6FBC | 820 bytes
// ============================================================================
// NON_MATCHING
void AptLoadVars__sMethod_load(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toString(EAStringC &) const
    // -> AptNativeHash::GetFirstItem(void)
    // -> memcmp
    // -> AptNativeHash::Unset(EAStringC *)
    // ... and 3 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptLoadVars::sMethod_send(AptValue *, int) - 0x802A72F0 | 764 bytes
// ============================================================================
// NON_MATCHING
void AptLoadVars__sMethod_send(void* self, void* p1, int p2) {
    // Stack: 64 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptValue::toString(EAStringC &) const
    // -> AptValue::urlEncode(void)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptLoadVars::sMethod_toString(AptValue *, int) - 0x802A7D2C | 288 bytes
// ============================================================================
// NON_MATCHING
void AptLoadVars__sMethod_toString(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> AptValue::urlEncode(void)
    // -> EAStringC::EAStringC(char *)
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptError::objectMemberLookup(AptValue *, EAStringC *) const - 0x802A7E4C | 648 bytes
// ============================================================================
// NON_MATCHING
void AptError__objectMemberLookup_const(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> strcmp
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::EAStringC(char *)
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Search/lookup
}

// ============================================================================
// AptError::objectMemberSet(AptValue *, EAStringC *, AptValue *) - 0x802A80D4 | 264 bytes
// ============================================================================
// NON_MATCHING
void AptError__objectMemberSet(void* self, void* p1, void* p2, void* p3) {
    // Stack: 32 bytes
    // -> strcmp
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::Duplicate(EAStringC &)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// AptError::sMethod_toString(AptValue *, int) - 0x802A82AC | 288 bytes
// ============================================================================
// NON_MATCHING
void AptError__sMethod_toString(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> AptValue::urlEncode(void)
    // -> EAStringC::EAStringC(char *)
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptStage::objectMemberLookup(AptValue *, EAStringC *) const - 0x802A84C4 | 392 bytes
// ============================================================================
// NON_MATCHING
void AptStage__objectMemberLookup_const(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> StageMembersIndex::in_word_set(char *, unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Search/lookup
}
