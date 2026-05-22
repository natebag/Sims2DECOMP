// 0x80142B84 RoutingSlot::AllowAnyRotation(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); ori 0,0,256; stw 0,0x1c(3)"
extern "C" void f_80142B84() {}
