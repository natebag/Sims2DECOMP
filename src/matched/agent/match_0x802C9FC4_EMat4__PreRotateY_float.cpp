// 0x802C9FC4 EMat4::PreRotateY(float) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); fmr f31,f1; mr 30,3; bl _s802C9FC4_0; fmr f30,f1; fmr f1,f31; bl _s802C9FC4_1; lfs f13,0x20(30); fneg f11,f30; lfs f9,0x0(30); mr 3,30; fmuls f0,f1,f13; lfs f12,0x24(30); fmadds f0,f30,f9,f0; lfs f10,0x28(30); fmuls f13,f11,f13; stfs f0,0x20(30); fmadds f13,f1,f9,f13; lfs f9,0x4(30); fmuls f0,f1,f12; fmuls f12,f11,f12; stfs f13,0x0(30); fmadds f0,f30,f9,f0; fmadds f12,f1,f9,f12; stfs f0,0x24(30); lfs f9,0x8(30); fmuls f0,f1,f10; fmuls f11,f11,f10; stfs f12,0x4(30); fmadds f30,f30,f9,f0; fmadds f1,f1,f9,f11; stfs f30,0x28(30); stfs f1,0x8(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802C9FC4_0();
extern "C" void _s802C9FC4_1();
extern "C" void f_802C9FC4() {}
