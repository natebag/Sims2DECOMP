// 0x8003059C EIWallPart::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-19514(9)"
extern "C" int f_8003059C() {}
