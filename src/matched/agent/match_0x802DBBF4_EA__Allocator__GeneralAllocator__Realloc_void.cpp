// 0x802DBBF4 EA::Allocator::GeneralAllocator::Realloc(void*, unsigned int, int) (116 B)
// Public Realloc: same conditional scoped-lock guard as Malloc, delegating
// (p, size, flags) to ReallocInternal and carrying the result past the unlock.
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
    void* Realloc(void* p, unsigned int size, int flags);
    void* ReallocInternal(void* p, unsigned int size, int flags);
};

void* GeneralAllocator::Realloc(void* p, unsigned int size, int flags)
{
    PPMutexAutoLock lock(m_mutex);
    return ReallocInternal(p, size, flags);
}

}}
