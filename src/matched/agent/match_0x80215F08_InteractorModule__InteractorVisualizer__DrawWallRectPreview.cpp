// 0x80215F08 InteractorModule::InteractorVisualizer::DrawWallRectPreview(InteractorModule::WallManipulator (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f30,0x18(1); stfd f31,0x20(1); stmw 29,0xc(1); stw 0,0x2c(1); lis 9,-32704; mr 29,3; mr 30,4; lfs f30,-10424(9); bl _s80215F08_0; mr. 3,3; beq 4f; lwz 0,0xc4(30); andi. 9,0,128; beq 2f; andi. 9,0,4; beq 1f; andi. 9,0,256; beq 0f; lis 4,-25844; ori 4,4,25741; b 3f; 0:; lis 4,-30309; ori 4,4,41963; b 3f; 1:; lis 4,15177; ori 4,4,19820; b 3f; 2:; lis 4,30212; ori 4,4,49507; 3:; bl _s80215F08_1; mr 31,3; cmpwi 31,0; beq 4f; lfs f31,-21100(13); mr 3,30; bl _s80215F08_2; mr 7,3; addi 5,30,96; addi 6,30,32; mr 3,29; mr 4,31; fmr f1,f31; fmr f2,f30; bl _s80215F08_3; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0xc(1); lfd f30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s80215F08_0();
extern "C" void _s80215F08_1();
extern "C" void _s80215F08_2();
extern "C" void _s80215F08_3();
extern "C" void f_80215F08() {}
