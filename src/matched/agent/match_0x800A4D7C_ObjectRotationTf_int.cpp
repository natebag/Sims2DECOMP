// 0x800A4D7C ObjectRotationTf(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); xoris 4,4,32768; stw 4,0x14(1); lis 0,17200; lis 11,-32706; lis 10,-32706; stw 0,0x10(1); lis 8,-32706; lfd f13,-28536(11); mr 30,3; lfd f0,0x10(1); lfs f11,-28528(10); li 4,1; fsub f0,f0,f13; lfs f12,-28524(8); frsp f0,f0; addi 5,1,8; fmuls f0,f0,f11; fadds f0,f0,f0; fmuls f0,f0,f12; stfs f0,0x8(1); bl _s800A4D7C_0; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s800A4D7C_0();
extern "C" void f_800A4D7C() {}
