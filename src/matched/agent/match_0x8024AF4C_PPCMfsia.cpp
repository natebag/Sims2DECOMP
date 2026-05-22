// 0x8024AF4C PPCMfsia (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,955"
extern "C" int f_8024AF4C() {}
