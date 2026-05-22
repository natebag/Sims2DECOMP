// 0x8014565C RoutingSlot::GetAllowFailureTrees(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1c(3); rlwinm 3,3,18,31,31"
extern "C" int f_8014565C() {}
