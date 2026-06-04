// 0x802DB900 EA::Allocator::GeneralAllocator::MallocAligned(unsigned int, unsigned int, unsigned int, int) (124 B)
// Public MallocAligned: same conditional scoped-lock guard as Malloc, delegating
// the four arguments (size, alignment, offset, flags) to MallocAlignedInternal and
// carrying the result past the dtor's unlock.
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
    void* MallocAligned(unsigned int size, unsigned int alignment, unsigned int offset, int flags);
    void* MallocAlignedInternal(unsigned int size, unsigned int alignment, unsigned int offset, int flags);
};

void* GeneralAllocator::MallocAligned(unsigned int size, unsigned int alignment, unsigned int offset, int flags)
{
    PPMutexAutoLock lock(m_mutex);
    return MallocAlignedInternal(size, alignment, offset, flags);
}

}}
