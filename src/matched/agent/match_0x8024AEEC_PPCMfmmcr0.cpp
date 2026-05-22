// 0x8024AEEC PPCMfmmcr0 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,952"
extern "C" int f_8024AEEC() {}
