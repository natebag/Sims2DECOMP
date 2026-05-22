// 0x80145688 RoutingSlot::GetAllowDifferentAlts(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1c(3); rlwinm 3,3,17,31,31"
extern "C" int f_80145688() {}
