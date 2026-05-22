// 0x8017E72C UIReflow::Tween_Alpha(unsigned (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 29,0x8c(1); stw 0,0x9c(1); mr 30,4; mr 29,3; lis 4,-32706; addi 4,4,14308; bl _s8017E72C_0; mulli 30,30,100; lis 0,-32640; ori 0,0,32897; lis 4,-32706; addi 3,1,8; addi 4,4,14212; mulhwu 30,30,0; rlwinm 5,30,25,7,31; crxor 6,6,6; bl _s8017E72C_1; addi 4,1,8; mr 3,29; bl _s8017E72C_2; lis 4,-32706; mr 3,29; addi 4,4,14316; bl _s8017E72C_3; lwz 0,0x9c(1); mtspr 8,0; lmw 29,0x8c(1); addi 1,1,152"
extern "C" void _s8017E72C_0();
extern "C" void _s8017E72C_1();
extern "C" void _s8017E72C_2();
extern "C" void _s8017E72C_3();
extern "C" void f_8017E72C() {}
