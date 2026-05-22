// 0x8024AFAC PPCMthid2 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 920,3"
extern "C" int f_8024AFAC() {}
