// 0x802C985C EMat4::RotateX(float) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); mr 30,3; fmr f31,f1; bl _s802C985C_0; fmr f1,f31; bl _s802C985C_1; fmr f30,f1; fmr f1,f31; bl _s802C985C_2; fneg f0,f30; mr 3,30; stfs f1,0x14(30); stfs f0,0x24(30); stfs f30,0x18(30); stfs f1,0x28(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802C985C_0();
extern "C" void _s802C985C_1();
extern "C" void _s802C985C_2();
extern "C" void f_802C985C() {}
