// apt_array_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptArray.cpp.obj
// 12 functions, 4776 bytes

#include "types.h"

// ============================================================================
// ArrayMembersIndex::in_word_set(char *, unsigned int) - 0x80285800 | 264 bytes
// ============================================================================
// NON_MATCHING
void ArrayMembersIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 272 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// AptArray::AptArray(int, AptValue **) - 0x80285908 | 292 bytes
// ============================================================================
// NON_MATCHING
void AptArray__AptArray(void* self, int p1, void* p2) {
    // Stack: 40 bytes
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> AptArray::_reserve(int)
    // Contains loop(s)

    // Initialize members
    // Object size >= 0x2C
}

// ============================================================================
// AptArray::CleanNativeFunctions(void) - 0x80285B10 | 732 bytes
// ============================================================================
// NON_MATCHING
void AptArray__CleanNativeFunctions(void* self) {
    // Stack: 8 bytes
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptArray::toString(EAStringC &, char *) - 0x80286168 | 352 bytes
// ============================================================================
// NON_MATCHING
void AptArray__toString(void* self, void* p1, char* p2) {
    // Stack: 48 bytes
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::operator+=(EAStringC &)
    // -> EAStringC::operator+=(char *)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptArray::sMethod_concat(AptValue *, int) - 0x80286D08 | 344 bytes
// ============================================================================
// NON_MATCHING
void AptArray__sMethod_concat(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptArray::AptArray(void)
    // -> AptArray::set(int, AptValue *)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptArray::sMethod_join(AptValue *, int) - 0x80286E60 | 500 bytes
// ============================================================================
// NON_MATCHING
void AptArray__sMethod_join(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> AptArray::toString(EAStringC &, char *)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptArray::sMethod_push(AptValue *, int) - 0x802870D4 | 292 bytes
// ============================================================================
// NON_MATCHING
void AptArray__sMethod_push(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptArray::set(int, AptValue *)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptArray::sMethod_unshift(AptValue *, int) - 0x8028729C | 372 bytes
// ============================================================================
// NON_MATCHING
void AptArray__sMethod_unshift(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> AptArray::_reserve(int)
    // -> memmove
    // -> AptArray::set(int, AptValue *)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptArray::scriptFunctionSortFunc(void *, void *) - 0x802874E0 | 368 bytes
// ============================================================================
// NON_MATCHING
void AptArray__scriptFunctionSortFunc(void* self, void* p1, void* p2) {
    // Stack: 48 bytes
    // -> AptActionInterpreter::PrepareForExecution(AptActionSetup *)
    // -> AptActionInterpreter::callFunction(AptValue *, AptValue *, int)
    // -> AptValue::toInteger(void) const
    // -> AptActionInterpreter::CleanupAfterExecution(void *, AptActionSetup *)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptArray::defaultSortOnCompareFunc(void *, void *) - 0x802876F4 | 336 bytes
// ============================================================================
// NON_MATCHING
int AptArray__defaultSortOnCompareFunc(void* self, void* p1, void* p2) {
    // Stack: 32 bytes
    // -> AptNativeHash::Lookup(EAStringC *) const
    // -> AptArray::defaultSortCompareFunc(void *, void *)
    // -> atoi
    // -> AptArray::get(int)
    // Accesses globals via r13 (SDA)

    // Comparison
    return 0;
}

// ============================================================================
// AptArray::sMethod_splice(AptValue *, int) - 0x802879B8 | 596 bytes
// ============================================================================
// NON_MATCHING
void AptArray__sMethod_splice(void* self, void* p1, int p2) {
    // Stack: 56 bytes
    // -> AptValue::toInteger(void) const
    // -> memmove
    // -> AptArray::_reserve(int)
    // -> AptArray::set(int, AptValue *)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptArray::sMethod_slice(AptValue *, int) - 0x80287C0C | 328 bytes
// ============================================================================
// NON_MATCHING
void AptArray__sMethod_slice(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toInteger(void) const
    // -> AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
    // -> AptArray::AptArray(void)
    // -> AptArray::set(int, AptValue *)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}
