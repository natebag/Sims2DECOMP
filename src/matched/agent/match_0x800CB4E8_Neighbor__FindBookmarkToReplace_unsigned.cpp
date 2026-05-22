// 0x800CB4E8 Neighbor::FindBookmarkToReplace(unsigned (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 28,5; mr 31,4; mr 29,3; li 25,-1; li 26,128; cmplw 31,28; bge 3f; mulli 9,31,12; lwz 0,0x194(29); addi 9,9,4; add 9,9,0; 0:; lwz 0,0x0(9); li 11,1; addi 9,9,12; cmpwi 0,0; bne 1f; li 11,0; 1:; cmpwi 11,0; bne 2f; mr 3,31; b 8f; 2:; addi 31,31,1; cmplw 31,28; blt 0b; 3:; mr 31,4; cmplw 31,28; bge 7f; mulli 30,31,12; lha 27,-21222(13); 4:; lwz 4,0x194(29); mr 3,29; add 4,4,30; bl _s800CB4E8_0; cmpw 3,27; bne 6f; lwz 3,0x194(29); add 3,3,30; bl _s800CB4E8_1; cmpwi 3,0; bne 5f; lwz 3,0x194(29); add 3,3,30; bl _s800CB4E8_2; cmpwi 3,0; bne 6f; 5:; lwz 4,0x194(29); mr 3,29; add 4,4,30; bl _s800CB4E8_3; cmplw 3,26; bge 6f; mr 26,3; mr 25,31; 6:; addi 31,31,1; addi 30,30,12; cmplw 31,28; blt 4b; 7:; mr 3,25; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s800CB4E8_0();
extern "C" void _s800CB4E8_1();
extern "C" void _s800CB4E8_2();
extern "C" void _s800CB4E8_3();
extern "C" void f_800CB4E8() {}
