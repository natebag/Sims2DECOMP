// 0x8007AB94 CatWsAToBuff(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,4; mr 8,3; lhz 0,0x0(9); li 11,0; cmpwi 0,0; beq 1f; 0:; lhzu 0,0x2(9); addi 11,11,1; cmpwi 0,0; bne 0b; 1:; lhz 3,0x0(3); add 0,11,11; add 9,4,0; li 10,0; cmpwi 3,0; beq 3f; addi 5,5,-1; cmplw 11,5; bge 3f; 2:; sth 3,0x0(9); addi 11,11,1; lhzu 3,0x2(8); addi 9,9,2; addi 10,10,1; cmpwi 3,0; beq 3f; cmplw 11,5; blt 2b; 3:; li 0,0; mr 3,10; sth 0,0x0(9)"
extern "C" void f_8007AB94() {}
