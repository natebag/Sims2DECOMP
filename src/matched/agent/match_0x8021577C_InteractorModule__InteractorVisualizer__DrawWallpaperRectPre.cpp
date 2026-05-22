// 0x8021577C InteractorModule::InteractorVisualizer::DrawWallpaperRectPreview(ERShader (1176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-304(1); mfspr 0,8; stfd f28,0x110(1); stfd f29,0x118(1); stfd f30,0x120(1); stfd f31,0x128(1); stmw 14,0xc8(1); stw 0,0x134(1); mr 26,3; addi 30,1,16; mr 31,5; mr 28,6; fmr f28,f1; addi 3,1,8; bl _s8021577C_0; mr 15,30; addi 29,1,24; mr 3,30; bl _s8021577C_1; mr 16,29; lis 9,-32704; lfs f11,0x4(28); lfs f0,0x0(31); addi 4,1,40; lfs f13,0x4(31); mr 22,4; lfs f12,0x0(28); mr 3,29; lfs f31,-10448(9); addi 5,1,8; stfs f0,0x18(1); mr 6,30; stfs f13,0x1c(1); stfs f12,0x28(1); stfs f11,0x2c(1); stfs f31,0x20(1); stfs f31,0x30(1); bl _s8021577C_2; addi 3,1,8; mr 4,30; bl _s8021577C_3; mr 24,3; cmpwi 24,8; bne 0f; mr 3,15; li 4,2; bl _s8021577C_4; addi 3,1,8; li 4,2; bl _s8021577C_5; li 3,0; b 5f; 0:; addi 27,1,56; mr 3,24; bl _s8021577C_6; rlwinm 29,24,1,0,30; mr 14,3; addi 28,1,112; lwz 23,-21488(13); mr 3,27; bl _s8021577C_7; li 17,0; lfs f13,0x4(31); addi 30,1,128; lfs f0,0x0(31); mr 5,28; stfs f13,0x74(1); mr 3,24; stfs f0,0x70(1); li 4,1; stfs f31,0x78(1); stfs f0,0x18(1); stfs f13,0x1c(1); stfs f31,0x20(1); bl _s8021577C_8; addi 4,1,8; mr 3,22; bl _s8021577C_9; lis 5,-32696; add 0,29,24; addi 5,5,24096; mr 3,30; add 5,0,5; mr 4,22; bl _s8021577C_10; mr 3,26; bl _s8021577C_11; mr 18,27; mr 21,28; mr 19,30; mr 20,29; b 3f; 1:; lwz 9,0x0(23); addi 31,1,136; mr 5,22; mr 3,31; lha 4,0xa8(9); lwz 0,0xac(9); add 4,23,4; mtspr 8,0; blrl; mr 4,31; mr 3,18; bl _s8021577C_12; mr 3,31; li 4,2; bl _s8021577C_13; mr 3,18; mr 4,14; bl _s8021577C_14; cmpwi 3,0; beq 2f; lwz 3,-28504(13); li 5,32; li 4,320; lis 26,17200; bl _s8021577C_15; addi 17,17,1; li 0,1; xoris 0,0,32768; mr 30,3; stw 0,0xc4(1); li 9,128; li 11,255; li 0,127; stw 11,0x1c(30); lis 8,-32704; stw 9,0x3c(30); addi 29,30,80; stw 0,0x14(30); mr 4,30; stw 9,0x30(30); mr 3,29; stw 9,0x34(30); addi 28,30,160; stw 9,0x38(30); addi 27,30,240; stw 25,0x10(30); stw 25,0x18(30); stw 26,0xc0(1); lfd f29,-10440(8); lfd f30,0xc0(1); fsub f30,f30,f29; frsp f30,f30; stfs f30,0x88(1); stfs f30,0x4(31); lfs f0,0x88(1); stfs f0,0x20(30); lfs f13,0x8c(1); stfs f13,0x24(30); lfs f0,0x18(1); lfs f13,0x1c(1); stfs f28,0x8(30); stfs f30,0xc(30); stfs f0,0x0(30); stfs f13,0x4(30); bl _s8021577C_16; xoris 0,25,32768; stw 0,0xc4(1); mr 4,30; stfs f30,0x88(1); mr 3,28; stw 26,0xc0(1); lfd f31,0xc0(1); fsub f31,f31,f29; frsp f31,f31; stfs f31,0x4(31); lfs f0,0x88(1); stfs f0,0x70(30); lfs f13,0x8c(1); stfs f13,0x74(30); lfs f0,0x70(1); lfs f13,0x74(1); stfs f0,0x50(30); stfs f30,0xc(29); stfs f28,0x8(29); stfs f13,0x4(29); bl _s8021577C_17; stfs f31,0x88(1); lis 9,-32704; stfs f30,0x4(31); mr 4,30; lfs f29,-10432(9); mr 3,27; lfs f0,0x88(1); stfs f0,0xc0(30); lfs f13,0x8c(1); stfs f13,0xc4(30); lfs f0,0x18(1); lfs f13,0x1c(1); stfs f0,0xa0(30); stfs f30,0xc(28); stfs f29,0x8(28); stfs f13,0x4(28); bl _s8021577C_18; stfs f31,0x88(1); li 4,1; stfs f31,0x4(31); li 5,2; lwz 11,-28504(13); li 7,0; lfs f13,0x88(1); li 6,0; stfs f13,0x110(30); lfs f0,0x8c(1); stfs f0,0x114(30); lfs f13,0x70(1); lfs f0,0x74(1); stfs f13,0xf0(30); stfs f0,0x4(27); stfs f30,0xc(27); stfs f29,0x8(27); lwz 9,0x70(11); lwz 0,0x1cc(9); lha 3,0x1c8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-28504(13); lwz 9,0x70(11); lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-28504(13); mr 4,30; li 5,4; lwz 9,0x70(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 2:; mr 4,19; mr 3,22; bl _s8021577C_19; lis 4,-32696; add 0,20,24; addi 4,4,24096; mr 3,19; add 4,0,4; bl _s8021577C_20; lwz 10,0x70(1); li 0,1; lwz 11,0x4(21); mr 3,24; lwz 9,0x8(21); li 4,1; stb 0,0x82(1); mr 5,21; stw 10,0x18(1); stw 11,0x4(16); stw 9,0x8(16); bl _s8021577C_21; 3:; lwz 9,0x0(23); mr 4,22; lha 3,0x58(9); lwz 0,0x5c(9); add 3,23,3; mtspr 8,0; blrl; mr. 25,3; bne 4f; mr 3,22; mr 4,15; bl _s8021577C_22; cmpwi 3,0; bne 1b; 4:; mr 3,19; li 4,2; bl _s8021577C_23; mr 3,22; li 4,2; bl _s8021577C_24; mr 3,18; li 4,2; bl _s8021577C_25; mr 3,15; li 4,2; bl _s8021577C_26; addi 3,1,8; li 4,2; bl _s8021577C_27; mr 3,17; 5:; lwz 0,0x134(1); mtspr 8,0; lmw 14,0xc8(1); lfd f28,0x110(1); lfd f29,0x118(1); lfd f30,0x120(1); lfd f31,0x128(1); addi 1,1,304"
extern "C" void _s8021577C_0();
extern "C" void _s8021577C_1();
extern "C" void _s8021577C_2();
extern "C" void _s8021577C_3();
extern "C" void _s8021577C_4();
extern "C" void _s8021577C_5();
extern "C" void _s8021577C_6();
extern "C" void _s8021577C_7();
extern "C" void _s8021577C_8();
extern "C" void _s8021577C_9();
extern "C" void _s8021577C_10();
extern "C" void _s8021577C_11();
extern "C" void _s8021577C_12();
extern "C" void _s8021577C_13();
extern "C" void _s8021577C_14();
extern "C" void _s8021577C_15();
extern "C" void _s8021577C_16();
extern "C" void _s8021577C_17();
extern "C" void _s8021577C_18();
extern "C" void _s8021577C_19();
extern "C" void _s8021577C_20();
extern "C" void _s8021577C_21();
extern "C" void _s8021577C_22();
extern "C" void _s8021577C_23();
extern "C" void _s8021577C_24();
extern "C" void _s8021577C_25();
extern "C" void _s8021577C_26();
extern "C" void _s8021577C_27();
extern "C" void f_8021577C() {}
