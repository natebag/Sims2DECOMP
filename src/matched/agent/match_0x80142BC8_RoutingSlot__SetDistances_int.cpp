// 0x80142BC8 RoutingSlot::SetDistances(int, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 6,0x2c(3); stw 4,0x24(3); stw 5,0x28(3)"
extern "C" void f_80142BC8() {}
