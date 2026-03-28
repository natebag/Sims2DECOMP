#ifndef DOGMA_ALLOCATOR_H
#define DOGMA_ALLOCATOR_H

#include "types.h"

// Forward declarations
struct AptFuncs;

// ============================================================================
// DOGMA_PoolManager - pool-based memory allocator for APT
// Source: libaptz.a(DogmaAllocator.cpp.obj)
//
// Layout (partial):
//   0x04: void* m_blockList (linked list of memory blocks)
//         Block layout:
//           0x00: void* m_next (next block in chain)
//           0x04: u32 m_end (end offset of used region)
//           0x08: u32 m_start (start offset of free region)
//           0x0C: data starts here (returned as base + 8)
//   0x10: u32 m_poolFlags (bits 28-31 encode minimum alignment size)
//   0x14: void* m_outsideAllocList (linked list of outside allocations)
//         Outside alloc layout:
//           -0x08: void* m_next (next outside alloc)
//           0x00: data starts here (returned as base + 8)
//
// Function pointers for allocation stored in gAptFuncs global table:
//   gAptFuncs[0] = allocate function pointer (for operator new / new[])
//   gAptFuncs[1] = free function pointer (for operator delete)
// ============================================================================
class DOGMA_PoolManager {
public:
    void* Allocate(unsigned int size);
    void Deallocate(void* ptr, unsigned int size);

    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr, unsigned int size);

    void* GetFirstOutsideAllocation();
    void* GetNextOutsideAllocation(void* current);

    unsigned int ToNextValidSize(unsigned int size);
    unsigned int GetTotalBytesUsed();
};

// Global APT function table (contains malloc/free function pointers)
extern AptFuncs gAptFuncs;

#endif // DOGMA_ALLOCATOR_H
