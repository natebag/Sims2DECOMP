// 0x800542A4 ISimsCounterTopObject::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-18348(9)"
extern "C" int f_800542A4() {}
