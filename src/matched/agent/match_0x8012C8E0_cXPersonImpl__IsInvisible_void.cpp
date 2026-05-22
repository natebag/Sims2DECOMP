// 0x8012C8E0 cXPersonImpl::IsInvisible(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x9c(3); rlwinm 3,3,0,31,31"
extern "C" int f_8012C8E0() {}
