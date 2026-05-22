// 0x80364B60 EFontData::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10424(9)"
extern "C" int f_80364B60() {}
