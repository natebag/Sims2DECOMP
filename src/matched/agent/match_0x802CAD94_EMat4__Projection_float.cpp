// 0x802CAD94 EMat4::Projection(float, (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f27,0x10(1); stfd f28,0x18(1); stfd f29,0x20(1); stfd f30,0x28(1); stfd f31,0x30(1); stmw 30,0x8(1); stw 0,0x3c(1); mr 30,3; fmr f28,f3; fmr f29,f4; fmr f27,f2; fmr f31,f1; bl _s802CAD94_0; lis 9,-32702; lis 11,-32702; lfs f0,-7428(9); lfs f13,-7424(11); fmuls f31,f31,f0; fmuls f31,f31,f13; fmr f1,f31; bl _s802CAD94_1; fmr f30,f1; fmr f1,f31; bl _s802CAD94_2; fdivs f30,f30,f1; lis 9,-32702; lfs f0,-7420(9); lis 11,-32702; lfs f13,-7416(11); mr 3,30; stfs f0,0x2c(30); stfs f13,0x3c(30); fmuls f0,f28,f29; stfs f30,0x14(30); fsubs f29,f28,f29; fdivs f0,f0,f29; fdivs f30,f30,f27; stfs f0,0x38(30); fdivs f28,f28,f29; stfs f30,0x0(30); stfs f28,0x28(30); lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x8(1); lfd f27,0x10(1); lfd f28,0x18(1); lfd f29,0x20(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s802CAD94_0();
extern "C" void _s802CAD94_1();
extern "C" void _s802CAD94_2();
extern "C" void f_802CAD94() {}
