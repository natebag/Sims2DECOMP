// 0x802552E8 OSGetTick (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0x7C6C42E6"
extern "C" int f_802552E8() {}
