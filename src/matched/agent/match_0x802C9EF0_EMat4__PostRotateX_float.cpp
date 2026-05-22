// 0x802C9EF0 EMat4::PostRotateX(float) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); fmr f30,f1; mr 30,3; bl _s802C9EF0_0; fmr f31,f1; fmr f1,f30; bl _s802C9EF0_1; lfs f13,0x8(30); fneg f9,f31; lfs f8,0x4(30); mr 3,30; fmuls f0,f13,f1; lfs f12,0x18(30); fmadds f0,f8,f31,f0; lfs f11,0x28(30); fmuls f13,f13,f9; stfs f0,0x8(30); fmadds f13,f8,f1,f13; lfs f10,0x38(30); lfs f8,0x14(30); fmuls f0,f12,f1; fmuls f12,f12,f9; stfs f13,0x4(30); fmadds f0,f8,f31,f0; fmadds f12,f8,f1,f12; stfs f0,0x18(30); lfs f8,0x24(30); fmuls f0,f11,f1; fmuls f11,f11,f9; stfs f12,0x14(30); fmadds f0,f8,f31,f0; fmadds f11,f8,f1,f11; stfs f0,0x28(30); lfs f8,0x34(30); fmuls f0,f10,f1; fmuls f10,f10,f9; stfs f11,0x24(30); fmadds f31,f8,f31,f0; fmadds f1,f8,f1,f10; stfs f31,0x38(30); stfs f1,0x34(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802C9EF0_0();
extern "C" void _s802C9EF0_1();
extern "C" void f_802C9EF0() {}
