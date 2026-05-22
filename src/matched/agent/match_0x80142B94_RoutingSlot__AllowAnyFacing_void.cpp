// 0x80142B94 RoutingSlot::AllowAnyFacing(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,-3; stw 0,0x34(3)"
extern "C" void f_80142B94() {}
