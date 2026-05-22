// 0x802CD7B4 EQuat::Set(EVec3 (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f30,0x18(1); stfd f31,0x20(1); stmw 29,0xc(1); stw 0,0x2c(1); lis 9,-32702; mr 30,3; lfs f0,-7268(9); mr 29,4; fmuls f31,f1,f0; fmr f1,f31; bl _s802CD7B4_0; fmr f30,f1; fmr f1,f31; bl _s802CD7B4_1; lfs f13,0x0(29); mr 3,30; fmuls f13,f13,f30; stfs f13,0x0(30); lfs f0,0x4(29); fmuls f0,f0,f30; stfs f0,0x4(30); lfs f13,0x8(29); stfs f1,0xc(30); fmuls f13,f13,f30; stfs f13,0x8(30); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0xc(1); lfd f30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s802CD7B4_0();
extern "C" void _s802CD7B4_1();
extern "C" void f_802CD7B4() {}
