// 0x800E7C14 EdithVariableSet::ReconKeyBitSet(ReconBuffer (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; lwz 28,0x0(5); lwz 0,0xc(29); li 31,0; mr 30,28; cmpwi 0,1; beq 0f; cmpwi 0,2; bne 3f; 0:; addi 0,31,1; cmpwi 31,2; mr 31,0; bne 1f; addi 4,30,3; mr 3,29; li 5,1; bl _s800E7C14_0; b 2f; 1:; mr 4,30; mr 3,29; li 5,1; bl _s800E7C14_1; 2:; rlwinm 0,31,2,0,29; cmpwi 31,3; add 30,28,0; blt 0b; b 7f; 3:; mr 3,28; li 4,0; li 5,12; bl _s800E7C14_2; 4:; addi 0,31,1; cmpwi 31,2; mr 31,0; bne 5f; addi 4,30,3; mr 3,29; li 5,1; bl _s800E7C14_3; b 6f; 5:; mr 4,30; mr 3,29; li 5,1; bl _s800E7C14_4; 6:; rlwinm 0,31,2,0,29; cmpwi 31,3; add 30,28,0; blt 4b; 7:; mr 3,28; li 10,0; addi 11,3,12; cmplw 3,11; bge 9f; lis 9,-32698; addi 8,9,-22288; 8:; lbz 0,0x0(3); addi 3,3,1; lbzx 9,8,0; cmplw 3,11; add 10,10,9; blt 8b; 9:; mr 3,10; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800E7C14_0();
extern "C" void _s800E7C14_1();
extern "C" void _s800E7C14_2();
extern "C" void _s800E7C14_3();
extern "C" void _s800E7C14_4();
extern "C" void f_800E7C14() {}
