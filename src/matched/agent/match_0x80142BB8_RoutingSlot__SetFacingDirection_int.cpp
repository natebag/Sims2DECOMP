// 0x80142BB8 RoutingSlot::SetFacingDirection(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,7; bgtlr; stw 4,0x34(3)"
extern "C" void f_80142BB8() {}
