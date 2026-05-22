// 0x8009FD10 operator+(BString (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,3; mr 29,4; mr. 28,5; beq 0f; mr 3,28; bl _s8009FD10_0; mr 31,3; b 1f; 0:; li 31,0; 1:; mr 3,29; bl _s8009FD10_1; mr 30,3; mr 3,29; bl _s8009FD10_2; mr 5,3; mr 4,30; addi 3,1,8; mr 6,31; bl _s8009FD10_3; cmpwi 31,0; beq 2f; addi 3,1,8; bl _s8009FD10_4; mr 30,3; mr 3,29; bl _s8009FD10_5; add 3,30,3; mr 4,28; addi 5,31,1; bl _s8009FD10_6; 2:; addi 3,1,8; bl _s8009FD10_7; mr 9,3; addi 4,1,8; lwz 0,0x0(9); li 5,0; li 6,-1; mr 3,27; add 0,0,31; stw 0,0x0(9); bl _s8009FD10_8; addi 3,1,8; li 4,2; bl _s8009FD10_9; mr 3,27; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8009FD10_0();
extern "C" void _s8009FD10_1();
extern "C" void _s8009FD10_2();
extern "C" void _s8009FD10_3();
extern "C" void _s8009FD10_4();
extern "C" void _s8009FD10_5();
extern "C" void _s8009FD10_6();
extern "C" void _s8009FD10_7();
extern "C" void _s8009FD10_8();
extern "C" void _s8009FD10_9();
extern "C" void f_8009FD10() {}
