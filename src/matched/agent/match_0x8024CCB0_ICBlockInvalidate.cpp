// 0x8024CCB0 ICBlockInvalidate (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="icbi 0,3"
extern "C" int f_8024CCB0() {}
