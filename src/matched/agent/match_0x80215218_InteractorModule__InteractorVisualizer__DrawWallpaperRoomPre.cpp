// 0x80215218 InteractorModule::InteractorVisualizer::DrawWallpaperRoomPreview(InteractorModule::WallPainter (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 28,0x40(1); stw 0,0x54(1); mr 31,3; mr 29,4; bl _s80215218_0; mr. 30,3; beq 5f; lis 9,-32697; li 28,0; lwz 9,0x5e94(9); cmpwi 9,0; beq 0f; lwz 28,0x8(9); 0:; addi 3,1,8; bl _s80215218_1; cmpwi 28,0; beq 4f; mr 3,29; bl _s80215218_2; mr 4,3; mr 3,30; bl _s80215218_3; mr. 9,3; bne 1f; addi 3,1,8; li 4,2; bl _s80215218_4; b 5f; 1:; lwz 3,0x14(9); lwz 4,-28504(13); cmpwi 3,0; beq 2f; mr 11,3; b 3f; 2:; lwz 3,0x18(9); li 11,0; cmpwi 3,0; beq 3f; lwz 11,0x14(3); 3:; lwz 9,0xf0(11); li 5,0; addi 30,1,48; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-28504(13); li 4,8; lwz 9,0x70(11); lwz 0,0x12c(9); lha 3,0x128(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; lis 8,-32696; stw 0,0x110(31); addi 7,8,32260; stw 0,0x10c(31); addi 11,31,28; lwz 6,-28504(13); mr 4,11; lwz 9,0x7e04(8); lwz 10,0x8(7); lwz 0,0x4(7); stw 9,0x1c(31); stw 10,0x8(11); stw 0,0x4(11); lwz 9,0x70(6); lwz 0,0x16c(9); lha 3,0x168(9); mtspr 8,0; add 3,6,3; blrl; lwz 0,0x60(29); addi 9,29,96; lwz 8,0x8(9); addi 11,1,32; lwz 10,0x4(9); addi 4,1,16; stw 0,0x20(1); mr 3,30; stw 8,0x8(11); stw 10,0x4(11); lfs f0,0x24(1); lfs f13,0x20(1); lfs f12,0x28(1); stfs f0,0x10(1); stfs f13,0x14(1); stfs f12,0x18(1); bl _s80215218_5; addi 3,1,8; mr 4,30; bl _s80215218_6; li 4,2; mr 3,30; bl _s80215218_7; addi 3,1,8; bl _s80215218_8; lfs f13,0xc(29); mr 5,3; lfs f0,0x8(29); mr 3,28; lwz 4,-28504(13); addi 6,1,56; stfs f0,0x38(1); stfs f13,0x3c(1); bl _s80215218_9; 4:; addi 3,1,8; li 4,2; bl _s80215218_10; 5:; lwz 0,0x54(1); mtspr 8,0; lmw 28,0x40(1); addi 1,1,80"
extern "C" void _s80215218_0();
extern "C" void _s80215218_1();
extern "C" void _s80215218_2();
extern "C" void _s80215218_3();
extern "C" void _s80215218_4();
extern "C" void _s80215218_5();
extern "C" void _s80215218_6();
extern "C" void _s80215218_7();
extern "C" void _s80215218_8();
extern "C" void _s80215218_9();
extern "C" void _s80215218_10();
extern "C" void f_80215218() {}
