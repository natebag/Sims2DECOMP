// 0x8024CC78 ICDisable (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="isync; mfspr 3,1008; rlwinm 3,3,0,17,15; mtspr 1008,3"
extern "C" int f_8024CC78() {}
