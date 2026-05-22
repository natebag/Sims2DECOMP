// 0x80227808 EIGameInstance::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13348(9)"
extern "C" int f_80227808() {}
