// 0x80364748 EFontCharacter::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-10564"
extern "C" int f_80364748() {}
