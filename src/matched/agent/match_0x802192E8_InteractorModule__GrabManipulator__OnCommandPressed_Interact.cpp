// 0x802192E8 InteractorModule::GrabManipulator::OnCommandPressed(InteractorModule::InteractorInputManager::InteractorCommand, (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,4; beq 6f; bgt 0f; cmpwi 4,0; beq 1f; cmpwi 4,1; beq 4f; b 11f; 0:; cmpwi 4,5; beq 9f; cmpwi 4,6; beq 10f; b 11f; 1:; lwz 0,0x64(3); li 9,1; cmpwi 0,0; bne 2f; li 9,0; 2:; cmpwi 9,0; beq 3f; bl _s802192E8_0; b 11f; 3:; bl _s802192E8_1; b 11f; 4:; lwz 0,0x64(3); li 9,1; cmpwi 0,0; bne 5f; li 9,0; 5:; cmpwi 9,0; beq 11f; bl _s802192E8_2; b 11f; 6:; lwz 0,0x64(3); li 9,1; cmpwi 0,0; bne 7f; li 9,0; 7:; cmpwi 9,0; beq 8f; bl _s802192E8_3; b 11f; 8:; bl _s802192E8_4; b 11f; 9:; addi 3,3,100; li 4,1; bl _s802192E8_5; b 11f; 10:; addi 3,3,100; li 4,0; bl _s802192E8_6; 11:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802192E8_0();
extern "C" void _s802192E8_1();
extern "C" void _s802192E8_2();
extern "C" void _s802192E8_3();
extern "C" void _s802192E8_4();
extern "C" void _s802192E8_5();
extern "C" void _s802192E8_6();
extern "C" void f_802192E8() {}
