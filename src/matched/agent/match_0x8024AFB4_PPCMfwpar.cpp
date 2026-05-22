// 0x8024AFB4 PPCMfwpar (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sync; mfspr 3,921"
extern "C" int f_8024AFB4() {}
