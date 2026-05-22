// 0x803A61B8 vector<byte_key_map<72, (596 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); mr 27,3; lis 9,-18725; lwz 31,0x0(27); ori 9,9,28087; lwz 0,0xc(27); subf 0,31,0; mullw 0,0,9; srawi 0,0,2; cmplw 0,4; bge 19f; lwz 23,0x4(27); cmpwi 31,0; subf 0,31,23; mullw 0,0,9; srawi 30,0,2; beq 14f; cmpwi 4,0; beq 1f; mulli 0,4,28; mr 26,0; cmplwi 0,128; ble 0f; mr 3,26; bl _s803A61B8_0; mr 25,3; b 2f; 0:; mr 3,26; bl _s803A61B8_1; mr 25,3; b 2f; 1:; li 25,0; li 26,0; 2:; mr 28,31; mulli 22,30,28; cmpw 28,23; beq 8f; li 24,0; addi 31,25,12; addi 29,28,12; 3:; lwz 0,-12(29); lwz 9,-8(29); lwz 11,-4(29); stw 0,-12(31); stw 9,-8(31); stw 11,-4(31); lwz 0,0x4(29); lwz 9,0x0(29); stw 24,0x0(31); subf 0,9,0; stw 24,0x4(31); srawi. 0,0,1; stw 24,0xc(31); beq 5f; add 0,0,0; mr 30,0; cmplwi 0,128; ble 4f; mr 3,30; bl _s803A61B8_2; b 6f; 4:; mr 3,30; bl _s803A61B8_3; b 6f; 5:; li 3,0; li 30,0; 6:; add 0,3,30; stw 3,0x0(31); stw 0,0xc(31); stw 3,0x4(31); lwz 4,0x0(29); lwz 30,0x4(29); cmpw 30,4; beq 7f; subf 30,4,30; mr 5,30; bl _s803A61B8_4; add 3,3,30; 7:; stw 3,0x4(31); addi 28,28,28; addi 29,29,28; addi 31,31,28; cmpw 28,23; bne 3b; 8:; lwz 30,0x4(27); mr 29,25; lwz 31,0x0(27); cmpw 31,30; beq 12f; 9:; lwz 3,0xc(31); addi 9,31,12; cmpwi 3,0; beq 11f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,30; cmplwi 4,128; ble 10f; bl _s803A61B8_5; b 11f; 10:; bl _s803A61B8_6; 11:; addi 31,31,28; cmpw 31,30; bne 9b; 12:; lwz 3,0x0(27); lis 9,-18725; lwz 0,0xc(27); ori 9,9,28087; cmpwi 3,0; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; beq 18f; mulli 4,0,28; cmplwi 4,128; ble 13f; bl _s803A61B8_7; b 18f; 13:; bl _s803A61B8_8; b 18f; 14:; cmpwi 4,0; beq 16f; mulli 0,4,28; mr 26,0; cmplwi 0,128; ble 15f; mr 3,26; bl _s803A61B8_9; b 17f; 15:; mr 3,26; bl _s803A61B8_10; b 17f; 16:; li 3,0; li 26,0; 17:; mulli 22,30,28; mr 29,3; 18:; add 9,22,29; add 0,26,29; stw 0,0xc(27); stw 29,0x0(27); stw 9,0x4(27); 19:; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"
extern "C" void _s803A61B8_0();
extern "C" void _s803A61B8_1();
extern "C" void _s803A61B8_2();
extern "C" void _s803A61B8_3();
extern "C" void _s803A61B8_4();
extern "C" void _s803A61B8_5();
extern "C" void _s803A61B8_6();
extern "C" void _s803A61B8_7();
extern "C" void _s803A61B8_8();
extern "C" void _s803A61B8_9();
extern "C" void _s803A61B8_10();
extern "C" void f_803A61B8() {}
