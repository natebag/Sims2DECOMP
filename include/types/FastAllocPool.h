/* include/types/FastAllocPool.h — canonical layout for FastAllocPool family
 *
 * S18 TypeArchaeologist deliverable. Opportunistic legacy promotion of
 * include/core/fastallocpool.h. Sibling to EAHeap (allocator family).
 *
 * Source TU: base_ngc_release_dvd.lib(fastallocpool.obj)
 *
 * v2 (S18 post-KimiWorker-incident): added byte-match conversion guidance
 * block (no signature changes — preemptive hardening per MainGuy ask
 * following the EString + BString2 fake-struct incidents).
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
 *
 * ============================================================================
 * **BYTE-MATCH CONVERSION GUIDANCE (READ BEFORE WRITING ANY CONVERT)**
 *
 * Same anti-pattern rules as EString.h v2 / BString2.h apply here. The
 * allocator-family classes are particularly fake-struct-invitation-prone
 * because of the `void*` return on Alloc + `void*` parameter on Free.
 *
 * 1. **#include "types/FastAllocPool.h"** — use canonical FastAllocPool +
 *    ProtectedAllocPool. Do NOT redeclare locally with a different name
 *    (e.g. fake `FAP_Alloc` shim) — different mangled symbols can collide
 *    with the real class in other TUs, causing collateral byte-match
 *    damage in unrelated units (per the EString MakeUpper incident
 *    mechanism — commit 7b81fa6a9 broke a 152B person-unit function).
 *
 * 2. **vtable @ +0x14 (SN-style), NOT +0x00.** Both classes use the
 *    SN ProDG vtable-at-end-of-head convention. If your conversion
 *    needs to dispatch through the vtable, the slot offset is calculated
 *    from `*(m_vtablePtr + 8 * N)` where N is the slot index, not from
 *    `*((void**)this + N)`.
 *
 * 3. **Use struct-member access, NOT raw pointer arithmetic.**
 *    `m_freeList` good; `*(void**)((char*)this + 4)` bad. Same
 *    register-allocation-drift principle as the BString2 incident:
 *    raw-cast access reuses r3; struct-member access uses r9 intermediate.
 *    Compiler emits different bytes for byte-identical-looking source.
 *
 * 4. **Init's 4-param signature is canonical.** `Init(void* pool,
 *    s32 blockSize, s32 numBlocks, s32 alignment)` — don't collapse
 *    params or change the order/types for "convenience". The DOL was
 *    compiled against this exact signature.
 *
 * 5. **Alloc returns void* (canonical) — don't "upgrade" to typed return.**
 *    If you need a specific type at the call site, cast there
 *    (`(MyStruct*)pool.Alloc()`), don't change the canonical signature.
 *
 * If you suspect a canonical signature gap, POST a typereq don't fake-struct.
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
