// 0x800A6A14 StringBuffer::appendNum(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 5,4; mr 30,3; lis 4,-32706; addi 3,1,8; addi 4,4,-28492; crxor 6,6,6; bl _s800A6A14_0; mr 3,30; addi 4,1,8; li 5,-1; bl _s800A6A14_1; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s800A6A14_0();
extern "C" void _s800A6A14_1();
extern "C" void f_800A6A14() {}
