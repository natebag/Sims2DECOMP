// 0x8017E5B8 UIReflow::Tween_XScale(float) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stfd f31,0x90(1); stmw 30,0x88(1); stw 0,0x9c(1); mr 30,3; lis 4,-32706; fmr f31,f1; addi 4,4,14524; bl _s8017E5B8_0; lis 9,-32706; lis 4,-32706; lfs f0,0x38d0(9); addi 4,4,14532; addi 3,1,8; fmuls f31,f31,f0; fmr f1,f31; creqv 6,6,6; bl _s8017E5B8_1; addi 4,1,8; mr 3,30; bl _s8017E5B8_2; lis 4,-32706; mr 3,30; addi 4,4,14536; bl _s8017E5B8_3; lwz 0,0x9c(1); mtspr 8,0; lmw 30,0x88(1); lfd f31,0x90(1); addi 1,1,152"
extern "C" void _s8017E5B8_0();
extern "C" void _s8017E5B8_1();
extern "C" void _s8017E5B8_2();
extern "C" void _s8017E5B8_3();
extern "C" void f_8017E5B8() {}
