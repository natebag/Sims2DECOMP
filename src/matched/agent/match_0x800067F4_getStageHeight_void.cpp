// 0x800067F4 getStageHeight(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32707; lfs f1,-11452(9)"
extern "C" float f_800067F4() {}
