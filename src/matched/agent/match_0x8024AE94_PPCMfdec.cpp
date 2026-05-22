// 0x8024AE94 PPCMfdec (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,22"
extern "C" int f_8024AE94() {}
