// 0x80255444 __OSSetTick (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 284,3"
extern "C" int f_80255444() {}
