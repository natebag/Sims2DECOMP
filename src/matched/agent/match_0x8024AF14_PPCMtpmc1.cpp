// 0x8024AF14 PPCMtpmc1 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 953,3"
extern "C" int f_8024AF14() {}
