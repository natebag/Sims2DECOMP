// 0x802D8080 ENgcSNFile::Tell(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x30(3)"
extern "C" int f_802D8080() {}
