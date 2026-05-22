// 0x8003512C ESim::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-19394(9)"
extern "C" int f_8003512C() {}
