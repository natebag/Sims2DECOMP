// 0x8015F718 CasCostumes::LoadCostumesList(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,3; lis 4,19606; lis 3,-32693; ori 4,4,31273; addi 3,3,17784; li 5,0; li 6,0; bl _s8015F718_0; mr. 30,3; bne 0f; mr 3,29; bl _s8015F718_1; b 3f; 0:; bl _s8015F718_2; li 4,12; li 5,0; bl _s8015F718_3; lwz 0,0x18(30); mr 31,3; li 9,0; li 11,2; stw 0,0x0(31); lis 5,17219; stw 9,0x8(31); mr 3,29; mr 4,31; ori 5,5,21332; lwz 0,0x14(30); addi 6,1,8; stw 0,0x4(31); stw 11,0x8(1); bl _s8015F718_4; cmpwi 31,0; beq 2f; lwz 0,0x8(31); cmpwi 0,0; beq 1f; bl _s8015F718_5; lwz 4,0x4(31); bl _s8015F718_6; 1:; bl _s8015F718_7; mr 4,31; bl _s8015F718_8; 2:; cmpwi 30,0; beq 3f; mr 3,30; bl _s8015F718_9; 3:; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8015F718_0();
extern "C" void _s8015F718_1();
extern "C" void _s8015F718_2();
extern "C" void _s8015F718_3();
extern "C" void _s8015F718_4();
extern "C" void _s8015F718_5();
extern "C" void _s8015F718_6();
extern "C" void _s8015F718_7();
extern "C" void _s8015F718_8();
extern "C" void _s8015F718_9();
extern "C" void f_8015F718() {}
