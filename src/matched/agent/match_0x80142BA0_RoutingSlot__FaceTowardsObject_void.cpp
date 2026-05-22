// 0x80142BA0 RoutingSlot::FaceTowardsObject(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,-2; stw 0,0x34(3)"
extern "C" void f_80142BA0() {}
