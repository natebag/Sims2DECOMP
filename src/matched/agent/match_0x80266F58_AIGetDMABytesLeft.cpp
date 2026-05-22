// 0x80266F58 AIGetDMABytesLeft (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lhz 0,0x503a(3); rlwinm 3,0,5,12,26"
extern "C" int f_80266F58() {}
