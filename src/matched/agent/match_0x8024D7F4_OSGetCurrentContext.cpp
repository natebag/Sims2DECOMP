// 0x8024D7F4 OSGetCurrentContext (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32768; lwz 3,0xd4(3)"
extern "C" int f_8024D7F4() {}
