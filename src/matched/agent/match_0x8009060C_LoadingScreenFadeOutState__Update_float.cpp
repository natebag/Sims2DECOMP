// 0x8009060C LoadingScreenFadeOutState::Update(float) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; lwz 9,0x8(31); lfs f12,-22736(13); addi 11,9,168; lwz 0,0xc(11); andi. 9,0,16; beq 2f; lis 9,-32706; lfs f0,0x8(11); lfs f13,-32660(9); fcmpu 0,f0,f13; beq 2f; fsubs f0,f0,f12; fcmpu 0,f0,f13; stfs f0,0x8(11); cror 3,2,0; bns 2f; stfs f13,0x8(11); andi. 9,0,1; beq 0f; rlwinm 0,0,0,0,30; ori 0,0,4; b 1f; 0:; andi. 9,0,2; beq 2f; rlwinm 0,0,0,31,29; ori 0,0,8; 1:; stw 0,0xc(11); 2:; lwz 3,-32160(13); lwz 0,0xb4(3); andi. 9,0,8; beq 3f; bl _s8009060C_0; lwz 10,-26392(13); li 0,1; lwz 8,-32160(13); lis 9,-32706; stw 0,0x320(10); li 11,0; lfs f1,-32660(9); mr 3,31; stw 11,0xb4(8); li 4,0; bl _s8009060C_1; 3:; lwz 9,-32160(13); lwz 3,0x98(9); cmpwi 3,0; beq 4f; fmr f1,f31; bl _s8009060C_2; 4:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s8009060C_0();
extern "C" void _s8009060C_1();
extern "C" void _s8009060C_2();
extern "C" void f_8009060C() {}
