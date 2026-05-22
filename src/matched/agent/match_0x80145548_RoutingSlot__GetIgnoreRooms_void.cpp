// 0x80145548 RoutingSlot::GetIgnoreRooms(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); li 3,1; andi. 9,0,2048; bnelr; li 3,0"
extern "C" int f_80145548() {}
