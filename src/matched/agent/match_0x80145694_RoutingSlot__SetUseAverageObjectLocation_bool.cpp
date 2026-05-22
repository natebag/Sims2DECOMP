// 0x80145694 RoutingSlot::SetUseAverageObjectLocation(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); cmplwi 4,0; rlwinm 0,0,0,16,14; stw 0,0x1c(3); beqlr; oris 0,0,1; stw 0,0x1c(3)"
extern "C" void f_80145694() {}
