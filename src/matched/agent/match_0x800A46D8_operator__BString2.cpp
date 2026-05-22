// 0x800A46D8 operator+(BString2 (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 29,4; mr 31,3; sth 5,0x10(1); mr 3,29; bl _s800A46D8_0; cmpwi 3,0; beq 0f; lwz 9,0x0(29); lwz 30,0x0(9); b 1f; 0:; li 30,0; 1:; mr 3,29; bl _s800A46D8_1; mr 5,3; mr 4,30; addi 3,1,8; li 6,1; bl _s800A46D8_2; addi 3,1,8; bl _s800A46D8_3; mr 30,3; mr 3,29; bl _s800A46D8_4; lhz 0,0x10(1); rlwinm 9,3,1,0,30; addi 3,1,8; sthx 0,9,30; bl _s800A46D8_5; mr 11,3; lwz 9,0x0(11); addi 3,1,8; addi 9,9,1; stw 9,0x0(11); bl _s800A46D8_6; mr 29,3; addi 3,1,8; bl _s800A46D8_7; mr 30,3; bl _s800A46D8_8; add 30,30,30; addi 4,1,8; sthx 3,30,29; li 5,0; li 6,-1; mr 3,31; bl _s800A46D8_9; addi 3,1,8; li 4,2; bl _s800A46D8_10; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s800A46D8_0();
extern "C" void _s800A46D8_1();
extern "C" void _s800A46D8_2();
extern "C" void _s800A46D8_3();
extern "C" void _s800A46D8_4();
extern "C" void _s800A46D8_5();
extern "C" void _s800A46D8_6();
extern "C" void _s800A46D8_7();
extern "C" void _s800A46D8_8();
extern "C" void _s800A46D8_9();
extern "C" void _s800A46D8_10();
extern "C" void f_800A46D8() {}
