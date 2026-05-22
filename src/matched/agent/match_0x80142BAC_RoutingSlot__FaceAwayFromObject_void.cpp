// 0x80142BAC RoutingSlot::FaceAwayFromObject(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,-1; stw 0,0x34(3)"
extern "C" void f_80142BAC() {}
