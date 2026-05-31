// 0x802D792C ESemaphore::Release(void) (96 B)
// FLAGS:
//
// Release (V operation), interrupt-safe. Disables interrupts (saving the prior
// enable state, normalized to bool), signals the OS semaphore if its count is
// still below the max, then restores the interrupt state. Always returns 1.
// The OSSemaphore is at +0x0C (count its first word); the max is cached at +0x08.

struct OSThreadQueue { void* head; void* tail; };
struct OSSemaphore  { int count; OSThreadQueue queue; };
extern "C" int  OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(int level);
extern "C" int  OSSignalSemaphore(OSSemaphore* sem);

struct ESemaphore {
    void*       m_vt;        // 0x00
    void*       m_handle;    // 0x04
    int         m_maxCount;  // 0x08
    OSSemaphore m_sem;       // 0x0C  (count @ 0x0C)
    int Release();
};

int ESemaphore::Release()
{
    bool enabled = OSDisableInterrupts();
    if (m_sem.count < m_maxCount)
        OSSignalSemaphore(&m_sem);
    OSRestoreInterrupts(enabled);
    return 1;
}
