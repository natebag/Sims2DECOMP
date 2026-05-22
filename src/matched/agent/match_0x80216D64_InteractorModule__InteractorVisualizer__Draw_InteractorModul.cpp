// 0x80216D64 InteractorModule::InteractorVisualizer::Draw(InteractorModule::ObjectManipulator (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stfd f31,0x80(1); stmw 27,0x6c(1); stw 0,0x8c(1); mr 31,4; mr 27,3; mr 3,31; bl _s80216D64_0; cmpwi 3,0; beq 0f; lwz 3,0x0(31); lis 9,-32697; addi 9,9,23428; addi 29,1,8; rlwinm 3,3,4,0,27; addi 30,1,88; addi 3,3,244; add 3,3,9; bl _s80216D64_1; mr 28,3; addi 3,1,8; bl _s80216D64_2; addi 9,31,8; lfs f12,0x8(31); lfs f13,0x8(9); lis 11,-32704; lfs f0,0x4(9); mr 4,30; lfs f31,-10380(11); mr 3,29; stfs f13,0x50(1); stfs f0,0x5c(1); stfs f0,0x4c(1); stfs f12,0x58(1); stfs f12,0x48(1); stfs f31,0x8(30); bl _s80216D64_3; lis 5,-29755; mr 6,28; ori 5,5,5330; mr 7,29; mr 3,27; mr 4,31; bl _s80216D64_4; lis 9,-32704; lfs f0,0x50(1); lfs f13,-10376(9); mr 4,30; stfs f31,0x58(1); mr 3,29; fadds f0,f0,f13; stfs f31,0x4(30); stfs f0,0x60(1); bl _s80216D64_5; lis 5,20155; mr 6,28; mr 7,29; mr 3,27; mr 4,31; ori 5,5,38535; bl _s80216D64_6; 0:; mr 3,31; bl _s80216D64_7; mr 4,3; lwz 0,0x28(4); cmpwi 0,0; beq 1f; mr 3,27; addi 5,31,32; bl _s80216D64_8; 1:; lwz 0,0x8c(1); mtspr 8,0; lmw 27,0x6c(1); lfd f31,0x80(1); addi 1,1,136"
extern "C" void _s80216D64_0();
extern "C" void _s80216D64_1();
extern "C" void _s80216D64_2();
extern "C" void _s80216D64_3();
extern "C" void _s80216D64_4();
extern "C" void _s80216D64_5();
extern "C" void _s80216D64_6();
extern "C" void _s80216D64_7();
extern "C" void _s80216D64_8();
extern "C" void f_80216D64() {}
