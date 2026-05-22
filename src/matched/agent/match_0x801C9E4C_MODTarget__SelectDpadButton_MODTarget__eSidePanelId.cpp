// 0x801C9E4C MODTarget::SelectDpadButton(MODTarget::eSidePanelId) (924 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 28,4; lwz 0,0xa8(31); cmpwi 0,0; beq 4f; cmpwi 28,3; beq 4f; cmpwi 28,4; beq 4f; li 27,0; addi 30,31,200; stw 27,0xa8(31); mr 3,30; stw 28,0xc4(31); mr 29,30; bl _s801C9E4C_0; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12776; mr 3,30; bl _s801C9E4C_1; li 4,0; mr 3,30; bl _s801C9E4C_2; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12736; mr 3,30; bl _s801C9E4C_3; li 4,0; mr 3,30; bl _s801C9E4C_4; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12700; mr 3,30; bl _s801C9E4C_5; mr 3,30; li 4,1; bl _s801C9E4C_6; cmpwi 28,2; bne 0f; lwz 0,0xb4(31); cmpwi 0,1; beq 1f; li 0,1; lis 4,-32705; stw 0,0xb4(31); addi 4,4,12760; mr 3,29; bl _s801C9E4C_7; b 1f; 0:; lwz 0,0xb4(31); cmpwi 0,1; bne 1f; lis 4,-32705; stw 27,0xb4(31); addi 4,4,12768; mr 3,29; bl _s801C9E4C_8; 1:; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12716; mr 3,29; bl _s801C9E4C_9; mr 3,29; li 4,1; bl _s801C9E4C_10; cmpwi 28,5; bne 2f; lwz 0,0xc0(31); cmpwi 0,1; beq 3f; li 0,1; lis 4,-32705; stw 0,0xc0(31); addi 4,4,3316; mr 3,29; bl _s801C9E4C_11; b 3f; 2:; lwz 0,0xc0(31); cmpwi 0,1; bne 3f; li 0,0; lis 4,-32705; stw 0,0xc0(31); addi 4,4,12800; mr 3,29; bl _s801C9E4C_12; 3:; mr 3,29; bl _s801C9E4C_13; b 13f; 4:; lwz 0,0xc4(31); cmpw 0,28; beq 13f; addi 0,31,200; stw 28,0xc4(31); mr 3,0; mr 29,0; bl _s801C9E4C_14; lwz 0,0xb8(31); cmpwi 0,1; bne 5f; cmpwi 28,3; beq 6f; li 0,0; lis 4,-32705; lwz 5,0x94(31); addi 4,4,12804; mr 3,29; stw 0,0xb8(31); bl _s801C9E4C_15; lis 4,-32705; mr 3,29; addi 4,4,12768; bl _s801C9E4C_16; b 6f; 5:; cmpwi 28,3; bne 6f; li 0,1; lis 4,-32705; lwz 5,0x94(31); addi 4,4,12804; mr 3,29; stw 0,0xb8(31); bl _s801C9E4C_17; lis 4,-32705; mr 3,29; addi 4,4,12760; bl _s801C9E4C_18; 6:; lwz 0,0xb4(31); cmpwi 0,1; bne 7f; cmpwi 28,2; beq 8f; li 0,0; lis 4,-32705; lwz 5,0x94(31); addi 4,4,12700; mr 3,29; stw 0,0xb4(31); bl _s801C9E4C_19; lis 4,-32705; mr 3,29; addi 4,4,12768; bl _s801C9E4C_20; b 8f; 7:; cmpwi 28,2; bne 8f; li 0,1; lis 4,-32705; lwz 5,0x94(31); addi 4,4,12700; mr 3,29; stw 0,0xb4(31); bl _s801C9E4C_21; lis 4,-32705; mr 3,29; addi 4,4,12760; bl _s801C9E4C_22; 8:; lwz 0,0xbc(31); cmpwi 0,1; bne 9f; cmpwi 28,4; beq 10f; li 0,0; lis 4,-32705; lwz 5,0x94(31); addi 4,4,12824; mr 3,29; stw 0,0xbc(31); bl _s801C9E4C_23; lis 4,-32705; mr 3,29; addi 4,4,12768; bl _s801C9E4C_24; b 10f; 9:; cmpwi 28,4; bne 10f; li 0,1; lis 4,-32705; lwz 5,0x94(31); addi 4,4,12824; mr 3,29; stw 0,0xbc(31); bl _s801C9E4C_25; lis 4,-32705; mr 3,29; addi 4,4,12760; bl _s801C9E4C_26; 10:; lwz 0,0xc0(31); cmpwi 0,1; bne 11f; cmpwi 28,5; beq 12f; li 0,0; lwz 5,0x94(31); lis 4,-32705; mr 3,29; addi 4,4,12716; stw 0,0xc0(31); bl _s801C9E4C_27; lis 4,-32705; mr 3,29; addi 4,4,3316; bl _s801C9E4C_28; b 12f; 11:; cmpwi 28,5; bne 12f; li 0,1; lwz 5,0x94(31); lis 4,-32705; mr 3,29; addi 4,4,12716; stw 0,0xc0(31); bl _s801C9E4C_29; lis 4,-32705; mr 3,29; addi 4,4,12800; bl _s801C9E4C_30; 12:; mr 3,29; bl _s801C9E4C_31; 13:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801C9E4C_0();
extern "C" void _s801C9E4C_1();
extern "C" void _s801C9E4C_2();
extern "C" void _s801C9E4C_3();
extern "C" void _s801C9E4C_4();
extern "C" void _s801C9E4C_5();
extern "C" void _s801C9E4C_6();
extern "C" void _s801C9E4C_7();
extern "C" void _s801C9E4C_8();
extern "C" void _s801C9E4C_9();
extern "C" void _s801C9E4C_10();
extern "C" void _s801C9E4C_11();
extern "C" void _s801C9E4C_12();
extern "C" void _s801C9E4C_13();
extern "C" void _s801C9E4C_14();
extern "C" void _s801C9E4C_15();
extern "C" void _s801C9E4C_16();
extern "C" void _s801C9E4C_17();
extern "C" void _s801C9E4C_18();
extern "C" void _s801C9E4C_19();
extern "C" void _s801C9E4C_20();
extern "C" void _s801C9E4C_21();
extern "C" void _s801C9E4C_22();
extern "C" void _s801C9E4C_23();
extern "C" void _s801C9E4C_24();
extern "C" void _s801C9E4C_25();
extern "C" void _s801C9E4C_26();
extern "C" void _s801C9E4C_27();
extern "C" void _s801C9E4C_28();
extern "C" void _s801C9E4C_29();
extern "C" void _s801C9E4C_30();
extern "C" void _s801C9E4C_31();
extern "C" void f_801C9E4C() {}
