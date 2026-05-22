// 0x8024AE64 PPCMfhid0 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,1008"
extern "C" int f_8024AE64() {}
