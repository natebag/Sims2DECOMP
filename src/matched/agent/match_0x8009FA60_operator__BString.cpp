// 0x8009FA60 operator+(BString (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 31,4; mr 26,3; mr 27,5; mr 3,31; bl _s8009FA60_0; mr 29,3; mr 3,31; bl _s8009FA60_1; mr 30,3; mr 3,27; bl _s8009FA60_2; mr 6,3; mr 4,29; mr 5,30; addi 3,1,8; bl _s8009FA60_3; mr 3,27; bl _s8009FA60_4; cmpwi 3,0; beq 0f; addi 3,1,8; bl _s8009FA60_5; mr 28,3; mr 3,31; bl _s8009FA60_6; mr 29,3; mr 3,27; bl _s8009FA60_7; mr 30,3; mr 3,27; bl _s8009FA60_8; addi 5,3,1; mr 4,30; add 3,28,29; bl _s8009FA60_9; 0:; addi 3,1,8; bl _s8009FA60_10; mr 30,3; mr 3,27; bl _s8009FA60_11; lwz 0,0x0(30); addi 4,1,8; li 5,0; li 6,-1; add 0,0,3; stw 0,0x0(30); mr 3,26; bl _s8009FA60_12; addi 3,1,8; li 4,2; bl _s8009FA60_13; mr 3,26; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s8009FA60_0();
extern "C" void _s8009FA60_1();
extern "C" void _s8009FA60_2();
extern "C" void _s8009FA60_3();
extern "C" void _s8009FA60_4();
extern "C" void _s8009FA60_5();
extern "C" void _s8009FA60_6();
extern "C" void _s8009FA60_7();
extern "C" void _s8009FA60_8();
extern "C" void _s8009FA60_9();
extern "C" void _s8009FA60_10();
extern "C" void _s8009FA60_11();
extern "C" void _s8009FA60_12();
extern "C" void _s8009FA60_13();
extern "C" void f_8009FA60() {}
