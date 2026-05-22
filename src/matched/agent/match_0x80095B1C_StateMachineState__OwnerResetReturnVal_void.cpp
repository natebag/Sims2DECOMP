// 0x80095B1C StateMachineState::OwnerResetReturnVal(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); li 0,0; stw 0,0x90(9)"
extern "C" void f_80095B1C() {}
