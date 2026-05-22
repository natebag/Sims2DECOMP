// 0x8024CC64 ICEnable (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="isync; mfspr 3,1008; ori 3,3,32768; mtspr 1008,3"
extern "C" int f_8024CC64() {}
