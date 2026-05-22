// 0x802C70F4 EFileSystem::HDDSaveInitialized(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x20(3); xoris 3,3,11; subfic 0,3,0; adde 3,0,3"
extern "C" int f_802C70F4() {}
