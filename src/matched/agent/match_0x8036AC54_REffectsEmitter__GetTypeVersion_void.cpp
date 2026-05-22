// 0x8036AC54 REffectsEmitter::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10064(9)"
extern "C" int f_8036AC54() {}
