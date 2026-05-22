// 0x802C9934 EMat4::RotateZ(float) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); mr 30,3; fmr f31,f1; bl _s802C9934_0; fmr f1,f31; bl _s802C9934_1; fmr f30,f1; fmr f1,f31; bl _s802C9934_2; fneg f0,f30; mr 3,30; stfs f1,0x0(30); stfs f0,0x10(30); stfs f30,0x4(30); stfs f1,0x14(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802C9934_0();
extern "C" void _s802C9934_1();
extern "C" void _s802C9934_2();
extern "C" void f_802C9934() {}
