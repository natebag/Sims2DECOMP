// 0x801455C0 RoutingSlot::SnapsToDirection(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); li 3,1; andi. 9,0,4096; bnelr; li 3,0"
extern "C" int f_801455C0() {}
