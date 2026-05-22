// 0x80186C48 HUDTarget::AttachControllers(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 4,0; lwz 3,-26524(13); lis 29,-32705; bl _s80186C48_0; mr 30,3; addi 3,31,264; bl _s80186C48_1; li 6,100; li 4,0; addi 5,29,-20036; mr 3,30; bl _s80186C48_2; mr 0,3; li 5,34; mr 4,0; stw 0,0xf8(31); mr 3,30; bl _s80186C48_3; lwz 4,0xf8(31); mr 3,30; li 5,35; bl _s80186C48_4; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 0f; lwz 3,-26524(13); li 4,1; bl _s80186C48_5; mr 30,3; addi 3,31,1060; bl _s80186C48_6; addi 5,29,-20036; li 4,0; li 6,100; mr 3,30; bl _s80186C48_7; mr 0,3; li 5,34; mr 4,0; mr 3,30; stw 0,0xfc(31); bl _s80186C48_8; lwz 4,0xfc(31); mr 3,30; li 5,35; bl _s80186C48_9; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80186C48_0();
extern "C" void _s80186C48_1();
extern "C" void _s80186C48_2();
extern "C" void _s80186C48_3();
extern "C" void _s80186C48_4();
extern "C" void _s80186C48_5();
extern "C" void _s80186C48_6();
extern "C" void _s80186C48_7();
extern "C" void _s80186C48_8();
extern "C" void _s80186C48_9();
extern "C" void f_80186C48() {}
