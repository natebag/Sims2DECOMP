// 0x80227820 EIGameInstance::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13340(9)"
extern "C" int f_80227820() {}
