// 0x8024AFA4 PPCMfhid2 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,920"
extern "C" int f_8024AFA4() {}
