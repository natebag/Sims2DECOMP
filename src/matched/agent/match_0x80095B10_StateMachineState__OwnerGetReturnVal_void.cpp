// 0x80095B10 StateMachineState::OwnerGetReturnVal(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); lwz 3,0x90(9)"
extern "C" int f_80095B10() {}
