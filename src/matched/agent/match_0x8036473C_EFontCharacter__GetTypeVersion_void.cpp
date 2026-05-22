// 0x8036473C EFontCharacter::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10544(9)"
extern "C" int f_8036473C() {}
