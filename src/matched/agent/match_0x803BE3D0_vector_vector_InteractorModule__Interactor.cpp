// 0x803BE3D0 vector<vector<InteractorModule::Interactor (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 23,0x14(1); stw 0,0x3c(1); mr 28,3; lwz 31,0x0(28); lwz 0,0xc(28); subf 0,31,0; srawi 0,0,4; cmplw 0,4; bge 19f; lwz 24,0x4(28); cmpwi 31,0; subf 0,31,24; srawi 30,0,4; beq 14f; cmpwi 4,0; beq 1f; rlwinm 0,4,4,0,27; mr 27,0; cmplwi 0,128; ble 0f; mr 3,27; bl _s803BE3D0_0; mr 26,3; b 2f; 0:; mr 3,27; bl _s803BE3D0_1; mr 26,3; b 2f; 1:; li 26,0; li 27,0; 2:; mr 29,31; rlwinm 23,30,4,0,27; mr 31,26; cmpw 29,24; beq 8f; li 25,0; 3:; lwz 0,0x4(29); addi 11,31,8; lwz 9,0x0(29); stw 25,0x0(31); subf 0,9,0; stw 25,0x4(31); srawi. 0,0,2; stw 25,0x4(11); beq 5f; rlwinm 0,0,2,0,29; mr 30,0; cmplwi 0,128; ble 4f; mr 3,30; bl _s803BE3D0_2; b 6f; 4:; mr 3,30; bl _s803BE3D0_3; b 6f; 5:; li 3,0; li 30,0; 6:; add 0,3,30; stw 3,0x0(31); stw 0,0xc(31); stw 3,0x4(31); lwz 4,0x0(29); lwz 30,0x4(29); cmpw 30,4; beq 7f; subf 30,4,30; mr 5,30; bl _s803BE3D0_4; add 3,3,30; 7:; stw 3,0x4(31); addi 29,29,16; addi 31,31,16; cmpw 29,24; bne 3b; 8:; lwz 31,0x4(28); mr 29,26; lwz 30,0x0(28); cmpw 30,31; beq 12f; 9:; lwz 3,0x0(30); cmpwi 3,0; beq 11f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 10f; bl _s803BE3D0_5; b 11f; 10:; bl _s803BE3D0_6; 11:; addi 30,30,16; cmpw 30,31; bne 9b; 12:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,4; beq 18f; rlwinm 4,0,4,0,27; cmplwi 4,128; ble 13f; bl _s803BE3D0_7; b 18f; 13:; bl _s803BE3D0_8; b 18f; 14:; cmpwi 4,0; beq 16f; rlwinm 0,4,4,0,27; mr 27,0; cmplwi 0,128; ble 15f; mr 3,27; bl _s803BE3D0_9; b 17f; 15:; mr 3,27; bl _s803BE3D0_10; b 17f; 16:; li 3,0; li 27,0; 17:; mr 29,3; rlwinm 23,30,4,0,27; 18:; add 9,23,29; add 0,27,29; stw 0,0xc(28); stw 29,0x0(28); stw 9,0x4(28); 19:; lwz 0,0x3c(1); mtspr 8,0; lmw 23,0x14(1); addi 1,1,56"
extern "C" void _s803BE3D0_0();
extern "C" void _s803BE3D0_1();
extern "C" void _s803BE3D0_2();
extern "C" void _s803BE3D0_3();
extern "C" void _s803BE3D0_4();
extern "C" void _s803BE3D0_5();
extern "C" void _s803BE3D0_6();
extern "C" void _s803BE3D0_7();
extern "C" void _s803BE3D0_8();
extern "C" void _s803BE3D0_9();
extern "C" void _s803BE3D0_10();
extern "C" void f_803BE3D0() {}
