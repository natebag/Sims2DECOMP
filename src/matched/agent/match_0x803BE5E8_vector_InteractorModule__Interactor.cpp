// 0x803BE5E8 vector<InteractorModule::Interactor (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 28,4; cmpw 28,29; beq 11f; lwz 27,0x4(28); lwz 31,0x0(28); lwz 0,0xc(29); lwz 3,0x0(29); subf 5,31,27; srawi 30,5,2; subf 0,3,0; srawi 0,0,2; cmplw 30,0; ble 6f; cmpwi 30,0; beq 1f; rlwinm 0,30,2,0,29; mr 30,0; cmplwi 0,128; ble 0f; mr 3,30; bl _s803BE5E8_0; mr 28,3; b 2f; 0:; mr 3,30; bl _s803BE5E8_1; mr 28,3; b 2f; 1:; li 28,0; li 30,0; 2:; cmpw 27,31; beq 3f; mr 4,31; mr 3,28; subf 5,4,27; bl _s803BE5E8_2; 3:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 5f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 4f; bl _s803BE5E8_3; b 5f; 4:; bl _s803BE5E8_4; 5:; add 0,28,30; stw 28,0x0(29); stw 0,0xc(29); b 10f; 6:; lwz 0,0x4(29); subf 0,3,0; srawi 0,0,2; cmplw 0,30; blt 8f; cmpw 27,31; beq 7f; mr 4,31; bl _s803BE5E8_5; 7:; rlwinm 30,30,2,0,29; b 10f; 8:; rlwinm 0,0,2,0,29; add 0,0,31; cmpw 0,31; beq 9f; mr 4,31; subf 5,4,0; bl _s803BE5E8_6; 9:; lwz 3,0x4(29); rlwinm 30,30,2,0,29; lwz 0,0x0(29); lwz 9,0x0(28); subf 0,0,3; lwz 5,0x4(28); rlwinm 0,0,0,0,29; add 4,0,9; cmpw 5,4; beq 10f; subf 5,4,5; bl _s803BE5E8_7; 10:; lwz 0,0x0(29); add 0,0,30; stw 0,0x4(29); 11:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803BE5E8_0();
extern "C" void _s803BE5E8_1();
extern "C" void _s803BE5E8_2();
extern "C" void _s803BE5E8_3();
extern "C" void _s803BE5E8_4();
extern "C" void _s803BE5E8_5();
extern "C" void _s803BE5E8_6();
extern "C" void _s803BE5E8_7();
extern "C" void f_803BE5E8() {}
