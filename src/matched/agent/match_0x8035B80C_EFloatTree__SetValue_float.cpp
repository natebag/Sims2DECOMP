// 0x8035B80C EFloatTree::SetValue(float, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; mr 30,4; bl _s8035B80C_0; mr. 4,3; beq 0f; lfs f0,0x1c(4); fcmpu 0,f0,f31; bne 0f; stw 30,0x18(4); mr 3,4; b 1f; 0:; mr 3,31; fmr f1,f31; mr 5,30; bl _s8035B80C_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s8035B80C_0();
extern "C" void _s8035B80C_1();
extern "C" void f_8035B80C() {}
