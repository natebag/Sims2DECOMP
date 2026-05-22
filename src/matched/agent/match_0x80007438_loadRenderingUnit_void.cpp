// 0x80007438 loadRenderingUnit(void (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0xc(3); rlwinm 4,4,3,0,28; add 9,9,4; lwz 3,0x4(9)"
extern "C" int f_80007438() {}
