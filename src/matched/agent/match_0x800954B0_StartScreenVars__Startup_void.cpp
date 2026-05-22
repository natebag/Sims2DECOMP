// 0x800954B0 StartScreenVars::Startup(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,3; bl _s800954B0_0; li 7,0; li 4,160; li 5,16; li 6,0; bl _s800954B0_1; bl _s800954B0_2; lwz 8,-26392(13); stw 3,0x20(30); lis 7,17200; lis 9,-32706; lis 10,-32706; lwz 0,0x1c(8); lfd f12,-30864(9); lis 8,-32706; xoris 0,0,32768; lfs f10,-30856(10); stw 0,0x1c(1); addi 9,1,8; lfs f13,0x18(30); mr 4,9; stw 7,0x18(1); lfs f9,-30872(8); lfd f0,0x18(1); lfs f11,0x10(30); fmuls f13,f13,f9; fsub f0,f0,f12; lfs f9,0x14(30); frsp f0,f0; fdivs f10,f10,f0; fsubs f12,f11,f13; stfs f12,0x8(1); fadds f11,f11,f13; fadds f10,f9,f10; stfs f9,0x4(9); stfs f11,0x8(9); stfs f10,0xc(9); bl _s800954B0_3; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s800954B0_0();
extern "C" void _s800954B0_1();
extern "C" void _s800954B0_2();
extern "C" void _s800954B0_3();
extern "C" void f_800954B0() {}
