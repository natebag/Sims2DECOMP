// 0x8025092C OSGetPhysicalMemSize (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32768; lwz 3,0x28(3)"
extern "C" int f_8025092C() {}
