// 0x802293C4 EInstance::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-18508(9)"
extern "C" int f_802293C4() {}
