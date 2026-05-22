// 0x80364878 EFontPage::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-10512(9)"
extern "C" int f_80364878() {}
