// 0x801534CC XRoute::ResetGoals(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(3); lwz 0,0x4(3); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,16; cmpw 9,0; bne 0b; 1:; li 0,-1; stw 11,0x4(3); stw 0,0x58(3); stw 0,0x54(3)"
extern "C" void f_801534CC() {}
