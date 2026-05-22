// 0x8012C8F8 cXPersonImpl::IsGhost(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x9c(3); rlwinm 3,3,30,31,31"
extern "C" int f_8012C8F8() {}
