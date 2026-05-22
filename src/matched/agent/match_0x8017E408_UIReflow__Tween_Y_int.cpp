// 0x8017E408 UIReflow::Tween_Y(int) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 29,0x8c(1); stw 0,0x9c(1); mr 29,4; mr 30,3; lis 4,-32706; addi 4,4,14268; bl _s8017E408_0; lis 4,-32706; mr 5,29; addi 4,4,14212; addi 3,1,8; crxor 6,6,6; bl _s8017E408_1; addi 4,1,8; mr 3,30; bl _s8017E408_2; lis 4,-32706; mr 3,30; addi 4,4,14272; bl _s8017E408_3; lwz 0,0x9c(1); mtspr 8,0; lmw 29,0x8c(1); addi 1,1,152"
extern "C" void _s8017E408_0();
extern "C" void _s8017E408_1();
extern "C" void _s8017E408_2();
extern "C" void _s8017E408_3();
extern "C" void f_8017E408() {}
