// 0x8024AFE0 PPCMtdmaL (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 923,3"
extern "C" int f_8024AFE0() {}
