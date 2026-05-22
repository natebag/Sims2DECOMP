// 0x80229C80 EIPointAmbLight::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13258(9)"
extern "C" int f_80229C80() {}
