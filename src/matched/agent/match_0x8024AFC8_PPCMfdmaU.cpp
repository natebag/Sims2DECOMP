// 0x8024AFC8 PPCMfdmaU (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,922"
extern "C" int f_8024AFC8() {}
