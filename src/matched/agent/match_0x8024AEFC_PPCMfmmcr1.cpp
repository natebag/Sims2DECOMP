// 0x8024AEFC PPCMfmmcr1 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,956"
extern "C" int f_8024AEFC() {}
