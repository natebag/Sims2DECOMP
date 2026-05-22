// 0x80048434 EIFloor::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-18546(9)"
extern "C" int f_80048434() {}
