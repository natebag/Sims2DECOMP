// 0x80228014 EILight::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13428(9)"
extern "C" int f_80228014() {}
