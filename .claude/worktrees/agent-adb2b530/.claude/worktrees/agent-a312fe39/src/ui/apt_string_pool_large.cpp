// apt_string_pool_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: StringPool.cpp.obj
// 2 functions, 920 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// StringPool::Teardown(void) - 0x802C4314 | 300 bytes
// ============================================================================
// NON_MATCHING
void StringPool__Teardown(void* self) {
    // Stack: 32 bytes
    // -> AptValueVector::ReleaseValues(void)
    // -> DOGMA_PoolManager::Deallocate(void *, unsigned int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// StringPool::GetFromPool(char *) - 0x802C44C4 | 620 bytes
// ============================================================================
// NON_MATCHING
void* StringPool__GetFromPool(void* self, char* p1) {
    // Stack: 32 bytes
    // -> strcmp
    // -> EAStringC::IsEmpty(void) const
    // -> EAStringC::ReserveSize(unsigned int)
    // -> DOGMA_PoolManager::Allocate(unsigned int)
    // -> AptString::AptString(void)
    // -> EAStringC::InitFromBuffer(char *)
    // ... and 2 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}
