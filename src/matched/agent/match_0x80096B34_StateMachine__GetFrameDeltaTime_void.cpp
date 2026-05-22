// 0x80096B34 StateMachine::GetFrameDeltaTime(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x28(3)"
extern "C" int f_80096B34() {}
