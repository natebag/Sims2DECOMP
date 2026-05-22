// 0x80364B54 EFontData::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-10428(9)"
extern "C" int f_80364B54() {}
