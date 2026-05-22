// 0x8024CAD4 DCBlockFlush (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="dcbf 0,3"
extern "C" int f_8024CAD4() {}
