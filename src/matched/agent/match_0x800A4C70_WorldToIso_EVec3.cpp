// 0x800A4C70 WorldToIso(EVec3 (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 30,0x18(1); stw 0,0x2c(1); mr 31,4; lis 9,-32706; lfs f11,-28560(9); lis 11,-32706; lfs f12,0x8(31); mr 30,3; lfd f13,-28552(11); fmuls f31,f12,f11; fmr f0,f31; fcmpu 0,f0,f13; bge 0f; lis 9,-32706; lfs f1,-28544(9); fsubs f1,f31,f1; bl _s800A4C70_0; b 1f; 0:; lis 9,-32706; lfs f1,-28544(9); fadds f1,f31,f1; bl _s800A4C70_1; 1:; fmr f31,f1; lis 11,-32706; lfs f11,0x0(31); lfs f12,-28560(11); lis 9,-32706; lfd f13,-28552(9); fmuls f11,f11,f12; fmr f0,f11; fcmpu 0,f0,f13; bge 2f; lis 9,-32706; lfs f1,-28544(9); fsubs f1,f11,f1; bl _s800A4C70_2; b 3f; 2:; lis 9,-32706; lfs f1,-28544(9); fadds f1,f11,f1; bl _s800A4C70_3; 3:; fmr f11,f1; fmr f0,f31; fctiwz f13,f0; mr 11,9; stfd f13,0x10(1); fmr f12,f11; fctiwz f0,f12; mr 3,30; lwz 9,0x14(1); stfd f0,0x10(1); stw 9,0xc(1); lwz 11,0x14(1); stw 11,0x8(1); lwz 9,0x8(1); lwz 10,0xc(1); stw 9,0x0(30); stw 10,0x4(30); lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s800A4C70_0();
extern "C" void _s800A4C70_1();
extern "C" void _s800A4C70_2();
extern "C" void _s800A4C70_3();
extern "C" void f_800A4C70() {}
