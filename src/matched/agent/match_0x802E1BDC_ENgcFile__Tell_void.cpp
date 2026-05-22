// 0x802E1BDC ENgcFile::Tell(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x68(3)"
extern "C" int f_802E1BDC() {}
