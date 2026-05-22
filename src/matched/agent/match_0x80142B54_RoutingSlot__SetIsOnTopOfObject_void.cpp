// 0x80142B54 RoutingSlot::SetIsOnTopOfObject(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); clrlwi 0,0,23; stw 0,0x1c(3)"
extern "C" void f_80142B54() {}
