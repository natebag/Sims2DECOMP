// 0x80096B80 StateMachine::IsEnabled(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x94(3)"
extern "C" int f_80096B80() {}
