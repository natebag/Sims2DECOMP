// eageneralallocator.cpp - EA::Allocator::GeneralAllocator implementation
// From: base_ngc_release_dvd.lib(eageneralallocator.obj)
// Small functions (<=64 bytes) decompiled from this object

#include "core/eageneralallocator.h"

// External function declarations
extern "C" void __builtin_delete(void* ptr);
extern "C" void free(void* ptr);

// DolphinSDK OS mutex functions
extern "C" void OSInitMutex(void* mutex);
extern "C" void OSLockMutex(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);

// Internal forward declarations
extern void DescribeDataInternal(EA::Allocator::GeneralAllocator* alloc, void* chunk, char* desc, unsigned int descSize);
extern void ReleaseSnapshotInternal(EA::Allocator::GeneralAllocator* alloc);

namespace EA {
namespace Allocator {

// ============================================================================
// GeneralAllocator::~GeneralAllocator - 0x802d8a2c (64 bytes)
// Destructor: calls Shutdown, then conditionally calls operator delete
// ============================================================================
// NON_MATCHING - destructor mode flag handling differs
GeneralAllocator::~GeneralAllocator(void) {
    Shutdown();
}

// ============================================================================
// GeneralAllocator::GetPageSize - 0x802d8fa8 (8 bytes)
// Returns fixed page size of 4096
// ============================================================================
unsigned int GeneralAllocator::GetPageSize(void) {
    return 4096;
}

// ============================================================================
// GeneralAllocator::AdjustHighFence - 0x802d9350 (4 bytes)
// Empty stub - does nothing (just blr)
// ============================================================================
void GeneralAllocator::AdjustHighFence(void) {
}

// ============================================================================
// GeneralAllocator::SetMallocFailureFunction - 0x802d8f78 (12 bytes)
// Stores callback function and context at offsets 0x4C4 and 0x4C8
// stw r5,0x4C8(r3); stw r4,0x4C4(r3)
// ============================================================================
// NON_MATCHING - store order (original stores r5 before r4)
void GeneralAllocator::SetMallocFailureFunction(
    bool (*func)(GeneralAllocator*, unsigned int, unsigned int, void*), void* context) {
    *(void**)((char*)this + 0x4C4) = (void*)func;
    *(void**)((char*)this + 0x4C8) = context;
}

// ============================================================================
// GeneralAllocator::SetHookFuncton - 0x802d8f84 (12 bytes)
// Note: original symbol has typo "Functon" not "Function"
// stw r5,0x4C0(r3); stw r4,0x4BC(r3)
// ============================================================================
void GeneralAllocator::SetHookFuncton(
    void (*func)(HookInfo*, void*), void* context) {
    *(void**)((char*)this + 0x4C0) = context;
    *(void**)((char*)this + 0x4BC) = (void*)func;
}

// ============================================================================
// GeneralAllocator::SetTraceFunction - 0x802d8f90 (12 bytes)
// stw r5,0x4DC(r3); stw r4,0x4D8(r3)
// ============================================================================
void GeneralAllocator::SetTraceFunction(
    void (*func)(char*, void*), void* context) {
    *(void**)((char*)this + 0x4DC) = context;
    *(void**)((char*)this + 0x4D8) = (void*)func;
}

// ============================================================================
// GeneralAllocator::SetTraceFieldDelimiters - 0x802d8f9c (12 bytes)
// Stores two byte values at offsets 0x485 and 0x484
// stb r5,0x485(r3); stb r4,0x484(r3)
// ============================================================================
void GeneralAllocator::SetTraceFieldDelimiters(unsigned char begin, unsigned char end) {
    *(unsigned char*)((char*)this + 0x485) = end;
    *(unsigned char*)((char*)this + 0x484) = begin;
}

// ============================================================================
// GeneralAllocator::SetAssertionFailureFunction - 0x802da53c (12 bytes)
// stw r5,0x4D4(r3); stw r4,0x4D0(r3)
// ============================================================================
void GeneralAllocator::SetAssertionFailureFunction(
    void (*func)(char*, void*), void* context) {
    *(void**)((char*)this + 0x4D4) = context;
    *(void**)((char*)this + 0x4D0) = (void*)func;
}

// ============================================================================
// GeneralAllocator::AssertionFailureFunctionDefault - 0x802da51c (32 bytes)
// Static function: calls TraceFunctionDefault (which is a no-op)
// The original calls the stub at 0x802da584
// ============================================================================
void GeneralAllocator::AssertionFailureFunctionDefault(char* msg, void* context) {
    TraceFunctionDefault(msg, context);
}

// ============================================================================
// GeneralAllocator::TraceFunctionDefault - 0x802da584 (4 bytes)
// Static function: empty stub (just blr)
// ============================================================================
void GeneralAllocator::TraceFunctionDefault(char* msg, void* context) {
}

// ============================================================================
// GeneralAllocator::AssertionFailure - 0x802da548 (60 bytes)
// Calls the assertion failure callback if set
// ============================================================================
void GeneralAllocator::AssertionFailure(char* msg) const {
    void (*func)(char*, void*) = *(void (**)(char*, void*))((char*)this + 0x4D0);
    if (func != 0) {
        void* context = *(void**)((char*)this + 0x4D4);
        func(msg, context);
    }
}

// ============================================================================
// GeneralAllocator::UnlinkCoreBlock - 0x802dc57c (28 bytes)
// Removes a core block from the doubly-linked list
// block->next->prev = block->prev
// block->prev->next = block->next
// ============================================================================
// NON_MATCHING - GCC optimizes out redundant reloads (5 insns vs original 7)
void GeneralAllocator::UnlinkCoreBlock(CoreBlock* block) {
    block->m_next->m_prev = block->m_prev;
    block->m_prev->m_next = block->m_next;
}

// ============================================================================
// GeneralAllocator::LinkCoreBlock - 0x802dc560 (28 bytes)
// Links a core block after 'after' in the doubly-linked list
// ============================================================================
void GeneralAllocator::LinkCoreBlock(CoreBlock* block, CoreBlock* after) {
    block->m_prev = after;
    CoreBlock* afterNext = after->m_next;
    block->m_next = afterNext;
    after->m_next = block;
    CoreBlock* blockNext = block->m_next;
    blockNext->m_prev = block;
}

// ============================================================================
// GeneralAllocator::FindCoreBlockForAddress - 0x802dc598 (64 bytes)
// Walks the core block list looking for one containing the given address
// Returns the CoreBlock or NULL
// ============================================================================
// NON_MATCHING - loop/branch structure may differ
GeneralAllocator::CoreBlock* GeneralAllocator::FindCoreBlockForAddress(void* addr) const {
    CoreBlock* sentinel = (CoreBlock*)((char*)this + 0x44C);
    CoreBlock* block = *(CoreBlock**)((char*)this + 0x46C);
    if (block == sentinel) {
        return 0;
    }
    while (1) {
        if ((unsigned int)addr >= (unsigned int)block) {
            unsigned int blockEnd = (unsigned int)block + block->m_size;
            if ((unsigned int)addr < blockEnd) {
                return block;
            }
        }
        block = block->m_next;
        if (block == sentinel) {
            break;
        }
    }
    return 0;
}

// ============================================================================
// GeneralAllocator::SetNewTopChunk - 0x802d9354 (60 bytes)
// Sets the top chunk, optionally links old top into free list
// ============================================================================
// NON_MATCHING - conditional return (beqlr) hard to match
void GeneralAllocator::SetNewTopChunk(Chunk* chunk, bool link) {
    Chunk* oldTop = *(Chunk**)((char*)this + 0x444);
    Chunk* sentinel = (Chunk*)((char*)this + 0x34);
    *(Chunk**)((char*)this + 0x444) = chunk;
    chunk->m_fd = chunk;
    chunk->m_bk = chunk;
    if (oldTop == sentinel) {
        return;
    }
    if (!link) {
        return;
    }
    // Link old top into the free list
    Chunk* sentFd = sentinel->m_bk;
    oldTop->m_fd = sentinel;
    oldTop->m_bk = sentFd;
    sentinel->m_bk = oldTop;
    sentFd->m_fd = oldTop;
}

// ============================================================================
// GeneralAllocator::AdjustTopChunk - 0x802d9390 (24 bytes)
// Adjusts the top chunk size and marks it
// ============================================================================
void GeneralAllocator::AdjustTopChunk(Chunk* chunk, unsigned int size) {
    unsigned int sizeWithFlag = size | 1;
    chunk->m_bk = (Chunk*)((unsigned int)chunk);
    chunk->m_size = sizeWithFlag;
    chunk->m_fd = chunk;
    // Store size at the end of the chunk (fence)
    *(unsigned int*)((char*)chunk + size) = size;
}

// ============================================================================
// GeneralAllocator::ChunkMatchesLowHigh - 0x802d93a8 (8 bytes)
// Always returns 1 (no high/low allocation distinction on NGC)
// ============================================================================
int GeneralAllocator::ChunkMatchesLowHigh(int flags, Chunk* chunk, unsigned int size) const {
    return 1;
}

// ============================================================================
// GeneralAllocator::SetFencepostAfterChunk - 0x802d93f8 (32 bytes)
// Creates fencepost markers after a chunk
// ============================================================================
void GeneralAllocator::SetFencepostAfterChunk(Chunk* chunk, unsigned int size) {
    // Store size at chunk boundary
    *(unsigned int*)((char*)chunk + size) = size;
    // Set up fencepost chunk after
    Chunk* fence = (Chunk*)((char*)chunk + size);
    fence->m_bk = (Chunk*)9;    // 0x0C = magic fencepost marker
    fence->m_fd = (Chunk*)8;    // 0x08
    fence->m_size = 8;          // 0x04
}

// ============================================================================
// GeneralAllocator::GetBlockInfoForCoreBlock - 0x802d94a0 (36 bytes)
// Fills a BlockInfo struct from a CoreBlock
// ============================================================================
void GeneralAllocator::GetBlockInfoForCoreBlock(CoreBlock* coreBlock, BlockInfo* info) const {
    info->m_type = 8;
    info->m_start = coreBlock->m_start;
    info->m_extra = 0;
    info->m_size = coreBlock->m_size;
}

// ============================================================================
// GeneralAllocator::GetUsableSize - 0x802dc4e0 (64 bytes)
// Returns the usable size of an allocated block
// ============================================================================
unsigned int GeneralAllocator::GetUsableSize(void* ptr) const {
    if (ptr == 0) {
        return 0;
    }
    // Chunk header is 8 bytes before the user pointer
    Chunk* chunk = (Chunk*)((char*)ptr - 8);
    unsigned int chunkSize = chunk->m_size & ~7u; // clear low 3 bits
    if (chunk->m_size & 2) {
        // MMap'd chunk - size minus header
        return chunkSize - 8;
    }
    // Check if next chunk's prev-in-use bit is set
    Chunk* nextChunk = (Chunk*)((char*)chunk + chunkSize);
    if (nextChunk->m_size & 1) {
        return chunkSize - 4;
    }
    return 0;
}

// ============================================================================
// GeneralAllocator::GetBlockSize - 0x802dc554 (12 bytes)
// Returns the chunk size from the header (4 bytes before user ptr)
// Clears low 3 bits
// ============================================================================
unsigned int GeneralAllocator::GetBlockSize(void* ptr) const {
    unsigned int raw = *(unsigned int*)((char*)ptr - 4);
    return raw & ~7u;
}

// ============================================================================
// GeneralAllocator::GetTotalCoreSize - 0x802dc520 (52 bytes)
// Walks core blocks summing up their sizes
// ============================================================================
unsigned int GeneralAllocator::GetTotalCoreSize(void) const {
    CoreBlock* block = *(CoreBlock**)((char*)this + 0x46C);
    CoreBlock* sentinel = (CoreBlock*)((char*)this + 0x44C);
    unsigned int total = 0;
    if (block == sentinel) {
        return total;
    }
    CoreBlock* sentEnd = sentinel;
    do {
        total += block->m_size;
        block = block->m_next;
    } while (block != sentEnd);
    return total;
}

// ============================================================================
// GeneralAllocator::DescribeData - 0x802da6e8 (36 bytes)
// Calls internal describe with ptr adjusted to chunk header
// ============================================================================
void GeneralAllocator::DescribeData(void* ptr, char* desc, unsigned int descSize) {
    // Adjust ptr back by 8 to get to chunk header
    DescribeDataInternal(this, (void*)((char*)ptr - 8), desc, descSize);
}

// ============================================================================
// GeneralAllocator::FreeSnapshot - 0x802daf38 (64 bytes)
// Frees a snapshot if it matches the expected magic and has no references
// ============================================================================
// NON_MATCHING - magic constant and branch structure
void GeneralAllocator::FreeSnapshot(void* snapshot) {
    unsigned int magic = *(unsigned int*)snapshot;
    if (magic != 0x534E4150) { // "SNAP"
        return;
    }
    unsigned int refCount = *(unsigned int*)((char*)snapshot + 0x0C);
    if (refCount != 0) {
        return;
    }
    ReleaseSnapshotInternal(this);
}

// ============================================================================
// GeneralAllocator::SetAutoHeapValidation - 0x802db0e8 (36 bytes)
// Sets validation level and frequency
// ============================================================================
void GeneralAllocator::SetAutoHeapValidation(HeapValidationLevel level, unsigned int freq) {
    *(unsigned int*)((char*)this + 0x48C) = freq;
    if (freq == 0) {
        *(unsigned int*)((char*)this + 0x48C) = 1;
    }
    *(unsigned int*)((char*)this + 0x488) = (unsigned int)level;
    *(unsigned int*)((char*)this + 0x490) = 0;
}

// ============================================================================
// GeneralAllocator::MMapFree - 0x802dcaf0 (36 bytes)
// Frees MMap'd memory by calling free()
// ============================================================================
void GeneralAllocator::MMapFree(void* ptr, unsigned int size) {
    free(ptr);
}

} // namespace Allocator
} // namespace EA

// ============================================================================
// PPM_VERIFY - 0x802d8740 (12 bytes)
// Returns 1 if condition is true, 0 if false
// subfic r0,r4,0; adde r3,r0,r4
// This is a clever PPC idiom: ((-x) + x + carry) = (x != 0 ? 1 : 0)
// ============================================================================
int PPM_VERIFY(EA::Allocator::GeneralAllocator* alloc, bool condition) {
    return condition ? 1 : 0;
}

// ============================================================================
// PPMMutexCreate - 0x802d874c (48 bytes)
// Initializes an OS mutex, returns the mutex pointer
// ============================================================================
// NON_MATCHING - OSInitMutex call linkage
void* PPMMutexCreate(void* mutex) {
    OSInitMutex(mutex);
    return mutex;
}

// ============================================================================
// PPMMutexDestroy - 0x802d877c (4 bytes)
// Empty stub - just returns (blr)
// ============================================================================
void PPMMutexDestroy(void* mutex) {
}

// ============================================================================
// PPMMutexLock - 0x802d8780 (48 bytes)
// Locks the OS mutex and returns the lock count
// ============================================================================
// NON_MATCHING - register usage for lock count return
int PPMMutexLock(void* mutex) {
    OSLockMutex(mutex);
    return *(int*)((char*)mutex + 0x0C);
}

// ============================================================================
// PPMMutexUnlock - 0x802d87b0 (52 bytes)
// Gets lock count-1, unlocks, returns previous lock count - 1
// ============================================================================
// NON_MATCHING - register usage
int PPMMutexUnlock(void* mutex) {
    int lockCount = *(int*)((char*)mutex + 0x0C) - 1;
    OSUnlockMutex(mutex);
    return lockCount;
}

// ============================================================================
// PPMMutexGetLockCount - 0x802d87e4 (8 bytes)
// Returns lock count from mutex at offset 0x0C
// ============================================================================
int PPMMutexGetLockCount(void* mutex) {
    return *(int*)((char*)mutex + 0x0C);
}
