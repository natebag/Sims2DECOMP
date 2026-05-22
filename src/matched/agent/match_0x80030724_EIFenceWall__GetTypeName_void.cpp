// 0x80030724 EIFenceWall::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-19484(9)"
extern "C" int f_80030724() {}
