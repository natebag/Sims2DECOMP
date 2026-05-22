// 0x8019FB08 CASRoommateTarget::CASRoommateTarget(void) (1344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; mfcr 12; stmw 20,0x48(1); stw 0,0x7c(1); stw 12,0x44(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12328; stw 9,0x80(31); addi 8,31,40; stw 0,0x0(31); addi 7,31,56; stw 0,0x4(31); addi 6,31,72; stw 0,0x8(31); addi 5,31,88; stw 0,0xc(31); addi 4,31,104; stw 0,0x10(31); lis 11,-32698; stw 0,0x14(31); lis 9,-32698; stw 0,0x18(31); li 10,4; stw 0,0x8(8); addi 11,11,27176; stw 0,0x28(31); addi 9,9,27272; stw 0,0x8(7); mtspr 9,10; stw 0,0x38(31); addi 8,1,24; stw 0,0x8(6); addi 30,1,8; stw 0,0x48(31); addi 23,1,32; stw 0,0x8(5); addi 22,1,40; stw 0,0x58(31); addi 21,1,48; stw 0,0x8(4); addi 20,1,56; stw 11,0x88(31); stw 9,0x80(31); stw 0,0x94(31); stw 0,0x68(31); stw 0,0x78(31); stw 0,0x84(31); stw 0,0x8c(31); stw 0,0x90(31); 0:; bdnz 0b; li 0,4; addi 24,31,40; mtspr 9,0; addi 25,31,56; addi 29,31,72; addi 27,31,88; addi 26,31,104; cmpwi 4,31,0; 1:; bdnz 1b; lis 9,-32705; lis 10,-32709; addi 9,9,-11560; addi 28,10,19472; lwz 11,0x0(9); lwz 12,0x4(9); stw 31,0x10(1); stw 11,0x18(1); stw 12,0x1c(1); beq cr4,2f; mr 4,8; addi 3,1,8; li 5,8; bl _s8019FB08_0; b 3f; 2:; stw 31,0x8(1); 3:; lis 9,-32705; stw 28,0x14(1); addi 9,9,-11552; lwz 6,0x8(1); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; lwz 10,0x4(30); addi 28,11,19592; lwz 0,0x8(30); lwz 9,0xc(30); stw 6,0x28(31); stw 10,0x4(24); stw 0,0x8(24); stw 9,0xc(24); stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq cr4,4f; mr 4,23; mr 3,30; li 5,8; bl _s8019FB08_1; b 5f; 4:; stw 31,0x8(1); 5:; lis 9,-32705; stw 28,0x14(1); addi 9,9,-15244; lwz 6,0x8(1); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; lwz 10,0x4(30); addi 28,11,19712; lwz 0,0x8(30); lwz 9,0xc(30); stw 6,0x38(31); stw 10,0x4(25); stw 0,0x8(25); stw 9,0xc(25); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq cr4,6f; mr 4,22; mr 3,30; li 5,8; bl _s8019FB08_2; b 7f; 6:; stw 31,0x8(1); 7:; lis 9,-32705; stw 28,0x14(1); addi 9,9,-15236; lwz 6,0x8(1); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; lwz 10,0x4(30); addi 28,11,19832; lwz 9,0x8(30); lwz 0,0xc(30); stw 6,0x48(31); stw 0,0xc(29); stw 10,0x4(29); stw 9,0x8(29); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,8f; mr 4,21; mr 3,30; li 5,8; bl _s8019FB08_3; b 9f; 8:; stw 31,0x8(1); 9:; lis 9,-32705; stw 28,0x14(1); addi 9,9,-11544; lwz 6,0x8(1); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; lwz 10,0x4(30); addi 29,11,19952; lwz 9,0x8(30); lwz 0,0xc(30); stw 6,0x58(31); stw 0,0xc(27); stw 10,0x4(27); stw 9,0x8(27); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,10f; mr 4,20; mr 3,30; li 5,8; bl _s8019FB08_4; b 11f; 10:; stw 31,0x8(1); 11:; stw 29,0x14(1); lis 9,-32705; lwz 10,0x8(1); addi 9,9,-11536; lwz 8,0x4(30); lwz 7,0x8(30); lwz 0,0xc(30); lwz 11,-31532(13); stw 10,0x68(31); stw 0,0xc(26); cmpwi 11,0; stw 8,0x4(26); stw 7,0x8(26); stw 9,0x7c(31); bne 12f; li 3,16; bl _s8019FB08_5; bl _s8019FB08_6; stw 3,-31532(13); 12:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 13f; li 3,16; bl _s8019FB08_7; bl _s8019FB08_8; stw 3,-31528(13); 13:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 14f; li 3,16; bl _s8019FB08_9; bl _s8019FB08_10; stw 3,-31524(13); 14:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 15f; li 3,16; bl _s8019FB08_11; bl _s8019FB08_12; stw 3,-31488(13); 15:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 16f; li 3,16; bl _s8019FB08_13; bl _s8019FB08_14; stw 3,-31516(13); 16:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 17f; li 3,16; bl _s8019FB08_15; bl _s8019FB08_16; stw 3,-31484(13); 17:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 18f; li 3,16; bl _s8019FB08_17; bl _s8019FB08_18; stw 3,-31544(13); 18:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 19f; li 3,32; bl _s8019FB08_19; bl _s8019FB08_20; stw 3,-31540(13); 19:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 20f; li 3,120; bl _s8019FB08_21; bl _s8019FB08_22; stw 3,-31536(13); 20:; lwz 0,-31536(13); li 29,1; stw 29,0x0(31); lis 4,-32705; lwz 3,0x4(31); addi 4,4,-11516; stw 0,0x24(31); mr 5,24; bl _s8019FB08_23; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-11500; cmpwi 0,0; beq 21f; lwz 3,0x8(31); mr 5,25; bl _s8019FB08_24; 21:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-11476; cmpwi 0,0; beq 22f; lwz 3,0x8(31); mr 5,25; bl _s8019FB08_25; 22:; li 3,60; bl _s8019FB08_26; bl _s8019FB08_27; stw 3,0x94(31); cmpwi 3,0; beq 23f; lis 4,27935; ori 4,4,2390; bl _s8019FB08_28; lwz 11,0x94(31); lis 9,-32705; lfs f0,-11452(9); lis 7,-32696; stw 29,0x20(11); addi 3,31,152; li 4,0; li 5,248; lwz 9,0x94(31); stw 29,0x24(9); stfs f0,0x8(30); stfs f0,0x4(30); stfs f0,0x8(1); lwz 11,0x94(31); lwz 10,0x8(1); lwz 8,0x8(30); addi 9,11,12; lwz 0,0x4(30); stw 10,0xc(11); stw 8,0x8(9); stw 0,0x4(9); lfs f0,0x55c0(7); lwz 9,0x94(31); stfs f0,0x18(9); bl _s8019FB08_29; 23:; mr 3,31; lwz 0,0x7c(1); lwz 12,0x44(1); mtspr 8,0; lmw 20,0x48(1); mtcrf 8,12; addi 1,1,120"
extern "C" void _s8019FB08_0();
extern "C" void _s8019FB08_1();
extern "C" void _s8019FB08_2();
extern "C" void _s8019FB08_3();
extern "C" void _s8019FB08_4();
extern "C" void _s8019FB08_5();
extern "C" void _s8019FB08_6();
extern "C" void _s8019FB08_7();
extern "C" void _s8019FB08_8();
extern "C" void _s8019FB08_9();
extern "C" void _s8019FB08_10();
extern "C" void _s8019FB08_11();
extern "C" void _s8019FB08_12();
extern "C" void _s8019FB08_13();
extern "C" void _s8019FB08_14();
extern "C" void _s8019FB08_15();
extern "C" void _s8019FB08_16();
extern "C" void _s8019FB08_17();
extern "C" void _s8019FB08_18();
extern "C" void _s8019FB08_19();
extern "C" void _s8019FB08_20();
extern "C" void _s8019FB08_21();
extern "C" void _s8019FB08_22();
extern "C" void _s8019FB08_23();
extern "C" void _s8019FB08_24();
extern "C" void _s8019FB08_25();
extern "C" void _s8019FB08_26();
extern "C" void _s8019FB08_27();
extern "C" void _s8019FB08_28();
extern "C" void _s8019FB08_29();
extern "C" void f_8019FB08() {}
