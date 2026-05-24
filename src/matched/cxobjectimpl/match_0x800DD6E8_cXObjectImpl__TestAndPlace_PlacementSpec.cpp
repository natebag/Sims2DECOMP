// 0x800DD6E8 cXObjectImpl::TestAndPlace(PlacementSpec (2456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; mfcr 12; stmw 22,0x48(1); stw 0,0x74(1); stw 12,0x44(1); mr 28,3; mr 27,4; lwz 11,0x4(28); mr 31,5; lwz 25,-21488(13); lwz 9,0x4(11); lwz 0,0x31c(9); lha 3,0x318(9); mtspr 8,0; add 3,11,3; blrl; xori 30,3,2; subfic 0,30,0; adde 30,0,30; lwz 0,0x0(27); cmpwi 0,0; bne 2f; cmpwi 31,0; beq 55f; mr 4,28; addi 3,1,8; bl _s800DD6E8_0; mr 3,28; bl _s800DD6E8_1; mr 3,28; li 4,0; bl _s800DD6E8_2; mr. 11,3; beq 0f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; b 1f; 0:; li 30,0; 1:; cmpwi 30,0; beq 55f; mr 3,30; bl _s800DD6E8_3; mr 3,30; addi 4,1,8; b 54f; 2:; cmpwi 4,31,0; bne cr4,47f; lwz 9,0x0(25); addi 4,27,4; mr 23,4; lha 3,0x68(9); lwz 0,0x6c(9); add 3,25,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; li 0,1; b 9f; 3:; cmpwi 28,0; beq 4f; lwz 9,0x4(28); li 4,2; lwz 3,0x0(9); bl _s800DD6E8_4; mr 31,3; b 5f; 4:; li 31,0; 5:; cmpwi 30,0; li 26,0; mfcr 22; li 24,0; beq 6f; lwz 29,0x0(25); mr 4,23; li 5,1; addi 3,1,8; lha 30,0xf8(29); li 26,1; addi 29,29,248; add 30,25,30; bl _s800DD6E8_5; lwz 0,0x4(29); mr 3,30; addi 4,1,8; mtspr 8,0; blrl; andi. 0,3,16; beq 6f; lwz 9,0x4(31); lwz 0,0x21c(9); lha 3,0x218(9); mtspr 8,0; add 3,31,3; blrl; subfic 0,3,0; adde 24,0,3; 6:; cmpwi 26,0; beq 7f; addi 3,1,8; li 4,2; bl _s800DD6E8_6; 7:; cmpwi 24,0; beq 8f; li 0,1; b 9f; 8:; lwz 9,0x14(27); addi 9,9,-1; cmplwi 9,2; ble 10f; li 0,2; 9:; li 3,0; stw 0,-31888(13); b 56f; 10:; addi 3,28,40; li 4,23; mr 24,3; bl _s800DD6E8_7; lha 0,0x0(3); cmpwi 0,4; bne 11f; mr 3,24; li 4,1; bl _s800DD6E8_8; 11:; lwz 5,0x14(27); mr 4,23; addi 3,1,8; bl _s800DD6E8_9; lwz 3,0x4(28); lwz 9,0x4(3); lha 0,0x368(9); lwz 9,0x36c(9); add 3,3,0; mtspr 8,9; blrl; bl _s800DD6E8_10; cmpwi 3,0; bne 16f; lwz 3,-21432(13); addi 4,1,8; lwz 5,0x4(28); bl _s800DD6E8_11; cmpwi 3,0; beq 16f; lwz 11,0x4(28); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x1c(3); cmpwi 0,1079; beq 16f; lwz 11,0x4(28); li 31,0; lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0xb6(3); andi. 9,0,1; beq 14f; addi 3,1,16; addi 4,1,8; li 5,0; bl _s800DD6E8_12; b 13f; 12:; addi 3,1,16; bl _s800DD6E8_13; 13:; lwz 11,0x14(1); cmpwi 11,0; beq 14f; lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0xb6(3); andi. 9,0,4; beq 12b; li 31,1; 14:; cmpwi 31,0; bne 21f; b 48f; 15:; li 26,1; b 20f; 16:; lwz 11,0x4(28); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0xb6(3); rlwinm 0,0,0,29,30; cmpwi 0,0; beq 21f; lwz 11,0x4(28); li 30,0; lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0xb6(3); andi. 9,0,4; beq 17f; li 30,1; 17:; addi 3,1,16; addi 4,1,8; li 5,0; li 31,0; bl _s800DD6E8_14; li 26,0; lwz 0,0x14(1); cmpwi 0,0; beq 20f; cmpwi 30,0; mfcr 29; 18:; lwz 30,0x14(1); lwz 0,0x4(28); cmpw 30,0; beq 19f; lwz 9,0x4(30); lha 3,0x48(9); lwz 0,0x4c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 19f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0x1c(3); cmpwi 0,1079; beq 19f; li 31,1; mtcrf 128,29; beq 20f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lhz 0,0xb6(3); andi. 9,0,1; bne 15b; 19:; addi 3,1,16; bl _s800DD6E8_15; lwz 0,0x14(1); cmpwi 0,0; bne 18b; 20:; cmpwi 31,0; beq 21f; cmpwi 26,0; beq 48f; 21:; li 4,42; mr 3,24; bl _s800DD6E8_16; lha 31,0x0(3); addi 3,1,8; bl _s800DD6E8_17; cmpwi 3,1; ble 22f; andi. 0,31,4096; beq 22f; li 0,31; b 49f; 22:; mr 3,24; li 4,13; bl _s800DD6E8_18; lha 26,0x0(3); mtcrf 128,22; bne 23f; lwz 9,0x4(27); lwz 10,0x8(27); addi 30,1,32; lwz 29,0x14(27); li 4,1; stw 9,0x20(1); stw 10,0x24(1); mr 3,24; bl _s800DD6E8_19; lha 5,0x0(3); mr 4,29; mr 3,30; mr 6,26; bl _s800DD6E8_20; cmpwi 3,1; beq 23f; addi 3,1,8; b 50f; 23:; andi. 0,31,512; bne 25f; lwz 0,0x14(27); cmpwi 0,1; ble 25f; lwz 9,0x0(25); addi 4,1,8; lha 3,0x98(9); lwz 0,0x9c(9); add 3,25,3; mtspr 8,0; blrl; cmpwi 3,0; beq 25f; lwz 0,0x14(27); cmpwi 0,1; li 0,41; bne 24f; li 0,18; 24:; stw 0,-31888(13); addi 3,1,8; b 50f; 25:; not 0,31; andi. 9,0,1; beq 27f; lwz 9,0x0(25); addi 4,1,8; lha 3,0x98(9); lwz 0,0x9c(9); add 3,25,3; mtspr 8,0; blrl; cmpwi 3,0; bne 27f; lwz 0,0x14(27); cmpwi 0,1; li 0,42; bne 26f; li 0,19; 26:; stw 0,-31888(13); addi 3,1,8; b 50f; 27:; andi. 0,31,2; bne 28f; lwz 0,0x14(27); cmpwi 0,1; bne 28f; lwz 9,0x0(25); addi 4,1,8; lha 3,0x98(9); lwz 0,0x9c(9); add 3,25,3; mtspr 8,0; blrl; cmpwi 3,0; beq 28f; li 0,20; b 49f; 28:; mr 3,24; li 4,30; bl _s800DD6E8_21; lha 29,0x0(3); cmpwi 29,0; beq 31f; addi 30,1,16; lwz 5,0x14(27); mr 4,23; mr 3,30; bl _s800DD6E8_22; lwz 9,0x0(25); mr 4,30; lha 3,0x108(9); lwz 0,0x10c(9); add 3,25,3; mtspr 8,0; blrl; cmpwi 29,1; bne 29f; cmpwi 3,0; bne 29f; li 0,9; mr 3,30; stw 0,-31888(13); li 4,2; bl _s800DD6E8_23; addi 3,1,8; b 50f; 29:; cmpwi 29,2; bne 30f; cmpwi 3,0; beq 30f; li 0,10; mr 3,30; stw 0,-31888(13); li 4,2; bl _s800DD6E8_24; addi 3,1,8; b 50f; 30:; mr 3,30; li 4,2; bl _s800DD6E8_25; 31:; mr 3,24; li 4,4; bl _s800DD6E8_26; lwz 9,0xc(27); lha 22,0x0(3); cmpwi 9,0; bne 33f; lwz 3,0x4(28); mr 4,23; lwz 5,0x14(27); lwz 9,0x4(3); lha 0,0x1b0(9); lwz 9,0x1b4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 32f; addi 3,1,8; b 50f; 32:; li 26,1; b 43f; 33:; lwz 3,0x4(9); lwz 4,0x10(27); lwz 9,0x4(3); lha 0,0x2b8(9); lwz 9,0x2bc(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; li 0,13; beq 49f; lha 0,0x4(31); cmpwi 0,0; beq 34f; lwz 11,0x4(28); lwz 9,0x4(11); lwz 0,0x32c(9); lha 3,0x328(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x4(31); cmpw 0,3; bne 48f; 34:; lwz 11,0xc(27); lwz 26,0x8(31); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x2b0(9); lwz 0,0x2b4(9); add 3,10,3; mtspr 8,0; blrl; addic. 29,3,-1; blt 39f; lis 25,-32706; li 23,11; 35:; lwz 11,0xc(27); mr 4,29; lwz 10,0x4(11); lwz 9,0x4(10); lwz 0,0x2bc(9); lha 3,0x2b8(9); mtspr 8,0; add 3,10,3; blrl; mr 30,3; lwz 0,0x8(30); cmpw 0,26; bne 38f; lha 0,0x4(30); cmpwi 0,0; beq 38f; lwz 11,0x4(28); lwz 9,0x4(11); lwz 0,0x32c(9); lha 3,0x328(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x4(30); cmpw 0,3; beq 38f; lfs f0,0x14(30); lfs f13,-20900(25); fcmpu 0,f0,f13; bne 36f; lfs f0,0x18(30); fcmpu 0,f0,f13; beq 37f; 36:; lfs f0,0x14(31); fcmpu 0,f0,f13; bne 38f; lfs f0,0x18(31); fcmpu 0,f0,f13; bne 38f; 37:; addi 3,1,8; stw 23,-31888(13); b 50f; 38:; addic. 29,29,-1; bge 35b; 39:; lwz 3,0xc(27); li 4,28; addi 3,3,40; bl _s800DD6E8_27; mr 30,3; li 4,27; mr 3,24; bl _s800DD6E8_28; lha 9,0x0(30); lha 0,0x0(3); cmpw 9,0; bge 40f; li 0,14; b 49f; 40:; lwz 9,0xc(27); li 11,0; cmpwi 9,0; beq 41f; lwz 11,0x4(9); 41:; cmpwi 11,0; beq 43f; 42:; lwz 0,0x4(28); cmpw 11,0; beq 48f; lwz 9,0x4(11); lha 3,0x2d0(9); lwz 0,0x2d4(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; bne 42b; 43:; cmpwi 26,0; beq 44f; cmpwi 22,0; bne 45f; 44:; li 0,24; b 49f; 45:; addi 9,26,-1; li 0,1; slw 0,0,9; and. 9,22,0; bne 46f; li 0,24; b 49f; 46:; addi 3,1,8; li 4,2; bl _s800DD6E8_29; 47:; mr 4,27; addi 3,1,8; bl _s800DD6E8_30; mr 3,28; addi 4,1,8; bl _s800DD6E8_31; mr. 11,3; beq 51f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 29,3; b 52f; 48:; li 0,11; 49:; addi 3,1,8; stw 0,-31888(13); 50:; li 4,2; bl _s800DD6E8_32; li 3,0; b 56f; 51:; li 29,0; 52:; beq cr4,55f; cmpw 29,28; beq 55f; cmpwi 29,0; mfcr 31; beq 53f; mr 3,29; bl _s800DD6E8_33; 53:; mr 3,28; addi 4,1,8; bl _s800DD6E8_34; mtcrf 128,31; beq 55f; addi 30,1,40; mr 4,28; mr 3,30; addi 5,1,12; li 6,0; bl _s800DD6E8_35; mr 3,29; mr 4,30; 54:; bl _s800DD6E8_36; 55:; li 3,1; 56:; lwz 0,0x74(1); lwz 12,0x44(1); mtspr 8,0; lmw 22,0x48(1); mtcrf 8,12; addi 1,1,112"

extern "C" void _s800DD6E8_0();
extern "C" void _s800DD6E8_1();
extern "C" void _s800DD6E8_2();
extern "C" void _s800DD6E8_3();
extern "C" void _s800DD6E8_4();
extern "C" void _s800DD6E8_5();
extern "C" void _s800DD6E8_6();
extern "C" void _s800DD6E8_7();
extern "C" void _s800DD6E8_8();
extern "C" void _s800DD6E8_9();
extern "C" void _s800DD6E8_10();
extern "C" void _s800DD6E8_11();
extern "C" void _s800DD6E8_12();
extern "C" void _s800DD6E8_13();
extern "C" void _s800DD6E8_14();
extern "C" void _s800DD6E8_15();
extern "C" void _s800DD6E8_16();
extern "C" void _s800DD6E8_17();
extern "C" void _s800DD6E8_18();
extern "C" void _s800DD6E8_19();
extern "C" void _s800DD6E8_20();
extern "C" void _s800DD6E8_21();
extern "C" void _s800DD6E8_22();
extern "C" void _s800DD6E8_23();
extern "C" void _s800DD6E8_24();
extern "C" void _s800DD6E8_25();
extern "C" void _s800DD6E8_26();
extern "C" void _s800DD6E8_27();
extern "C" void _s800DD6E8_28();
extern "C" void _s800DD6E8_29();
extern "C" void _s800DD6E8_30();
extern "C" void _s800DD6E8_31();
extern "C" void _s800DD6E8_32();
extern "C" void _s800DD6E8_33();
extern "C" void _s800DD6E8_34();
extern "C" void _s800DD6E8_35();
extern "C" void _s800DD6E8_36();

struct cXObjectImpl {
    void TestAndPlace_PlacementSpec();
};

void cXObjectImpl::TestAndPlace_PlacementSpec() {
}
