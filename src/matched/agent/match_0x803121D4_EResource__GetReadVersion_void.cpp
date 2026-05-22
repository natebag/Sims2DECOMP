// 0x803121D4 EResource::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12978(9)"
extern "C" int f_803121D4() {}
