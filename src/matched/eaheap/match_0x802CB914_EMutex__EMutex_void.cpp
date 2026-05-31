// 0x802CB914 EMutex::EMutex(void) (88 B)
// FLAGS:
//
// EMutex constructor: chains the ESyncObject base ctor, installs the EMutex
// vtable, default-constructs the backing ESemaphore member, then creates it as
// a binary semaphore (initial count 1, max -1 = unbounded). Lock/Unlock
// dispatch through the ESyncObject vtable; see include/types/ProtectedAllocPool.h.

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

EMutex::EMutex()
{
    m_semaphore.Create(1, -1);
}
