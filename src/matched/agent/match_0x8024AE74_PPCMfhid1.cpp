// 0x8024AE74 PPCMfhid1 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,1009"
extern "C" int f_8024AE74() {}
