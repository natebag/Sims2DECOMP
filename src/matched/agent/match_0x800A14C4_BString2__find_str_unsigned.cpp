// 0x800A14C4 BString2::find_str(unsigned (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 26,3; mr 31,4; mr 29,6; mr 27,5; bl _s800A14C4_0; cmpwi 3,0; beq 9f; cmpwi 29,0; bne 1f; b 9f; 0:; mr 3,27; b 10f; 1:; add 0,29,29; addi 24,29,-2; add 22,31,0; add 23,31,24; b 8f; 2:; li 28,0; cmplw 28,29; bge 7f; add 25,27,27; add 30,23,29; add 31,29,24; 3:; mr 3,26; bl _s800A14C4_1; cmpwi 3,0; beq 4f; lwz 9,0x0(26); lwz 9,0x0(9); b 5f; 4:; li 9,0; 5:; add 9,25,9; lhz 11,0x0(30); lhzx 0,31,9; li 9,1; cmpw 11,0; bne 6f; li 9,0; 6:; cmpwi 9,0; bne 7f; addi 28,28,1; addi 30,30,-2; addi 31,31,-2; cmplw 28,29; blt 3b; 7:; cmpw 28,29; beq 0b; add 9,28,28; subf 31,28,29; subf 9,9,22; add 5,27,31; lhz 4,-2(9); mr 3,26; bl _s800A14C4_2; cmpwi 3,-1; beq 9f; addi 0,3,1; subf 27,31,0; 8:; mr 3,26; bl _s800A14C4_3; subf 3,27,3; cmplw 29,3; ble 2b; 9:; li 3,-1; 10:; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s800A14C4_0();
extern "C" void _s800A14C4_1();
extern "C" void _s800A14C4_2();
extern "C" void _s800A14C4_3();
extern "C" void f_800A14C4() {}
