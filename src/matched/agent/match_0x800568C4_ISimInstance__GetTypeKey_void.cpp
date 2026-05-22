// 0x800568C4 ISimInstance::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-19360(9)"
extern "C" int f_800568C4() {}
