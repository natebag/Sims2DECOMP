// 0x80238118 ERLevel::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13060(9)"
extern "C" int f_80238118() {}
