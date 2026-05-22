// 0x80266F18 AIGetDMAEnableFlag (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lhz 0,0x5036(3); rlwinm 3,0,17,31,31"
extern "C" int f_80266F18() {}
