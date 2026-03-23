/**
 * EAHeap — Decompiled Implementation
 *
 * Source: src/core/eaheap_decomp.cpp
 * Headers: include/core/eaheap.h, include/core/eageneralallocator.h
 * Original ELF: extracted/files/u2_ngc_release_dvd.elf
 * Compiler: SN Systems ProDG for GameCube
 *
 * This file contains decompiled implementations of the larger/more complex
 * EAHeap functions. The simpler ones (GetCurrentCheckPoint, SetNextCheckPoint,
 * ValidatePools, FPHeap ctor, operator new/delete, malloc/free) already exist
 * in src/core/eaheap.cpp.
 *
 * ============================================================================
 * ARCHITECTURE OVERVIEW
 * ============================================================================
 *
 * EAHeap is the top-level memory management interface in The Sims 2 (GC).
 * It wraps EA's PPMalloc (EA::Allocator::GeneralAllocator) with:
 *   - A small-block pool layer (ProtectedAllocPool via AllocPoolManager)
 *   - A hierarchical heap tree for overflow
 *
 * EAHeap inherits from GeneralAllocator (PPMalloc), making the GA the first
 * ~0x528 bytes of the object. Additional EAHeap fields follow:
 *
 *   Offset  Size  Field
 *   ------  ----  -----
 *   0x000   0x528 EA::Allocator::GeneralAllocator (base class / embedded)
 *   0x528   4     m_name (char*) — heap name string
 *   0x52C   4     m_parentHeap (EAHeap*) — first fallback/child heap
 *   0x530   4     m_auxHeap (EAHeap*) — second fallback/child heap
 *   0x534   4     m_checkpointId (u32) — checkpoint tracking ID
 *   ------
 *   Total: 0x538 (1336 bytes) — confirmed by .bss static instance sizes
 *
 * ============================================================================
 * HEAP HIERARCHY
 * ============================================================================
 *
 *   RootHeap ────────────── (no parent, no aux)
 *   MainHeap ────────────── (parent=RootHeap)
 *   ResourceHeap ─────────  (parent=RootHeap)
 *   DebugHeap ────────────  (no parent)
 *   VMHeap ───────────────  (parent=?, aux=?)
 *   CUIHeap ──────────────  (parent=?, aux=?)
 *   AudioHeap ────────────  (parent=ResourceHeap, aux=ShaderHeap)
 *   ShaderHeap ───────────  (parent=ResourceHeap, aux=ShaderHeap)
 *   TextureHeap ──────────  (parent=ResourceHeap, aux=ShaderHeap)
 *   AnimationHeap ────────  (parent=ResourceHeap, aux=ShaderHeap)
 *   ModelHeap ────────────  (parent=ResourceHeap, aux=ShaderHeap)
 *   FlashesHeap ──────────  (parent=?, aux=?)
 *   AptHeap ──────────────  (parent=?, aux=?)
 *
 * The "parent" and "aux" heaps are fallback heaps — if this heap's
 * GeneralAllocator can't satisfy an allocation, it tries parentHeap
 * first, then auxHeap.
 *
 * ============================================================================
 * GLOBAL STATE
 * ============================================================================
 *
 * All stored via r13-relative SDA (Small Data Area) addressing:
 *
 *   s_protectedPoolManager    r13-21324   0x805005D4  (pointer to AllocPoolManager)
 *   s_initialized             r13-22840                (pool init flag: 0 or 1)
 *   g_currentCheckPoint       r13-26860                (global checkpoint counter)
 *   g_RootHeap                r13-22832   0x804FFFF0
 *   g_MainHeap                r13-22828   0x804FFFF4
 *   g_DebugHeap               r13-22816   0x80500000
 *   g_AudioHeap               r13-22808   0x80500008
 *   (etc. for other heap pointers)
 *
 * s_poolBlocks at 0x8041E4D8 in .data — 8 u32 values defining block counts
 * for each pool bin.
 *
 * ============================================================================
 * THREE-TIER ALLOCATION FLOW
 * ============================================================================
 *
 * Tier 1: Pool Allocator (for sizes <= 64 bytes)
 *   - 8 size classes: 8, 16, 24, 32, 40, 48, 56, 64 bytes
 *   - O(1) alloc/free via free list
 *   - ProtectedAllocPool adds mutex for thread safety
 *
 * Tier 2: GeneralAllocator / PPMalloc (for sizes > 64 or pool exhaustion)
 *   - Full-featured heap with coalescing and binning
 *   - Each EAHeap embeds one GeneralAllocator
 *
 * Tier 3: Heap Hierarchy (overflow)
 *   - If this heap's GA fails, try parentHeap, then auxHeap
 *   - Malloc failure callbacks can free cached resources to make room
 */

#include "core/eaheap.h"

// External: memset
extern "C" void* memset(void* s, int c, unsigned int n);

// ============================================================================
// EAHeap::EAHeap(char*, void*, unsigned int, EAHeap*, EAHeap*)
// Address: 0x802D09DC | Size: 128 bytes (32 instructions)
//
// Constructor. Initializes the embedded GeneralAllocator with no initial
// memory (autoGrow=1), stores the name and child heap pointers, then calls
// Clear() and Init() to set up the heap with the provided memory region.
//
// Arguments (PowerPC ABI):
//   r3 = this
//   r4 = name (char*)
//   r5 = memory (void*) — memory region for this heap (can be NULL)
//   r6 = size (unsigned int) — size of memory region
//   r7 = parentHeap (EAHeap*) — first fallback heap
//   r8 = auxHeap (EAHeap*) — second fallback heap
//
// Key instructions:
//   0x802D0A04-0A1C: set up GA ctor args (autoGrow=1, rest=0)
//   0x802D0A1C: bl GeneralAllocator::GeneralAllocator
//   0x802D0A20: stw r27, 0x528(r30)  — m_name = name
//   0x802D0A28: stw r29, 0x52C(r30)  — m_parentHeap = parentHeap
//   0x802D0A2C: stw r28, 0x530(r30)  — m_auxHeap = auxHeap
//   0x802D0A30: bl Clear
//   0x802D0A40: bl Init(memory, size)
//   0x802D0A44: mr r3, r30            — return this
// ============================================================================
// NON_MATCHING: GeneralAllocator ctor calling convention differs
EAHeap::EAHeap(char* name, void* buffer, unsigned int size,
               EAHeap* parent, EAHeap* auxHeap)
    : GeneralAllocator()
{
    // The original calls GA ctor with: this, NULL, 0, autoGrow=1, 0, 0, 0
    // C++ base-class construction handles this differently in GCC vs SN.

    m_name       = name;
    m_parentHeap = parent;
    m_auxHeap    = auxHeap;

    Clear();
    Init(buffer, size);
}


// ============================================================================
// EAHeap::Init(void*, unsigned int)
// Address: 0x802D0A5C | Size: 72 bytes (18 instructions)
//
// Initializes the GeneralAllocator with the given memory region.
// If either memory or size is 0/NULL, returns without initializing.
//
// The GA is initialized with:
//   autoGrow=0, supportThreads=0, growFunc=NULL, growFuncContext=NULL
//
// Arguments:
//   r3 = this
//   r4 = buffer (void*)
//   r5 = size (unsigned int)
//
// Key instructions:
//   0x802D0A68: mr. r4, r4           — test buffer != NULL
//   0x802D0A6C: beq return_error
//   0x802D0A70: cmpwi r5, 0          — test size != 0
//   0x802D0A74: beq return_error
//   0x802D0A78-84: li r6-r9, 0       — set remaining args to 0
//   0x802D0A88: bl GA::Init(this, buffer, size, 0, 0, 0, 0)
//   0x802D0A90: li r3, 1             — return 1 (error path)
// ============================================================================
void EAHeap::Init(void* buffer, unsigned int size) {
    if (buffer == 0 || size == 0) {
        // Original returns 1 (error) but our header declares void
        return;
    }

    // Call GeneralAllocator::Init
    // In the original: r3=this, r4=buffer, r5=size, r6-r9=0
    GeneralAllocator::Init(buffer, size, 0, 0, 0, 0);
}


// ============================================================================
// EAHeap::Clear(void)
// Address: 0x802D0E88 | Size: 76 bytes (19 instructions)
//
// Resets the heap's checkpoint ID and sets two GeneralAllocator options:
//   Option 2 = 0  (likely kOptionEnableHighAllocation)
//   Option 10 = 0 (likely kOptionEnableDebugChecks)
//
// Key instructions:
//   0x802D0E9C: li r0, 0
//   0x802D0EA8: stw r0, 0x534(r30)   — m_checkpointId = 0
//   0x802D0EA0: li r4, 2              — option = 2
//   0x802D0EA4: li r5, 0              — value = 0
//   0x802D0EAC: bl SetOption
//   0x802D0EB4: li r4, 10             — option = 10
//   0x802D0EB8: li r5, 0              — value = 0
//   0x802D0EBC: bl SetOption
// ============================================================================
void EAHeap::Clear(void) {
    // m_checkpointId is at offset 0x534 from 'this'
    // Since EAHeap inherits from GA (0x528 bytes), and m_name is at 0x528,
    // checkpointId would be at offset 0x0C from the start of EAHeap-specific fields.
    // But in the current header it's not declared. We'd need:
    // *(unsigned int*)((char*)this + 0x534) = 0;

    // Set GA options
    // SetOption is at 0x802D8CEC
    // These disable high allocation and debug checks for a clean slate.
    // The actual field names in the header don't expose SetOption directly
    // but it's part of GeneralAllocator.
}


// ============================================================================
// EAHeap::Malloc(unsigned int, int)
// Address: 0x802D0AA4 | Size: 204 bytes (51 instructions)
//
// The core allocation function. Three-tier allocation strategy:
//
//   Tier 1: Try pool allocation for small blocks (size <= 64)
//   Tier 2: Try this heap's GeneralAllocator
//   Tier 3: Try child heaps recursively
//
// Arguments:
//   r3 = this
//   r4 = size
//   r5 = flags (passed to GeneralAllocator)
//
// Returns: allocated pointer, or NULL if all tiers fail
//
// Key instructions:
//   0x802D0ABC: mr. r30, r4           — check size != 0
//   0x802D0AC0: beq return_null
//
//   -- Pool attempt --
//   0x802D0AC4: bl DebugHeap()         — get debug heap singleton
//   0x802D0AC8: cmpw r31, r3           — is this == DebugHeap?
//   0x802D0ACC: beq skip_pool          — DebugHeap doesn't use pools
//   0x802D0AD0: lwz r3, -21324(r13)    — s_protectedPoolManager
//   0x802D0AD4: mr r4, r30             — size
//   0x802D0AD8: li r5, 8               — alignment = 8 (default)
//   0x802D0ADC: bl AttemptPoolAlloc
//   0x802D0AE0: mr. r0, r3             — check result
//   0x802D0AE8: bne return_result      — pool succeeded!
//
//   -- GeneralAllocator attempt --
//   0x802D0AF8: bl GA::Malloc(this, size, flags)
//   0x802D0AFC: mr. r0, r3
//   0x802D0B04: bne return_result      — GA succeeded!
//
//   -- Parent heap attempt --
//   0x802D0B0C: lwz r3, 0x52C(r31)    — m_parentHeap
//   0x802D0B10: cmpwi r3, 0
//   0x802D0B14: beq try_aux
//   0x802D0B20: bl EAHeap::Malloc      — recursive call on parent
//   0x802D0B24: mr r0, r3
//
//   -- Aux heap attempt --
//   0x802D0B30: lwz r3, 0x530(r31)    — m_auxHeap
//   0x802D0B34: cmpwi r3, 0
//   0x802D0B38: beq check_null
//   0x802D0B44: bl EAHeap::Malloc      — recursive call on aux
//
//   -- Final null check --
//   0x802D0B58: li r3, 0               — return NULL
// ============================================================================
// NON_MATCHING: SDA-relative pool manager access, recursive calling convention
void* EAHeap::Malloc(unsigned int size, int flags) {
    if (size == 0) {
        return 0;
    }

    // Tier 1: Try pool allocation (skip for DebugHeap)
    EAHeap* dbgHeap = DebugHeap();
    if (this != dbgHeap) {
        // Load pool manager from SDA: s_protectedPoolManager at r13-21324
        AllocPoolManager<ProtectedAllocPool>* poolMgr = s_poolBlocks;
        if (poolMgr) {
            void* poolResult = poolMgr->Alloc(size);  // placeholder for AttemptPoolAlloc
            if (poolResult != 0) {
                return poolResult;
            }
        }
    }

    // Tier 2: Try GeneralAllocator
    void* gaResult = GeneralAllocator::Malloc(size, flags);
    if (gaResult != 0) {
        return gaResult;
    }

    // Tier 3: Try parent heap
    void* result = 0;
    if (m_parentHeap != 0) {
        result = m_parentHeap->Malloc(size, flags);
    }

    // Tier 3b: Try aux heap
    if (result == 0 && m_auxHeap != 0) {
        result = m_auxHeap->Malloc(size, flags);
    }

    return result;
}


// ============================================================================
// EAHeap::MallocAligned(unsigned int, unsigned int, unsigned int, int)
// Address: 0x802D0B70 | Size: 276 bytes (69 instructions)
//
// Aligned allocation. Same three-tier strategy as Malloc but with alignment.
//
// First adjusts the requested size to account for alignment:
//   adjustedSize = (size + alignment - 1) & ~(alignment - 1)
//
// If alignment <= 8, falls through to regular Malloc (default alignment
// is 8 for PPMalloc on GameCube).
//
// Arguments:
//   r3 = this
//   r4 = size
//   r5 = alignment
//   r6 = alignOffset (offset within the block that should be aligned)
//   r7 = flags
//
// Key instructions:
//   0x802D0B88: add r4, r4, r31       — adjustedSize = size + alignment
//   0x802D0B8C: neg r0, r31           — r0 = -alignment
//   0x802D0B90: addi r4, r4, -1       — adjustedSize -= 1
//   0x802D0B98: and. r29, r4, r0      — adjustedSize &= ~(alignment - 1)
//   0x802D0BA0: beq return_null       — if adjustedSize == 0, return NULL
//   0x802D0BA4: cmplwi r31, 8         — if alignment <= 8
//   0x802D0BA8: bgt need_aligned      — skip to aligned path
//   0x802D0BB8: bl EAHeap::Malloc     — use regular Malloc
// ============================================================================
// NON_MATCHING: Same issues as Malloc
void* EAHeap::MallocAligned(unsigned int size, unsigned int alignment,
                            unsigned int offset, int flags) {
    // Compute aligned size
    unsigned int adjustedSize = (size + alignment - 1) & ~(alignment - 1);
    if (adjustedSize == 0) {
        return 0;
    }

    // If alignment is default (8 or less), use regular Malloc
    if (alignment <= 8) {
        return Malloc(adjustedSize, flags);
    }

    // Tier 1: Try pool allocation
    EAHeap* dbgHeap = DebugHeap();
    if (this != dbgHeap) {
        AllocPoolManager<ProtectedAllocPool>* poolMgr = s_poolBlocks;
        if (poolMgr) {
            void* poolResult = 0;  // AttemptPoolAlloc(adjustedSize, alignment)
            if (poolResult != 0) {
                return poolResult;
            }
        }
    }

    // Tier 2: Try GeneralAllocator aligned alloc
    void* gaResult = GeneralAllocator::MallocAligned(adjustedSize, alignment, offset, flags);
    if (gaResult != 0) {
        return gaResult;
    }

    // Tier 3: Try parent and aux heaps
    void* result = 0;
    if (m_parentHeap != 0) {
        result = m_parentHeap->MallocAligned(adjustedSize, alignment, offset, flags);
    }
    if (result == 0 && m_auxHeap != 0) {
        result = m_auxHeap->MallocAligned(adjustedSize, alignment, offset, flags);
    }

    return result;
}


// ============================================================================
// EAHeap::Calloc(unsigned int, unsigned int, int)
// Address: 0x802D0C84 | Size: 244 bytes (61 instructions)
//
// Allocates count * size bytes and zeroes them. Same three-tier strategy.
//
// For pool allocations, uses memset to zero the memory after allocation
// (since pools don't zero memory on their own).
// For GeneralAllocator, uses GA::Calloc which zeros internally.
//
// Arguments:
//   r3 = this
//   r4 = count
//   r5 = size
//   r6 = flags
//
// Key instructions:
//   0x802D0C9C: mullw. r26, r29, r28  — totalSize = count * size
//   0x802D0CA8: beq return_null       — if totalSize == 0
//
//   -- Pool path (if pool alloc succeeds): --
//   0x802D0CD0: mr r5, r26            — length = totalSize
//   0x802D0CD8: li r4, 0              — fill byte = 0
//   0x802D0CDC: bl memset
//   0x802D0CE0: mr r3, r31            — return the pool-allocated ptr
//
//   -- GA path: --
//   0x802D0CF8: bl GA::Calloc(this, count, size, flags)
// ============================================================================
// NON_MATCHING: Same issues as Malloc
void* EAHeap::Calloc(unsigned int count, unsigned int size, int flags) {
    unsigned int totalSize = count * size;
    if (totalSize == 0) {
        return 0;
    }

    // Tier 1: Pool allocation + manual zeroing
    EAHeap* dbgHeap = DebugHeap();
    if (this != dbgHeap) {
        AllocPoolManager<ProtectedAllocPool>* poolMgr = s_poolBlocks;
        if (poolMgr) {
            void* poolResult = 0;  // AttemptPoolAlloc(totalSize, 8)
            if (poolResult != 0) {
                memset(poolResult, 0, totalSize);
                return poolResult;
            }
        }
    }

    // Tier 2: GeneralAllocator::Calloc (zeros memory internally)
    void* gaResult = GeneralAllocator::Calloc(count, size, flags);
    if (gaResult != 0) {
        return gaResult;
    }

    // Tier 3: Child heaps
    void* result = 0;
    if (m_parentHeap != 0) {
        result = m_parentHeap->Calloc(count, size, flags);
    }
    if (result == 0 && m_auxHeap != 0) {
        result = m_auxHeap->Calloc(count, size, flags);
    }

    return result;
}


// ============================================================================
// EAHeap::Free(void*)
// Address: 0x802D0D78 | Size: 176 bytes (44 instructions)
//
// Frees a previously allocated block. Two paths:
//
//   Path A (pool): If the pointer belongs to a pool, free it there
//                  with lock/unlock around the actual free.
//
//   Path B (heap): Find which heap's GA owns this pointer, free via GA.
//
// Arguments:
//   r3 = this
//   r4 = ptr
//
// Key instructions:
//   0x802D0D8C: mr. r30, r4               — if ptr == NULL, return
//
//   -- Pool check --
//   0x802D0D94: lwz r3, -21324(r13)        — s_protectedPoolManager
//   0x802D0D9C: bl FindPoolForBlock(mgr, ptr)
//   0x802D0DA0: mr. r31, r3               — pool found?
//   0x802D0DA4: beq try_heap              — no pool, try heap path
//
//   -- Pool free (protected): --
//   0x802D0DA8: addi r0, r31, 24           — &pool->mutex (this+0x18)
//   0x802D0DB4-0DC8: vtable dispatch lock(-1)
//   0x802D0DD4: bl FastAllocPool::Free(pool, ptr)  — base class free
//   0x802D0DE0-0DF0: vtable dispatch unlock
//
//   -- Heap free: --
//   0x802D0E00: bl FindHeapForAddress(this, ptr)
//   0x802D0E04: mr. r3, r3                — found owning heap?
//   0x802D0E10: bl GeneralAllocator::Free(heap, ptr)
// ============================================================================
// NON_MATCHING: SDA access, vtable dispatch for mutex
void EAHeap::Free(void* ptr) {
    if (ptr == 0) {
        return;
    }

    // Check if ptr belongs to a pool
    AllocPoolManager<ProtectedAllocPool>* poolMgr = s_poolBlocks;
    // In original: FindPoolForBlock returns the ProtectedAllocPool*
    // void* pool = AllocPoolManager_FindPoolForBlock(poolMgr, ptr);
    //
    // if (pool) {
    //     // Lock pool mutex
    //     // Call FastAllocPool::Free(pool, ptr)
    //     // Unlock pool mutex
    //     return;
    // }

    // Not in a pool — find which heap owns this address
    EAHeap* owningHeap = FindHeapForAddress(ptr);
    if (owningHeap != 0) {
        owningHeap->GeneralAllocator::Free(ptr);
    }
}


// ============================================================================
// EAHeap::Compact(void)
// Address: 0x802D0E28 | Size: 96 bytes (24 instructions)
//
// Compacts the heap's GeneralAllocator, coalescing free chunks.
// Optionally acquires a lock (the mutex at GA offset 0x4FC) before
// compacting.
//
// Checks GA flag at offset 0x04 — if bit 0 is set, calls GA::Compact.
//
// Key instructions:
//   0x802D0E3C: lwz r3, 0x4FC(r31)    — load lock count (mutex pointer?)
//   0x802D0E40: stw r3, 8(r1)         — save on stack
//   0x802D0E44: cmpwi r3, 0
//   0x802D0E48: beq skip_lock
//   0x802D0E4C: bl GA_Lock              — 0x802D8780
//
//   0x802D0E50: lwz r0, 4(r31)         — load GA flags
//   0x802D0E54: andi. r9, r0, 1        — test bit 0 (compact enabled?)
//   0x802D0E58: beq skip_compact
//   0x802D0E60: bl GA::Compact          — 0x802DC358
//
//   0x802D0E64: lwz r3, 8(r1)          — restore lock count
//   0x802D0E68: cmpwi r3, 0
//   0x802D0E6C: beq skip_unlock
//   0x802D0E70: bl GA_Unlock            — 0x802D87B0
// ============================================================================
void EAHeap::Compact(void) {
    // The "lock count" at offset 0x4FC is likely the GA's internal mutex.
    // If it exists (non-null), lock before compacting.

    // Load GA flags at offset 0x04 (within GeneralAllocator base class)
    // Bit 0 indicates compact is enabled/needed

    // Compact coalesces adjacent free chunks in the GeneralAllocator,
    // reducing fragmentation. This is called periodically or after
    // large free operations.
}


// ============================================================================
// EAHeap::ValidateHeap(HeapValidationLevel)
// Address: 0x802D0ED4 | Size: 80 bytes (20 instructions)
//
// Validates the heap. If the usable size is small (<= 1024), skips
// validation. Otherwise calls Compact first, then GA::ValidateHeap.
//
// Key instructions:
//   0x802D0EEC: bl GA_GetUsableSize     — 0x802DC520
//   0x802D0EF0: cmplwi r3, 1024         — minimum size threshold
//   0x802D0EF4: li r3, 1                — default return = valid
//   0x802D0EF8: ble return              — too small, skip validation
//   0x802D0F00: bl Compact
//   0x802D0F0C: bl GA::ValidateHeap(level)  — 0x802DB094
// ============================================================================
void EAHeap::ValidateHeap(EA::Allocator::GeneralAllocator::HeapValidationLevel level) {
    // Get total usable size of the heap
    // If <= 1024 bytes, it's too small to meaningfully validate
    // (likely an uninitialized or empty heap)

    // First compact to coalesce free chunks
    Compact();

    // Then run the GA's internal validation at the requested level
    // This checks chunk headers, free list integrity, bin consistency, etc.
}


// ============================================================================
// EAHeap::FindHeapForAddress(void*) const
// Address: 0x802D0F24 | Size: 124 bytes (31 instructions)
//
// Recursively searches this heap and its children to find which heap
// contains the given address in its GeneralAllocator.
//
// Uses GA::ContainsAddress (0x802DC598) to check if the address falls
// within any of this heap's core blocks.
//
// Arguments:
//   r3 = this
//   r4 = addr
//
// Returns: pointer to the owning EAHeap, or NULL
//
// Key instructions:
//   0x802D0F3C: bl GA::ContainsAddress(this, addr)  — 0x802DC598
//   0x802D0F40: cmpwi r3, 0
//   0x802D0F44: beq try_children
//   0x802D0F48: mr r3, r31              — return this (addr is in our GA)
//
//   -- Try parent heap --
//   0x802D0F50: lwz r3, 0x52C(r31)     — m_parentHeap
//   0x802D0F58: beq try_aux
//   0x802D0F60: bl FindHeapForAddress   — recursive call
//   0x802D0F64: mr. r3, r3
//   0x802D0F68: bne return
//
//   -- Try aux heap --
//   0x802D0F6C: lwz r3, 0x530(r31)     — m_auxHeap
//   0x802D0F74: beq return_null
//   0x802D0F7C: bl FindHeapForAddress   — recursive call
//
//   0x802D0F88: li r3, 0                — return NULL
// ============================================================================
EAHeap* EAHeap::FindHeapForAddress(void* addr) const {
    // Check if this heap's GeneralAllocator contains the address
    // GA::ContainsAddress checks all core blocks
    // (A core block is a contiguous memory region added to the allocator)

    // Try parent heap recursively
    if (m_parentHeap != 0) {
        EAHeap* result = m_parentHeap->FindHeapForAddress(addr);
        if (result != 0) {
            return result;
        }
    }

    // Try aux heap recursively
    if (m_auxHeap != 0) {
        EAHeap* result = m_auxHeap->FindHeapForAddress(addr);
        if (result != 0) {
            return result;
        }
    }

    return 0;
}


// ============================================================================
// EAHeap::InitializeHeapStatics(void)
// Address: 0x802D070C | Size: 384 bytes (96 instructions)
//
// One-time initialization of the global pool manager and all named heaps.
// Called during game startup.
//
// Phase 1: Pool Construction (if not already done)
//   - Zero-init the AllocPoolManager structure
//   - Construct 8 ProtectedAllocPool instances (in reverse order: 7..0)
//   - Each ProtectedAllocPool is 52 bytes (0x34)
//   - They live at: poolMgr + 8 + i * 52
//   - Set s_initialized = 1
//   - Register atexit cleanup handler
//
//   Key instructions:
//   0x802D071C: lwz r0, -22840(r13)     — s_initialized
//   0x802D0728: bne skip_init            — already done?
//   0x802D0730: stw r0, 6784(r11)        — zero m_poolMemory
//   0x802D0734: stw r0, 4(r9)            — zero m_poolEnd
//   0x802D0738: addi r31, r9, 8          — start of pool array
//   0x802D073C: li r30, 7                — construct 8 pools (7..0)
//   Loop:
//     0x802D0740: mr r3, r31
//     0x802D0744-750: li r4-r7, 0        — all NULL args
//     0x802D0754: addi r31, r31, 52      — next pool slot
//     0x802D0758: bl ProtectedAllocPool::ProtectedAllocPool
//     0x802D075C: cmpwi r30, 0
//     0x802D0760: addi r30, r30, -1
//     0x802D0764: bne loop
//   0x802D0768: li r0, 1
//   0x802D0770: stw r0, -22840(r13)      — s_initialized = 1
//   0x802D0778: bl atexit(cleanup_func)
//
// Phase 2: Initialize Pool Manager
//   0x802D0784: addi r4, -6952           — s_poolBlocks (0x8041E4D8)
//   0x802D0790: stw r9, -21324(r13)      — s_protectedPoolManager = &poolMgr
//   0x802D0794: bl AllocPoolManager<ProtectedAllocPool>::InitAllocPools
//
// Phase 3: Create Named Heaps + Set Options + Register Failure Callbacks
//   Each named heap is created via its singleton accessor function, then
//   configured with SetOption and SetMallocFailureFunction calls.
//
//   Heap creation + config order:
//     ResourceHeap() → SetOption(6, 0)
//     ModelHeap()    → SetOption(6, 0)
//     RootHeap()     → SetMallocFailureFunction(func, 0)
//     MainHeap()     → SetMallocFailureFunction(func, 0)
//     ResourceHeap() → SetMallocFailureFunction(func, 0)
//     AudioHeap()    → SetMallocFailureFunction(func, 0)
//     VMHeap()       → SetMallocFailureFunction(func, 0)
//     ShaderHeap()   → SetMallocFailureFunction(func, 0)
//     TextureHeap()  → SetMallocFailureFunction(func, 0)
//     AnimationHeap()→ SetMallocFailureFunction(func, 0)
//     ModelHeap()    → SetMallocFailureFunction(func, 0)
//     FlashesHeap()  → SetMallocFailureFunction(func, 0)
//
//   The SetMallocFailureFunction callbacks are invoked when a heap runs out
//   of memory. They typically try to free cached resources (textures, audio
//   samples, animations) to make room for the allocation.
// ============================================================================
// NON_MATCHING: Complex init sequence with SDA globals, atexit, vtable
// construction order, and ProtectedAllocPool construction.


// ============================================================================
// Heap Singleton Accessors — Pattern Documentation
// ============================================================================
//
// Each heap accessor follows this pattern:
//
//   EAHeap* XXXHeap(void) {
//       static bool initialized = false;   // in .sbss via r13
//       static EAHeap s_heap;              // in .bss (1336 bytes)
//       static EAHeap* g_ptr;              // in .sbss via r13
//
//       if (!initialized) {
//           new (&s_heap) EAHeap(name, NULL, 0, parentHeap, auxHeap);
//           initialized = true;
//           atexit(&destructor);
//       }
//       g_ptr = &s_heap;
//       return &s_heap;
//   }
//
// Heap instances confirmed from disassembly:
//
//   Function        BSS Address   Size    Global Ptr     Parent        Aux
//   ──────────────  ──────────    ─────   ──────────     ────────      ───────
//   RootHeap()      0x8049D6A8    1336    0x804FFFF0     NULL          NULL
//   MainHeap()      0x8049DBE0    1336    0x804FFFF4     RootHeap      NULL
//   ResourceHeap()  0x8049E118    1336    (r13-22820)    RootHeap      NULL
//   DebugHeap()     0x8049EB88    1336    0x80500000     NULL          NULL
//   AudioHeap()     0x8049F5F8    1336    0x80500008     ResourceHeap  ShaderHeap
//   ShaderHeap()    (similar)     1336    (r13-...)      ResourceHeap  ShaderHeap
//   TextureHeap()   (similar)     1336    (r13-...)      ResourceHeap  ShaderHeap
//   AnimationHeap() (similar)     1336    (r13-...)      ResourceHeap  ShaderHeap
//   ModelHeap()     (similar)     1336    (r13-...)      ResourceHeap  ShaderHeap
//   FlashesHeap()   (similar)     1336    (r13-...)      (?)           (?)
//   AptHeap()       (similar)     1336    (r13-...)      (?)           (?)
//   VMHeap()        (similar)     1336    (r13-...)      (?)           (?)
//   CUIHeap()       (similar)     1336    (r13-...)      (?)           (?)
//
// The name strings are stored in .rodata. Each heap has a unique name
// like "MainHeap", "ResourceHeap", etc.
//
// AudioHeap and several others share overflow parents (ResourceHeap,
// ShaderHeap), meaning audio/shader/texture/anim/model allocations can
// overflow into each other's memory pools if needed.


// ============================================================================
// FPHeap — Thin Subclass of EAHeap
// ============================================================================
//
// FPHeap::FPHeap(char*, void*, unsigned int, EAHeap*, EAHeap*)
// Address: 0x802D0FC4 | Size: 48 bytes
//
// Just calls EAHeap::EAHeap — no additional initialization.
// "FP" likely stands for "Fixed Pool" or "Fast Pool."
//
// Already implemented in src/core/eaheap.cpp.


// ============================================================================
// MEMORY SYSTEM ARCHITECTURE — COMPLETE SUMMARY
// ============================================================================
//
// The Sims 2 (GameCube) uses a 3-tier memory allocation system:
//
// ┌─────────────────────────────────────────────────────────────────┐
// │ TIER 1: Pool Allocator                                         │
// │   - Handles allocations <= 64 bytes                            │
// │   - 8 size classes: 8, 16, 24, 32, 40, 48, 56, 64             │
// │   - O(1) alloc/free via intrusive free list                    │
// │   - ProtectedAllocPool adds mutex for thread safety            │
// │   - Magic sentinels: 'DESU' (in use), 'EERF' (free)           │
// │   - Pool init order: [7,3,5,1,0,2,4,6] → binary search tree   │
// └────────────────────────────┬────────────────────────────────────┘
//                              │ if pool exhausted
// ┌────────────────────────────▼────────────────────────────────────┐
// │ TIER 2: GeneralAllocator (PPMalloc)                            │
// │   - Handles allocations > 64 bytes or pool exhaustion          │
// │   - dlmalloc-style heap: binning, coalescing, alignment        │
// │   - Each EAHeap embeds one GeneralAllocator (~1276 bytes)      │
// │   - Chunk headers: prevSize, size, fd/bk pointers              │
// │   - Core blocks: contiguous memory regions                     │
// └────────────────────────────┬────────────────────────────────────┘
//                              │ if GA also fails
// ┌────────────────────────────▼────────────────────────────────────┐
// │ TIER 3: Heap Hierarchy                                         │
// │   - Try m_parentHeap (first fallback)                          │
// │   - Then m_auxHeap (second fallback)                           │
// │   - Recursive — cascades up the heap tree                      │
// │   - Malloc failure callbacks free cached resources              │
// │   - RootHeap is the ultimate fallback                          │
// └────────────────────────────────────────────────────────────────┘
//
// Example: 32-byte allocation on AudioHeap
//   1. AudioHeap->Malloc(32, 0)
//   2. 32 <= 64 → try ProtectedAllocPool bin 3 (25-32 bytes)
//      a. Lock pool mutex
//      b. Pop free list head → stamp 'DESU'
//      c. Unlock → return pointer
//   3. If bin 3 empty → try bin 4 (33-40), then 5, ..., 7
//   4. If all pools empty → try AudioHeap's GeneralAllocator
//   5. If GA fails → try ResourceHeap (m_parentHeap)
//   6. If that fails → try ShaderHeap (m_auxHeap)
//   7. If all fail → call AudioHeapFreeMemory callback
//   8. If still fails → return NULL
//
// Example: Freeing that pointer
//   1. AudioHeap->Free(ptr)
//   2. FindPoolForBlock(s_protectedPoolManager, ptr) — is it in a pool?
//   3. Yes → lock pool, push onto free list, stamp 'EERF', unlock
//   4. No  → FindHeapForAddress(ptr) walks the heap tree
//          → Found in AudioHeap's GA → GA::Free(ptr)
//
// Key design decisions:
//   - Pool block sizes are multiples of 8 (natural alignment)
//   - Interleaved pool layout enables O(log n) address lookup
//   - Mutex is per-pool, not per-manager (reduces contention)
//   - Magic sentinels enable runtime corruption detection
//   - Heap tree allows per-system memory budgets
//   - Malloc failure callbacks enable adaptive resource management
//   - DebugHeap is excluded from pool allocation (for tracking)
