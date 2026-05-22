// 0x8012C910 cXPersonImpl::IsInMotiveFailure(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x9c(3); rlwinm 3,3,28,31,31"
extern "C" int f_8012C910() {}
