// 0x802D0D78 EAHeap::Free(void*) (176 B)
// FLAGS:
//
// Free a block back to the right allocator. If it belongs to one of the fast
// fixed-block pools, return it there under the pool's mutex (via a scoped lock
// guard); otherwise locate the owning general heap region and free it through
// the general allocator.
//
// Lock/Unlock dispatch through the EMutex (ESyncObject vtable) at pool+0x18
// (slots 2/3); FastAllocPool::Free is the inherited base, called directly.
// See include/types/ProtectedAllocPool.h for the lock-subobject layout.

namespace EA { namespace Allocator {
struct GeneralAllocator {
    char _opaqueBase[0x528];
    void Free(void* p);
};
}}

struct ESyncObject {
    virtual ~ESyncObject();
    virtual void Lock(int timeout);
    virtual void Unlock();
};

struct ESemaphore { unsigned char _opaque[0x0C]; };

struct EMutex : ESyncObject {
    ESemaphore m_semaphore;
};

struct EMutexGuard {
    ESyncObject* m_lock;
    EMutexGuard(ESyncObject* lock) : m_lock(lock) { m_lock->Lock(-1); }
    ~EMutexGuard() { m_lock->Unlock(); }
};

struct FastAllocPool {
    void* m_poolStart;
    void* m_freeList;
    int   m_poolBlocks;
    int   m_blockSize;
    int   m_alignment;
    void* m_vtablePtr;
    void  Free(void* p);
};

struct ProtectedAllocPool : FastAllocPool {
    EMutex m_mutex;   /* @ +0x18 */
};

struct AllocPoolManager {
    ProtectedAllocPool* FindPoolForBlock(void* p);
};

extern AllocPoolManager* g_protectedPoolManager;

struct EAHeap : EA::Allocator::GeneralAllocator {
    void                          Free(void* p);
    EA::Allocator::GeneralAllocator* FindHeapForAddress(void* p);
};

void EAHeap::Free(void* p)
{
    if (p == 0)
        return;

    ProtectedAllocPool* pool = g_protectedPoolManager->FindPoolForBlock(p);
    if (pool != 0) {
        EMutexGuard guard(&pool->m_mutex);
        pool->FastAllocPool::Free(p);
    } else {
        EA::Allocator::GeneralAllocator* heap = FindHeapForAddress(p);
        if (heap != 0)
            heap->Free(p);
    }
}
