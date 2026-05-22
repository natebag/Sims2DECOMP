// 0x80226F28 EIAmbLight::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13468(9)"
extern "C" int f_80226F28() {}
