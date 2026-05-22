// 0x80022694 EDummyFile::Seek(int, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x2c(3); mr 3,4"
extern "C" void f_80022694() {}
