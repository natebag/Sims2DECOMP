// 0x801C9C8C MODTarget::SelectDpadArrow(MODTarget::eSidePanelId) (448 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 0,0xa8(31); cmpwi 0,0; bne 4f; addi 30,31,200; mr 3,30; mr 29,30; bl _s801C9C8C_0; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12700; mr 3,30; bl _s801C9C8C_1; li 4,0; mr 3,30; bl _s801C9C8C_2; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12716; mr 3,30; bl _s801C9C8C_3; li 4,0; mr 3,30; bl _s801C9C8C_4; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12736; mr 3,30; bl _s801C9C8C_5; mr 3,30; li 4,1; bl _s801C9C8C_6; cmpwi 28,1; bne 0f; lis 4,-32705; mr 3,29; addi 4,4,12760; bl _s801C9C8C_7; b 1f; 0:; lis 4,-32705; mr 3,29; addi 4,4,12768; bl _s801C9C8C_8; 1:; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12776; mr 3,29; bl _s801C9C8C_9; mr 3,29; li 4,1; bl _s801C9C8C_10; cmpwi 28,0; bne 2f; lis 4,-32705; mr 3,29; addi 4,4,12760; bl _s801C9C8C_11; b 3f; 2:; lis 4,-32705; mr 3,29; addi 4,4,12768; bl _s801C9C8C_12; 3:; mr 3,29; bl _s801C9C8C_13; li 9,0; li 0,1; stw 9,0xb0(31); stw 0,0xa8(31); stw 9,0xac(31); b 6f; 4:; cmpwi 28,1; bne 5f; addi 30,31,200; mr 3,30; bl _s801C9C8C_14; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12736; mr 3,30; bl _s801C9C8C_15; lis 4,-32705; mr 3,30; addi 4,4,12760; bl _s801C9C8C_16; mr 3,30; bl _s801C9C8C_17; 5:; cmpwi 28,0; bne 6f; addi 30,31,200; mr 3,30; bl _s801C9C8C_18; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12776; mr 3,30; bl _s801C9C8C_19; lis 4,-32705; mr 3,30; addi 4,4,12760; bl _s801C9C8C_20; mr 3,30; bl _s801C9C8C_21; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801C9C8C_0();
extern "C" void _s801C9C8C_1();
extern "C" void _s801C9C8C_2();
extern "C" void _s801C9C8C_3();
extern "C" void _s801C9C8C_4();
extern "C" void _s801C9C8C_5();
extern "C" void _s801C9C8C_6();
extern "C" void _s801C9C8C_7();
extern "C" void _s801C9C8C_8();
extern "C" void _s801C9C8C_9();
extern "C" void _s801C9C8C_10();
extern "C" void _s801C9C8C_11();
extern "C" void _s801C9C8C_12();
extern "C" void _s801C9C8C_13();
extern "C" void _s801C9C8C_14();
extern "C" void _s801C9C8C_15();
extern "C" void _s801C9C8C_16();
extern "C" void _s801C9C8C_17();
extern "C" void _s801C9C8C_18();
extern "C" void _s801C9C8C_19();
extern "C" void _s801C9C8C_20();
extern "C" void _s801C9C8C_21();
extern "C" void f_801C9C8C() {}
