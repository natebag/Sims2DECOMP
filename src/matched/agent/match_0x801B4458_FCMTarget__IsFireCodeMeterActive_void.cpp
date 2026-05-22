// 0x801B4458 FCMTarget::IsFireCodeMeterActive(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x88(3)"
extern "C" int f_801B4458() {}
