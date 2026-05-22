// 0x8017EBB0 UIReflow::Reflow_Visibility(bool) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 30,0x88(1); stw 0,0x94(1); mr 30,4; mr 31,3; lis 4,-32706; addi 4,4,14292; bl _s8017EBB0_0; cmpwi 30,0; li 5,0; beq 0f; li 5,1; 0:; lis 4,-32706; addi 3,1,8; addi 4,4,14212; crxor 6,6,6; bl _s8017EBB0_1; addi 4,1,8; mr 3,31; bl _s8017EBB0_2; lis 4,-32706; mr 3,31; addi 4,4,14300; bl _s8017EBB0_3; lwz 0,0x94(1); mtspr 8,0; lmw 30,0x88(1); addi 1,1,144"
extern "C" void _s8017EBB0_0();
extern "C" void _s8017EBB0_1();
extern "C" void _s8017EBB0_2();
extern "C" void _s8017EBB0_3();
extern "C" void f_8017EBB0() {}
