// 0x803BF654 vector<pair<InteractorModule::Interactor (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 27,3; lwz 31,0x0(27); lwz 0,0xc(27); subf 0,31,0; srawi 0,0,7; cmplw 0,4; bge 13f; lwz 26,0x4(27); cmpwi 31,0; subf 0,31,26; srawi 30,0,7; beq 8f; cmpwi 4,0; beq 1f; rlwinm 0,4,7,0,24; mr 28,0; cmplwi 0,128; ble 0f; mr 3,28; bl _s803BF654_0; mr 29,3; b 2f; 0:; mr 3,28; bl _s803BF654_1; mr 29,3; b 2f; 1:; li 29,0; li 28,0; 2:; rlwinm 25,30,7,0,24; cmpw 31,26; mr 30,29; beq 4f; 3:; lwz 0,0x0(31); addi 3,30,4; addi 4,31,4; stw 0,0x0(30); addi 31,31,128; bl _s803BF654_2; addi 30,30,128; cmpw 31,26; bne 3b; 4:; lwz 30,0x4(27); lwz 31,0x0(27); cmpw 31,30; beq 6f; 5:; addi 3,31,4; li 4,2; bl _s803BF654_3; addi 31,31,128; cmpw 31,30; bne 5b; 6:; lwz 3,0x0(27); lwz 0,0xc(27); cmpwi 3,0; subf 0,3,0; srawi 0,0,7; beq 12f; rlwinm 4,0,7,0,24; cmplwi 4,128; ble 7f; bl _s803BF654_4; b 12f; 7:; bl _s803BF654_5; b 12f; 8:; cmpwi 4,0; beq 10f; rlwinm 0,4,7,0,24; mr 28,0; cmplwi 0,128; ble 9f; mr 3,28; bl _s803BF654_6; b 11f; 9:; mr 3,28; bl _s803BF654_7; b 11f; 10:; li 3,0; li 28,0; 11:; mr 29,3; rlwinm 25,30,7,0,24; 12:; add 9,25,29; add 0,28,29; stw 0,0xc(27); stw 29,0x0(27); stw 9,0x4(27); 13:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s803BF654_0();
extern "C" void _s803BF654_1();
extern "C" void _s803BF654_2();
extern "C" void _s803BF654_3();
extern "C" void _s803BF654_4();
extern "C" void _s803BF654_5();
extern "C" void _s803BF654_6();
extern "C" void _s803BF654_7();
extern "C" void f_803BF654() {}
