// 0x802DBF34 EA::Allocator::GeneralAllocator::Calloc(unsigned int, unsigned int, int) (116 B)
// Public Calloc: same conditional scoped-lock guard, delegating (count, size,
// flags) to CallocInternal and carrying the result past the unlock.
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
    void* Calloc(unsigned int count, unsigned int size, int flags);
    void* CallocInternal(unsigned int count, unsigned int size, int flags);
};

void* GeneralAllocator::Calloc(unsigned int count, unsigned int size, int flags)
{
    PPMutexAutoLock lock(m_mutex);
    return CallocInternal(count, size, flags);
}

}}
