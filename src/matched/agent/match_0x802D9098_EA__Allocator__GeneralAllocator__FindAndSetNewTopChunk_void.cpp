// 0x802D9098 EA::Allocator::GeneralAllocator::FindAndSetNewTopChunk(void) (212 B)
// Scan every core block's chunk list for the best free chunk to promote to the
// new top chunk: a free chunk larger than 8192 bytes, or one whose tail sits on
// a core block's top fencepost, is taken immediately; otherwise the largest free
// chunk seen wins. The chosen chunk is unlinked from its free bin and recorded
// as mpTopChunk; the chosen chunk is also returned. If nothing qualifies, the
// head-chunk sentinel is used.
namespace EA { namespace Allocator {

struct Chunk {
    unsigned int mPrevSize;   // 0x00
    unsigned int mnSize;      // 0x04  size | flag bits (bit0 = prev-in-use)
    Chunk*       mpNext;      // 0x08  free-list forward
    Chunk*       mpPrev;      // 0x0C  free-list back
};

struct CoreBlock {
    Chunk*       mpFirstChunk; // 0x00
    unsigned int mnSize;       // 0x04
    char         mPad[0x18];   // 0x08
    CoreBlock*   mpNext;       // 0x20
};

struct GeneralAllocator {
    char       mPad0[0x34];
    Chunk      mHeadChunk;       // 0x34
    char       mPad1[0x400];     // 0x44
    Chunk*     mpTopChunk;       // 0x444
    char       mPad2[0x04];      // 0x448
    CoreBlock  mHeadCoreBlock;   // 0x44C (mpNext at 0x46C)

    Chunk* FindAndSetNewTopChunk();
};

Chunk* GeneralAllocator::FindAndSetNewTopChunk()
{
    Chunk*       pHighestChunk = &mHeadChunk;
    unsigned int nHighestSize  = 0;

    for (CoreBlock* pCoreBlock = mHeadCoreBlock.mpNext;
         pCoreBlock != &mHeadCoreBlock;
         pCoreBlock = pCoreBlock->mpNext)
    {
        Chunk* pChunk = pCoreBlock->mpFirstChunk;
        Chunk* pLimit = (Chunk*)((char*)pCoreBlock + pCoreBlock->mnSize - 16);

        while (pChunk < pLimit)
        {
            unsigned int sz = pChunk->mnSize & ~7u;
            Chunk* pNext = (Chunk*)((char*)pChunk + sz);

            if ((pNext->mnSize & 1) == 0)
            {
                if (sz > 8192 || pNext == pLimit)
                {
                    pHighestChunk = pChunk;
                    goto done;
                }
                if (sz > nHighestSize)
                {
                    pHighestChunk = pChunk;
                    nHighestSize  = sz;
                }
            }

            pChunk = pNext;
        }
    }

done:
    if (pHighestChunk != &mHeadChunk)
    {
        pHighestChunk->mpNext->mpPrev = pHighestChunk->mpPrev;
        pHighestChunk->mpPrev->mpNext = pHighestChunk->mpNext;
        pHighestChunk->mpPrev = pHighestChunk;
        pHighestChunk->mpNext = pHighestChunk;
    }

    mpTopChunk = pHighestChunk;
    return pHighestChunk;
}

}}
