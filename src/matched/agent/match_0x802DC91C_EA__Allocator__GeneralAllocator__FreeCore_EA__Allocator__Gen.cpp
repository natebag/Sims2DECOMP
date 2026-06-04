// 0x802DC91C EA::Allocator::GeneralAllocator::FreeCore(EA::Allocator::GeneralAllocator::CoreBlock*) (80 B)
// A CoreBlock can carry its own "free" callback (the memory backing the block
// came from an external source). If the block is freeable (flag @ +0x10 set)
// and a callback was supplied (@ +0x18), invoke it as
//   fn(this, core, core->mnSize, core->mnUserData)
// via the stored function pointer (mtlr/blrl) and report success; else return 0.
// Result lives in r9 (0, then 1 after the call) and merges into r3 at the tail.
struct CoreBlock {
    char         pad0[4];
    unsigned int mnSize;        // 0x04
    char         pad8[8];
    unsigned int mnFlag;        // 0x10
    char         pad14[4];
    void*        mpFreeFn;      // 0x18
    unsigned int mnUserData;    // 0x1C
};

struct GeneralAllocator;
typedef void (*CoreFreeFn)(GeneralAllocator*, CoreBlock*, unsigned int, unsigned int);

struct GeneralAllocator {
    int FreeCore(CoreBlock* core);
};

int GeneralAllocator::FreeCore(CoreBlock* core)
{
    int result = 0;
    if (core->mnFlag != 0) {
        CoreFreeFn fn = (CoreFreeFn)core->mpFreeFn;
        if (fn != 0) {
            fn(this, core, core->mnSize, core->mnUserData);
            result = 1;
        }
    }
    return result;
}
