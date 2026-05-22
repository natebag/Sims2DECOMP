// 0x802F1B3C EGraphics::SetUpNormalMapMatrix(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); lis 9,-32702; lis 11,-32702; lfs f31,-4028(9); addi 30,1,8; lfs f0,-4024(11); addi 29,3,64; stfs f31,0x8(1); mr 4,30; stfs f0,0x8(30); mr 3,29; stfs f31,0x4(30); bl _s802F1B3C_0; lis 9,-32702; stfs f31,0x8(1); lfs f0,-4020(9); mr 3,29; stfs f31,0x4(30); mr 4,30; stfs f0,0x8(30); bl _s802F1B3C_1; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s802F1B3C_0();
extern "C" void _s802F1B3C_1();
extern "C" void f_802F1B3C() {}
