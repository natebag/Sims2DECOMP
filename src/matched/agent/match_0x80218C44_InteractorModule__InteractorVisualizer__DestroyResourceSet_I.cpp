// 0x80218C44 InteractorModule::InteractorVisualizer::DestroyResourceSet(InteractorModule::Interactor (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); addi 7,3,8; lwz 30,0x8(3); lwz 0,0x4(7); addi 6,1,8; stw 4,0x8(1); subf 0,30,0; srawi. 10,0,7; ble 3f; 0:; srawi 11,10,1; rlwinm 9,11,7,0,24; lwzx 0,30,9; add 8,30,9; cmplw 0,4; blt 1f; mr 10,11; b 2f; 1:; subf 9,11,10; addi 30,8,128; addi 10,9,-1; 2:; cmpwi 10,0; bgt 0b; 3:; lwz 11,0x4(7); cmpw 30,11; beq 4f; lwz 9,0x0(6); lwz 0,0x0(30); cmplw 9,0; bge 4f; mr 30,11; 4:; addi 26,3,8; lwz 0,0x4(26); cmpw 30,0; li 3,0; beq 10f; addi 3,30,4; bl _s80218C44_0; lwz 0,0x4(26); addi 4,30,128; cmpw 4,0; beq 9f; mr 28,4; mr 31,30; subf 0,28,0; srawi. 27,0,7; ble 9f; addi 29,31,44; addi 30,31,172; 5:; lwz 0,-44(30); addi 3,31,4; addi 4,28,4; stw 0,-44(29); cmpw 3,4; beq 6f; bl _s80218C44_1; lbz 0,-24(30); stb 0,-24(29); 6:; addi 3,31,24; addi 4,28,24; cmpw 3,4; beq 7f; bl _s80218C44_2; lbz 0,-4(30); stb 0,-4(29); 7:; cmpw 29,30; beq 8f; mr 3,29; mr 4,30; bl _s80218C44_3; lbz 0,0x10(30); stb 0,0x10(29); 8:; addi 4,28,64; addi 3,31,64; bl _s80218C44_4; addi 30,30,128; addi 4,28,80; addi 3,31,80; bl _s80218C44_5; addi 29,29,128; addi 4,28,96; addi 3,31,96; bl _s80218C44_6; addi 3,31,112; addi 4,28,112; bl _s80218C44_7; addi 28,28,128; addi 31,31,128; addic. 27,27,-1; bgt 5b; 9:; lwz 3,0x4(26); li 4,2; addi 0,3,-128; addi 3,3,-124; stw 0,0x4(26); bl _s80218C44_8; li 3,1; 10:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s80218C44_0();
extern "C" void _s80218C44_1();
extern "C" void _s80218C44_2();
extern "C" void _s80218C44_3();
extern "C" void _s80218C44_4();
extern "C" void _s80218C44_5();
extern "C" void _s80218C44_6();
extern "C" void _s80218C44_7();
extern "C" void _s80218C44_8();
extern "C" void f_80218C44() {}
