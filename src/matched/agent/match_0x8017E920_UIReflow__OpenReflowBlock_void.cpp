// 0x8017E920 UIReflow::OpenReflowBlock(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,0x0(31); cmpwi 30,0; bne 0f; li 0,1; li 9,4096; stw 0,0x8(31); stw 9,0xc(31); bl _s8017E920_0; lwz 4,0xc(31); li 5,0; bl _s8017E920_1; stw 30,0x10(31); cmpwi 3,0; stw 3,0x0(31); stw 3,0x4(31); beq 0f; lis 4,-32706; mr 3,31; addi 4,4,14172; bl _s8017E920_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8017E920_0();
extern "C" void _s8017E920_1();
extern "C" void _s8017E920_2();
extern "C" void f_8017E920() {}
