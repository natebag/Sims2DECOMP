// 0x802C70D0 EFileSystem::HDDStatus(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x18(3)"
extern "C" int f_802C70D0() {}
