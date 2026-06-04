// 0x802DC0B8 EA::Allocator::GeneralAllocator::MallocMultiple(unsigned int, unsigned int, void**, int) (128 B)
// Equal-size overload: allocate `count` blocks all of size `nSize`. Under the
// heap mutex, delegate to MallocMultipleInternal with a one-element size array
// (the address of the spilled nSize parameter) and a size-element count of 1.
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
    unsigned int MallocMultiple(unsigned int count, unsigned int nSize, void** pResultArray, int flags);
    unsigned int MallocMultipleInternal(unsigned int count, unsigned int sizeCount,
                                        const unsigned int* pSizeArray, void** pResultArray, int flags);
};

unsigned int GeneralAllocator::MallocMultiple(unsigned int count, unsigned int nSize, void** pResultArray, int flags)
{
    PPMutexAutoLock lock(m_mutex);
    return MallocMultipleInternal(count, 1, &nSize, pResultArray, flags);
}

}}
