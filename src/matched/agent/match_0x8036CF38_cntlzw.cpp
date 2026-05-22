// 0x8036CF38 __cntlzw (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cntlzw 3,3"
extern "C" int f_8036CF38() {}
