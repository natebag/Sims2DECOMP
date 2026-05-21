// 0x802DC560 EA::Allocator::GeneralAllocator::LinkCoreBlock(CoreBlock*, CoreBlock*) (28B)
//
// Doubly-linked-list insertion: links newBlock after newHead and updates
// both newHead.next and the prior-next's prev pointer. Standard 4-store
// doubly-linked-list head insertion.
//
// Wall was a CLASSIFICATION error in the parked wip: function was declared
// `static` but DOL emits with `this` in r3 (taking r4=newBlock, r5=newHead).
// Fix: declare it as an instance method (non-static), so the implicit r3=this
// shifts the explicit args to r4/r5. Byte-perfect first compile after the fix.

namespace EA { namespace Allocator {

struct GeneralAllocator {
    struct CoreBlock {
        char pad[32];
        CoreBlock* next;
        CoreBlock* prev;
    };
    void LinkCoreBlock(CoreBlock* newBlock, CoreBlock* newHead);
};

void GeneralAllocator::LinkCoreBlock(CoreBlock* newBlock, CoreBlock* newHead) {
    newBlock->prev = newHead;
    newBlock->next = newHead->next;
    newHead->next = newBlock;
    newBlock->next->prev = newBlock;
}

}}
