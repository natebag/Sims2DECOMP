// 0x800A19D8 BString2::find_last_not_of_str(unsigned (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,3; mr 31,5; mr 25,4; mr 28,6; li 26,0; bl _s800A19D8_0; cmplw 31,3; bge 0f; addi 30,31,1; b 1f; 0:; mr 3,29; bl _s800A19D8_1; mr 30,3; 1:; mr 3,29; bl _s800A19D8_2; cmpwi 3,0; beq 7f; cmpwi 30,0; beq 7f; 2:; li 26,0; addi 27,30,-1; cmpw 26,28; beq 8f; mr 31,25; 3:; mr 3,29; bl _s800A19D8_3; cmpwi 3,0; beq 4f; lwz 9,0x0(29); lwz 0,0x0(9); b 5f; 4:; li 0,0; 5:; add 9,30,30; lhz 11,0x0(31); add 9,9,0; lhz 0,-2(9); cmpw 0,11; beq 6f; addi 26,26,1; addi 31,31,2; cmpw 26,28; bne 3b; 6:; cmpw 26,28; beq 8f; mr. 30,27; bne 2b; 7:; cmpw 26,28; bne 9f; 8:; mr 3,29; bl _s800A19D8_4; cmpwi 3,0; addi 3,30,-1; bne 10f; 9:; li 3,-1; 10:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s800A19D8_0();
extern "C" void _s800A19D8_1();
extern "C" void _s800A19D8_2();
extern "C" void _s800A19D8_3();
extern "C" void _s800A19D8_4();
extern "C" void f_800A19D8() {}
