// apt_native_hash_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptNativeHash.cpp.obj
// 8 functions, 3408 bytes

#include "types.h"

// ============================================================================
// AptNativeHash::~AptNativeHash(void) - 0x802A98CC | 260 bytes
// ============================================================================
// NON_MATCHING
void AptNativeHash__dtor_AptNativeHash(void* self) {
    // Stack: 32 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Release resources
    // Destroy members
}

// ============================================================================
// AptNativeHash::DestroyGCPointers(void) - 0x802A99D0 | 308 bytes
// ============================================================================
// NON_MATCHING
void AptNativeHash__DestroyGCPointers(void* self) {
    // Stack: 32 bytes
    // Contains loop(s)

    // Tear down subsystem
}

// ============================================================================
// AptNativeHash::Set(EAStringC *, AptValue *) - 0x802A9B50 | 548 bytes
// ============================================================================
// NON_MATCHING
void AptNativeHash__Set(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> AptNativeHash::Unset(EAStringC *)
    // -> EAStringC::CalculateHashValue(void) const
    // -> strcasecmp
    // -> AptNativeHash::FirstAllocation(void)
    // -> AptNativeHash::HashSet(EAStringC *, AptValue *)

    // Setter
}

// ============================================================================
// AptNativeHash::Unset(EAStringC *) - 0x802A9D74 | 552 bytes
// ============================================================================
// NON_MATCHING
void AptNativeHash__Unset(void* self, void* p1) {
    // Stack: 32 bytes
    // -> EAStringC::CalculateHashValue(void) const
    // -> AptNativeHash::HashFindKey(EAStringC *) const
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // -> strcasecmp
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptNativeHash::Lookup(EAStringC *) const - 0x802A9F9C | 312 bytes
// ============================================================================
// NON_MATCHING
void AptNativeHash__Lookup_const(void* self, void* p1) {
    // Stack: 24 bytes
    // -> EAStringC::CalculateHashValue(void) const
    // -> AptNativeHash::HashFindKey(EAStringC *) const
    // -> strcasecmp

    // Search/lookup
}

// ============================================================================
// AptNativeHash::ClearData(void) - 0x802AA0D4 | 424 bytes
// ============================================================================
// NON_MATCHING
void AptNativeHash__ClearData(void* self) {
    // Stack: 40 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// AptNativeHash::ClearDataNoDelete(void) - 0x802AA27C | 388 bytes
// ============================================================================
// NON_MATCHING
void AptNativeHash__ClearDataNoDelete(void* self) {
    // Stack: 40 bytes
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Remove element
}

// ============================================================================
// AptNativeHash::HashFindKey(EAStringC *) const - 0x802AAB18 | 616 bytes
// ============================================================================
// NON_MATCHING
int AptNativeHash__HashFindKey_const(void* self, void* p1) {
    // Stack: 40 bytes
    // -> strcasecmp
    // Contains loop(s)

    // Search/lookup
    return 0;
}
