// 0x800A44F4 operator+(wchar_t, (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,5; mr 27,3; sth 4,0x8(1); mr 3,31; bl _s800A44F4_0; addi 0,1,16; mr 6,3; mr 28,0; addi 4,1,8; li 5,1; mr 3,0; bl _s800A44F4_1; mr 3,31; bl _s800A44F4_2; cmpwi 3,0; beq 2f; mr 3,28; bl _s800A44F4_3; mr 29,3; mr 3,31; bl _s800A44F4_4; cmpwi 3,0; beq 0f; lwz 9,0x0(31); lwz 30,0x0(9); b 1f; 0:; li 30,0; 1:; mr 3,31; bl _s800A44F4_5; addi 5,3,1; mr 4,30; addi 3,29,2; rlwinm 5,5,1,0,30; bl _s800A44F4_6; 2:; mr 3,28; bl _s800A44F4_7; mr 30,3; mr 3,31; bl _s800A44F4_8; lwz 0,0x0(30); mr 4,28; li 5,0; li 6,-1; add 0,0,3; stw 0,0x0(30); mr 3,27; bl _s800A44F4_9; mr 3,28; li 4,2; bl _s800A44F4_10; mr 3,27; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s800A44F4_0();
extern "C" void _s800A44F4_1();
extern "C" void _s800A44F4_2();
extern "C" void _s800A44F4_3();
extern "C" void _s800A44F4_4();
extern "C" void _s800A44F4_5();
extern "C" void _s800A44F4_6();
extern "C" void _s800A44F4_7();
extern "C" void _s800A44F4_8();
extern "C" void _s800A44F4_9();
extern "C" void _s800A44F4_10();
extern "C" void f_800A44F4() {}
