// 0x80373954 C_MTXLightPerspective (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-88(1); stfd f31,0x50(1); stfd f30,0x48(1); stfd f29,0x40(1); stfd f28,0x38(1); stfd f27,0x30(1); stw 31,0x2c(1); fmr f27,f2; mr 31,3; fmr f28,f3; fmr f29,f4; fmr f30,f5; fmr f31,f6; lfs f2,-17960(13); lfs f0,-17940(13); fmuls f1,f2,f1; fmuls f1,f0,f1; bl _s80373954_0; lfs f3,-17968(13); fneg f2,f30; fneg f0,f31; fdivs f4,f3,f1; fdivs f1,f4,f27; fmuls f3,f28,f1; fmuls f1,f4,f29; stfs f3,0x0(31); lfs f3,-17964(13); stfs f3,0x4(31); stfs f2,0x8(31); stfs f3,0xc(31); stfs f3,0x10(31); stfs f1,0x14(31); stfs f0,0x18(31); stfs f3,0x1c(31); stfs f3,0x20(31); stfs f3,0x24(31); lfs f0,-17944(13); stfs f0,0x28(31); stfs f3,0x2c(31); lwz 0,0x5c(1); lfd f31,0x50(1); lfd f30,0x48(1); lfd f29,0x40(1); lfd f28,0x38(1); lfd f27,0x30(1); lwz 31,0x2c(1); addi 1,1,88; mtspr 8,0"
extern "C" void _s80373954_0();
extern "C" void f_80373954() {}
