// 0x8024AEA4 PPCEieio (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfmsr 5; rlwinm 6,5,0,17,15; mtmsr 6; mfspr 3,1008; ori 4,3,8; mtspr 1008,4; isync; eieio; isync; mtspr 1008,3; mtmsr 5; isync"
extern "C" int f_8024AEA4() {}
