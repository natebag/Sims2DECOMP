// 0x8024BC48 __OSGetDIConfig (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,24576; lwz 0,0x24(3); rlwinm 3,0,0,24,31"
extern "C" int f_8024BC48() {}
