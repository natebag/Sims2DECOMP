// 0x80141A8C cSimulatorImpl::IsStopped(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x17c(3); cmpwi 0,0; beq 0f; li 3,0; blr; 0:; lwz 0,0x178(3); li 3,1; cmpwi 0,0; bnelr; li 3,0"
extern "C" int f_80141A8C() {}
