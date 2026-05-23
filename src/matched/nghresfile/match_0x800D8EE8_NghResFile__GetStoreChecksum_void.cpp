// 0x800D8EE8 NghResFile::GetStoreChecksum(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x18c(3)"
extern "C" int f_800D8EE8() {}
