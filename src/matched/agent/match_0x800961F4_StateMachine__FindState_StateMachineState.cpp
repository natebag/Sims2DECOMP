// 0x800961F4 StateMachine::FindState(StateMachineState (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x30(3); lwz 9,0x2c(3); cmpw 9,0; beq 1f; 0:; lwz 3,0x0(9); cmpw 3,4; beqlr; addi 9,9,4; cmpw 9,0; bne 0b; 1:; li 3,0"
extern "C" int f_800961F4() {}
