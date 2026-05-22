// 0x801454C0 RoutingSlot::IsOnTopOfObject(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x1f(3); subfic 0,3,0; adde 3,0,3"
extern "C" int f_801454C0() {}
