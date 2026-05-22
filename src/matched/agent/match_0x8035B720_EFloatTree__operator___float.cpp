// 0x8035B720 EFloatTree::operator[](float) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; bl _s8035B720_0; mr. 4,3; beq 0f; lfs f0,0x1c(4); fcmpu 0,f0,f31; bne 0f; addi 3,4,24; b 1f; 0:; mr 3,31; fmr f1,f31; li 5,0; bl _s8035B720_1; addi 3,3,24; 1:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s8035B720_0();
extern "C" void _s8035B720_1();
extern "C" void f_8035B720() {}
