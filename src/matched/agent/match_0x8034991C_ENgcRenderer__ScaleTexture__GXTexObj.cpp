// 0x8034991C ENgcRenderer::ScaleTexture(_GXTexObj (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stfd f29,0x38(1); stfd f30,0x40(1); stfd f31,0x48(1); stmw 25,0x1c(1); stw 0,0x54(1); mr 30,6; xoris 0,30,32768; lis 26,17200; stw 0,0x14(1); lis 9,-32702; lfd f30,0x1f08(9); mr 29,3; stw 26,0x10(1); mr 27,4; lwz 10,0x4d8(29); mr 25,5; lfd f31,0x10(1); li 4,0; fmr f29,f1; rlwinm 28,30,0,16,31; fsub f31,f31,f30; frsp f31,f31; stfs f31,0x9b8(10); lwz 9,0x4d8(29); stfs f31,0x9bc(9); lwz 11,0x4d8(29); lwz 0,0x6cc(11); oris 0,0,32768; ori 0,0,512; stw 0,0x6cc(11); lwz 3,0x4d8(29); bl _s8034991C_0; rlwinm 30,30,1,0,30; xoris 30,30,32768; lis 11,-32702; stw 30,0x14(1); mr 3,29; lfs f1,0x1f10(11); stw 26,0x10(1); fdivs f31,f1,f31; lfd f0,0x10(1); fsub f0,f0,f30; frsp f0,f0; fdivs f1,f1,f0; fmsubs f1,f1,f29,f31; fmr f2,f1; bl _s8034991C_1; bl _s8034991C_2; mr 3,27; bl _s8034991C_3; mr 7,3; li 8,2; li 9,2; li 10,0; mr 3,27; mr 4,25; mr 5,28; mr 6,28; bl _s8034991C_4; li 4,0; mr 5,28; mr 6,28; li 3,0; bl _s8034991C_5; mr 3,27; bl _s8034991C_6; mr 5,3; li 6,0; mr 3,28; mr 4,3; bl _s8034991C_7; mr 3,25; li 4,1; bl _s8034991C_8; bl _s8034991C_9; lwz 0,0x54(1); mtspr 8,0; lmw 25,0x1c(1); lfd f29,0x38(1); lfd f30,0x40(1); lfd f31,0x48(1); addi 1,1,80"
extern "C" void _s8034991C_0();
extern "C" void _s8034991C_1();
extern "C" void _s8034991C_2();
extern "C" void _s8034991C_3();
extern "C" void _s8034991C_4();
extern "C" void _s8034991C_5();
extern "C" void _s8034991C_6();
extern "C" void _s8034991C_7();
extern "C" void _s8034991C_8();
extern "C" void _s8034991C_9();
extern "C" void f_8034991C() {}
