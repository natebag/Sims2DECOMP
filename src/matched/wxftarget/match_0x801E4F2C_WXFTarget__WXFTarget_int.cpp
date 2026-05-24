// 0x801E4F2C WXFTarget::WXFTarget(int) (3048 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 24,0x40(1); stw 0,0x64(1); lis 9,-32698; mr 31,3; li 30,0; addi 9,9,-12328; stw 9,0x80(31); addi 10,31,40; stw 30,0x0(31); addi 8,31,56; stw 30,0x4(31); addi 7,31,72; stw 30,0x8(31); addi 6,31,88; stw 30,0xc(31); addi 5,31,104; stw 30,0x10(31); lis 11,-32698; stw 30,0x14(31); lis 9,-32698; stw 30,0x18(31); addi 11,11,29504; stw 30,0x8(10); addi 9,9,29528; stw 30,0x28(31); mr 29,4; stw 30,0x8(8); addi 3,31,160; stw 30,0x38(31); stw 30,0x8(7); stw 30,0x48(31); stw 30,0x8(6); stw 30,0x58(31); stw 30,0x8(5); stw 30,0x68(31); stw 30,0x78(31); stw 30,0x88(31); stw 30,0x8c(31); stw 30,0x90(31); stw 11,0x84(31); stw 9,0x80(31); bl _s801E4F2C_0; lis 9,-32705; stw 30,0x130(31); addi 9,9,26016; stw 29,0x94(31); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32708; addi 4,1,24; addi 28,11,-22520; cmpwi 31,0; stw 7,0x18(1); stw 8,0x1c(1); stw 31,0x10(1); beq 0f; addi 3,1,8; li 5,8; bl _s801E4F2C_1; b 1f; 0:; stw 31,0x8(1); 1:; stw 28,0x14(1); addi 11,1,8; lwz 4,0x8(1); lis 9,-32705; lwz 6,0x4(11); addi 9,9,26024; lwz 5,0x8(11); addi 10,31,40; lwz 0,0xc(11); cmpwi 31,0; stw 4,0x28(31); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); mr 25,10; stw 6,0x4(10); lis 9,-32708; stw 5,0x8(10); addi 28,9,-22400; stw 0,0xc(10); addi 4,1,32; mfcr 29; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq 2f; mr 3,30; li 5,8; bl _s801E4F2C_2; b 3f; 2:; stw 31,0x8(1); 3:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,26032; lwz 5,0x8(30); addi 11,31,56; lwz 0,0x4(30); mr 26,11; lwz 10,0xc(30); addi 4,1,40; stw 6,0x38(31); mtcrf 128,29; lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32708; stw 5,0x8(11); addi 28,9,-22280; stw 10,0xc(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq 4f; mr 3,30; li 5,8; bl _s801E4F2C_3; b 5f; 4:; stw 31,0x8(1); 5:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,26040; lwz 5,0x8(30); addi 11,31,72; lwz 0,0x4(30); mr 28,11; lwz 10,0xc(30); addi 4,1,48; stw 6,0x48(31); mtcrf 128,29; lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32708; stw 5,0x8(11); addi 27,9,-22160; stw 10,0xc(11); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq 6f; mr 3,30; li 5,8; bl _s801E4F2C_4; b 7f; 6:; stw 31,0x8(1); 7:; stw 27,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-8840; lwz 5,0x8(30); addi 11,31,88; lwz 0,0x4(30); mr 24,11; lwz 10,0xc(30); addi 4,1,56; stw 6,0x58(31); mtcrf 128,29; lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32708; stw 5,0x8(11); addi 27,9,-22040; stw 10,0xc(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq 8f; mr 3,30; li 5,8; bl _s801E4F2C_5; b 9f; 8:; stw 31,0x8(1); 9:; stw 27,0x14(1); addi 11,31,104; lwz 8,0x8(1); lis 9,-32705; lwz 7,0xc(30); addi 9,9,26048; lwz 10,0x4(30); lwz 6,0x8(30); lwz 0,-31532(13); stw 8,0x68(31); stw 7,0xc(11); cmpwi 0,0; stw 10,0x4(11); stw 6,0x8(11); stw 9,0x7c(31); bne 10f; li 3,16; bl _s801E4F2C_6; bl _s801E4F2C_7; stw 3,-31532(13); 10:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 11f; li 3,16; bl _s801E4F2C_8; bl _s801E4F2C_9; stw 3,-31528(13); 11:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 12f; li 3,16; bl _s801E4F2C_10; bl _s801E4F2C_11; stw 3,-31524(13); 12:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 13f; li 3,16; bl _s801E4F2C_12; bl _s801E4F2C_13; stw 3,-31488(13); 13:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 14f; li 3,16; bl _s801E4F2C_14; bl _s801E4F2C_15; stw 3,-31516(13); 14:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 15f; li 3,16; bl _s801E4F2C_16; bl _s801E4F2C_17; stw 3,-31484(13); 15:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 16f; li 3,16; bl _s801E4F2C_18; bl _s801E4F2C_19; stw 3,-31544(13); 16:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 17f; li 3,32; bl _s801E4F2C_20; bl _s801E4F2C_21; stw 3,-31540(13); 17:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 18f; li 3,120; bl _s801E4F2C_22; bl _s801E4F2C_23; stw 3,-31536(13); 18:; lwz 0,-31536(13); li 9,1; stw 9,0x0(31); li 11,0; stw 0,0x24(31); lwz 9,0x8(24); cmpwi 9,0; bne 19f; lwz 0,0x58(31); cmpwi 0,0; beq 20f; 19:; li 11,1; 20:; cmpwi 11,0; beq 21f; lwz 3,0x10(31); mr 5,24; lwz 6,0x7c(31); li 4,75; bl _s801E4F2C_24; 21:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26060; cmpwi 0,0; beq 22f; lwz 3,0x4(31); mr 5,25; bl _s801E4F2C_25; 22:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26072; cmpwi 0,0; beq 23f; lwz 3,0x4(31); mr 5,25; bl _s801E4F2C_26; 23:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26088; cmpwi 0,0; beq 24f; lwz 3,0x4(31); mr 5,25; bl _s801E4F2C_27; 24:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26108; cmpwi 0,0; beq 25f; lwz 3,0x8(31); mr 5,26; bl _s801E4F2C_28; 25:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26128; cmpwi 0,0; beq 26f; lwz 3,0x8(31); mr 5,26; bl _s801E4F2C_29; 26:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26144; cmpwi 0,0; beq 27f; lwz 3,0x8(31); mr 5,26; bl _s801E4F2C_30; 27:; lwz 0,0x0(31); lwz 4,-28724(13); cmpwi 0,0; beq 28f; lwz 3,0x8(31); mr 5,26; bl _s801E4F2C_31; 28:; lwz 0,0x0(31); lwz 4,-28720(13); cmpwi 0,0; beq 29f; lwz 3,0x8(31); mr 5,26; bl _s801E4F2C_32; 29:; lwz 0,0x0(31); lwz 4,-28716(13); cmpwi 0,0; beq 30f; lwz 3,0x8(31); mr 5,26; bl _s801E4F2C_33; 30:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26160; cmpwi 0,0; beq 31f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_34; 31:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26176; cmpwi 0,0; beq 32f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_35; 32:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26192; cmpwi 0,0; beq 33f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_36; 33:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26208; cmpwi 0,0; beq 34f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_37; 34:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26224; cmpwi 0,0; beq 35f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_38; 35:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26240; cmpwi 0,0; beq 36f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_39; 36:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26256; cmpwi 0,0; beq 37f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_40; 37:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26280; cmpwi 0,0; beq 38f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_41; 38:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26304; cmpwi 0,0; beq 39f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_42; 39:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26328; cmpwi 0,0; beq 40f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_43; 40:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26348; cmpwi 0,0; beq 41f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_44; 41:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26372; cmpwi 0,0; beq 42f; lwz 3,0xc(31); mr 5,28; bl _s801E4F2C_45; 42:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26400; cmpwi 0,0; beq 43f; lwz 3,0x1c(31); cmpwi 3,0; beq 43f; lis 5,32431; lwz 6,0x7c(31); ori 5,5,1729; li 7,0; bl _s801E4F2C_46; 43:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26424; cmpwi 0,0; beq 44f; lwz 3,0x1c(31); cmpwi 3,0; beq 44f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_47; 44:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26436; cmpwi 0,0; beq 45f; lwz 3,0x1c(31); cmpwi 3,0; beq 45f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_48; 45:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26448; cmpwi 0,0; beq 46f; lwz 3,0x1c(31); cmpwi 3,0; beq 46f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_49; 46:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26460; cmpwi 0,0; beq 47f; lwz 3,0x1c(31); cmpwi 3,0; beq 47f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_50; 47:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26472; cmpwi 0,0; beq 48f; lwz 3,0x1c(31); cmpwi 3,0; beq 48f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_51; 48:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26484; cmpwi 0,0; beq 49f; lwz 3,0x1c(31); cmpwi 3,0; beq 49f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_52; 49:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26496; cmpwi 0,0; beq 50f; lwz 3,0x1c(31); cmpwi 3,0; beq 50f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_53; 50:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26508; cmpwi 0,0; beq 51f; lwz 3,0x1c(31); cmpwi 3,0; beq 51f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_54; 51:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26520; cmpwi 0,0; beq 52f; lwz 3,0x1c(31); cmpwi 3,0; beq 52f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_55; 52:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26540; cmpwi 0,0; beq 53f; lwz 3,0x1c(31); cmpwi 3,0; beq 53f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_56; 53:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26560; cmpwi 0,0; beq 54f; lwz 3,0x1c(31); cmpwi 3,0; beq 54f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_57; 54:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26580; cmpwi 0,0; beq 55f; lwz 3,0x1c(31); cmpwi 3,0; beq 55f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_58; 55:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26600; cmpwi 0,0; beq 56f; lwz 3,0x1c(31); cmpwi 3,0; beq 56f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_59; 56:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26620; cmpwi 0,0; beq 57f; lwz 3,0x1c(31); cmpwi 3,0; beq 57f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801E4F2C_60; 57:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26640; cmpwi 0,0; beq 58f; lwz 3,0x24(31); cmpwi 3,0; beq 58f; lis 5,-13521; lwz 6,0x7c(31); ori 5,5,42957; bl _s801E4F2C_61; 58:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26668; cmpwi 0,0; beq 59f; lwz 3,0x24(31); cmpwi 3,0; beq 59f; lis 5,-18377; lwz 6,0x7c(31); ori 5,5,60148; bl _s801E4F2C_62; 59:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26696; cmpwi 0,0; beq 60f; lwz 3,0x24(31); cmpwi 3,0; beq 60f; lis 5,10927; lwz 6,0x7c(31); ori 5,5,62296; bl _s801E4F2C_63; 60:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26720; cmpwi 0,0; beq 61f; lwz 3,0x24(31); cmpwi 3,0; beq 61f; lis 5,14155; lwz 6,0x7c(31); ori 5,5,56554; bl _s801E4F2C_64; 61:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26744; cmpwi 0,0; beq 62f; lwz 3,0x24(31); cmpwi 3,0; beq 62f; lis 5,1162; lwz 6,0x7c(31); ori 5,5,59727; bl _s801E4F2C_65; 62:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26764; cmpwi 0,0; beq 63f; lwz 3,0x24(31); cmpwi 3,0; beq 63f; lis 5,14155; lwz 6,0x7c(31); ori 5,5,56554; bl _s801E4F2C_66; 63:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26784; cmpwi 0,0; beq 64f; lwz 3,0x24(31); cmpwi 3,0; beq 64f; lis 5,10927; lwz 6,0x7c(31); ori 5,5,62296; bl _s801E4F2C_67; 64:; lis 9,-32697; lwz 5,0x94(31); lwz 3,0x5f10(9); li 4,39; bl _s801E4F2C_68; mr 3,31; bl _s801E4F2C_69; lis 4,-32705; li 3,0; addi 4,4,26048; bl _s801E4F2C_70; stw 3,0x98(31); lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 65f; lis 4,-32705; li 3,1; addi 4,4,26048; bl _s801E4F2C_71; stw 3,0x9c(31); b 66f; 65:; stw 0,0x9c(31); 66:; mr 3,31; lwz 0,0x64(1); mtspr 8,0; lmw 24,0x40(1); addi 1,1,96"

extern "C" void _s801E4F2C_0();
extern "C" void _s801E4F2C_1();
extern "C" void _s801E4F2C_2();
extern "C" void _s801E4F2C_3();
extern "C" void _s801E4F2C_4();
extern "C" void _s801E4F2C_5();
extern "C" void _s801E4F2C_6();
extern "C" void _s801E4F2C_7();
extern "C" void _s801E4F2C_8();
extern "C" void _s801E4F2C_9();
extern "C" void _s801E4F2C_10();
extern "C" void _s801E4F2C_11();
extern "C" void _s801E4F2C_12();
extern "C" void _s801E4F2C_13();
extern "C" void _s801E4F2C_14();
extern "C" void _s801E4F2C_15();
extern "C" void _s801E4F2C_16();
extern "C" void _s801E4F2C_17();
extern "C" void _s801E4F2C_18();
extern "C" void _s801E4F2C_19();
extern "C" void _s801E4F2C_20();
extern "C" void _s801E4F2C_21();
extern "C" void _s801E4F2C_22();
extern "C" void _s801E4F2C_23();
extern "C" void _s801E4F2C_24();
extern "C" void _s801E4F2C_25();
extern "C" void _s801E4F2C_26();
extern "C" void _s801E4F2C_27();
extern "C" void _s801E4F2C_28();
extern "C" void _s801E4F2C_29();
extern "C" void _s801E4F2C_30();
extern "C" void _s801E4F2C_31();
extern "C" void _s801E4F2C_32();
extern "C" void _s801E4F2C_33();
extern "C" void _s801E4F2C_34();
extern "C" void _s801E4F2C_35();
extern "C" void _s801E4F2C_36();
extern "C" void _s801E4F2C_37();
extern "C" void _s801E4F2C_38();
extern "C" void _s801E4F2C_39();
extern "C" void _s801E4F2C_40();
extern "C" void _s801E4F2C_41();
extern "C" void _s801E4F2C_42();
extern "C" void _s801E4F2C_43();
extern "C" void _s801E4F2C_44();
extern "C" void _s801E4F2C_45();
extern "C" void _s801E4F2C_46();
extern "C" void _s801E4F2C_47();
extern "C" void _s801E4F2C_48();
extern "C" void _s801E4F2C_49();
extern "C" void _s801E4F2C_50();
extern "C" void _s801E4F2C_51();
extern "C" void _s801E4F2C_52();
extern "C" void _s801E4F2C_53();
extern "C" void _s801E4F2C_54();
extern "C" void _s801E4F2C_55();
extern "C" void _s801E4F2C_56();
extern "C" void _s801E4F2C_57();
extern "C" void _s801E4F2C_58();
extern "C" void _s801E4F2C_59();
extern "C" void _s801E4F2C_60();
extern "C" void _s801E4F2C_61();
extern "C" void _s801E4F2C_62();
extern "C" void _s801E4F2C_63();
extern "C" void _s801E4F2C_64();
extern "C" void _s801E4F2C_65();
extern "C" void _s801E4F2C_66();
extern "C" void _s801E4F2C_67();
extern "C" void _s801E4F2C_68();
extern "C" void _s801E4F2C_69();
extern "C" void _s801E4F2C_70();
extern "C" void _s801E4F2C_71();

struct WXFTarget {
    void WXFTarget();
};

void WXFTarget::WXFTarget() {
}
