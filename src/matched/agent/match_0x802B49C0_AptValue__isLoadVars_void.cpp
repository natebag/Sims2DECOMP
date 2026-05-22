// 0x802B49C0 AptValue::isLoadVars(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); rlwinm 3,3,0,25,31; xori 3,3,35; subfic 0,3,0; adde 3,0,3"
extern "C" int f_802B49C0() {}
