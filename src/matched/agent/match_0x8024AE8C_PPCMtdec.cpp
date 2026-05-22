// 0x8024AE8C PPCMtdec (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 22,3"
extern "C" int f_8024AE8C() {}
