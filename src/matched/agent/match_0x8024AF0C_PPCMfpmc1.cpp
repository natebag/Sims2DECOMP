// 0x8024AF0C PPCMfpmc1 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,953"
extern "C" int f_8024AF0C() {}
