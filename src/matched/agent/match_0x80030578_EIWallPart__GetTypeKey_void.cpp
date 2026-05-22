// 0x80030578 EIWallPart::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-19520(9)"
extern "C" int f_80030578() {}
