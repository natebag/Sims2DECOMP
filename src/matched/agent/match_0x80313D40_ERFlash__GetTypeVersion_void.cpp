// 0x80313D40 ERFlash::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12644(9)"
extern "C" int f_80313D40() {}
