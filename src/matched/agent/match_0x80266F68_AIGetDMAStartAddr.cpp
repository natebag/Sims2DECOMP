// 0x80266F68 AIGetDMAStartAddr (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,20480; lhz 4,0x30(3); lhz 0,0x32(3); rlwinm 3,0,0,16,26; rlwimi 3,4,16,6,15"
extern "C" int f_80266F68() {}
