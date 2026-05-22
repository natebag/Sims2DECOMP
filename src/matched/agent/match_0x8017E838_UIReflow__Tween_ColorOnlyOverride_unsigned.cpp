// 0x8017E838 UIReflow::Tween_ColorOnlyOverride(unsigned (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 29,0x8c(1); stw 0,0x9c(1); mr 29,4; mr 30,3; lis 4,-32706; addi 4,4,14352; bl _s8017E838_0; lis 4,-32706; mr 3,30; addi 4,4,14360; bl _s8017E838_1; lis 4,-32706; mr 5,29; addi 4,4,14364; addi 3,1,8; crxor 6,6,6; bl _s8017E838_2; addi 4,1,8; mr 3,30; bl _s8017E838_3; lis 4,-32706; mr 3,30; addi 4,4,14372; bl _s8017E838_4; lwz 0,0x9c(1); mtspr 8,0; lmw 29,0x8c(1); addi 1,1,152"
extern "C" void _s8017E838_0();
extern "C" void _s8017E838_1();
extern "C" void _s8017E838_2();
extern "C" void _s8017E838_3();
extern "C" void _s8017E838_4();
extern "C" void f_8017E838() {}
