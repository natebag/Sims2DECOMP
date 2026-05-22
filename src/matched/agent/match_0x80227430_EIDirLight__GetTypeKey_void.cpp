// 0x80227430 EIDirLight::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13384(9)"
extern "C" int f_80227430() {}
