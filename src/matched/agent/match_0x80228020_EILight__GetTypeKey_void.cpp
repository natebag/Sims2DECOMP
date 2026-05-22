// 0x80228020 EILight::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13424(9)"
extern "C" int f_80228020() {}
