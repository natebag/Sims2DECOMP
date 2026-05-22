// 0x802CB42C EMat4::TexturePerspectiveProjection(EVec3 (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-344(1); mfspr 0,8; stfd f28,0x138(1); stfd f29,0x140(1); stfd f30,0x148(1); stfd f31,0x150(1); stmw 24,0x118(1); stw 0,0x15c(1); mr 24,3; fmr f31,f3; addi 3,1,8; fmr f30,f4; fmr f29,f1; lis 25,-32702; fmr f28,f2; lis 27,-32702; bl _s802CB42C_0; addi 30,1,72; lfs f3,-7392(25); lfs f4,-7388(27); addi 29,1,264; addi 26,1,136; fmr f1,f29; fmr f2,f28; mr 3,30; bl _s802CB42C_1; addi 28,1,200; addi 4,1,8; mr 5,30; mr 3,26; bl _s802CB42C_2; lis 9,-32702; lfs f13,-7388(27); lfs f0,-7384(9); mr 4,29; mr 3,28; fmuls f30,f30,f0; fmuls f31,f31,f0; stfs f30,0x10c(1); stfs f31,0x108(1); stfs f13,0x8(29); bl _s802CB42C_3; lfs f0,-7392(25); mr 4,29; stfs f31,0x108(1); mr 3,28; stfs f30,0x10c(1); stfs f0,0x8(29); bl _s802CB42C_4; mr 3,24; mr 4,26; mr 5,28; bl _s802CB42C_5; mr 3,24; lwz 0,0x15c(1); mtspr 8,0; lmw 24,0x118(1); lfd f28,0x138(1); lfd f29,0x140(1); lfd f30,0x148(1); lfd f31,0x150(1); addi 1,1,344"
extern "C" void _s802CB42C_0();
extern "C" void _s802CB42C_1();
extern "C" void _s802CB42C_2();
extern "C" void _s802CB42C_3();
extern "C" void _s802CB42C_4();
extern "C" void _s802CB42C_5();
extern "C" void f_802CB42C() {}
