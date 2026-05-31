// 0x802D72C8 ProtectedAllocPool::Free(void*) (80 B)
// FLAGS:
//
// Thread-safe free: a scoped lock guard takes the pool's mutex, the lockless
// FastAllocPool base reclaims the block, and the guard releases the mutex at
// scope exit. Lock/Unlock dispatch through the EMutex (ESyncObject vtable) at
// +0x18; see include/types/ProtectedAllocPool.h.

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
    void Free(void* p);
};

void ProtectedAllocPool::Free(void* p)
{
    EMutexGuard guard(&m_mutex);
    FastAllocPool::Free(p);
}
