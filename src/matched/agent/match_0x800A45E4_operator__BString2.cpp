// 0x800A45E4 operator+(BString2 (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,3; mr 31,4; mr. 28,5; beq 0f; mr 3,28; bl _s800A45E4_0; mr 29,3; b 1f; 0:; li 29,0; 1:; mr 3,31; bl _s800A45E4_1; cmpwi 3,0; beq 2f; lwz 9,0x0(31); lwz 30,0x0(9); b 3f; 2:; li 30,0; 3:; mr 3,31; bl _s800A45E4_2; mr 5,3; mr 4,30; addi 3,1,8; mr 6,29; bl _s800A45E4_3; cmpwi 29,0; beq 4f; addi 3,1,8; bl _s800A45E4_4; mr 30,3; mr 3,31; bl _s800A45E4_5; rlwinm 3,3,1,0,30; addi 5,29,1; add 3,3,30; mr 4,28; rlwinm 5,5,1,0,30; bl _s800A45E4_6; 4:; addi 3,1,8; bl _s800A45E4_7; mr 9,3; addi 4,1,8; lwz 0,0x0(9); li 5,0; li 6,-1; mr 3,27; add 0,0,29; stw 0,0x0(9); bl _s800A45E4_8; addi 3,1,8; li 4,2; bl _s800A45E4_9; mr 3,27; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800A45E4_0();
extern "C" void _s800A45E4_1();
extern "C" void _s800A45E4_2();
extern "C" void _s800A45E4_3();
extern "C" void _s800A45E4_4();
extern "C" void _s800A45E4_5();
extern "C" void _s800A45E4_6();
extern "C" void _s800A45E4_7();
extern "C" void _s800A45E4_8();
extern "C" void _s800A45E4_9();
extern "C" void f_800A45E4() {}
