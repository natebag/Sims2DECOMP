// 0x803649E0 EFontSize::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-10472(9)"
extern "C" int f_803649E0() {}
