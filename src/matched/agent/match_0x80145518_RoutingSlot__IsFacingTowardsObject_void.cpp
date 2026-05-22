// 0x80145518 RoutingSlot::IsFacingTowardsObject(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x34(3); subfic 3,3,-2; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80145518() {}
