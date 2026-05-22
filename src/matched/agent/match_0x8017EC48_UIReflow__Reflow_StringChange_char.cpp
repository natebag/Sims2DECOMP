// 0x8017EC48 UIReflow::Reflow_StringChange(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 30,3; lis 4,-32706; addi 4,4,14328; bl _s8017EC48_0; mr 4,29; mr 3,30; bl _s8017EC48_1; lis 4,-32706; mr 3,30; addi 4,4,14340; bl _s8017EC48_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8017EC48_0();
extern "C" void _s8017EC48_1();
extern "C" void _s8017EC48_2();
extern "C" void f_8017EC48() {}
