// 0x80368574 ERBinary::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10264(9)"
extern "C" int f_80368574() {}
