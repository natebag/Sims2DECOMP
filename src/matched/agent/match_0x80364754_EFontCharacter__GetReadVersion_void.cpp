// 0x80364754 EFontCharacter::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10542(9)"
extern "C" int f_80364754() {}
