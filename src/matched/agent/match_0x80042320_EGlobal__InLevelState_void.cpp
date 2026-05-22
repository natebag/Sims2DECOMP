// 0x80042320 EGlobal::InLevelState(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; lwz 3,0x5e6c(9); xoris 3,3,1; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80042320() {}
