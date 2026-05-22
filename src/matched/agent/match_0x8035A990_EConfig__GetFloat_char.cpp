// 0x8035A990 EConfig::GetFloat(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stfd f31,0x8(1); stw 0,0x14(1); fmr f31,f1; li 5,0; bl _s8035A990_0; mr. 3,3; bne 0f; fmr f1,f31; b 1f; 0:; bl _s8035A990_1; 1:; lwz 0,0x14(1); mtspr 8,0; lfd f31,0x8(1); addi 1,1,16"
extern "C" void _s8035A990_0();
extern "C" void _s8035A990_1();
extern "C" void f_8035A990() {}
