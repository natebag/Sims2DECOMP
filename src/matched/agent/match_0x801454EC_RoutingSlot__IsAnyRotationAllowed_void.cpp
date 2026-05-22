// 0x801454EC RoutingSlot::IsAnyRotationAllowed(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); li 3,1; andi. 9,0,256; bnelr; li 3,0"
extern "C" int f_801454EC() {}
