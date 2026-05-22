// 0x80035114 ESim::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-19396(9)"
extern "C" int f_80035114() {}
