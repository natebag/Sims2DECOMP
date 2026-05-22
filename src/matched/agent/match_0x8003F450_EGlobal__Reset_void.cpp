// 0x8003F450 EGlobal::Reset(void) (1168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; li 30,0; stw 30,0xd0(31); lwz 3,0xe4(31); cmpwi 3,0; beq 0f; bl _s8003F450_0; stw 30,0xe4(31); 0:; lwz 3,0xe8(31); cmpwi 3,0; beq 1f; bl _s8003F450_1; stw 30,0xe8(31); 1:; lwz 3,0xf0(31); cmpwi 3,0; beq 2f; bl _s8003F450_2; stw 30,0xf0(31); 2:; lwz 3,0xec(31); cmpwi 3,0; beq 3f; bl _s8003F450_3; stw 30,0xec(31); 3:; lwz 3,0xf4(31); cmpwi 3,0; beq 4f; bl _s8003F450_4; stw 30,0xf4(31); 4:; lwz 3,0xfc(31); cmpwi 3,0; beq 5f; bl _s8003F450_5; stw 30,0xfc(31); 5:; lwz 3,0x100(31); cmpwi 3,0; beq 6f; bl _s8003F450_6; stw 30,0x100(31); 6:; lwz 3,0x104(31); cmpwi 3,0; beq 7f; bl _s8003F450_7; stw 30,0x104(31); 7:; lwz 3,0x108(31); cmpwi 3,0; beq 8f; bl _s8003F450_8; stw 30,0x108(31); 8:; lis 30,-32693; lis 4,20498; addi 3,30,24536; ori 4,4,58880; bl _s8003F450_9; cmpwi 3,0; beq 9f; lis 4,20498; addi 3,30,24536; ori 4,4,58880; li 5,1; bl _s8003F450_10; 9:; lwz 3,-32424(13); cmpwi 3,0; beq 10f; bl _s8003F450_11; li 0,0; stw 0,-32424(13); 10:; lwz 3,0x114(31); cmpwi 3,0; beq 12f; bl _s8003F450_12; lwz 3,0x114(31); cmpwi 3,0; beq 11f; li 4,3; bl _s8003F450_13; 11:; li 0,0; stw 0,0x114(31); 12:; lwz 3,0x110(31); cmpwi 3,0; beq 16f; li 4,0; bl _s8003F450_14; cmpwi 3,0; beq 13f; lwz 3,0x110(31); li 4,0; bl _s8003F450_15; 13:; lwz 3,0x110(31); li 4,1; bl _s8003F450_16; cmpwi 3,0; beq 14f; lwz 3,0x110(31); li 4,1; bl _s8003F450_17; 14:; lwz 3,0x110(31); bl _s8003F450_18; lwz 3,0x110(31); cmpwi 3,0; beq 15f; li 4,3; bl _s8003F450_19; 15:; li 0,0; stw 0,0x110(31); 16:; lwz 3,0xc8(31); cmpwi 3,0; beq 17f; li 4,3; bl _s8003F450_20; 17:; lwz 3,0x10c(31); li 30,0; stw 30,0xc8(31); cmpwi 3,0; beq 18f; li 4,3; bl _s8003F450_21; 18:; lwz 3,0x148(31); stw 30,0x10c(31); cmpwi 3,0; beq 19f; bl _s8003F450_22; 19:; stw 30,0x148(31); addi 29,31,280; li 27,0; li 30,0; li 28,2; 20:; lwzx 3,30,29; cmpwi 3,0; beq 21f; li 4,3; bl _s8003F450_23; 21:; stwx 27,30,29; addic. 28,28,-1; addi 30,30,4; bne 20b; lwz 3,0x120(31); cmpwi 3,0; beq 22f; li 4,3; bl _s8003F450_24; 22:; lwz 3,0x490(31); li 29,0; stw 29,0x120(31); cmpwi 3,0; beq 23f; li 4,3; bl _s8003F450_25; stw 29,0x490(31); 23:; bl _s8003F450_26; li 30,0; lwz 11,0x140(31); stw 30,0x450(31); stw 30,0x454(31); cmpwi 11,0; beq 24f; lwz 9,0x84(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x140(31); 24:; lwz 11,0x13c(31); cmpwi 11,0; beq 25f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 28,0x13c(31); 25:; lwz 11,0x134(31); cmpwi 11,0; beq 26f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 28,0x134(31); 26:; lwz 11,0x130(31); cmpwi 11,0; beq 27f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 28,0x130(31); 27:; lwz 11,0x128(31); cmpwi 11,0; beq 28f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 28,0x128(31); 28:; lwz 11,0x124(31); cmpwi 11,0; beq 29f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 28,0x124(31); 29:; lwz 11,0x12c(31); cmpwi 11,0; beq 30f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 28,0x12c(31); 30:; bl _s8003F450_27; bl _s8003F450_28; lwz 11,-31516(13); cmpwi 11,0; beq 31f; lwz 9,0xc(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 28,-31516(13); 31:; lwz 11,-31488(13); cmpwi 11,0; beq 32f; lwz 9,0xc(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 29,-31488(13); 32:; lwz 11,-31528(13); cmpwi 11,0; beq 33f; lwz 9,0xc(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 30,-31528(13); 33:; lwz 11,-31532(13); cmpwi 11,0; beq 34f; lwz 9,0xc(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,-31532(13); 34:; lwz 3,0xb4(31); cmpwi 3,0; beq 35f; li 4,3; bl _s8003F450_29; li 0,0; stw 0,0xb4(31); 35:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8003F450_0();
extern "C" void _s8003F450_1();
extern "C" void _s8003F450_2();
extern "C" void _s8003F450_3();
extern "C" void _s8003F450_4();
extern "C" void _s8003F450_5();
extern "C" void _s8003F450_6();
extern "C" void _s8003F450_7();
extern "C" void _s8003F450_8();
extern "C" void _s8003F450_9();
extern "C" void _s8003F450_10();
extern "C" void _s8003F450_11();
extern "C" void _s8003F450_12();
extern "C" void _s8003F450_13();
extern "C" void _s8003F450_14();
extern "C" void _s8003F450_15();
extern "C" void _s8003F450_16();
extern "C" void _s8003F450_17();
extern "C" void _s8003F450_18();
extern "C" void _s8003F450_19();
extern "C" void _s8003F450_20();
extern "C" void _s8003F450_21();
extern "C" void _s8003F450_22();
extern "C" void _s8003F450_23();
extern "C" void _s8003F450_24();
extern "C" void _s8003F450_25();
extern "C" void _s8003F450_26();
extern "C" void _s8003F450_27();
extern "C" void _s8003F450_28();
extern "C" void _s8003F450_29();
extern "C" void f_8003F450() {}
