// 0x80225D70 InteractorModule::WallPainter::FinalizePaperForRoom(void) (1352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-336(1); mfspr 0,8; stmw 14,0x108(1); stw 0,0x154(1); mr 21,3; addi 9,1,8; lfs f13,0x64(21); addi 30,1,24; lfs f12,0x60(21); mr 4,9; lfs f0,0x68(21); mr 3,30; stfs f13,0x8(1); stfs f12,0xc(1); stfs f0,0x8(9); bl _s80225D70_0; mr 3,30; bl _s80225D70_1; lwz 0,-21472(13); lwz 9,-21488(13); stw 3,0xf0(1); cmpwi 0,0; stw 0,0xf8(1); stw 9,0xf4(1); beq 2f; lwz 3,0xf8(1); lwz 4,0xf0(1); bl _s80225D70_2; mr. 3,3; beq 2f; addi 3,3,4; lwz 4,0x90(21); lis 30,-32697; stw 3,0xfc(1); addi 3,30,24012; li 31,0; bl _s80225D70_3; addi 30,30,24012; mr 14,3; lwz 0,0x3bc(30); cmpwi 0,0; bne 0f; mr 3,30; bl _s80225D70_4; cmpwi 3,0; bne 0f; lwz 0,0x94(21); cmpwi 0,-1; bne 1f; 0:; li 31,1; 1:; cmpwi 7,31,0; bne cr7,5f; lwz 9,0x98(21); lwz 0,0x94(21); mr 10,9; mr 11,0; cmpw 9,0; ble 3f; lwz 0,0x88(21); andi. 9,0,8; bne 3f; 2:; addi 3,1,24; li 4,2; bl _s80225D70_5; li 3,0; b 32f; 3:; bne cr7,5f; lwz 0,0x88(21); andi. 9,0,8; beq 4f; stw 31,0x94(21); b 5f; 4:; subf 0,10,11; stw 0,0x94(21); 5:; lwz 11,0xfc(1); lwz 30,0x0(11); lwz 0,0x4(11); cmpw 30,0; beq 31f; addi 0,1,40; addi 22,1,32; stw 0,0x100(1); 6:; mr 4,30; mr 3,22; bl _s80225D70_6; addi 30,30,3; stw 30,0x104(1); mr 4,22; lwz 11,0xf4(1); lwz 9,0x0(11); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 30f; lwz 11,0xf4(1); mr 5,22; lwz 3,0x100(1); li 31,0; lwz 9,0x0(11); lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,11,4; blrl; li 9,0; lwz 3,0x100(1); li 10,0; stw 9,0xe8(1); stw 10,0xec(1); bl _s80225D70_7; mr. 23,3; beq 29f; addi 20,1,96; li 15,0; addi 27,1,232; li 16,1; li 17,3; li 18,2; li 19,4; 7:; cmpwi 23,16; mfcr 30; beq 8f; cmpwi 23,32; bne 23f; 8:; mr 4,22; mr 3,20; bl _s80225D70_8; lwz 3,0xf8(1); mr 4,20; stw 15,0xd8(1); addi 5,1,216; stw 15,0xdc(1); addi 6,1,220; addi 7,1,224; addi 8,1,228; bl _s80225D70_9; mr 11,20; cmpwi 3,0; beq 19f; lwz 9,0xd8(1); cmpwi 9,0; beq 15f; lhz 0,0x0(9); lwz 9,0xf0(1); cmpw 0,9; bne 15f; lwz 0,0xe0(1); cmpwi 0,3; beq 13f; cmpwi 0,1; bne 9f; rlwinm 0,31,2,0,29; stwx 17,27,0; b 14f; 9:; cmpwi 0,4; bne 10f; rlwinm 0,31,2,0,29; stwx 18,27,0; b 14f; 10:; cmpwi 0,2; bne 11f; rlwinm 0,31,2,0,29; stwx 19,27,0; b 14f; 11:; mtcrf 128,30; bne 12f; rlwinm 9,31,2,0,29; addi 31,31,1; stwx 18,9,27; rlwinm 0,31,2,0,29; stwx 19,27,0; b 14f; 12:; rlwinm 9,31,2,0,29; addi 31,31,1; stwx 17,9,27; 13:; rlwinm 0,31,2,0,29; stwx 16,27,0; 14:; addi 31,31,1; 15:; lwz 9,0xdc(1); cmpwi 9,0; beq 22f; lwz 0,0xd8(1); cmpw 9,0; beq 22f; lhz 0,0x0(9); lwz 9,0xf0(1); cmpw 0,9; bne 22f; lwz 0,0xe4(1); cmpwi 0,3; bne 16f; rlwinm 0,31,2,0,29; stwx 16,27,0; addi 31,31,1; 16:; lwz 0,0xe4(1); cmpwi 0,1; bne 17f; rlwinm 0,31,2,0,29; stwx 17,27,0; b 21f; 17:; cmpwi 0,4; bne 18f; rlwinm 0,31,2,0,29; stwx 18,27,0; b 21f; 18:; cmpwi 0,2; bne 22f; rlwinm 0,31,2,0,29; stwx 19,27,0; b 21f; 19:; mtcrf 128,30; bne 20f; rlwinm 9,31,2,0,29; addi 31,31,1; stwx 18,9,27; rlwinm 0,31,2,0,29; stwx 19,27,0; b 21f; 20:; rlwinm 9,31,2,0,29; addi 31,31,1; stwx 17,9,27; rlwinm 0,31,2,0,29; stwx 16,27,0; 21:; addi 31,31,1; 22:; mr 3,11; li 4,2; bl _s80225D70_10; b 24f; 23:; stw 15,0x4(27); li 31,1; stw 15,0xe8(1); 24:; cmpwi 31,0; ble 28f; addi 24,1,160; addi 28,1,232; mr 25,31; 25:; lwz 3,0x0(28); cmpwi 3,0; beq 26f; li 4,0; bl _s80225D70_11; stw 3,0x0(28); 26:; lwz 29,-21488(13); addi 30,1,104; mr 3,30; mr 5,22; lwz 9,0x0(29); mr 26,30; lha 4,0xa8(9); lwz 0,0xac(9); add 4,29,4; mtspr 8,0; blrl; lwz 5,0x0(28); mr 3,30; mr 4,23; bl _s80225D70_12; mr 30,3; cmpw 30,14; beq 27f; lwz 6,0x0(28); mr 5,23; mr 4,14; mr 3,26; bl _s80225D70_13; mr 4,26; mr 3,24; bl _s80225D70_14; lwz 9,0x0(29); mr 4,22; mr 5,24; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 30,0; beq 27f; mr 3,26; mr 4,23; bl _s80225D70_15; cmpwi 3,0; beq 27f; mr 3,30; addi 4,21,156; bl _s80225D70_16; 27:; mr 3,26; li 4,2; bl _s80225D70_17; addi 28,28,4; addic. 25,25,-1; bne 25b; 28:; mr 4,23; addi 3,1,40; bl _s80225D70_18; mr. 23,3; bne 7b; 29:; addi 3,1,40; li 4,2; bl _s80225D70_19; 30:; mr 3,22; li 4,2; bl _s80225D70_20; lwz 9,0xfc(1); lwz 30,0x104(1); lwz 0,0x4(9); cmpw 30,0; bne 6b; 31:; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lis 3,-32697; addi 3,3,24012; bl _s80225D70_21; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; addi 3,1,24; li 4,2; bl _s80225D70_22; li 3,1; 32:; lwz 0,0x154(1); mtspr 8,0; lmw 14,0x108(1); addi 1,1,336"
extern "C" void _s80225D70_0();
extern "C" void _s80225D70_1();
extern "C" void _s80225D70_2();
extern "C" void _s80225D70_3();
extern "C" void _s80225D70_4();
extern "C" void _s80225D70_5();
extern "C" void _s80225D70_6();
extern "C" void _s80225D70_7();
extern "C" void _s80225D70_8();
extern "C" void _s80225D70_9();
extern "C" void _s80225D70_10();
extern "C" void _s80225D70_11();
extern "C" void _s80225D70_12();
extern "C" void _s80225D70_13();
extern "C" void _s80225D70_14();
extern "C" void _s80225D70_15();
extern "C" void _s80225D70_16();
extern "C" void _s80225D70_17();
extern "C" void _s80225D70_18();
extern "C" void _s80225D70_19();
extern "C" void _s80225D70_20();
extern "C" void _s80225D70_21();
extern "C" void _s80225D70_22();
extern "C" void f_80225D70() {}
