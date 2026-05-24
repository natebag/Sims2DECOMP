/* include/types/FastAllocPool.h — canonical layout for FastAllocPool family
 *
 * S18 TypeArchaeologist deliverable. Opportunistic legacy promotion of
 * include/core/fastallocpool.h. Sibling to EAHeap (allocator family).
 *
 * Source TU: base_ngc_release_dvd.lib(fastallocpool.obj)
 *
 * ============================================================================
 * SN ProDG vtable convention: vtable pointer at +0x14, AFTER data fields
 * (mirrors Interactor +0x5C, cXObjectImpl +0xEC, ESimsCam +0x56C — see
 * include/types/EAHeap.h sibling header for the parallel allocator class).
 *
 * Same head layout shared by both classes (FastAllocPool and
 * ProtectedAllocPool); the distinction is the dtor behavior +
 * synchronization (ProtectedAllocPool wraps Alloc/Free with thread-safe
 * synchronization; FastAllocPool is the lockless variant).
 * ============================================================================
 */
#ifndef SIMS2_TYPES_FASTALLOCPOOL_H
#define SIMS2_TYPES_FASTALLOCPOOL_H

#include "../types.h"

/* ============================================================================
 * ProtectedAllocPool — thread-safe fixed-block pool allocator
 *
 * 0x18 byte head (per legacy).
 * ========================================================================== */
class ProtectedAllocPool {
public:
    /* 0x00 */ void* m_poolStart;
    /* 0x04 */ void* m_freeList;
    /* 0x08 */ s32   m_poolBlocks;
    /* 0x0C */ s32   m_blockSize;
    /* 0x10 */ s32   m_alignment;
    /* 0x14 */ void* m_vtablePtr;     /* SN-style vtable at end of head */

    void  Validate(void);
    void* Alloc(void);
    void  Free(void* ptr);
    s32   BlockIsInPool(void* ptr) const;
    s32   GetAlignment(void) const;
    void* GetPoolStart(void) const;
    u32   GetPoolSize(void) const;
    s32   GetBlockSize(void) const;
    s32   GetPoolBlocks(void) const;
};

/* ============================================================================
 * FastAllocPool — lockless fixed-block pool allocator
 *
 * Same 0x18 head layout as ProtectedAllocPool. dtor + Alloc/Free differ
 * (no synchronization in the lockless variant).
 * ========================================================================== */
class FastAllocPool {
public:
    /* 0x00 */ void* m_poolStart;
    /* 0x04 */ void* m_freeList;
    /* 0x08 */ s32   m_poolBlocks;
    /* 0x0C */ s32   m_blockSize;
    /* 0x10 */ s32   m_alignment;
    /* 0x14 */ void* m_vtablePtr;

    FastAllocPool(void);
    ~FastAllocPool(void);

    void  Init(void* pool, s32 blockSize, s32 numBlocks, s32 alignment);
    void  Validate(void);
    void* Alloc(void);
    void  Free(void* ptr);
    s32   BlockIsInPool(void* ptr) const;
    s32   GetAlignment(void) const;
    void* GetPoolStart(void) const;
    u32   GetPoolSize(void) const;
    s32   GetBlockSize(void) const;
    s32   GetPoolBlocks(void) const;
};

#endif /* SIMS2_TYPES_FASTALLOCPOOL_H */
