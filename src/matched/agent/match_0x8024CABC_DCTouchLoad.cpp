// 0x8024CABC DCTouchLoad (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="dcbt 0,3"
extern "C" int f_8024CABC() {}
