// 0x80196364 CASTarget::IsViewingCAR(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x104(3); xori 3,3,3; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80196364() {}
