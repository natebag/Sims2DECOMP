// 0x80186D2C HUDTarget::ReleaseControllers(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0xf8(31); cmpwi 0,0; beq 0f; lwz 30,-26524(13); li 4,0; mr 3,30; bl _s80186D2C_0; mr 4,3; mr 3,30; bl _s80186D2C_1; lwz 4,0xf8(31); bl _s80186D2C_2; li 0,0; stw 0,0xf8(31); 0:; lwz 0,0xfc(31); cmpwi 0,0; beq 1f; lwz 30,-26524(13); li 4,1; mr 3,30; bl _s80186D2C_3; mr 4,3; mr 3,30; bl _s80186D2C_4; lwz 4,0xfc(31); bl _s80186D2C_5; li 0,0; stw 0,0xfc(31); 1:; addi 3,31,264; bl _s80186D2C_6; addi 3,31,1060; bl _s80186D2C_7; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80186D2C_0();
extern "C" void _s80186D2C_1();
extern "C" void _s80186D2C_2();
extern "C" void _s80186D2C_3();
extern "C" void _s80186D2C_4();
extern "C" void _s80186D2C_5();
extern "C" void _s80186D2C_6();
extern "C" void _s80186D2C_7();
extern "C" void f_80186D2C() {}
