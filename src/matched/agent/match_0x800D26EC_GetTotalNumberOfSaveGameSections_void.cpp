// 0x800D26EC GetTotalNumberOfSaveGameSections(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32696; lwz 3,0x6334(9)"
extern "C" int f_800D26EC() {}
