// 0x8007AB0C CatWsABToBuff(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; lhz 0,0x0(11); li 3,0; cmpwi 0,0; beq 1f; addi 9,6,-1; cmplw 3,9; bge 1f; 0:; sth 0,0x0(5); addi 3,3,1; lhzu 0,0x2(11); addi 5,5,2; cmpwi 0,0; beq 1f; cmplw 3,9; blt 0b; 1:; mr 11,4; lhz 0,0x0(11); cmpwi 0,0; beq 3f; addi 6,6,-1; cmplw 3,6; bge 3f; 2:; sth 0,0x0(5); addi 3,3,1; lhzu 0,0x2(11); addi 5,5,2; cmpwi 0,0; beq 3f; cmplw 3,6; blt 2b; 3:; li 0,0; sth 0,0x0(5)"
extern "C" void f_8007AB0C() {}
