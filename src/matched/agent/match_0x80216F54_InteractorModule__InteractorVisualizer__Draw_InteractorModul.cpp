// 0x80216F54 InteractorModule::InteractorVisualizer::Draw(InteractorModule::SimInteractor (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stfd f31,0x78(1); stmw 24,0x58(1); stw 0,0x84(1); mr 29,4; mr 24,3; lwz 30,0x0(29); li 28,0; cmplwi 30,1; bgt 0f; rlwinm 0,30,2,0,29; addi 9,13,-21420; lwzx 0,9,0; cmpwi 0,0; beq 0f; mr 28,0; 0:; cmpwi 28,0; beq 1f; lis 3,-32697; mr 4,30; addi 3,3,24012; bl _s80216F54_0; mr 31,3; mr 4,30; mr 3,28; bl _s80216F54_1; cmpwi 31,0; beq 1f; lwz 3,0x0(31); lwz 9,0x4(3); lha 0,0x1a8(9); lwz 9,0x1ac(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; lwz 3,0x0(31); li 4,34; lwz 9,0x4(3); lha 0,0x260(9); lwz 9,0x264(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1f; lwz 4,-28504(13); mr 3,28; bl _s80216F54_2; 1:; mulli 0,30,12; lis 9,-32696; addi 9,9,21920; addi 25,29,8; addi 26,1,8; addi 28,1,72; addi 30,29,100; add 27,0,9; li 31,10; 2:; mr 3,30; bl _s80216F54_3; cmpwi 3,0; beq 3f; lwz 4,-28504(13); mr 3,30; mr 5,27; bl _s80216F54_4; 3:; addi 30,30,28; addic. 31,31,-1; bne 2b; lwz 11,-28504(13); lis 30,-32704; lfs f1,-10372(30); lwz 9,0x70(11); lwz 0,0x25c(9); lha 3,0x258(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x5c(29); lwz 0,0xcc(9); lha 3,0xc8(9); mtspr 8,0; add 3,29,3; blrl; fmr f31,f1; addi 3,1,8; bl _s80216F54_5; lfs f12,0x4(25); lis 9,-32704; lfs f0,0x8(29); mr 4,28; lfs f13,-10368(9); mr 3,26; stfs f0,0x48(1); stfs f12,0x4c(1); stfs f13,0x8(28); bl _s80216F54_6; lfs f0,-10372(30); mr 4,28; mr 3,26; stfs f0,0x48(1); stfs f0,0x4(28); stfs f31,0x50(1); bl _s80216F54_7; lis 5,4888; mr 3,24; mr 4,29; mr 6,27; mr 7,26; ori 5,5,30297; bl _s80216F54_8; lwz 0,0x84(1); mtspr 8,0; lmw 24,0x58(1); lfd f31,0x78(1); addi 1,1,128"
extern "C" void _s80216F54_0();
extern "C" void _s80216F54_1();
extern "C" void _s80216F54_2();
extern "C" void _s80216F54_3();
extern "C" void _s80216F54_4();
extern "C" void _s80216F54_5();
extern "C" void _s80216F54_6();
extern "C" void _s80216F54_7();
extern "C" void _s80216F54_8();
extern "C" void f_80216F54() {}
