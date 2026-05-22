// 0x80022684 EDummyFile::Read(void (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,5"
extern "C" int f_80022684() {}
