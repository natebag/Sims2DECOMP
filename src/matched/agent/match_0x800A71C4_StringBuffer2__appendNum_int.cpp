// 0x800A71C4 StringBuffer2::appendNum(int) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 29,0x6c(1); stw 0,0x7c(1); mr 5,4; mr 29,3; lis 4,-32706; addi 3,1,8; addi 4,4,-28480; crxor 6,6,6; bl _s800A71C4_0; addi 30,1,40; addi 4,1,8; mr 3,30; bl _s800A71C4_1; mr 3,29; mr 4,30; li 5,-1; bl _s800A71C4_2; lwz 0,0x7c(1); mtspr 8,0; lmw 29,0x6c(1); addi 1,1,120"
extern "C" void _s800A71C4_0();
extern "C" void _s800A71C4_1();
extern "C" void _s800A71C4_2();
extern "C" void f_800A71C4() {}
