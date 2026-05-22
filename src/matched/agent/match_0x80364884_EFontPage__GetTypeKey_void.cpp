// 0x80364884 EFontPage::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-10508(9)"
extern "C" int f_80364884() {}
