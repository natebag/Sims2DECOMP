// 0x80141A2C cSimulatorImpl::GetLightingIntensity(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x68(3); rlwinm 3,3,0,23,31"
extern "C" int f_80141A2C() {}
