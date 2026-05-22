// 0x80142B64 RoutingSlot::AllowDirection(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,7; bgtlr; lwz 9,0x1c(3); li 0,1; slw 0,0,4; or 9,9,0; stw 9,0x1c(3)"
extern "C" void f_80142B64() {}
