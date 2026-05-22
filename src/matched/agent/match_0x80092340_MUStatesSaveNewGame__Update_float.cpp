// 0x80092340 MUStatesSaveNewGame::Update(float) (1608 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stfd f31,0x48(1); stmw 27,0x34(1); stw 0,0x54(1); mr 31,3; fmr f31,f1; lwz 3,0x8(31); lwz 0,0x90(3); cmpwi 0,0; bne 8f; lwz 0,0x1c(31); mr 30,0; cmpwi 0,0; bne 18f; lis 9,-32696; stw 30,0x8(1); addi 27,9,22744; lwz 3,0x58d8(9); stw 30,0x4(27); addi 4,1,8; bl _s80092340_0; lis 28,-32696; lwz 0,0x8(1); cmpwi 0,0; bne 0f; lwz 11,0x8(31); li 30,1; li 4,3; lwz 9,0x98(11); stw 30,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092340_1; mr 3,31; li 4,14; bl _s80092340_2; stw 30,0x1c(31); b 25f; 0:; lwz 3,0x58d8(28); addi 4,1,12; stw 30,0xc(1); bl _s80092340_3; mr 9,3; cmpwi 9,1; bne 19f; lwz 0,0xc(1); cmpwi 0,0; beq 1f; lwz 11,0x8(31); li 0,9; li 4,23; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092340_4; mr 3,31; li 4,14; bl _s80092340_5; li 0,13; stw 0,0x1c(31); b 25f; 1:; lwz 3,0x58d8(28); addi 4,1,16; stw 9,0x10(1); bl _s80092340_6; mr 9,3; cmpwi 9,1; bne 19f; lwz 0,0x10(1); cmpwi 0,0; beq 2f; lwz 11,0x8(31); li 0,6; li 4,1; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092340_7; mr 3,31; li 4,14; bl _s80092340_8; li 0,2; stw 0,0x1c(31); b 25f; 2:; lwz 3,0x58d8(28); addi 4,1,20; stw 9,0x14(1); bl _s80092340_9; cmpwi 3,1; bne 19f; lwz 29,0x14(1); cmpwi 29,0; bne 3f; lwz 3,0x58d8(28); addi 4,1,24; stw 30,0x18(1); bl _s80092340_10; cmpwi 3,1; bne 19f; lwz 0,0x18(1); cmpwi 0,0; bne 4f; 3:; lwz 11,0x8(31); li 0,10; li 4,1; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092340_11; mr 3,31; li 4,14; bl _s80092340_12; li 0,4; stw 0,0x1c(31); b 25f; 4:; lwz 3,0x0(27); lis 5,171; stw 29,0x1c(1); addi 4,1,28; ori 5,5,52719; bl _s80092340_13; mr 9,3; cmpwi 9,1; beq 5f; lwz 9,0x18(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; lwz 9,0x8(31); stw 29,0x90(9); b 25f; 5:; lwz 0,0x1c(1); cmpwi 0,0; beq 7f; lwz 30,0x20(31); cmpwi 30,0; bne 6f; lwz 3,0x0(27); lis 5,171; stw 9,0x20(1); addi 4,1,32; ori 5,5,52719; bl _s80092340_14; cmpwi 3,1; bne 19f; lwz 0,0x20(1); cmpwi 0,0; bne 6f; lwz 11,0x8(31); li 0,2; li 4,2; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092340_15; mr 3,31; li 4,14; bl _s80092340_16; li 0,6; stw 0,0x1c(31); b 25f; 6:; lwz 0,0x1c(1); cmpwi 0,0; bne 17f; 7:; lis 9,-32696; li 30,0; lwz 3,0x58d8(9); addi 4,1,36; stw 30,0x24(1); li 5,0; bl _s80092340_17; cmpwi 3,1; bne 19f; lwz 0,0x24(1); cmpwi 0,0; bne 17f; lwz 11,0x8(31); li 0,6; li 4,26; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092340_18; mr 3,31; li 4,14; bl _s80092340_19; li 0,7; stw 0,0x1c(31); b 25f; 8:; cmpwi 0,1; bne 10f; lwz 0,0x1c(31); cmpwi 0,1; beq 9f; cmpwi 0,4; beq 9f; cmpwi 0,6; beq 9f; cmpwi 0,15; beq 9f; cmpwi 0,5; beq 9f; cmpwi 0,7; bne 17f; 9:; lwz 3,0x8(31); b 16f; 10:; cmpwi 0,2; bne 15f; lwz 9,0x1c(31); cmpwi 7,9,7; beq cr7,16f; cmpwi 9,1; beq 11f; beq cr7,11f; cmpwi 9,5; bne 12f; 11:; li 0,0; lwz 9,0x8(31); stw 0,0x1c(31); stw 0,0x90(9); b 25f; 12:; addi 0,9,-2; cmplwi 0,1; ble 9b; cmpwi 9,8; beq 9b; cmpwi 9,14; beq 9b; cmpwi 9,16; beq 9b; cmpwi 9,12; beq 9b; cmpwi 9,4; bne 13f; mr 3,31; li 4,1; bl _s80092340_20; li 0,5; stw 0,0x1c(31); b 25f; 13:; cmpwi 9,6; bne 14f; li 9,0; li 0,1; stw 0,0x20(31); stw 9,0x1c(31); stw 9,0x90(3); b 25f; 14:; addi 0,9,-9; cmplwi 0,2; ble 17f; cmpwi 9,15; beq 17f; cmpwi 9,13; bne 17f; li 0,0; stw 0,0x1c(31); stw 0,0x90(3); b 25f; 15:; cmpwi 0,3; bne 17f; lwz 0,0x1c(31); cmpwi 0,4; bne 16f; lwz 11,0x98(3); li 0,6; li 4,6; stw 0,0xac(11); lwz 9,0x8(31); lwz 3,0x98(9); bl _s80092340_21; mr 3,31; li 4,14; bl _s80092340_22; li 0,16; stw 0,0x1c(31); b 25f; 16:; li 4,1; bl _s80092340_23; b 25f; 17:; lwz 0,0x1c(31); mr 30,0; cmpwi 0,0; bne 18f; lis 9,-32706; lwz 11,0x8(31); lfs f0,-32040(9); li 0,9; stw 0,0x1c(31); stfs f0,0x24(31); stw 30,0x90(11); b 25f; 18:; cmpwi 30,9; bne 21f; lis 30,-32696; li 29,0; lwz 3,0x58d8(30); lis 5,171; addi 4,1,40; ori 5,5,52719; stw 29,0x28(1); bl _s80092340_24; lwz 3,0x58d8(30); addi 4,1,44; stw 29,0x2c(1); li 5,0; bl _s80092340_25; lwz 0,0x28(1); cmpwi 0,0; bne 20f; lwz 30,0x2c(1); cmpwi 30,0; bne 20f; 19:; lwz 9,0x18(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; lwz 9,0x8(31); stw 30,0x90(9); b 25f; 20:; lwz 3,-21500(13); lis 4,21321; ori 4,4,19795; addi 30,31,48; bl _s80092340_26; lwz 11,-26532(13); li 0,0; stw 0,0x24(3); lis 4,-32693; addi 4,4,-11760; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; stfs f1,0x4(30); bl _s80092340_27; li 0,10; stw 0,0x1c(31); b 25f; 21:; cmpwi 30,10; beq 22f; cmpwi 30,15; bne 24f; 22:; bl _s80092340_28; cmpwi 3,0; beq 25f; lwz 0,-24648(13); cmpwi 0,0; bne 23f; lwz 3,-21500(13); lis 4,21321; ori 4,4,19795; bl _s80092340_29; li 0,1; li 10,6; stw 0,0x24(3); li 4,10; lwz 9,0x8(31); lwz 11,0x98(9); stw 10,0xac(11); lwz 9,0x8(31); lwz 3,0x98(9); bl _s80092340_30; mr 3,31; li 4,14; bl _s80092340_31; li 0,8; stw 0,0x1c(31); b 25f; 23:; li 0,11; stw 0,0x1c(31); b 25f; 24:; cmpwi 30,11; bne 25f; lfs f0,0x24(31); lis 9,-32706; lfs f13,-32036(9); fsubs f0,f0,f31; fcmpu 0,f0,f13; stfs f0,0x24(31); bgt 25f; lwz 3,0x8(31); li 4,2; bl _s80092340_32; 25:; lwz 0,0x54(1); mtspr 8,0; lmw 27,0x34(1); lfd f31,0x48(1); addi 1,1,80"
extern "C" void _s80092340_0();
extern "C" void _s80092340_1();
extern "C" void _s80092340_2();
extern "C" void _s80092340_3();
extern "C" void _s80092340_4();
extern "C" void _s80092340_5();
extern "C" void _s80092340_6();
extern "C" void _s80092340_7();
extern "C" void _s80092340_8();
extern "C" void _s80092340_9();
extern "C" void _s80092340_10();
extern "C" void _s80092340_11();
extern "C" void _s80092340_12();
extern "C" void _s80092340_13();
extern "C" void _s80092340_14();
extern "C" void _s80092340_15();
extern "C" void _s80092340_16();
extern "C" void _s80092340_17();
extern "C" void _s80092340_18();
extern "C" void _s80092340_19();
extern "C" void _s80092340_20();
extern "C" void _s80092340_21();
extern "C" void _s80092340_22();
extern "C" void _s80092340_23();
extern "C" void _s80092340_24();
extern "C" void _s80092340_25();
extern "C" void _s80092340_26();
extern "C" void _s80092340_27();
extern "C" void _s80092340_28();
extern "C" void _s80092340_29();
extern "C" void _s80092340_30();
extern "C" void _s80092340_31();
extern "C" void _s80092340_32();
extern "C" void f_80092340() {}
