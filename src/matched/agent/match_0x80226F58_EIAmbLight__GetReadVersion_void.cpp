// 0x80226F58 EIAmbLight::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13458(9)"
extern "C" int f_80226F58() {}
