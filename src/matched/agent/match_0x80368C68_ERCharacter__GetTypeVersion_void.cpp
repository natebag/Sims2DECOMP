// 0x80368C68 ERCharacter::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10224(9)"
extern "C" int f_80368C68() {}
