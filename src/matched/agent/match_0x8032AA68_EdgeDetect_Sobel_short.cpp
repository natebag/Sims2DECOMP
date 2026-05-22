// 0x8032AA68 EdgeDetect_Sobel(short (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 20,0x48(1); stw 0,0x7c(1); mr 28,6; mr 31,7; addi 25,1,56; mr 29,5; mr 22,4; mr 26,3; bl _s8032AA68_0; mullw 30,29,28; addi 24,1,64; li 5,0; add 30,30,30; mr 4,30; bl _s8032AA68_1; mr 27,3; bl _s8032AA68_2; mr 4,30; li 5,0; bl _s8032AA68_3; lis 9,-32702; addi 11,1,16; mr 30,3; addi 9,9,4984; mr 20,11; li 10,24; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); li 4,9; addi 3,1,16; mullw 23,29,28; stw 0,0x0(11); addi 21,31,8; lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); bl _s8032AA68_4; lhz 0,0x0(31); mr 8,3; lbz 9,0x2(31); li 10,3; sth 0,0x38(1); mr 3,26; stb 9,0x2(25); mr 4,27; li 9,3; stw 25,0x8(1); mr 5,29; mr 6,28; addi 7,1,16; bl _s8032AA68_5; lis 9,-32702; mr 11,20; addi 9,9,5020; li 10,24; 1:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 1b; lwz 0,0x0(9); addi 3,1,16; li 4,9; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); bl _s8032AA68_6; lhz 0,0x0(31); mr 8,3; lbz 11,0x2(31); addi 7,1,16; sth 0,0x40(1); li 9,3; stw 24,0x8(1); li 10,3; stb 11,0x2(24); mr 3,26; mr 4,30; mr 5,29; mr 6,28; bl _s8032AA68_7; mr 6,23; mr 5,30; mr 4,27; mr 3,22; bl _s8032AA68_8; bl _s8032AA68_9; mr 4,30; bl _s8032AA68_10; bl _s8032AA68_11; mr 4,27; bl _s8032AA68_12; mr 3,22; mr 4,26; mr 5,29; mr 6,28; mr 7,21; bl _s8032AA68_13; lwz 0,0x7c(1); mtspr 8,0; lmw 20,0x48(1); addi 1,1,120"
extern "C" void _s8032AA68_0();
extern "C" void _s8032AA68_1();
extern "C" void _s8032AA68_2();
extern "C" void _s8032AA68_3();
extern "C" void _s8032AA68_4();
extern "C" void _s8032AA68_5();
extern "C" void _s8032AA68_6();
extern "C" void _s8032AA68_7();
extern "C" void _s8032AA68_8();
extern "C" void _s8032AA68_9();
extern "C" void _s8032AA68_10();
extern "C" void _s8032AA68_11();
extern "C" void _s8032AA68_12();
extern "C" void _s8032AA68_13();
extern "C" void f_8032AA68() {}
