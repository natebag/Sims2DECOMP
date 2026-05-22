// 0x800997DC TheSimsStateMachine::IsFlowStateRequestPending(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x98(3); cmpwi 11,0; beq 0f; lwz 9,0x88(11); li 3,1; lwz 0,0x84(11); cmpw 0,9; bnelr; 0:; li 3,0"
extern "C" int f_800997DC() {}
