// 0x803648A8 EFontPage::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10502(9)"
extern "C" int f_803648A8() {}
