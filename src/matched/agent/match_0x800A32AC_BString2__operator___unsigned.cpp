// 0x800A32AC BString2::operator[](unsigned (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 28,4; bl _s800A32AC_0; cmplw 28,3; blt 0f; bl _s800A32AC_1; 0:; mr 3,31; bl _s800A32AC_2; cmplwi 3,1; ble 3f; bl _s800A32AC_3; li 4,16; li 5,0; bl _s800A32AC_4; mr 27,3; mr 3,31; bl _s800A32AC_5; cmpwi 3,0; beq 1f; lwz 9,0x0(31); lwz 29,0x0(9); b 2f; 1:; li 29,0; 2:; mr 3,31; bl _s800A32AC_6; mr 30,3; mr 3,31; bl _s800A32AC_7; mr 6,3; mr 5,30; mr 4,29; mr 3,27; bl _s800A32AC_8; mr 30,3; mr 3,31; bl _s800A32AC_9; stw 30,0x0(31); 3:; mr 3,31; bl _s800A32AC_10; add 0,28,28; add 3,3,0; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800A32AC_0();
extern "C" void _s800A32AC_1();
extern "C" void _s800A32AC_2();
extern "C" void _s800A32AC_3();
extern "C" void _s800A32AC_4();
extern "C" void _s800A32AC_5();
extern "C" void _s800A32AC_6();
extern "C" void _s800A32AC_7();
extern "C" void _s800A32AC_8();
extern "C" void _s800A32AC_9();
extern "C" void _s800A32AC_10();
extern "C" void f_800A32AC() {}
