// 0x8024CC8C ICFreeze (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="isync; mfspr 3,1008; ori 3,3,8192; mtspr 1008,3"
extern "C" int f_8024CC8C() {}
