// 0x802C68C8 EFile::operator (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,4"
extern "C" int f_802C68C8() {}
