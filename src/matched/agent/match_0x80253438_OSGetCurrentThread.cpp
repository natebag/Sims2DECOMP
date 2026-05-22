// 0x80253438 OSGetCurrentThread (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32768; lwz 3,0xe4(3)"
extern "C" int f_80253438() {}
