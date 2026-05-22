// 0x8022A740 EIPortalPointLight::EIPortalPointLight(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); mr 30,3; li 29,0; bl _s8022A740_0; lis 11,-32704; lwz 0,0x5c(30); lfs f31,-5104(11); addi 9,1,8; lis 11,-32697; oris 0,0,8; stfs f31,0x8(9); addi 11,11,-27584; stfs f31,0x4(9); mr 4,9; stw 11,0x0(30); mr 3,30; stw 0,0x5c(30); stw 29,0xd4(30); stfs f31,0x8(1); bl _s8022A740_1; stfs f31,0xc4(30); li 0,1; mr 3,30; lfs f0,-28484(13); stw 0,0xcc(30); stfs f0,0xc8(30); lfs f13,-28460(13); stw 29,0xd0(30); stfs f13,0x8c(30); stw 0,0x88(30); bl _s8022A740_2; mr 3,30; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s8022A740_0();
extern "C" void _s8022A740_1();
extern "C" void _s8022A740_2();
extern "C" void f_8022A740() {}
