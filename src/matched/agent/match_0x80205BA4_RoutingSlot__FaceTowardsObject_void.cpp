// 0x80205BA4 RoutingSlot::FaceTowardsObject(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; addi 1,1,8"
extern "C" int f_80205BA4() {}
