// 0x80368C74 ERCharacter::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-10244"
extern "C" int f_80368C74() {}
