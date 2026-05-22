// 0x80095DFC StateMachine::ReturnFromState(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 4,0x8c(3); stw 0,0x88(3)"
extern "C" void f_80095DFC() {}
