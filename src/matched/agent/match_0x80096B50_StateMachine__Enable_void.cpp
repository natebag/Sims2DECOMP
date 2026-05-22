// 0x80096B50 StateMachine::Enable(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x94(3)"
extern "C" void f_80096B50() {}
