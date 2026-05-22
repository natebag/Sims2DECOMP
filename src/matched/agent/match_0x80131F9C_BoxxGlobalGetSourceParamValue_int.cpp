// 0x80131F9C BoxxGlobalGetSourceParamValue(int, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; blrl; b 0f; li 3,0; 0:; mr 4,28; fmr f1,f31; bl _s80131F9C_0; lwz 0,0x5c(1); lwz 12,0xc(1); mtspr 8,0; lmw 22,0x10(1); lfd f28,0x38(1); lfd f29,0x40(1); lfd f30,0x48(1); lfd f31,0x50(1); mtcrf 24,12; addi 1,1,88"
extern "C" void _s80131F9C_0();
extern "C" float f_80131F9C() {}
