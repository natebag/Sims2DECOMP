// 0x8032EC4C XOSFontStartup(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-26448(13); cmpwi 0,0; bne 2f; bl _s8032EC4C_0; cmpwi 3,1; bne 0f; bl _s8032EC4C_1; lis 4,9; li 5,32; ori 4,4,3812; li 6,0; li 7,0; bl _s8032EC4C_2; stw 3,-26448(13); bl _s8032EC4C_3; lis 4,4; li 5,32; ori 4,4,53248; b 1f; 0:; bl _s8032EC4C_4; lis 4,1; li 5,32; ori 4,4,288; li 6,0; li 7,0; bl _s8032EC4C_5; stw 3,-26448(13); bl _s8032EC4C_6; li 4,12288; li 5,32; 1:; li 6,0; li 7,0; bl _s8032EC4C_7; stw 3,-26444(13); lwz 4,-26444(13); lwz 3,-26448(13); bl _s8032EC4C_8; bl _s8032EC4C_9; lwz 4,-26444(13); bl _s8032EC4C_10; li 0,0; stw 0,-26444(13); 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032EC4C_0();
extern "C" void _s8032EC4C_1();
extern "C" void _s8032EC4C_2();
extern "C" void _s8032EC4C_3();
extern "C" void _s8032EC4C_4();
extern "C" void _s8032EC4C_5();
extern "C" void _s8032EC4C_6();
extern "C" void _s8032EC4C_7();
extern "C" void _s8032EC4C_8();
extern "C" void _s8032EC4C_9();
extern "C" void _s8032EC4C_10();
extern "C" void f_8032EC4C() {}
