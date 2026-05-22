// 0x8022B854 EISpotLight::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13138(9)"
extern "C" int f_8022B854() {}
