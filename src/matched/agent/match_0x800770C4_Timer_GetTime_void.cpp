// 0x800770C4 Timer_GetTime(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,-24912(13)"
extern "C" int f_800770C4() {}
