// 0x8003073C EIFenceWall::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-19476(9)"
extern "C" int f_8003073C() {}
