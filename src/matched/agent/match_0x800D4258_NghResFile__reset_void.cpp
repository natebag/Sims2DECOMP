// 0x800D4258 NghResFile::reset(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 26,3; li 30,0; li 31,0; li 29,4; 0:; lwz 9,0x138(26); lwzx 3,31,9; bl _s800D4258_0; lwz 9,0x138(26); addic. 29,29,-1; stwx 30,31,9; addi 31,31,4; bne 0b; addi 30,26,316; addi 24,26,404; li 28,0; li 31,0; li 29,2; 1:; lwz 9,0x17c(26); lwzx 3,31,9; bl _s800D4258_1; lwz 9,0x17c(26); addic. 29,29,-1; stwx 28,31,9; addi 31,31,4; bne 1b; mr 27,30; li 25,0; li 28,0; li 29,16; 2:; li 31,0; li 30,6; 3:; lwzx 9,28,27; lwzx 3,31,9; bl _s800D4258_2; lwzx 9,28,27; addic. 30,30,-1; stwx 25,31,9; addi 31,31,4; bne 3b; addi 28,28,4; addic. 29,29,-1; bne 2b; li 11,36; addi 9,24,140; mtspr 9,11; li 0,0; 4:; stw 0,0x0(9); addi 9,9,-4; bdnz 4b; li 0,0; stw 0,0x24(26); lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s800D4258_0();
extern "C" void _s800D4258_1();
extern "C" void _s800D4258_2();
extern "C" void f_800D4258() {}
