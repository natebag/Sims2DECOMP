// 0x80227814 EIGameInstance::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13344(9)"
extern "C" int f_80227814() {}
