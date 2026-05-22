// 0x80030754 EIFenceWall::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-19474(9)"
extern "C" int f_80030754() {}
