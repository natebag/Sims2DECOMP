// fastallocpool.cpp - FastAllocPool implementation
// From: base_ngc_release_dvd.lib(fastallocpool.obj)
// Small functions (<=64 bytes) decompiled from this object

#include "core/fastallocpool.h"
#include "core/eaheap.h"

// Magic values used for pool block tagging
#define FAST_ALLOC_MAGIC_USED  0x44455355  // "DESU" - marks allocated block
#define FAST_ALLOC_MAGIC_FREE  0x45455246  // "EERF" - marks freed block

// ============================================================================
// FastAllocPool::~FastAllocPool - 0x802d6ff0 (52 bytes)
// Destructor: sets vtable pointer at offset 0x14, conditionally frees
// Original: lis r9,vtable_hi; addi r9,r9,vtable_lo; stw r9,0x14(r3)
//           andi. r0,r4,1; beq skip; bl __builtin_delete
// ============================================================================
// NON_MATCHING - vtable pointer store + conditional delete via SN calling convention
FastAllocPool::~FastAllocPool(void) {
    // m_vtablePtr would be set to FastAllocPool vtable by SN compiler
    // Conditional operator delete based on destructor mode flag in r4
    // Cannot match with GCC - SN destructor calling convention differs
}

// ============================================================================
// FastAllocPool::GetAlignment - 0x802d7220 (8 bytes)
// Returns m_alignment at offset 0x10
// ============================================================================
int FastAllocPool::GetAlignment(void) const {
    return m_alignment;
}

// ============================================================================
// FastAllocPool::GetPoolStart - 0x802d7228 (8 bytes)
// Returns m_poolStart at offset 0x00
// ============================================================================
void* FastAllocPool::GetPoolStart(void) const {
    return m_poolStart;
}

// ============================================================================
// FastAllocPool::GetPoolSize - 0x802d7230 (16 bytes)
// Returns m_poolBlocks * m_blockSize
// lwz r0,8(r3); lwz r3,12(r3); mullw r3,r3,r0
// ============================================================================
unsigned int FastAllocPool::GetPoolSize(void) const {
    return (unsigned int)m_poolBlocks * (unsigned int)m_blockSize;
}

// ============================================================================
// FastAllocPool::GetBlockSize - 0x802d7240 (8 bytes)
// Returns m_blockSize at offset 0x0C
// ============================================================================
int FastAllocPool::GetBlockSize(void) const {
    return m_blockSize;
}

// ============================================================================
// FastAllocPool::GetPoolBlocks - 0x802d7248 (8 bytes)
// Returns m_poolBlocks at offset 0x08
// ============================================================================
int FastAllocPool::GetPoolBlocks(void) const {
    return m_poolBlocks;
}

// ============================================================================
// FastAllocPool::Alloc - 0x802d7374 (40 bytes)
// Pops a block from the free list, tags it as used
// r11 = this; r3 = freeList; if null return null
// loads next free from block+4, stores magic "DESU" at block+0
// ============================================================================
void* FastAllocPool::Alloc(void) {
    void* block = m_freeList;
    if (block == 0) {
        return 0;
    }
    // Next free pointer is stored at offset 4 of the free block
    m_freeList = *(void**)((char*)block + 4);
    // Tag block with "in use" magic
    *(unsigned int*)block = FAST_ALLOC_MAGIC_USED;
    return block;
}

// ============================================================================
// FastAllocPool::Free - 0x802d739c (36 bytes)
// Pushes a block back onto the free list, tags it as free
// if ptr is null, return immediately
// ============================================================================
void FastAllocPool::Free(void* ptr) {
    if (ptr == 0) {
        return;
    }
    // Tag block as free
    *(unsigned int*)ptr = FAST_ALLOC_MAGIC_FREE;
    // Push onto free list
    *(void**)((char*)ptr + 4) = m_freeList;
    m_freeList = ptr;
}

// ============================================================================
// FastAllocPool::BlockIsInPool - 0x802d7340 (52 bytes)
// Checks if ptr is within [m_poolStart, m_poolStart + m_poolBlocks * m_blockSize)
// Returns 1 if in pool, 0 if not
// ============================================================================
int FastAllocPool::BlockIsInPool(void* ptr) const {
    int result = 0;
    if ((unsigned int)ptr < (unsigned int)m_poolStart) {
        return 0;
    }
    unsigned int poolEnd = (unsigned int)m_poolStart + (unsigned int)m_poolBlocks * (unsigned int)m_blockSize;
    if ((unsigned int)ptr < poolEnd) {
        result = 1;
    }
    return result;
}
