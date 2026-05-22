// 0x803649D4 EFontSize::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-10484"
extern "C" int f_803649D4() {}
