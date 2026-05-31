/* include/types/ProtectedAllocPool.h — ProtectedAllocPool MI layout + the
 * EMutex / ESyncObject lock-sync subobject it dispatches through.
 *
 * S19 TypeArchaeologist deliverable — services typereq:ProtectedAllocPool from
 * SN-4. Reopens the EAHeap deep tier: EAHeap::Free/Malloc/Calloc route to
 * ProtectedAllocPool::Alloc/Free, which take a lock via 2 MI-adjustor vcalls
 * through the EMutex at pool+0x18.
 *
 * Provenance: tools/disasm_digest.sh + raw disasm of ProtectedAllocPool ctor
 * (0x802D718C), ProtectedAllocPool::Alloc (0x802D7250), Free (0x802D72C8), and
 * EMutex::EMutex (0x802CB914). Shape-only header — no ASMPROC/asm/injection.
 *
 * ============================================================================
 * Class graph (all offsets cited below)
 * ============================================================================
 *   ProtectedAllocPool : public FastAllocPool      // single inheritance
 *       FastAllocPool base   @ 0x00 (0x18-byte head, SN-vtable @ +0x14)
 *       EMutex      m_mutex  @ 0x18                 // the lock subobject
 *
 *   EMutex : public ESyncObject
 *       ESyncObject base     @ 0x00 (vtable @ +0x00, holds Lock/Unlock)
 *       ESemaphore  m_sem    @ 0x04                 // ESemaphore::Create(1,-1)
 *
 * Alloc/Free wrap the real work in a lock:
 *   void* ProtectedAllocPool::Alloc() {
 *       m_mutex.Lock();                  // vcall, ESyncObject vtable slot 2
 *       void* p = FastAllocPool::Alloc();// direct bl 0x802D7374
 *       m_mutex.Unlock();                // vcall, ESyncObject vtable slot 3
 *       return p;
 *   }
 * (Free is the same shape around FastAllocPool::Free, bl 0x802D739C.)
 * ============================================================================
 */
#ifndef SIMS2_TYPES_PROTECTEDALLOCPOOL_H
#define SIMS2_TYPES_PROTECTEDALLOCPOOL_H

#include "../types.h"
#include "FastAllocPool.h"   /* FastAllocPool base (0x18-byte head, vtable@0x14) */

/* ============================================================================
 * ESemaphore — the underlying OS sync primitive. Opaque here (not needed to
 * model the lock dispatch). Constructed via ESemaphore::ESemaphore()
 * (0x802D7758) + ESemaphore::Create(int initial=1, int max=-1) (0x802D7874).
 * File typereq:ESemaphore with a consuming function's asm if its fields are
 * needed.
 * ========================================================================== */
struct ESemaphore {
    /* 0x00 */ u8 _opaque[0x0C]; /* size unverified; placeholder. EMutex places
                                    its next-after-semaphore content relative to
                                    this — treat as opaque, do not slice. */
};

/* ============================================================================
 * ESyncObject — abstract lock base. Polymorphic; its vtable carries the
 * Lock/Unlock virtuals that ProtectedAllocPool::Alloc/Free dispatch.
 *
 * VTABLE SLOT EVIDENCE (ProtectedAllocPool::Alloc 0x802D7250, SN {s16 adjustor
 * @entry+0, fnptr @entry+4}, 8-byte entries):
 *   Lock   : lha r3,0x10(vt); lwz r9,0x14(vt)  -> entry 2  (vt+0x10 / vt+0x14)
 *   Unlock : lha r3,0x18(vt); lwz r0,0x1c(vt)  -> entry 3  (vt+0x18 / vt+0x1c)
 * So Lock is the 3rd virtual and Unlock the 4th. Entries 0 and 1 (vt+0x00,
 * vt+0x08) precede them — almost certainly the GCC2/SN virtual-destructor pair
 * (deleting + non-deleting). Modeled that way below.
 *
 * !! MATCHER CHECK: if your compiled Lock/Unlock vcalls land at vt offsets
 *    other than 0x10/0x18, adjust the count of leading virtuals here (the
 *    slot-0/1 identity is the one inferred, not directly-evidenced, part).
 *    Everything else (the +0x18 mutex offset, the {adjustor,fnptr} entry
 *    format, Lock=slot2/Unlock=slot3) is from the asm.
 * ========================================================================== */
struct ESyncObject {
    /* 0x00 */ void* m_vtable;           /* SN-style vtable at +0x00 here       */
    virtual ~ESyncObject();             /* slots 0,1 (GCC2 dtor pair) — inferred */
    virtual void Lock();                /* slot 2  (vtable+0x10) — EVIDENCED    */
    virtual void Unlock();              /* slot 3  (vtable+0x18) — EVIDENCED    */
};

/* ============================================================================
 * EMutex : ESyncObject — concrete mutex backed by an ESemaphore.
 * Ctor 0x802CB914: ESyncObject::ESyncObject(this); install EMutex vtable @0x00;
 * ESemaphore::ESemaphore(this+0x04); ESemaphore::Create(this+0x04, 1, -1).
 * ========================================================================== */
struct EMutex : ESyncObject {
    /* 0x04 */ ESemaphore m_semaphore;   /* the backing sync primitive          */
    /* EMutex overrides Lock/Unlock (acquire/release m_semaphore). Total size
       = sizeof(ESyncObject head) + sizeof(ESemaphore); tail opaque. */
};

/* ============================================================================
 * ProtectedAllocPool : FastAllocPool — a FastAllocPool guarded by an EMutex.
 * Ctor 0x802D718C: FastAllocPool::FastAllocPool(this,...); install
 * ProtectedAllocPool vtable @ this+0x14 (overrides the inherited
 * FastAllocPool::m_vtablePtr slot); EMutex::EMutex(this+0x18).
 *
 * So the FastAllocPool 0x18-byte head (m_poolStart@0x00 .. m_vtablePtr@0x14) is
 * fully inherited, the vtable@0x14 is ProtectedAllocPool's own, and the EMutex
 * begins immediately after at +0x18.
 * ========================================================================== */
struct ProtectedAllocPool : FastAllocPool {
    /* 0x18 */ EMutex m_mutex;           /* lock taken around Alloc/Free        */
};

/* ============================================================================
 * Matched method addresses (DVD-map; files in src/matched/agent/, dirtyxml/)
 * ========================================================================== */
extern "C" void f_802D718C(void); /* ProtectedAllocPool::ProtectedAllocPool(char*,...) */
extern "C" void f_802D71D0(void); /* ProtectedAllocPool::~ProtectedAllocPool()  */
extern "C" void f_802D7250(void); /* ProtectedAllocPool::Alloc()                */
extern "C" void f_802D72C8(void); /* ProtectedAllocPool::Free(void*)            */
extern "C" void f_802CB914(void); /* EMutex::EMutex()                           */
extern "C" void f_802CB96C(void); /* EMutex::~EMutex()                          */
extern "C" void f_802D5850(void); /* ESyncObject::ESyncObject()                 */
extern "C" void f_802D7758(void); /* ESemaphore::ESemaphore()                   */
extern "C" void f_802D7874(void); /* ESemaphore::Create(int, int)               */
/* AllocPoolManager<ProtectedAllocPool> (the owning pool table): */
extern "C" void f_803C1E84(void); /* InitAllocPools(unsigned)                   */
extern "C" void f_803C2140(void); /* AttemptPoolAlloc(unsigned)                 */
extern "C" void f_803C2214(void); /* FindPoolForBlock(void*)                    */

#endif /* SIMS2_TYPES_PROTECTEDALLOCPOOL_H */
