// 0x803AC178 void (600 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); mr 29,3; mr 27,4; lwz 9,0x0(29); mr 25,5; lwz 0,0x4(29); addi 4,1,16; li 5,1; mr 3,27; subf 0,9,0; srawi 0,0,2; stw 0,0x10(1); bl _s803AC178_0; lwz 4,0x4(29); lwz 0,0x0(29); lwz 5,0x10(1); subf 0,0,4; srawi 9,0,2; cmplw 9,5; bge 0f; li 0,0; subf 5,9,5; stw 0,0x14(1); mr 3,29; addi 6,1,20; bl _s803AC178_1; 0:; lwz 0,0x4(29); lwz 9,0x0(29); lwz 11,0x10(1); subf 0,9,0; srawi 0,0,2; cmplw 0,11; ble 9f; 1:; lwz 9,0x4(29); lwzu 30,-4(9); mr 31,9; cmpwi 30,0; beq 6f; lwz 9,0x0(30); lwz 0,0x4(30); mr 3,9; cmpw 9,0; beq 3f; 2:; addi 9,9,4; cmpw 9,0; bne 2b; 3:; cmpwi 3,0; beq 5f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 4f; bl _s803AC178_2; b 5f; 4:; bl _s803AC178_3; 5:; mr 3,30; bl _s803AC178_4; 6:; lwz 30,0x4(29); addi 4,31,4; cmpw 30,4; beq 7f; subf 30,4,30; mr 3,31; mr 5,30; bl _s803AC178_5; add 3,3,30; b 8f; 7:; mr 3,31; 8:; lwz 0,0x0(29); lwz 9,0x10(1); subf 0,0,3; stw 3,0x4(29); srawi 0,0,2; cmplw 0,9; bgt 1b; 9:; lwz 31,0x0(29); lwz 0,0x4(29); cmpw 31,0; beq 20f; li 26,0; 10:; li 0,1; stw 0,0x18(1); lwz 0,0x0(31); cmpwi 0,0; bne 11f; stw 0,0x18(1); 11:; mr 3,27; addi 4,1,24; li 5,1; bl _s803AC178_6; lwz 0,0x18(1); cmpwi 0,0; beq 12f; lwz 30,0x0(31); addi 28,31,4; cmpwi 30,0; bne 18f; li 3,20; bl _s803AC178_7; stw 30,0x10(3); stw 30,0x0(3); stw 30,0x4(3); stw 30,0xc(3); stw 3,0x0(31); b 17f; 12:; lwz 30,0x0(31); addi 28,31,4; cmpwi 30,0; beq 17f; lwz 9,0x0(30); lwz 0,0x4(30); mr 3,9; cmpw 9,0; beq 14f; 13:; addi 9,9,4; cmpw 9,0; bne 13b; 14:; cmpwi 3,0; beq 16f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 15f; bl _s803AC178_8; b 16f; 15:; bl _s803AC178_9; 16:; mr 3,30; bl _s803AC178_10; stw 26,0x0(31); 17:; lwz 0,0x18(1); cmpwi 0,0; beq 19f; 18:; lwz 3,0x0(31); mr 4,27; mr 5,25; bl _s803AC178_11; 19:; lwz 0,0x4(29); mr 31,28; cmpw 31,0; bne 10b; 20:; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"
extern "C" void _s803AC178_0();
extern "C" void _s803AC178_1();
extern "C" void _s803AC178_2();
extern "C" void _s803AC178_3();
extern "C" void _s803AC178_4();
extern "C" void _s803AC178_5();
extern "C" void _s803AC178_6();
extern "C" void _s803AC178_7();
extern "C" void _s803AC178_8();
extern "C" void _s803AC178_9();
extern "C" void _s803AC178_10();
extern "C" void _s803AC178_11();
extern "C" void f_803AC178() {}
