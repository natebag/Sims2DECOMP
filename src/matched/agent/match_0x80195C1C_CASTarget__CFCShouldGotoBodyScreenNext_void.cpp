// 0x80195C1C CASTarget::CFCShouldGotoBodyScreenNext(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x104(3); cmpwi 0,0; bne 0f; lwz 0,0xa4(3); li 3,1; cmpwi 0,19; beqlr; 0:; li 3,0"
// NOTE: GCC uses branchless xori/subfic/adde for equality-int; DOL uses li+cmpwi+beqlr; unmatchable
extern "C" int f_80195C1C() {}
