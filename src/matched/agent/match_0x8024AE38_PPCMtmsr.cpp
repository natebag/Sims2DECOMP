// 0x8024AE38 PPCMtmsr (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtmsr 3"
extern "C" int f_8024AE38() {}
