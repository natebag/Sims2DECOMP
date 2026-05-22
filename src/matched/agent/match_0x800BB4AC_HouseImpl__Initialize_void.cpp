// 0x800BB4AC HouseImpl::Initialize(void) (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; bl _s800BB4AC_0; bl _s800BB4AC_1; stw 3,-21496(13); bl _s800BB4AC_2; lwz 11,-21496(13); stw 3,-21484(13); lwz 9,0x0(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21484(13); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21476(13); li 4,0; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; stw 3,0x14(31); li 3,48; bl _s800BB4AC_3; bl _s800BB4AC_4; stw 3,-21472(13); li 3,16; bl _s800BB4AC_5; bl _s800BB4AC_6; mr 0,3; li 4,8; stw 0,0x1c(31); bl _s800BB4AC_7; li 3,16; bl _s800BB4AC_8; bl _s800BB4AC_9; mr 0,3; li 4,8; stw 0,0x20(31); bl _s800BB4AC_10; li 0,0; stw 0,0x8(1); bl _s800BB4AC_11; lwz 0,0x8(1); mr 30,3; cmpw 30,0; beq 2f; cmpwi 30,0; beq 0f; lwz 9,0x0(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; 0:; lwz 11,0x8(1); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 1:; stw 30,0x8(1); 2:; lwz 3,0x8(1); li 5,505; lwz 4,-31848(13); lwz 9,0x0(3); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 3f; lwz 11,0x8(1); li 5,-1; li 4,1; lwz 30,0x1c(31); lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,30; bl _s800BB4AC_12; lwz 11,0x8(1); li 4,2; li 5,-1; lwz 30,0x20(31); lwz 9,0x0(11); lha 3,0x80(9); lwz 0,0x84(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,30; bl _s800BB4AC_13; 3:; lwz 11,0x8(1); cmpwi 11,0; beq 4f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800BB4AC_0();
extern "C" void _s800BB4AC_1();
extern "C" void _s800BB4AC_2();
extern "C" void _s800BB4AC_3();
extern "C" void _s800BB4AC_4();
extern "C" void _s800BB4AC_5();
extern "C" void _s800BB4AC_6();
extern "C" void _s800BB4AC_7();
extern "C" void _s800BB4AC_8();
extern "C" void _s800BB4AC_9();
extern "C" void _s800BB4AC_10();
extern "C" void _s800BB4AC_11();
extern "C" void _s800BB4AC_12();
extern "C" void _s800BB4AC_13();
extern "C" void f_800BB4AC() {}
