// 0x80364724 EFontCharacter::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-10552(9)"
extern "C" int f_80364724() {}
