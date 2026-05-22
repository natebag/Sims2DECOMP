// 0x8024CACC DCBlockStore (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="dcbst 0,3"
extern "C" int f_8024CACC() {}
