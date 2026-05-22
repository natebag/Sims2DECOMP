// 0x802F1C34 EGraphics::DrawTiming(void) (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-304(1); mfspr 0,8; stfd f27,0x108(1); stfd f28,0x110(1); stfd f29,0x118(1); stfd f30,0x120(1); stfd f31,0x128(1); stmw 26,0xf0(1); stw 0,0x134(1); mr 31,3; lwz 0,0x14(31); cmpwi 0,0; beq 0f; lwz 0,0x90(31); cmpwi 0,0; beq 0f; lwz 9,0x0(31); li 4,0; lha 3,0x80(9); lwz 0,0x84(9); add 3,31,3; mtspr 8,0; blrl; mr 26,3; addi 3,1,24; bl _s802F1C34_0; addi 3,1,24; mr 4,26; bl _s802F1C34_1; lwz 3,0x90(31); mr 4,26; bl _s802F1C34_2; lwz 4,0x90(31); lis 5,-32702; addi 3,1,216; lfs f28,0x9c(31); addi 5,5,-4004; lfs f29,0xa0(31); li 6,0; li 7,1; li 8,0; li 30,0; bl _s802F1C34_3; li 28,1; xoris 0,30,32768; stw 0,0xec(1); lis 11,17200; lis 10,-32702; addi 27,1,224; stw 11,0xe8(1); lis 5,-32702; lfd f0,-3960(10); lis 11,-32702; lfd f31,0xe8(1); addi 29,1,184; lwz 3,0x90(31); mr 6,27; fsub f31,f31,f0; lfs f27,-3968(11); frsp f31,f31; lfs f30,0xd8(1); fadds f31,f29,f31; stw 30,0xc(1); stw 30,0x8(1); li 7,0; stw 28,0x10(1); li 8,0; stfs f28,0xe0(1); li 9,0; stfs f31,0xe4(1); li 10,0; mr 4,26; addi 5,5,-3996; bl _s802F1C34_4; fadds f30,f28,f30; lwz 5,-26788(13); lis 4,-32702; addi 4,4,-3988; mr 3,29; crxor 6,6,6; bl _s802F1C34_5; fadds f29,f29,f27; lwz 3,0x90(31); mr 5,29; stfs f31,0xe4(1); mr 4,26; stw 30,0x8(1); mr 6,27; stw 30,0xc(1); li 7,0; stw 28,0x10(1); li 8,0; stfs f30,0xe0(1); li 9,0; li 10,0; bl _s802F1C34_6; lwz 3,0x90(31); lis 5,-32702; stfs f28,0xe0(1); addi 5,5,-3984; stw 30,0x8(1); mr 6,27; stw 30,0xc(1); li 7,0; stw 28,0x10(1); li 8,0; stfs f29,0xe4(1); li 9,0; li 10,0; mr 4,26; bl _s802F1C34_7; lfs f0,-22744(13); lis 4,-32702; lfs f1,-26784(13); addi 4,4,-3976; mr 3,29; fdivs f1,f1,f0; creqv 6,6,6; bl _s802F1C34_8; lwz 3,0x90(31); li 9,0; mr 5,29; stw 30,0xc(1); mr 6,27; stw 28,0x10(1); stfs f30,0xe0(1); mr 4,26; stfs f29,0xe4(1); li 7,0; stw 30,0x8(1); li 8,0; li 10,0; bl _s802F1C34_9; lwz 9,0x0(31); mr 4,26; lha 3,0x88(9); lwz 0,0x8c(9); add 3,31,3; mtspr 8,0; blrl; addi 3,1,24; li 4,2; bl _s802F1C34_10; 0:; lwz 0,0x134(1); mtspr 8,0; lmw 26,0xf0(1); lfd f27,0x108(1); lfd f28,0x110(1); lfd f29,0x118(1); lfd f30,0x120(1); lfd f31,0x128(1); addi 1,1,304"
extern "C" void _s802F1C34_0();
extern "C" void _s802F1C34_1();
extern "C" void _s802F1C34_2();
extern "C" void _s802F1C34_3();
extern "C" void _s802F1C34_4();
extern "C" void _s802F1C34_5();
extern "C" void _s802F1C34_6();
extern "C" void _s802F1C34_7();
extern "C" void _s802F1C34_8();
extern "C" void _s802F1C34_9();
extern "C" void _s802F1C34_10();
extern "C" void f_802F1C34() {}
