// 0x802DC598 EA::Allocator::GeneralAllocator::FindCoreBlockForAddress(void*) const (64 B)
// Walk the circular CoreBlock list (sentinel head embedded at +0x44C) and return
// the block whose [block, block+mnSize) span contains addr, else 0.
// mnSize @ +0x04, mpNext @ +0x20.
struct CoreBlock {
    char         pad0[4];
    unsigned int mnSize;     // 0x04
    char         pad8[0x18];
    CoreBlock*   mpNext;      // 0x20
};

struct GeneralAllocator {
    char      pad[1100];
    CoreBlock mHeadCoreBlock;   // 0x44C
    CoreBlock* FindCoreBlockForAddress(const void* addr) const;
};

CoreBlock* GeneralAllocator::FindCoreBlockForAddress(const void* addr) const
{
    CoreBlock* block = mHeadCoreBlock.mpNext;
    while (block != &mHeadCoreBlock) {
        if ((const char*)addr >= (const char*)block &&
            (const char*)addr < (const char*)block + block->mnSize)
            return block;
        block = block->mpNext;
    }
    return 0;
}
