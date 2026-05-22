// 0x8017B988 FlowGotoTarget::SetPendingStateCurrent(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x84(3); stw 0,0x88(3)"
extern "C" void f_8017B988() {}
