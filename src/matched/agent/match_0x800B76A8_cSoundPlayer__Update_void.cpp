// 0x800B76A8 cSoundPlayer::Update(void) (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stfd f30,0x40(1); stfd f31,0x48(1); stmw 26,0x28(1); stw 0,0x54(1); lis 9,-32706; mr 28,3; addi 11,28,24; lfs f30,-25904(9); lwz 9,0x4(11); mr 27,11; lis 26,-32692; lwz 0,0x0(9); stw 0,0x8(1); stw 0,0x10(1); b 3f; 0:; lwz 9,0x10(1); addi 3,26,-14084; lwz 0,0x0(9); stw 0,0x10(1); lwz 4,0xc(11); bl _s800B76A8_0; mr. 29,3; beq 2f; lwz 0,0x10(1); lwz 3,0x8(1); stw 0,0x10(28); cmpwi 3,0; lfs f31,0x10(3); lwz 30,0x8(3); stw 3,0x20(1); lwz 31,0x0(3); lwz 9,0x4(3); stw 31,0x0(9); stw 9,0x4(31); beq 1f; li 4,20; bl _s800B76A8_1; 1:; lwz 3,-24508(13); mr 5,30; stw 31,0x18(1); fadds f1,f31,f30; mr 4,29; bl _s800B76A8_2; mr 3,29; bl _s800B76A8_3; 2:; lwz 0,0x10(1); stw 0,0x8(1); 3:; lwz 0,0x4(27); li 9,1; lwz 11,0x8(1); stw 0,0x18(1); cmpw 11,0; bne 4f; li 9,0; 4:; cmpwi 9,0; bne 0b; lwz 0,0x0(28); cmpwi 0,0; beq 5f; lwz 0,0x8(28); cmpwi 0,0; beq 5f; lwz 3,-24508(13); bl _s800B76A8_4; lwz 0,0xc(28); cmpwi 0,0; bne 5f; lwz 11,-24508(13); li 4,0; lwz 9,0x78(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(28); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 5:; lwz 0,0x54(1); mtspr 8,0; lmw 26,0x28(1); lfd f30,0x40(1); lfd f31,0x48(1); addi 1,1,80"
extern "C" void _s800B76A8_0();
extern "C" void _s800B76A8_1();
extern "C" void _s800B76A8_2();
extern "C" void _s800B76A8_3();
extern "C" void _s800B76A8_4();
extern "C" void f_800B76A8() {}
