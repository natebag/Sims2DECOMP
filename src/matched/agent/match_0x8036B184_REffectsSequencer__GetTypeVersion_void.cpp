// 0x8036B184 REffectsSequencer::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10024(9)"
extern "C" int f_8036B184() {}
