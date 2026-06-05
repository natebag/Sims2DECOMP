// 0x802D8C14 EA::Allocator::GeneralAllocator::Shutdown(void) (216 B)
// Tear the allocator down under its mutex: clear fast bins (if enabled), free
// every remaining core block (unlink + return to the OS), reset the top chunk
// to the head sentinel and zero the running counters, then destroy the mutex.
// Returns true.
namespace EA { namespace Allocator {

struct Chunk {
    unsigned int mPrevSize;   // 0x00
    unsigned int mnSize;      // 0x04
    Chunk*       mpNext;      // 0x08
    Chunk*       mpPrev;      // 0x0C
};

struct CoreBlock {
    Chunk*       mpFirstChunk; // 0x00
    unsigned int mnSize;       // 0x04
    char         mPad[0x18];   // 0x08
    CoreBlock*   mpNext;       // 0x20
    CoreBlock*   mpPrev;       // 0x24
};

struct GeneralAllocator {
    int          mField0;                 // 0x00  teardown gate
    unsigned int mFlags;                  // 0x04  option flags (bit0 -> fast bins)
    char         mPad08[0x34 - 0x08];     // 0x08
    Chunk        mHeadChunk;              // 0x34
    char         mPad44[0x444 - 0x44];    // 0x44
    Chunk*       mpTopChunk;              // 0x444
    char         mPad448[0x44C - 0x448];  // 0x448
    CoreBlock    mHeadCoreBlock;          // 0x44C  (mpNext 0x46C, mpPrev 0x470)
    unsigned int mField474;               // 0x474
    unsigned int mField478;               // 0x478
    char         mPad47C[0x4FC - 0x47C];  // 0x47C
    void*        mpMutex;                 // 0x4FC

    bool Shutdown();
    void ClearFastBins();
    void UnlinkCoreBlock(CoreBlock* pCoreBlock);
    void FreeCore(CoreBlock* pCoreBlock);
};

extern "C" void PPMMutexLock(void* pMutex);
extern "C" void PPMMutexUnlock(void* pMutex);
extern "C" void PPMMutexDestroy(void* pMutex);

bool GeneralAllocator::Shutdown()
{
    if (mpMutex)
        PPMMutexLock(mpMutex);

    if (mField0)
    {
        mField0 = 0;
        if (mFlags & 1)
            ClearFastBins();

        if (mHeadCoreBlock.mpPrev != &mHeadCoreBlock)
        {
            do {
                CoreBlock* pCoreBlock = mHeadCoreBlock.mpPrev;
                UnlinkCoreBlock(pCoreBlock);
                FreeCore(pCoreBlock);
            } while (mHeadCoreBlock.mpPrev != &mHeadCoreBlock);
        }

        mpTopChunk = &mHeadChunk;
        *(volatile unsigned int*)&mField478 = 0;
        *(volatile unsigned int*)&mField474 = 0;
    }

    if (mpMutex)
    {
        void* pMutex = mpMutex;
        mpMutex = 0;
        PPMMutexUnlock(pMutex);
        PPMMutexDestroy(pMutex);
    }

    return true;
}

}}
