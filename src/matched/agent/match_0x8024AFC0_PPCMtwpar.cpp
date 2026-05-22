// 0x8024AFC0 PPCMtwpar (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 921,3"
extern "C" int f_8024AFC0() {}
