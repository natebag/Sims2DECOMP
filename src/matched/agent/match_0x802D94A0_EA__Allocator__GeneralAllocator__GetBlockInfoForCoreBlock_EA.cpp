// 0x802D94A0 EA::Allocator::GeneralAllocator::GetBlockInfoForCoreBlock(CoreBlock*, BlockInfo*) const (36 B)
// Fill a BlockInfo (r5) describing a CoreBlock (r4): copy the first two words,
// stamp the block-type byte (8) at +0x10, and clear +0x14.
struct CoreBlock {
    void*        mpCore;     // 0x00
    unsigned int mnSize;     // 0x04
};

struct BlockInfo {
    void*         mpData;    // 0x00
    unsigned int  mnSize;    // 0x04
    char          pad8[8];
    unsigned char mBlockType;// 0x10
    char          padB[3];
    unsigned int  mField14;  // 0x14
};

// r3 = this (unused), r4 = pCoreBlock, r5 = pBlockInfo
extern "C" void f_802D94A0(void* /*self*/, CoreBlock* pCoreBlock, BlockInfo* pBlockInfo)
{
    pBlockInfo->mBlockType = 8;
    pBlockInfo->mpData     = pCoreBlock->mpCore;
    pBlockInfo->mnSize     = pCoreBlock->mnSize;
    pBlockInfo->mField14   = 0;
}
