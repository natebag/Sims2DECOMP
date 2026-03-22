// apt_gc_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: AptGC.cpp.obj
// 1 functions, 408 bytes

#include "types.h"

// ============================================================================
// AptGC::CleanUnreachable(void) - 0x8029C69C | 408 bytes
// ============================================================================
// NON_MATCHING
void AptGC__CleanUnreachable(void* self) {
    // Stack: 24 bytes
    // -> AptValueVector::ReleaseValues(void)
    // -> AptValueGC_PoolManager::GetFirstAptValue(void)
    // -> AptValueGC_PoolManager::GetNextAptValue(AptValue *)
    // -> AptRegisterGlobalReferences(void)
    // -> AptBoolean::ClearPool(void)
    // -> AptInteger::ClearPool(void)
    // ... and 2 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}
