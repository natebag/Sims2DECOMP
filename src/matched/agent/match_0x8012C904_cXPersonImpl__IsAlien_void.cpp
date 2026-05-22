// 0x8012C904 cXPersonImpl::IsAlien(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x9c(3); rlwinm 3,3,29,31,31"
extern "C" int f_8012C904() {}
