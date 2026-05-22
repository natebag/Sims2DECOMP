// 0x800067E8 getStageWidth(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32707; lfs f1,-11456(9)"
extern "C" float f_800067E8() {}
