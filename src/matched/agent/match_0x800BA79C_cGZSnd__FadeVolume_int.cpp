// 0x800BA79C cGZSnd::FadeVolume(int, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 8,3; mr 4,5; cmplwi 6,50; bge 0f; li 6,50; 0:; lis 0,17200; stw 6,0xc(1); lis 9,-32706; lfd f13,-25336(9); lis 10,-32706; stw 0,0x8(1); mr 9,11; lfs f11,-25328(10); mr 3,8; lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f0,f11; fmr f13,f0; fctiwz f12,f13; stfd f12,0x8(1); lwz 9,0xc(1); stw 9,0x34(8); bl _s800BA79C_0; li 3,1; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s800BA79C_0();
extern "C" void f_800BA79C() {}
