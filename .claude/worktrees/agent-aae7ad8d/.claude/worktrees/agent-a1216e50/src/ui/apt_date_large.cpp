// apt_date_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptDate.cpp.obj
// 14 functions, 5104 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// DateMembersIndex::in_word_set(char *, unsigned int) - 0x80293FD8 | 416 bytes
// ============================================================================
// NON_MATCHING
void DateMembersIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 280 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// AptDate::setDates(AptSysClock *, AptSysClock *, int) - 0x802942A8 | 312 bytes
// ============================================================================
// NON_MATCHING
void AptDate__setDates(void* self, void* p1, void* p2, int p3) {
    // Stack: 16 bytes
    // -> AptDate::dateGetNumDaysInMonth(int, int)

}

// ============================================================================
// AptDate::getDayOfWeek(int, int, int) - 0x802943E0 | 680 bytes
// ============================================================================
// NON_MATCHING
void AptDate__getDayOfWeek(void* self, int p1, int p2, int p3) {
    // Stack: 64 bytes
    // -> AptDate::dateIsYearLeap(int)
    // -> floorf
    // Uses floating point

}

// ============================================================================
// AptDate::toString(EAStringC &) - 0x80294688 | 728 bytes
// ============================================================================
// NON_MATCHING
void AptDate__toString(void* self, void* p1) {
    // Stack: 136 bytes
    // -> AptDate::getDayOfWeek(int, int, int)
    // -> EAStringC::InitFromBuffer(char *)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> EAStringC::operator+=(char *)
    // -> sprintf
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::sMethod_setFullYear(AptValue *, int) - 0x802957E0 | 336 bytes
// ============================================================================
// NON_MATCHING
void AptDate__sMethod_setFullYear(void* self, void* p1, int p2) {
    // Stack: 24 bytes
    // -> AptValue::toInteger(void) const
    // -> AptDate::setDates(AptSysClock *, AptSysClock *, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::sMethod_setUTCDate(AptValue *, int) - 0x80295EE4 | 260 bytes
// ============================================================================
// NON_MATCHING
void AptDate__sMethod_setUTCDate(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> AptValue::toInteger(void) const
    // -> AptDate::setDates(AptSysClock *, AptSysClock *, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::sMethod_setUTCFullYear(AptValue *, int) - 0x80295FE8 | 340 bytes
// ============================================================================
// NON_MATCHING
void AptDate__sMethod_setUTCFullYear(void* self, void* p1, int p2) {
    // Stack: 24 bytes
    // -> AptValue::toInteger(void) const
    // -> AptDate::setDates(AptSysClock *, AptSysClock *, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::sMethod_setUTCHours(AptValue *, int) - 0x8029613C | 260 bytes
// ============================================================================
// NON_MATCHING
void AptDate__sMethod_setUTCHours(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> AptValue::toInteger(void) const
    // -> AptDate::setDates(AptSysClock *, AptSysClock *, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::sMethod_setUTCMilliseconds(AptValue *, int) - 0x80296240 | 260 bytes
// ============================================================================
// NON_MATCHING
void AptDate__sMethod_setUTCMilliseconds(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> AptValue::toInteger(void) const
    // -> AptDate::setDates(AptSysClock *, AptSysClock *, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::sMethod_setUTCMinutes(AptValue *, int) - 0x80296344 | 260 bytes
// ============================================================================
// NON_MATCHING
void AptDate__sMethod_setUTCMinutes(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> AptValue::toInteger(void) const
    // -> AptDate::setDates(AptSysClock *, AptSysClock *, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::sMethod_setUTCMonth(AptValue *, int) - 0x80296448 | 260 bytes
// ============================================================================
// NON_MATCHING
void AptDate__sMethod_setUTCMonth(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> AptValue::toInteger(void) const
    // -> AptDate::setDates(AptSysClock *, AptSysClock *, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::sMethod_setUTCSeconds(AptValue *, int) - 0x8029654C | 260 bytes
// ============================================================================
// NON_MATCHING
void AptDate__sMethod_setUTCSeconds(void* self, void* p1, int p2) {
    // Stack: 16 bytes
    // -> AptValue::toInteger(void) const
    // -> AptDate::setDates(AptSysClock *, AptSysClock *, int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::sMethod_toString(AptValue *, int) - 0x80296750 | 312 bytes
// ============================================================================
// NON_MATCHING
void AptDate__sMethod_toString(void* self, void* p1, int p2) {
    // Stack: 40 bytes
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> AptDate::toString(EAStringC &)
    // -> EAStringC::EAStringC(char *)
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptDate::AptDate(int, int, int, int, int, int, int) - 0x80298C30 | 420 bytes
// ============================================================================
// NON_MATCHING
void AptDate__AptDate(void* self, int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
    // Stack: 48 bytes
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // -> AptNativeHash::AptNativeHash(int)
    // -> AptDate::setDates(AptSysClock *, AptSysClock *, int)

    // Initialize members
    // Object size >= 0x90
}
