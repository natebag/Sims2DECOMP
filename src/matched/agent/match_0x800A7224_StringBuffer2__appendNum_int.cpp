// 0x800A7224 StringBuffer2::appendNum(int, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 27,0x8c(1); stw 0,0xa4(1); mr 28,4; addi 30,1,40; mr 27,3; lis 4,-32706; addi 29,1,72; addi 4,4,-28476; mr 3,30; crxor 6,6,6; bl _s800A7224_0; mr 5,28; mr 4,30; addi 3,1,8; crxor 6,6,6; bl _s800A7224_1; mr 3,29; addi 4,1,8; bl _s800A7224_2; mr 3,27; mr 4,29; li 5,-1; bl _s800A7224_3; lwz 0,0xa4(1); mtspr 8,0; lmw 27,0x8c(1); addi 1,1,160"
extern "C" void _s800A7224_0();
extern "C" void _s800A7224_1();
extern "C" void _s800A7224_2();
extern "C" void _s800A7224_3();
extern "C" void f_800A7224() {}
