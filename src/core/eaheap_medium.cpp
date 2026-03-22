#if 0 // SKIP
// eaheap_medium.cpp - Medium-sized functions (65-128 bytes) from e_standard_heap.obj and fastallocpool.obj
// From: base_ngc_release_dvd.lib

#include "core/eaheap.h"
#include "core/fastallocpool.h"

// External functions
extern "C" void __register_atexit(void (*func)(void));

// SDA globals
extern int g_currentCheckPoint;

// ============================================================================
// EAHeap::EAHeap - 0x802d09dc (128 bytes)
// Constructor: calls GeneralAllocator base with default params,
// stores name/parent/aux, calls Clear, then Init
// ============================================================================
// NON_MATCHING - SN Systems calling convention for base class construction
EAHeap::EAHeap(char* name, void* buffer, unsigned int size, EAHeap* parent, EAHeap* auxHeap)
    : EA::Allocator::GeneralAllocator(0, 0, 1, 0, 0, 0) {
    m_name = name;
    m_parentHeap = parent;
    m_auxHeap = auxHeap;
    Clear();
    Init(buffer, size);
}

// ============================================================================
// EAHeap::FindHeapForAddress - 0x802d0f24 (124 bytes)
// Recursively searches this heap and children for address ownership
// ============================================================================
// NON_MATCHING - recursive call pattern
EAHeap* EAHeap::FindHeapForAddress(void* addr) const {
    if (((int*)this)->FindCoreBlockForAddress(addr) != 0) {
        return (EAHeap*)this;
    }
    if (m_parentHeap != 0) {
        EAHeap* found = m_parentHeap->FindHeapForAddress(addr);
        if (found != 0) {
            return found;
        }
    }
    if (m_auxHeap != 0) {
        EAHeap* found = m_auxHeap->FindHeapForAddress(addr);
        if (found != 0) {
            return found;
        }
    }
    return 0;
}

// ============================================================================
// memalign - 0x802d116c (68 bytes)
// Aligned allocation through MainHeap's MallocAligned
// ============================================================================
// NON_MATCHING - register allocation
void* memalign(unsigned int align, unsigned int size) {
    EAHeap* heap = MainHeap();
    return heap->MallocAligned(size, align, 0, 0);
}

// ============================================================================
// AllocPoolManager<ProtectedAllocPool>::InitPoolByIndex - 0x803c1e18 (108 bytes)
// Inits pool at given index: calculates stride offset, calls Init,
// returns pointer past end of pool data
// ============================================================================
// NON_MATCHING - template instantiation differences
template<>
unsigned char* AllocPoolManager<ProtectedAllocPool>::InitPoolByIndex(int index, unsigned int* sizes, unsigned char* poolMem) {
    unsigned int poolDataOffset = index * 0x34 + 0x08;
    unsigned int blockSize = sizes[index];
    int poolIdx = index + 1;
    int numBlocks = poolIdx << 3;
    FastAllocPool* pool = (FastAllocPool*)((char*)this + poolDataOffset);
    pool->Init(poolMem, blockSize, numBlocks);
    unsigned int poolSize = pool->GetPoolBlocks() * pool->GetBlockSize();
    return poolMem + poolSize;
}

// ============================================================================
// AllocPoolManager<FastAllocPool>::InitPoolByIndex - 0x803c1fac (108 bytes)
// Same as above but for FastAllocPool (stride = 24 = 0x18)
// ============================================================================
// NON_MATCHING - template instantiation differences
template<>
unsigned char* AllocPoolManager<FastAllocPool>::InitPoolByIndex(int index, unsigned int* sizes, unsigned char* poolMem) {
    unsigned int poolDataOffset = index * 0x18 + 0x08;
    unsigned int blockSize = sizes[index];
    int poolIdx = index + 1;
    int numBlocks = poolIdx << 3;
    FastAllocPool* pool = (FastAllocPool*)((char*)this + poolDataOffset);
    pool->Init(poolMem, blockSize, numBlocks);
    unsigned int poolSize = pool->GetPoolBlocks() * pool->GetBlockSize();
    return poolMem + poolSize;
}

// ============================================================================
// AllocPoolManager<FastAllocPool>::AttemptPoolAlloc - 0x803c22f4 (116 bytes)
// Attempts to allocate from a pool that fits the requested size.
// If size > 64 returns null. Converts size to pool index via (size-1)/8.
// Walks pools from that index looking for one with free blocks.
// ============================================================================
// NON_MATCHING - loop unrolling and branch structure
template<>
void* AllocPoolManager<FastAllocPool>::AttemptPoolAlloc(unsigned int size, unsigned int align) {
    if (size > 64) {
        return 0;
    }
    int poolIdx = (size - 1) >> 3;
    if (poolIdx > 7) {
        return 0;
    }
    FastAllocPool* pool = (FastAllocPool*)(m_poolData + poolIdx * 0x18);
    while (poolIdx <= 7) {
        unsigned int poolAlign = (unsigned int)pool->m_alignment;
        if (align <= poolAlign) {
            void* block = pool->m_freeList;
            if (block != 0) {
                pool->m_freeList = *(void**)((char*)block + 4);
                *(unsigned int*)block = 0x44455355; // "DESU"
                return block;
            }
        }
        poolIdx++;
        pool = (FastAllocPool*)((char*)pool + 0x18);
    }
    return 0;
}

// ============================================================================
// FPHeap::Malloc - 0x802d0ff4 (100 bytes)
// Tries pool alloc first, falls back to EAHeap::Malloc
// ============================================================================
// NON_MATCHING - SDA access to s_poolBlocks
void* FPHeap::Malloc(unsigned int size, int align) {
    if (size == 0) {
        return 0;
    }
    AllocPoolManager<FastAllocPool>* mgr = s_fpPoolBlocks;
    void* result = mgr->AttemptPoolAlloc(size, 8);
    if (result != 0) {
        return result;
    }
    return EAHeap::Malloc(size, align);
}

// ============================================================================
// FPHeap::Free - 0x802d1058 (108 bytes)
// Tries pool free first, falls back to EAHeap::Free
// ============================================================================
// NON_MATCHING - SDA access to s_poolBlocks
void FPHeap::Free(void* ptr) {
    if (ptr == 0) {
        return;
    }
    AllocPoolManager<FastAllocPool>* mgr = s_fpPoolBlocks;
    FastAllocPool* pool = mgr->FindPoolForBlock(ptr);
    if (pool != 0) {
        *(unsigned int*)ptr = 0x45455246; // "EERF"
        void* nextFree = *(void**)((char*)pool + 4);
        *(void**)((char*)ptr + 4) = nextFree;
        *(void**)((char*)pool + 4) = ptr;
    } else {
        EAHeap::Free(ptr);
    }
}

// ============================================================================
// FastAllocPool::Init - 0x802d7024 (112 bytes)
// Initializes pool: sets pool start, block/pool sizes, alignment,
// builds free list by chaining blocks together with "EERF" magic
// ============================================================================
// NON_MATCHING - free list construction loop
void FastAllocPool::Init(void* pool, int blockSize, int numBlocks) {
    unsigned int combined = (unsigned int)blockSize | (unsigned int)pool;
    unsigned int negCombined = -(int)combined;
    unsigned int alignment = combined & negCombined;

    m_freeList = 0;
    m_alignment = (int)alignment;
    m_poolStart = pool;
    m_poolBlocks = numBlocks;
    m_blockSize = blockSize;

    unsigned char* blockPtr = (unsigned char*)pool;
    for (unsigned int i = 0; i < (unsigned int)numBlocks; i++) {
        if (blockPtr == 0) break;
        *(unsigned int*)blockPtr = 0x45455246; // "EERF"
        *(void**)(blockPtr + 4) = m_freeList;
        m_freeList = blockPtr;
        blockPtr += blockSize;
    }
}

// ============================================================================
// ProtectedAllocPool::~ProtectedAllocPool - 0x802d71d0 (80 bytes)
// Destructor: sets vtable, destroys mutex, calls FastAllocPool dtor
// ============================================================================
// NON_MATCHING - SN Systems destructor calling convention
ProtectedAllocPool::~ProtectedAllocPool(void) {
    // Original: sets ProtectedAllocPool vtable at offset 0x14
    // Destroys mutex at offset 0x18
    // Calls FastAllocPool::~FastAllocPool
}

// ============================================================================
// ProtectedAllocPool::Alloc - 0x802d7250 (120 bytes)
// Thread-safe alloc: locks mutex, calls FastAllocPool::Alloc, unlocks mutex
// ============================================================================
// NON_MATCHING - virtual dispatch through vtable at offset 0x18
void* ProtectedAllocPool::Alloc(void) {
    return ((FastAllocPool*)this)->Alloc();
}

// ============================================================================
// ProtectedAllocPool::Free - 0x802d72c8 (120 bytes)
// Thread-safe free: locks mutex, calls FastAllocPool::Free, unlocks mutex
// ============================================================================
// NON_MATCHING - virtual dispatch through vtable at offset 0x18
void ProtectedAllocPool::Free(void* ptr) {
    ((FastAllocPool*)this)->Free(ptr);
}

// ============================================================================
// Heap accessor functions (RootHeap through AptHeap) and __tcf_13/__tcf_14:
// These are all singleton initialization functions (112-132 bytes each).
// They use SDA-relative guard flags, construct static heap objects at fixed
// BSS addresses, and register atexit handlers.
// All NON_MATCHING due to SDA addressing and compiler-generated patterns.
//
// Documented addresses:
//   RootHeap     - 0x802cfe64 (112 bytes) - no parent
//   MainHeap     - 0x802cff00 (116 bytes) - parent = RootHeap
//   ResourceHeap - 0x802cffa0 (116 bytes) - parent = MainHeap
//   VMHeap       - 0x802d0040 (116 bytes) - parent = MainHeap
//   DebugHeap    - 0x802d00e0 (112 bytes) - no parent
//   CUIHeap      - 0x802d017c (116 bytes) - parent = MainHeap
//   FlashesHeap  - 0x802d058c (116 bytes) - parent = ResourceHeap
//   AptHeap      - 0x802d062c (116 bytes) - parent = FlashesHeap (FPHeap)
//   __tcf_13     - 0x802d06a0 (108 bytes) - ProtectedAllocPool manager dtor
//   __tcf_14     - 0x802d088c (108 bytes) - FastAllocPool manager dtor
// ============================================================================
#endif
