// 0x8024AF54 PPCMtsia (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 955,3"
extern "C" int f_8024AF54() {}
