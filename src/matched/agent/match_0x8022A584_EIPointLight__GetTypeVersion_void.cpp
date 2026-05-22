// 0x8022A584 EIPointLight::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13220(9)"
extern "C" int f_8022A584() {}
