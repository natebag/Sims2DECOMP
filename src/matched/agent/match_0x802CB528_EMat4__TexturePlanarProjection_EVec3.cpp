// 0x802CB528 EMat4::TexturePlanarProjection(EVec3 (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f28,0x20(1); stfd f29,0x28(1); stfd f30,0x30(1); stfd f31,0x38(1); stmw 30,0x18(1); stw 0,0x44(1); mr 30,3; fmr f29,f1; fmr f28,f2; fmr f31,f3; fmr f30,f4; bl _s802CB528_0; fdivs f31,f31,f29; lis 9,-32702; lfs f0,-7380(9); addi 11,1,8; mr 4,11; mr 3,30; fdivs f30,f30,f28; stfs f31,0x8(1); stfs f0,0x8(11); stfs f30,0x4(11); bl _s802CB528_1; mr 3,30; lwz 0,0x44(1); mtspr 8,0; lmw 30,0x18(1); lfd f28,0x20(1); lfd f29,0x28(1); lfd f30,0x30(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s802CB528_0();
extern "C" void _s802CB528_1();
extern "C" void f_802CB528() {}
