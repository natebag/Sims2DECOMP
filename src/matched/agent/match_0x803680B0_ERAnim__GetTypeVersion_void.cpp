// 0x803680B0 ERAnim::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10344(9)"
extern "C" int f_803680B0() {}
