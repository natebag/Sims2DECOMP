// apt_string_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptString.cpp.obj
// 13 functions, 6368 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// StringMembersIndex::in_word_set(char *, unsigned int) - 0x802AC144 | 416 bytes
// ============================================================================
// NON_MATCHING
void StringMembersIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 280 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// AptString::CleanNativeFunctions(void) - 0x802AC4D0 | 796 bytes
// ============================================================================
// NON_MATCHING
void AptString__CleanNativeFunctions(void* self) {
    // Stack: 8 bytes
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_charAt(AptValue *, int) - 0x802AC7EC | 372 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_charAt(void* self, void* p1, int p2) {
    // Stack: 32 bytes
    // -> AptValue::toInteger(void) const
    // -> EAStringC::UTF8_GetBuffer(int)
    // -> EAStringC::UTF8_Append(char *, int)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_charCodeAt(AptValue *, int) - 0x802AC960 | 496 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_charCodeAt(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> AptValue::toInteger(void) const
    // -> EAStringC::UTF8_GetBuffer(int)
    // -> sprintf
    // -> EAStringC::InitFromBuffer(char *)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // ... and 4 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_concat(AptValue *, int) - 0x802ACB50 | 476 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_concat(void* self, void* p1, int p2) {
    // Stack: 56 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::operator+=(EAStringC &)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_fromCharCode(AptValue *, int) - 0x802ACD2C | 408 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_fromCharCode(void* self, void* p1, int p2) {
    // Stack: 56 bytes
    // -> EAStringC::EAStringC(unsigned int)
    // -> AptValue::toInteger(void) const
    // -> EAStringC::UTF8_Initialize(int)
    // -> EAStringC::operator+=(EAStringC &)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::IsEmpty(void) const
    // ... and 4 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_indexOf(AptValue *, int) - 0x802ACEC4 | 528 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_indexOf(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptValue::toInteger(void) const
    // -> EAStringC::UTF8_Find(char *, int) const
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_slice(AptValue *, int) - 0x802AD0DC | 744 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_slice(void* self, void* p1, int p2) {
    // Stack: 64 bytes
    // -> AptValue::toInteger(void) const
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::UTF8_Size(void) const
    // -> EAStringC::UTF8_Mid(int, int) const
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::IsEmpty(void) const
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_substr(AptValue *, int) - 0x802AD964 | 560 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_substr(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> AptValue::toInteger(void) const
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::UTF8_Size(void) const
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_substring(AptValue *, int) - 0x802ADB94 | 604 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_substring(void* self, void* p1, int p2) {
    // Stack: 48 bytes
    // -> AptValue::toInteger(void) const
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_toLowerCase(AptValue *, int) - 0x802ADDF0 | 340 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_toLowerCase(void* self, void* p1, int p2) {
    // Stack: 24 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::UTF8_MakeLower(void)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::sMethod_toUpperCase(AptValue *, int) - 0x802ADF44 | 340 bytes
// ============================================================================
// NON_MATCHING
void AptString__sMethod_toUpperCase(void* self, void* p1, int p2) {
    // Stack: 24 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::UTF8_MakeUpper(void)
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptString::printf(char *,...) - 0x802AEA34 | 288 bytes
// ============================================================================
// NON_MATCHING
void AptString__printf(void* self, char* p1) {
    // Stack: 160 bytes
    // -> vsprintf
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}
