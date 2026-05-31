// 0x802D7874 ESemaphore::Create(int, int) (84 B)
// FLAGS:
//
// Initialize the embedded OS semaphore. The first param is the max count
// (cached at +0x08, returned by GetMaxCount); the second is the initial count,
// where -1 means "start full" (= max). m_handle (+0x04) is set to point at the
// embedded OSSemaphore, which is what IsCreated() tests. Always returns 1.

struct OSThreadQueue { void* head; void* tail; };
struct OSSemaphore  { int count; OSThreadQueue queue; };
extern "C" void OSInitSemaphore(OSSemaphore* sem, int count);

struct ESemaphore {
    void*        m_vt;        // 0x00
    OSSemaphore* m_handle;    // 0x04  -> &m_sem once created
    int          m_maxCount;  // 0x08
    OSSemaphore  m_sem;       // 0x0C
    int Create(int maxCount, int initialCount);
};

int ESemaphore::Create(int maxCount, int initialCount)
{
    if (initialCount == -1)
        initialCount = maxCount;
    OSInitSemaphore(&m_sem, initialCount);
    m_handle = &m_sem;
    m_maxCount = maxCount;
    return 1;
}
