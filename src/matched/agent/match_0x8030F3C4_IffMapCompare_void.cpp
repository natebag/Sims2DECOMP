// 0x8030F3C4 IffMapCompare(void (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); lwz 0,0x0(4); cmpw 9,0; li 3,-1; bltlr; mfcr 3; rlwinm 3,3,2,31,31"
extern "C" int f_8030F3C4() {}
