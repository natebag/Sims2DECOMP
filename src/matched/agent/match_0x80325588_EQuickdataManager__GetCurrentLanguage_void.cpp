// 0x80325588 EQuickdataManager::GetCurrentLanguage(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xd20(3)"
extern "C" int f_80325588() {}
