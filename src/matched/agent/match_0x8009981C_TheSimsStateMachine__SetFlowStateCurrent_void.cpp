// 0x8009981C TheSimsStateMachine::SetFlowStateCurrent(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x98(3); cmplwi 9,0; beqlr; lwz 0,0x84(9); stw 0,0x88(9)"
extern "C" void f_8009981C() {}
