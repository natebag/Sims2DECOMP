// 0x800D26E0 GetTotalSaveGameSize(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32696; lwz 3,0x633c(9)"
extern "C" int f_800D26E0() {}
