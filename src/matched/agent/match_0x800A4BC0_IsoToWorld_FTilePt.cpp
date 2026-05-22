// 0x800A4BC0 IsoToWorld(FTilePt (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f29,0x20(1); stfd f30,0x28(1); stfd f31,0x30(1); stmw 28,0x10(1); stw 0,0x3c(1); mr 29,4; lwz 0,0x0(29); lis 28,17200; lis 11,-32706; lis 10,-32706; xoris 0,0,32768; lfd f30,-28568(11); stw 0,0xc(1); mr 30,3; lfs f29,-28572(10); mr 3,5; stw 28,0x8(1); lfd f31,0x8(1); fsub f31,f31,f30; frsp f31,f31; fmuls f31,f31,f29; bl _s800A4BC0_0; lwz 0,0x4(29); stfs f31,0x0(30); mr 3,30; xoris 0,0,32768; stfs f1,0x4(30); stw 0,0xc(1); stw 28,0x8(1); lfd f0,0x8(1); fsub f0,f0,f30; frsp f0,f0; fmuls f0,f0,f29; stfs f0,0x8(30); lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x10(1); lfd f29,0x20(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s800A4BC0_0();
extern "C" void f_800A4BC0() {}
