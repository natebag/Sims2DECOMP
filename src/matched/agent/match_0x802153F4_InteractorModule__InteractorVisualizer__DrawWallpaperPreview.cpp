// 0x802153F4 InteractorModule::InteractorVisualizer::DrawWallpaperPreviewOnAffectedWalls(InteractorModule::WallPainter (500 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 22,0x38(1); stw 0,0x64(1); mr 24,3; mr 26,4; bl _s802153F4_0; mr. 25,3; beq 2f; lwz 0,0x88(26); andi. 9,0,8; beq 0f; lis 4,-31611; mr 3,25; ori 4,4,13842; b 1f; 0:; mr 3,26; bl _s802153F4_1; mr 4,3; mr 3,25; 1:; bl _s802153F4_2; mr 31,3; cmpwi 31,0; bne 3f; 2:; li 3,0; b 8f; 3:; lwz 3,0x14(31); lwz 4,-28504(13); cmpwi 3,0; beq 4f; mr 11,3; b 5f; 4:; lwz 9,0x18(31); li 11,0; cmpwi 9,0; beq 5f; lwz 11,0x14(9); 5:; lwz 9,0xf0(11); li 5,0; addi 30,1,8; addi 27,1,24; lha 3,0x10(9); addi 29,26,96; lwz 0,0x14(9); addi 28,26,32; add 3,11,3; mr 22,29; mtspr 8,0; mr 23,28; blrl; lfs f0,0x60(26); lfs f11,0x4(29); lfs f10,0x8(29); stfs f0,0x8(1); lfs f0,0x4(28); lfs f13,0x20(26); lfs f12,0x8(28); stfs f11,0x4(30); stfs f10,0x8(30); stfs f13,0x18(1); stfs f0,0x1c(1); stfs f12,0x20(1); bl _s802153F4_3; lwz 4,0x0(26); bl _s802153F4_4; mr 4,30; addi 6,1,40; mr 5,27; bl _s802153F4_5; lfs f0,0x8(1); mr 5,30; lfs f13,0x28(1); mr 4,31; lfs f11,0x2c(1); mr 6,27; fadds f0,f0,f13; lfs f1,-21080(13); stfs f0,0x8(1); mr 3,24; lfs f0,0x4(30); lfs f12,0x8(30); fadds f0,f0,f11; stfs f0,0x4(30); lfs f13,0x30(1); fadds f12,f12,f13; stfs f12,0x8(30); lfs f0,0x18(1); lfs f13,0x1c(1); lfs f12,0x20(1); lfs f11,0x28(1); lfs f10,0x2c(1); lfs f9,0x30(1); fadds f0,f0,f11; fadds f13,f13,f10; stfs f0,0x18(1); fadds f12,f12,f9; stfs f13,0x1c(1); stfs f12,0x20(1); bl _s802153F4_6; mr. 30,3; beq 6f; lis 4,15177; mr 3,25; ori 4,4,19820; b 7f; 6:; lis 4,-5607; mr 3,25; ori 4,4,1515; 7:; bl _s802153F4_7; mr 31,3; lis 9,-32704; lfs f1,-21084(13); lfs f2,-10460(9); mr 3,24; mr 4,31; mr 5,22; mr 6,23; li 7,0; bl _s802153F4_8; mr 3,30; 8:; lwz 0,0x64(1); mtspr 8,0; lmw 22,0x38(1); addi 1,1,96"
extern "C" void _s802153F4_0();
extern "C" void _s802153F4_1();
extern "C" void _s802153F4_2();
extern "C" void _s802153F4_3();
extern "C" void _s802153F4_4();
extern "C" void _s802153F4_5();
extern "C" void _s802153F4_6();
extern "C" void _s802153F4_7();
extern "C" void _s802153F4_8();
extern "C" void f_802153F4() {}
