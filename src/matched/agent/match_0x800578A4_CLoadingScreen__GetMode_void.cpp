// 0x800578A4 CLoadingScreen::GetMode(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x354(3)"
extern "C" int f_800578A4() {}
