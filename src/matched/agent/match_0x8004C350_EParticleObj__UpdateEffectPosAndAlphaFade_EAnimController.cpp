// 0x8004C350 EParticleObj::UpdateEffectPosAndAlphaFade(EAnimController (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stfd f31,0x70(1); stmw 23,0x4c(1); stw 0,0x7c(1); mr 23,3; mr 25,4; lwz 29,0x0(23); mr 26,5; mr 27,6; fmr f31,f2; cmpwi 29,0; beq 4f; addi 28,1,8; li 24,0; 0:; lwz 31,0x0(29); cmpwi 31,0; beq 3f; mr 3,31; bl _s8004C350_0; cmpwi 3,0; beq 3f; lwz 9,0xc(23); lwz 0,0x14(9); add 30,0,24; lbz 9,0x1(30); andi. 0,9,128; bne 2f; lwz 9,0x24(25); cmpwi 9,0; li 0,0; beq 1f; lwz 0,0x18(9); 1:; cmpwi 0,0; beq 3f; mr 4,26; mr 3,28; bl _s8004C350_1; lbz 4,0x1(30); mr 3,25; mr 5,28; extsb 4,4; bl _s8004C350_2; mr 3,31; mr 4,28; mr 5,27; bl _s8004C350_3; mr 3,31; fmr f1,f31; bl _s8004C350_4; b 3f; 2:; mr 3,31; mr 4,26; mr 5,27; bl _s8004C350_5; mr 3,31; fmr f1,f31; bl _s8004C350_6; 3:; lwz 29,0x8(29); addi 24,24,8; cmpwi 29,0; bne 0b; 4:; lwz 0,0x7c(1); mtspr 8,0; lmw 23,0x4c(1); lfd f31,0x70(1); addi 1,1,120"
extern "C" void _s8004C350_0();
extern "C" void _s8004C350_1();
extern "C" void _s8004C350_2();
extern "C" void _s8004C350_3();
extern "C" void _s8004C350_4();
extern "C" void _s8004C350_5();
extern "C" void _s8004C350_6();
extern "C" void f_8004C350() {}
