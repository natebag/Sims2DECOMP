// 0x80234438 ERLevel::CalcRadiusFromViewParams(float, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f30,0x20(1); stfd f31,0x28(1); stmw 30,0x18(1); stw 0,0x34(1); lis 9,-32704; lis 11,-32704; lfs f0,-2856(9); fmr f30,f2; lfs f13,-2852(11); addi 30,1,8; fmuls f1,f1,f0; fmr f31,f3; fmuls f1,f1,f13; bl _s80234438_0; fmuls f1,f1,f30; mr 3,30; fmuls f31,f1,f31; stfs f1,0xc(1); stfs f31,0x8(1); stfs f30,0x8(30); bl _s80234438_1; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x18(1); lfd f30,0x20(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s80234438_0();
extern "C" void _s80234438_1();
extern "C" void f_80234438() {}
