// 0x8024CAC4 DCBlockZero (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="dcbz 0,3"
extern "C" int f_8024CAC4() {}
