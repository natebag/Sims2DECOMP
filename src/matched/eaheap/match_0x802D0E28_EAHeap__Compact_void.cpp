// 0x802D0E28 EAHeap::Compact(void) (96 B)
// FLAGS:
//
// Compact the heap under the (optional) PPM mutex. A scoped guard takes the
// mutex if one is configured (the pointer at +0x4FC lives in the guard's stack
// slot — that IS the DOL spill), then if the "fast bins active" flag (bit 0 of
// the flags word at +0x04) is set the fast bins are flushed, and the guard
// releases the mutex at scope exit. See feedback_scoped_lock_guard_pattern.

extern "C" void PPMMutexLock(void* mutex);
extern "C" void PPMMutexUnlock(void* mutex);

struct PPMMutexGuard {
    void* m_mutex;
    PPMMutexGuard(void* m) : m_mutex(m) { if (m_mutex) PPMMutexLock(m_mutex); }
    ~PPMMutexGuard()                    { if (m_mutex) PPMMutexUnlock(m_mutex); }
};

struct EAHeap {
    char     _pad0[0x04];
    unsigned m_flags;       // 0x04
    char     _pad1[0x4F4];  // 0x08 .. 0x4FB
    void*    m_mutex;       // 0x4FC
    void Compact();
    void ClearFastBins();
};

void EAHeap::Compact()
{
    PPMMutexGuard guard(m_mutex);
    if (m_flags & 1)
        ClearFastBins();
}
