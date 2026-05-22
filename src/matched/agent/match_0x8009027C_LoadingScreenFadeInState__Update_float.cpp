// 0x8009027C LoadingScreenFadeInState::Update(float) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 0,0x1c(1); lwz 9,0x8(3); fmr f31,f1; lfs f12,-22736(13); addi 11,9,168; lwz 0,0xc(11); andi. 9,0,16; beq 2f; lis 9,-32707; lfs f0,0x8(11); lfs f13,0x7fd8(9); fcmpu 0,f0,f13; beq 2f; fsubs f0,f0,f12; fcmpu 0,f0,f13; stfs f0,0x8(11); cror 3,2,0; bns 2f; stfs f13,0x8(11); andi. 9,0,1; beq 0f; rlwinm 0,0,0,0,30; ori 0,0,4; b 1f; 0:; andi. 9,0,2; beq 2f; rlwinm 0,0,0,31,29; ori 0,0,8; 1:; stw 0,0xc(11); 2:; lwz 8,0x8(3); lis 7,17200; lis 11,-32707; lwz 0,0xa4(8); lis 10,-32707; lfd f13,0x7fe0(11); stw 0,0xc(1); lfs f1,0x7fd8(10); stw 7,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fcmpu 0,f0,f1; bne 3f; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 4f; 3:; lwz 9,-32160(13); li 0,0; lwz 11,-26392(13); li 4,2; stw 0,0xa0(9); stw 0,0x320(11); bl _s8009027C_0; 4:; lwz 9,-32160(13); lwz 3,0x98(9); cmpwi 3,0; beq 5f; fmr f1,f31; bl _s8009027C_1; 5:; lwz 0,0x1c(1); mtspr 8,0; lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s8009027C_0();
extern "C" void _s8009027C_1();
extern "C" void f_8009027C() {}
