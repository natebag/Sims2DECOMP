// 0x802CA14C EMat4::PreRotateZ(float) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); fmr f31,f1; mr 30,3; bl _s802CA14C_0; fmr f30,f1; fmr f1,f31; bl _s802CA14C_1; lfs f13,0x10(30); fneg f11,f30; lfs f9,0x0(30); mr 3,30; fmuls f0,f1,f13; lfs f12,0x14(30); fmadds f0,f11,f9,f0; lfs f10,0x18(30); fmuls f13,f30,f13; stfs f0,0x10(30); fmadds f13,f1,f9,f13; lfs f9,0x4(30); fmuls f0,f1,f12; fmuls f12,f30,f12; stfs f13,0x0(30); fmadds f0,f11,f9,f0; fmadds f12,f1,f9,f12; stfs f0,0x14(30); lfs f9,0x8(30); fmuls f0,f1,f10; fmuls f30,f30,f10; stfs f12,0x4(30); fmadds f11,f11,f9,f0; fmadds f1,f1,f9,f30; stfs f11,0x18(30); stfs f1,0x8(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802CA14C_0();
extern "C" void _s802CA14C_1();
extern "C" void f_802CA14C() {}
