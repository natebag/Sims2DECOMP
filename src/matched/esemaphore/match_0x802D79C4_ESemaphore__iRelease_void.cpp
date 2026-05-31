// 0x802D79C4 ESemaphore::iRelease(void) (52 B)
// FLAGS: -fno-schedule-insns
//
// Inner release: if the backing OS semaphore's count is still below the max,
// signal it (V operation). The OSSemaphore lives at +0x0C (its first word is
// the live count); the max count is cached at +0x08.

struct OSThreadQueue { void* head; void* tail; };
struct OSSemaphore  { int count; OSThreadQueue queue; };
extern "C" int OSSignalSemaphore(OSSemaphore* sem);

struct ESemaphore {
    void*       m_vt;        // 0x00
    int         m_handle;    // 0x04
    int         m_maxCount;  // 0x08
    OSSemaphore m_sem;       // 0x0C  (count @ 0x0C)
    void iRelease();
};

void ESemaphore::iRelease()
{
    if (m_sem.count < m_maxCount)
        OSSignalSemaphore(&m_sem);
}
