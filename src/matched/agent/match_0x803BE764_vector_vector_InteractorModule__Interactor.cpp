// 0x803BE764 vector<vector<InteractorModule::Interactor (1928 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 21,0x2c(1); stw 0,0x5c(1); mr 26,3; mr 23,4; mr 27,6; mr. 28,5; beq 64f; lwz 0,0xc(26); lwz 9,0x4(26); subf 0,9,0; srawi 0,0,4; cmplw 0,28; blt 29f; lwz 9,0x0(27); li 11,0; lwz 0,0x4(27); addi 31,1,8; stw 11,0x8(1); mr 24,31; subf 0,9,0; stw 11,0x4(31); addi 9,31,8; srawi. 0,0,2; stw 11,0x4(9); beq 1f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 0f; mr 3,29; bl _s803BE764_0; b 2f; 0:; mr 3,29; bl _s803BE764_1; b 2f; 1:; li 3,0; li 29,0; 2:; lwz 30,0x4(27); add 0,3,29; lwz 4,0x0(27); mr 9,3; stw 0,0xc(31); stw 3,0x0(31); cmpw 30,4; stw 3,0x4(31); beq 3f; subf 30,4,30; mr 5,30; bl _s803BE764_2; add 3,3,30; 3:; lwz 27,0x4(26); stw 3,0x4(31); subf 0,23,27; srawi 0,0,4; cmplw 0,28; ble 13f; rlwinm 0,28,4,0,27; mr 22,27; subf 29,0,27; mr 25,0; mr 31,27; cmpw 29,27; beq 9f; li 28,0; 4:; lwz 0,0x4(29); addi 11,31,8; lwz 9,0x0(29); stw 28,0x0(31); subf 0,9,0; stw 28,0x4(31); srawi. 0,0,2; stw 28,0x4(11); beq 6f; rlwinm 0,0,2,0,29; mr 30,0; cmplwi 0,128; ble 5f; mr 3,30; bl _s803BE764_3; b 7f; 5:; mr 3,30; bl _s803BE764_4; b 7f; 6:; li 3,0; li 30,0; 7:; add 0,3,30; stw 3,0x0(31); stw 0,0xc(31); stw 3,0x4(31); lwz 4,0x0(29); lwz 30,0x4(29); cmpw 30,4; beq 8f; subf 30,4,30; mr 5,30; bl _s803BE764_5; add 3,3,30; 8:; stw 3,0x4(31); addi 29,29,16; addi 31,31,16; cmpw 29,22; bne 4b; 9:; lwz 0,0x4(26); subf 30,25,27; subf 9,23,30; mr 29,27; add 0,0,25; srawi. 31,9,4; stw 0,0x4(26); ble 11f; 10:; addi 29,29,-16; addi 30,30,-16; mr 3,29; mr 4,30; bl _s803BE764_6; addic. 31,31,-1; bgt 10b; 11:; mr 30,23; add 31,25,30; cmpw 30,31; beq 27f; 12:; mr 3,30; mr 4,24; bl _s803BE764_7; addi 30,30,16; cmpw 30,31; bne 12b; b 27f; 13:; subf. 29,0,28; rlwinm 21,0,4,0,27; cmpw cr7,23,27; mr 25,29; mr 31,27; mfcr 22; rlwinm 22,22,28,0,3; beq 19f; li 28,0; 14:; lwz 0,0x4(24); addi 11,31,8; lwz 9,0x0(24); stw 28,0x0(31); subf 0,9,0; stw 28,0x4(31); srawi. 0,0,2; stw 28,0x4(11); beq 16f; rlwinm 0,0,2,0,29; mr 30,0; cmplwi 0,128; ble 15f; mr 3,30; bl _s803BE764_8; b 17f; 15:; mr 3,30; bl _s803BE764_9; b 17f; 16:; li 3,0; li 30,0; 17:; add 0,3,30; stw 3,0x0(31); stw 0,0xc(31); stw 3,0x4(31); lwz 4,0x0(24); lwz 30,0x4(24); cmpw 30,4; beq 18f; subf 30,4,30; mr 5,30; bl _s803BE764_10; add 3,3,30; 18:; stw 3,0x4(31); addic. 29,29,-1; addi 31,31,16; bne 14b; 19:; lwz 0,0x4(26); rlwinm 9,25,4,0,27; mr 29,23; mtcrf 128,22; add 0,0,9; mr 31,0; stw 0,0x4(26); beq 25f; li 28,0; 20:; lwz 0,0x4(29); addi 11,31,8; lwz 9,0x0(29); stw 28,0x0(31); subf 0,9,0; stw 28,0x4(31); srawi. 0,0,2; stw 28,0x4(11); beq 22f; rlwinm 0,0,2,0,29; mr 30,0; cmplwi 0,128; ble 21f; mr 3,30; bl _s803BE764_11; b 23f; 21:; mr 3,30; bl _s803BE764_12; b 23f; 22:; li 3,0; li 30,0; 23:; add 0,3,30; stw 3,0x0(31); stw 0,0xc(31); stw 3,0x4(31); lwz 4,0x0(29); lwz 30,0x4(29); cmpw 30,4; beq 24f; subf 30,4,30; mr 5,30; bl _s803BE764_13; add 3,3,30; 24:; stw 3,0x4(31); addi 29,29,16; addi 31,31,16; cmpw 29,27; bne 20b; 25:; lwz 0,0x4(26); mr 30,23; mtcrf 128,22; add 0,0,21; stw 0,0x4(26); beq 27f; 26:; mr 3,30; mr 4,24; bl _s803BE764_14; addi 30,30,16; cmpw 30,27; bne 26b; 27:; lwz 3,0x8(1); cmpwi 3,0; beq 64f; lwz 0,0xc(24); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 28f; bl _s803BE764_15; b 64f; 28:; bl _s803BE764_16; b 64f; 29:; lwz 0,0x0(26); addi 10,1,36; stw 28,0x24(1); addi 11,1,32; subf 0,0,9; srawi 9,0,4; cmplw 9,28; stw 9,0x20(1); bge 30f; mr 11,10; 30:; lwz 0,0x0(11); add. 0,9,0; beq 32f; rlwinm 0,0,4,0,27; mr 25,0; cmplwi 0,128; ble 31f; mr 3,25; bl _s803BE764_17; b 33f; 31:; mr 3,25; bl _s803BE764_18; b 33f; 32:; li 3,0; li 25,0; 33:; lwz 31,0x0(26); mr 24,3; mr 29,24; cmpw 31,23; beq 39f; li 28,0; 34:; lwz 0,0x4(31); addi 11,29,8; lwz 9,0x0(31); stw 28,0x0(29); subf 0,9,0; stw 28,0x4(29); srawi. 0,0,2; stw 28,0x4(11); beq 36f; rlwinm 0,0,2,0,29; mr 30,0; cmplwi 0,128; ble 35f; mr 3,30; bl _s803BE764_19; b 37f; 35:; mr 3,30; bl _s803BE764_20; b 37f; 36:; li 3,0; li 30,0; 37:; add 0,3,30; stw 3,0x0(29); stw 0,0xc(29); stw 3,0x4(29); lwz 4,0x0(31); lwz 30,0x4(31); cmpw 30,4; beq 38f; subf 30,4,30; mr 5,30; bl _s803BE764_21; add 3,3,30; 38:; stw 3,0x4(29); addi 31,31,16; addi 29,29,16; cmpw 31,23; bne 34b; 39:; lwz 0,0x24(1); mr 8,29; cmpwi 0,1; bne 44f; lwz 0,0x4(27); li 9,0; lwz 11,0x0(27); addi 10,8,8; stw 9,0x0(8); subf 0,11,0; stw 9,0x4(8); srawi. 0,0,2; stw 9,0x4(10); beq 41f; rlwinm 0,0,2,0,29; mr 31,0; cmplwi 0,128; ble 40f; mr 3,31; bl _s803BE764_22; b 42f; 40:; mr 3,31; bl _s803BE764_23; b 42f; 41:; li 3,0; li 31,0; 42:; add 0,3,31; stw 3,0x0(29); stw 0,0xc(29); stw 3,0x4(29); lwz 30,0x4(27); lwz 4,0x0(27); cmpw 30,4; beq 43f; subf 30,4,30; mr 5,30; bl _s803BE764_24; add 3,3,30; 43:; stw 3,0x4(29); addi 8,29,16; b 51f; 44:; mr 31,8; mr. 29,0; beq 50f; li 28,0; 45:; lwz 0,0x4(27); addi 11,31,8; lwz 9,0x0(27); stw 28,0x0(31); subf 0,9,0; stw 28,0x4(31); srawi. 0,0,2; stw 28,0x4(11); beq 47f; rlwinm 0,0,2,0,29; mr 30,0; cmplwi 0,128; ble 46f; mr 3,30; bl _s803BE764_25; b 48f; 46:; mr 3,30; bl _s803BE764_26; b 48f; 47:; li 3,0; li 30,0; 48:; add 0,3,30; stw 3,0x0(31); stw 0,0xc(31); stw 3,0x4(31); lwz 4,0x0(27); lwz 30,0x4(27); cmpw 30,4; beq 49f; subf 30,4,30; mr 5,30; bl _s803BE764_27; add 3,3,30; 49:; stw 3,0x4(31); addic. 29,29,-1; addi 31,31,16; bne 45b; 50:; mr 8,31; 51:; lwz 28,0x4(26); mr 31,23; mr 29,8; cmpw 31,28; beq 57f; li 27,0; 52:; lwz 0,0x4(31); addi 11,29,8; lwz 9,0x0(31); stw 27,0x0(29); subf 0,9,0; stw 27,0x4(29); srawi. 0,0,2; stw 27,0x4(11); beq 54f; rlwinm 0,0,2,0,29; mr 30,0; cmplwi 0,128; ble 53f; mr 3,30; bl _s803BE764_28; b 55f; 53:; mr 3,30; bl _s803BE764_29; b 55f; 54:; li 3,0; li 30,0; 55:; add 0,3,30; stw 3,0x0(29); stw 0,0xc(29); stw 3,0x4(29); lwz 4,0x0(31); lwz 30,0x4(31); cmpw 30,4; beq 56f; subf 30,4,30; mr 5,30; bl _s803BE764_30; add 3,3,30; 56:; stw 3,0x4(29); addi 31,31,16; addi 29,29,16; cmpw 31,28; bne 52b; 57:; lwz 31,0x4(26); lwz 30,0x0(26); cmpw 30,31; beq 61f; 58:; lwz 3,0x0(30); cmpwi 3,0; beq 60f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 59f; bl _s803BE764_31; b 60f; 59:; bl _s803BE764_32; 60:; addi 30,30,16; cmpw 30,31; bne 58b; 61:; lwz 3,0x0(26); lwz 0,0xc(26); cmpwi 3,0; subf 0,3,0; srawi 0,0,4; beq 63f; rlwinm 4,0,4,0,27; cmplwi 4,128; ble 62f; bl _s803BE764_33; b 63f; 62:; bl _s803BE764_34; 63:; add 0,25,24; stw 24,0x0(26); stw 0,0xc(26); stw 29,0x4(26); 64:; lwz 0,0x5c(1); mtspr 8,0; lmw 21,0x2c(1); addi 1,1,88"
extern "C" void _s803BE764_0();
extern "C" void _s803BE764_1();
extern "C" void _s803BE764_2();
extern "C" void _s803BE764_3();
extern "C" void _s803BE764_4();
extern "C" void _s803BE764_5();
extern "C" void _s803BE764_6();
extern "C" void _s803BE764_7();
extern "C" void _s803BE764_8();
extern "C" void _s803BE764_9();
extern "C" void _s803BE764_10();
extern "C" void _s803BE764_11();
extern "C" void _s803BE764_12();
extern "C" void _s803BE764_13();
extern "C" void _s803BE764_14();
extern "C" void _s803BE764_15();
extern "C" void _s803BE764_16();
extern "C" void _s803BE764_17();
extern "C" void _s803BE764_18();
extern "C" void _s803BE764_19();
extern "C" void _s803BE764_20();
extern "C" void _s803BE764_21();
extern "C" void _s803BE764_22();
extern "C" void _s803BE764_23();
extern "C" void _s803BE764_24();
extern "C" void _s803BE764_25();
extern "C" void _s803BE764_26();
extern "C" void _s803BE764_27();
extern "C" void _s803BE764_28();
extern "C" void _s803BE764_29();
extern "C" void _s803BE764_30();
extern "C" void _s803BE764_31();
extern "C" void _s803BE764_32();
extern "C" void _s803BE764_33();
extern "C" void _s803BE764_34();
extern "C" void f_803BE764() {}
