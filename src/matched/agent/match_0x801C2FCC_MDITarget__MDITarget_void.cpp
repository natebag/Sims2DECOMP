// 0x801C2FCC MDITarget::MDITarget(void) (1552 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stmw 25,0x44(1); stw 0,0x64(1); stw 12,0x40(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12328; stw 9,0x80(31); addi 10,31,40; stw 0,0x0(31); addi 7,31,56; stw 0,0x4(31); addi 5,31,72; stw 0,0x8(31); addi 4,31,88; stw 0,0xc(31); lis 9,-32708; stw 0,0x10(31); lis 8,-32705; stw 0,0x14(31); addi 8,8,9312; stw 0,0x18(31); addi 6,31,104; stw 0,0x8(10); lis 11,-32698; stw 0,0x28(31); addi 30,9,-32020; stw 0,0x8(7); addi 11,11,29992; stw 0,0x38(31); addi 7,1,24; stw 0,0x8(5); cmpwi 31,0; stw 0,0x48(31); stw 0,0x8(4); stw 0,0x58(31); stw 0,0x8(6); lwz 9,0x0(8); lwz 10,0x4(8); stw 11,0x80(31); stw 0,0x9c(31); stw 9,0x18(1); stw 10,0x1c(1); stw 0,0x68(31); stw 0,0x78(31); stw 0,0x84(31); stw 0,0x88(31); stw 0,0x90(31); stw 0,0x94(31); stw 0,0x98(31); stw 31,0x10(1); beq 0f; mr 4,7; addi 3,1,8; li 5,8; bl _s801C2FCC_0; b 1f; 0:; stw 31,0x8(1); 1:; stw 30,0x14(1); addi 11,1,8; lwz 4,0x8(1); lis 9,-32705; lwz 6,0x4(11); addi 9,9,9320; lwz 5,0x8(11); addi 10,31,40; lwz 0,0xc(11); mr 30,11; stw 4,0x28(31); mr 28,10; lwz 7,0x0(9); lwz 8,0x4(9); addi 4,1,32; stw 6,0x4(10); lis 9,-32708; stw 5,0x8(10); addi 29,9,-31900; stw 0,0xc(10); cmpwi 4,31,0; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq cr4,2f; mr 3,30; li 5,8; bl _s801C2FCC_1; b 3f; 2:; stw 31,0x8(1); 3:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,9328; lwz 5,0x8(30); addi 11,31,56; lwz 0,0x4(30); mr 25,11; lwz 10,0xc(30); addi 4,1,40; stw 6,0x38(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32708; stw 5,0x8(11); addi 29,9,-31780; stw 10,0xc(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq cr4,4f; mr 3,30; li 5,8; bl _s801C2FCC_2; b 5f; 4:; stw 31,0x8(1); 5:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,9336; lwz 5,0x8(30); addi 11,31,72; lwz 0,0x4(30); mr 26,11; lwz 10,0xc(30); addi 4,1,48; stw 6,0x48(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32708; stw 5,0x8(11); addi 29,9,-31660; stw 10,0xc(11); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,6f; mr 3,30; li 5,8; bl _s801C2FCC_3; b 7f; 6:; stw 31,0x8(1); 7:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-8840; lwz 5,0x8(30); addi 11,31,88; lwz 0,0x4(30); mr 27,11; lwz 10,0xc(30); addi 4,1,56; stw 6,0x58(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32708; stw 5,0x8(11); addi 29,9,-31540; stw 10,0xc(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,8f; mr 3,30; li 5,8; bl _s801C2FCC_4; b 9f; 8:; stw 31,0x8(1); 9:; stw 29,0x14(1); addi 11,31,104; lwz 8,0x8(1); lis 9,-32705; lwz 7,0xc(30); addi 9,9,9344; lwz 10,0x4(30); lwz 6,0x8(30); lwz 0,-31532(13); stw 8,0x68(31); stw 7,0xc(11); cmpwi 0,0; stw 10,0x4(11); stw 6,0x8(11); stw 9,0x7c(31); bne 10f; li 3,16; bl _s801C2FCC_5; bl _s801C2FCC_6; stw 3,-31532(13); 10:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 11f; li 3,16; bl _s801C2FCC_7; bl _s801C2FCC_8; stw 3,-31528(13); 11:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 12f; li 3,16; bl _s801C2FCC_9; bl _s801C2FCC_10; stw 3,-31524(13); 12:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 13f; li 3,16; bl _s801C2FCC_11; bl _s801C2FCC_12; stw 3,-31488(13); 13:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 14f; li 3,16; bl _s801C2FCC_13; bl _s801C2FCC_14; stw 3,-31516(13); 14:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 15f; li 3,16; bl _s801C2FCC_15; bl _s801C2FCC_16; stw 3,-31484(13); 15:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 16f; li 3,16; bl _s801C2FCC_17; bl _s801C2FCC_18; stw 3,-31544(13); 16:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 17f; li 3,32; bl _s801C2FCC_19; bl _s801C2FCC_20; stw 3,-31540(13); 17:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 18f; li 3,120; bl _s801C2FCC_21; bl _s801C2FCC_22; stw 3,-31536(13); 18:; lwz 0,-31536(13); li 9,1; stw 9,0x0(31); li 11,0; stw 0,0x24(31); lwz 9,0x8(27); cmpwi 9,0; bne 19f; lwz 0,0x58(31); cmpwi 0,0; beq 20f; 19:; li 11,1; 20:; cmpwi 11,0; beq 21f; lwz 3,0x10(31); mr 5,27; lwz 6,0x7c(31); li 4,75; bl _s801C2FCC_23; 21:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9356; cmpwi 0,0; beq 22f; lwz 3,0x4(31); mr 5,28; bl _s801C2FCC_24; 22:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9368; cmpwi 0,0; beq 23f; lwz 3,0x4(31); mr 5,28; bl _s801C2FCC_25; 23:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9388; cmpwi 0,0; beq 24f; lwz 3,0x4(31); mr 5,28; bl _s801C2FCC_26; 24:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9408; cmpwi 0,0; beq 25f; lwz 3,0x4(31); mr 5,28; bl _s801C2FCC_27; 25:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9428; cmpwi 0,0; beq 26f; lwz 3,0x8(31); mr 5,25; bl _s801C2FCC_28; 26:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9448; cmpwi 0,0; beq 27f; lwz 3,0x8(31); mr 5,25; bl _s801C2FCC_29; 27:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9468; cmpwi 0,0; beq 28f; lwz 3,0xc(31); mr 5,26; bl _s801C2FCC_30; 28:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9480; cmpwi 0,0; beq 29f; lwz 3,0xc(31); mr 5,26; bl _s801C2FCC_31; 29:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9492; cmpwi 0,0; beq 30f; lwz 3,0x1c(31); cmpwi 3,0; beq 30f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801C2FCC_32; 30:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,9508; cmpwi 0,0; beq 31f; lwz 3,0x1c(31); cmpwi 3,0; beq 31f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801C2FCC_33; 31:; li 0,64; lis 9,-32697; stw 0,0x8c(31); li 4,66; li 5,0; lwz 3,0x5f10(9); bl _s801C2FCC_34; mr 3,31; lwz 0,0x64(1); lwz 12,0x40(1); mtspr 8,0; lmw 25,0x44(1); mtcrf 8,12; addi 1,1,96"
extern "C" void _s801C2FCC_0();
extern "C" void _s801C2FCC_1();
extern "C" void _s801C2FCC_2();
extern "C" void _s801C2FCC_3();
extern "C" void _s801C2FCC_4();
extern "C" void _s801C2FCC_5();
extern "C" void _s801C2FCC_6();
extern "C" void _s801C2FCC_7();
extern "C" void _s801C2FCC_8();
extern "C" void _s801C2FCC_9();
extern "C" void _s801C2FCC_10();
extern "C" void _s801C2FCC_11();
extern "C" void _s801C2FCC_12();
extern "C" void _s801C2FCC_13();
extern "C" void _s801C2FCC_14();
extern "C" void _s801C2FCC_15();
extern "C" void _s801C2FCC_16();
extern "C" void _s801C2FCC_17();
extern "C" void _s801C2FCC_18();
extern "C" void _s801C2FCC_19();
extern "C" void _s801C2FCC_20();
extern "C" void _s801C2FCC_21();
extern "C" void _s801C2FCC_22();
extern "C" void _s801C2FCC_23();
extern "C" void _s801C2FCC_24();
extern "C" void _s801C2FCC_25();
extern "C" void _s801C2FCC_26();
extern "C" void _s801C2FCC_27();
extern "C" void _s801C2FCC_28();
extern "C" void _s801C2FCC_29();
extern "C" void _s801C2FCC_30();
extern "C" void _s801C2FCC_31();
extern "C" void _s801C2FCC_32();
extern "C" void _s801C2FCC_33();
extern "C" void _s801C2FCC_34();
extern "C" void f_801C2FCC() {}
