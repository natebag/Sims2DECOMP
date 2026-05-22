// 0x8012CA00 cXPersonImpl::GetLastMotiveUpdateTick(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x538(3)"
extern "C" int f_8012CA00() {}
