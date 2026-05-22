// 0x80145668 RoutingSlot::SetAllowDifferentAlts(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); cmplwi 4,0; rlwinm 0,0,0,17,15; stw 0,0x1c(3); beqlr; ori 0,0,32768; stw 0,0x1c(3)"
extern "C" void f_80145668() {}
