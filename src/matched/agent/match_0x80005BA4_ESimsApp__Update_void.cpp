// 0x80005BA4 ESimsApp::Update(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x48c(31); cmpwi 0,0; beq 0f; lwz 3,-26524(13); li 4,0; bl _s80005BA4_0; cmpwi 3,0; bne 0f; lis 30,-32697; li 4,0; addi 3,30,24012; bl _s80005BA4_1; cmpwi 3,-1; beq 0f; addi 9,30,24012; li 0,-1; lwz 11,0xb4(9); stw 0,0x3ac(11); 0:; lwz 0,0x490(31); cmpwi 0,0; beq 1f; lwz 3,-26524(13); li 4,1; bl _s80005BA4_2; cmpwi 3,0; bne 1f; lis 30,-32697; li 4,1; addi 3,30,24012; bl _s80005BA4_3; cmpwi 3,-1; beq 1f; addi 10,30,24012; li 0,-1; lwz 11,0xb4(10); li 8,1; stw 0,0x3ac(11); lwz 9,0xb4(10); stw 8,0x3a8(9); 1:; bl _s80005BA4_4; mr 3,31; bl _s80005BA4_5; mr 3,31; bl _s80005BA4_6; mr 3,31; bl _s80005BA4_7; mr 3,31; bl _s80005BA4_8; lis 9,-32707; mr 3,31; lfs f1,-19652(9); bl _s80005BA4_9; mr 3,31; bl _s80005BA4_10; mr 3,31; bl _s80005BA4_11; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80005BA4_0();
extern "C" void _s80005BA4_1();
extern "C" void _s80005BA4_2();
extern "C" void _s80005BA4_3();
extern "C" void _s80005BA4_4();
extern "C" void _s80005BA4_5();
extern "C" void _s80005BA4_6();
extern "C" void _s80005BA4_7();
extern "C" void _s80005BA4_8();
extern "C" void _s80005BA4_9();
extern "C" void _s80005BA4_10();
extern "C" void _s80005BA4_11();
extern "C" void f_80005BA4() {}
