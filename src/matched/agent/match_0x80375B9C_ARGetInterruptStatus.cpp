// 0x80375B9C __ARGetInterruptStatus (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lhz 0,0x500a(3); rlwinm 3,0,0,26,26"
extern "C" int f_80375B9C() {}
