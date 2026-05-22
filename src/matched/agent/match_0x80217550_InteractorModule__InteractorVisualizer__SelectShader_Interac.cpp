// 0x80217550 InteractorModule::InteractorVisualizer::SelectShader(InteractorModule::Interactor (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,5; bl _s80217550_0; mr. 0,3; li 3,0; beq 2f; mr 3,0; mr 4,31; bl _s80217550_1; mr. 9,3; li 3,0; beq 2f; lwz 3,0x14(9); lwz 4,-28504(13); cmpwi 3,0; beq 0f; mr 11,3; b 1f; 0:; lwz 3,0x18(9); li 11,0; cmpwi 3,0; beq 1f; lwz 11,0x14(3); 1:; lwz 9,0xf0(11); li 5,0; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; li 3,1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80217550_0();
extern "C" void _s80217550_1();
extern "C" void f_80217550() {}
