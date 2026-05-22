// 0x80226F40 EIAmbLight::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13460(9)"
extern "C" int f_80226F40() {}
