// 0x800568E8 ISimInstance::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-19354(9)"
extern "C" int f_800568E8() {}
