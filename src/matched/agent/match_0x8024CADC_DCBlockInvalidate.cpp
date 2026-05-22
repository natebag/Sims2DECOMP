// 0x8024CADC DCBlockInvalidate (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="dcbi 0,3"
extern "C" int f_8024CADC() {}
