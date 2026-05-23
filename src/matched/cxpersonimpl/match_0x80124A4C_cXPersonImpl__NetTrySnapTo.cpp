// 0x80124A4C cXPersonImpl::NetTrySnapTo (144B)
// Three sequential BBI dispatches. Returns {0, 1} = (result_code=0, success=1).
// First call (slot 0x330/0x334 on m_implPtr->holder->vt) takes (&stash, 1) —
// likely seeds a network-or-snap state. Second (slot 0x188/0x18C on m_subPtr->vt)
// retrieves an object. Third (slot 0x40/0x44 on result->vt-at-+0) finalizes.
// elem argument is unused; stashed int arg is the snap context.
//
// First-chain registers: GCC allocates impl→r11, holder→r10 but DOL uses
// impl→r10, holder→r11 (same lifetime, equivalent volatile regs). Swap via
// replace_insn to match exactly.
// ASMPROC_replace_insn: match="lwz 11,0(30)" replacement="lwz 10,0(30)"
// ASMPROC_replace_insn: match="lwz 10,4(11)" replacement="lwz 11,4(10)"
// ASMPROC_replace_insn: match="lwz 9,4(10)" replacement="lwz 9,4(11)"
// ASMPROC_replace_insn: match="add 3,10,3" replacement="add 3,11,3" occurrence=0

typedef void (*FnA)(void*, int*, int);
typedef void* (*FnB)(void*);
typedef void (*FnC)(void*);

struct cXPerson_NTS {
    char* m_implPtr;   // 0x0
    char* m_subPtr;    // 0x4
    long long NetTrySnapTo(void* elem, int stashedArg);
};

long long cXPerson_NTS::NetTrySnapTo(void* elem, int stashedArg) {
    (void)elem;
    int stash = stashedArg;

    char* holder = *(char**)(m_implPtr + 4);
    char* vt1 = *(char**)(holder + 4);
    short adj1 = *(short*)(vt1 + 0x330);
    FnA fn1 = (FnA)*(void**)(vt1 + 0x334);
    fn1(holder + adj1, &stash, 1);

    char* sub = m_subPtr;
    char* vt2 = *(char**)(sub + 4);
    short adj2 = *(short*)(vt2 + 0x188);
    FnB fn2 = (FnB)*(void**)(vt2 + 0x18C);
    char* res = (char*)fn2(sub + adj2);

    char* vt3 = *(char**)(res + 0);
    short adj3 = *(short*)(vt3 + 0x40);
    FnC fn3 = (FnC)*(void**)(vt3 + 0x44);
    fn3(res + adj3);

    return (long long)1;  // r3=0 (hi), r4=1 (lo) — matches DOL li 3,0; li 4,1
}
