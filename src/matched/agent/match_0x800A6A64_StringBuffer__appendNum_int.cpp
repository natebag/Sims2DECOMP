// 0x800A6A64 StringBuffer::appendNum(int, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); mr 29,4; addi 30,1,40; mr 28,3; lis 4,-32706; addi 4,4,-28488; mr 3,30; crxor 6,6,6; bl _s800A6A64_0; mr 4,30; mr 5,29; addi 3,1,8; crxor 6,6,6; bl _s800A6A64_1; mr 3,28; addi 4,1,8; li 5,-1; bl _s800A6A64_2; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"
extern "C" void _s800A6A64_0();
extern "C" void _s800A6A64_1();
extern "C" void _s800A6A64_2();
extern "C" void f_800A6A64() {}
