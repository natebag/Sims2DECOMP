// 0x800A227C BString2::append(wchar_t, (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 28,5; sth 4,0x8(1); bl _s800A227C_0; not 0,28; cmplw 3,0; blt 0f; bl _s800A227C_1; 0:; cmpwi 28,0; beq 7f; mr 3,31; bl _s800A227C_2; cmplwi 3,1; bgt 1f; mr 3,31; bl _s800A227C_3; mr 30,3; mr 3,31; bl _s800A227C_4; add 3,3,28; addi 3,3,1; cmplw 30,3; bge 4f; 1:; bl _s800A227C_5; li 4,16; li 5,0; bl _s800A227C_6; mr 27,3; mr 3,31; bl _s800A227C_7; cmpwi 3,0; beq 2f; lwz 9,0x0(31); lwz 29,0x0(9); b 3f; 2:; li 29,0; 3:; mr 3,31; bl _s800A227C_8; mr 30,3; mr 3,31; bl _s800A227C_9; add 6,3,28; mr 5,30; mr 4,29; mr 3,27; bl _s800A227C_10; mr 30,3; mr 3,31; bl _s800A227C_11; stw 30,0x0(31); 4:; li 29,0; add 27,28,28; cmplw 29,28; bge 6f; 5:; mr 3,31; bl _s800A227C_12; mr 30,3; mr 3,31; bl _s800A227C_13; add 9,29,29; rlwinm 3,3,1,0,30; lhz 0,0x8(1); add 3,3,30; addi 29,29,1; sthx 0,9,3; cmplw 29,28; blt 5b; 6:; mr 3,31; bl _s800A227C_14; mr 29,3; mr 3,31; bl _s800A227C_15; mr 30,3; bl _s800A227C_16; add 30,30,30; add 30,30,29; sthx 3,27,30; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,28; stw 0,0x4(9); 7:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800A227C_0();
extern "C" void _s800A227C_1();
extern "C" void _s800A227C_2();
extern "C" void _s800A227C_3();
extern "C" void _s800A227C_4();
extern "C" void _s800A227C_5();
extern "C" void _s800A227C_6();
extern "C" void _s800A227C_7();
extern "C" void _s800A227C_8();
extern "C" void _s800A227C_9();
extern "C" void _s800A227C_10();
extern "C" void _s800A227C_11();
extern "C" void _s800A227C_12();
extern "C" void _s800A227C_13();
extern "C" void _s800A227C_14();
extern "C" void _s800A227C_15();
extern "C" void _s800A227C_16();
extern "C" void f_800A227C() {}
