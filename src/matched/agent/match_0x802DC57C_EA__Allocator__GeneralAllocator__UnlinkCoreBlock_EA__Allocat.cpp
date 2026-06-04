// 0x802DC57C EA::Allocator::GeneralAllocator::UnlinkCoreBlock(EA::Allocator::GeneralAllocator::CoreBlock*) (28 B)
// Doubly-linked CoreBlock list removal. mpPrev @ +0x20, mpNext @ +0x24.
// Each statement re-reads block->mpPrev / block->mpNext: GCC can't CSE the
// loads across the intervening store (the store may alias the pointer fields),
// so the second statement reloads both pointers.
struct CoreBlock {
    char pad[0x20];
    CoreBlock* mpPrev;   // 0x20
    CoreBlock* mpNext;   // 0x24
};

// r3 = this (GeneralAllocator*, unused), r4 = pCoreBlock
extern "C" void f_802DC57C(void* /*self*/, CoreBlock* pCoreBlock)
{
    pCoreBlock->mpPrev->mpNext = pCoreBlock->mpNext;
    pCoreBlock->mpNext->mpPrev = pCoreBlock->mpPrev;
}
