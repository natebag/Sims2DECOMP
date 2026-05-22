// 0x8030809C EVibrate::VibrateAll(unsigned (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f28,0x8(1); stfd f29,0x10(1); stfd f30,0x18(1); stfd f31,0x20(1); stw 0,0x2c(1); lwz 3,-26524(13); fmr f31,f1; fmr f30,f2; fmr f29,f3; fmr f28,f4; bl _s8030809C_0; mr. 11,3; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x208(11); fmr f1,f31; fmr f2,f30; lha 3,0x50(9); fmr f3,f29; lwz 0,0x54(9); fmr f4,f28; add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x2c(1); mtspr 8,0; lfd f28,0x8(1); lfd f29,0x10(1); lfd f30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s8030809C_0();
extern "C" void f_8030809C() {}
