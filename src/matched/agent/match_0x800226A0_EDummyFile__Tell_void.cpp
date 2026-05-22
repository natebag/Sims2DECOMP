// 0x800226A0 EDummyFile::Tell(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x2c(3)"
extern "C" int f_800226A0() {}
