// 0x80327EB4 EResourceMap::GetMaxEntries(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3)"
extern "C" int f_80327EB4() {}
