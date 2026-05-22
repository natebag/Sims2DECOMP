// 0x8024AF1C PPCMfpmc2 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,954"
extern "C" int f_8024AF1C() {}
