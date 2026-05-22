// 0x80217438 InteractorModule::InteractorVisualizer::DrawSimpleResourceSet(InteractorModule::Interactor (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stfd f31,0x60(1); stmw 26,0x48(1); stw 0,0x6c(1); mr 31,3; mr 27,4; mr 30,5; mr 28,6; fmr f31,f1; bl _s80217438_0; mr. 3,3; beq 0f; mr 4,30; bl _s80217438_1; mr. 26,3; beq 0f; li 0,0; addi 3,1,8; stw 0,0x110(31); addi 30,31,28; stw 0,0x10c(31); mr 29,3; lwz 9,0x0(28); lwz 0,0x4(28); lwz 11,0x8(28); stw 9,0x1c(31); stw 0,0x4(30); stw 11,0x8(30); bl _s80217438_2; lfs f12,0x8(27); addi 9,27,8; lfs f13,0x4(9); addi 11,1,56; lfs f0,0x8(9); mr 3,29; stfs f12,0x38(1); stfs f13,0x4(11); stfs f0,0x8(11); lfs f0,0x40(1); fadds f0,f0,f31; stfs f0,0x40(1); lfs f1,0x88(26); bl _s80217438_3; lwz 11,-28504(13); mr 4,30; lwz 9,0x70(11); lwz 0,0x16c(9); lha 3,0x168(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-28504(13); mr 4,29; li 5,1; lwz 9,0x70(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; lwz 4,-28504(13); mr 3,26; bl _s80217438_4; 0:; lwz 0,0x6c(1); mtspr 8,0; lmw 26,0x48(1); lfd f31,0x60(1); addi 1,1,104"
extern "C" void _s80217438_0();
extern "C" void _s80217438_1();
extern "C" void _s80217438_2();
extern "C" void _s80217438_3();
extern "C" void _s80217438_4();
extern "C" void f_80217438() {}
