// 0x8024CE40 LCLoadBlocks (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 6,5,30,27,31; rlwinm 4,4,0,4,31; or 6,6,4; mtspr 922,6; rlwinm 6,5,2,28,29; or 6,6,3; ori 6,6,18; mtspr 923,6"
extern "C" int f_8024CE40() {}
