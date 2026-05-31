// 0x802D77A0 ESemaphore::ESemaphore(int, int) (96 B)
// FLAGS:
//
// Two-arg ESemaphore ctor: chains the ESyncObject base ctor, zero-inits the
// max-count and handle fields, installs the ESemaphore vtable, then delegates
// to Create(maxCount, initialCount) to bring up the OS semaphore. The base ctor
// + vtable are modeled the same way as the sibling default ctor (0x802D7758).

extern void EObj_ctor(void* self);   // ESyncObject::ESyncObject
extern char vt_ESemaphore[];

class ESemaphore {
public:
    void* m_vt;          // 0x00
    void* m_handle;      // 0x04
    int   m_maxCount;    // 0x08
    int   m_field_C;     // 0x0C  (OS semaphore object follows)
    ESemaphore(int maxCount, int initialCount);
    int Create(int maxCount, int initialCount);
};

ESemaphore::ESemaphore(int maxCount, int initialCount)
{
    EObj_ctor(this);
    m_handle = 0;
    m_vt = vt_ESemaphore;
    m_maxCount = 0;
    Create(maxCount, initialCount);
}
