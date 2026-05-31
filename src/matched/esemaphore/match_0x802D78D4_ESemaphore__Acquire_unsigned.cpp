// 0x802D78D4 ESemaphore::Acquire(unsigned int) (88 B)
// FLAGS:
//
// Acquire (P operation). A timeout of -1 means block indefinitely
// (OSWaitSemaphore) and always reports success. Otherwise try without blocking
// (OSTryWaitSemaphore): the try returns the pre-decrement count, so if it still
// equals the live count nothing was taken (fail -> 0); a changed count means we
// acquired (success -> 1). The OSSemaphore lives at +0x0C (count is its first word).

struct OSThreadQueue { void* head; void* tail; };
struct OSSemaphore  { int count; OSThreadQueue queue; };
extern "C" int OSWaitSemaphore(OSSemaphore* sem);
extern "C" int OSTryWaitSemaphore(OSSemaphore* sem);

struct ESemaphore {
    void*       m_vt;        // 0x00
    void*       m_handle;    // 0x04
    int         m_maxCount;  // 0x08
    OSSemaphore m_sem;       // 0x0C  (count @ 0x0C)
    int Acquire(unsigned int timeout);
};

int ESemaphore::Acquire(unsigned int timeout)
{
    if (timeout == (unsigned int)-1) {
        OSWaitSemaphore(&m_sem);
        return 1;
    }
    if (OSTryWaitSemaphore(&m_sem) == m_sem.count)
        return 0;
    return 1;
}
