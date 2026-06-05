// 0x802DAF78 EA::Allocator::GeneralAllocator::ValidateAddress(void*, bool) (284 B)
// Validate that an address falls inside an allocated chunk, under the allocator
// mutex (RAII guard). Find the owning core block, walk its chunk list to the
// chunk that contains the address, confirm that chunk is in use, then either
// require an exact match against the chunk's data pointer (bExact) or accept any
// address within the chunk's data span.
namespace EA { namespace Allocator {

struct Chunk {
    unsigned int mPrevSize;  // 0x00
    unsigned int mnSize;     // 0x04  size | flag bits
};

struct CoreBlock {
    Chunk* mpFirstChunk;     // 0x00
};

struct GeneralAllocator {
    char  mPad0[0x4FC];
    void* mpMutex;           // 0x4FC

    int        ValidateAddress(void* pAddress, bool bExact);
    CoreBlock* FindCoreBlockForAddress(void* pAddress) const;
};

extern "C" void PPMMutexLock(void* pMutex);
extern "C" void PPMMutexUnlock(void* pMutex);

struct PPMutexAutoLock {
    void* mpMutex;
    PPMutexAutoLock(void* pMutex) : mpMutex(pMutex) { if (mpMutex) PPMMutexLock(mpMutex); }
    ~PPMutexAutoLock() { if (mpMutex) PPMMutexUnlock(mpMutex); }
};

int GeneralAllocator::ValidateAddress(void* pAddress, bool bExact)
{
    PPMutexAutoLock lock(mpMutex);

    CoreBlock* pCoreBlock = FindCoreBlockForAddress(pAddress);
    if (pCoreBlock) {
        Chunk* pChunk = pCoreBlock->mpFirstChunk;
        Chunk* pNext  = (Chunk*)((char*)pChunk + (pChunk->mnSize & ~7u));

        while ((char*)pNext < (char*)pAddress && pNext != pChunk) {
            pChunk = pNext;
            pNext  = (Chunk*)((char*)pNext + (pNext->mnSize & ~7u));
        }

        Chunk* pAfter = (Chunk*)((char*)pChunk + (pChunk->mnSize & ~7u));
        if (pAfter->mnSize & 1) {
            void* pData = (char*)pChunk + 8;
            if (bExact) {
                return (pAddress == pData) ? 1 : 0;
            } else {
                int result = 0;
                if ((char*)pAddress >= (char*)pData)
                    result = ((char*)pAddress < (char*)pNext) ? 1 : 0;
                return result;
            }
        }
    }

    return 0;
}

}}
