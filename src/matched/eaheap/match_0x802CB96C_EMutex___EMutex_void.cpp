// 0x802CB96C EMutex::~EMutex(void) (80 B)
// FLAGS:
//
// EMutex destructor: reinstalls the EMutex vtable, destroys the backing
// ESemaphore member (complete-object dtor), then chains the ESyncObject base
// destructor, propagating the in-charge flag. See ProtectedAllocPool.h.

struct ESemaphore {
    unsigned char _opaque[0x0C];
    ~ESemaphore();
};

struct ESyncObject {
    virtual ~ESyncObject();
    virtual void Lock(int timeout);
    virtual void Unlock();
};

struct EMutex : ESyncObject {
    ESemaphore m_semaphore;   /* @ +0x04 */
    virtual ~EMutex();
};

EMutex::~EMutex()
{
}
