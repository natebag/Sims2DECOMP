// 0x80090C1C LoadingScreenStateMachine::StartLoad(CLoadingScreen::eLoadingScreenMode) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 0,1; li 9,0; stw 4,0x9c(31); stw 0,0xa0(31); stw 9,0xa4(31); bl _s80090C1C_0; mr. 3,3; bne 0f; lwz 9,-26392(13); stw 3,0x320(9); b 4f; 0:; lwz 9,-32160(13); lwz 0,0xb4(9); rlwinm 9,0,31,31,31; cmpwi 9,0; beq 3f; addi 11,31,168; lfs f13,0xa8(31); lfs f0,0x8(11); lis 9,-32706; lfs f12,-32596(9); fsubs f13,f13,f0; fcmpu 0,f13,f12; ble 1f; fmr f13,f12; 1:; lis 9,-32706; lfs f1,-32592(9); fcmpu 0,f13,f1; bne 2f; lis 9,-32706; lfs f13,-32588(9); 2:; li 0,16; stfs f12,0x8(11); stw 0,0xc(11); lis 9,-32706; stfs f12,0xa8(31); mr 3,31; li 4,1; lfs f0,-32584(9); lwz 0,0xc(11); fdivs f0,f0,f12; stfs f13,0x8(11); rlwinm 0,0,0,31,27; ori 0,0,1; stw 0,0xc(11); stfs f0,0x4(11); bl _s80090C1C_1; b 4f; 3:; andi. 11,0,4; beq 4f; stw 9,0xa0(31); 4:; mr 3,31; bl _s80090C1C_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80090C1C_0();
extern "C" void _s80090C1C_1();
extern "C" void _s80090C1C_2();
extern "C" void f_80090C1C() {}
