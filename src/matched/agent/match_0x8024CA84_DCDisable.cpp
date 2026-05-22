// 0x8024CA84 DCDisable (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sync; mfspr 3,1008; rlwinm 3,3,0,18,16; mtspr 1008,3"
extern "C" int f_8024CA84() {}
