// 0x80145604 RoutingSlot::Absolute(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1c(3); rlwinm 3,3,23,31,31"
extern "C" int f_80145604() {}
