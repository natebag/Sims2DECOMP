// 0x8002268C EDummyFile::Write(void (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,5"
extern "C" int f_8002268C() {}
