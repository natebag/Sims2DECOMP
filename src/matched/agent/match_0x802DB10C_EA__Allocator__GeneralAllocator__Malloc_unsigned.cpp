// 0x802DB10C EA::Allocator::GeneralAllocator::Malloc(unsigned int, int) (108 B)
// Public Malloc: hold the heap's mutex (if configured) across MallocInternal and
// return its result. Same conditional scoped-lock guard as Free; the allocation
// result is carried in a callee-saved register past the dtor's unlock call.
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
    void* Malloc(unsigned int size, int flags);
    void* MallocInternal(unsigned int size, int flags);
};

void* GeneralAllocator::Malloc(unsigned int size, int flags)
{
    PPMutexAutoLock lock(m_mutex);
    return MallocInternal(size, flags);
}

}}
