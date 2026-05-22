// 0x80307408 CalcAdjacentSide(float (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); fmr f30,f2; mr 30,3; fmr f31,f3; bl _s80307408_0; fadds f0,f30,f30; fmuls f0,f0,f31; fmuls f31,f31,f31; fmuls f0,f0,f1; fmadds f30,f30,f30,f31; fsubs f1,f30,f0; bl _s80307408_1; stfs f1,0x0(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s80307408_0();
extern "C" void _s80307408_1();
extern "C" void f_80307408() {}
