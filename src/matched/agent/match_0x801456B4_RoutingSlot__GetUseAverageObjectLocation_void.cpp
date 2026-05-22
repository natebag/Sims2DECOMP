// 0x801456B4 RoutingSlot::GetUseAverageObjectLocation(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x1c(3); rlwinm 3,3,0,31,31"
extern "C" int f_801456B4() {}
