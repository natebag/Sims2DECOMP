// 0x8030746C CalcThreeAngles(float (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f27,0x18(1); stfd f28,0x20(1); stfd f29,0x28(1); stfd f30,0x30(1); stfd f31,0x38(1); stmw 28,0x8(1); stw 0,0x44(1); fmr f29,f3; mr 29,3; fmr f31,f1; mr 28,4; fmuls f27,f2,f2; mr 30,5; fmuls f28,f29,f29; fmuls f30,f31,f31; fadds f2,f2,f2; fadds f1,f27,f28; fsubs f1,f1,f30; fmuls f2,f2,f29; fdivs f1,f1,f2; bl _s8030746C_0; fadds f30,f30,f28; fadds f31,f31,f31; fmr f28,f1; fsubs f30,f30,f27; fmuls f31,f31,f29; fdivs f1,f30,f31; bl _s8030746C_1; lis 9,-32702; stfs f28,0x0(29); lfs f0,-1280(9); fadds f13,f28,f1; stfs f1,0x0(28); fsubs f0,f0,f13; stfs f0,0x0(30); lwz 0,0x44(1); mtspr 8,0; lmw 28,0x8(1); lfd f27,0x18(1); lfd f28,0x20(1); lfd f29,0x28(1); lfd f30,0x30(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s8030746C_0();
extern "C" void _s8030746C_1();
extern "C" void f_8030746C() {}
