// 0x802B47E8 AptValue::getGCMark(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); rlwinm 3,3,2,31,31"
extern "C" int f_802B47E8() {}
