// 0x801A4070 CRDTarget::CRDTarget(void) (2008 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; mfcr 12; stmw 26,0x50(1); stw 0,0x6c(1); stw 12,0x4c(1); lis 9,-32698; li 0,0; mr 31,3; addi 9,9,-12328; stw 9,0x80(31); addi 8,31,40; stw 0,0x0(31); addi 9,31,56; stw 0,0x4(31); addi 7,31,72; stw 0,0x8(31); addi 5,31,88; stw 0,0xc(31); addi 4,31,104; stw 0,0x10(31); lis 10,-32698; stw 0,0x14(31); addi 10,10,30880; stw 0,0x18(31); addi 11,31,208; stw 0,0x8(8); li 6,64; stw 0,0x28(31); li 30,1; stw 0,0x8(9); li 3,32; stw 0,0x38(31); lis 9,-32709; stw 0,0x8(7); lis 8,-32705; stw 0,0x48(31); addi 8,8,-8280; stw 0,0x8(5); addi 29,9,25228; stw 0,0x58(31); addi 7,1,24; stw 0,0x8(4); cmpwi 31,0; stw 10,0x80(31); stw 0,0x68(31); stw 0,0x78(31); stw 0,0x84(31); stw 0,0x88(31); stw 0,0x8c(31); stw 0,0x90(31); stw 0,0xd0(31); sth 6,0x10(11); stb 30,0x18(11); stb 3,0x1a(11); stw 0,0x4(11); stw 0,0x8(11); sth 6,0x12(11); stb 0,0x19(11); stb 0,0x1b(11); sth 0,0x14(11); lwz 9,0x0(8); lwz 10,0x4(8); stw 0,0x1c(11); sth 0,0x16(11); stw 9,0x18(1); stw 10,0x1c(1); stw 31,0x10(1); beq 0f; mr 4,7; addi 3,1,8; li 5,8; bl _s801A4070_0; b 1f; 0:; stw 31,0x8(1); 1:; stw 29,0x14(1); addi 11,1,8; lwz 4,0x8(1); lis 9,-32705; lwz 6,0x4(11); addi 9,9,-8272; lwz 5,0x8(11); addi 10,31,40; lwz 0,0xc(11); mr 29,11; stw 4,0x28(31); mr 27,10; lwz 7,0x0(9); lwz 8,0x4(9); addi 4,1,32; stw 6,0x4(10); lis 9,-32709; stw 5,0x8(10); addi 30,9,25348; stw 0,0xc(10); cmpwi 4,31,0; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq cr4,2f; mr 3,29; li 5,8; bl _s801A4070_1; b 3f; 2:; stw 31,0x8(1); 3:; stw 30,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-8264; lwz 5,0x8(29); addi 11,31,56; lwz 0,0x4(29); mr 28,11; lwz 10,0xc(29); addi 4,1,40; stw 6,0x38(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32709; stw 5,0x8(11); addi 30,9,25468; stw 10,0xc(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq cr4,4f; mr 3,29; li 5,8; bl _s801A4070_2; b 5f; 4:; stw 31,0x8(1); 5:; stw 30,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-8256; lwz 5,0x8(29); addi 11,31,72; lwz 10,0x4(29); addi 4,1,48; lwz 0,0xc(29); stw 6,0x48(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 30,9,25588; stw 5,0x8(11); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,6f; mr 3,29; li 5,8; bl _s801A4070_3; b 7f; 6:; stw 31,0x8(1); 7:; stw 30,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-8248; lwz 5,0x8(29); addi 11,31,88; lwz 0,0x4(29); mr 26,11; lwz 10,0xc(29); addi 4,1,56; stw 6,0x58(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32709; stw 5,0x8(11); addi 30,9,25708; stw 10,0xc(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,8f; mr 3,29; li 5,8; bl _s801A4070_4; b 9f; 8:; stw 31,0x8(1); 9:; stw 30,0x14(1); addi 11,31,104; lwz 8,0x8(1); lis 9,-32705; lwz 7,0x4(29); addi 9,9,-8240; lwz 6,0x8(29); lwz 0,0xc(29); lwz 10,-31532(13); stw 8,0x68(31); stw 0,0xc(11); cmpwi 10,0; stw 7,0x4(11); stw 6,0x8(11); stw 9,0x7c(31); bne 10f; li 3,16; bl _s801A4070_5; bl _s801A4070_6; stw 3,-31532(13); 10:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 11f; li 3,16; bl _s801A4070_7; bl _s801A4070_8; stw 3,-31528(13); 11:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 12f; li 3,16; bl _s801A4070_9; bl _s801A4070_10; stw 3,-31524(13); 12:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 13f; li 3,16; bl _s801A4070_11; bl _s801A4070_12; stw 3,-31488(13); 13:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 14f; li 3,16; bl _s801A4070_13; bl _s801A4070_14; stw 3,-31516(13); 14:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 15f; li 3,16; bl _s801A4070_15; bl _s801A4070_16; stw 3,-31484(13); 15:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 16f; li 3,16; bl _s801A4070_17; bl _s801A4070_18; stw 3,-31544(13); 16:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 17f; li 3,32; bl _s801A4070_19; bl _s801A4070_20; stw 3,-31540(13); 17:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 18f; li 3,120; bl _s801A4070_21; bl _s801A4070_22; stw 3,-31536(13); 18:; lwz 0,-31536(13); li 9,1; stw 9,0x0(31); li 11,0; stw 0,0x24(31); lwz 9,0x8(26); cmpwi 9,0; bne 19f; lwz 0,0x58(31); cmpwi 0,0; beq 20f; 19:; li 11,1; 20:; cmpwi 11,0; beq 21f; lwz 3,0x10(31); mr 5,26; lwz 6,0x7c(31); li 4,75; bl _s801A4070_23; 21:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8228; cmpwi 0,0; beq 22f; lwz 3,0x4(31); mr 5,27; bl _s801A4070_24; 22:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8216; cmpwi 0,0; beq 23f; lwz 3,0x4(31); mr 5,27; bl _s801A4070_25; 23:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8196; cmpwi 0,0; beq 24f; lwz 3,0x4(31); mr 5,27; bl _s801A4070_26; 24:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8176; cmpwi 0,0; beq 25f; lwz 3,0x8(31); mr 5,28; bl _s801A4070_27; 25:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8156; cmpwi 0,0; beq 26f; lwz 3,0x8(31); mr 5,28; bl _s801A4070_28; 26:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8136; cmpwi 0,0; beq 27f; lwz 3,0x8(31); mr 5,28; bl _s801A4070_29; 27:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8116; cmpwi 0,0; beq 28f; lwz 3,0x8(31); mr 5,28; bl _s801A4070_30; 28:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8096; cmpwi 0,0; beq 29f; lwz 3,0x8(31); mr 5,28; bl _s801A4070_31; 29:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8080; cmpwi 0,0; beq 30f; lwz 3,0x1c(31); cmpwi 3,0; beq 30f; lis 5,8376; lwz 6,0x7c(31); ori 5,5,17021; li 7,0; bl _s801A4070_32; 30:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8064; cmpwi 0,0; beq 31f; lwz 3,0x1c(31); cmpwi 3,0; beq 31f; lis 5,12351; lwz 6,0x7c(31); ori 5,5,29580; li 7,0; bl _s801A4070_33; 31:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8052; cmpwi 0,0; beq 32f; lwz 3,0x1c(31); cmpwi 3,0; beq 32f; lis 5,-22218; lwz 6,0x7c(31); ori 5,5,8758; li 7,0; bl _s801A4070_34; 32:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8040; cmpwi 0,0; beq 33f; lwz 3,0x1c(31); cmpwi 3,0; beq 33f; lis 5,-8655; lwz 6,0x7c(31); ori 5,5,4768; li 7,0; bl _s801A4070_35; 33:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-8028; cmpwi 0,0; beq 37f; lwz 3,0x1c(31); cmpwi 3,0; beq 34f; lis 5,16469; lwz 6,0x7c(31); ori 5,5,34563; li 7,0; bl _s801A4070_36; 34:; lwz 0,0x0(31); cmpwi 0,0; beq 37f; li 3,16; bl _s801A4070_37; lis 9,-32705; mr 30,3; addi 9,9,-8016; li 0,0; lwz 11,0x0(9); lwz 12,0x4(9); lis 10,-32709; stw 0,0x0(30); addi 4,1,64; stw 11,0x40(1); stw 12,0x44(1); addi 28,10,25828; stw 0,0x8(30); stw 30,0x78(31); stw 31,0x10(1); beq cr4,35f; addi 3,1,8; li 5,8; bl _s801A4070_38; b 36f; 35:; stw 31,0x8(1); 36:; stw 28,0x14(1); lis 4,-32705; lwz 10,0x8(1); addi 4,4,-8008; lwz 0,0xc(29); lwz 9,0x4(29); lwz 11,0x8(29); lwz 3,0x18(31); lwz 5,0x78(31); lwz 6,0x7c(31); stw 0,0xc(30); stw 10,0x0(30); stw 9,0x4(30); stw 11,0x8(30); bl _s801A4070_39; 37:; lis 9,-32705; lis 11,-32705; lis 10,-32705; lfs f12,-7988(9); lfs f0,-7984(11); li 0,0; lfs f13,-7980(10); stfs f0,0xa8(31); stfs f12,0xb4(31); stfs f13,0xac(31); stw 0,0xc0(31); stw 0,0x9c(31); stw 0,0xa0(31); stfs f12,0xa4(31); stw 0,0xc4(31); stw 0,0xcc(31); stw 0,0xf0(31); stw 0,0xf4(31); stw 0,0xb8(31); stw 0,0xb0(31); bl _s801A4070_40; li 4,160; li 5,16; li 6,0; li 7,0; bl _s801A4070_41; bl _s801A4070_42; stw 3,0xc8(31); mr 3,31; lwz 0,0x6c(1); lwz 12,0x4c(1); mtspr 8,0; lmw 26,0x50(1); mtcrf 8,12; addi 1,1,104"
extern "C" void _s801A4070_0();
extern "C" void _s801A4070_1();
extern "C" void _s801A4070_2();
extern "C" void _s801A4070_3();
extern "C" void _s801A4070_4();
extern "C" void _s801A4070_5();
extern "C" void _s801A4070_6();
extern "C" void _s801A4070_7();
extern "C" void _s801A4070_8();
extern "C" void _s801A4070_9();
extern "C" void _s801A4070_10();
extern "C" void _s801A4070_11();
extern "C" void _s801A4070_12();
extern "C" void _s801A4070_13();
extern "C" void _s801A4070_14();
extern "C" void _s801A4070_15();
extern "C" void _s801A4070_16();
extern "C" void _s801A4070_17();
extern "C" void _s801A4070_18();
extern "C" void _s801A4070_19();
extern "C" void _s801A4070_20();
extern "C" void _s801A4070_21();
extern "C" void _s801A4070_22();
extern "C" void _s801A4070_23();
extern "C" void _s801A4070_24();
extern "C" void _s801A4070_25();
extern "C" void _s801A4070_26();
extern "C" void _s801A4070_27();
extern "C" void _s801A4070_28();
extern "C" void _s801A4070_29();
extern "C" void _s801A4070_30();
extern "C" void _s801A4070_31();
extern "C" void _s801A4070_32();
extern "C" void _s801A4070_33();
extern "C" void _s801A4070_34();
extern "C" void _s801A4070_35();
extern "C" void _s801A4070_36();
extern "C" void _s801A4070_37();
extern "C" void _s801A4070_38();
extern "C" void _s801A4070_39();
extern "C" void _s801A4070_40();
extern "C" void _s801A4070_41();
extern "C" void _s801A4070_42();
extern "C" void f_801A4070() {}
