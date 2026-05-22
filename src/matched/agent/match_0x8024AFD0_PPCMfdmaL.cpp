// 0x8024AFD0 PPCMfdmaL (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,923"
extern "C" int f_8024AFD0() {}
