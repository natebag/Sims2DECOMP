// 0x80093BD4 MUStateMachine::GetMUWrapper(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x98(3)"
extern "C" int f_80093BD4() {}
