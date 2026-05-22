// 0x8024CA60 DCFlashInvalidate (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,1008; ori 3,3,1024; mtspr 1008,3"
extern "C" int f_8024CA60() {}
