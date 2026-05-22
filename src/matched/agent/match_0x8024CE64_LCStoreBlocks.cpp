// 0x8024CE64 LCStoreBlocks (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 6,5,30,27,31; rlwinm 3,3,0,4,31; or 6,6,3; mtspr 922,6; rlwinm 6,5,2,28,29; or 6,6,4; ori 6,6,2; mtspr 923,6"
extern "C" int f_8024CE64() {}
