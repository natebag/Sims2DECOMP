// 0x80090E04 LoadingScreenStateMachine::GetLoadingScreen(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x98(3)"
extern "C" int f_80090E04() {}
