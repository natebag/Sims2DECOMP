// 0x8024AF34 PPCMtpmc3 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 957,3"
extern "C" int f_8024AF34() {}
