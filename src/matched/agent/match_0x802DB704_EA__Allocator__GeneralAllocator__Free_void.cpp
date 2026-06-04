// 0x802DB704 EA::Allocator::GeneralAllocator::Free(void*) (92 B)
// Public Free: take the heap's mutex (if one is configured), delegate to
// FreeInternal, then release the mutex. The lock is held by a scoped guard whose
// member (the spilled mutex pointer @ stack+8) is re-read in the dtor to decide
// whether to unlock. PPMMutexLock/Unlock are plain (non-virtual) calls.
namespace EA { namespace Allocator {

extern "C" void PPMMutexLock(void* mutex);
extern "C" void PPMMutexUnlock(void* mutex);

struct PPMutexAutoLock {
    void* m_mutex;
    PPMutexAutoLock(void* mutex) : m_mutex(mutex) { if (m_mutex) PPMMutexLock(m_mutex); }
    ~PPMutexAutoLock() { if (m_mutex) PPMMutexUnlock(m_mutex); }
};

struct GeneralAllocator {
    char  pad[0x4FC];
    void* m_mutex;        // 0x4FC = 1276
    void Free(void* p);
    void FreeInternal(void* p);
};

void GeneralAllocator::Free(void* p)
{
    PPMutexAutoLock lock(m_mutex);
    FreeInternal(p);
}

}}
