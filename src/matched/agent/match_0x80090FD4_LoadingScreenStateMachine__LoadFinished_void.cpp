// 0x80090FD4 LoadingScreenStateMachine::LoadFinished(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0xa4(3)"
extern "C" void f_80090FD4() {}
