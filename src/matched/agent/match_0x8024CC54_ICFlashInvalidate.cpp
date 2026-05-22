// 0x8024CC54 ICFlashInvalidate (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 3,1008; ori 3,3,2048; mtspr 1008,3"
extern "C" int f_8024CC54() {}
