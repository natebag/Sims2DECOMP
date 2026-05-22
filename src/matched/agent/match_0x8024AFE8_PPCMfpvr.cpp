// 0x8024AFE8 PPCMfpvr (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,287"
extern "C" int f_8024AFE8() {}
