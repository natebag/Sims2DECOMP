// 0x8022743C EIDirLight::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13380(9)"
extern "C" int f_8022743C() {}
