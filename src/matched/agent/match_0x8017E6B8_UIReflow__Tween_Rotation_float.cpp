// 0x8017E6B8 UIReflow::Tween_Rotation(float) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stfd f31,0x90(1); stmw 30,0x88(1); stw 0,0x9c(1); mr 30,3; lis 4,-32706; addi 4,4,14568; fmr f31,f1; bl _s8017E6B8_0; lis 4,-32706; fmr f1,f31; addi 4,4,14576; addi 3,1,8; creqv 6,6,6; bl _s8017E6B8_1; addi 4,1,8; mr 3,30; bl _s8017E6B8_2; lis 4,-32706; mr 3,30; addi 4,4,14584; bl _s8017E6B8_3; lwz 0,0x9c(1); mtspr 8,0; lmw 30,0x88(1); lfd f31,0x90(1); addi 1,1,152"
extern "C" void _s8017E6B8_0();
extern "C" void _s8017E6B8_1();
extern "C" void _s8017E6B8_2();
extern "C" void _s8017E6B8_3();
extern "C" void f_8017E6B8() {}
