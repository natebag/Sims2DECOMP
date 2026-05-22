// 0x8024AE30 PPCMfmsr(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfmsr 3"
extern "C" unsigned int PPCMfmsr() {}
