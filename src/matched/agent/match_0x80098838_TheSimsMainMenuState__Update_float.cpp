// 0x80098838 TheSimsMainMenuState::Update(float) (1076 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32697; mr 31,3; addi 30,9,23428; lwz 0,0x114(30); andi. 9,0,4; beq 0f; andi. 9,0,8; bne 0f; andi. 9,0,2; bne 0f; lwz 11,-26532(13); lis 4,-32693; addi 4,4,-11760; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lfs f13,0x11c(30); lis 9,-32706; lfs f0,-29616(9); fsubs f1,f1,f13; fcmpu 7,f1,f0; mfcr 0; rlwinm 0,0,30,31,31; cmpwi 0,0; beq 0f; lwz 0,0x114(30); li 9,-14; and 0,0,9; ori 0,0,2; stw 0,0x114(30); 0:; lwz 3,-24620(13); cmpwi 3,0; beq 1f; bl _s80098838_0; lwz 9,-24620(13); li 0,1; stw 0,0xd4(9); 1:; lis 9,-32697; addi 30,9,23428; lwz 0,0x9c(30); cmpwi 0,0; beq 2f; li 0,0; stw 0,0x9c(30); 2:; lis 9,-32697; lwz 0,0x61a0(9); cmpwi 0,0; beq 3f; li 0,1; stw 0,0xb4(30); 3:; lwz 3,0x8(31); lwz 9,0x90(3); cmpwi 9,0; beq 5f; li 0,0; cmpwi 9,1; stw 0,0x90(3); bne 4f; lwz 9,0x18(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; b 24f; 4:; mr 3,30; bl _s80098838_1; lis 9,-32706; mr 3,31; lfs f1,-29612(9); li 4,6; bl _s80098838_2; b 24f; 5:; bl _s80098838_3; cmpwi 3,0; beq 24f; lwz 3,0x8(31); li 28,0; li 29,0; li 27,1; bl _s80098838_4; cmpwi 3,24; bne 6f; lwz 3,0x8(31); bl _s80098838_5; mr 3,31; li 4,17; bl _s80098838_6; b 21f; 6:; lwz 3,0x8(31); bl _s80098838_7; cmpwi 3,1; bne 7f; lwz 3,0x8(31); bl _s80098838_8; b 21f; 7:; lwz 3,0x8(31); bl _s80098838_9; cmpwi 3,23; bne 9f; lwz 3,0x8(31); bl _s80098838_10; lwz 0,0x54(30); stw 27,0xd8(30); cmpwi 0,0; bne 8f; lis 3,-32706; li 4,0; addi 3,3,-29632; bl _s80098838_11; li 3,408; bl _s80098838_12; bl _s80098838_13; stw 3,0x54(30); 8:; li 27,0; b 21f; 9:; lwz 3,0x8(31); bl _s80098838_14; cmpwi 3,48; bne 10f; bl _s80098838_15; cmpwi 3,0; beq 19f; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 21f; lwz 3,0x8(31); li 29,1; bl _s80098838_16; mr 3,31; bl _s80098838_17; mr 3,31; li 4,8; bl _s80098838_18; b 21f; 10:; lwz 3,0x8(31); bl _s80098838_19; cmpwi 3,49; beq 13f; lwz 3,0x8(31); bl _s80098838_20; cmpwi 3,46; bne 12f; lwz 3,0x8(31); bl _s80098838_21; lwz 11,0x54(30); cmpwi 11,0; beq 11f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 11:; lwz 3,0x68(30); li 4,1; b 15f; 12:; lwz 3,0x8(31); bl _s80098838_22; cmpwi 3,47; bne 16f; 13:; lwz 3,0x8(31); bl _s80098838_23; lwz 11,0x54(30); cmpwi 11,0; beq 14f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 14:; lwz 3,0x68(30); li 4,0; 15:; stw 29,0x54(30); li 28,1; bl _s80098838_24; b 21f; 16:; lwz 3,0x8(31); bl _s80098838_25; cmpwi 3,8; bne 18f; bl _s80098838_26; cmpwi 3,0; beq 19f; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 21f; lwz 3,0x8(31); bl _s80098838_27; lis 9,-32697; addi 30,9,23428; lwz 11,0x68(30); stw 27,0xd8(30); cmpwi 11,0; beq 17f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 29,0x68(30); 17:; mr 3,31; li 29,1; li 4,16; bl _s80098838_28; b 21f; 18:; lwz 3,0x8(31); bl _s80098838_29; cmpwi 3,3; bne 21f; bl _s80098838_30; cmpwi 3,0; bne 20f; 19:; li 3,1; bl _s80098838_31; b 21f; 20:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 21f; lwz 3,0x8(31); li 29,1; bl _s80098838_32; mr 3,31; bl _s80098838_33; mr 3,31; li 4,8; bl _s80098838_34; 21:; cmpwi 28,0; beq 22f; lwz 0,-24620(13); cmpwi 0,0; bne 22f; li 3,220; bl _s80098838_35; bl _s80098838_36; stw 3,-24620(13); 22:; cmpwi 29,0; beq 23f; lwz 3,-24620(13); cmpwi 3,0; beq 24f; li 4,3; bl _s80098838_37; li 0,0; stw 0,-24620(13); 23:; lwz 9,-24620(13); cmpwi 9,0; beq 24f; stw 27,0xd8(9); 24:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80098838_0();
extern "C" void _s80098838_1();
extern "C" void _s80098838_2();
extern "C" void _s80098838_3();
extern "C" void _s80098838_4();
extern "C" void _s80098838_5();
extern "C" void _s80098838_6();
extern "C" void _s80098838_7();
extern "C" void _s80098838_8();
extern "C" void _s80098838_9();
extern "C" void _s80098838_10();
extern "C" void _s80098838_11();
extern "C" void _s80098838_12();
extern "C" void _s80098838_13();
extern "C" void _s80098838_14();
extern "C" void _s80098838_15();
extern "C" void _s80098838_16();
extern "C" void _s80098838_17();
extern "C" void _s80098838_18();
extern "C" void _s80098838_19();
extern "C" void _s80098838_20();
extern "C" void _s80098838_21();
extern "C" void _s80098838_22();
extern "C" void _s80098838_23();
extern "C" void _s80098838_24();
extern "C" void _s80098838_25();
extern "C" void _s80098838_26();
extern "C" void _s80098838_27();
extern "C" void _s80098838_28();
extern "C" void _s80098838_29();
extern "C" void _s80098838_30();
extern "C" void _s80098838_31();
extern "C" void _s80098838_32();
extern "C" void _s80098838_33();
extern "C" void _s80098838_34();
extern "C" void _s80098838_35();
extern "C" void _s80098838_36();
extern "C" void _s80098838_37();
extern "C" void f_80098838() {}
