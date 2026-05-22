// 0x8035B878 EFloatTree::Insert(float, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; mr 30,4; cmpwi 5,0; beq 0f; bl _s8035B878_0; mr 4,3; fmr f1,f31; mr 3,31; b 2f; 0:; mr 3,31; fmr f1,f31; bl _s8035B878_1; mr. 4,3; beq 1f; lfs f0,0x1c(4); li 3,0; fcmpu 0,f0,f31; beq 3f; 1:; mr 3,31; fmr f1,f31; 2:; mr 5,30; bl _s8035B878_2; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s8035B878_0();
extern "C" void _s8035B878_1();
extern "C" void _s8035B878_2();
extern "C" void f_8035B878() {}
