// 0x8024AF2C PPCMfpmc3 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,957"
extern "C" int f_8024AF2C() {}
