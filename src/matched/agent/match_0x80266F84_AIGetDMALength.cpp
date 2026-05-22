// 0x80266F84 AIGetDMALength (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lhz 0,0x5036(3); rlwinm 3,0,5,12,26"
extern "C" int f_80266F84() {}
