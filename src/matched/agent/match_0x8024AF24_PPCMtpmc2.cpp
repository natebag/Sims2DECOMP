// 0x8024AF24 PPCMtpmc2 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 954,3"
extern "C" int f_8024AF24() {}
