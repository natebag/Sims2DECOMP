// 0x801F91A0 KEYTarget::KEYTarget(void) (1636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; mfcr 12; stmw 27,0x44(1); stw 0,0x5c(1); stw 12,0x40(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12328; stw 9,0x80(31); addi 11,31,40; stw 0,0x0(31); addi 9,31,56; stw 0,0x4(31); addi 10,31,72; stw 0,0x8(31); addi 4,31,88; stw 0,0xc(31); lis 6,-32704; stw 0,0x10(31); addi 6,6,-22620; stw 0,0x14(31); addi 5,31,104; stw 0,0x18(31); lis 8,-32698; stw 0,0x8(11); addi 8,8,31672; stw 0,0x28(31); lis 11,-32698; stw 0,0x8(9); addi 11,11,31768; stw 0,0x38(31); lis 9,-32708; stw 0,0x8(10); addi 30,9,-17520; stw 0,0x48(31); cmpwi 31,0; stw 0,0x8(4); stw 0,0x58(31); addi 4,1,24; stw 0,0x8(5); lwz 9,0x0(6); lwz 10,0x4(6); stw 8,0x88(31); stw 11,0x80(31); stw 0,0x8c(31); stw 9,0x18(1); stw 10,0x1c(1); stw 0,0x68(31); stw 0,0x78(31); stw 0,0x84(31); stw 31,0x10(1); beq 0f; addi 3,1,8; li 5,8; bl _s801F91A0_0; b 1f; 0:; stw 31,0x8(1); 1:; stw 30,0x14(1); addi 11,1,8; lwz 4,0x8(1); lis 9,-32704; lwz 6,0x4(11); addi 9,9,-22612; lwz 5,0x8(11); addi 10,31,40; lwz 0,0xc(11); mr 30,11; stw 4,0x28(31); mr 27,10; lwz 7,0x0(9); lwz 8,0x4(9); addi 4,1,32; stw 6,0x4(10); lis 9,-32708; stw 5,0x8(10); addi 29,9,-17400; stw 0,0xc(10); cmpwi 4,31,0; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq cr4,2f; mr 3,30; li 5,8; bl _s801F91A0_1; b 3f; 2:; stw 31,0x8(1); 3:; stw 29,0x14(1); lis 9,-32704; lwz 6,0x8(1); addi 9,9,-32348; lwz 5,0x8(30); addi 11,31,56; lwz 0,0x4(30); mr 28,11; lwz 10,0xc(30); addi 4,1,40; stw 6,0x38(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32708; stw 5,0x8(11); addi 29,9,-17280; stw 10,0xc(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq cr4,4f; mr 3,30; li 5,8; bl _s801F91A0_2; b 5f; 4:; stw 31,0x8(1); 5:; stw 29,0x14(1); lis 9,-32704; lwz 6,0x8(1); addi 9,9,-30788; lwz 5,0x8(30); addi 11,31,72; lwz 10,0x4(30); addi 4,1,48; lwz 0,0xc(30); stw 6,0x48(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 10,0x4(11); addi 29,9,-17160; stw 5,0x8(11); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,6f; mr 3,30; li 5,8; bl _s801F91A0_3; b 7f; 6:; stw 31,0x8(1); 7:; stw 29,0x14(1); lis 9,-32704; lwz 6,0x8(1); addi 9,9,-32332; lwz 5,0x8(30); addi 11,31,88; lwz 10,0x4(30); addi 4,1,56; lwz 0,0xc(30); stw 6,0x58(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 10,0x4(11); addi 29,9,-17040; stw 5,0x8(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,8f; mr 3,30; li 5,8; bl _s801F91A0_4; b 9f; 8:; stw 31,0x8(1); 9:; stw 29,0x14(1); addi 11,31,104; lwz 8,0x8(1); lis 9,-32704; lwz 7,0xc(30); addi 9,9,-22604; lwz 10,0x4(30); lwz 6,0x8(30); lwz 0,-31532(13); stw 8,0x68(31); stw 7,0xc(11); cmpwi 0,0; stw 10,0x4(11); stw 6,0x8(11); stw 9,0x7c(31); bne 10f; li 3,16; bl _s801F91A0_5; bl _s801F91A0_6; stw 3,-31532(13); 10:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 11f; li 3,16; bl _s801F91A0_7; bl _s801F91A0_8; stw 3,-31528(13); 11:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 12f; li 3,16; bl _s801F91A0_9; bl _s801F91A0_10; stw 3,-31524(13); 12:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 13f; li 3,16; bl _s801F91A0_11; bl _s801F91A0_12; stw 3,-31488(13); 13:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 14f; li 3,16; bl _s801F91A0_13; bl _s801F91A0_14; stw 3,-31516(13); 14:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 15f; li 3,16; bl _s801F91A0_15; bl _s801F91A0_16; stw 3,-31484(13); 15:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 16f; li 3,16; bl _s801F91A0_17; bl _s801F91A0_18; stw 3,-31544(13); 16:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 17f; li 3,32; bl _s801F91A0_19; bl _s801F91A0_20; stw 3,-31540(13); 17:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 18f; li 3,120; bl _s801F91A0_21; bl _s801F91A0_22; stw 3,-31536(13); 18:; lwz 0,-31536(13); li 9,1; lis 4,-32704; lwz 3,0x4(31); stw 0,0x24(31); addi 4,4,-22592; stw 9,0x0(31); mr 5,27; bl _s801F91A0_23; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22580; cmpwi 0,0; beq 19f; lwz 3,0x4(31); mr 5,27; bl _s801F91A0_24; 19:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22564; cmpwi 0,0; beq 20f; lwz 3,0x4(31); mr 5,27; bl _s801F91A0_25; 20:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22548; cmpwi 0,0; beq 21f; lwz 3,0x8(31); mr 5,28; bl _s801F91A0_26; 21:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22536; cmpwi 0,0; beq 22f; lwz 3,0x8(31); mr 5,28; bl _s801F91A0_27; 22:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22524; cmpwi 0,0; beq 23f; lwz 3,0x8(31); mr 5,28; bl _s801F91A0_28; 23:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22516; cmpwi 0,0; beq 24f; lwz 3,0x8(31); mr 5,28; bl _s801F91A0_29; 24:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22504; cmpwi 0,0; beq 25f; lwz 3,0x24(31); cmpwi 3,0; beq 25f; lis 5,-13521; lwz 6,0x7c(31); ori 5,5,42957; bl _s801F91A0_30; 25:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22476; cmpwi 0,0; beq 26f; lwz 3,0x24(31); cmpwi 3,0; beq 26f; lis 5,1162; lwz 6,0x7c(31); ori 5,5,59727; bl _s801F91A0_31; 26:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22456; cmpwi 0,0; beq 27f; lwz 3,0x24(31); cmpwi 3,0; beq 27f; lis 5,14155; lwz 6,0x7c(31); ori 5,5,56554; bl _s801F91A0_32; 27:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22432; cmpwi 0,0; beq 28f; lwz 3,0x24(31); cmpwi 3,0; beq 28f; lis 5,28199; lwz 6,0x7c(31); ori 5,5,30903; bl _s801F91A0_33; 28:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22404; cmpwi 0,0; beq 29f; lwz 3,0x24(31); cmpwi 3,0; beq 29f; lis 5,10927; lwz 6,0x7c(31); ori 5,5,62296; bl _s801F91A0_34; 29:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22380; cmpwi 0,0; beq 30f; lwz 3,0x24(31); cmpwi 3,0; beq 30f; lis 5,20190; lwz 6,0x7c(31); ori 5,5,32194; bl _s801F91A0_35; 30:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-22356; cmpwi 0,0; beq 31f; lwz 3,0x24(31); cmpwi 3,0; beq 31f; lis 5,-13004; lwz 6,0x7c(31); ori 5,5,43996; bl _s801F91A0_36; 31:; mr 3,31; lwz 0,0x5c(1); lwz 12,0x40(1); mtspr 8,0; lmw 27,0x44(1); mtcrf 8,12; addi 1,1,88"
extern "C" void _s801F91A0_0();
extern "C" void _s801F91A0_1();
extern "C" void _s801F91A0_2();
extern "C" void _s801F91A0_3();
extern "C" void _s801F91A0_4();
extern "C" void _s801F91A0_5();
extern "C" void _s801F91A0_6();
extern "C" void _s801F91A0_7();
extern "C" void _s801F91A0_8();
extern "C" void _s801F91A0_9();
extern "C" void _s801F91A0_10();
extern "C" void _s801F91A0_11();
extern "C" void _s801F91A0_12();
extern "C" void _s801F91A0_13();
extern "C" void _s801F91A0_14();
extern "C" void _s801F91A0_15();
extern "C" void _s801F91A0_16();
extern "C" void _s801F91A0_17();
extern "C" void _s801F91A0_18();
extern "C" void _s801F91A0_19();
extern "C" void _s801F91A0_20();
extern "C" void _s801F91A0_21();
extern "C" void _s801F91A0_22();
extern "C" void _s801F91A0_23();
extern "C" void _s801F91A0_24();
extern "C" void _s801F91A0_25();
extern "C" void _s801F91A0_26();
extern "C" void _s801F91A0_27();
extern "C" void _s801F91A0_28();
extern "C" void _s801F91A0_29();
extern "C" void _s801F91A0_30();
extern "C" void _s801F91A0_31();
extern "C" void _s801F91A0_32();
extern "C" void _s801F91A0_33();
extern "C" void _s801F91A0_34();
extern "C" void _s801F91A0_35();
extern "C" void _s801F91A0_36();
extern "C" void f_801F91A0() {}
