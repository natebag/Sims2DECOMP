// 0x802DC520 EA::Allocator::GeneralAllocator::GetTotalCoreSize(void) const (52 B)
// Sum mnSize over the circular CoreBlock list. The list head sentinel is an
// embedded CoreBlock at +0x44C (1100). The DOL reads head.mpNext directly off
// this (this+1132) and forms &head separately (this+1100), so keep the member
// access and the address-of as distinct expressions. mnSize @ +0x04, mpNext @ +0x20.
struct CoreBlock {
    char         pad0[4];
    unsigned int mnSize;     // 0x04
    char         pad8[0x18];
    CoreBlock*   mpNext;      // 0x20
};

struct GeneralAllocator {
    char      pad[1100];
    CoreBlock mHeadCoreBlock;   // 0x44C
    unsigned int GetTotalCoreSize() const;
};

unsigned int GeneralAllocator::GetTotalCoreSize() const
{
    unsigned int total = 0;
    for (const CoreBlock* p = mHeadCoreBlock.mpNext; p != &mHeadCoreBlock; p = p->mpNext)
        total += p->mnSize;
    return total;
}
