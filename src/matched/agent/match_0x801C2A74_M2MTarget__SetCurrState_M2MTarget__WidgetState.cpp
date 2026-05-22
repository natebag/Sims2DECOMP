// 0x801C2A74 M2MTarget::SetCurrState(M2MTarget::WidgetState) (780 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; cmpwi 4,2; beq 16f; bgt 0f; cmpwi 4,0; beq 1f; cmpwi 4,1; beq 15f; b 33f; 0:; cmpwi 4,3; beq 17f; b 33f; 1:; lwz 0,0x11c(31); cmpwi 0,8; beq 33f; bgt 2f; cmpwi 0,1; beq 14f; b 33f; 2:; cmpwi 0,13; beq 33f; bgt 3f; cmpwi 0,9; beq 4f; b 33f; 3:; cmpwi 0,15; beq 7f; b 33f; 4:; lwz 0,0x10c(31); cmpwi 0,255; beq 5f; lwz 0,0x110(31); cmpwi 0,255; bne 6f; 5:; li 0,1; b 32f; 6:; lwz 0,0x118(31); cmpwi 0,0; bne 33f; li 3,332; bl _s801C2A74_0; mr 30,3; mr 3,31; bl _s801C2A74_1; mr 5,3; mr 4,31; mr 3,30; li 6,19; bl _s801C2A74_2; b 12f; 7:; lwz 0,0x10c(31); cmpwi 0,255; beq 8f; lwz 0,0x110(31); cmpwi 0,255; bne 9f; 8:; li 0,1; b 32f; 9:; lwz 0,0x118(31); cmpwi 0,0; bne 33f; lwz 0,0x194(31); cmpwi 0,0; beq 10f; li 3,360; bl _s801C2A74_3; mr 30,3; mr 3,31; bl _s801C2A74_4; mr 5,3; mr 4,31; mr 3,30; li 6,1; b 11f; 10:; li 3,360; bl _s801C2A74_5; mr 30,3; mr 3,31; bl _s801C2A74_6; mr 5,3; mr 4,31; mr 3,30; li 6,0; 11:; bl _s801C2A74_7; 12:; mr. 3,3; li 0,0; beq 13f; addi 0,3,268; 13:; stw 0,0x118(31); b 33f; 14:; mr 3,31; bl _s801C2A74_8; b 33f; 15:; li 9,0; li 0,2; stw 0,0x168(31); stw 9,0x184(31); b 33f; 16:; addi 3,31,132; bl _s801C2A74_9; li 0,1; stw 0,0x184(31); b 33f; 17:; mr 3,31; bl _s801C2A74_10; addi 3,31,132; bl _s801C2A74_11; lis 3,-32705; addi 3,3,8412; bl _s801C2A74_12; cmpwi 3,6; beq 23f; bgt 19f; cmpwi 3,1; beq 28f; bgt 18f; cmpwi 3,-1; beq 31f; cmpwi 3,0; beq 21f; b 31f; 18:; cmpwi 3,2; beq 30f; cmpwi 3,5; beq 22f; b 31f; 19:; cmpwi 3,9; beq 26f; bgt 20f; cmpwi 3,7; beq 24f; cmpwi 3,8; beq 25f; b 31f; 20:; cmpwi 3,10; beq 27f; cmpwi 3,11; beq 29f; b 31f; 21:; lis 3,-32705; addi 3,3,9192; bl _s801C2A74_13; b 31f; 22:; lis 3,-32705; addi 3,3,9204; bl _s801C2A74_14; b 31f; 23:; lis 3,-32705; addi 3,3,9224; bl _s801C2A74_15; b 31f; 24:; lis 3,-32705; addi 3,3,9244; bl _s801C2A74_16; b 31f; 25:; lis 3,-32705; addi 3,3,9268; bl _s801C2A74_17; b 31f; 26:; lis 3,-32705; addi 3,3,6560; bl _s801C2A74_18; b 31f; 27:; lis 3,-32705; addi 3,3,6560; bl _s801C2A74_19; lis 9,-32697; lwz 3,0x5bc0(9); cmpwi 3,0; beq 31f; li 4,1; bl _s801C2A74_20; b 31f; 28:; lis 3,-32705; addi 3,3,-5340; bl _s801C2A74_21; b 31f; 29:; lis 3,-32705; addi 3,3,9292; bl _s801C2A74_22; b 31f; 30:; lis 3,-32705; addi 3,3,6560; bl _s801C2A74_23; 31:; li 0,4; 32:; stw 0,0x168(31); 33:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801C2A74_0();
extern "C" void _s801C2A74_1();
extern "C" void _s801C2A74_2();
extern "C" void _s801C2A74_3();
extern "C" void _s801C2A74_4();
extern "C" void _s801C2A74_5();
extern "C" void _s801C2A74_6();
extern "C" void _s801C2A74_7();
extern "C" void _s801C2A74_8();
extern "C" void _s801C2A74_9();
extern "C" void _s801C2A74_10();
extern "C" void _s801C2A74_11();
extern "C" void _s801C2A74_12();
extern "C" void _s801C2A74_13();
extern "C" void _s801C2A74_14();
extern "C" void _s801C2A74_15();
extern "C" void _s801C2A74_16();
extern "C" void _s801C2A74_17();
extern "C" void _s801C2A74_18();
extern "C" void _s801C2A74_19();
extern "C" void _s801C2A74_20();
extern "C" void _s801C2A74_21();
extern "C" void _s801C2A74_22();
extern "C" void _s801C2A74_23();
extern "C" void f_801C2A74() {}
