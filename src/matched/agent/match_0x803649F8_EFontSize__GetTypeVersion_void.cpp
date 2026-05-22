// 0x803649F8 EFontSize::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10464(9)"
extern "C" int f_803649F8() {}
