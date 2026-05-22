// 0x8024CA70 DCEnable (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sync; mfspr 3,1008; ori 3,3,16384; mtspr 1008,3"
extern "C" int f_8024CA70() {}
