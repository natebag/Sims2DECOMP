// 0x80307370 CalcTwoSides(float (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f28,0x18(1); stfd f29,0x20(1); stfd f30,0x28(1); stfd f31,0x30(1); stmw 29,0xc(1); stw 0,0x3c(1); lis 9,-32702; fmr f28,f2; lfs f29,-1284(9); fadds f0,f1,f28; fmr f30,f3; mr 29,3; fsubs f29,f29,f0; mr 30,4; bl _s80307370_0; fmr f31,f1; fmr f1,f28; bl _s80307370_1; fmr f28,f1; fmr f1,f29; bl _s80307370_2; fmuls f31,f30,f31; fmuls f30,f30,f28; fdivs f31,f31,f1; fdivs f30,f30,f1; stfs f31,0x0(29); stfs f30,0x0(30); lwz 0,0x3c(1); mtspr 8,0; lmw 29,0xc(1); lfd f28,0x18(1); lfd f29,0x20(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s80307370_0();
extern "C" void _s80307370_1();
extern "C" void _s80307370_2();
extern "C" void f_80307370() {}
