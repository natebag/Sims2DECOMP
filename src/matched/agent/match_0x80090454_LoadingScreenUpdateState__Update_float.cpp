// 0x80090454 LoadingScreenUpdateState::Update(float) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); lwz 9,-32160(13); mr 31,3; lwz 3,0x98(9); cmpwi 3,0; beq 0f; bl _s80090454_0; 0:; lwz 9,0x8(31); lis 8,17200; lis 10,-32706; lwz 0,0xa4(9); mr 7,9; lfd f13,-32736(10); lis 9,-32706; stw 0,0x14(1); lfs f12,-32728(9); stw 8,0x10(1); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fcmpu 0,f0,f12; beq 2f; lis 9,-32706; lwz 11,-32160(13); lfs f13,-32724(9); lwz 9,0x98(11); cmpwi 9,0; beq 1f; lwz 0,0x354(9); cmpwi 0,0; bne 1f; lis 9,-32706; lfs f13,-32720(9); 1:; addi 11,7,168; li 0,16; stw 0,0xc(11); lis 10,-32706; stfs f13,0x8(11); li 8,-14; stfs f13,0xa8(7); lis 9,-32706; lfs f1,-32728(9); mr 3,31; lfs f0,-32716(10); li 4,3; lwz 0,0xc(11); fdivs f0,f0,f13; and 0,0,8; ori 0,0,2; stw 0,0xc(11); stfs f0,0x4(11); bl _s80090454_1; 2:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s80090454_0();
extern "C" void _s80090454_1();
extern "C" void f_80090454() {}
