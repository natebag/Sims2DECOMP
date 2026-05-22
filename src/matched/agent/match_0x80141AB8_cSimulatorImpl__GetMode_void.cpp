// 0x80141AB8 cSimulatorImpl::GetMode(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x3a(3)"
extern "C" int f_80141AB8() {}
