// 0x801CA648 MODTarget::SetDpadIcons(MODTarget::eSidePanelIcon) (768 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x84(31); cmpwi 0,0; beq 15f; cmpwi 29,4; beq 9f; bgt 1f; cmpwi 29,1; beq 2f; bgt 0f; cmpwi 29,0; beq 11f; b 15f; 0:; cmpwi 29,2; beq 3f; cmpwi 29,3; beq 4f; b 15f; 1:; cmpwi 29,6; beq 6f; blt 5f; cmpwi 29,7; beq 7f; cmpwi 29,8; beq 8f; b 15f; 2:; mr 3,31; li 4,6; bl _s801CA648_0; b 15f; 3:; mr 3,31; li 4,0; bl _s801CA648_1; b 15f; 4:; mr 3,31; li 4,1; bl _s801CA648_2; b 15f; 5:; mr 3,31; li 4,2; bl _s801CA648_3; b 15f; 6:; mr 3,31; li 4,3; bl _s801CA648_4; b 15f; 7:; mr 3,31; li 4,4; bl _s801CA648_5; b 15f; 8:; mr 3,31; li 4,5; bl _s801CA648_6; b 15f; 9:; lwz 4,0xc4(31); addi 0,4,-3; cmplwi 0,1; bgt 10f; addi 30,31,200; mr 3,30; bl _s801CA648_7; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12776; mr 3,30; bl _s801CA648_8; li 4,0; mr 3,30; bl _s801CA648_9; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12736; mr 3,30; bl _s801CA648_10; li 4,0; mr 3,30; bl _s801CA648_11; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12700; mr 3,30; bl _s801CA648_12; li 4,1; mr 3,30; bl _s801CA648_13; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12716; mr 3,30; bl _s801CA648_14; mr 3,30; li 4,1; bl _s801CA648_15; mr 3,30; bl _s801CA648_16; li 0,0; stw 0,0xa8(31); b 15f; 10:; mr 3,31; bl _s801CA648_17; b 15f; 11:; lwz 9,0xc4(31); cmpwi 9,5; beq 15f; lwz 0,0xa8(31); cmpwi 0,0; bne 12f; li 4,6; mr 3,31; bl _s801CA648_18; addi 30,31,200; mr 3,30; bl _s801CA648_19; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12716; mr 3,30; bl _s801CA648_20; lis 4,-32705; mr 3,30; addi 4,4,12884; bl _s801CA648_21; mr 3,30; bl _s801CA648_22; b 14f; 12:; cmpwi 9,3; bne 13f; addi 30,31,200; mr 3,30; bl _s801CA648_23; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12804; mr 3,30; bl _s801CA648_24; lis 4,-32705; mr 3,30; addi 4,4,12768; bl _s801CA648_25; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12716; mr 3,30; bl _s801CA648_26; lis 4,-32705; mr 3,30; addi 4,4,12884; bl _s801CA648_27; mr 3,30; bl _s801CA648_28; stw 29,0xb8(31); 13:; lwz 0,0xc4(31); cmpwi 0,4; bne 14f; addi 30,31,200; mr 3,30; bl _s801CA648_29; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12824; mr 3,30; bl _s801CA648_30; lis 4,-32705; mr 3,30; addi 4,4,12768; bl _s801CA648_31; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12716; mr 3,30; bl _s801CA648_32; lis 4,-32705; mr 3,30; addi 4,4,12884; bl _s801CA648_33; mr 3,30; bl _s801CA648_34; stw 29,0xbc(31); 14:; li 9,5; li 0,1; stw 0,0xc0(31); stw 9,0xc4(31); 15:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801CA648_0();
extern "C" void _s801CA648_1();
extern "C" void _s801CA648_2();
extern "C" void _s801CA648_3();
extern "C" void _s801CA648_4();
extern "C" void _s801CA648_5();
extern "C" void _s801CA648_6();
extern "C" void _s801CA648_7();
extern "C" void _s801CA648_8();
extern "C" void _s801CA648_9();
extern "C" void _s801CA648_10();
extern "C" void _s801CA648_11();
extern "C" void _s801CA648_12();
extern "C" void _s801CA648_13();
extern "C" void _s801CA648_14();
extern "C" void _s801CA648_15();
extern "C" void _s801CA648_16();
extern "C" void _s801CA648_17();
extern "C" void _s801CA648_18();
extern "C" void _s801CA648_19();
extern "C" void _s801CA648_20();
extern "C" void _s801CA648_21();
extern "C" void _s801CA648_22();
extern "C" void _s801CA648_23();
extern "C" void _s801CA648_24();
extern "C" void _s801CA648_25();
extern "C" void _s801CA648_26();
extern "C" void _s801CA648_27();
extern "C" void _s801CA648_28();
extern "C" void _s801CA648_29();
extern "C" void _s801CA648_30();
extern "C" void _s801CA648_31();
extern "C" void _s801CA648_32();
extern "C" void _s801CA648_33();
extern "C" void _s801CA648_34();
extern "C" void f_801CA648() {}
