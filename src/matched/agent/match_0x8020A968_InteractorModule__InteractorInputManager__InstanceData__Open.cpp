// 0x8020A968 InteractorModule::InteractorInputManager::InstanceData::OpenSession(int, (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,3; mr 0,4; lwz 3,-26524(13); mr 30,10; stw 5,0x1c(29); mr 31,6; mr 27,7; mr 26,8; mr 25,9; stw 0,0x18(29); bl _s8020A968_0; mr 28,3; mr. 5,30; bne 0f; lis 9,-32704; addi 5,9,-12060; 0:; mr 3,28; li 4,0; li 6,100; bl _s8020A968_1; stw 3,0x14(29); cmpwi 31,0; ble 2f; mr 30,27; 1:; lwz 4,0x4(30); mr 3,29; lwz 5,0x0(30); bl _s8020A968_2; lwz 5,0x0(30); mr 3,28; lwz 4,0x14(29); addi 30,30,8; bl _s8020A968_3; addic. 31,31,-1; bne 1b; 2:; cmpwi 26,0; ble 5f; mr 30,25; mr 31,26; 3:; lwz 4,0x4(30); mr 3,29; lha 5,0x0(30); lha 6,0x2(30); bl _s8020A968_4; lha 0,0x0(30); lis 5,240; lwz 4,0x14(29); cmpwi 0,0; bne 4f; lis 5,15; 4:; mr 3,28; addi 30,30,8; bl _s8020A968_5; addic. 31,31,-1; bne 3b; 5:; li 3,1; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8020A968_0();
extern "C" void _s8020A968_1();
extern "C" void _s8020A968_2();
extern "C" void _s8020A968_3();
extern "C" void _s8020A968_4();
extern "C" void _s8020A968_5();
extern "C" void f_8020A968() {}
