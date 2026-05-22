// 0x8024CA98 DCFreeze (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sync; mfspr 3,1008; ori 3,3,4096; mtspr 1008,3"
extern "C" int f_8024CA98() {}
