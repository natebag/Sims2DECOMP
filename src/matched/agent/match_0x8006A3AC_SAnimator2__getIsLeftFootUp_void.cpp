// 0x8006A3AC SAnimator2::getIsLeftFootUp(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x8(3); lis 4,1; addi 3,3,820; bl _s8006A3AC_0; lis 9,-32707; lfs f0,0x4cc4(9); fcmpu 0,f1,f0; cror 3,2,1; bns 0f; lis 9,-32707; li 3,0; lfs f0,0x4cc8(9); fcmpu 0,f1,f0; blt 1f; 0:; li 3,1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8006A3AC_0();
extern "C" void f_8006A3AC() {}
