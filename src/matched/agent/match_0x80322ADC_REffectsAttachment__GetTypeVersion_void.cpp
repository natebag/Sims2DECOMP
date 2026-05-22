// 0x80322ADC REffectsAttachment::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12444(9)"
extern "C" int f_80322ADC() {}
