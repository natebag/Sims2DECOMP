// dogma_allocator_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: DogmaAllocator.cpp.obj
// 2 functions, 588 bytes

#include "types.h"

// ============================================================================
// DOGMA_PoolManager::DOGMA_PoolManager(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char, bool, unsigned char, bool, unsigned char, bool) - 0x802B565C | 264 bytes
// ============================================================================
// NON_MATCHING
void DOGMA_PoolManager__DOGMA_PoolManager(void* self, int p1, int p2, int p3, int p4, u8* p5, int p6, u8* p7, int p8, u8* p9, int p10) {
    // Stack: 48 bytes
    // -> memset

    // Initialize members
    // Object size >= 0x3FA0
}

// ============================================================================
// DOGMA_PoolManager::Allocate(unsigned int) - 0x802B5848 | 324 bytes
// ============================================================================
// NON_MATCHING
void* DOGMA_PoolManager__Allocate(void* self, int p1) {
    // Stack: 24 bytes
    // -> DOGMA_PoolManager::ToNextValidSize(unsigned int)
    // -> DOGMA_PoolManager::ConsumeFreeBlockBySize(unsigned int)
    // Contains loop(s)

    return 0;
}
