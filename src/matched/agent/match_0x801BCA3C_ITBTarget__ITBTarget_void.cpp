// 0x801BCA3C ITBTarget::ITBTarget(void) (1612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stmw 25,0x44(1); stw 0,0x64(1); stw 12,0x40(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12328; stw 9,0x80(31); addi 10,31,40; stw 0,0x0(31); addi 6,31,56; stw 0,0x4(31); addi 4,31,72; stw 0,0x8(31); addi 3,31,88; stw 0,0xc(31); lis 9,-32709; stw 0,0x10(31); lis 8,-32705; stw 0,0x14(31); lis 7,-32705; stw 0,0x18(31); addi 8,8,6644; stw 0,0x8(10); addi 5,31,104; stw 0,0x28(31); lis 11,-32698; stw 0,0x8(6); addi 30,9,31596; stw 0,0x38(31); addi 11,11,30056; stw 0,0x8(4); cmpwi 31,0; stw 0,0x48(31); addi 4,1,24; stw 0,0x8(3); stw 0,0x58(31); lfs f0,0x1b00(7); stw 0,0x8(5); lwz 9,0x0(8); lwz 10,0x4(8); stw 11,0x80(31); stw 0,0x98(31); stfs f0,0x9c(31); stw 9,0x18(1); stw 10,0x1c(1); stw 0,0x68(31); stw 0,0x78(31); stw 0,0x84(31); stw 0,0x88(31); stw 0,0x94(31); stw 31,0x10(1); beq 0f; addi 3,1,8; li 5,8; bl _s801BCA3C_0; b 1f; 0:; stw 31,0x8(1); 1:; stw 30,0x14(1); addi 11,1,8; lwz 4,0x8(1); lis 9,-32705; lwz 6,0x4(11); addi 9,9,6652; lwz 5,0x8(11); addi 10,31,40; lwz 0,0xc(11); mr 30,11; stw 4,0x28(31); mr 26,10; lwz 7,0x0(9); lwz 8,0x4(9); addi 4,1,32; stw 6,0x4(10); lis 9,-32709; stw 5,0x8(10); addi 29,9,31716; stw 0,0xc(10); cmpwi 4,31,0; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq cr4,2f; mr 3,30; li 5,8; bl _s801BCA3C_1; b 3f; 2:; stw 31,0x8(1); 3:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,6660; lwz 5,0x8(30); addi 11,31,56; lwz 0,0x4(30); mr 28,11; lwz 10,0xc(30); addi 4,1,40; stw 6,0x38(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32709; stw 5,0x8(11); addi 29,9,31836; stw 10,0xc(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq cr4,4f; mr 3,30; li 5,8; bl _s801BCA3C_2; b 5f; 4:; stw 31,0x8(1); 5:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,6668; lwz 5,0x8(30); addi 11,31,72; lwz 0,0x4(30); mr 25,11; lwz 10,0xc(30); addi 4,1,48; stw 6,0x48(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32709; stw 5,0x8(11); addi 29,9,31956; stw 10,0xc(11); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,6f; mr 3,30; li 5,8; bl _s801BCA3C_3; b 7f; 6:; stw 31,0x8(1); 7:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-8840; lwz 5,0x8(30); addi 11,31,88; lwz 0,0x4(30); mr 27,11; lwz 10,0xc(30); addi 4,1,56; stw 6,0x58(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32709; stw 5,0x8(11); addi 29,9,32076; stw 10,0xc(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,8f; mr 3,30; li 5,8; bl _s801BCA3C_4; b 9f; 8:; stw 31,0x8(1); 9:; stw 29,0x14(1); addi 11,31,104; lwz 8,0x8(1); lis 9,-32705; lwz 7,0xc(30); addi 9,9,6676; lwz 10,0x4(30); lwz 6,0x8(30); lwz 0,-31532(13); stw 8,0x68(31); stw 7,0xc(11); cmpwi 0,0; stw 10,0x4(11); stw 6,0x8(11); stw 9,0x7c(31); bne 10f; li 3,16; bl _s801BCA3C_5; bl _s801BCA3C_6; stw 3,-31532(13); 10:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 11f; li 3,16; bl _s801BCA3C_7; bl _s801BCA3C_8; stw 3,-31528(13); 11:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 12f; li 3,16; bl _s801BCA3C_9; bl _s801BCA3C_10; stw 3,-31524(13); 12:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 13f; li 3,16; bl _s801BCA3C_11; bl _s801BCA3C_12; stw 3,-31488(13); 13:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 14f; li 3,16; bl _s801BCA3C_13; bl _s801BCA3C_14; stw 3,-31516(13); 14:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 15f; li 3,16; bl _s801BCA3C_15; bl _s801BCA3C_16; stw 3,-31484(13); 15:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 16f; li 3,16; bl _s801BCA3C_17; bl _s801BCA3C_18; stw 3,-31544(13); 16:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 17f; li 3,32; bl _s801BCA3C_19; bl _s801BCA3C_20; stw 3,-31540(13); 17:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 18f; li 3,120; bl _s801BCA3C_21; bl _s801BCA3C_22; stw 3,-31536(13); 18:; lwz 0,-31536(13); li 9,1; stw 9,0x0(31); li 11,0; stw 0,0x24(31); lwz 9,0x8(27); cmpwi 9,0; bne 19f; lwz 0,0x58(31); cmpwi 0,0; beq 20f; 19:; li 11,1; 20:; cmpwi 11,0; beq 21f; lwz 3,0x10(31); mr 5,27; lwz 6,0x7c(31); li 4,75; bl _s801BCA3C_23; 21:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6688; cmpwi 0,0; beq 22f; lwz 3,0x4(31); mr 5,26; bl _s801BCA3C_24; 22:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6700; cmpwi 0,0; beq 23f; lwz 3,0x8(31); mr 5,28; bl _s801BCA3C_25; 23:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6720; cmpwi 0,0; beq 24f; lwz 3,0x8(31); mr 5,28; bl _s801BCA3C_26; 24:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6748; cmpwi 0,0; beq 25f; lwz 3,0x8(31); mr 5,28; bl _s801BCA3C_27; 25:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6780; cmpwi 0,0; beq 26f; lwz 3,0x8(31); mr 5,28; bl _s801BCA3C_28; 26:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6804; cmpwi 0,0; beq 27f; lwz 3,0x8(31); mr 5,28; bl _s801BCA3C_29; 27:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6832; cmpwi 0,0; beq 28f; lwz 3,0xc(31); mr 5,25; bl _s801BCA3C_30; 28:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6844; cmpwi 0,0; beq 29f; lwz 3,0x1c(31); cmpwi 3,0; beq 29f; lis 5,25496; lwz 6,0x7c(31); ori 5,5,20865; li 7,0; bl _s801BCA3C_31; 29:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6860; cmpwi 0,0; beq 30f; lwz 3,0x1c(31); cmpwi 3,0; beq 30f; lis 5,5857; lwz 6,0x7c(31); ori 5,5,21012; li 7,0; bl _s801BCA3C_32; 30:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,6880; cmpwi 0,0; beq 31f; lwz 3,0x1c(31); cmpwi 3,0; beq 31f; lis 5,5857; lwz 6,0x7c(31); ori 5,5,21012; li 7,0; bl _s801BCA3C_33; 31:; bl _s801BCA3C_34; li 5,0; li 4,4; bl _s801BCA3C_35; bl _s801BCA3C_36; mr 0,3; lis 4,-32705; addi 4,4,6900; stw 0,0x8c(31); bl _s801BCA3C_37; li 0,0; lis 9,-32697; stw 0,0x90(31); li 4,65; li 5,0; lwz 3,0x5f10(9); bl _s801BCA3C_38; mr 3,31; lwz 0,0x64(1); lwz 12,0x40(1); mtspr 8,0; lmw 25,0x44(1); mtcrf 8,12; addi 1,1,96"
extern "C" void _s801BCA3C_0();
extern "C" void _s801BCA3C_1();
extern "C" void _s801BCA3C_2();
extern "C" void _s801BCA3C_3();
extern "C" void _s801BCA3C_4();
extern "C" void _s801BCA3C_5();
extern "C" void _s801BCA3C_6();
extern "C" void _s801BCA3C_7();
extern "C" void _s801BCA3C_8();
extern "C" void _s801BCA3C_9();
extern "C" void _s801BCA3C_10();
extern "C" void _s801BCA3C_11();
extern "C" void _s801BCA3C_12();
extern "C" void _s801BCA3C_13();
extern "C" void _s801BCA3C_14();
extern "C" void _s801BCA3C_15();
extern "C" void _s801BCA3C_16();
extern "C" void _s801BCA3C_17();
extern "C" void _s801BCA3C_18();
extern "C" void _s801BCA3C_19();
extern "C" void _s801BCA3C_20();
extern "C" void _s801BCA3C_21();
extern "C" void _s801BCA3C_22();
extern "C" void _s801BCA3C_23();
extern "C" void _s801BCA3C_24();
extern "C" void _s801BCA3C_25();
extern "C" void _s801BCA3C_26();
extern "C" void _s801BCA3C_27();
extern "C" void _s801BCA3C_28();
extern "C" void _s801BCA3C_29();
extern "C" void _s801BCA3C_30();
extern "C" void _s801BCA3C_31();
extern "C" void _s801BCA3C_32();
extern "C" void _s801BCA3C_33();
extern "C" void _s801BCA3C_34();
extern "C" void _s801BCA3C_35();
extern "C" void _s801BCA3C_36();
extern "C" void _s801BCA3C_37();
extern "C" void _s801BCA3C_38();
extern "C" void f_801BCA3C() {}
