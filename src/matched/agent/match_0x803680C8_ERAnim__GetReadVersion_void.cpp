// 0x803680C8 ERAnim::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10342(9)"
extern "C" int f_803680C8() {}
