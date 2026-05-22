// 0x80030584 EIWallPart::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-19516(9)"
extern "C" int f_80030584() {}
