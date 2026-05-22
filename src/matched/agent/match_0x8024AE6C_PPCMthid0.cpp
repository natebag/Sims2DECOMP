// 0x8024AE6C PPCMthid0 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 1008,3"
extern "C" int f_8024AE6C() {}
