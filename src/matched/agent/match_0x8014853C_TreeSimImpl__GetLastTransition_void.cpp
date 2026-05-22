// 0x8014853C TreeSimImpl::GetLastTransition(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x28(3); xori 3,3,254; subfic 0,3,0; adde 3,0,3"
extern "C" int f_8014853C() {}
