// 0x80228044 EILight::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13418(9)"
extern "C" int f_80228044() {}
