// 0x802B4294 AptValue::GetAllowDelayedDeletion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); rlwinm 3,3,6,31,31"
extern "C" int f_802B4294() {}
