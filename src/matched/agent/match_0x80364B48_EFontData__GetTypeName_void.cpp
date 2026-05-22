// 0x80364B48 EFontData::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-10432(9)"
extern "C" int f_80364B48() {}
