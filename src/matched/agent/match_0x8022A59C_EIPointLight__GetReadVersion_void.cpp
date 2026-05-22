// 0x8022A59C EIPointLight::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13218(9)"
extern "C" int f_8022A59C() {}
