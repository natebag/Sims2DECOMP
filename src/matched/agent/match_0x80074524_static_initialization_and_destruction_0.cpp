// 0x80074524 __static_initialization_and_destruction_0 (1504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; lis 30,-32696; li 4,0; addi 30,30,22168; li 5,10; mr 3,30; li 29,0; li 26,2; crxor 6,6,6; bl _s80074524_0; addi 9,30,2; stb 26,0x1(30); sth 29,0x2(30); li 28,64; li 25,32; addi 30,30,10; sth 28,0x6(9); mr 3,30; li 4,0; li 5,10; sth 25,0x2(9); li 24,1; sth 25,0x4(9); li 27,128; crxor 6,6,6; bl _s80074524_1; li 22,3; addi 9,30,2; stb 24,0x0(30); sth 29,0x2(30); li 4,0; addi 30,30,10; sth 28,0x6(9); mr 3,30; li 5,10; sth 29,0x2(9); li 23,10; sth 28,0x4(9); li 21,2; crxor 6,6,6; bl _s80074524_2; addi 9,30,2; stb 26,0x0(30); stb 26,0x1(30); li 4,0; sth 28,0x2(30); li 5,10; addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_3; addi 9,30,2; stb 22,0x0(30); stb 26,0x1(30); li 4,0; sth 28,0x2(30); li 5,10; addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_4; li 0,4; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 28,0x2(30); addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_5; li 0,5; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 28,0x2(30); addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_6; li 0,6; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 28,0x2(30); addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_7; li 0,7; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 24,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_8; li 0,8; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 28,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_9; li 0,9; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 24,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_10; addi 9,30,2; stb 23,0x0(30); stb 24,0x1(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_11; li 0,11; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 28,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_12; li 0,12; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 24,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_13; li 0,13; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 24,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_14; li 0,14; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 28,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_15; li 0,15; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 22,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_16; li 0,16; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 28,0x2(30); li 5,10; addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_17; li 0,17; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 28,0x2(30); li 5,10; addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 27,0x4(9); crxor 6,6,6; bl _s80074524_18; li 0,18; addi 9,30,2; stb 0,0x0(30); li 4,0; sth 29,0x2(30); li 5,10; addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 29,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s80074524_19; li 0,19; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 27,0x6(9); mr 3,30; sth 28,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s80074524_20; li 0,20; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 25,0x2(30); addi 30,30,10; sth 28,0x6(9); mr 3,30; sth 25,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s80074524_21; li 0,21; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 29,0x2(30); addi 30,30,10; sth 25,0x6(9); mr 3,30; sth 29,0x2(9); sth 25,0x4(9); crxor 6,6,6; bl _s80074524_22; li 0,22; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 25,0x2(30); addi 30,30,10; sth 25,0x6(9); mr 3,30; sth 29,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s80074524_23; li 0,23; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 21,0x1(30); li 5,10; sth 25,0x2(30); addi 30,30,10; sth 25,0x6(9); mr 3,30; sth 29,0x2(9); sth 28,0x4(9); crxor 6,6,6; bl _s80074524_24; li 0,24; addi 9,30,2; stb 0,0x0(30); li 4,0; stb 26,0x1(30); li 5,10; sth 25,0x2(30); addi 30,30,10; sth 25,0x6(9); sth 29,0x2(9); mr 3,30; sth 28,0x4(9); crxor 6,6,6; bl _s80074524_25; li 0,25; stb 26,0x1(30); stb 0,0x0(30); addi 9,30,2; sth 28,0x2(30); sth 27,0x6(9); sth 28,0x2(9); sth 27,0x4(9); 0:; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"
extern "C" void _s80074524_0();
extern "C" void _s80074524_1();
extern "C" void _s80074524_2();
extern "C" void _s80074524_3();
extern "C" void _s80074524_4();
extern "C" void _s80074524_5();
extern "C" void _s80074524_6();
extern "C" void _s80074524_7();
extern "C" void _s80074524_8();
extern "C" void _s80074524_9();
extern "C" void _s80074524_10();
extern "C" void _s80074524_11();
extern "C" void _s80074524_12();
extern "C" void _s80074524_13();
extern "C" void _s80074524_14();
extern "C" void _s80074524_15();
extern "C" void _s80074524_16();
extern "C" void _s80074524_17();
extern "C" void _s80074524_18();
extern "C" void _s80074524_19();
extern "C" void _s80074524_20();
extern "C" void _s80074524_21();
extern "C" void _s80074524_22();
extern "C" void _s80074524_23();
extern "C" void _s80074524_24();
extern "C" void _s80074524_25();
extern "C" void f_80074524() {}
