// 0x802256FC InteractorModule::WallPainter::CountWallsInRoomSelection(void) (1652 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-256(1); mfspr 0,8; mfcr 12; stmw 14,0xb8(1); stw 0,0x104(1); stw 12,0xb4(1); mr 16,3; addi 9,1,8; lfs f0,0x64(16); addi 30,1,24; lfs f13,0x60(16); mr 4,9; lfs f12,0x68(16); mr 3,30; stfs f0,0x8(1); li 29,0; stfs f13,0xc(1); stfs f12,0x8(9); bl _s802256FC_0; mr 3,30; bl _s802256FC_1; lwz 0,-21472(13); lwz 9,-21488(13); stw 3,0x90(1); cmpwi 0,0; stw 0,0x98(1); stw 9,0x94(1); stw 29,0x98(16); beq 0f; lwz 3,0x98(1); lwz 4,0x90(1); bl _s802256FC_2; mr. 31,3; beq 0f; lwz 4,0x90(16); addi 9,31,4; lis 30,-32697; stw 9,0x9c(1); addi 3,30,24012; bl _s802256FC_3; stw 3,0xa0(1); addi 30,30,24012; lwz 4,0x90(1); lwz 9,0xc8(30); lwz 3,0x8(9); bl _s802256FC_4; cmpwi 3,0; stw 3,0x98(16); bne 1f; 0:; addi 3,1,24; li 4,2; bl _s802256FC_5; b 50f; 1:; stw 29,0x20(1); addi 3,1,32; stw 29,0x4(3); addi 9,1,40; stw 29,0x4(9); lis 11,-21846; lwz 9,0x9c(1); ori 11,11,43691; lwz 0,0x4(31); lwz 4,0x4(9); subf 4,0,4; mullw 4,4,11; bl _s802256FC_6; lwz 9,0x9c(1); lwz 18,0x4(31); lwz 0,0x4(9); cmpw 18,0; beq 45f; addi 11,1,56; stw 11,0xa4(1); 2:; lwz 11,0x94(1); addi 0,18,3; mr 4,18; lwz 9,0x0(11); stw 0,0xa8(1); lwz 0,0xc4(9); lha 3,0xc0(9); mtspr 8,0; add 3,11,3; blrl; cmpwi 3,0; beq 44f; lwz 11,0x94(1); mr 5,18; lwz 3,0xa4(1); li 28,0; lwz 9,0x0(11); mr 14,3; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,11,4; blrl; li 9,0; lwz 3,0xa4(1); li 10,0; stw 9,0x88(1); stw 10,0x8c(1); bl _s802256FC_7; mr. 17,3; beq 43f; li 15,1; addi 27,1,136; 3:; cmpwi 4,17,16; beq cr4,4f; cmpwi 17,32; bne 35f; 4:; lwz 3,0x20(1); mr 5,18; lwz 4,0x24(1); bl _s802256FC_8; lwz 0,0x24(1); cmpw 3,0; bne 42f; lwz 0,0x2c(1); cmpw 3,0; beq 5f; mr 4,18; bl _s802256FC_9; lwz 9,0x24(1); addi 20,1,120; addi 21,1,124; addi 22,1,128; addi 9,9,3; addi 23,1,132; stw 9,0x24(1); b 20f; 5:; lwz 9,0x20(1); mr 26,3; lis 0,-21846; stw 15,0x74(1); ori 0,0,43691; subf 9,9,26; mullw 9,9,0; addi 11,1,112; addi 0,1,116; stw 9,0x70(1); cmplw 9,15; bge 6f; mr 11,0; 6:; lwz 0,0x0(11); add. 24,9,0; beq 8f; rlwinm 0,24,1,0,30; add 3,0,24; mr 19,0; cmplwi 3,128; ble 7f; bl _s802256FC_10; b 9f; 7:; bl _s802256FC_11; b 9f; 8:; li 3,0; li 19,0; 9:; mr 29,3; lwz 30,0x20(1); mr 25,29; addi 20,1,120; mr 31,25; cmpw 30,26; addi 21,1,124; addi 22,1,128; addi 23,1,132; beq 11f; 10:; mr 3,31; mr 4,30; bl _s802256FC_12; addi 30,30,3; addi 31,31,3; cmpw 30,26; bne 10b; 11:; lwz 0,0x74(1); mr 29,31; cmpwi 0,1; bne 12f; mr 3,29; mr 4,18; bl _s802256FC_13; addi 29,29,3; b 15f; 12:; mr 30,29; mr. 31,0; beq 14f; 13:; mr 3,30; mr 4,18; bl _s802256FC_14; addi 30,30,3; addic. 31,31,-1; bne 13b; 14:; mr 29,30; 15:; lwz 31,0x24(1); lwz 30,0x20(1); cmpw 30,31; beq 17f; 16:; mr 3,30; li 4,2; bl _s802256FC_15; addi 30,30,3; cmpw 30,31; bne 16b; 17:; lwz 3,0x20(1); lwz 0,0x2c(1); cmpwi 3,0; subf 4,3,0; beq 19f; cmplwi 4,128; ble 18f; bl _s802256FC_16; b 19f; 18:; bl _s802256FC_17; 19:; add 0,19,24; stw 25,0x20(1); add 0,0,25; stw 29,0x24(1); stw 0,0x2c(1); 20:; li 0,0; lwz 3,0x98(1); mr 5,20; mr 6,21; mr 7,22; mr 8,23; stw 0,0x78(1); mr 4,18; stw 0,0x7c(1); bl _s802256FC_18; cmpwi 3,0; beq 32f; lwz 9,0x78(1); cmpwi 9,0; beq 27f; lhz 0,0x0(9); lwz 9,0x90(1); cmpw 0,9; bne 27f; lwz 0,0x80(1); cmpwi 0,3; beq 25f; cmpwi 0,1; bne 21f; rlwinm 0,28,2,0,29; li 11,3; stwx 11,27,0; b 26f; 21:; cmpwi 0,4; bne 22f; rlwinm 0,28,2,0,29; li 9,2; stwx 9,27,0; b 26f; 22:; cmpwi 0,2; bne 23f; rlwinm 0,28,2,0,29; li 11,4; stwx 11,27,0; b 26f; 23:; bne cr4,24f; rlwinm 9,28,2,0,29; li 0,2; stwx 0,9,27; addi 28,28,1; rlwinm 0,28,2,0,29; li 9,4; stwx 9,27,0; b 26f; 24:; rlwinm 9,28,2,0,29; li 11,3; addi 28,28,1; stwx 11,9,27; 25:; rlwinm 0,28,2,0,29; stwx 15,27,0; 26:; addi 28,28,1; 27:; lwz 9,0x7c(1); cmpwi 9,0; beq 36f; lwz 0,0x78(1); cmpw 9,0; beq 36f; lhz 0,0x0(9); lwz 9,0x90(1); cmpw 0,9; bne 36f; lwz 0,0x84(1); cmpwi 0,3; bne 28f; rlwinm 0,28,2,0,29; stwx 15,27,0; addi 28,28,1; 28:; lwz 0,0x84(1); cmpwi 0,1; bne 29f; rlwinm 0,28,2,0,29; li 11,3; b 31f; 29:; cmpwi 0,4; bne 30f; rlwinm 0,28,2,0,29; li 9,2; b 33f; 30:; cmpwi 0,2; bne 36f; rlwinm 0,28,2,0,29; li 11,4; 31:; stwx 11,27,0; addi 28,28,1; b 36f; 32:; bne cr4,34f; rlwinm 9,28,2,0,29; li 0,2; stwx 0,9,27; addi 28,28,1; rlwinm 0,28,2,0,29; li 9,4; 33:; stwx 9,27,0; addi 28,28,1; b 36f; 34:; rlwinm 9,28,2,0,29; li 11,3; addi 28,28,1; stwx 11,9,27; rlwinm 0,28,2,0,29; stwx 15,27,0; addi 28,28,1; b 36f; 35:; li 0,0; li 28,1; stw 0,0x4(27); stw 0,0x88(1); 36:; cmpwi 28,0; ble 42f; addi 31,1,136; mr 29,28; 37:; lwz 3,0x0(31); cmpwi 3,0; beq 38f; li 4,0; bl _s802256FC_19; stw 3,0x0(31); 38:; lwz 5,0x0(31); mr 3,14; mr 4,17; bl _s802256FC_20; lwz 0,0xa0(1); mr 30,3; cmpw 30,0; bne 39f; lwz 9,0x98(16); addi 9,9,-1; stw 9,0x98(16); b 41f; 39:; lwz 0,0x88(16); andi. 9,0,8; beq 40f; mr 3,14; mr 4,17; bl _s802256FC_21; cmpwi 3,0; beq 41f; mr 3,30; addi 4,16,156; bl _s802256FC_22; b 41f; 40:; mr 3,30; addi 4,16,156; bl _s802256FC_23; 41:; addi 31,31,4; addic. 29,29,-1; bne 37b; 42:; mr 4,17; mr 3,14; bl _s802256FC_24; mr. 17,3; bne 3b; 43:; mr 3,14; li 4,2; bl _s802256FC_25; 44:; lwz 9,0x9c(1); lwz 18,0xa8(1); lwz 0,0x4(9); cmpw 18,0; bne 2b; 45:; lwz 30,0x24(1); lwz 31,0x20(1); cmpw 31,30; beq 47f; 46:; mr 3,31; li 4,2; bl _s802256FC_26; addi 31,31,3; cmpw 31,30; bne 46b; 47:; lwz 3,0x20(1); cmpwi 3,0; beq 49f; lwz 0,0x2c(1); subf 4,3,0; cmplwi 4,128; ble 48f; bl _s802256FC_27; b 49f; 48:; bl _s802256FC_28; 49:; addi 3,1,24; li 4,2; bl _s802256FC_29; 50:; lwz 0,0x104(1); lwz 12,0xb4(1); mtspr 8,0; lmw 14,0xb8(1); mtcrf 8,12; addi 1,1,256"
extern "C" void _s802256FC_0();
extern "C" void _s802256FC_1();
extern "C" void _s802256FC_2();
extern "C" void _s802256FC_3();
extern "C" void _s802256FC_4();
extern "C" void _s802256FC_5();
extern "C" void _s802256FC_6();
extern "C" void _s802256FC_7();
extern "C" void _s802256FC_8();
extern "C" void _s802256FC_9();
extern "C" void _s802256FC_10();
extern "C" void _s802256FC_11();
extern "C" void _s802256FC_12();
extern "C" void _s802256FC_13();
extern "C" void _s802256FC_14();
extern "C" void _s802256FC_15();
extern "C" void _s802256FC_16();
extern "C" void _s802256FC_17();
extern "C" void _s802256FC_18();
extern "C" void _s802256FC_19();
extern "C" void _s802256FC_20();
extern "C" void _s802256FC_21();
extern "C" void _s802256FC_22();
extern "C" void _s802256FC_23();
extern "C" void _s802256FC_24();
extern "C" void _s802256FC_25();
extern "C" void _s802256FC_26();
extern "C" void _s802256FC_27();
extern "C" void _s802256FC_28();
extern "C" void _s802256FC_29();
extern "C" void f_802256FC() {}
