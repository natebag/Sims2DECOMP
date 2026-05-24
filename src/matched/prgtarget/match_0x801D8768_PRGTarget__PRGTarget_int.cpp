// 0x801D8768 PRGTarget::PRGTarget(int) (2352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stmw 26,0x48(1); stw 0,0x64(1); stw 12,0x44(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12328; stw 9,0x80(31); addi 10,31,40; stw 0,0x0(31); addi 7,31,56; stw 0,0x4(31); addi 5,31,72; stw 0,0x8(31); addi 3,31,88; stw 0,0xc(31); lis 9,-32708; stw 0,0x10(31); lis 8,-32705; stw 0,0x14(31); addi 8,8,18700; stw 0,0x18(31); addi 6,31,104; stw 0,0x8(10); lis 11,-32698; stw 0,0x28(31); addi 30,9,-26240; stw 0,0x8(7); addi 11,11,29440; stw 0,0x38(31); addi 7,1,24; stw 0,0x8(5); cmpwi 31,0; stw 0,0x48(31); stw 0,0x8(3); stw 0,0x58(31); stw 0,0x8(6); lwz 9,0x0(8); lwz 10,0x4(8); stw 11,0x80(31); stw 0,0x84(31); stw 4,0x88(31); stw 9,0x18(1); stw 10,0x1c(1); stw 0,0x68(31); stw 0,0x78(31); stw 31,0x10(1); beq 0f; mr 4,7; addi 3,1,8; li 5,8; bl _s801D8768_0; b 1f; 0:; stw 31,0x8(1); 1:; stw 30,0x14(1); addi 11,1,8; lwz 4,0x8(1); lis 9,-32705; lwz 6,0x4(11); addi 9,9,18708; lwz 5,0x8(11); addi 10,31,40; lwz 0,0xc(11); mr 29,11; stw 4,0x28(31); mr 26,10; lwz 7,0x0(9); lwz 8,0x4(9); addi 4,1,32; stw 6,0x4(10); lis 9,-32708; stw 5,0x8(10); addi 30,9,-26120; stw 0,0xc(10); cmpwi 4,31,0; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq cr4,2f; mr 3,29; li 5,8; bl _s801D8768_1; b 3f; 2:; stw 31,0x8(1); 3:; stw 30,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,18716; lwz 5,0x8(29); addi 11,31,56; lwz 0,0x4(29); mr 27,11; lwz 10,0xc(29); addi 4,1,40; stw 6,0x38(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32708; stw 5,0x8(11); addi 30,9,-26000; stw 10,0xc(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq cr4,4f; mr 3,29; li 5,8; bl _s801D8768_2; b 5f; 4:; stw 31,0x8(1); 5:; stw 30,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,7192; lwz 5,0x8(29); addi 11,31,72; lwz 0,0x4(29); mr 30,11; lwz 10,0xc(29); addi 4,1,48; stw 6,0x48(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32708; stw 5,0x8(11); addi 28,9,-25880; stw 10,0xc(11); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,6f; mr 3,29; li 5,8; bl _s801D8768_3; b 7f; 6:; stw 31,0x8(1); 7:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-8840; lwz 5,0x8(29); addi 11,31,88; lwz 10,0x4(29); addi 4,1,56; lwz 0,0xc(29); stw 6,0x58(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 10,0x4(11); addi 28,9,-25760; stw 5,0x8(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,8f; mr 3,29; li 5,8; bl _s801D8768_4; b 9f; 8:; stw 31,0x8(1); 9:; stw 28,0x14(1); addi 11,31,104; lwz 8,0x8(1); lis 9,-32705; lwz 7,0xc(29); addi 9,9,18724; lwz 10,0x4(29); lwz 6,0x8(29); lwz 0,-31532(13); stw 8,0x68(31); stw 7,0xc(11); cmpwi 0,0; stw 10,0x4(11); stw 6,0x8(11); stw 9,0x7c(31); bne 10f; li 3,16; bl _s801D8768_5; bl _s801D8768_6; stw 3,-31532(13); 10:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 11f; li 3,16; bl _s801D8768_7; bl _s801D8768_8; stw 3,-31528(13); 11:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 12f; li 3,16; bl _s801D8768_9; bl _s801D8768_10; stw 3,-31524(13); 12:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 13f; li 3,16; bl _s801D8768_11; bl _s801D8768_12; stw 3,-31488(13); 13:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 14f; li 3,16; bl _s801D8768_13; bl _s801D8768_14; stw 3,-31516(13); 14:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 15f; li 3,16; bl _s801D8768_15; bl _s801D8768_16; stw 3,-31484(13); 15:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 16f; li 3,16; bl _s801D8768_17; bl _s801D8768_18; stw 3,-31544(13); 16:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 17f; li 3,32; bl _s801D8768_19; bl _s801D8768_20; stw 3,-31540(13); 17:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 18f; li 3,120; bl _s801D8768_21; bl _s801D8768_22; stw 3,-31536(13); 18:; lwz 0,-31536(13); li 9,1; lis 4,-32705; lwz 3,0x4(31); stw 0,0x24(31); addi 4,4,18736; stw 9,0x0(31); mr 5,26; bl _s801D8768_23; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18748; cmpwi 0,0; beq 19f; lwz 3,0x8(31); mr 5,27; bl _s801D8768_24; 19:; lwz 0,0x0(31); lwz 4,-29700(13); cmpwi 0,0; beq 20f; lwz 3,0x8(31); mr 5,27; bl _s801D8768_25; 20:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18768; cmpwi 0,0; beq 21f; lwz 3,0x8(31); mr 5,27; bl _s801D8768_26; 21:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18780; cmpwi 0,0; beq 22f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_27; 22:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18792; cmpwi 0,0; beq 23f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_28; 23:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18816; cmpwi 0,0; beq 24f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_29; 24:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18840; cmpwi 0,0; beq 25f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_30; 25:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18860; cmpwi 0,0; beq 26f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_31; 26:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18880; cmpwi 0,0; beq 27f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_32; 27:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18896; cmpwi 0,0; beq 28f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_33; 28:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18912; cmpwi 0,0; beq 29f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_34; 29:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18936; cmpwi 0,0; beq 30f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_35; 30:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18952; cmpwi 0,0; beq 31f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_36; 31:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18968; cmpwi 0,0; beq 32f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_37; 32:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18992; cmpwi 0,0; beq 33f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_38; 33:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19008; cmpwi 0,0; beq 34f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_39; 34:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19024; cmpwi 0,0; beq 35f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_40; 35:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19048; cmpwi 0,0; beq 36f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_41; 36:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19064; cmpwi 0,0; beq 37f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_42; 37:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19080; cmpwi 0,0; beq 38f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_43; 38:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19104; cmpwi 0,0; beq 39f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_44; 39:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19120; cmpwi 0,0; beq 40f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_45; 40:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19136; cmpwi 0,0; beq 41f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_46; 41:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19160; cmpwi 0,0; beq 42f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_47; 42:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19176; cmpwi 0,0; beq 43f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_48; 43:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19192; cmpwi 0,0; beq 44f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_49; 44:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19216; cmpwi 0,0; beq 45f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_50; 45:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19232; cmpwi 0,0; beq 46f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_51; 46:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19248; cmpwi 0,0; beq 47f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_52; 47:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19272; cmpwi 0,0; beq 48f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_53; 48:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19288; cmpwi 0,0; beq 49f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_54; 49:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19304; cmpwi 0,0; beq 50f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_55; 50:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19328; cmpwi 0,0; beq 51f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_56; 51:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19344; cmpwi 0,0; beq 52f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_57; 52:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19360; cmpwi 0,0; beq 53f; lwz 3,0xc(31); mr 5,30; bl _s801D8768_58; 53:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,19384; cmpwi 0,0; beq 54f; lwz 3,0x24(31); cmpwi 3,0; beq 54f; lis 5,10927; lwz 6,0x7c(31); ori 5,5,62296; bl _s801D8768_59; 54:; lis 9,-32697; lwz 5,0x88(31); lwz 3,0x5f10(9); li 4,40; bl _s801D8768_60; lis 4,-32705; li 3,0; addi 4,4,18724; bl _s801D8768_61; stw 3,0x8c(31); lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 55f; lis 4,-32705; li 3,1; addi 4,4,18724; bl _s801D8768_62; stw 3,0x90(31); b 56f; 55:; stw 0,0x90(31); 56:; mr 3,31; lwz 0,0x64(1); lwz 12,0x44(1); mtspr 8,0; lmw 26,0x48(1); mtcrf 8,12; addi 1,1,96"

extern "C" void _s801D8768_0();
extern "C" void _s801D8768_1();
extern "C" void _s801D8768_2();
extern "C" void _s801D8768_3();
extern "C" void _s801D8768_4();
extern "C" void _s801D8768_5();
extern "C" void _s801D8768_6();
extern "C" void _s801D8768_7();
extern "C" void _s801D8768_8();
extern "C" void _s801D8768_9();
extern "C" void _s801D8768_10();
extern "C" void _s801D8768_11();
extern "C" void _s801D8768_12();
extern "C" void _s801D8768_13();
extern "C" void _s801D8768_14();
extern "C" void _s801D8768_15();
extern "C" void _s801D8768_16();
extern "C" void _s801D8768_17();
extern "C" void _s801D8768_18();
extern "C" void _s801D8768_19();
extern "C" void _s801D8768_20();
extern "C" void _s801D8768_21();
extern "C" void _s801D8768_22();
extern "C" void _s801D8768_23();
extern "C" void _s801D8768_24();
extern "C" void _s801D8768_25();
extern "C" void _s801D8768_26();
extern "C" void _s801D8768_27();
extern "C" void _s801D8768_28();
extern "C" void _s801D8768_29();
extern "C" void _s801D8768_30();
extern "C" void _s801D8768_31();
extern "C" void _s801D8768_32();
extern "C" void _s801D8768_33();
extern "C" void _s801D8768_34();
extern "C" void _s801D8768_35();
extern "C" void _s801D8768_36();
extern "C" void _s801D8768_37();
extern "C" void _s801D8768_38();
extern "C" void _s801D8768_39();
extern "C" void _s801D8768_40();
extern "C" void _s801D8768_41();
extern "C" void _s801D8768_42();
extern "C" void _s801D8768_43();
extern "C" void _s801D8768_44();
extern "C" void _s801D8768_45();
extern "C" void _s801D8768_46();
extern "C" void _s801D8768_47();
extern "C" void _s801D8768_48();
extern "C" void _s801D8768_49();
extern "C" void _s801D8768_50();
extern "C" void _s801D8768_51();
extern "C" void _s801D8768_52();
extern "C" void _s801D8768_53();
extern "C" void _s801D8768_54();
extern "C" void _s801D8768_55();
extern "C" void _s801D8768_56();
extern "C" void _s801D8768_57();
extern "C" void _s801D8768_58();
extern "C" void _s801D8768_59();
extern "C" void _s801D8768_60();
extern "C" void _s801D8768_61();
extern "C" void _s801D8768_62();

struct PRGTarget {
    void PRGTarget();
};

void PRGTarget::PRGTarget() {
}
