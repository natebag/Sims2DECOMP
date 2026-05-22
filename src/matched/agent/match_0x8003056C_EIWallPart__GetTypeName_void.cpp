// 0x8003056C EIWallPart::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-19524(9)"
extern "C" int f_8003056C() {}
