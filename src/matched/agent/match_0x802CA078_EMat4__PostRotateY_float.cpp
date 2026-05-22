// 0x802CA078 EMat4::PostRotateY(float) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); fmr f31,f1; mr 30,3; bl _s802CA078_0; fmr f30,f1; fmr f1,f31; bl _s802CA078_1; lfs f13,0x8(30); fneg f10,f30; lfs f8,0x0(30); mr 3,30; fmuls f0,f13,f1; lfs f12,0x18(30); fmadds f0,f8,f10,f0; lfs f11,0x28(30); fmuls f13,f13,f30; stfs f0,0x8(30); fmadds f13,f8,f1,f13; lfs f9,0x38(30); lfs f8,0x10(30); fmuls f0,f12,f1; fmuls f12,f12,f30; stfs f13,0x0(30); fmadds f0,f8,f10,f0; fmadds f12,f8,f1,f12; stfs f0,0x18(30); lfs f8,0x20(30); fmuls f0,f11,f1; fmuls f11,f11,f30; stfs f12,0x10(30); fmadds f0,f8,f10,f0; fmadds f11,f8,f1,f11; stfs f0,0x28(30); lfs f8,0x30(30); fmuls f0,f9,f1; fmuls f9,f9,f30; stfs f11,0x20(30); fmadds f10,f8,f10,f0; fmadds f1,f8,f1,f9; stfs f10,0x38(30); stfs f1,0x30(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802CA078_0();
extern "C" void _s802CA078_1();
extern "C" void f_802CA078() {}
