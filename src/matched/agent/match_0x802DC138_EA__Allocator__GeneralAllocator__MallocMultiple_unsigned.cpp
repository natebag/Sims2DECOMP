// 0x802DC138 EA::Allocator::GeneralAllocator::MallocMultiple(unsigned int, const unsigned int*, void**, int) (128 B)
// Per-element-size overload: allocate `count` blocks whose sizes come from
// pSizeArray. Under the heap mutex, delegate to MallocMultipleInternal passing
// `count` as both the block count and the size-element count (so r5 = r4).
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
    unsigned int MallocMultiple(unsigned int count, const unsigned int* pSizeArray, void** pResultArray, int flags);
    unsigned int MallocMultipleInternal(unsigned int count, unsigned int sizeCount,
                                        const unsigned int* pSizeArray, void** pResultArray, int flags);
};

unsigned int GeneralAllocator::MallocMultiple(unsigned int count, const unsigned int* pSizeArray, void** pResultArray, int flags)
{
    PPMutexAutoLock lock(m_mutex);
    return MallocMultipleInternal(count, count, pSizeArray, pResultArray, flags);
}

}}
