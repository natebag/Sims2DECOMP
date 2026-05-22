// 0x8032A804 EdgeDetect_Prewitt(short (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 19,0x4c(1); stw 0,0x84(1); mr 29,6; mr 28,7; addi 24,1,56; mr 31,5; mr 25,4; mr 27,3; bl _s8032A804_0; mullw 30,31,29; addi 22,1,64; li 5,0; add 30,30,30; mr 4,30; bl _s8032A804_1; mr 26,3; bl _s8032A804_2; mr 4,30; li 5,0; bl _s8032A804_3; lis 9,-32702; addi 11,1,16; mr 30,3; addi 9,9,4912; mr 19,11; li 10,24; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); li 4,9; addi 3,1,16; mullw 21,31,29; stw 0,0x0(11); li 23,24; lwz 0,0x4(9); addi 20,28,8; stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); bl _s8032A804_4; lhz 0,0x0(28); mr 8,3; lbz 9,0x2(28); mr 3,27; sth 0,0x38(1); mr 4,26; stb 9,0x2(24); mr 5,31; li 9,3; stw 24,0x8(1); mr 6,29; addi 7,1,16; li 10,3; bl _s8032A804_5; lis 9,-32702; mr 11,19; addi 9,9,4948; 1:; lwz 0,0x0(9); addic. 23,23,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 1b; lwz 0,0x0(9); addi 3,1,16; li 4,9; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); bl _s8032A804_6; lhz 0,0x0(28); mr 8,3; lbz 11,0x2(28); addi 7,1,16; sth 0,0x40(1); li 9,3; stw 22,0x8(1); li 10,3; stb 11,0x2(22); mr 3,27; mr 4,30; mr 5,31; mr 6,29; bl _s8032A804_7; mr 6,21; mr 5,30; mr 4,26; mr 3,25; bl _s8032A804_8; bl _s8032A804_9; mr 4,30; bl _s8032A804_10; bl _s8032A804_11; mr 4,26; bl _s8032A804_12; lwz 0,-26580(13); cmpwi 0,0; beq 2f; mr 3,25; mr 4,31; mr 5,29; bl _s8032A804_13; mr 3,27; mr 4,31; mr 5,29; bl _s8032A804_14; 2:; mr 4,27; mr 7,20; mr 3,25; mr 5,31; mr 6,29; bl _s8032A804_15; lwz 0,-26580(13); cmpwi 0,0; beq 3f; mr 3,25; mr 4,31; mr 5,29; bl _s8032A804_16; 3:; stw 23,-26580(13); lwz 0,0x84(1); mtspr 8,0; lmw 19,0x4c(1); addi 1,1,128"
extern "C" void _s8032A804_0();
extern "C" void _s8032A804_1();
extern "C" void _s8032A804_2();
extern "C" void _s8032A804_3();
extern "C" void _s8032A804_4();
extern "C" void _s8032A804_5();
extern "C" void _s8032A804_6();
extern "C" void _s8032A804_7();
extern "C" void _s8032A804_8();
extern "C" void _s8032A804_9();
extern "C" void _s8032A804_10();
extern "C" void _s8032A804_11();
extern "C" void _s8032A804_12();
extern "C" void _s8032A804_13();
extern "C" void _s8032A804_14();
extern "C" void _s8032A804_15();
extern "C" void _s8032A804_16();
extern "C" void f_8032A804() {}
