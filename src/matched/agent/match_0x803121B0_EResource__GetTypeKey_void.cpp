// 0x803121B0 EResource::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-12984(9)"
extern "C" int f_803121B0() {}
