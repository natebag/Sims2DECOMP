// 0x80096B24 StateMachine::GetMachineId(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1c(3)"
extern "C" int f_80096B24() {}
