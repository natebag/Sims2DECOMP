// 0x802D7250 ProtectedAllocPool::Alloc(void) (80 B)
// FLAGS:
//
// Thread-safe alloc: a scoped lock guard takes the pool's mutex, the lockless
// FastAllocPool base hands out a block, and the guard releases the mutex at
// scope exit (after the result is latched). Lock/Unlock dispatch through the
// EMutex (ESyncObject vtable) at +0x18; see include/types/ProtectedAllocPool.h.

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
    void* Alloc();
};

struct ProtectedAllocPool : FastAllocPool {
    EMutex m_mutex;   /* @ +0x18 */
    void* Alloc();
};

void* ProtectedAllocPool::Alloc()
{
    EMutexGuard guard(&m_mutex);
    return FastAllocPool::Alloc();
}
