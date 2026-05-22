// 0x803A42C4 vector<IFFResList, (1080 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 23,0x2c(1); stw 0,0x54(1); stw 12,0x28(1); mr 27,3; mr 25,4; mr 28,6; mr. 30,5; beq 36f; lwz 0,0xc(27); lis 29,-21846; lwz 9,0x4(27); ori 29,29,43691; subf 0,9,0; mullw 0,0,29; srawi 0,0,3; cmplw 0,30; blt 15f; mr 4,28; addi 3,1,8; bl _s803A42C4_0; lwz 28,0x4(27); subf 0,25,28; mullw 0,0,29; srawi 0,0,3; cmplw 0,30; ble 5f; mulli 0,30,24; mr 29,28; mr 30,28; addi 24,1,8; subf 31,0,28; mr 26,0; cmpw 31,28; beq 1f; 0:; mr 3,30; mr 4,31; bl _s803A42C4_1; addi 31,31,24; addi 30,30,24; cmpw 31,29; bne 0b; 1:; subf 30,26,28; lis 0,-21846; subf 11,25,30; ori 0,0,43691; mullw 11,11,0; lwz 9,0x4(27); mr 31,28; add 9,9,26; stw 9,0x4(27); srawi. 29,11,3; ble 3f; 2:; addi 31,31,-24; addi 30,30,-24; mr 3,31; mr 4,30; bl _s803A42C4_2; lwz 9,0x10(30); addic. 29,29,-1; stw 9,0x10(31); lwz 0,0x14(30); stw 0,0x14(31); bgt 2b; 3:; mr 31,25; add 30,26,31; cmpw 31,30; beq 11f; 4:; mr 3,31; mr 4,24; bl _s803A42C4_3; lwz 0,0x10(24); stw 0,0x10(31); lwz 9,0x14(24); stw 9,0x14(31); addi 31,31,24; cmpw 31,30; bne 4b; b 11f; 5:; subf. 31,0,30; addi 29,1,8; mr 26,31; mulli 23,0,24; mr 30,28; mr 24,29; cmpw cr4,25,28; beq 7f; 6:; mr 3,30; mr 4,29; bl _s803A42C4_4; addi 30,30,24; addic. 31,31,-1; bne 6b; 7:; mulli 9,26,24; lwz 0,0x4(27); mr 31,25; add 0,0,9; mr 30,0; stw 0,0x4(27); beq cr4,9f; 8:; mr 3,30; mr 4,31; bl _s803A42C4_5; addi 31,31,24; addi 30,30,24; cmpw 31,28; bne 8b; 9:; lwz 0,0x4(27); mr 31,25; add 0,0,23; stw 0,0x4(27); beq cr4,11f; 10:; mr 3,31; mr 4,24; bl _s803A42C4_6; lwz 0,0x10(24); stw 0,0x10(31); lwz 9,0x14(24); stw 9,0x14(31); addi 31,31,24; cmpw 31,28; bne 10b; 11:; lwz 0,0x4(24); lwz 9,0x8(1); cmpw 9,0; beq 13f; 12:; addi 9,9,88; cmpw 9,0; bne 12b; 13:; lwz 3,0x0(24); cmpwi 3,0; beq 36f; lwz 0,0xc(24); lis 9,-17874; ori 9,9,35747; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 14f; bl _s803A42C4_7; b 36f; 14:; bl _s803A42C4_8; b 36f; 15:; lwz 0,0x0(27); addi 10,1,36; stw 30,0x24(1); addi 11,1,32; subf 0,0,9; mullw 0,0,29; srawi 9,0,3; cmplw 9,30; stw 9,0x20(1); bge 16f; mr 11,10; 16:; lwz 0,0x0(11); add. 0,9,0; beq 18f; mulli 0,0,24; mr 26,0; cmplwi 0,128; ble 17f; mr 3,26; bl _s803A42C4_9; b 19f; 17:; mr 3,26; bl _s803A42C4_10; b 19f; 18:; li 3,0; li 26,0; 19:; lwz 31,0x0(27); mr 24,3; mr 30,24; cmpw 31,25; beq 21f; 20:; mr 3,30; mr 4,31; bl _s803A42C4_11; addi 31,31,24; addi 30,30,24; cmpw 31,25; bne 20b; 21:; lwz 0,0x24(1); cmpwi 0,1; bne 22f; mr 3,30; mr 4,28; bl _s803A42C4_12; addi 30,30,24; b 25f; 22:; mr 31,30; mr. 30,0; beq 24f; 23:; mr 3,31; mr 4,28; bl _s803A42C4_13; addi 31,31,24; addic. 30,30,-1; bne 23b; 24:; mr 30,31; 25:; lwz 29,0x4(27); mr 31,25; cmpw 31,29; beq 27f; 26:; mr 3,30; mr 4,31; bl _s803A42C4_14; addi 31,31,24; addi 30,30,24; cmpw 31,29; bne 26b; 27:; lwz 28,0x4(27); lwz 11,0x0(27); cmpw 11,28; beq 33f; lis 31,-17874; ori 31,31,35747; 28:; lwz 9,0x0(11); addi 29,11,24; lwz 0,0x4(11); mr 3,9; cmpw 9,0; beq 30f; 29:; addi 9,9,88; cmpw 9,0; bne 29b; 30:; cmpwi 3,0; beq 32f; lwz 0,0xc(11); subf 0,3,0; mullw 0,0,31; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 31f; bl _s803A42C4_15; b 32f; 31:; bl _s803A42C4_16; 32:; mr 11,29; cmpw 11,28; bne 28b; 33:; lwz 3,0x0(27); lis 9,-21846; lwz 0,0xc(27); ori 9,9,43691; cmpwi 3,0; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; beq 35f; mulli 4,0,24; cmplwi 4,128; ble 34f; bl _s803A42C4_17; b 35f; 34:; bl _s803A42C4_18; 35:; add 0,26,24; stw 24,0x0(27); stw 0,0xc(27); stw 30,0x4(27); 36:; lwz 0,0x54(1); lwz 12,0x28(1); mtspr 8,0; lmw 23,0x2c(1); mtcrf 8,12; addi 1,1,80"
extern "C" void _s803A42C4_0();
extern "C" void _s803A42C4_1();
extern "C" void _s803A42C4_2();
extern "C" void _s803A42C4_3();
extern "C" void _s803A42C4_4();
extern "C" void _s803A42C4_5();
extern "C" void _s803A42C4_6();
extern "C" void _s803A42C4_7();
extern "C" void _s803A42C4_8();
extern "C" void _s803A42C4_9();
extern "C" void _s803A42C4_10();
extern "C" void _s803A42C4_11();
extern "C" void _s803A42C4_12();
extern "C" void _s803A42C4_13();
extern "C" void _s803A42C4_14();
extern "C" void _s803A42C4_15();
extern "C" void _s803A42C4_16();
extern "C" void _s803A42C4_17();
extern "C" void _s803A42C4_18();
extern "C" void f_803A42C4() {}
