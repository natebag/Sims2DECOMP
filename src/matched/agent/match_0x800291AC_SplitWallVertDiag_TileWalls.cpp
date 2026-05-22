// 0x800291AC SplitWallVertDiag(TileWalls (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); lwz 11,-21488(13); mr 30,4; addi 29,1,16; lwz 9,0x0(11); mr 31,29; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 28,3; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lbz 4,0x0(30); mr 27,3; lbz 5,0x1(30); li 6,1; extsb 4,4; addi 3,1,8; addi 4,4,-1; extsb 5,5; bl _s800291AC_0; lbz 5,0x1(30); mr 3,29; lbz 4,0x0(30); li 6,1; extsb 5,5; extsb 4,4; addi 5,5,-1; bl _s800291AC_1; lbz 0,0x8(1); extsb 9,0; cmpwi 9,0; blt 0f; addi 0,28,-1; cmpw 9,0; bgt 0f; lbz 0,0x9(1); extsb 9,0; cmpwi 9,0; blt 0f; addi 0,27,-1; cmpw 9,0; bgt 0f; lwz 11,-21488(13); addi 4,1,8; lwz 9,0x0(11); lwz 0,0xcc(9); lha 3,0xc8(9); mtspr 8,0; add 3,11,3; blrl; lbz 0,0x0(3); andi. 9,0,16; bne 1f; 0:; lbz 0,0x10(1); extsb 9,0; cmpwi 9,0; blt 2f; addi 0,28,-1; cmpw 9,0; bgt 2f; lbz 0,0x11(1); extsb 9,0; cmpwi 9,0; blt 2f; addi 0,27,-1; cmpw 9,0; bgt 2f; lwz 11,-21488(13); mr 4,31; lwz 9,0x0(11); lwz 0,0xcc(9); lha 3,0xc8(9); mtspr 8,0; add 3,11,3; blrl; lbz 0,0x0(3); andi. 9,0,16; beq 2f; 1:; mr 3,31; li 4,2; bl _s800291AC_2; addi 3,1,8; li 4,2; bl _s800291AC_3; li 3,1; b 3f; 2:; mr 3,31; li 4,2; bl _s800291AC_4; addi 3,1,8; li 4,2; bl _s800291AC_5; li 3,0; 3:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s800291AC_0();
extern "C" void _s800291AC_1();
extern "C" void _s800291AC_2();
extern "C" void _s800291AC_3();
extern "C" void _s800291AC_4();
extern "C" void _s800291AC_5();
extern "C" void f_800291AC() {}
