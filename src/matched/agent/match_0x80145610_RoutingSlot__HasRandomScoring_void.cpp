// 0x80145610 RoutingSlot::HasRandomScoring(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1c(3); rlwinm 3,3,19,31,31"
extern "C" int f_80145610() {}
