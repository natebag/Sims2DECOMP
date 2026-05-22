// 0x80056BF0 CLoadingScreen::~CLoadingScreen(void) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lwz 3,0x358(31); addi 9,9,-14056; mr 30,4; stw 9,0x390(31); cmpwi 3,0; beq 0f; bl _s80056BF0_0; li 0,0; stw 0,0x358(31); 0:; lwz 3,0x35c(31); cmpwi 3,0; beq 1f; bl _s80056BF0_1; li 0,0; stw 0,0x35c(31); 1:; lwz 3,0x360(31); cmpwi 3,0; beq 2f; bl _s80056BF0_2; li 0,0; stw 0,0x360(31); 2:; lwz 3,0x364(31); cmpwi 3,0; beq 3f; li 4,3; bl _s80056BF0_3; li 0,0; stw 0,0x364(31); 3:; lis 9,-32697; lwz 3,0x5ee4(9); cmpwi 3,0; beq 4f; bl _s80056BF0_4; mr. 3,3; beq 4f; bl _s80056BF0_5; mr. 3,3; beq 4f; lwz 0,0xc(3); cmpwi 0,1; beq 4f; li 4,0; bl _s80056BF0_6; 4:; mr 3,31; li 4,0; bl _s80056BF0_7; andi. 0,30,1; beq 5f; bl _s80056BF0_8; mr 4,31; bl _s80056BF0_9; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80056BF0_0();
extern "C" void _s80056BF0_1();
extern "C" void _s80056BF0_2();
extern "C" void _s80056BF0_3();
extern "C" void _s80056BF0_4();
extern "C" void _s80056BF0_5();
extern "C" void _s80056BF0_6();
extern "C" void _s80056BF0_7();
extern "C" void _s80056BF0_8();
extern "C" void _s80056BF0_9();
extern "C" void f_80056BF0() {}
