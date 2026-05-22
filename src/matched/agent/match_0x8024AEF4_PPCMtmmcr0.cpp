// 0x8024AEF4 PPCMtmmcr0 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 952,3"
extern "C" int f_8024AEF4() {}
