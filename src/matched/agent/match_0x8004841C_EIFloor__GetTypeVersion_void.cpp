// 0x8004841C EIFloor::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-18548(9)"
extern "C" int f_8004841C() {}
