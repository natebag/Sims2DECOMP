// 0x8024AF04 PPCMtmmcr1 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 956,3"
extern "C" int f_8024AF04() {}
