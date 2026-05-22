// 0x80099804 TheSimsStateMachine::GetFlowStateRequest(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x98(3); cmplwi 9,0; li 3,0; beqlr; lwz 3,0x84(9)"
extern "C" int f_80099804() {}
