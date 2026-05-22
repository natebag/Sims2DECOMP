// 0x8032AC80 EdgeDetect_OnePass(short (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 26,0x40(1); stw 0,0x5c(1); lis 9,-32702; mr 29,3; mr 28,4; mr 27,5; mr 26,6; mr 31,7; addi 9,9,5056; addi 11,1,16; li 10,24; addi 30,1,56; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); li 4,9; addi 3,1,16; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); bl _s8032AC80_0; lhz 0,0x0(31); mr 8,3; lbz 9,0x2(31); mr 3,29; sth 0,0x38(1); mr 4,28; stb 9,0x2(30); mr 5,27; stw 30,0x8(1); mr 6,26; addi 7,1,16; li 9,3; li 10,3; bl _s8032AC80_1; lwz 0,0x5c(1); mtspr 8,0; lmw 26,0x40(1); addi 1,1,88"
extern "C" void _s8032AC80_0();
extern "C" void _s8032AC80_1();
extern "C" void f_8032AC80() {}
