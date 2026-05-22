// 0x8024AF3C PPCMfpmc4 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,958"
extern "C" int f_8024AF3C() {}
