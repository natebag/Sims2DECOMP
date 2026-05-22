// 0x80219230 InteractorModule::PlaceManipulator::OnCommandPressed(InteractorModule::InteractorInputManager::InteractorCommand, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,4; beq 3f; bgt 0f; cmpwi 4,0; beq 1f; b 7f; 0:; cmpwi 4,5; beq 5f; cmpwi 4,6; beq 6f; b 7f; 1:; lwz 0,0x64(3); li 9,1; cmpwi 0,0; bne 2f; li 9,0; 2:; cmpwi 9,0; beq 7f; bl _s80219230_0; b 7f; 3:; lwz 0,0x64(3); li 9,1; cmpwi 0,0; bne 4f; li 9,0; 4:; cmpwi 9,0; beq 7f; lwz 0,0xd0(3); cmpwi 0,0; beq 7f; bl _s80219230_1; b 7f; 5:; addi 3,3,100; li 4,1; bl _s80219230_2; b 7f; 6:; addi 3,3,100; li 4,0; bl _s80219230_3; 7:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80219230_0();
extern "C" void _s80219230_1();
extern "C" void _s80219230_2();
extern "C" void _s80219230_3();
extern "C" void f_80219230() {}
