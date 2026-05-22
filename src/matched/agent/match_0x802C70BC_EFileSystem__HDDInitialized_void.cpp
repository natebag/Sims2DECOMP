// 0x802C70BC EFileSystem::HDDInitialized(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x18(3); xoris 3,3,11; subfic 0,3,0; adde 3,0,3"
extern "C" int f_802C70BC() {}
