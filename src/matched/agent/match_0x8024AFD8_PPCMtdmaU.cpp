// 0x8024AFD8 PPCMtdmaU (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 922,3"
extern "C" int f_8024AFD8() {}
