/**
 * FastAllocPool / ProtectedAllocPool / AllocPoolManager — Decompiled Implementation
 *
 * Source: src/core/fastallocpool_decomp.cpp
 * Headers: include/core/fastallocpool.h, include/core/eaheap.h
 * Original ELF: extracted/files/u2_ngc_release_dvd.elf
 * Compiler: SN Systems ProDG for GameCube
 *
 * This file contains decompiled implementations of the larger/more complex
 * functions in the pool allocator system. The simpler functions (getters,
 * Alloc, Free, BlockIsInPool) already exist in src/core/fastallocpool.cpp.
 *
 * ============================================================================
 * ARCHITECTURE OVERVIEW
 * ============================================================================
 *
 * FastAllocPool is a fixed-block-size free-list pool allocator used by EAHeap
 * for small allocations (up to 64 bytes). It divides a contiguous memory region
 * into equal-sized blocks and chains free blocks via an intrusive linked list.
 *
 * ProtectedAllocPool wraps FastAllocPool with an EThreadMutex for thread safety.
 * It adds a mutex at offset 0x18 (after the base class's 0x18 bytes).
 *
 * AllocPoolManager<T> manages 8 pools (one per 8-byte size class: 8, 16, 24,
 * ..., 64) and is used by EAHeap to service small allocations.
 *
 * Memory layout of a free block (8 bytes minimum):
 *   +0x00: u32 magic   ('EERF' = 0x45455246 when free, 'DESU' = 0x44455355 when allocated)
 *   +0x04: void* next   (pointer to next free block, or NULL if last)
 *
 * ============================================================================
 * POOL LAYOUT IN AllocPoolManager
 * ============================================================================
 *
 * AllocPoolManager<ProtectedAllocPool>:
 *   0x00: void* m_poolMemory      — base of allocated pool memory block
 *   0x04: void* m_poolEnd         — end of pool memory region
 *   0x08: ProtectedAllocPool[8]   — 8 pools, each 0x34 (52) bytes = 416 bytes total
 *
 * AllocPoolManager<FastAllocPool>:
 *   0x00: void* m_poolMemory
 *   0x04: void* m_poolEnd
 *   0x08: FastAllocPool[8]        — 8 pools, each 0x18 (24) bytes = 192 bytes total
 *
 * Pool initialization order: 7, 3, 5, 1, 0, 2, 4, 6
 * This interleaved order creates an implicit binary search tree for
 * FindPoolForBlock — enabling O(log n) pool lookup by address.
 *
 * Pool bin mapping: index = (requestedSize - 1) >> 3
 *   Pool 0: 1-8 bytes (block size 8)
 *   Pool 1: 9-16 bytes (block size 16)
 *   Pool 2: 17-24 bytes (block size 24)
 *   Pool 3: 25-32 bytes (block size 32)
 *   Pool 4: 33-40 bytes (block size 40)
 *   Pool 5: 41-48 bytes (block size 48)
 *   Pool 6: 49-56 bytes (block size 56)
 *   Pool 7: 57-64 bytes (block size 64)
 */

#include "core/fastallocpool.h"
#include "core/eaheap.h"

// Magic values (also defined in fastallocpool.cpp)
#define FAST_ALLOC_MAGIC_USED  0x44455355  // "DESU" - marks allocated block
#define FAST_ALLOC_MAGIC_FREE  0x45455246  // "EERF" - marks freed block

// External functions
extern "C" int OSIsDebuggerPresent(void);  // 0x8023e514


// ============================================================================
// FastAllocPool::FastAllocPool(char*, void*, int, int)
// Address: 0x802D6F7C | Size: 116 bytes (29 instructions)
//
// Constructor. Zeroes all fields, sets vtable. If poolMemory, blockSize,
// and numBlocks are all non-null/non-zero, calls Init().
//
// The 'name' parameter is unused in this release build (SN Systems strips
// debug strings in release). It exists only in the debug build.
//
// Arguments (PowerPC register ABI):
//   r3 = this
//   r4 = name (char*) — stripped/unused in release
//   r5 = poolMemory (void*)
//   r6 = blockSize (int)
//   r7 = numBlocks (int)
//
// Decompiled logic:
//   Set vtable to FastAllocPool vtable (0x8046A2D8)
//   Zero: m_alignment, m_poolStart, m_freeList, m_poolBlocks, m_blockSize
//   If poolMemory && blockSize && numBlocks: call Init(poolMemory, blockSize, numBlocks)
//   Return this
// ============================================================================
// NON_MATCHING: SN Systems places vtable at offset 0x14; GCC puts it at 0x00
FastAllocPool::FastAllocPool() {
    m_poolStart  = 0;
    m_freeList   = 0;
    m_poolBlocks = 0;
    m_blockSize  = 0;
    m_alignment  = 0;
    m_vtablePtr  = 0;  // Would be 0x8046A2D8 in original
}


// ============================================================================
// FastAllocPool::Init(void*, int, int)
// Address: 0x802D7024 | Size: 112 bytes (28 instructions)
//
// Initializes the pool. Computes alignment, stores parameters, then
// builds the free list by walking through the pool memory and chaining
// each block with 'EERF' magic headers.
//
// Alignment computation:
//   combined = blockSize | (poolMemory & 0x00FFFFFF)
//   alignment = combined & (-combined)    // isolate lowest set bit
//
// Free list is built in reverse order — last block is pushed first,
// so Alloc will return blocks from the END of the pool first.
//
// The original function signature in the header is:
//   void Init(void* pool, int blockSize, int numBlocks, int alignment)
// But the disassembly shows only 3 args (r4=pool, r5=blockSize, r6=numBlocks)
// with alignment computed internally. The 4th param in the header is unused.
//
// Register mapping:
//   r3 = this
//   r4 = poolMemory
//   r5 = blockSize
//   r6 = numBlocks
//
// Key instructions:
//   0x802D7024: clrlwi r0, r4, 8       — r0 = poolMemory & 0x00FFFFFF
//   0x802D702C: or r0, r5, r0          — r0 = blockSize | r0
//   0x802D7034: neg r9, r0             — r9 = -r0
//   0x802D703C: and r0, r0, r9         — alignment = r0 & (-r0)
//   0x802D7044: stw r0, 0x10(r3)       — m_alignment = alignment
//   0x802D7048: mr r9, r4              — r9 = poolMemory (loop cursor)
//   0x802D704C: stw r4, 0x00(r3)       — m_poolStart = poolMemory
//   0x802D7050: stw r6, 0x08(r3)       — m_poolBlocks = numBlocks
//   0x802D7054: stw r5, 0x0C(r3)       — m_blockSize = blockSize
//
// Free list build loop (0x802D705C-708C):
//   for each block (0 to numBlocks):
//     if blockPtr != NULL:
//       *(u32*)(blockPtr + 0) = MAGIC_FREE   // 'EERF'
//       *(void**)(blockPtr + 4) = m_freeList  // link to previous head
//       m_freeList = blockPtr                  // new head
//     blockPtr += blockSize
//
// Returns via bgelr after storing fields (no explicit return value).
// ============================================================================
// NON_MATCHING: The original uses bgelr (conditional return) after storing
// fields, before entering the loop. This is an optimization the SN compiler
// generates when numBlocks == 0.
void FastAllocPool_Init(FastAllocPool* self, void* pool, int blockSize, int numBlocks) {
    // Compute alignment: isolate lowest set bit of (blockSize | low24bits(pool))
    unsigned int addrBits = ((unsigned int)pool) & 0x00FFFFFF;
    unsigned int combined = (unsigned int)blockSize | addrBits;
    self->m_alignment = (int)(combined & (unsigned int)(-(int)combined));

    // Store pool parameters
    self->m_freeList   = 0;
    self->m_poolStart  = pool;
    self->m_poolBlocks = numBlocks;
    self->m_blockSize  = blockSize;

    // Build free list: chain all blocks from start to end
    unsigned char* blockPtr = (unsigned char*)pool;
    for (int i = 0; (unsigned int)i < (unsigned int)numBlocks; i++) {
        if (blockPtr != 0) {
            // Stamp free magic
            *(unsigned int*)(blockPtr + 0) = FAST_ALLOC_MAGIC_FREE;
            // Link to current head
            *(void**)(blockPtr + 4) = self->m_freeList;
            // Push as new head
            self->m_freeList = blockPtr;
        }
        blockPtr += blockSize;
    }
}


// ============================================================================
// FastAllocPool::Valid(void)
// Address: 0x802D7094 | Size: 248 bytes (62 instructions)
//
// Validates the pool's free list integrity. Walks the entire free list and
// checks that every node's address falls within [poolStart, poolStart + size).
//
// Triggers a debug assert (intentional null deref crash) if validation fails.
// Returns 1 if valid, 0 if corrupt.
//
// The validation is two-phase:
//   Phase 1: Check free list head is within pool bounds
//   Phase 2: Walk the linked list, checking each node
//
// The bounds check uses the PPC branchless idiom:
//   subfc r, poolEnd, nodeAddr  — sets carry if poolEnd <= nodeAddr
//   subfe r, r, r               — r = -1 if carry set, 0 otherwise
//   neg r, r                    — r = 1 if nodeAddr < poolEnd, 0 otherwise
//
// Debug assert pattern:
//   bl OSIsDebuggerPresent
//   if (result) *(volatile u32*)0 = 0;   // crash to break into debugger
//   .long 0x00000001                      // assert metadata
// ============================================================================
// NON_MATCHING: Debug assert code (.long 0x1) is embedded data, not reproducible
int FastAllocPool_Valid(FastAllocPool* self) {
    // Phase 1: Validate free list head
    void* node = self->m_freeList;
    if (node != 0) {
        int inRange = 0;
        if ((unsigned int)node >= (unsigned int)self->m_poolStart) {
            unsigned int poolEnd = (unsigned int)self->m_poolStart
                + (unsigned int)self->m_blockSize * (unsigned int)self->m_poolBlocks;
            inRange = ((unsigned int)node < poolEnd) ? 1 : 0;
        }
        if (inRange == 0) {
            // Debug assert: free list head is outside pool bounds
            if (OSIsDebuggerPresent()) {
                *(volatile unsigned int*)0 = 0;
            }
            return 0;
        }
    }

    // Phase 2: Walk entire free list
    void* current = self->m_freeList;
    if (current != 0) {
        for (;;) {
            void* next = *(void**)((char*)current + 4);
            if (next == 0) {
                break;  // end of list
            }

            int nextInRange = 0;
            if ((unsigned int)next >= (unsigned int)self->m_poolStart) {
                unsigned int poolEnd = (unsigned int)self->m_poolStart
                    + (unsigned int)self->m_blockSize * (unsigned int)self->m_poolBlocks;
                nextInRange = ((unsigned int)next < poolEnd) ? 1 : 0;
            }
            if (nextInRange == 0) {
                // Debug assert: free list node is outside pool bounds
                if (OSIsDebuggerPresent()) {
                    *(volatile unsigned int*)0 = 0;
                }
                return 0;
            }
            current = next;
        }
    }

    return 1;  // all nodes valid
}


// ============================================================================
// AllocPoolManager<FastAllocPool>::InitPoolByIndex
// Address: 0x803C1FAC | Size: 108 bytes (27 instructions)
//
// Initializes a single pool within the manager at the given bin index.
//
// Arguments:
//   r3 = this (AllocPoolManager)
//   r4 = poolIndex (0-7: which size bin)
//   r5 = blockCounts (u32[8]: how many blocks for each bin)
//   r6 = memCursor (u8*: current write position in pool memory)
//
// Returns: updated memCursor pointing past the initialized pool.
//
// The pool at bin index i has:
//   blockSize = (i + 1) * 8
//   numBlocks = blockCounts[i]
//   startAddr = memCursor
//
// Pool lives at: manager + 8 + poolIndex * sizeof(FastAllocPool)
//                manager + 8 + poolIndex * 24
// ============================================================================
void* AllocPoolManager_Fast_InitPoolByIndex(
    void* self, int poolIndex, unsigned int* blockCounts, unsigned char* memCursor)
{
    // Pool address in array: self + 8 + poolIndex * 24
    int poolOffset = poolIndex * 24;  // sizeof(FastAllocPool) = 0x18
    FastAllocPool* pool = (FastAllocPool*)((char*)self + poolOffset + 8);

    // Block count for this pool
    unsigned int numBlocks = blockCounts[poolIndex];

    // Block size: (poolIndex + 1) * 8
    int blockSize = (poolIndex + 1) * 8;

    // Initialize the pool
    FastAllocPool_Init(pool, memCursor, blockSize, (int)numBlocks);

    // Advance cursor past pool memory
    unsigned int poolSize = (unsigned int)pool->m_blockSize * (unsigned int)pool->m_poolBlocks;
    return memCursor + poolSize;
}


// ============================================================================
// AllocPoolManager<FastAllocPool>::InitAllocPools
// Address: 0x803C2018 | Size: 296 bytes (74 instructions)
//
// Master initialization for all 8 pool bins. Called once during
// EAHeap::InitializeHeapStatics.
//
// Steps:
//   1. If already initialized (m_poolMemory != 0), return
//   2. Calculate total memory: sum of blockCounts[i] * (i+1) * 8 for i=0..7
//   3. Allocate total memory from MainHeap with 64-byte alignment
//   4. Initialize pools in interleaved order: 7, 3, 5, 1, 0, 2, 4, 6
//   5. Store end pointer (m_poolEnd)
//
// The interleaved init order means pools are physically laid out:
//   [7][3][5][1][0][2][4][6]
// This creates an implicit balanced binary search tree for FindPoolForBlock.
//
// Arguments:
//   r3 = this (AllocPoolManager)
//   r4 = blockCounts (u32[8])
// ============================================================================
void AllocPoolManager_Fast_InitAllocPools(void* self, unsigned int* blockCounts) {
    unsigned int* mgr = (unsigned int*)self;

    // Check if already initialized
    if (mgr[0] != 0) {
        return;
    }

    // Calculate total memory needed
    unsigned int totalSize = 0;
    for (int i = 0; i < 8; i++) {
        unsigned int blockSize = (unsigned int)(i + 1) * 8;
        totalSize += blockCounts[i] * blockSize;
    }

    // Allocate pool memory from MainHeap, 64-byte aligned
    EAHeap* heap = MainHeap();
    void* poolMem = heap->MallocAligned(totalSize, 64, 0, 0);
    mgr[0] = (unsigned int)poolMem;

    // Initialize pools in interleaved order: 7, 3, 5, 1, 0, 2, 4, 6
    unsigned char* cursor = (unsigned char*)poolMem;
    cursor = (unsigned char*)AllocPoolManager_Fast_InitPoolByIndex(self, 7, blockCounts, cursor);
    cursor = (unsigned char*)AllocPoolManager_Fast_InitPoolByIndex(self, 3, blockCounts, cursor);
    cursor = (unsigned char*)AllocPoolManager_Fast_InitPoolByIndex(self, 5, blockCounts, cursor);
    cursor = (unsigned char*)AllocPoolManager_Fast_InitPoolByIndex(self, 1, blockCounts, cursor);
    cursor = (unsigned char*)AllocPoolManager_Fast_InitPoolByIndex(self, 0, blockCounts, cursor);
    cursor = (unsigned char*)AllocPoolManager_Fast_InitPoolByIndex(self, 2, blockCounts, cursor);
    cursor = (unsigned char*)AllocPoolManager_Fast_InitPoolByIndex(self, 4, blockCounts, cursor);
    cursor = (unsigned char*)AllocPoolManager_Fast_InitPoolByIndex(self, 6, blockCounts, cursor);

    // Store pool end pointer
    mgr[1] = (unsigned int)cursor;
}


// ============================================================================
// AllocPoolManager<FastAllocPool>::AttemptPoolAlloc(u32 size, u32 alignment)
// Address: 0x803C22F4 | Size: 116 bytes (29 instructions)
//
// Tries to allocate from a pool. If size > 64, returns NULL immediately.
// Otherwise computes bin index and tries that pool and larger ones.
//
// This FastAllocPool version inlines the alloc — no mutex needed.
// The alloc is just: pop free list head, stamp 'DESU' magic.
//
// Arguments:
//   r3 = this (AllocPoolManager)
//   r4 = size
//   r5 = alignment
//
// Returns: allocated pointer, or NULL if all pools exhausted
//
// Key instructions:
//   0x803C22F4: cmplwi r4, 64         — if size > 64, return NULL
//   0x803C2304: addi r0, r4, -1
//   0x803C2308: srwi r4, r0, 3        — binIndex = (size - 1) >> 3
//   0x803C2328-235C: loop from binIndex to 7
//     Check pool->m_alignment >= requested alignment
//     Try to pop from pool's free list (inlined Alloc)
//     If empty, try next larger bin
// ============================================================================
void* AllocPoolManager_Fast_AttemptPoolAlloc(void* self, unsigned int size, unsigned int alignment) {
    if (size > 64) {
        return 0;
    }

    int binIndex = (int)((size - 1) >> 3);
    if (binIndex > 7) {
        return 0;
    }

    while (binIndex <= 7) {
        FastAllocPool* pool = (FastAllocPool*)((char*)self + 8 + binIndex * 24);

        // Check alignment requirement
        if (alignment <= (unsigned int)pool->m_alignment) {
            // Inline FastAllocPool::Alloc
            void* block = pool->m_freeList;
            if (block != 0) {
                // Pop from free list
                pool->m_freeList = *(void**)((char*)block + 4);
                // Stamp allocated magic
                *(unsigned int*)block = FAST_ALLOC_MAGIC_USED;
                return block;
            }
        }

        binIndex++;
    }

    return 0;
}


// ============================================================================
// AllocPoolManager<FastAllocPool>::FindPoolForBlock(void*)
// Address: 0x803C2368 | Size: 160 bytes (40 instructions)
//
// Given a pointer, finds which pool it belongs to using a hardcoded
// binary search tree over pool address ranges.
//
// The pools are stored in interleaved order [7,3,5,1,0,2,4,6] in memory.
// The binary search uses pool start addresses (m_poolStart at offset 0x00
// within each pool) as split points.
//
// For FastAllocPool (24 bytes each):
//   Slot 0 (pool 7): self+0x08, m_poolStart at self+0x08
//   Slot 1 (pool 3): self+0x20, m_poolStart at self+0x20
//   Slot 2 (pool 5): self+0x38, m_poolStart at self+0x38
//   Slot 3 (pool 1): self+0x50, m_poolStart at self+0x50
//   Slot 4 (pool 0): self+0x68, m_poolStart at self+0x68
//   Slot 5 (pool 2): self+0x80, m_poolStart at self+0x80
//   Slot 6 (pool 4): self+0x98, m_poolStart at self+0x98
//   Slot 7 (pool 6): self+0xB0, m_poolStart at self+0xB0
//
// The search tree navigates using offsets into these slots:
//   Root: check against slot 0 start (self+0x08)
//   Left subtree: slots with lower addresses
//   Right subtree: slots with higher addresses
//
// Returns: pointer to the FastAllocPool containing the block, or NULL
//
// Arguments:
//   r3 = this
//   r4 = ptr to find
// ============================================================================
FastAllocPool* AllocPoolManager_Fast_FindPoolForBlock(void* self, void* ptr) {
    unsigned int addr = (unsigned int)ptr;
    unsigned int* mgr = (unsigned int*)self;

    // Range check: is ptr within [poolMemory, poolEnd)?
    if (addr < mgr[0] || addr >= mgr[1]) {
        return 0;
    }

    // Binary search through the interleaved pool layout
    // The disassembly uses hardcoded offsets from self for the search.
    // This is a flattened binary search tree over the 8 pool slots.

    // The exact tree structure from the disassembly (offsets are from self):
    //
    //         slot0 (0x08)
    //        /           \
    //   right_subtree    left_subtree
    //
    // Each node compares ptr against the pool's m_poolStart and navigates
    // to find the pool whose address range contains ptr.

    // For a PC port, this can be simplified to a linear scan:
    for (int i = 0; i < 8; i++) {
        FastAllocPool* pool = (FastAllocPool*)((char*)self + 8 + i * 24);
        if (pool->BlockIsInPool(ptr)) {
            return pool;
        }
    }
    return 0;
}


// ============================================================================
// AllocPoolManager<FastAllocPool>::Validate(void)
// Address: 0x803C2408 | Size: 64 bytes (16 instructions)
//
// Iterates over all 8 pools and calls FastAllocPool::Valid() on each.
// Simple counted loop with stride = sizeof(FastAllocPool) = 24.
//
// 0x803C240C: addi r31, r3, 8        — start at first pool
// 0x803C2410: li r30, 8              — 8 pools to check
// Loop:
//   0x803C2414: mr r3, r31
//   0x803C2418: bl FastAllocPool::Valid
//   0x803C241C: addi r31, r31, 24    — advance to next pool
//   0x803C2420: addic. r30, r30, -1  — decrement counter
//   0x803C2424: bne loop
// ============================================================================
// Already implemented in src/core/eaheap.cpp as template specialization


// ============================================================================
// ProtectedAllocPool::Alloc(void)
// Address: 0x802D7250 | Size: 120 bytes (30 instructions)
//
// Thread-safe allocation. Acquires the mutex at this+0x18, calls
// FastAllocPool::Alloc (base class), then releases the mutex.
//
// The lock/unlock mechanism uses virtual dispatch through the mutex's vtable:
//   1. Load vtable from mutex object at this+0x18
//   2. Read 'this' adjustment (s16 at vtable+0x10) and function ptr (vtable+0x14)
//   3. Adjust 'this' = mutexAddr + adjustment
//   4. Call function via blrl
//
// This is the SN Systems C++ virtual call convention for multiple inheritance.
//
// Lock: vtable[+0x10] = this_offset, vtable[+0x14] = lock_func_ptr
//   Called with adjusted_this and r4=-1 (INFINITE wait timeout)
//
// Unlock: vtable[+0x18] = this_offset, vtable[+0x1C] = unlock_func_ptr
//   Called with adjusted_this
//
// In pseudocode:
//   mutex = this + 0x18
//   mutex->Lock(-1)        // infinite wait
//   result = FastAllocPool::Alloc()
//   mutex->Unlock()
//   return result
// ============================================================================
// NON_MATCHING: Cannot reproduce SN Systems vtable dispatch with GCC


// ============================================================================
// ProtectedAllocPool::Free(void*)
// Address: 0x802D72C8 | Size: 120 bytes (30 instructions)
//
// Thread-safe free. Same lock/unlock pattern as Alloc.
//
//   mutex = this + 0x18
//   mutex->Lock(-1)
//   FastAllocPool::Free(ptr)
//   mutex->Unlock()
// ============================================================================
// NON_MATCHING: Cannot reproduce SN Systems vtable dispatch with GCC


// ============================================================================
// ProtectedAllocPool::ProtectedAllocPool(char*, void*, int, int)
// Address: 0x802D718C | Size: 68 bytes (17 instructions)
//
// Constructor:
//   1. Call FastAllocPool::FastAllocPool(name, pool, blockSize, numBlocks)
//   2. Override vtable to ProtectedAllocPool vtable (0x8046A2C0)
//   3. Construct EThreadMutex at this+0x18 (call 0x802cb914)
// ============================================================================
// NON_MATCHING: SN Systems vtable placement + mutex construction


// ============================================================================
// ProtectedAllocPool::~ProtectedAllocPool(void)
// Address: 0x802D71D0 | Size: 80 bytes (20 instructions)
//
// Destructor:
//   1. Set vtable to ProtectedAllocPool vtable
//   2. Destroy EThreadMutex at this+0x18 (call 0x802cb96c with mode=2)
//   3. Call FastAllocPool::~FastAllocPool(flags)
// ============================================================================
// NON_MATCHING: SN Systems vtable + mutex destruction


// ============================================================================
// AllocPoolManager<ProtectedAllocPool>::AttemptPoolAlloc(u32, u32)
// Address: 0x803C2140 | Size: 212 bytes (53 instructions)
//
// Same logic as the FastAllocPool version but uses protected dispatch:
//   1. Check size > 64 → return NULL
//   2. Compute binIndex = (size - 1) >> 3
//   3. For each pool from binIndex to 7:
//      a. Check pool->m_alignment >= requested alignment
//      b. Lock the pool's mutex (vtable dispatch)
//      c. Call FastAllocPool::Alloc() (base class, unprotected)
//      d. Unlock the pool's mutex
//      e. If alloc succeeded, return the block
//      f. If not, try next larger pool
//   4. Return NULL if all pools exhausted
//
// The mutex lock/unlock pattern adds ~20 instructions of overhead per
// attempt compared to the FastAllocPool version. This is why the game
// uses FastAllocPool for single-threaded paths.
//
// Pool stride for ProtectedAllocPool = 0x34 (52 bytes)
// ============================================================================
// NON_MATCHING: Requires SN Systems vtable dispatch for mutex lock/unlock


// ============================================================================
// SUMMARY: Pool Allocation Fast Path
// ============================================================================
//
// 1. EAHeap::Malloc(size) is called
// 2. If size <= 64, try AttemptPoolAlloc on the ProtectedAllocPool manager:
//    a. Compute bin = (size-1) / 8
//    b. Lock the pool's mutex
//    c. Pop head of free list (just pointer swap + magic stamp)
//    d. Unlock
//    e. If pool was empty, try next larger bin
// 3. If pool alloc fails, fall through to GeneralAllocator (PPMalloc)
// 4. If GeneralAllocator fails, try child heaps (m_parentHeap, m_auxHeap)
//
// For Free:
// 1. Check if the pointer belongs to a pool (FindPoolForBlock)
// 2. If yes, lock pool → push onto free list → stamp 'EERF' → unlock
// 3. If no, find which heap owns it (FindHeapForAddress) and free via GA
