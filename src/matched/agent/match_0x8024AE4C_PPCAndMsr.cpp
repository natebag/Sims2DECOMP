// 0x8024AE4C PPCAndMsr (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfmsr 4; and 3,4,3"
extern "C" int f_8024AE4C() {}
