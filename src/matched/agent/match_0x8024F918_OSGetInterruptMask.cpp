// 0x8024F918 OSGetInterruptMask (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32768; lwz 3,0xc8(3)"
extern "C" int f_8024F918() {}
