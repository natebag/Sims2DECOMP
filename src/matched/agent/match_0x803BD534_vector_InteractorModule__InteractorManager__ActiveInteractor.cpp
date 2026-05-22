// 0x803BD534 vector<InteractorModule::InteractorManager::ActiveInteractor, (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; lwz 30,0x0(29); lwz 0,0xc(29); subf 0,30,0; srawi 0,0,3; cmplw 0,4; bge 13f; lwz 28,0x4(29); cmpwi 30,0; subf 0,30,28; srawi 27,0,3; beq 8f; cmpwi 4,0; beq 1f; rlwinm 0,4,3,0,28; mr 31,0; cmplwi 0,128; ble 0f; mr 3,31; bl _s803BD534_0; b 2f; 0:; mr 3,31; bl _s803BD534_1; b 2f; 1:; li 3,0; li 31,0; 2:; mr 11,30; rlwinm 27,27,3,0,28; mr 8,3; cmpw 11,28; beq 4f; 3:; lwz 9,0x0(11); lwz 10,0x4(11); addi 11,11,8; stw 9,0x0(8); stw 10,0x4(8); cmpw 11,28; addi 8,8,8; bne 3b; 4:; lwz 9,0x0(29); mr 30,3; lwz 11,0x4(29); mr 3,9; lwz 0,0xc(29); cmpw 9,11; beq 6f; 5:; addi 9,9,8; cmpw 9,11; bne 5b; 6:; subf 0,3,0; cmpwi 3,0; srawi 0,0,3; beq 12f; rlwinm 4,0,3,0,28; cmplwi 4,128; ble 7f; bl _s803BD534_2; b 12f; 7:; bl _s803BD534_3; b 12f; 8:; cmpwi 4,0; beq 10f; rlwinm 0,4,3,0,28; mr 31,0; cmplwi 0,128; ble 9f; mr 3,31; bl _s803BD534_4; b 11f; 9:; mr 3,31; bl _s803BD534_5; b 11f; 10:; li 3,0; li 31,0; 11:; mr 30,3; rlwinm 27,27,3,0,28; 12:; add 9,27,30; add 0,31,30; stw 0,0xc(29); stw 30,0x0(29); stw 9,0x4(29); 13:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803BD534_0();
extern "C" void _s803BD534_1();
extern "C" void _s803BD534_2();
extern "C" void _s803BD534_3();
extern "C" void _s803BD534_4();
extern "C" void _s803BD534_5();
extern "C" void f_803BD534() {}
