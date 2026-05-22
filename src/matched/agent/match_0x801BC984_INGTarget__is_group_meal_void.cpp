// 0x801BC984 INGTarget::is_group_meal(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8c(3); xoris 3,3,2; subfic 0,3,0; adde 3,0,3"
extern "C" int f_801BC984() {}
