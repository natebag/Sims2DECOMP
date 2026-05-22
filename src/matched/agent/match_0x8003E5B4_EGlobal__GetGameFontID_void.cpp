// 0x8003E5B4 EGlobal::GetGameFontID(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,26614; ori 3,3,25851"
extern "C" int f_8003E5B4() {}
