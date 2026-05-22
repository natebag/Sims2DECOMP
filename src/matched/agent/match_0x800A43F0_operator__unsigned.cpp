// 0x800A43F0 operator+(unsigned (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,3; mr 29,5; mr. 31,4; beq 0f; mr 3,31; bl _s800A43F0_0; mr 30,3; b 1f; 0:; li 30,0; 1:; mr 3,29; bl _s800A43F0_1; mr 6,3; mr 4,31; mr 5,30; addi 3,1,8; bl _s800A43F0_2; mr 3,29; bl _s800A43F0_3; cmpwi 3,0; beq 4f; addi 3,1,8; bl _s800A43F0_4; mr 28,3; mr 3,29; bl _s800A43F0_5; cmpwi 3,0; beq 2f; lwz 9,0x0(29); lwz 31,0x0(9); b 3f; 2:; li 31,0; 3:; mr 3,29; bl _s800A43F0_6; addi 5,3,1; mr 4,31; add 3,30,30; rlwinm 5,5,1,0,30; add 3,3,28; bl _s800A43F0_7; 4:; addi 3,1,8; bl _s800A43F0_8; mr 30,3; mr 3,29; bl _s800A43F0_9; lwz 0,0x0(30); addi 4,1,8; li 5,0; li 6,-1; add 0,0,3; stw 0,0x0(30); mr 3,27; bl _s800A43F0_10; addi 3,1,8; li 4,2; bl _s800A43F0_11; mr 3,27; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800A43F0_0();
extern "C" void _s800A43F0_1();
extern "C" void _s800A43F0_2();
extern "C" void _s800A43F0_3();
extern "C" void _s800A43F0_4();
extern "C" void _s800A43F0_5();
extern "C" void _s800A43F0_6();
extern "C" void _s800A43F0_7();
extern "C" void _s800A43F0_8();
extern "C" void _s800A43F0_9();
extern "C" void _s800A43F0_10();
extern "C" void _s800A43F0_11();
extern "C" void f_800A43F0() {}
