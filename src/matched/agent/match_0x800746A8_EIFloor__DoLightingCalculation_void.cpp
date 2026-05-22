// 0x800746A8 EIFloor::DoLightingCalculation(void) (1160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_0; li 0,6; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 28,0x2(30); addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_1; li 0,7; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 24,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_2; li 0,8; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 28,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_3; li 0,9; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 24,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_4; addi 9,30,2; stb 23,0x0(30); stb 24,0x1(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_5; li 0,11; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 28,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_6; li 0,12; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 24,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_7; li 0,13; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 24,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_8; li 0,14; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 28,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_9; li 0,15; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 22,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_10; li 0,16; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 28,0x2(30); li 5,10; addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_11; li 0,17; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 28,0x2(30); li 5,10; addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s800746A8_12; li 0,18; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s800746A8_13; li 0,19; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 28,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s800746A8_14; li 0,20; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 25,0x2(30); addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 25,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s800746A8_15; li 0,21; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 25,0x6(9); mr 3,30; sth 29,0x2(9); sth 25,0x4(9); crxor 6,6,6; bl _s800746A8_16; li 0,22; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 25,0x2(30); addi 30,30,10; sth 25,0x6(9); mr 3,30; sth 29,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s800746A8_17; li 0,23; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 21,0x1(30); li 5,10; sth 25,0x2(30); addi 30,30,10; sth 25,0x6(9); mr 3,30; sth 29,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s800746A8_18; li 0,24; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 25,0x2(30); addi 30,30,10; sth 25,0x6(9); sth 29,0x2(9); mr 3,30; sth 28,0x4(9); crxor 6,6,6; bl _s800746A8_19; li 0,25; stb 26,0x1(30); stb 0,0x0(30); addi 9,30,2; sth 28,0x2(30); sth 27,0x6(9); sth 28,0x2(9); sth 27,0x4(9); lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,0; li 3,1; ori 4,4,65535; bl _s800746A8_20; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800746A8_0();
extern "C" void _s800746A8_1();
extern "C" void _s800746A8_2();
extern "C" void _s800746A8_3();
extern "C" void _s800746A8_4();
extern "C" void _s800746A8_5();
extern "C" void _s800746A8_6();
extern "C" void _s800746A8_7();
extern "C" void _s800746A8_8();
extern "C" void _s800746A8_9();
extern "C" void _s800746A8_10();
extern "C" void _s800746A8_11();
extern "C" void _s800746A8_12();
extern "C" void _s800746A8_13();
extern "C" void _s800746A8_14();
extern "C" void _s800746A8_15();
extern "C" void _s800746A8_16();
extern "C" void _s800746A8_17();
extern "C" void _s800746A8_18();
extern "C" void _s800746A8_19();
extern "C" void _s800746A8_20();
extern "C" void f_800746A8() {}
