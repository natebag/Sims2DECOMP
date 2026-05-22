// 0x800568D0 ISimInstance::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-19356(9)"
extern "C" int f_800568D0() {}
