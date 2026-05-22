// 0x802E38CC EEngine::GetCurrentLevel(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x30(3)"
extern "C" int f_802E38CC() {}
