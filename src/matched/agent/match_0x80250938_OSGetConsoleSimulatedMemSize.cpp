// 0x80250938 OSGetConsoleSimulatedMemSize (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32768; lwz 3,0xf0(3)"
extern "C" int f_80250938() {}
