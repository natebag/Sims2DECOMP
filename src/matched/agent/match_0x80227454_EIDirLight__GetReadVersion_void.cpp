// 0x80227454 EIDirLight::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13378(9)"
extern "C" int f_80227454() {}
