// 0x802D718C ProtectedAllocPool::ProtectedAllocPool(char*, void*, int, int) (68 B)
// FLAGS:
//
// ProtectedAllocPool constructor: forwards its args to the FastAllocPool base
// ctor, installs the ProtectedAllocPool vtable (SN-style, at the +0x14 slot at
// the end of the FastAllocPool head), then default-constructs the guarding
// EMutex member at +0x18. See include/types/ProtectedAllocPool.h.

struct ESemaphore {
    unsigned char _opaque[0x0C];
    ESemaphore();
    void Create(int initial, int max);
};

struct ESyncObject {
    ESyncObject();
    virtual ~ESyncObject();
    virtual void Lock(int timeout);
    virtual void Unlock();
};

struct EMutex : ESyncObject {
    ESemaphore m_semaphore;   /* @ +0x04 */
    EMutex();
};

struct FastAllocPool {
    void* m_poolStart;    /* 0x00 */
    void* m_freeList;     /* 0x04 */
    int   m_poolBlocks;   /* 0x08 */
    int   m_blockSize;    /* 0x0C */
    int   m_alignment;    /* 0x10 */
    /* vtable ptr @ 0x14 (SN-style, after data) */
    FastAllocPool(char* name, void* mem, int blockSize, int count);
    virtual ~FastAllocPool();
    virtual void Validate();
    virtual void* Alloc();
    virtual void Free(void* p);
};

struct ProtectedAllocPool : FastAllocPool {
    EMutex m_mutex;   /* @ +0x18 */
    ProtectedAllocPool(char* name, void* mem, int blockSize, int count);
};

ProtectedAllocPool::ProtectedAllocPool(char* name, void* mem, int blockSize, int count)
    : FastAllocPool(name, mem, blockSize, count)
{
}
