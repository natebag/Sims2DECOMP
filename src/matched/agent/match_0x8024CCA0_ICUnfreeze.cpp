// 0x8024CCA0 ICUnfreeze (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,1008; rlwinm 3,3,0,19,17; mtspr 1008,3"
extern "C" int f_8024CCA0() {}
