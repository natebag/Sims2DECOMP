// 0x8024AF44 PPCMtpmc4 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 958,3"
extern "C" int f_8024AF44() {}
