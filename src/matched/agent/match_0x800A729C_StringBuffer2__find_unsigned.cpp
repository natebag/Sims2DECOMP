// 0x800A729C StringBuffer2::find(unsigned (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 24,4; mr 25,3; mr 30,5; mr 3,24; bl _s800A729C_0; mr 29,30; mr 27,3; mr 3,25; bl _s800A729C_1; subf 3,27,3; addi 26,3,1; cmpw 29,26; bge 5f; 0:; li 28,1; li 30,0; mr 31,24; b 2f; 1:; addi 31,31,2; addi 30,30,1; 2:; cmpw 30,27; bge 3f; mr 3,25; add 4,29,30; bl _s800A729C_2; lhz 0,0x0(31); cmpw 3,0; beq 1b; li 28,0; 3:; cmpwi 28,0; beq 4f; mr 3,29; b 6f; 4:; addi 29,29,1; cmpw 29,26; blt 0b; 5:; li 3,-1; 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s800A729C_0();
extern "C" void _s800A729C_1();
extern "C" void _s800A729C_2();
extern "C" void f_800A729C() {}
