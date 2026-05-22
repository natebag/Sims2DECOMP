// 0x800063F8 GetGameFontID(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,26614; ori 3,3,25851"
extern "C" int f_800063F8() {}
