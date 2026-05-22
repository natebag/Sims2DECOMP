// 0x80299970 AptDisplayList::instantiateCharacter(int, (2100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 17,0x1c(1); stw 0,0x5c(1); mr 23,3; mr 26,6; lwz 3,0x0(23); mr 22,4; mr 25,5; mr 28,7; mr 31,8; mr 20,9; mr 19,10; mr 5,26; addi 6,1,16; addi 7,1,20; li 21,0; bl _s80299970_0; li 27,0; lwz 3,0x14(1); cmpwi 3,0; beq 5f; cmpwi 31,0; beq 0f; bl _s80299970_1; lwz 4,0x14(1); mr 3,23; bl _s80299970_2; stw 21,0x14(1); b 5f; 0:; lwz 0,0x0(3); andis. 9,0,2048; bne 4f; cmpwi 26,0; beq 5f; lwz 4,0xc(3); lwz 3,0x0(26); lhz 0,0x2(4); lhz 5,0x2(3); cmpw 5,0; beq 1f; li 3,0; b 3f; 1:; cmpw 3,4; bne 2f; li 3,1; b 3f; 2:; addi 3,3,8; addi 4,4,8; bl _s80299970_3; subfic 0,3,0; adde 3,0,3; 3:; cmpwi 3,0; beq 5f; lwz 9,0x14(1); lwz 0,0x0(9); oris 0,0,2048; stw 0,0x0(9); lwz 27,0x14(1); b 5f; 4:; mr 27,3; b 6f; 5:; li 21,1; 6:; cmpwi 21,0; lis 17,-32704; lis 18,-32704; beq 41f; lwz 0,0x0(25); li 31,0; li 24,13; cmpwi 0,5; bne 7f; lwz 3,-23020(13); li 4,48; bl _s80299970_4; mr 30,3; mr 31,30; bl _s80299970_5; lis 9,-32704; li 11,-1; addi 9,9,30368; stw 9,0x14(30); stw 11,0x18(31); lwz 0,0x1c(31); ori 0,0,192; stw 0,0x1c(31); b 13f; 7:; cmpwi 0,4; bne 8f; lwz 3,-23020(13); li 4,32; li 29,0; li 24,14; bl _s80299970_6; mr 30,3; lis 9,-32702; addi 9,9,-13024; li 0,-1; stw 31,0xc(30); addi 3,30,28; stw 31,0x10(30); stw 31,0x8(30); stw 0,0x0(30); mr 31,30; stw 9,0x14(30); bl _s80299970_7; lwz 3,-23020(13); li 4,20; bl _s80299970_8; li 4,4; bl _s80299970_9; stw 3,0xc(30); stw 29,0x18(31); b 13f; 8:; cmpwi 0,2; bne 9f; lwz 3,-23020(13); li 4,120; li 24,15; bl _s80299970_10; bl _s80299970_11; mr 31,3; stw 25,0x8(31); lwz 0,0x20(25); stw 0,0x24(31); lfs f0,0x24(25); stfs f0,0x60(31); lwz 0,0x1c(25); stw 0,0x3c(31); lwz 9,0x18(25); stw 9,0x64(31); lfs f0,0x14(25); stfs f0,0x5c(31); lfs f13,0x8(25); stfs f13,0x50(31); lfs f0,0x10(25); stfs f0,0x58(31); lfs f13,0xc(25); stfs f13,0x54(31); b 13f; 9:; cmpwi 0,10; bne 10f; lwz 3,-23020(13); li 4,24; li 24,16; bl _s80299970_12; lis 9,-32704; stw 31,0xc(3); addi 9,9,30448; stw 31,0x10(3); li 0,-1; b 12f; 10:; cmpwi 0,1; bne 11f; lwz 3,-23020(13); li 4,24; li 24,12; bl _s80299970_13; lis 9,-32704; stw 31,0xc(3); addi 9,9,30488; stw 31,0x10(3); li 0,-1; b 12f; 11:; cmpwi 0,8; bne 13f; lwz 3,-23020(13); li 4,28; li 24,17; bl _s80299970_14; lis 9,-32704; li 0,-1; addi 9,9,30408; stw 31,0xc(3); stw 31,0x10(3); 12:; stw 31,0x8(3); stw 0,0x0(3); mr 31,3; stw 9,0x14(3); 13:; mr 3,28; li 29,0; bl _s80299970_15; li 30,0; cmpwi 3,13; bne 14f; mr 3,28; bl _s80299970_16; subfic 0,3,0; adde 30,0,3; 14:; cmpwi 30,0; bne 16f; mr 3,28; li 30,0; bl _s80299970_17; cmpwi 3,18; bne 15f; mr 3,28; bl _s80299970_18; subfic 0,3,0; adde 30,0,3; 15:; cmpwi 30,0; beq 17f; 16:; li 29,1; 17:; cmpwi 29,0; beq 18f; lwz 9,0x4c(28); lwz 0,0x18(9); b 19f; 18:; li 0,-1; 19:; stw 0,0x4(31); cmpwi 27,0; bne 20f; lwz 3,0x0(23); mr 4,22; mr 5,24; mr 6,31; bl _s80299970_19; lis 17,-32704; mr 27,3; lis 18,-32704; b 22f; 20:; lwz 0,0x58(27); lis 17,-32704; lis 18,-32704; srawi 0,0,15; cmpw 22,0; beq 21f; mr 3,27; bl _s80299970_20; lwz 3,0x0(23); mr 4,22; mr 5,27; bl _s80299970_21; lwz 9,0x8(27); addi 4,17,29904; addi 5,18,29796; li 6,727; lha 3,0x10(9); lwz 0,0x14(9); add 3,27,3; mtspr 8,0; blrl; 21:; stw 31,0x4c(27); 22:; mr 3,28; li 29,0; bl _s80299970_22; li 30,0; cmpwi 3,13; bne 23f; mr 3,28; bl _s80299970_23; subfic 0,3,0; adde 30,0,3; 23:; cmpwi 30,0; bne 25f; mr 3,28; li 30,0; bl _s80299970_24; cmpwi 3,18; bne 24f; mr 3,28; bl _s80299970_25; subfic 0,3,0; adde 30,0,3; 24:; cmpwi 30,0; beq 26f; 25:; li 29,1; 26:; cmpwi 29,0; beq 27f; lwz 9,0x4(31); lwz 0,0x58(27); rlwimi 0,9,1,17,30; b 28f; 27:; lwz 0,0x58(27); ori 0,0,32766; 28:; stw 0,0x58(27); cmpwi 26,0; beq 31f; lwz 11,0x0(26); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(27); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 29f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80299970_26; 29:; lwz 0,0x0(26); lis 9,-32700; addi 9,9,-6476; stw 0,0xc(27); lwz 11,0x0(26); cmpw 11,9; beq 31f; lwz 9,0x4c(28); mr 4,26; lwz 3,0xc(9); bl _s80299970_27; mr. 3,3; beq 30f; lwz 9,0x0(3); rlwinm 9,9,0,25,31; addi 9,9,-12; cmplwi 9,7; ble 31f; 30:; lwz 9,0x4c(28); mr 4,26; mr 5,27; lwz 3,0xc(9); bl _s80299970_28; 31:; addi 0,24,-13; cmplwi 0,1; bgt 32f; lwz 10,-23008(13); lis 4,-32704; lis 5,-32704; addi 4,4,29904; lwz 11,0x4(10); addi 5,5,29796; lwz 8,0x0(10); li 6,761; rlwinm 9,11,2,0,29; stwx 27,9,8; addi 11,11,1; stw 11,0x4(10); lwz 9,0x8(27); lha 3,0x8(9); lwz 0,0xc(9); add 3,27,3; mtspr 8,0; blrl; b 41f; 32:; cmpwi 24,15; bne 41f; lwz 31,0x4c(27); lwz 9,0x8(31); lwz 4,0x34(9); cmpwi 4,0; beq 34f; addi 0,1,8; mr 3,0; mr 30,0; bl _s80299970_29; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x18(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 33f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80299970_30; 33:; lwz 0,0x8(1); stw 0,0x18(31); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 36f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80299970_31; b 36f; 34:; addi 30,1,8; lis 4,-32704; addi 4,4,29200; mr 3,30; bl _s80299970_32; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x18(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 35f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80299970_33; 35:; lwz 0,0x8(1); stw 0,0x18(31); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 36f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80299970_34; 36:; lwz 9,0x8(31); lwz 4,0x38(9); cmpwi 4,0; beq 38f; mr 3,30; bl _s80299970_35; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x1c(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 37f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80299970_36; 37:; lwz 0,0x8(1); stw 0,0x1c(31); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 40f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80299970_37; b 40f; 38:; lis 4,-32704; mr 3,30; addi 4,4,29200; bl _s80299970_38; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x1c(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 39f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80299970_39; 39:; lwz 0,0x8(1); stw 0,0x1c(31); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 40f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80299970_40; 40:; mr 3,31; mr 4,28; bl _s80299970_41; li 0,6; stw 0,0x6c(31); 41:; lwz 9,0x8(28); lis 4,-32704; lis 5,-32704; addi 4,4,29904; lha 3,0x8(9); addi 5,5,29796; lwz 0,0xc(9); li 6,785; add 3,28,3; mtspr 8,0; blrl; lwz 11,0x48(27); cmpwi 11,0; beq 42f; lwz 9,0x8(11); addi 4,17,29904; addi 5,18,29796; li 6,786; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 42:; lwz 9,0x4c(27); stw 28,0x48(27); stw 25,0x8(9); lwz 11,0x4c(27); stw 20,0x0(11); lwz 0,0x0(25); cmpwi 0,4; bne 43f; mr 3,27; li 4,1; bl _s80299970_42; 43:; stw 27,0x0(19); lwz 9,0x60(1); stw 21,0x0(9); lwz 0,0x5c(1); mtspr 8,0; lmw 17,0x1c(1); addi 1,1,88"
extern "C" void _s80299970_0();
extern "C" void _s80299970_1();
extern "C" void _s80299970_2();
extern "C" void _s80299970_3();
extern "C" void _s80299970_4();
extern "C" void _s80299970_5();
extern "C" void _s80299970_6();
extern "C" void _s80299970_7();
extern "C" void _s80299970_8();
extern "C" void _s80299970_9();
extern "C" void _s80299970_10();
extern "C" void _s80299970_11();
extern "C" void _s80299970_12();
extern "C" void _s80299970_13();
extern "C" void _s80299970_14();
extern "C" void _s80299970_15();
extern "C" void _s80299970_16();
extern "C" void _s80299970_17();
extern "C" void _s80299970_18();
extern "C" void _s80299970_19();
extern "C" void _s80299970_20();
extern "C" void _s80299970_21();
extern "C" void _s80299970_22();
extern "C" void _s80299970_23();
extern "C" void _s80299970_24();
extern "C" void _s80299970_25();
extern "C" void _s80299970_26();
extern "C" void _s80299970_27();
extern "C" void _s80299970_28();
extern "C" void _s80299970_29();
extern "C" void _s80299970_30();
extern "C" void _s80299970_31();
extern "C" void _s80299970_32();
extern "C" void _s80299970_33();
extern "C" void _s80299970_34();
extern "C" void _s80299970_35();
extern "C" void _s80299970_36();
extern "C" void _s80299970_37();
extern "C" void _s80299970_38();
extern "C" void _s80299970_39();
extern "C" void _s80299970_40();
extern "C" void _s80299970_41();
extern "C" void _s80299970_42();
extern "C" void f_80299970() {}
