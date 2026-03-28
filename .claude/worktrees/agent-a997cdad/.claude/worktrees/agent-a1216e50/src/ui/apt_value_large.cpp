// apt_value_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptValue.cpp.obj
// 6 functions, 3172 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// ObjectIndex::in_word_set(char *, unsigned int) - 0x802B02F8 | 448 bytes
// ============================================================================
// NON_MATCHING
void ObjectIndex__in_word_set(void* self, char* p1, int p2) {
    // Stack: 280 bytes
    // -> strcmp
    // Contains loop(s)

}

// ============================================================================
// AptValue::toBool(void) const - 0x802B06AC | 396 bytes
// ============================================================================
// NON_MATCHING
void AptValue__toBool_const(void* self) {
    // Stack: 16 bytes
    // -> AptGetSwfVersion(void)
    // -> strtol
    // -> Apt_atoff(char *)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// _gObjRegistrationFunc(AptValue *, int) - 0x802B0E4C | 600 bytes
// ============================================================================
// NON_MATCHING
void _gObjRegistrationFunc(void* p1, int p2) {
    // Stack: 16 bytes
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptNativeHash::AptNativeHash(int)
    // -> AptNativeHash::Unset(EAStringC *)
    // -> AptNativeHash::Set(EAStringC *, AptValue *)
    // -> AptValue::AptValue(AptVirtualFunctionTable_Indices)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptValue::urlEncode(void) - 0x802B3248 | 624 bytes
// ============================================================================
// NON_MATCHING
void AptValue__urlEncode(void* self) {
    // Stack: 56 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptNativeHash::GetFirstItem(void)
    // -> strcasecmp
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::operator+=(EAStringC &)
    // -> EAStringC::operator+=(char *)
    // ... and 2 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptValue::urlEncodeCustomRender(void) - 0x802B34B8 | 676 bytes
// ============================================================================
// NON_MATCHING
void AptValue__urlEncodeCustomRender(void* self) {
    // Stack: 56 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> AptNativeHash::GetFirstItem(void)
    // -> strcmp
    // -> AptValue::toString(EAStringC &) const
    // -> EAStringC::operator+=(EAStringC &)
    // -> EAStringC::operator+=(char *)
    // ... and 2 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Render pass
}

// ============================================================================
// AptValue::Release(char *, char *, int) - 0x802B3FC4 | 428 bytes
// ============================================================================
// NON_MATCHING
void AptValue__Release(void* self, char* p1, char* p2, int p3) {
    // Stack: 24 bytes
    // -> AptValue::toString(EAStringC &) const
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Accesses globals via r13 (SDA)

}
