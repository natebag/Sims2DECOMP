// 0x80142C30 RoutingSlot::SetMultiplier(RoutingSlot::VerticalPosition, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,16; stwx 5,3,4"
extern "C" void f_80142C30() {}
