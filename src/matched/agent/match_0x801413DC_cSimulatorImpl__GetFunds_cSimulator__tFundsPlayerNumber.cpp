// 0x801413DC cSimulatorImpl::GetFunds(cSimulator::tFundsPlayerNumber) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x78(3); lwz 3,0x74(3); add 3,3,0"
extern "C" int f_801413DC() {}
