// 0x800770D4 Timer_GetTicks(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-24900(13)"
extern "C" int f_800770D4() {}
