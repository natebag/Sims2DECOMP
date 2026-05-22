// 0x80308174 EVibrate::StopMotorOne(unsigned (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stfd f31,0x8(1); stw 0,0x14(1); lwz 3,-26524(13); fmr f31,f1; bl _s80308174_0; mr. 11,3; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x208(11); fmr f1,f31; lha 3,0x60(9); lwz 0,0x64(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x14(1); mtspr 8,0; lfd f31,0x8(1); addi 1,1,16"
extern "C" void _s80308174_0();
extern "C" void f_80308174() {}
