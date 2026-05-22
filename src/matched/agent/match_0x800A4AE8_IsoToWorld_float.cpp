// 0x800A4AE8 IsoToWorld(float (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f30,0x18(1); stfd f31,0x20(1); stmw 29,0xc(1); stw 0,0x2c(1); lis 9,-32706; lfs f31,0x0(5); lfs f30,-28580(9); mr 30,3; mr 29,4; mr 3,6; fmuls f31,f31,f30; bl _s800A4AE8_0; lfs f0,0x0(29); mr 3,30; stfs f31,0x0(30); fmuls f0,f0,f30; stfs f1,0x4(30); stfs f0,0x8(30); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0xc(1); lfd f30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s800A4AE8_0();
extern "C" void f_800A4AE8() {}
