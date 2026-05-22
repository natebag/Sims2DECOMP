// 0x8010EDFC StateMachineState::Draw(ERC (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8010EE50" lines="blrl; li 3,-1; li 4,-1"
extern "C" void f_8010EE50();
extern "C" void f_8010EDFC() {}
