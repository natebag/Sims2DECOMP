// 0x802166D0 InteractorModule::InteractorVisualizer::DrawPreviewOnAffectedWalls(InteractorModule::WallManipulator (1472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-336(1); mfspr 0,8; stfd f29,0x138(1); stfd f30,0x140(1); stfd f31,0x148(1); stmw 14,0xf0(1); stw 0,0x154(1); mr 29,3; addi 30,1,16; mr 26,4; addi 3,1,8; bl _s802166D0_0; mr 16,30; mr 3,30; bl _s802166D0_1; mr 3,29; mr 4,26; bl _s802166D0_2; mr. 3,3; beq 0f; lis 4,-31611; ori 4,4,13842; bl _s802166D0_3; mr. 27,3; beq 0f; addi 30,1,40; mr 3,29; bl _s802166D0_4; lwz 11,0x60(26); addi 9,26,96; lwz 7,0x8(9); addi 10,26,32; lwz 0,0x4(9); addi 29,1,56; stw 11,0x28(1); lwz 8,0x20(26); stw 7,0x8(30); stw 0,0x4(30); lwz 0,0x4(10); lwz 9,0x8(10); stw 8,0x38(1); stw 0,0x4(29); stw 9,0x8(29); bl _s802166D0_5; lwz 4,0x0(26); bl _s802166D0_6; addi 6,1,24; mr 4,30; mr 5,29; bl _s802166D0_7; lfs f9,0x28(1); mr 3,30; lfs f6,0x18(1); mr 4,29; lfs f10,0x2c(1); addi 5,1,8; lfs f7,0x1c(1); fadds f9,f9,f6; lfs f11,0x30(1); mr 6,16; lfs f8,0x20(1); fadds f10,f10,f7; lfs f13,0x38(1); lfs f12,0x3c(1); fadds f11,f11,f8; lfs f0,0x40(1); fadds f13,f13,f6; fadds f12,f12,f7; stfs f9,0x28(1); fadds f0,f0,f8; stfs f10,0x2c(1); stfs f11,0x30(1); stfs f13,0x38(1); stfs f12,0x3c(1); stfs f0,0x40(1); bl _s802166D0_8; addi 3,1,8; mr 4,16; bl _s802166D0_9; mr 24,3; cmpwi 24,8; bne 1f; 0:; mr 3,16; li 4,2; bl _s802166D0_10; addi 3,1,8; li 4,2; bl _s802166D0_11; li 3,0; b 15f; 1:; addi 29,1,72; mr 3,24; bl _s802166D0_12; mr 20,29; mr 19,3; addi 30,1,144; mr 3,29; lwz 25,-21488(13); bl _s802166D0_13; mr 23,30; lfs f0,0x28(1); addi 29,1,160; lfs f13,0x2c(1); mr 5,30; lfs f12,0x30(1); addi 28,1,168; stfs f0,0x90(1); mr 3,24; stfs f13,0x94(1); li 4,1; stfs f12,0x98(1); rlwinm 30,24,1,0,30; stfs f0,0x80(1); mr 31,30; stfs f13,0x84(1); mr 21,29; stfs f12,0x88(1); li 14,0; bl _s802166D0_14; addi 4,1,8; mr 3,29; bl _s802166D0_15; lis 5,-32696; add 30,30,24; addi 5,5,24096; mr 3,28; mr 4,29; add 5,30,5; bl _s802166D0_16; lwz 3,0x14(27); lwz 4,-28504(13); cmpwi 3,0; beq 2f; mr 11,3; b 3f; 2:; lwz 3,0x18(27); li 11,0; cmpwi 3,0; beq 3f; lwz 11,0x14(3); 3:; lwz 9,0xf0(11); add 0,31,24; li 5,0; addi 31,1,176; lha 3,0x10(9); addi 17,1,168; stw 0,0xe8(1); addi 18,1,128; lwz 0,0x14(9); add 3,11,3; li 22,128; li 15,0; mtspr 8,0; blrl; lis 9,-32704; lis 10,-32704; lis 11,-32704; lfs f30,-10384(9); lfs f29,-10388(10); lfs f31,-10392(11); b 13f; 4:; lwz 9,0x0(25); mr 5,21; mr 3,31; mr 27,31; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,25,4; blrl; mr 4,31; mr 3,20; bl _s802166D0_17; mr 3,31; li 4,2; bl _s802166D0_18; lwz 0,0xc4(26); andi. 9,0,512; beq 5f; mr 3,20; mr 4,19; bl _s802166D0_19; b 7f; 5:; andi. 9,0,256; beq 6f; mr 3,20; mr 4,19; bl _s802166D0_20; b 7f; 6:; mr 3,20; mr 4,19; bl _s802166D0_21; 7:; cmpwi 3,0; beq 12f; lwz 3,-28504(13); li 4,320; li 5,32; bl _s802166D0_22; mr 28,3; li 0,127; stw 0,0x14(28); stw 22,0x30(28); stw 22,0x34(28); stw 22,0x38(28); stw 22,0x3c(28); stw 15,0x10(28); stw 15,0x18(28); stw 15,0x1c(28); stfs f31,0xb0(1); stfs f31,0x4(27); lfs f0,0xb0(1); stfs f0,0x20(28); lfs f13,0xb4(1); stfs f13,0x24(28); lwz 0,0xc4(26); andi. 9,0,256; beq 8f; lfs f12,-21092(13); b 9f; 8:; lfs f12,-21096(13); 9:; lfs f13,0x80(1); addi 30,28,80; lfs f0,0x84(1); mr 3,30; stfs f31,0xc(28); mr 4,28; stfs f13,0x0(28); stfs f0,0x4(28); stfs f12,0x8(28); bl _s802166D0_23; stfs f31,0xb0(1); mr 9,30; stfs f30,0x4(27); lfs f0,0xb0(1); stfs f0,0x70(28); lfs f13,0xb4(1); stfs f13,0x74(28); lwz 0,0xc4(26); andi. 11,0,256; beq 10f; lfs f12,-21092(13); b 11f; 10:; lfs f12,-21096(13); 11:; lfs f0,0x90(1); addi 30,28,160; lfs f13,0x94(1); mr 4,28; stfs f0,0x50(28); mr 3,30; stfs f12,0x8(9); addi 29,28,240; stfs f13,0x4(9); addi 14,14,1; stfs f31,0xc(9); bl _s802166D0_24; stfs f30,0xb0(1); mr 4,28; stfs f31,0x4(27); mr 3,29; lfs f0,0xb0(1); stfs f0,0xc0(28); lfs f13,0xb4(1); stfs f13,0xc4(28); lfs f0,0x80(1); lfs f13,0x84(1); stfs f0,0xa0(28); stfs f31,0xc(30); stfs f29,0x8(30); stfs f13,0x4(30); bl _s802166D0_25; stfs f30,0xb0(1); li 4,1; stfs f30,0x4(27); li 5,2; lwz 11,-28504(13); li 7,0; lfs f13,0xb0(1); li 6,0; stfs f13,0x110(28); lfs f0,0xb4(1); stfs f0,0x114(28); lfs f13,0x90(1); lfs f0,0x94(1); stfs f13,0xf0(28); stfs f0,0x4(29); stfs f31,0xc(29); stfs f29,0x8(29); lwz 9,0x70(11); lwz 0,0x1cc(9); lha 3,0x1c8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-28504(13); lwz 9,0x70(11); lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-28504(13); mr 4,28; li 5,4; lwz 9,0x70(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 12:; mr 4,17; mr 3,21; bl _s802166D0_26; lis 9,-32696; lwz 11,0xe8(1); addi 4,9,24096; mr 3,17; add 4,11,4; bl _s802166D0_27; li 0,1; lwz 11,0x90(1); stb 0,0xaa(1); mr 3,24; li 4,1; mr 5,23; lwz 9,0x4(23); lwz 0,0x8(23); stw 11,0x80(1); stw 9,0x4(18); stw 0,0x8(18); bl _s802166D0_28; 13:; lwz 9,0x0(25); mr 4,21; lha 3,0x58(9); lwz 0,0x5c(9); add 3,25,3; mtspr 8,0; blrl; cmpwi 3,0; bne 14f; mr 3,21; mr 4,16; bl _s802166D0_29; cmpwi 3,0; bne 4b; 14:; addi 3,1,168; li 4,2; bl _s802166D0_30; mr 3,21; li 4,2; bl _s802166D0_31; mr 3,20; li 4,2; bl _s802166D0_32; mr 3,16; li 4,2; bl _s802166D0_33; addi 3,1,8; li 4,2; bl _s802166D0_34; mr 3,14; 15:; lwz 0,0x154(1); mtspr 8,0; lmw 14,0xf0(1); lfd f29,0x138(1); lfd f30,0x140(1); lfd f31,0x148(1); addi 1,1,336"
extern "C" void _s802166D0_0();
extern "C" void _s802166D0_1();
extern "C" void _s802166D0_2();
extern "C" void _s802166D0_3();
extern "C" void _s802166D0_4();
extern "C" void _s802166D0_5();
extern "C" void _s802166D0_6();
extern "C" void _s802166D0_7();
extern "C" void _s802166D0_8();
extern "C" void _s802166D0_9();
extern "C" void _s802166D0_10();
extern "C" void _s802166D0_11();
extern "C" void _s802166D0_12();
extern "C" void _s802166D0_13();
extern "C" void _s802166D0_14();
extern "C" void _s802166D0_15();
extern "C" void _s802166D0_16();
extern "C" void _s802166D0_17();
extern "C" void _s802166D0_18();
extern "C" void _s802166D0_19();
extern "C" void _s802166D0_20();
extern "C" void _s802166D0_21();
extern "C" void _s802166D0_22();
extern "C" void _s802166D0_23();
extern "C" void _s802166D0_24();
extern "C" void _s802166D0_25();
extern "C" void _s802166D0_26();
extern "C" void _s802166D0_27();
extern "C" void _s802166D0_28();
extern "C" void _s802166D0_29();
extern "C" void _s802166D0_30();
extern "C" void _s802166D0_31();
extern "C" void _s802166D0_32();
extern "C" void _s802166D0_33();
extern "C" void _s802166D0_34();
extern "C" void f_802166D0() {}
