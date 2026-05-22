// 0x801415DC cSimulatorImpl::GetDaysRunning(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x4c(3)"
extern "C" int f_801415DC() {}
