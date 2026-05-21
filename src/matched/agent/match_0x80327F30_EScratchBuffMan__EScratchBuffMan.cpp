// 0x80327F30 EScratchBuffMan::EScratchBuffMan(void) (40B)
// GCC emits: mr, li, lis, stw(0), ori, stores... DOL wants: lis, mr, li, ori, stores...
// 3 swap_adj directives reorder the setup block:
//   1. swap li+lis to get: mr, lis, li, ...
//   2. swap mr+lis to get: lis, mr, li, ...
//   3. swap stw+ori to complete sentinel before first store
// ASMPROC_swap_adj: a=li b=lis which=first
// ASMPROC_swap_adj: a=mr b=lis which=first
// ASMPROC_swap_adj: a=stw b=ori which=first

struct EScratchBuffMan {
    EScratchBuffMan();
};

EScratchBuffMan::EScratchBuffMan() {
    volatile int* p = (volatile int*)this;
    int sentinel = (int)0xDEADBEEF;
    p[1] = 0;
    p[4] = sentinel;
    p[3] = 0;
    p[2] = 0;
    p[0] = 0;
}
