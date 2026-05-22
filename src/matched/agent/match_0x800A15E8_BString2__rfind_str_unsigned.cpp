// 0x800A15E8 BString2::rfind_str(unsigned (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 26,3; mr 30,5; mr 31,6; mr 29,4; bl _s800A15E8_0; subf 3,31,3; cmplw 30,3; bge 0f; addi 27,30,1; b 1f; 0:; mr 3,26; bl _s800A15E8_1; subf 27,31,3; 1:; mr 3,26; bl _s800A15E8_2; cmplw 3,31; blt 10f; cmpwi 31,0; bne 3f; b 10f; 2:; addi 3,27,-1; b 11f; 3:; cmpwi 27,0; beq 10f; add 9,31,31; addi 0,31,-2; add 23,29,0; add 24,29,9; 4:; li 28,0; cmplw 28,31; bge 9f; add 25,27,27; add 29,23,31; add 30,31,31; 5:; mr 3,26; bl _s800A15E8_3; cmpwi 3,0; beq 6f; lwz 9,0x0(26); lwz 9,0x0(9); b 7f; 6:; li 9,0; 7:; add 9,25,9; lhz 11,0x0(29); add 9,30,9; li 10,1; lhz 0,-4(9); cmpw 11,0; bne 8f; li 10,0; 8:; cmpwi 10,0; bne 9f; addi 28,28,1; addi 29,29,-2; addi 30,30,-2; cmplw 28,31; blt 5b; 9:; cmpw 28,31; beq 2b; add 9,28,28; subf 5,28,31; subf 9,9,24; add 5,27,5; lhz 4,-2(9); addi 5,5,-3; mr 3,26; bl _s800A15E8_4; cmpwi 3,-1; beq 10f; add 0,3,28; subf 0,31,0; addic. 27,0,2; bne 4b; 10:; li 3,-1; 11:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s800A15E8_0();
extern "C" void _s800A15E8_1();
extern "C" void _s800A15E8_2();
extern "C" void _s800A15E8_3();
extern "C" void _s800A15E8_4();
extern "C" void f_800A15E8() {}
