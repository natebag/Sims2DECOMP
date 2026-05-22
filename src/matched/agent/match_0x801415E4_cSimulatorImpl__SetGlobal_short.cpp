// 0x801415E4 cSimulatorImpl::SetGlobal(short, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,1,0,30; addi 3,3,20; sthx 5,3,4"
extern "C" void f_801415E4() {}
