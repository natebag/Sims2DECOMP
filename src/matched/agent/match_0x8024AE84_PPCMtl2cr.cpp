// 0x8024AE84 PPCMtl2cr (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 1017,3"
extern "C" int f_8024AE84() {}
