// 0x8012C91C cXPersonImpl::NeedsWantFearShuffle(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x9c(3); rlwinm 3,3,27,31,31"
extern "C" int f_8012C91C() {}
