// 0x8033D5B4 ENgcRenderer::InitVideo(int (692 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 23,0x14(1); stw 0,0x3c(1); lwz 0,-18460(13); mr 31,3; mr 25,4; mr 24,5; cmpwi 0,1; bne 0f; addi 30,31,868; lis 3,-32698; addi 3,3,-24484; mr 4,30; li 5,0; li 6,8; bl _s8033D5B4_0; b 1f; 0:; addi 30,31,868; lis 3,-32698; addi 3,3,-25504; mr 4,30; li 5,0; li 6,16; bl _s8033D5B4_1; 1:; mr 27,30; addi 9,13,-18440; lwz 0,0x364(31); lwz 11,0x0(9); addi 10,31,918; lbz 8,0x6(9); xori 26,0,1; lhz 7,0x4(9); addi 23,31,836; stw 11,0x396(31); mr 29,23; stb 8,0x6(10); addi 28,31,840; sth 7,0x4(10); rlwinm 26,26,0,31,31; lhz 0,0x368(31); stw 0,0x0(25); lhz 11,0x36a(31); stw 11,0x0(24); lhz 9,0x368(31); lhz 0,0x36c(31); addi 9,9,15; rlwinm 9,9,1,15,26; mullw 0,9,0; stw 9,0x354(31); stw 0,0x350(31); 2:; bl _s8033D5B4_2; lwz 4,0x350(31); li 5,32; li 6,0; li 7,0; bl _s8033D5B4_3; mr 30,3; stw 30,0x0(29); addi 29,29,4; lwz 4,0x350(31); bl _s8033D5B4_4; lwz 4,0x350(31); mr 3,30; bl _s8033D5B4_5; cmpw 29,28; ble 2b; li 4,256; li 5,4; li 6,0; li 7,0; li 3,256; li 29,0; bl _s8033D5B4_6; mr 30,3; bl _s8033D5B4_7; mr 4,30; li 5,32; li 6,0; li 7,0; bl _s8033D5B4_8; lhz 0,0x368(31); li 5,4; lhz 4,0x36a(31); li 6,0; stw 3,0x464c(31); li 7,0; rlwinm 3,0,31,1,31; rlwinm 4,4,31,1,31; bl _s8033D5B4_9; mr 30,3; bl _s8033D5B4_10; li 6,0; li 7,0; li 5,32; mr 4,30; bl _s8033D5B4_11; stw 3,0x4650(31); stw 29,0x340(31); mr 3,31; lwzx 0,23,29; stw 0,0x34c(31); bl _s8033D5B4_12; bl _s8033D5B4_13; mr 3,27; bl _s8033D5B4_14; li 3,0; bl _s8033D5B4_15; mr 4,27; mr 3,31; bl _s8033D5B4_16; li 3,1; bl _s8033D5B4_17; li 3,1; bl _s8033D5B4_18; li 5,1; li 3,1; li 4,7; bl _s8033D5B4_19; lwz 0,0x3ac(31); addi 3,1,8; lwz 4,0x3b0(31); stw 0,0x8(1); bl _s8033D5B4_20; lwz 3,0x34c(31); li 4,1; bl _s8033D5B4_21; lwz 3,0x34c(31); li 4,0; bl _s8033D5B4_22; bl _s8033D5B4_23; li 3,1; li 4,3; li 5,1; bl _s8033D5B4_24; mr 3,31; bl _s8033D5B4_25; cmpwi 26,0; bne 3f; bl _s8033D5B4_26; 3:; lis 3,-32716; addi 3,3,-13100; bl _s8033D5B4_27; lis 3,-32716; addi 3,3,-12820; bl _s8033D5B4_28; li 3,35; li 4,22; bl _s8033D5B4_29; lis 11,-13311; li 8,97; lis 0,9218; stb 8,-32768(11); ori 0,0,49156; lis 9,8960; stw 0,-32768(11); ori 9,9,32; stb 8,-32768(11); li 10,16; stw 9,-32768(11); li 8,4102; stb 10,-32768(11); lis 0,8; sth 29,-32768(11); ori 0,0,17408; sth 8,-32768(11); li 3,1; stw 0,-32768(11); lwz 0,0x3c(1); mtspr 8,0; lmw 23,0x14(1); addi 1,1,56"
extern "C" void _s8033D5B4_0();
extern "C" void _s8033D5B4_1();
extern "C" void _s8033D5B4_2();
extern "C" void _s8033D5B4_3();
extern "C" void _s8033D5B4_4();
extern "C" void _s8033D5B4_5();
extern "C" void _s8033D5B4_6();
extern "C" void _s8033D5B4_7();
extern "C" void _s8033D5B4_8();
extern "C" void _s8033D5B4_9();
extern "C" void _s8033D5B4_10();
extern "C" void _s8033D5B4_11();
extern "C" void _s8033D5B4_12();
extern "C" void _s8033D5B4_13();
extern "C" void _s8033D5B4_14();
extern "C" void _s8033D5B4_15();
extern "C" void _s8033D5B4_16();
extern "C" void _s8033D5B4_17();
extern "C" void _s8033D5B4_18();
extern "C" void _s8033D5B4_19();
extern "C" void _s8033D5B4_20();
extern "C" void _s8033D5B4_21();
extern "C" void _s8033D5B4_22();
extern "C" void _s8033D5B4_23();
extern "C" void _s8033D5B4_24();
extern "C" void _s8033D5B4_25();
extern "C" void _s8033D5B4_26();
extern "C" void _s8033D5B4_27();
extern "C" void _s8033D5B4_28();
extern "C" void _s8033D5B4_29();
extern "C" void f_8033D5B4() {}
