// 0x800691F4 SAnimator2::IsRouting(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x10(3); xori 3,3,1; subfic 0,3,0; adde 3,0,3"
extern "C" int f_800691F4() {}
