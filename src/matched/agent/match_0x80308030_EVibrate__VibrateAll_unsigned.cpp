// 0x80308030 EVibrate::VibrateAll(unsigned (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f30,0x8(1); stfd f31,0x10(1); stw 0,0x1c(1); lwz 3,-26524(13); fmr f31,f1; fmr f30,f2; bl _s80308030_0; mr. 11,3; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x208(11); fmr f1,f31; fmr f2,f30; lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x1c(1); mtspr 8,0; lfd f30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s80308030_0();
extern "C" void f_80308030() {}
