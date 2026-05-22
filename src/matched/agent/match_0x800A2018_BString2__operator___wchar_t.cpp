// 0x800A2018 BString2::operator+=(wchar_t) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; sth 4,0x8(1); bl _s800A2018_0; li 0,-3; cmplw 3,0; ble 0f; bl _s800A2018_1; 0:; mr 3,31; bl _s800A2018_2; cmpwi 3,1; bne 1f; mr 3,31; bl _s800A2018_3; mr 30,3; mr 3,31; bl _s800A2018_4; addi 3,3,1; cmplw 30,3; bgt 4f; 1:; bl _s800A2018_5; li 4,16; li 5,0; bl _s800A2018_6; mr 28,3; mr 3,31; bl _s800A2018_7; cmpwi 3,0; beq 2f; lwz 9,0x0(31); lwz 29,0x0(9); b 3f; 2:; li 29,0; 3:; mr 3,31; bl _s800A2018_8; mr 30,3; mr 3,31; bl _s800A2018_9; addi 6,3,1; mr 5,30; mr 4,29; mr 3,28; bl _s800A2018_10; mr 30,3; mr 3,31; bl _s800A2018_11; stw 30,0x0(31); 4:; mr 3,31; bl _s800A2018_12; mr 30,3; mr 3,31; bl _s800A2018_13; lhz 0,0x8(1); rlwinm 9,3,1,0,30; mr 3,31; sthx 0,9,30; bl _s800A2018_14; mr 29,3; mr 3,31; bl _s800A2018_15; mr 30,3; bl _s800A2018_16; add 30,30,30; add 30,30,29; sth 3,0x2(30); mr 3,31; lwz 11,0x0(31); lwz 9,0x4(11); addi 9,9,1; stw 9,0x4(11); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800A2018_0();
extern "C" void _s800A2018_1();
extern "C" void _s800A2018_2();
extern "C" void _s800A2018_3();
extern "C" void _s800A2018_4();
extern "C" void _s800A2018_5();
extern "C" void _s800A2018_6();
extern "C" void _s800A2018_7();
extern "C" void _s800A2018_8();
extern "C" void _s800A2018_9();
extern "C" void _s800A2018_10();
extern "C" void _s800A2018_11();
extern "C" void _s800A2018_12();
extern "C" void _s800A2018_13();
extern "C" void _s800A2018_14();
extern "C" void _s800A2018_15();
extern "C" void _s800A2018_16();
extern "C" void f_800A2018() {}
