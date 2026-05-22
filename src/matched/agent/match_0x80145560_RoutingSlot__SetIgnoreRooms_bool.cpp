// 0x80145560 RoutingSlot::SetIgnoreRooms(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); cmplwi 4,0; rlwinm 0,0,0,21,19; stw 0,0x1c(3); beqlr; ori 0,0,2048; stw 0,0x1c(3)"
extern "C" void f_80145560() {}
