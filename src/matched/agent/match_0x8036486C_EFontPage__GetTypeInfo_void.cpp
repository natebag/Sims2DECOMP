// 0x8036486C EFontPage::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-10524"
extern "C" int f_8036486C() {}
