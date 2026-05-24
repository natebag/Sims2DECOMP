// 0x803326B4 ENgcMemoryCard::CheckAndWriteBannerAndIcon(char (1584 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-192(1); mfspr 0,8; stmw 23,0x9c(1); stw 0,0xc4(1); li 0,0; mr 23,3; mr 25,4; mr 29,5; stw 0,0x94(1); stw 0,0x90(1); bl _s803326B4_0; li 26,0; li 24,0; addi 27,1,144; addi 28,1,148; 0:; mr 3,29; mr 4,27; mr 5,28; bl _s803326B4_1; mr 31,3; cmpwi 31,-7; beq 13f; bgt 2f; cmpwi 31,-12; beq 13f; bgt 1f; cmpwi 31,-14; beq 12f; bgt 11f; cmpwi 31,-128; b 13f; 1:; cmpwi 31,-10; beq 13f; blt 10f; cmpwi 31,-9; beq 10f; cmpwi 31,-8; b 13f; 2:; cmpwi 31,-3; beq 6f; bgt 3f; cmpwi 31,-5; beq 8f; bgt 7f; b 9f; 3:; cmpwi 7,31,-1; beq cr7,14f; blt cr7,5f; cmpwi 31,0; beq 4f; cmpwi 31,1; b 14f; 4:; li 30,1; b 15f; 5:; li 30,-9; b 15f; 6:; cmpwi 7,31,-1; li 30,-1; b 15f; 7:; cmpwi 7,31,-1; li 30,-7; b 15f; 8:; li 0,1; cmpwi 7,31,-1; stw 0,-26380(13); li 30,-8; b 15f; 9:; cmpwi 7,31,-1; li 30,-4; b 15f; 10:; cmpwi 7,31,-1; li 30,-3; b 15f; 11:; cmpwi 7,31,-1; li 30,-6; b 15f; 12:; cmpwi 7,31,-1; li 30,-5; b 15f; 13:; cmpwi 7,31,-1; 14:; li 30,0; 15:; beq cr7,0b; cmpwi 30,1; bne 67f; lis 4,-32692; mr 3,29; addi 4,4,29280; li 5,0; bl _s803326B4_2; mr. 31,3; beq 16f; cmpwi 31,-6; bne 29f; 16:; mr 3,29; bl _s803326B4_3; mr 31,3; cmpwi 31,-7; beq 28f; bgt 18f; cmpwi 31,-12; beq 28f; bgt 17f; cmpwi 31,-14; beq 27f; bgt 26f; cmpwi 31,-128; b 28f; 17:; cmpwi 31,-10; beq 28f; blt 25f; cmpwi 31,-9; beq 25f; cmpwi 31,-8; b 28f; 18:; cmpwi 31,-3; beq 21f; bgt 19f; cmpwi 31,-5; beq 23f; bgt 22f; b 24f; 19:; cmpwi 31,-1; beq 28f; blt 20f; cmpwi 31,0; beq 29f; cmpwi 31,1; b 28f; 20:; li 30,-9; b 29f; 21:; li 30,-1; b 29f; 22:; li 30,-7; b 29f; 23:; stw 30,-26380(13); li 30,-8; b 29f; 24:; li 30,-4; b 29f; 25:; li 30,-3; b 29f; 26:; li 30,-6; b 29f; 27:; li 30,-5; b 29f; 28:; li 30,0; 29:; cmpwi 30,1; bne 67f; mr 4,25; mr 3,29; addi 5,1,8; bl _s803326B4_4; mr 31,3; cmpwi 31,-7; beq 41f; bgt 31f; cmpwi 31,-12; beq 41f; bgt 30f; cmpwi 31,-14; beq 40f; bgt 39f; cmpwi 31,-128; b 41f; 30:; cmpwi 31,-10; beq 41f; blt 38f; cmpwi 31,-9; beq 38f; cmpwi 31,-8; b 41f; 31:; cmpwi 31,-3; beq 34f; bgt 32f; cmpwi 31,-5; beq 36f; bgt 35f; b 37f; 32:; cmpwi 31,-1; beq 41f; blt 33f; cmpwi 31,0; beq 42f; cmpwi 31,1; b 41f; 33:; li 30,-9; b 42f; 34:; li 30,-1; b 42f; 35:; li 30,-7; b 42f; 36:; stw 30,-26380(13); li 30,-8; b 42f; 37:; li 30,-4; b 42f; 38:; li 30,-3; b 42f; 39:; li 30,-6; b 42f; 40:; li 30,-5; b 42f; 41:; li 30,0; 42:; cmpwi 30,1; beq 43f; mr 3,29; bl _s803326B4_5; b 67f; 43:; addi 3,1,32; li 4,0; mr 28,3; li 5,108; bl _s803326B4_6; 44:; lwz 3,0x8(1); mr 5,28; lwz 4,0xc(1); bl _s803326B4_7; cmpwi 3,-1; beq 44b; cmpwi 3,0; beq 45f; mr 3,29; li 30,0; bl _s803326B4_8; b 67f; 45:; lbz 11,0x4e(1); li 10,64; lhz 0,0x54(1); lhz 9,0x56(1); ori 11,11,2; ori 0,0,2; andi. 11,11,250; ori 9,9,3; andi. 0,0,64514; rlwinm 9,9,0,30,27; stw 10,0x50(1); stb 11,0x4e(1); sth 9,0x56(1); stw 3,0x58(1); sth 0,0x54(1); bl _s803326B4_9; li 6,0; li 7,0; li 4,16384; li 5,32; bl _s803326B4_10; mr 26,3; li 4,0; li 5,16384; bl _s803326B4_11; bl _s803326B4_12; li 4,16384; li 5,32; li 6,0; li 7,0; bl _s803326B4_13; lis 9,-32700; mr 24,3; addi 9,9,-4416; mr 11,26; li 10,14400; 46:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 46b; addi 3,1,8; mr 4,24; li 5,16384; li 6,0; bl _s803326B4_14; mr. 31,3; mfcr 30; bge 50f; mr 3,29; bl _s803326B4_15; cmpwi 31,-7; beq 66f; bgt 48f; 47:; cmpwi 31,-12; beq 66f; ble 52f; b 53f; 48:; cmpwi 31,-3; beq 59f; ble 55f; cmpwi 31,-1; beq 66f; blt 58f; mtcrf 128,30; 49:; beq 57f; cmpwi 31,1; b 66f; 50:; mr 3,26; mr 4,24; li 5,16384; bl _s803326B4_16; cmpwi 3,0; beq 51f; addi 3,1,8; mr 4,26; li 5,16384; li 6,0; bl _s803326B4_17; mr. 31,3; mfcr 30; bge 51f; mr 3,29; bl _s803326B4_18; cmpwi 31,-7; beq 66f; ble 47b; b 48b; 51:; lwz 4,0xc(1); mr 5,28; lwz 3,0x8(1); bl _s803326B4_19; mr 3,29; bl _s803326B4_20; mr 31,3; cmpwi 31,-7; beq 66f; bgt 54f; cmpwi 31,-12; beq 66f; bgt 53f; 52:; cmpwi 31,-14; beq 65f; bgt 64f; cmpwi 31,-128; b 66f; 53:; cmpwi 31,-10; beq 66f; blt 63f; cmpwi 31,-9; beq 63f; cmpwi 31,-8; b 66f; 54:; cmpwi 31,-3; beq 59f; bgt 56f; 55:; cmpwi 31,-5; beq 61f; bgt 60f; b 62f; 56:; cmpwi 31,-1; beq 66f; blt 58f; cmpwi 31,0; b 49b; 57:; li 30,1; b 67f; 58:; li 30,-9; b 67f; 59:; li 30,-1; b 67f; 60:; li 30,-7; b 67f; 61:; li 0,1; li 30,-8; stw 0,-26380(13); b 67f; 62:; li 30,-4; b 67f; 63:; li 30,-3; b 67f; 64:; li 30,-6; b 67f; 65:; li 30,-5; b 67f; 66:; li 30,0; 67:; bl _s803326B4_21; mr 4,24; bl _s803326B4_22; bl _s803326B4_23; mr 4,26; bl _s803326B4_24; mr 3,23; bl _s803326B4_25; mr 3,30; lwz 0,0xc4(1); mtspr 8,0; lmw 23,0x9c(1); addi 1,1,192"

extern "C" void _s803326B4_0();
extern "C" void _s803326B4_1();
extern "C" void _s803326B4_2();
extern "C" void _s803326B4_3();
extern "C" void _s803326B4_4();
extern "C" void _s803326B4_5();
extern "C" void _s803326B4_6();
extern "C" void _s803326B4_7();
extern "C" void _s803326B4_8();
extern "C" void _s803326B4_9();
extern "C" void _s803326B4_10();
extern "C" void _s803326B4_11();
extern "C" void _s803326B4_12();
extern "C" void _s803326B4_13();
extern "C" void _s803326B4_14();
extern "C" void _s803326B4_15();
extern "C" void _s803326B4_16();
extern "C" void _s803326B4_17();
extern "C" void _s803326B4_18();
extern "C" void _s803326B4_19();
extern "C" void _s803326B4_20();
extern "C" void _s803326B4_21();
extern "C" void _s803326B4_22();
extern "C" void _s803326B4_23();
extern "C" void _s803326B4_24();
extern "C" void _s803326B4_25();

struct ENgcMemoryCard {
    void CheckAndWriteBannerAndIcon();
};

void ENgcMemoryCard::CheckAndWriteBannerAndIcon() {
}
