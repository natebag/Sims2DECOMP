// 0x802281A8 EILight::GetFalloffEnd(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32704; lfs f1,-6524(9)"
extern "C" float f_802281A8() {}
