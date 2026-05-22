// 0x802CA69C EMat4::GetHPR(float (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; lfs f2,0x28(30); mr 28,5; lfs f1,0x20(30); mr 27,6; bl _s802CA69C_0; stfs f1,0x0(29); lfs f1,0x28(30); lfs f0,0x20(30); fmuls f1,f1,f1; fmadds f1,f0,f0,f1; bl _s802CA69C_1; fmr f2,f1; lfs f1,0x24(30); bl _s802CA69C_2; fneg f1,f1; stfs f1,0x0(28); lfs f1,0x4(30); lfs f2,0x14(30); fneg f1,f1; bl _s802CA69C_3; fneg f1,f1; stfs f1,0x0(27); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802CA69C_0();
extern "C" void _s802CA69C_1();
extern "C" void _s802CA69C_2();
extern "C" void _s802CA69C_3();
extern "C" void f_802CA69C() {}
