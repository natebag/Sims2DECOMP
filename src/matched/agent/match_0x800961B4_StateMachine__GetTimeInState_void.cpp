// 0x800961B4 StateMachine::GetTimeInState(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x50(3)"
extern "C" int f_800961B4() {}
